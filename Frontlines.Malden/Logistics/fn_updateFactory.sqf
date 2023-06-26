/*
	File: fn_updateFactoryProduction.sqf
	Author: Dom
	Description: Updates what a factory produces
*/

private _display = findDisplay 9643;
private _listbox = _display displayCtrl 1500;
private _index = lbCurSel _listbox;
private _object = objectFromNetId (_listbox lbData _index);
private _toolbox = _display displayCtrl 1600;
private _toolboxIndex = (lbCurSel _toolbox) - 1;

private _type = _object getVariable "DT_factoryType";
private _resources = _object getVariable "DT_factoryResources";
if (_type isEqualTo _toolboxIndex) exitWith {["No update required."] call DT_fnc_notify};
_resources params ["_suppliesAvailable"];
if (_suppliesAvailable < 100) exitWith {["100 supplies need to be available at the factory to change its production."] call DT_fnc_notify};

_resources = _resources vectorDiff [100,0,0];
_object setVariable ["DT_factoryType",_toolboxIndex,true];
_object setVariable ["DT_factoryResources",_resources,true]; 

["Factory updated."] call DT_fnc_notify;

private _colour = switch _toolboxIndex do {
	case -1: {[1,1,1,1]};
	case 0: {[0,0.75,0,1]};
	case 1: {[0.75,0.75,0,1]};
	case 2: {[0.75,0,0,1]};
};

_listbox lbSetColor [_index,_colour];
_listbox lbSetCurSel _index;