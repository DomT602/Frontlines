/*
	File: fn_startSideMission.sqf
	Author: Dom
	Description: Randomly selects a new side mission that hasn't recently been used
*/
params [
	["_lastMissionType","",[""]]
];

private _timer = getNumber(missionConfigFile >> "Settings" >> "sideMissionTimer");
private _sideMissions = [
	["destroyAA","DT_threatLevel > 33",DT_fnc_destroyAA],
	["destroyArtillery","DT_threatLevel > 33",DT_fnc_destroyArtillery],
	["destroyJammer","DT_threatLevel > 33",DT_fnc_destroyJammer],
	["convoyAmbush","DT_threatLevel > 50 && {(DT_logistics select 2) isNotEqualTo []}",DT_fnc_ambushLogisticsConvoy],
	["counterAttack","DT_threatLevel > 33 && {[] call DT_fnc_getMissionProgress > 0.1}",DT_fnc_sectorCounterAttack],
	["fobAssault","DT_threatLevel > 80 && {count playableUnits > 3}",DT_fnc_fobAssault],
	["repairRequest","private _possibleSectors = [['town','city','factory'],true] call DT_fnc_getSectorsByType; (_possibleSectors findIf {_x getVariable ['DT_destroyedBuildingCount',0] isNotEqualTo 0}) isNotEqualTo -1",DT_fnc_repairRequest]
];

private _index = _sideMissions findIf {_x select 0 in _lastMissionType};
_sideMissions deleteAt _index;

/*
{
	_x params ["","_conditions"];
	if !([_conditions] call DT_fnc_conditionChecker) then {
		_sideMissions deleteAt _forEachIndex;
	};
} forEachReversed _sideMissions;
*/
private _possibleMissions = []; //replace with forEachReversed in future
{
	_x params ["","_conditions"];
	if ([_conditions] call DT_fnc_conditionChecker) then {
		_possibleMissions pushBack _x;
	};
} forEach _sideMissions;

if (_possibleMissions isEqualTo [] || {playableUnits isEqualTo []}) exitWith {[DT_fnc_startSideMission,"",_timer] call CBA_fnc_waitAndExecute};

(selectRandom _possibleMissions) params ["_type","","_code"];
[] call _code;

[DT_fnc_startSideMission,_type,_timer + (random _timer)] call CBA_fnc_waitAndExecute;