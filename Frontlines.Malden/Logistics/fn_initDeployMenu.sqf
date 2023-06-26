/*
	File: fn_initSpawnMenu.sqf
	Author: Dom
	Description: Open and populates the deploy menu
*/

private _display = createDialog ["DT_deployMenu",true];
private _tree = _display displayCtrl 1500;

DT_spawnCamera = "camera" camCreate [worldSize / 2,worldSize / 2,250];
DT_spawnCamera cameraEffect ["internal","back"];
showCinemaBorder false;

_tree tvAdd [[],"Bases"];
_tree tvAdd [[],"Mobile Spawns"];

private _units = playableUnits;
private _fobRadius = getNumber(missionConfigFile >> "Settings" >> "fobBuildRadius");
{
	private _fobName = _x getVariable "DT_fobName";
	private _pos = getPosATL _x;
	private _playerCount = count (_units inAreaArray [_pos,_fobRadius,_fobRadius]);
	private _index = _tree tvAdd [[0],format ["%1 (%2)",_fobName,_playerCount]];
	_tree tvSetData [[0,_index],netId _x];
} forEach DT_allFOBs;

{
	private _vehicleName = getText(configOf _x >> "displayName");
	private _pos = getPosATL _x;
	private _playerCount = count (_units inAreaArray [_pos,100,100]);
	private _index = _tree tvAdd [[1],format ["%1 (%2)",_vehicleName,_playerCount]];
	_tree tvSetData [[1,_index],netId _x];
} forEach (missionNamespace getVariable ["DT_mobileRespawns",[]]);

tvExpandAll _tree;
_tree tvSetCurSel [0,0];