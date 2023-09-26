/*
	File: fn_clearArea.sqf
	Author: Dom
	Description: Clears a given area of AI, vehicles and associated items
*/
params [
	["_centre",[],[[],objNull]],
	["_groups",[],[[],grpNull,true]],
	["_specificObjects",[],[[]]]
];

if (_groups isEqualType true) then {
	_groups = (groups east) select {(leader _x) distance2D _centre < 600};
} else {
	if (_groups isEqualType grpNull) then {
		_groups = [_groups];
	};
};

{
	[_x] call DT_fnc_deleteGroup;
} forEach _groups;

private _objects = nearestObjects [_centre,["LandVehicle","Air","Strategic","GroundWeaponHolder","WeaponHolderSimulated"],600];
_objects insert [-1,_specificObjects,true];
{
	if (!(_x getVariable ["DT_isProtected",false]) && !(_x getVariable ["DT_playerUsed",false]) && !((typeOf _x) in DT_bluforClassesToSave)) then {
		deleteVehicle _x;
	};
} forEach _objects;