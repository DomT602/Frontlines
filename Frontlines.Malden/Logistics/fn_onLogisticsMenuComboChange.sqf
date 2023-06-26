/*
	File: fn_onLogisticsMenuComboChange.sqf
	Author: Dom
	Description: Called on a new selection in the logistics (new route) menu
*/
params [
	["_control",controlNull,[controlNull]],
	["_index",0,[0]]
];

private _display = findDisplay 9645;
private _fromCombobox = _display displayCtrl 2100;
private _toCombobox = _display displayCtrl 2101;
private _from = objectFromNetId (_fromCombobox lbData (lbCurSel _fromCombobox));
private _to = objectFromNetId (_toCombobox lbData (lbCurSel _toCombobox));
private _fromName = [_from getVariable "DT_sectorName",_from getVariable "DT_fobName"] select (isNil {_from getVariable "DT_sectorName"});
private _toName = [_to getVariable "DT_sectorName",_to getVariable "DT_fobName"] select (isNil {_to getVariable "DT_sectorName"});
private _resources = [_from getVariable "DT_factoryResources",[_from] call DT_fnc_getCurrentResources] select (isNil {_from getVariable "DT_factoryResources"});

private _textBox = _display displayCtrl 1101;
private _button = _display displayCtrl 2401;
private _text = format ["<t size='1.2'>New Route:</t><br/>
%1 to %2
",_fromName,_toName
];

if (_from isEqualTo _to) exitWith {
	_textBox ctrlSetStructuredText parseText _text;
	_button ctrlEnable false;
};

private _mapTarget = if (_control isEqualTo _fromCombobox) then {_from} else {_to};
private _mapControl = _display displayCtrl 1200;
_mapControl ctrlMapAnimAdd [2,0.3,_mapTarget];
ctrlMapAnimCommit _mapControl;

private _suppliesToMove = ctrlText (_display displayCtrl 1400);
private _fuelToMove = ctrlText (_display displayCtrl 1401);
private _ammoToMove = ctrlText (_display displayCtrl 1402);
if (!([_suppliesToMove] call DT_fnc_checkNumber) || {!([_fuelToMove] call DT_fnc_checkNumber) || {!([_ammoToMove] call DT_fnc_checkNumber)}}) exitWith {_button ctrlEnable false};
_suppliesToMove = parseNumber _suppliesToMove;
_fuelToMove = parseNumber _fuelToMove;
_ammoToMove = parseNumber _ammoToMove;
private _totalToMove = _suppliesToMove + _fuelToMove + _ammoToMove;
if (_totalToMove isEqualTo 0) exitWith {
	_textBox ctrlSetStructuredText parseText _text;
	_button ctrlEnable false;
};

private _travelDistance = _from distance2D _to;
private _travelTime = ceil ((_travelDistance / 1000) * 4);
private _requiredTrucks = ceil (_totalToMove / (getNumber(missionConfigFile >> "Settings" >> "logisticsTruckCapacity")));
private _travelFuel = _requiredTrucks * (_travelTime * 2);

private _text = format ["<t size='1.2'>New Route:</t><br/>
%1 to %2 using %3 truck(s)<br/>
Total travel time: %4 minutes<br/>
Total fuel required: %5 litres<br/>
",_fromName,_toName,_requiredTrucks,_travelTime,_travelFuel
];

private _buttonAvailable = true;
private _nearFOBRes = [_from] call DT_fnc_getCurrentResources;
if (_travelFuel > (_nearFOBRes select 1)) then {
	_buttonAvailable = false;
_text = format ["%1
<t color='#BFBF00'>Not enough fuel at nearest FOB</t><br/>
",_text
];
};

if (_requiredTrucks > (DT_logistics select 0)) then {
	_buttonAvailable = false;
_text = format ["%1
<t color='#BFBF00'>Not enough trucks</t><br/>
",_text
];
};

if !([_resources,[_suppliesToMove,_fuelToMove,_ammoToMove]] call DT_fnc_compareResources) then {
	_buttonAvailable = false;
_text = format ["%1
<t color='#BFBF00'>Not enough resources at the location</t><br/>
",_text
];
};

_textBox ctrlSetStructuredText parseText _text;
_button ctrlEnable _buttonAvailable;