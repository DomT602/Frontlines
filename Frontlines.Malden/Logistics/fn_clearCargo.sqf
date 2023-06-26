/*
	File: fn_clearCargo.sqf
	Author: Dom
	Description: Empties cargo of specified object
*/
params [
	["_object",objNull,[objNull]]
];
if (isNull _object) exitWith {};

private _class = typeOf _object;
if ("UK3CB" in _class) then { //exception for 3CB mods, as they keep ammo in vehicle
	(getMagazineCargo _object) params ["_magClasses","_magCounts"];
	clearMagazineCargoGlobal _object;

	{
		if ("UK3CB" in _x) then {
			_object addMagazineCargoGlobal [_x,(_magCounts select _forEachIndex)];
		};
	} forEach _magClasses;
} else {
	clearMagazineCargoGlobal _object;
};

clearWeaponCargoGlobal _object;
clearBackpackCargoGlobal _object;
clearItemCargoGlobal _object;