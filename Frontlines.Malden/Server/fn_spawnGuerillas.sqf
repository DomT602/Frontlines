/*
	File: fn_spawnGuerillas.sqf
	Author: Dom
	Description: Spawns independent units to attack/defend a sector
*/
params [
	["_sectorObj",objNull,[objNull,[]]],
	["_action","",[""]]
];

private _sectorTypeIndex = [_sectorObj getVariable "DT_sectorType"] call DT_fnc_getSectorTypeIndex;
private _spawnRadius = (getArray(missionConfigFile >> "Settings" >> "sectorRadius")) select _sectorTypeIndex;
private _position = [_sectorObj,_spawnRadius,(_spawnRadius * 2),5,0,1,0] call BIS_fnc_findSafePos;
[format["Guerilla forces are on the way to %1.",_sectorObj getVariable "DT_sectorName"],"generalNotif","Guerilla Forces"] remoteExecCall ["DT_fnc_notify",0];

private _groups = [];
_groups pushBack ([_position,150,independent] call DT_fnc_createSquad);
if (abs DT_globalReputation > 50) then {
	_groups pushBack ([_position,150,independent] call DT_fnc_createSquad);
};

if (_action in ["mechAttack","sectorDefence"] || {DT_globalReputation < -33}) then {
	private _guerillaVehicles = getArray(missionConfigFile >> "Guerilla_Setup" >> "guerillaVehicles");
	_groups pushBack ([selectRandom _guerillaVehicles,_position,150,true,independent] call DT_fnc_createVehicle);
};

{
	private _waypoint = _x addWaypoint [_sectorObj,10];
	_waypoint setWaypointType "SAD";
	_waypoint setWaypointCombatMode "RED";
	_waypoint setWaypointBehaviour "AWARE";
} forEach _groups;

[
	{
		params ["_sectorObj"];
		!(_sectorObj in DT_activeSectors)
	},
	DT_fnc_clearArea,
	[_sectorObj,_groups]
] call CBA_fnc_waitUntilAndExecute;

_groups;