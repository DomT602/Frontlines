/*
	File: fn_civilianKilled.sqf
	Author: Dom
	Description: Handles the death of a civilian
*/
params ["_unit","","_instigator"];

private _lastInstigator = _unit getVariable ["ace_medical_lastInstigator",objNull];

if (isPlayer _lastInstigator || {isPlayer _instigator}) then {
	["A civilian has been killed."] remoteExecCall ["DT_fnc_notify",0];
	private _nearestSector = [_unit,["town","city","factory"]] call DT_fnc_getNearestSector;
	if !(isNull _nearestSector) then {
		[_nearestSector,getNumber (missionConfigFile >> "Settings" >> "killedCivRepLoss")] call DT_fnc_updateCivRep;

		private _civsKilled = _nearestSector getVariable ["DT_sectorCivsKilled",0];
		_nearestSector setVariable ["DT_sectorCivsKilled",_civsKilled + 1];
	};
};