/*
	File: fn_towerDestroyed.sqf
	Author: Dom
	Description: Reduces threat if the tower was destroyed recently after capture
*/
params ["_unit","_killer","_instigator","_useEffects"];

private _sector = [_unit,["tower"]] call DT_fnc_getNearestSector;
private _captureTimer = missionNamespace getVariable [format["DT_%1CapTime",(_sector getVariable "DT_sectorVariable")],-1500];
private _timer = getNumber(missionConfigFile >> "Settings" >> "radioTowerDestructionTimer");

if (_captureTimer + _timer > CBA_missionTime || {!(_sector getVariable ["DT_sectorOwned",false])}) then {
	private _threatReduction = getNumber(missionConfigFile >> "Settings" >> "radioTowerThreatReduction");
	[_threatReduction] call DT_fnc_updateThreat;
	[format["The destruction of a radio tower has adjusted the threat level by %1.",_threatReduction]] remoteExecCall ["DT_fnc_notify",0];
};

_sector setVariable ["DT_towerDestroyed",true,true];