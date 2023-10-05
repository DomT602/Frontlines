/*
	File: fn_createNewFob.sqf
	Author: Dom
	Description: Creates a new FOB at nearest suitable position
*/
params [
	["_object",objNull,[objNull]]
];

private _action = [
	"Are you sure you want to establish a new FOB, you cannot cancel this action and the vehicle will be consumed.",
	"Establish FOB",
	"Establish",
	"Cancel"
] call BIS_fnc_guiMessage;

if (_action) then {
	deleteVehicle _object;

	DT_canBuild = false;
	DT_buildAction = 0;
	if !(DT_preserveBuildData) then {
		DT_alignToTerrain = true;
		DT_buildElevation = 0;
		DT_buildRotation = 0;
	};

	private _fobClass = getText(missionConfigFile >> "Logi_Setup" >> "fobBuilding");
	([_fobClass] call DT_fnc_setupBuild) params ["_previewObject","_objectPreviewSpheres","_collisionZone","_actions"];

	[DT_fnc_buildLoop,0,[_previewObject,_objectPreviewSpheres,_collisionZone,_actions,_fobClass,[0,0,0],"",false,true]] call CBA_fnc_addPerFrameHandler;
};