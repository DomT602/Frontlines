/*
	File: fn_getFrontlineSectors.sqf
	Author: Dom
	Description: Finds desired count of sectors along the frontline
*/
params [
	["_blufor",false,[true]],
	["_count",5,[0]]
];

private _sortedArray = [];
private _bluforSectors = [];
private _opforSectors = [];
{
	if (_x getVariable ["DT_sectorOwned",false]) then {
		_bluforSectors pushBack _x;
	} else {
		_opforSectors pushBack _x;
	};
} forEach DT_allSectors;

private _searchFromSectors = if (_blufor) then {_bluforSectors} else {_opforSectors};;
private _searchAgainstSectors = if (_blufor) then {_opforSectors} else {_bluforSectors};

{
	private _distance = 99999;
	private _selectedSector = _x;
	{
		private _testPos = _selectedSector distance _x;
		if (_testPos < _distance) then {
			_distance = _testPos;
		};
	} forEach _searchAgainstSectors;
	_sortedArray pushBack [_distance,_selectedSector];
} forEach _searchFromSectors;

_sortedArray sort true;
private _sectorCount = count _sortedArray;
if (_count > _sectorCount) then {
	_count = _sectorCount;
};
_sortedArray resize _count;
_sortedArray = _sortedArray apply {_x select 1};

_sortedArray;