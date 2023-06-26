/*
	File: fn_getBuildings.sqf
	Author: Dom
	Description: Gets suitable buildings for items/units to be placed in
*/
params [
	["_centre",[],[[],objNull]],
	["_radius",300,[0]]
];

private _buildings = _centre nearObjects ["House",_radius];
_buildings select {((_x buildingPos -1) isNotEqualTo [])};