/*
	File: fn_updateThreat.sqf
	Author: Dom
	Description: Updates the global threat level
*/
params [
	["_value",0,[0]]
];

private _newThreat = 0 max ((DT_threatLevel + _value) min 100);
missionNamespace setVariable ["DT_threatLevel",_newThreat,true];