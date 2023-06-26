/*
	File: fn_onFactoryMenuLbChange.sqf
	Author: Dom
	Description: Called on a new selection in the factory menu
*/
params [
	["_control",controlNull,[controlNull]],
	["_index",0,[0]]
];

private _display = findDisplay 9643;
private _object = objectFromNetId (_control lbData _index);
private _type = _object getVariable "DT_factoryType";
(_object getVariable "DT_factoryResources") params ["_supplies","_fuel","_ammo"];

(_display displayCtrl 1600) lbSetCurSel (_type + 1);
_type = switch _type do {
	case -1: {"None"};
	case 0: {"Supplies"};
	case 1: {"Fuel"};
	case 2: {"Ammo"};
};

private _text = format ["
<t align='center' font='PuristaBold' size='1.6'>%1</t><br/>
<t font='PuristaLight'>Producing: %2</t><br/>
<t color='#00BF00' font='PuristaLight'>Supplies: %3</t>
<t color='#BFBF00' font='PuristaLight' align='center'>Fuel: %4</t>
<t color='#BF0000' font='PuristaLight' align='right'>Ammo: %5</t>"
,_control lbText _index,_type,_supplies,_fuel,_ammo];

(_display displayCtrl 1100) ctrlSetStructuredText parseText _text;

private _mapControl = _display displayCtrl 1200;
_mapControl ctrlMapAnimAdd [2,0.3,_object];
ctrlMapAnimCommit _mapControl;