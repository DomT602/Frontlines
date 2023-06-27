/*
	File: fn_logisticsLoop.sqf
	Author: Dom
	Description: Handles all logistic routes
*/
params ["_args","_handle"];

DT_logistics params ["_availableTrucks","_trucksInUse","_currentRoutes"];
if (_currentRoutes isEqualTo []) exitWith {
	[_handle] call CBA_fnc_removePerFrameHandler;
	DT_logisticsHandle = -1;
};

private _toDelete = [];
{
	_x params ["_from","_to","_truckCount","_startTransitTime","_endTransitTime","_carrying"];
	if (_endTransitTime < CBA_missionTime) then {
		_availableTrucks = _availableTrucks + _truckCount;
		_trucksInUse = _trucksInUse - _truckCount;
		DT_logistics set [0,_availableTrucks];
		DT_logistics set [1,_trucksInUse];
		_toDelete pushBack _forEachIndex;

		if (isNil {_to getVariable "DT_factoryResources"}) then {
			[_to,_carrying,true] call DT_fnc_adjustResources;
		} else {
			private _factoryResources = _to getVariable "DT_factoryResources";
			_factoryResources = _factoryResources vectorAdd _carrying;
			_to setVariable ["DT_factoryResources",_factoryResources,true];
		};
	};
} forEach _currentRoutes;
if (_toDelete isEqualTo []) exitWith {};

reverse _toDelete;
{
	_currentRoutes deleteAt _x;
} forEach _toDelete;

[DT_logistics,"endRoute"] remoteExecCall ["DT_fnc_updateLogistics",-2,"DT_Logi_JIP"];