/*
	File: fn_checkVehicleAccess.sqf
	Author: Dom
	Description: Checks if a player can use a vehicle
*/
params [
	["_vehicle",objNull,[objNull]],
	["_moveOutOnly",false,[true]]
];

private _seatsRestricted = (getNumber(missionConfigFile >> "Settings" >> "vehicleSeatRestrictions")) isEqualTo 1;
if !(_seatsRestricted) exitWith {true};

if (DT_isZeus) exitWith {true};
if (_vehicle isKindOf "ParachuteBase") exitWith {true};

private _cargoIndex = _vehicle getCargoIndex player;
if (_cargoIndex isNotEqualTo -1) exitWith {true};

private _isPilot = driver _vehicle isEqualTo player;
if (_vehicle isKindOf "Air" && {_isPilot}) exitWith {
	if (player getVariable ["DT_role","rifleman"] isEqualTo "pilot") exitWith {
		true;
	};
	["You must be a pilot to use this vehicle."] call DT_fnc_notify;
	moveOut player;
	if !(_moveOutOnly) then {player moveInCargo _vehicle};
	false;
};

if (_vehicle isKindOf "Tank" && {!(_vehicle isKindOf "APC_Tracked_02_base_F")}) exitWith {
	if (player getVariable ["DT_role","rifleman"] in ["commander","crewman","engineer"]) exitWith {
		true;
	};
	["You are not authorised use this vehicle."] call DT_fnc_notify;
	moveOut player;
	if !(_moveOutOnly) then {player moveInCargo _vehicle};
	false;
};

true;