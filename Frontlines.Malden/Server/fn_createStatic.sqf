/*
	File: fn_createStatic.sqf
	Author: Dom
	Description: Creates a static weapon
*/
params [
	["_pos",[],[[],objNull]],
	["_radius",150,[0]]
];

private _statics = getArray(missionConfigFile >> "Opfor_Setup" >> "opforStatics");
private _staticClass = selectRandom _statics;
private _spawnPos = [_pos,10,_radius,5,0,0.15,0] call BIS_fnc_findSafePos;
if (_spawnPos isEqualTo []) exitWith {};

private _static = createVehicle [_staticClass,_spawnPos,[],0,"CAN_COLLIDE"];
_static setVectorUp [0,0,1];
private _dirToTarget = _static getDir _pos;
_static setDir (_dirToTarget + (random [135,180,225]));

private _fence = createVehicle ["Land_BagFence_Round_F",_spawnPos vectorAdd [0,-2],[],0,"CAN_COLLIDE"];
_fence = createVehicle ["Land_BagFence_Round_F",_spawnPos vectorAdd [0,2],[],0,"CAN_COLLIDE"];
_fence setDir 180;
_fence = createVehicle ["Land_BagFence_Round_F",_spawnPos vectorAdd [3,0],[],0,"CAN_COLLIDE"];
_fence setDir 270;
_fence = createVehicle ["Land_BagFence_Round_F",_spawnPos vectorAdd [-3,0],[],0,"CAN_COLLIDE"];
_fence setDir 90;

private _group = createGroup [east,true];
private _unitClass = selectRandom (selectRandom (getArray(missionConfigFile >> "Opfor_Setup" >> "opforSquads")));
private _unit = [_group,east,_unitClass,_spawnPos] call DT_fnc_createUnit;

_unit moveInGunner _static;

_group;