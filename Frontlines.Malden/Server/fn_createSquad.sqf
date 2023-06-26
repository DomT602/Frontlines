/*
	File: fn_createSquad.sqf
	Author: Dom
	Description: Creates the squad pulled from the config
*/
params [
	["_position",[],[[],objNull]],
	["_radius",150,[0]],
	["_side",east,[east]]
];

private _spawnPosition = [_position,0,_radius,5,0,1,0,[],[_position,_position]] call BIS_fnc_findSafePos;

private _squadComposition = if (_side isEqualTo east) then {selectRandom (getArray(missionConfigFile >> "Opfor_Setup" >> "opforSquads"))} else {selectRandom (getArray(missionConfigFile >> "Guerilla_Setup" >> "guerillaSquads"))};
private _group = createGroup [_side,true];

{
	[_group,_side,_x,_spawnPosition,10] call DT_fnc_createUnit;
} forEach _squadComposition;

[_group] call CBA_fnc_clearWaypoints;
_group;