/*
	File: fn_getCaptureRatio.sqf
	Author: Dom
	Description: Obtains the capture ratio of an objective
*/
params [
	["_sectorObj",objNull,[objNull]],
	["_radius",200,[0]]
];

private _nearEntities = _sectorObj nearEntities [["CAManBase","LandVehicle","Ship","Air"],_radius];
private _bluforCount = 0;
private _opforCount = 0;

{
	private _side = side _x;
	if (_side isEqualTo west) then {
		_bluforCount = _bluforCount + (count (crew _x select {alive _x}));
	} else {
		if (_side isEqualTo east && {!(_x getVariable ["ace_captives_ishandcuffed",false])}) then {
			_opforCount = _opforCount + (count crew _x);
		};
	};
} forEach _nearEntities;

private _ratio = 0;
if (_bluforCount > 0 && {_opforCount > 0}) then {
	_ratio = _bluforCount / (_bluforCount + _opforCount);
} else {
	if (_bluforCount > 0 && {_opforCount isEqualTo 0}) then {
		_ratio = 1;
	};
};

_ratio;
