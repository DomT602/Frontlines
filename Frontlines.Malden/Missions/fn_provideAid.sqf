/*
	File: fn_provideAid.sqf
	Author: Dom
	Description: Secondary objective to provide medical aid to a front line sector
*/
missionNamespace setVariable ["DT_secondaryActive","medicalAid",true];

private _sectors = [["city","town","factory"],true] call DT_fnc_getSectorsByType;
private _civReps = [];
{
	_civReps pushBack (_x getVariable ["DT_sectorReputation",0]);
} forEach _sectors;
private _index = (_civReps call CBA_fnc_findMax) select 1;
private _chosenSector = _sectors select _index;

private _marker = ["medicalAid",_chosenSector,false,"ColorYellow","mil_objective",1.5,"Medical Aid Requested"] call DT_fnc_createMarker;
["The town is marked, head there to assist.","generalNotif","Medical Aid"] remoteExecCall ["DT_fnc_notify",0];

[
	{
		params ["_pos"];
		!([_pos,2000] call DT_fnc_areaIsClear) || {isNil "DT_secondaryActive"}
	},
	{
		params ["_sector","_marker"];

		if (isNil "DT_secondaryActive") then {
			deleteMarker _marker;
			["Mission cancelled.","failedNotif","Medical Aid"] remoteExecCall ["DT_fnc_notify",0];
		} else {
			private _injuredCount = 2 + (ceil (count playableUnits / 4));
			private _civilianTypes = getArray(missionConfigFile >> "Civilian_Setup" >> "civilianTypes");
			private _bodyParts = ["Head","Body","LeftArm","RightArm","LeftLeg","RightLeg"];
			private _damageTypes = ["grenade","explosive","ropeburn"];

			private _group = createGroup [civilian,true];
			for "_i" from 1 to _injuredCount do {
				private _civClass = selectRandom _civilianTypes;
				private _position = [_sector,0,150,5,0,1,0,[]] call BIS_fnc_findSafePos;

				private _civilian = _group createUnit [_civClass,_position,[],5,"NONE"];
				removeAllItems _civilian;
				_civilian addEventHandler ["Killed",DT_fnc_civilianKilled];

				private _woundCount = 2 + (round (random 1));
				for "_i" from 1 to _woundCount do {
					[_civilian,0.25,(selectRandom _bodyParts),(selectRandom _damageTypes)] call ace_medical_fnc_addDamageToUnit;
				};
				[_civilian,true,300,true] call ace_medical_fnc_setUnconscious;
				_civilian setVariable ["ace_medical_ai_lastFired",(CBA_missionTime + 300)];
			};
			[_group,getPosATL _sector] call DT_fnc_civilianWalking;

			[
				{
					params ["_civilians"];
					private _civCount = count _civilians;
					({
						!alive _x || 
						{[_x] call ace_medical_status_fnc_isInStableCondition}
					} count _civilians) isEqualTo _civCount;
				},
				{
					params ["_civilians","_marker","_sector","_group"];
					private _aliveCount = {alive _x} count _civilians;
					[format["The aid mission is over, you saved %1 civilians.",_aliveCount],"generalNotif","Medical Aid"] remoteExecCall ["DT_fnc_notify",0];

					private _repGain = 2 * (abs(getNumber (missionConfigFile >> "Settings" >> "killedCivRepLoss")));
					[_sector,(_aliveCount * _repGain)] call DT_fnc_updateCivRep;
					deleteMarker _marker;
					missionNamespace setVariable ["DT_secondaryActive",nil,true];
					[
						{
							params ["_pos"];
							[_pos] call DT_fnc_areaIsClear;
						},
						DT_fnc_clearArea,
						[_sector,_group]
					] call CBA_fnc_waitUntilAndExecute;
				},
				[units _group,_marker,_sector,_group]
			] call CBA_fnc_waitUntilAndExecute;
		};
	},
	[_chosenSector,_marker]
] call CBA_fnc_waitUntilAndExecute;