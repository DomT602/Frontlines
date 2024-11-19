/*
	File: fn_destroyArtillery.sqf
	Author: Dom
	Description: Creates and monitors mission to destroy an artillery emplacement
*/

private _militarySectors = ([["military","tower"]] call DT_fnc_getSectorsByType) select {!(_x getVariable ["DT_sectorOwned",false])};
private _spawnPos = [selectRandom _frontlineSectors,0,750,25,0,0.25,0] call BIS_fnc_findSafePos;

[format["The enemy has setup an artillery site at %1.",mapGridPosition _spawnPos],"generalNotif","Destroy Artillery"] remoteExecCall ["DT_fnc_notify",0];

private _templateObjects = selectRandom (getArray(missionConfigFile >> "Compositions" >> "opforArtillerySites"));
private _artyClass = getText(missionConfigFile >> "Opfor_Setup" >> "opforArtilleryVehicle");
private _objects = [];
private _objectives = [];
private _squads = [];

{
	_x params ["_class","_pos","_dir"];
	_pos = _pos vectorAdd _spawnPos;

	if (_class isEqualTo "PortableHelipadLight_01_yellow_F") then {
		private _group = [_artyClass,_pos,0] call DT_fnc_createVehicle;
		_squads pushBack _group;
		if (DT_isLambsEnabled) then {
			[_group] call lambs_wp_fnc_taskArtilleryRegister;
		};
		private _vehicle = objectParent (leader _group);
		(driver _vehicle) disableAI "MOVE";
		_vehicle setDir _dir;
		_vehicle lock 3;
		_objectives pushBack _vehicle;
	} else {
		private _object = createVehicle [_class,_pos,[],0,"CAN_COLLIDE"];
		_object setPosATL _pos;
		_object setVectorUp [0,0,1];
		_object setDir _dir;

		_objects pushBack _object;
	};
} forEach _templateObjects;

_squads append ([_spawnPos,50,([0.75] call DT_fnc_calculateEnemySquads)] call DT_fnc_createPatrols);
[_spawnPos,250] call DT_fnc_createMines;
//may need scripted arty?

private _marker = ["destroyArtillery",_spawnPos,true,"ColorOPFOR","ELLIPSE",250,"Destroy Artillery","Grid"] call DT_fnc_createMarker;
missionNamespace setVariable ["DT_opforArtilleryActive",true,true];

[
	{
		params ["_objectives"];
		(_objectives select {alive _x}) isEqualTo []
	},
	{
		params ["","_marker","_spawnPos","_squads","_objects"];

		deleteMarker _marker;
		["The artillery site has been destroyed.","successNotif","Destroy Artillery"] remoteExecCall ["DT_fnc_notify",0];
		missionNamespace setVariable ["DT_opforArtilleryActive",nil,true];

		[
			{
				params ["_pos"];
				[_pos] call DT_fnc_areaIsClear
			},
			DT_fnc_clearArea,
			[_spawnPos,_squads,_objects]
		] call CBA_fnc_waitUntilAndExecute;
	},
	[_objectives,_marker,_spawnPos,_squads,_objects]
] call CBA_fnc_waitUntilAndExecute;