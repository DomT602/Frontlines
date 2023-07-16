/*
	File: fn_logisticsStartRoute.sqf
	Author: Dom
	Description: Begins a logistics route
*/
params ["_from","_to","_truckCount","_startTransitTime","_endTransitTime","_carrying","_fuelRequired","_fromIndex"];

DT_logistics params ["_availableTrucks","_trucksInUse","_currentRoutes"];
private _nearFOBRes = [_from] call DT_fnc_getCurrentResources;
private _fuelAvailable = _nearFOBRes select 1;
if (_truckCount > _availableTrucks || {_fuelRequired > _fuelAvailable}) exitWith {["Something went wrong."] remoteExecCall ["DT_fnc_notify",remoteExecutedOwner]};

if (isNil {_from getVariable "DT_factoryResources"}) then {
	[_from,_carrying,false] call DT_fnc_adjustResources;
} else {
	private _factoryResources = _from getVariable "DT_factoryResources";
	_factoryResources = _factoryResources vectorDiff _carrying;
	_from setVariable ["DT_factoryResources",_factoryResources,true];
};
[_from,[0,_fuelRequired,0],false] call DT_fnc_adjustResources;

private _newRoute = [_from,_to,_truckCount,_startTransitTime,_endTransitTime,_carrying];
_currentRoutes pushBack _newRoute;
DT_logistics set [0,(_availableTrucks - _truckCount)];
DT_logistics set [1,(_trucksInUse + _truckCount)];
[DT_logistics,"startRoute",_newRoute,_fromIndex] remoteExecCall ["DT_fnc_updateLogistics",-2,"DT_Logi_JIP"];

if ((missionNamespace getVariable ["DT_logisticsHandle",-1]) isEqualTo -1) then {
	DT_logisticsHandle = [DT_fnc_logisticsLoop,10] call CBA_fnc_addPerFrameHandler;
};