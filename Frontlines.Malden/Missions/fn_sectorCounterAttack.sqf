/*
	File: fn_sectorCounterAttack.sqf
	Author: Dom
	Description: Side mission for a sector counterattack
*/

private _frontlineBluforSectors = [true] call DT_fnc_getFrontlineSectors;
private _targetSector = selectRandom _frontlineBluforSectors;

private _frontlineOpforSectors = ([false] call DT_fnc_getFrontlineSectors) select {!(_x in DT_activeSectors)};
private _sendingSector = selectRandom _frontlineOpforSectors;

private _marker = ["counterAttack",_targetSector,false,"ColorRed","mil_objective",1.5,"Enemy Counter-Attack"] call DT_fnc_createMarker;
if ((DT_activeSectors pushBackUnique _targetSector) isNotEqualTo -1) then {
	publicVariable "DT_activeSectors";
};
[format["The enemy has begun a counter-attack at %1.",_targetSector getVariable "DT_sectorName"],"generalNotif","Enemy Counter-Attack"] remoteExecCall ["DT_fnc_notify",0];

private _groups = [_targetSector,_sendingSector] call DT_fnc_spawnAssault;

[
	{
		[
			{
				params ["_targetSector","_groups"];
				private _requiredCaptureRatio = getNumber(missionConfigFile >> "Settings" >> "sectorCaptureRatio");
				([_targetSector] call DT_fnc_getCaptureRatio) > _requiredCaptureRatio || {_groups findIf {!isNull _x} isEqualTo -1}
			},
			{
				params ["_targetSector","_groups","_marker"];
				["The counter-attack was successfully repelled.","successNotif","Enemy Counter-Attack"] remoteExecCall ["DT_fnc_notify",0];
				deleteMarker _marker;
				DT_activeSectors deleteAt (DT_activeSectors find _targetSector);
				publicVariable "DT_activeSectors";

				[
					{
						params ["_targetSector"];
						[_targetSector,1000] call DT_fnc_areaIsClear;
					},
					DT_fnc_clearArea,
					[_targetSector,_groups]
				] call CBA_fnc_waitUntilAndExecute;
			},
			_this,
			(getNumber(missionConfigFile >> "Settings" >> "sideMissionTimer") - 600),
			{
				params ["_targetSector","_groups","_marker"];
				[format["The enemy have re-taken %1.",_targetSector getVariable "DT_sectorName"],"failedNotif","Enemy Counter-Attack"] remoteExecCall ["DT_fnc_notify",0];
				_targetSector setVariable ["DT_sectorOwned",false,true];
				deleteMarker _marker;

				DT_activeSectors deleteAt (DT_activeSectors find _targetSector);
				publicVariable "DT_activeSectors";
				(_targetSector getVariable "DT_sectorVariable") setMarkerColor "colorOPFOR";
				_targetSector setVariable ["DT_sectorStrength",[] call DT_fnc_getAverageStrength,true];

				private _sectorType = _targetSector getVariable "DT_sectorType";
				if (_sectorType isEqualTo "factory") then {
					_targetSector setVariable ["DT_factoryType",nil,true];
					_targetSector setVariable ["DT_factoryResources",nil,true];
				};

				[
					{
						params ["_targetSector"];
						[_targetSector,1000] call DT_fnc_areaIsClear;
					},
					DT_fnc_clearArea,
					[_targetSector,_groups]
				] call CBA_fnc_waitUntilAndExecute;
			}
		] call CBA_fnc_waitUntilAndExecute;
	},
	[_targetSector,_groups,_marker],
	600
] call CBA_fnc_waitAndExecute;