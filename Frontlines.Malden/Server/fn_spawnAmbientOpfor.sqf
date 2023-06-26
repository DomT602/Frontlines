/*
	File: fn_spawnAmbientOpfor.sqf
	Author: Dom
	Description: Spawns ambient enemy patrols
*/

private _sectorsToSpawn = DT_allSectors select {!(_x getVariable ["DT_sectorOwned",false]) && {!(_x in DT_activeSectors)}};
if (_sectorsToSpawn isEqualTo []) exitWith {};

private _maxAmbientOpfor = getNumber(missionConfigFile >> "Settings" >> "maxAmbientOpfor");
private _averageStrength = [] call DT_fnc_getAverageStrength;
_maxAmbientOpfor = round (_maxAmbientOpfor * _averageStrength);
private _vehicleTypes = getArray(missionConfigFile >> "Opfor_Setup" >> "opforTroopCarriers");

while {count DT_ambientOpfor < _maxAmbientOpfor} do {
	private _group = [selectRandom _vehicleTypes,getPosATL (selectRandom _sectorsToSpawn),750,true] call DT_fnc_createVehicle;
	private _vehicle = objectParent (leader _group);
	_vehicle setVariable ["DT_isProtected",true,true];

	DT_ambientOpfor pushBack [_vehicle,_group,[0,0,0]];
};

if (DT_ambientOpforHandle isEqualTo -1) then {
	DT_ambientOpforHandle = [
		{
			if (DT_ambientOpfor isEqualTo []) exitWith {
				[_this select 1] call CBA_fnc_removePerFrameHandler;
				DT_ambientOpforHandle = -1;
			};
			
			private _toDelete = [];
			{
				_x params ["_vehicle","_group","_lastPos"];
				if (isNull _group) then {
					_toDelete pushBack _forEachIndex;
					if (!isNull _vehicle && {!(_vehicle getVariable ["DT_playerUsed",false])}) then {
						deleteVehicle _vehicle;
					};
				} else {
					if (playableUnits isEqualTo []) exitWith {};
					private _currentPos = getPosATL _vehicle;
					if (_lastPos distance _currentPos < 1 && {[_vehicle,1500] call DT_fnc_areaIsClear}) then {
						[_group] call DT_fnc_deleteGroup;
						if !(isNull _vehicle) then {
							deleteVehicle _vehicle;
						};
						_toDelete pushBack _forEachIndex;
					} else {
						if (waypoints _group isEqualTo []) then {
							private _sectorsToDrive = DT_allSectors select {!(_x getVariable ["DT_sectorOwned",false])};

							private _position = [];
							while {_position isEqualTo []} do {
								private _nearRoads = (selectRandom _sectorsToDrive) nearRoads 750;
								if (_nearRoads isNotEqualTo []) then {
									_position = selectRandom _nearRoads;
								};
							};
							
							private _waypoint = _group addWaypoint [_position,10];
							_waypoint setWaypointType "MOVE";
							_waypoint setWaypointBehaviour "SAFE";
							_waypoint setWaypointCombatMode "YELLOW";
							_waypoint setWaypointCompletionRadius 30;
							_waypoint setWayPointStatements ["true","deleteWaypoint [group this,currentWaypoint (group this)]"];
						} else {
							if (!isNull _vehicle && {fuel _vehicle < 0.1}) then {
								[_vehicle,1] remoteExecCall ["setFuel",_vehicle];
							};
							_x set [2,_currentPos];
						};
					};
				};
			} forEach DT_ambientOpfor;

			reverse _toDelete;
			{
				DT_ambientOpfor deleteAt _x;
			} forEach _toDelete;

			if (_toDelete isNotEqualTo []) then {
				[] call DT_fnc_spawnAmbientOpfor;
			};
		},
		15
	] call CBA_fnc_addPerFrameHandler;
};