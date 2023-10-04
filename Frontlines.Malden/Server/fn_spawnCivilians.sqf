/*
	File: fn_spawnCivilians.sqf
	Author: Dom
	Description: Spawns civilians in a town
*/
params [
	["_townObj",objNull,[objNull]],
	["_reputation",0,[0]],
	["_radius",250,[0]]
];

private _civilianCount = getNumber(missionConfigFile >> "Settings" >> "maxCivsPerSector");
_civilianCount = (_civilianCount - (_townObj getVariable ["DT_sectorCivsKilled",0])) max 2;
private _civTypes = getArray(missionConfigFile >> "Civilian_Setup" >> "civilianTypes");
if ([] call DT_fnc_isNight) then {
	_civilianCount = round (_civilianCount / 2);
};

private _civilians = [];
for "_i" from 1 to _civilianCount do {
	private _group = createGroup [civilian,true];
	private _className = selectRandom _civTypes;
	private _spawnPosition = [_townObj,0,_radius,5,0,1,0,[]] call BIS_fnc_findSafePos;

	private _civilian = _group createUnit [_className,_spawnPosition,[],5,"NONE"];
	_civilians pushBack _civilian;
	[_group,_spawnPosition,_radius] call DT_fnc_civilianWalking;

	if (_reputation < -50 && {25 > random 100}) then {
		[_civilian] call DT_fnc_setupSuicideBomber;
	} else {
		if (_reputation < 0 && {abs _reputation > random 100}) then {
			private _civWeps = getArray(missionConfigFile >> "Civilian_Setup" >> "civilianWeapons");
			private _weapon = selectRandom _civWeps;
			private _magazine = selectRandom (getArray (configFile >> "CfgWeapons" >> _weapon >> "magazines"));
			for "_i" from 1 to (ceil random 5) do {
				_civilian addItem _magazine;
			};
			_civilian addWeapon _weapon;

			private _hostileGroup = createGroup [east,true];
			_hostileGroup copyWaypoints _group;
			[_civilian] joinSilent _hostileGroup;
		} else {
			_civilian addEventHandler ["Hit",DT_fnc_civilianHit];
			_civilian addEventHandler ["Killed",DT_fnc_civilianKilled];

			if (7 > random 10) then {
				private _bodyParts = ["head","body","leftarm","rightarm","leftleg","rightleg"];
				private _damageTypes = ["grenade","explosive","bullet"];

				for "_i" from 1 to 3 do {
					[_civilian,random [0.3,0.4,0.5],selectRandom _bodyParts,selectRandom _damageTypes] call ace_medical_fnc_addDamageToUnit;
				};
				_civilian setVariable ["ace_medical_ai_lastFired",(CBA_missionTime + 600)];
			};
		};
	};
};

[
	{
		params ["_obj"];
		!(_obj in DT_activeSectors)
	},
	{
		params ["_obj","_civilians"];
		
		{
			if (alive _x) then {
				deleteVehicle _x;
			};
		} forEach _civilians;
	},
	[_townObj,_civilians]
] call CBA_fnc_waitUntilAndExecute;