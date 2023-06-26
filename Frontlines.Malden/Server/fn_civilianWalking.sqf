/*
	File: fn_civilianWalking.sqf
	Author: Dom
	Description: Starts civilians walking round a general area
*/
params [
	["_group",grpNull,[grpNull]],
	["_pos",[],[[]]],
	["_radius",250,[0]]
];

private _walkTargets = [];

private _nearBuildings = _pos nearObjects ["House",_radius];
if (_nearBuildings isNotEqualTo []) then {
	[_nearBuildings,true] call CBA_fnc_shuffle;
	for "_i" from 0 to ((count _nearBuildings) min 4)-1 do {
		_walkTargets pushBack (_nearBuildings select _i);
	};
};

for "_i" from 0 to 1 do {
	_walkTargets pushBack ([_pos,_radius] call CBA_fnc_randPos);
};
[_walkTargets,true] call CBA_fnc_shuffle;

private _lastIndex = (count _walkTargets) - 1;
{
	private _waypoint = _group addWaypoint [_x,5];

	if (_forEachIndex isEqualTo _lastIndex) then {
		_waypoint setWaypointType "CYCLE";
	} else {
		_waypoint setWaypointType "MOVE";
	};
	_waypoint setWaypointSpeed "LIMITED";
	_waypoint setWaypointBehaviour "SAFE";
	_waypoint setWaypointCombatMode "RED";
} forEach _walkTargets;