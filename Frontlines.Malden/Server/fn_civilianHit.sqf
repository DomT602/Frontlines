/*
	File: fn_civilianHit.sqf
	Author: Dom
	Description: Handles the injury of a civilian
*/
params ["_unit","","","_instigator"];

if (isPlayer _instigator) then {
	["A civilian has been injured."] remoteExecCall ["DT_fnc_notify",0];
	private _nearestSector = [_unit,["town","city","factory"]] call DT_fnc_getNearestSector;
	[_nearestSector,getNumber (missionConfigFile >> "Settings" >> "injuredCivRepLoss")] call DT_fnc_updateCivRep;
};