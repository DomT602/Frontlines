/*
	File: fn_destroyConvoy.sqf
	Author: Dom
	Description: Creates and monitors mission to destroy a nearby convoy
*/
private _frontlineOpforSectors = ([false] call DT_fnc_getFrontlineSectors) select {!(_x in DT_activeSectors)};
private _recievingSector = selectRandom _frontlineOpforSectors;
private _sectorTypeIndex = [_recievingSector getVariable "DT_sectorType"] call DT_fnc_getSectorTypeIndex;
private _radius = (getArray(missionConfigFile >> "Settings" >> "sectorRadius")) select _sectorTypeIndex;
private _opforFactories = ([["factory"]] call DT_fnc_getSectorsByType) select {!(_x getVariable ["DT_sectorOwned",false]) && {(_x distance2D _recievingSector) > 3000}};
private _sendingSector = selectRandom _opforFactories;

private _marker = ["opforConvoy",_recievingSector,false,"ColorRed","mil_objective",1.5,"Incoming Convoy"] call DT_fnc_createMarker;
[format["An enemy supply convoy that started at %1 is inbound to %2.",_sendingSector getVariable "DT_sectorName",_recievingSector getVariable "DT_sectorName"],"generalNotif","Enemy Convoy"] remoteExecCall ["DT_fnc_notify",0];

private _roadPositions = (_sendingSector nearRoads 1000) apply {getPosATL _x};
_roadPositions = [_roadPositions,[],{_sendingSector distance2D _x},"DESCEND"] call BIS_fnc_sortBy;
_roadPositions params ["_spawnPos"];

private _recievingRoadPositions = (_recievingSector nearRoads _radius) apply {getPosATL _x};
if (_recievingRoadPositions isEqualTo []) then {
	_recievingRoadPositions = [_recievingSector];
};
_recievingRoadPositions = [_recievingRoadPositions,[],{_recievingSector distance2D _x},"ASCEND"] call BIS_fnc_sortBy;
_recievingRoadPositions params ["_destination"];

([_spawnPos,_destination] call DT_fnc_createConvoy) params ["_group","_objectives"];

[
	{
		params ["_group","_objectives","_recievingSector","_radius"];
		({!alive _x || {_x getVariable ["DT_playerUsed",false] || {(_x distance2D _recievingSector) < _radius}}} count _objectives) isEqualTo (count _objectives)
	},
	{
		params ["_group","_objectives","_recievingSector","_radius","_marker"];

		deleteMarker _marker;
		private _opforVehiclesInSector = {alive _x && {!(_x getVariable ["DT_playerUsed",false]) && {(_x distance2D _recievingSector) < _radius}}} count _objectives;
		if (_opforVehiclesInSector > 0) then {
			[format["Some supplies made it through to %1.",_recievingSector getVariable "DT_sectorName"],"failedNotif","Incoming Convoy"] remoteExecCall ["DT_fnc_notify",0];
			_recievingSector setVariable ["DT_sectorStrength",1,true];
			if ([leader _group] call DT_fnc_areaIsClear) then {
				[_group] call DT_fnc_deleteGroup;
			};
		} else {
			["The convoy was stopped successfully.","successNotif","Incoming Convoy"] remoteExecCall ["DT_fnc_notify",0];
			_recievingSector setVariable ["DT_sectorStrength",0.33,true];
			[-5] call DT_fnc_updateThreat;
		};
	},
	[_group,_objectives,_recievingSector,_radius / 2,_marker],
	getNumber(missionConfigFile >> "Settings" >> "sideMissionTimer"),
	{
		params ["_group","_objectives","","","_marker"];
		["The convoy didn't make it in time.","generalNotif","Incoming Convoy"] remoteExecCall ["DT_fnc_notify",0];
		deleteMarker _marker;

		if ([_group] call DT_fnc_areaIsClear) then {
			[_group] call DT_fnc_deleteGroup;
		};
	}
] call CBA_fnc_waitUntilAndExecute;