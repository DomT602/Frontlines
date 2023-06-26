/*
	File: fn_logisticsMenuStartRoute.sqf
	Author: Dom
	Description: Final checks before sending route to server to begin
*/

private _display = findDisplay 9645;
private _fromCombobox = _display displayCtrl 2100;
private _fromIndex = lbCurSel _fromCombobox;
private _toCombobox = _display displayCtrl 2101;
private _from = objectFromNetId (_fromCombobox lbData _fromIndex);
private _to = objectFromNetId (_toCombobox lbData (lbCurSel _toCombobox));

private _suppliesToMove = ctrlText (_display displayCtrl 1400);
private _fuelToMove = ctrlText (_display displayCtrl 1401);
private _ammoToMove = ctrlText (_display displayCtrl 1402);
if (!([_suppliesToMove] call DT_fnc_checkNumber) || {!([_fuelToMove] call DT_fnc_checkNumber) || {!([_ammoToMove] call DT_fnc_checkNumber)}}) exitWith {_button ctrlEnable false};
_suppliesToMove = parseNumber _suppliesToMove;
_fuelToMove = parseNumber _fuelToMove;
_ammoToMove = parseNumber _ammoToMove;
private _totalToMove = _suppliesToMove + _fuelToMove + _ammoToMove;
if (_totalToMove isEqualTo 0) exitWith {["Nothing to move."] call DT_fnc_notify};

private _travelDistance = _from distance2D _to;
private _travelTime = ceil ((_travelDistance / 1000) * 4);
private _requiredTrucks = ceil (_totalToMove / (getNumber(missionConfigFile >> "Settings" >> "logisticsTruckCapacity")));
private _travelFuel = _requiredTrucks * (_travelTime * 2);
private _arrivalTime = CBA_missionTime + (_travelTime * 60);

[_from,_to,_requiredTrucks,CBA_missionTime,_arrivalTime,[_suppliesToMove,_fuelToMove,_ammoToMove],_travelFuel,_fromIndex] remoteExecCall ["DT_fnc_logisticsStartRoute",2];
["Request sent."] call DT_fnc_notify;

private _button = _display displayCtrl 2401;
_button ctrlEnable false;