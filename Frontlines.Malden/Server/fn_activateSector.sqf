/*
	File: fn_activateSector.sqf
	Author: Dom
	Description: Activates a sector
*/
params [
	["_sectorObj",objNull,[objNull]]
];
DT_activeSectors pushBack _sectorObj;
publicVariable "DT_activeSectors";

private _sectorVar = _sectorObj getVariable "DT_sectorVariable";
private _sectorType = _sectorObj getVariable "DT_sectorType";
private _sectorStrength = _sectorObj getVariable ["DT_sectorStrength",1];
private _sectorRep = _sectorObj getVariable ["DT_sectorReputation",100];

private _isCivilian = _sectorType in ["town","city","factory"];
private _isFortified = _sectorType in ["city","military"];
private _isMilitary = _sectorType isEqualTo "military";

private _sectorTypeIndex = [_sectorType] call DT_fnc_getSectorTypeIndex;
private _spawnRadius = (getArray(missionConfigFile >> "Settings" >> "sectorRadius")) select _sectorTypeIndex;

private _cratesAndIntel = [];
if (_isCivilian) then {
	private _maxCrates = getNumber(missionConfigFile >> "Settings" >> "maxSectorCrates");
	private _crateTypes = getArray(missionConfigFile >> "Logi_Setup" >> "bluforCrates");

	for "_i" from 1 to round (random _maxCrates) do {
		private _spawnPos = [_sectorObj,10,_spawnRadius,5,0,0.3,0] call BIS_fnc_findSafePos;
		if (_spawnPos isEqualTo []) exitWith {};

		private _crate = createVehicle [selectRandom _crateTypes,_spawnPos];
		_cratesAndIntel pushBack _crate;
	};

	[_sectorObj,_sectorRep,_spawnRadius] call DT_fnc_spawnCivilians;
};

private _buildings = [_sectorObj,_spawnRadius] call DT_fnc_getBuildings;
if (_buildings isNotEqualTo []) then {
	private _intelCount = getNumber(missionConfigFile >> "Settings" >> "maxSectorIntel");
	private _intelTypes = getArray(missionConfigFile >> "Settings" >> "intelObjects");

	private _spawnOptions = [];
	{
		_spawnOptions append (_x buildingPos -1);
	} forEach _sectorBuildings;
	[_spawnOptions,true] call CBA_fnc_shuffle;

	_intelCount = (round (random _intelCount)) min (count _spawnOptions);
	for "_i" from 0 to (_intelCount - 1) do {
		private _intel = createVehicle [selectRandom _intelTypes,_spawnOptions select _i];
		_intel setDir (random 360);
		_cratesAndIntel pushBack _intel;
	};
};

private _extras = [0,0,0,0];
if (_isFortified) then {_extras set [0,1]; _extras set [1,1]};
if (_isMilitary) then {_extras set [3,1]};

private _squads = [_sectorObj,_spawnRadius,([_sectorStrength,_extras] call DT_fnc_calculateEnemySquads)] call DT_fnc_createPatrols;
_squads append ([_sectorObj,_spawnRadius,true] call DT_fnc_createDefences);

private _unitCount = 0;
{
	_unitCount = _unitCount + (count units _x);
} forEach _squads;
_sectorObj setVariable ["DT_sectorUnitCount",_unitCount];

if (_isMilitary || {DT_threatLevel > 50 && {DT_threatLevel > (random 100)}}) then {
	private _timer = getNumber(missionConfigFile >> "Settings" >> "reinforcementTimer");
	[DT_fnc_callReinforcements,[_sectorObj],_timer + random (_timer / 2)] call CBA_fnc_waitAndExecute;
};

[
	DT_fnc_monitorSector,
	1,
	[_sectorObj,_spawnRadius,_squads,_cratesAndIntel,0]
] call CBA_fnc_addPerFrameHandler;