/*
	File: fn_storeCrate.sqf
	Author: Dom
	Description: Stores the crate and adds to resource pool
*/
params [
	["_crate",objNull,[objNull]]
];

private _crateClass = typeOf _crate;
private _pos = getPosATL _crate;
deleteVehicle _crate;

private _crateArray = getArray(missionConfigFile >> "Logi_Setup" >> "bluforCrates");
private _index = _crateArray find _crateClass;
if (_index isEqualTo -1) exitWith {};

private _vector = [0,0,0];
_vector set [_index,100];

if ([_pos] call DT_fnc_isNearFOB) then {
	[_pos,_vector,true] call DT_fnc_adjustResources;
} else {
	private _nearestFactory = [_pos,["factory"]] call DT_fnc_getNearestSector;
	private _resources = _nearestFactory getVariable ["DT_factoryResources",[0,0,0]];
	_resources = _resources vectorAdd _vector;
	_nearestFactory setVariable ["DT_factoryResources",_resources,true];
};