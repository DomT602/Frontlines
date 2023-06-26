/*
	File: fn_compareResources.sqf
	Author: Dom
	Description: Compares two arrays and returns true if first is bigger then second
*/
params [
	["_ownedRes",[],[[]]],
	["_comparisonRes",[],[[]]]
];

_ownedRes params ["_ownedSupplies","_ownedFuel","_ownedAmmo"];
_comparisonRes params ["_neededSupplies","_neededFuel","_neededAmmo"];

_ownedSupplies >= _neededSupplies && {_ownedFuel >= _neededFuel && {_ownedAmmo >= _neededAmmo}}