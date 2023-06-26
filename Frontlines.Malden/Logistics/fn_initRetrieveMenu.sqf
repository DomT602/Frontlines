/*
	File: fn_initRetrieveMenu.sqf
	Author: Dom
	Description: Opens the retrieve menu and populates it with the amount of crates available to withdraw
*/

private _storedResources = [];
if ([player] call DT_fnc_isNearFOB) then {
	_storedResources = [player] call DT_fnc_getCurrentResources;
} else {
	private _nearestFactory = [player,["factory"]] call DT_fnc_getNearestSector;
	_storedResources = _nearestFactory getVariable "DT_factoryResources";
};
if (_storedResources isEqualTo [0,0,0]) exitWith {["No resources are here."] call DT_fnc_notify};

private _display = createDialog ["DT_retrieveMenu",true];
private _supplyBox = _display displayCtrl 1400;
private _fuelBox = _display displayCtrl 1401;
private _ammoBox = _display displayCtrl 1402;

_storedResources params ["_supplies","_fuel","_ammo"];
_supplyBox ctrlSetText str floor(_supplies / 100);
_fuelBox ctrlSetText str floor(_fuel / 100);
_ammoBox ctrlSetText str floor(_ammo / 100);