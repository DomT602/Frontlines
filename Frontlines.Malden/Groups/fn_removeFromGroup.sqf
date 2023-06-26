/*
	File: fn_removeFromGroup.sqf
	Author: Dom
	Description: Remove desired unit from a group
*/
params [
	["_unit",objNull,[objNull]]
];

private _oldPath = [];

{
	_x params ["","","","","_units"];
	if (_unit in _units) exitWith {
		private _unitIndex = _units find _unit;
		_units set [_unitIndex,objNull];
		_oldPath = [_forEachIndex,_unitIndex];
	};
} forEach DT_dynamicGroups;

_oldPath