/*
	File: fn_onFactoryMapPress.sqf
	Author: Dom
	Description: Checks if the player has selected a factory on the map and if so zooms to it
*/
params [
	["_control",controlNull,[controlNull]]
];

(ctrlMapMouseOver _control) params ["_type","_value"];
if (_type isEqualTo "marker") then {
	private _factories = [["factory"],true] call DT_fnc_getSectorsByType;
	private _factoryIndex = _factories findIf {_x getVariable ["DT_sectorVariable",""] isEqualTo _value};
	if (_factoryIndex isEqualTo -1) exitWith {};

	private _display = findDisplay 9643;
	private _listbox = _display displayCtrl 1500;
	private _sector = _factories select _factoryIndex;

	for "_i" from 0 to (lbSize _listbox)-1 do {
		if (_sector isEqualTo (objectFromNetId (_listbox lbData _i))) exitWith {
			_listbox lbSetCurSel _i;
		};
	};
};