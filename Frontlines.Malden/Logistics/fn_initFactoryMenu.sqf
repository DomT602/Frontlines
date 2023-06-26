/*
	File: fn_initFactoryMenu.sqf
	Author: Dom
	Description: Opens and populates the factory menu
*/

private _display = createDialog ["DT_factoryMenu",true];
private _listbox = _display displayCtrl 1500;

private _factories = [["factory"],true] call DT_fnc_getSectorsByType;
{
	private _name = _x getVariable "DT_sectorName";
	private _type = _x getVariable "DT_factoryType";

	private _index = _listbox lbAdd _name;
	_listbox lbSetData [_index,netId _x];

	if (_type isNotEqualTo -1) then {
		private _colour = switch _type do {
			case 0: {[0,0.75,0,1]};
			case 1: {[0.75,0.75,0,1]};
			case 2: {[0.75,0,0,1]};
		};
		_listbox lbSetColor [_index,_colour];
	};
} forEach _factories;

_listbox lbSetCurSel 0;

private _mapControl = _display displayCtrl 1200;
_mapControl ctrlAddEventHandler ["MouseButtonDown",{
	params ["_control"];
	(ctrlMapMouseOver _control) params ["_type","_value"];
	if (_type isEqualTo "marker") then {
		private _factories = [["factory"],true] call DT_fnc_getSectorsByType;
		private _factoryIndex = _factories findIf {_x getVariable ["DT_sectorVariable",""] isEqualTo _value};
		if (_factoryIndex isEqualTo -1) exitWith {};

		private _display = findDisplay 9642;
		private _listbox = _display displayCtrl 1500;
		private _sector = _factories select _factoryIndex;

		for "_i" from 0 to (lbSize _listbox)-1 do {
			if (_sector isEqualTo (objectFromNetId (_listbox lbData _i))) exitWith {
				_listbox lbSetCurSel _i;
			};
		};
	};
}];