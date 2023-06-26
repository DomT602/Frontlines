/*
	File: fn_moveObject.sqf
	Author: Dom
	Description: Starts the process of moving an object
*/
params [
	["_object",objNull,[objNull]]
];

DT_canBuild = false;
DT_buildAction = 0;
DT_alignToTerrain = true;
if !(DT_preserveBuildData) then {
	DT_buildElevation = 0;
	DT_buildRotation = 0;
};

private _class = typeOf _object;
deleteVehicle _object;
([_class] call DT_fnc_setupBuild) params ["_previewObject","_objectPreviewSpheres","_collisionZone","_actions"];

[DT_fnc_buildLoop,0,[_previewObject,_objectPreviewSpheres,_collisionZone,_actions,_class,[0,0,0],"true",true]] call CBA_fnc_addPerFrameHandler;