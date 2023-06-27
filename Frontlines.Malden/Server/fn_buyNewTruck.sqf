/*
	File: fn_buyNewTruck.sqf
	Author: Dom
	Description: Buys a logistics truck
*/
params [
	["_unit",objNull,[objNull]]
];

private _nearFOB = [_unit] call DT_fnc_getNearestFob;
([_nearFOB] call DT_fnc_getCurrentResources) params ["_supplies"];
DT_logistics params ["_availableTrucks"];

if (_supplies >= 100) then {
	[_nearFOB,[100,0,0],_false] call DT_fnc_adjustResources;
	DT_logistics set [0,(DT_logistics select 0) + 1];
	[DT_logistics,"newTruck",_nearFOB] remoteExecCall ["DT_fnc_updateLogistics",-2,"DT_Logi_JIP"];
} else {
	["You need 100 supplies at the nearest FOB to buy a new truck."] remoteExecCall ["DT_fnc_notify",_unit];
};