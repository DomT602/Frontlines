/*
	File: fn_getSectorTypeIndex.sqf
	Author: Dom
	Description: Returns the index of the current sector to be used when selecting from arrays
*/
params [
	["_sectorType","",[""]]
];

switch _sectorType do {
	case "military": {4};
	case "tower": {3};
	case "city": {2};
	case "factory": {1};
	default {0}; //town
};