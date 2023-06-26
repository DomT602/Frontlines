/*
	File: fn_isNearFob.sqf
	Author: Dom
	Description: Checks if the current position is near a FOB
*/
params [
	["_pos",player,[[],objNull]],
	["_radius",getNumber(missionConfigFile >> "Settings" >> "fobBuildRadius"),[0]]
];

private _nearFOB = DT_allFOBs findIf {_x distance _pos < _radius};

(_nearFob isNotEqualTo -1)