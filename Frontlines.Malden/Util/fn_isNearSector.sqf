/*
	File: fn_isNearSector.sqf
	Author: Dom
	Description: Checks if the current position is near a certain sector type
*/
params [
	["_startPos",[],[[],objNull]],
	["_sectors",[],[[]]],
	["_radius",100,[0]]
];

private _nearSector = _sectors findIf {_x distance _startPos < _radius};

(_nearSector isNotEqualTo -1)