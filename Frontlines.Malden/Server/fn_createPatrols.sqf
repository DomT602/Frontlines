/*
	File: fn_createPatrols.sqf
	Author: Dom
	Description: Creates units and sets them on patrols round a specific location
*/
params [
	["_position",[],[[],objNull]],
	["_spawnRadius",150,[0]],
	["_squadCounts",[1,1,0,0],[]]
];

_squadCounts params ["_infantryCount","_lightCount","_mediumCount","_heavyCount"];

private _groups = [];
for "_i" from 1 to _infantryCount do {
	_groups pushBack ([_position,_spawnRadius] call DT_fnc_createSquad);
};

for "_i" from 1 to _lightCount do {
	private _lightVehicles = getArray(missionConfigFile >> "Opfor_Setup" >> "opforLightVehicles");
	_groups pushBack ([selectRandom _lightVehicles,_position,_spawnRadius] call DT_fnc_createVehicle);
};

for "_i" from 1 to _mediumCount do {
	private _mediumVehicles = getArray(missionConfigFile >> "Opfor_Setup" >> "opforMediumVehicles");
	_groups pushBack ([selectRandom _mediumVehicles,_position,_spawnRadius] call DT_fnc_createVehicle);
};

for "_i" from 1 to _heavyCount do {
	private _heavyVehicles = getArray(missionConfigFile >> "Opfor_Setup" >> "opforHeavyVehicles");
	_groups pushBack ([selectRandom _heavyVehicles,_position,_spawnRadius] call DT_fnc_createVehicle);
};

[_groups,_position,_spawnRadius] call DT_fnc_initPatrol;

_groups;