/*
	File: fn_autoCrateRetrieve.sqf
	Author: Dom
	Description: Begins the automatic crate retrieval process
*/
params [
	["_sector",objNull,[objNull]]
];

private _crateTypes = getArray(missionConfigFile >> "Logi_Setup" >> "bluforCrates");
private _radius = (getArray(missionConfigFile >> "Settings" >> "sectorRadius")) select ([_sector getVariable "DT_sectorType"] call DT_fnc_getSectorTypeIndex);

private _crates = nearestObjects [_sector,_crateTypes,(_radius * 1.1),true];
if (_crates isEqualTo []) exitWith {};

private _resources = [0,0,0];
{
	private _index = _crateTypes find (typeOf _x);
	_resources set [_index,(_resources select _index) + 100];
	deleteVehicle _x;
} forEach _crates;

private _nearFob = [_sector] call DT_fnc_getNearestFOB;
private _distance = _sector distance _nearFob;
private _time = ceil ((_distance / 1000) * 2);

[
	{
		params ["_resources","_nearFob"];
		[_nearFob,_resources,true] call DT_fnc_adjustResources;
	},
	[_resources,_nearFob],
	(_time * 60)
] call CBA_fnc_waitAndExecute;