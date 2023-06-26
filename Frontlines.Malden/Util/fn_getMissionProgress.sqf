/*
	File: fn_getMissionProgress.sqf
	Author: Dom
	Description: Returns a ratio of mission progress
*/

private _totalCount = 0;
private _bluforCount = {
	_totalCount = _totalCount + 1;
	_x getVariable ["DT_sectorOwned",false]
} count DT_allSectors;

private _ratio = 0;
if (_bluforCount isNotEqualTo 0) then {
	_ratio = _bluforCount / _totalCount;
};

_ratio;