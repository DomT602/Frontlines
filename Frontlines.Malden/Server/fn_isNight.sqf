/*
	File: fn_isNight.sqf
	Author: Dom
	Description: Checks if it is nighttime
*/

(date call BIS_fnc_sunriseSunsetTime) params ["_sunRiseTime","_sunSetTime"];

private _currentTime = dayTime;
if (_currentTime > (_sunSetTime + 1) || {_currentTime < _sunRiseTime}) exitWith {
	true;
};

false;