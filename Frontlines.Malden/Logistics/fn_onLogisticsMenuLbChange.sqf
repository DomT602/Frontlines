/*
	File: fn_onLogisticsMenuLChange.sqf
	Author: Dom
	Description: Called on a new selection in the logistics (current route) menu
*/
params [
	["_control",controlNull,[controlNull]],
	["_index",0,[0]]
];

private _display = findDisplay 9645;
private _textBox = _display displayCtrl 1100;

DT_logistics params ["_availableTrucks","_trucksInUse"];
private _text = format ["
<t size='1.2'>Logistics Status:</t><br/>
Trucks available: <t color='#00BF00'>%1</t><br/>
Trucks in use: <t color='#BFBF00'>%2</t><br/>
Trucks capacity: %3 resources<br/>",
_availableTrucks,_trucksInUse,getNumber(missionConfigFile >> "Settings" >> "logisticsTruckCapacity")
];

if !(isNull _control) then {
	(parseSimpleArray (_control lbData _index)) params ["_truckCount","","_endTransitTime","_carrying"];
	private _timeRemaining = ceil ((_endTransitTime - CBA_missionTime) / 60);
	_carrying params ["_supplies","_fuel","_ammo"];

_text = format ["%1
<t size='1.2'>Route:</t><br/>
%2 using %3 trucks<br/>
Time remaining: %4 minutes<br/>
<t color='#00BF00'>Supplies: %5 </t>
<t color='#BFBF00'>Fuel: %6 </t>
<t color='#BF0000'>Ammo: %7</t>
",_text,_control lbText _index,_truckCount,_timeRemaining,_supplies,_fuel,_ammo
];
};

_textBox ctrlSetStructuredText parseText _text;