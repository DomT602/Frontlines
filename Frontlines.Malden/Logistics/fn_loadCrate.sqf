/*
	File: fn_loadCrate.sqf
	Author: Dom
	Description: Loads a crate into a vehicle
*/
params [
	["_crate",objNull,[objNull]]
];

private _transportClasses = getArray(missionConfigFile >> "Settings" >> "transportVehicles");
private _classArray = _transportClasses apply {_x select 0};
private _nearbyVehicles = nearestObjects [_crate,_classArray,15];

private _vehicle = objNull;
private _offset = [];
{
	if !(isNull _vehicle) exitWith {};
	if (alive _x) then {
		private _vehClass = typeOf _x;
		private _index = _classArray findIf {_vehClass isKindOf _x};
		if (_index isNotEqualTo -1) then {
			private _positionArray = (_transportClasses select _index) select 2;
			private _maxCrates = count _positionArray;
			private _currentCrateCount = count (_x getVariable ["DT_loadedCrates",[]]);
			if (_currentCrateCount isEqualTo _maxCrates) exitWith {};
			_offset = _positionArray select _currentCrateCount;
			_vehicle = _x;
		};
	};
} forEach _nearbyVehicles;

if (isNull _vehicle) exitWith {["No suitable vehicle nearby."] call DT_fnc_notify};

_crate attachTo [_vehicle,_offset];
[_crate,false] remoteExecCall ["enableRopeAttach",_crate];
private _currentCrates = _vehicle getVariable ["DT_loadedCrates",[]];
_currentCrates pushBack _crate;
_vehicle setVariable ["DT_loadedCrates",_currentCrates,true];