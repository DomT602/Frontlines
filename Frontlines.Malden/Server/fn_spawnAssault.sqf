/*
	File: fn_spawnAssault.sqf
	Author: Dom
	Description: Spawns enemy units to attack an area/unit
*/
params [
	["_target",objNull,[objNull,[]]],
	["_position",[],[[],objNull]],
	["_modifier",1,[0]]
];

if (_position isEqualTo []) then {
	_position = [_target,500,1000,5,0,1,0] call BIS_fnc_findSafePos;
};

([_modifier] call DT_fnc_calculateEnemySquads) params ["_infantryCount","_lightCount","_mediumCount","_heavyCount"];

private _groups = [];
for "_i" from 1 to _infantryCount do {
	_groups pushBack ([_position] call DT_fnc_createSquad);
};

for "_i" from 1 to _lightCount do {
	private _lightVehicles = getArray(missionConfigFile >> "Opfor_Setup" >> "opforLightVehicles");
	_groups pushBack ([selectRandom _lightVehicles,_position,250,true] call DT_fnc_createVehicle);
};

for "_i" from 1 to _mediumCount do {
	private _mediumVehicles = getArray(missionConfigFile >> "Opfor_Setup" >> "opforMediumVehicles");
	_groups pushBack ([selectRandom _mediumVehicles,_position,250,true] call DT_fnc_createVehicle);
};

for "_i" from 1 to _heavyCount do {
	private _heavyVehicles = getArray(missionConfigFile >> "Opfor_Setup" >> "opforHeavyVehicles");
	_groups pushBack ([selectRandom _heavyVehicles,_position,250,true] call DT_fnc_createVehicle);
};

{
	private _waypoint = _x addWaypoint [_target,10];
	_waypoint setWaypointType "SAD";
	_waypoint setWaypointCombatMode "RED";
	_waypoint setWaypointBehaviour "AWARE";
} forEach _groups;

_groups pushBack ([_target,_mediumCount] call DT_fnc_spawnAttackHelicopters);

_groups;