/*
	File: fn_getNearestSector.sqf
	Author: Dom
	Description: Finds the nearest sector
*/
params [
	["_pos",[],[[],objNull]]
];

private _distance = 99999;
private _object = objNull;

{
	private _testDistance = _pos distance2D _x;
	if (_testDistance < _distance) then {
		_distance = _testDistance;
		_object = _x;
	};
} forEach DT_allFOBs;

_object;