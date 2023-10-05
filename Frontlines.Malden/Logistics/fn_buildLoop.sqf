/*
	File: fn_buildLoop.sqf
	Author: Dom
	Description: Manages PFH of building
*/
params ["_args","_handle"];
_args params ["_previewObject","_spheres","_collisionZone","_actions","_class","_resources","_conditions","_moving",["_nearFobOverride",false]];

if (DT_buildAction > 0 || {!alive player || {!isNull objectParent player}}) then {
	[_handle] call CBA_fnc_removePerFrameHandler;
	private _finalPosition = getPosATLVisual _previewObject;
	private _finalDir = getDir _previewObject;
	deleteVehicle _previewObject;
	{
		deleteVehicle _x;
	} forEach _spheres;
	{
		player removeAction _x;
	} forEach _actions;

	if (DT_buildAction isEqualTo 1) then {
		private _localResources = [player] call DT_fnc_getCurrentResources;
		if !([_localResources,_resources] call DT_fnc_compareResources) exitWith {["Not enough resources."] call DT_fnc_notify};

		[player,_resources,false] call DT_fnc_adjustResources;

		[
			{
				params ["_class","_finalPosition","_finalDir","_moving","_resources","_conditions"];
				private _object = createVehicle [_class,_finalPosition,[],0,"CAN_COLLIDE"];
				_object setPosATL _finalPosition;
				_object setDir _finalDir;
				if (DT_alignToTerrain) then {
					_object setVectorUp surfaceNormal (getPosATL _object);
				};
				[_object,_moving] call DT_fnc_initialiseObject;

				if (unitIsUAV _object) then {
					[_object] call DT_fnc_setupUAV;
				};

				private _fobClassname = getText(missionConfigFile >> "Logi_Setup" >> "fobBuilding");
				if (_class isEqualTo _fobClassname) then {
					private _fobNames = getArray(missionConfigFile >> "Settings" >> "defaultFOBNames");
					private _fobNamespace = createSimpleObject ["CBA_NamespaceDummy",_finalPosition];
					_fobNamespace setPosATL _finalPosition;
					private _fobVariable = format ["FOB_%1",count DT_allFOBs];

					_fobNamespace setVariable ["DT_fobVariable",_fobVariable,true];
					private _startingFobResources = getArray(missionConfigFile >> "Settings" >> "newFobResources");
					_fobNamespace setVariable ["DT_fobResources",_startingFobResources,true];
					DT_allFOBs pushBack _fobNamespace;
					publicVariable "DT_allFOBs";

					private _marker = createMarker [_fobVariable,_finalPosition];
					_marker setMarkerType "b_hq";
					_marker setMarkerSize [1.5,1.5];

					["A new FOB has been established.","successNotif","New FOB"] remoteExecCall ["DT_fnc_notify",0];
					[true] call DT_fnc_initNamingMenu;
				} else {
					if (DT_postBuildAction > 0 && {!_moving}) then {
						if (DT_postBuildAction isEqualTo 1) then {
							if (_object isKindOf "AllVehicles") exitWith {};
							DT_canBuild = false;
							DT_buildAction = 0;
							if !(DT_preserveBuildData) then {
								DT_alignToTerrain = true;
								DT_buildElevation = 0;
								DT_buildRotation = 0;
							};

							[DT_fnc_startBuild,[[_class,_resources,_conditions]],0.3] call CBA_fnc_waitAndExecute;
						} else {
							[] call DT_fnc_initBuildMenu;
						};
					};
				};
			},
			[_class,_finalPosition,_finalDir,_moving,_resources,_conditions],
			0.1
		] call CBA_fnc_waitAndExecute;
	};
} else {
	private _nextPreviewPos = player modelToWorld [0,3 + _collisionZone,DT_buildElevation];
	_previewObject setPosATL _nextPreviewPos;
	_previewObject setDir ((getDir player) + DT_buildRotation);

	private _nearbyObjects = nearestObjects [_nextPreviewPos,["AllVehicles","House"],_collisionZone,true];
	_nearbyObjects append (nearestTerrainObjects [_nextPreviewPos,["TREE","BUILDING"],_collisionZone,false,true]);

	private _ignoreObjects = getArray(missionConfigFile >> "Settings" >> "ignoreWhenBuilding");
	private _collidingObjects = [];
	{
		if !(_x isKindOf "CAManBase" || {(typeOf _x) in _ignoreObjects || {_x isEqualTo _previewObject}}) then {
			_collidingObjects pushBack _x;
		};
	} forEach _nearbyObjects;

	private _sphereColour = "#(rgb,8,8,3)color(1,0,0,1)";
	if (_collidingObjects isEqualTo [] && {[player] call DT_fnc_isNearFob || {_nearFobOverride}}) then {
		_sphereColour = "#(rgb,8,8,3)color(0,1,0,1)";
		DT_canBuild = true;
	} else {
		DT_canBuild = false;
		{
			drawIcon3D ["\A3\ui_f\data\map\markers\handdrawn\objective_CA.paa",[1,0,0,1],(getPosATL _x vectorAdd [0,0,2]),1,1,0,getText(configOf _x >> "displayName"),0,0.04];
		} forEach _collidingObjects;
	};

	{
		_x setPosATL (_nextPreviewPos getPos [_collisionZone,10 * _forEachIndex]);
		_x setObjectTexture [0,_sphereColour];
	} forEach _spheres;
};