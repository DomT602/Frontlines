/*
	File: fn_ambushLogisticsConvoy.sqf
	Author: Dom
	Description: Side mission for a convoy ambush
*/

DT_logistics params ["","_trucksInTransit","_currentRoutes"];
private _index = round (random (count _currentRoutes - 1));
private _attackedRoute = _currentRoutes select _index;
_attackedRoute params ["_from","_to","_truckCount","_startTransitTime","_endTransitTime","_carrying"];

private _fromPos = getPosATL _from;
private _toPos = getPosATL _to;

private _travelDir = _fromPos getDir _toPos;
private _distance = _fromPos distance2D _toPos;
private _timeInTransit = round(CBA_missionTime - _startTransitTime);
private _fullTransitTime = round(_endTransitTime - _startTransitTime);
private _percentageTimeTravelled = _timeInTransit / _fullTransitTime;
private _distanceTravelled = _distance * _percentageTimeTravelled;

private _estimatedPosition = _fromPos getPos [_distanceTravelled,_travelDir];
private _nearRoads = _estimatedPosition nearRoads 1000;
if (_nearRoads isEqualTo []) exitWith {};

_currentRoutes deleteAt _index;
DT_logistics set [1,(_trucksInTransit - _truckCount)];
DT_logistics set [2,_currentRoutes];
publicVariable "DT_logistics";

private _roadToSpawn = getPosATL (selectRandom _nearRoads);
private _deadVehicles = [];
for "_i" from 1 to _truckCount do {
	private _truck = createVehicle ["C_Van_01_box_F",_roadToSpawn,[],75,"NONE"];
	_truck setDir (random 360);
	_truck setDamage 1;
	_deadVehicles pushBack _truck;
};

private _crateTypes = getArray(missionConfigFile >> "Logi_Setup" >> "bluforCrates");
private _crates = [];
{
	if (_x isNotEqualTo 0) then {
		private _crateCount = floor(_x / 100);
		for "_i" from 1 to _crateCount do {
			private _crate = createVehicle [(_crateTypes select _forEachIndex),_roadToSpawn,[],50,"NONE"];
			_crates pushBack _crate;
		};
	};
} forEach _carrying;

private _squads = [_roadToSpawn,150,([0.75] call DT_fnc_calculateEnemySquads)] call DT_fnc_createPatrols;

private _marker = ["logiAmbush",_roadToSpawn,true,"ColorOPFOR","ELLIPSE",50,"Last reported convoy position","Grid"] call DT_fnc_createMarker;
[format["One of your convoys have been ambushed at %1.",mapGridPosition _roadToSpawn],"generalNotif","Attacked Convoy"] remoteExecCall ["DT_fnc_notify",0];

[
	{
		params ["_position"];
		!([_position,50] call DT_fnc_areaIsClear)
	},
	{
		params ["","","_marker"];
		deleteMarker _marker;
		["The convoy has been secured.","successNotif","Convoy Secured"] remoteExecCall ["DT_fnc_notify",0];
	},
	[_roadToSpawn,_squads,_marker,_crates],
	1800,
	{
		params ["_position","_squads","_marker","_crates"];
		[
			{
				params ["_position"];
				[_position] call DT_fnc_areaIsClear;
			},
			{
				params ["_position","_squads","_marker","_crates"];

				[_position,_squads,_crates] call DT_fnc_clearArea;
				deleteMarker _marker;
				["The convoy was lost.","failedNotif","Convoy Lost"] remoteExecCall ["DT_fnc_notify",0];
			},
			[_position,_squads,_marker,_crates]
		] call CBA_fnc_waitUntilAndExecute;
	}
] call CBA_fnc_waitUntilAndExecute;