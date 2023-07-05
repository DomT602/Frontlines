/*
	File: fn_initPatrol.sqf
	Author: Dom
	Description: Sets up patrolling AI
*/
params [
	["_groups",[],[[]]],
	["_position",[],[[],objNull]],
	["_radius",150,[0]]
];

{
	private _leader = leader _x;
	if (DT_isLambsEnabled && {isNull objectParent _leader}) then {
		if ((_forEachIndex mod 2) isEqualTo 1) then {
			if (([_position,_radius,false] call lambs_main_fnc_findBuildings) isEqualTo []) then {
				[_x,(_position getPos [random 25,random 360]),_radius,[],true,false,-1] remoteExecCall ["lambs_wp_fnc_taskCamp",_leader];
			} else {
				[_x,_position,_radius,[],false,true,-2,false] remoteExecCall ["lambs_wp_fnc_taskGarrison",_leader];
			};
		} else {
			[_x,_position,_radius,4,[],false,true] remoteExecCall ["lambs_wp_fnc_taskPatrol",_leader];
		};
	} else {
		if !(isNull objectParent _leader) then {_radius = _radius + 150};
		private _waypoints = [];
		for "_i" from 0 to 5 do {
			_waypoints pushBack ([_position,_radius] call CBA_fnc_randPos);
		};

		private _lastIndex = (count _waypoints) - 1;
		private _group = _x;
		{
			private _waypoint = _group addWaypoint [_x,5];

			if (_forEachIndex isEqualTo _lastIndex) then {
				_waypoint setWaypointType "CYCLE";
			} else {
				_waypoint setWaypointType "MOVE";
			};
			_waypoint setWaypointSpeed "LIMITED";
			_waypoint setWaypointBehaviour "SAFE";
			_waypoint setWaypointCombatMode "YELLOW";
		} forEach _waypoints;
	};
} forEach _groups;