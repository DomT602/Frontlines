/*
	File: fn_fetchDetails.sqf
	Author: Dom
	Description: Fetches details on an item - needed for different classes
*/
params [
	["_className","",["",[]]]
];
if (_className isEqualType []) then {_className = _className select 0};

private _section = call {
	if (isClass(configFile >> "CfgMagazines" >> _className)) exitWith {"CfgMagazines"};
	if (isClass(configFile >> "CfgWeapons" >> _className)) exitWith {"CfgWeapons"};
	if (isClass(configFile >> "CfgVehicles" >> _className)) exitWith {"CfgVehicles"};
	if (isClass(configFile >> "CfgGlasses" >> _className)) exitWith {"CfgGlasses"};
};

private _config = configFile >> _section >> _className;

[getText(_config >> "displayName"),getText(_config >> "picture")];
