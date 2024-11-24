/*
	File: fn_createConvoy.sqf
	Author: Dom
	Description: Creates a convoy of vehicles and sets their waypoints
*/
params [
	["_startPos",[],[[]]],
	["_endPos",[],[[]]]
];

([] call DT_fnc_calculateEnemySquads) params ["","_lightCount","_mediumCount"];
private _startDirection = _startPos getDir _endPos;

private _groups = [];
private _lightVehicles = getArray(missionConfigFile >> "Opfor_Setup" >> "opforLightVehicles");
for "_i" from 1 to _lightCount do {
	_groups pushBack ([selectRandom _lightVehicles,_startPos] call DT_fnc_createVehicle);
};

private _mediumVehicles = getArray(missionConfigFile >> "Opfor_Setup" >> "opforMediumVehicles");
for "_i" from 1 to _mediumCount do {
	_groups pushBack ([selectRandom _mediumVehicles,_startPos] call DT_fnc_createVehicle);
};

private _supplyTrucks = ["opforSupplyTruck","opforFuelTruck","opforAmmoTruck"];
for "_i" from 1 to ceil (random 4) do {
	private _type = selectRandom _supplyTrucks;
	private _group = [getText(missionConfigFile >> "Opfor_Setup" >> _type),_startPos] call DT_fnc_createVehicle;
	_groups pushBack _group;
	private _truck = objectParent (leader _group);
	[_truck,_type] remoteExecCall ["DT_fnc_addDepotRaidAction",0,_truck];
};

private _mainGroup = createGroup [east,true];
private _vehicles = [];
{
	_vehicles pushBack (objectParent (leader _x));
	(units _x) joinSilent _mainGroup;
} forEach _groups;
_vehicles params ["_aheadVehicle"];

/*(driver _aheadVehicle) addEventHandler ["PathCalculated",{
	hint "calc path pop";
	params ["_unit","_path"];
	{
		private _marker = createMarker ["marker" + str _forEachIndex, _x];
		_marker setMarkerType "mil_dot";
		_marker setMarkerText str _forEachIndex;
	} forEach _path;
	systemchat str _path;
	doStop _unit;
	_unit setDriveOnPath _path;
}];
(driver _aheadVehicle) setDestination [_endPos,"LEADER PLANNED",true];*/
_mainGroup setFormation "COLUMN";
private _waypoint = _mainGroup addWaypoint [_endPos,5];
_waypoint setWayPointType "MOVE";
_waypoint setWaypointBehaviour "CARELESS";

_vehicles params ["_aheadVehicle"];
{
	_x setDir _startDirection;
	if (_forEachIndex isNotEqualTo 0) then {
		private _vehAheadSize = (boundingBox _aheadVehicle) select 2;
		private _convoyPos = _aheadVehicle getPos [_vehAheadSize + 3,_startDirection + 180];
		_x setVehiclePosition [_convoyPos,[],0,"NONE"];
		_aheadVehicle = _x;
	};

	_x limitSpeed 45;
	_x setConvoySeparation 15;
} forEach _vehicles;

[_mainGroup,_objectives];