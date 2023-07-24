/*
	File: fn_callReinforcements.sqf
	Author: Dom
	Description: Calls reinforcements into a location
*/
params [
	["_target",[],[objNull]]
];

private _isSector = (_target getVariable ["DT_sectorVariable",""]) isNotEqualTo "";
if (_isSector && (!(_target in DT_activeSectors) || _target getVariable ["DT_sectorOwned",false])) exitWith {};

private _frontlineSectors = [false,10] call DT_fnc_getFrontlineSectors;
private _sortedSectors = [_frontlineSectors,[],{_x distance2D _target},"ASCEND",{!(_x in DT_activeSectors)}] call BIS_fnc_sortBy;
if (_sortedSectors isEqualTo []) exitWith {};
_sortedSectors params ["_nearestSector"];
private _groups = [];

if ((_target distance2D _nearestSector) < 2500) then {
	private _vehicleTypes = getArray(missionConfigFile >> "Opfor_Setup" >> "opforTroopCarriers");
	for "_i" from 0 to ceil(DT_threatLevel / 33) do {
		_groups pushBack ([selectRandom _vehicleTypes,_nearestSector,250,true,east] call DT_fnc_createVehicle);
	};

	{
		private _waypoint = _x addWaypoint [_target,0];
		_waypoint setWaypointType "SAD";
		_waypoint setWaypointBehaviour "AWARE";
		_waypoint setWaypointCombatMode "RED";
		_waypoint setWaypointSpeed "FULL";
	} forEach _groups;
} else {
	_groups pushBack ([getPosATL _target,ceil (DT_threatLevel / 50)] call DT_fnc_spawnAttackHelicopters);
};

if (_isSector) then {
	if (getNumber(missionConfigFile >> "Settings" >> "reinforcementNotification") isEqualTo 1) then {
		[format["Reinforcements are incoming at %1.",_target getVariable "DT_sectorName"],"generalNotif","Enemy Reinforcements"] remoteExecCall ["DT_fnc_notify",0];
	};

	[
		{
			params ["_target"];
			!(_target in DT_activeSectors) &&
			{[_target] call DT_fnc_areaIsClear}
		},
		DT_fnc_clearArea,
		[_target,_groups]
	] call CBA_fnc_waitUntilAndExecute;
};