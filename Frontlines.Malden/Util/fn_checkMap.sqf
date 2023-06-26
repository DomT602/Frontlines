/*
	File: fn_checkMap.sqf
	Author: Dom
	Description: Handles opening of the map
*/
params ["_mapIsOpened","_mapIsForced"];

if (_mapIsOpened) then {
	[] call DT_fnc_createBluforMarkers;

	private _map = findDisplay 12;
	private _control = _map displayCtrl 51;
	_control ctrlAddEventHandler ["MouseButtonDown",DT_fnc_showMapInfo];

	private _button = _map ctrlCreate ["DT_mapButton",-1];
};