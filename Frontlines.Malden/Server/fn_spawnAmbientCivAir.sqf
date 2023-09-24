/*
	File: fn_spawnAmbientAir.sqf
	Author: Dom
	Description: Spawns ambient civilian air
*/
params [
	["_count",1,[0]],
	["_startMonitor",false,[true]]
];

private _civilianTypes = getArray(missionConfigFile >> "Civilian_Setup" >> "civilianTypes");
private _civilianAirTypes = getArray(missionConfigFile >> "Civilian_Setup" >> "civilianAircraftTypes");

for "_i" from 1 to _count do {
	(selectRandom DT_airportLocations) params ["_spawnPos"];
	private _vehicle = createVehicle [selectRandom _civilianAirTypes,_spawnPos,[],10,"NONE"];
	_vehicle setVariable ["DT_isProtected",true,true];
	private _group = createGroup [civilian,true];
	private _pilot = _group createUnit [selectRandom _civilianTypes,_spawnPos,[],0,"NONE"];
	_pilot moveInDriver _vehicle;
	[_group] call CBA_fnc_clearWaypoints;
	_pilot addEventHandler ["Hit",DT_fnc_civilianHit];
	_pilot addEventHandler ["Killed",DT_fnc_civilianKilled];

	DT_ambientCivAir pushBack [_pilot,_group,_vehicle,[0,0,0]];
};

if (_startMonitor) then {
	[
		{
			if (DT_ambientCivAir isEqualTo []) exitWith {
				[_this select 1] call CBA_fnc_removePerFrameHandler;
			};

			{
				_x params ["_unit","_group","_vehicle","_lastPos"];
				if !(alive _unit) then {
					DT_ambientCivAir deleteAt _forEachIndex;
					[1] call DT_fnc_spawnAmbientCivAir;
					if (!isNull _vehicle && {!(_vehicle getVariable ["DT_playerUsed",false])}) then {
						deleteVehicle _vehicle;
					};
				} else {
					if !(alive _vehicle) then {
						deleteVehicle _unit;
						DT_ambientCivAir deleteAt _forEachIndex;
						[1] call DT_fnc_spawnAmbientCivAir;
					} else {
						if (playableUnits isEqualTo []) exitWith {};
						private _currentPos = getPosATL _unit;
						if (_lastPos distance _currentPos < 1 && {[_unit,1500] call DT_fnc_areaIsClear}) then {
							[_group] call DT_fnc_deleteGroup;
							DT_ambientCivAir deleteAt _forEachIndex;
							[1] call DT_fnc_spawnAmbientCivAir;
						} else {
							if (speed (vehicle _unit) < 5 && {count (waypoints _group) < 1}) then {
								private _waypoint = _group addWaypoint [(selectRandom DT_airportLocations) select 0,0];
								_waypoint setWaypointType "MOVE";
								_waypoint setWaypointBehaviour "SAFE";
								_waypoint setWaypointCompletionRadius 10;
								_waypoint setWayPointStatements ["true","deleteWaypoint [group this,currentWaypoint (group this)]; [group this,getPosATL this] spawn BIS_fnc_wpLand"];
							} else {
								if (!isNull _vehicle && {fuel _vehicle < 0.1}) then {
									[_vehicle,1] remoteExecCall ["setFuel",_vehicle];
								};
								_x set [3,_currentPos];
							};
						};
					};
				};
			} forEachReversed DT_ambientCivAir;
		},
		15
	] call CBA_fnc_addPerFrameHandler;
};