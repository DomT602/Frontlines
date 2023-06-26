/*
	File: fn_createUnit.sqf
	Author: Dom
	Description: Creates a unit and returns the object, required due to needing to force change side for some units (opfor & indep)
*/
params [
	["_group",grpNull,[grpNull]],
	["_desiredSide",east,[west]],
	["_class","",[""]],
	["_position",[],[[],objNull]],
	["_radius",0,[0]],
	["_special","NONE",[""]]
];

private _configSide = [_class] call DT_fnc_getConfigSide;

private _unit = objNull;
if (_desiredSide isEqualTo _configSide) then {
	_unit = _group createUnit [_class,_position,[],_radius,_special];
} else {
	private _tempGroup = createGroup [civilian,true];
	_unit = _tempGroup createUnit [_class,_position,[],_radius,_special];

	[_unit] joinSilent _group;
	deleteGroup _tempGroup;
};

_unit;