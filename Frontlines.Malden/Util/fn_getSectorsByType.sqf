/*
	File: fn_getSectorsByType.sqf
	Author: Dom
	Description: Returns all sectors of a desired type
*/
params [
	["_desiredTypes",["town"],[[]]],
	["_bluforOnly",false,[true]]
];

private _sectors = [];

{
	private _type = _x getVariable ["DT_sectorType",""];
	if (_type in _desiredTypes) then {
		if (_bluforOnly && {!(_x getVariable ["DT_sectorOwned",false])}) exitWith {};
		_sectors pushBack _x;
	};
} forEach DT_allSectors;

_sectors;