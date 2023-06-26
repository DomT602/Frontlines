/*
	File: fn_unloadCrate.sqf
	Author: Dom
	Description: Unloads a crate from a vehicle
*/
params [
	["_vehicle",objNull,[objNull]]
];
if (isEngineOn _vehicle) exitWith {["Turn off the engine before unloading crates."] call DT_fnc_notify};

_vehicle allowDamage false;
private _vehType = typeOf _vehicle;
private _transportClasses = getArray(missionConfigFile >> "Settings" >> "transportVehicles");
private _index = _transportClasses findIf {_vehType isKindOf (_x select 0)};
private _offset = (_transportClasses select _index) select 1;

private _currentCrates = _vehicle getVariable ["DT_loadedCrates",[]];
private _vehicleDirection = getDir _vehicle;
{
	private _nextPos = _vehicle getPos [_offset,_vehicleDirection];
	_nextPos set [2,0];
	detach _x;
	_x setPosATL _nextPos;
	_offset = _offset - 2;
	[_x,true] remoteExecCall ["enableRopeAttach",_x];
} forEach _currentCrates;

_vehicle setVariable ["DT_loadedCrates",nil,true];
_vehicle allowDamage true;
["Vehicle unloaded."] call DT_fnc_notify;