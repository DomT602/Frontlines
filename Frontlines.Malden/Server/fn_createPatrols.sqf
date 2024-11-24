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

private _lightVehicles = getArray(missionConfigFile >> "Opfor_Setup" >> "opforLightVehicles");
for "_i" from 1 to _lightCount do {
	_groups pushBack ([selectRandom _lightVehicles,_position,_spawnRadius] call DT_fnc_createVehicle);
};

private _mediumVehicles = getArray(missionConfigFile >> "Opfor_Setup" >> "opforMediumVehicles");
for "_i" from 1 to _mediumCount do {
	_groups pushBack ([selectRandom _mediumVehicles,_position,_spawnRadius] call DT_fnc_createVehicle);
};

private _heavyVehicles = getArray(missionConfigFile >> "Opfor_Setup" >> "opforHeavyVehicles");
for "_i" from 1 to _heavyCount do {
	_groups pushBack ([selectRandom _heavyVehicles,_position,_spawnRadius] call DT_fnc_createVehicle);
};

[_groups,_position,_spawnRadius] call DT_fnc_initPatrol;

_groups;