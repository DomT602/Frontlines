/*
	File: fn_initLogisticsMenu.sqf
	Author: Dom
	Description: Opens and populates the logistics menu
*/
private _display = createDialog ["DT_logisticsMenu",true];

DT_logistics params ["_availableTrucks","_trucksInUse","_currentRoutes"];

private _listbox = _display displayCtrl 1500;

{
	_x params ["_from","_to","","","","_carrying"];
	private _index = _listbox lbAdd format ["%1 to %2",[_from getVariable "DT_sectorName",_from getVariable "DT_fobName"] select (isNil {_from getVariable "DT_sectorName"}),[_to getVariable "DT_sectorName",_to getVariable "DT_fobName"] select (isNil {_to getVariable "DT_sectorName"})];
	_listbox lbSetData [_index,str(_x select [2,9])];
	_listbox lbSetTextRight [_index,str _carrying];
} forEach _currentRoutes;

private _fromComboBox = _display displayCtrl 2100;
private _toComboBox = _display displayCtrl 2101;

{
	private _name = _x getVariable "DT_fobName";
	private _id = netId _x;
	private _resources = [_x] call DT_fnc_getCurrentResources;

	private _index = _fromComboBox lbAdd _name;
	_fromComboBox lbSetData [_index,_id];
	_fromComboBox lbSetTextRight [_index,str _resources];
	_toComboBox lbAdd _name;
	_toComboBox lbSetData [_index,_id];
	_toComboBox lbSetTextRight [_index,str _resources];
} forEach DT_allFOBs;

private _factories = [["factory"],true] call DT_fnc_getSectorsByType;
{
	private _name = _x getVariable "DT_sectorName";
	private _resources = _x getVariable "DT_factoryResources";
	private _id = netId _x;

	private _index = _fromComboBox lbAdd _name;
	_fromComboBox lbSetData [_index,_id];
	_fromComboBox lbSetTextRight [_index,str _resources];
	_toComboBox lbAdd _name;
	_toComboBox lbSetData [_index,_id];
	_toComboBox lbSetTextRight [_index,str _resources];
} forEach _factories;

_fromComboBox lbSetCurSel 0;
_toComboBox lbSetCurSel 0;

[] call DT_fnc_onLogisticsMenuLbChange;