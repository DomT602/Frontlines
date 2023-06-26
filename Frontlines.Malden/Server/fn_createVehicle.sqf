/*
	File: fn_createVehicle.sqf
	Author: Dom
	Description: Creates the opfor vehicle pulled from the config
*/
params [
	["_classData","",["",[]]],
	["_position",[],[[],objNull]],
	["_radius",100,[0]],
	["_fillWithPax",false,[true]],
	["_side",east,[east]]
];

private _className = _classData;
private _spawnFactionCrew = false;
if (_classData isEqualType []) then {
	_className = _classData select 0;
	_spawnFactionCrew = true;
};

private _spawnPos = _position;
if (_radius isNotEqualTo 0) then {
	private _nearRoads = _position nearRoads (_radius * 2);
	if (_nearRoads isEqualTo []) then {
		_spawnPos = [_position,0,_radius,10,0,0.4,0] call BIS_fnc_findSafePos;
	} else {
		_spawnPos = getPosATL (selectRandom _nearRoads);
	};
};

private _vehicle = createVehicle [_className,_spawnPos];
private _group = createGroup [_side,true];
if (_spawnFactionCrew) then {
	[_group,_vehicle,_side] call DT_fnc_forceCreateFactionCrew;
} else {
	private _crew = createVehicleCrew _vehicle;
	(units _crew) joinSilent _group;
};

if (_fillWithPax) then {
	private _squadComposition = if (_side isEqualTo east) then {selectRandom (getArray(missionConfigFile >> "Opfor_Setup" >> "opforSquads"))} else {selectRandom (getArray(missionConfigFile >> "Guerilla_Setup" >> "guerillaSquads"))};
	private _seatCount = getNumber(configOf _vehicle >> "transportSoldier");
	private _troopCount = ceil (random [1,_seatCount / 2,_seatCount]);

	for "_i" from 1 to _troopCount do {
		private _unit = [_group,_side,selectRandom _squadComposition,_vehicle] call DT_fnc_createUnit;
		_unit moveInCargo _vehicle;
	};
};

[_group] call CBA_fnc_clearWaypoints;
if (_side isEqualTo east && {getNumber(missionConfigFile >> "Settings" >> "opforVehicleLockState") isEqualTo 1}) then {
	_vehicle lock 3;
};
_vehicle setUnloadInCombat [true,false];

_group;