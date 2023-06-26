/*
	File: fn_nameFob.sqf
	Author: Dom
	Description: Renames a FOB and updates its marker
*/

private _display = findDisplay 9650;
private _newName = ctrlText (_display displayCtrl 1400);
private _fob = [player] call DT_fnc_getNearestFob;

closeDialog 0;

_fob setVariable ["DT_fobName",_newName,true];
(_fob getVariable "DT_fobVariable") setMarkerText _newName;