/*
	File: fn_getConfigSide.sqf
	Author: Dom
	Description: Gets the side of the unit according to its config file
*/
params [
	["_class","",[""]]
];

private _configValue = getNumber(configFile >> "CfgVehicles" >> _class >> "side");

switch _configValue do {
	case 0: {east};
	case 1: {west};
	case 2: {independent};
	default {civilian};
};