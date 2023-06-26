/*
	File: fn_setupUAV.sqf
	Author: Dom
	Description: Sets up a UAV, ensuring it can be used by players
*/
params [
	["_object",objNull,[objNull]]
];

private _configSide = [typeOf _object] call DT_fnc_getConfigSide;

private _group = createVehicleCrew _object;
if (_configSide isNotEqualTo west) then {
	private _westGroup = createGroup [west,true];
	(units _group) joinSilent _westGroup;
};