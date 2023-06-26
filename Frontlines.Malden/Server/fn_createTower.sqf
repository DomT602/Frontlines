/*
	File: fn_createTower.sqf
	Author: Dom
	Description: Spawns a radio tower depending on space available
*/
params [
	["_sectorObj",objNull,[objNull]]
];

private _isTowerDestroyed = _sectorObj getVariable ["DT_towerDestroyed",false];
private _possibleTowerCompositions = getArray(missionConfigFile >> "Compositions" >> "opforTowers");

private _objects = [];
private _spawnPos = [];

{
	_x params ["_radius","_objectArray"];

	while {_spawnPos isEqualTo []} do {
		private _testPos = _sectorObj getPos [random 50,random 360];
		if (
			_testPos isFlatEmpty [-1,-1,0.2,(_radius * 0.75),0,false,objNull] isNotEqualTo [] &&
			{nearestTerrainObjects [_testPos,["HIDE","BUILDING","ROCK","ROCKS"],_radius,false] isEqualTo []}
		) then {
			_spawnPos = _testPos;
			_objects = _objectArray;
		};
	};
} forEach _possibleTowerCompositions;
_spawnPos params ["_xPos","_yPos"];

private _nearTrees = nearestTerrainObjects [_spawnPos,["TREE"],50,false];
{
	_x hideObjectGlobal true;
} forEach _nearTrees;

{
	_x params ["_class","_pos","_dir"];
	if (_class in ["Land_Communication_F","Land_TTowerSmall_2_F","Land_TTowerBig_1_F"] && {_isTowerDestroyed}) then {continue};
	_pos = _pos vectorAdd [_xPos,_yPos,0];
	private _object = createVehicle [_class,_pos,[],0,"CAN_COLLIDE"];
	_object setPosATL _pos;
	_object setVectorUp [0,0,1];
	_object setDir _dir;

	if (_class isEqualTo "Land_Laptop_unfolded_F") then {
		[_object,_sectorObj] remoteExecCall ["DT_fnc_gatherIntel",0,_object];
	} else {
		if (_class in ["Land_Communication_F","Land_TTowerSmall_2_F","Land_TTowerBig_1_F"]) then {
			_object addEventHandler ["Killed",DT_fnc_towerDestroyed];
		};
	};
} forEach _objects;