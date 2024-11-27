/*
	File: fn_areaIsClear.sqf
	Author: Dom
	Description: Checks if given area (pos or object) has any players nearby
*/
params [
	["_target",objNull,[objNull,[]]],
	["_distance",750,[0]]
];

playableUnits findIf {_x distance2D _target < _distance} isEqualTo -1;