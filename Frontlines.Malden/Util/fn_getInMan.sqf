/*
	File: fn_getInMan.sqf
	Author: Dom
	Description: Handles entry into any vehicle
*/
params ["_unit","_role","_vehicle","_turret"];

if !([_vehicle,true] call DT_fnc_checkVehicleAccess) exitWith {};

if !(_vehicle getVariable ["DT_playerUsed",false]) then {
	private _civVehicles = getArray(missionConfigFile >> "Civilian_Setup" >> "civilianVehicleTypes");
	_civVehicles append getArray(missionConfigFile >> "Civilian_Setup" >> "civilianAircraftTypes");
	if ((typeOf _vehicle) in _civVehicles) then {
		private _penalty = getNumber(missionConfigFile >> "Settings" >> "seizedCivVehicleRepLoss");
		[[_vehicle,["town","city","factory"]] call DT_fnc_getNearestSector,_penalty] remoteExecCall ["DT_fnc_updateCivRep",2];
		["A civilian vehicle has been seized."] remoteExecCall ["DT_fnc_notify",0];
	};
	_vehicle setVariable ["DT_playerUsed",true,true];
};