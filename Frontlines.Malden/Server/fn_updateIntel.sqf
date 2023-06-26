/*
	File: fn_updateIntel.sqf
	Author: Dom
	Description: Updates the intel pool
*/
params [
	["_value",0,[0]]
];

private _newIntel = 0 max (DT_intelCount + _value);
missionNamespace setVariable ["DT_intelCount",_newIntel,true];