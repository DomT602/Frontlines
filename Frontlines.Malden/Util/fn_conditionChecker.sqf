/*
	File: fn_conditionChecker.sqf
	Author: Dom
	Description: Checks conditions on items in menus
*/
params [
	["_conditions","",[""]]
];

if (_conditions isEqualTo "") exitWith {true};
if (call compile _conditions) exitWith {true};
false