/*
	File: fn_updateEnvironment.sqf
	Author: Dom
	Requires: Checks for changes and updates the environment as requested
*/

private _display = findDisplay 9644;

toFixed 1;
private _timeSkip = parseNumber (ctrlText (_display displayCtrl 1400));
private _windDir = parseNumber (ctrlText (_display displayCtrl 1401));
private _windSpeed = parseNumber (ctrlText (_display displayCtrl 1402));
private _gusts = parseNumber (ctrlText (_display displayCtrl 1403));
private _lightning = parseNumber (ctrlText (_display displayCtrl 1404));
private _waves = parseNumber (ctrlText (_display displayCtrl 1405));
private _rain = parseNumber (ctrlText (_display displayCtrl 1406));
private _overcast = parseNumber (ctrlText (_display displayCtrl 1407));
private _fogValue = parseNumber (ctrlText (_display displayCtrl 1408));
private _fogDecay = parseNumber (ctrlText (_display displayCtrl 1409));
private _fogBase = parseNumber (ctrlText (_display displayCtrl 1410));

private _wind = [_windSpeed * sin _windDir,_windSpeed * cos _windDir,true];
private _fog = [_fogValue,_fodDecay,_fogBase];

if (_wind isNotEqualTo wind) then {
	[_wind] remoteExecCall ["setWind",2];
};

if (_fog isNotEqualTo fogParams) then {
	[5,_fog] remoteExecCall ["setFog",2];
};

if (_gusts isNotEqualTo gusts) then {
	[5,_gusts] remoteExecCall ["setGusts",2];
};

if (_lightning isNotEqualTo lightnings) then {
	[5,_lightning] remoteExecCall ["setLightnings",2];
};

if (_waves isNotEqualTo waves) then {
	[5,_waves] remoteExecCall ["setWaves",2];
};

if (_rain isNotEqualTo rain) then {
	[5,_rain] remoteExecCall ["setRain",2];
};

if (_overcast isNotEqualTo overcast) then {
	[5,_overcast] remoteExecCall ["setOvercast",2];
};

if (_timeSkip isNotEqualTo 0) then {
	[_timeSkip] remoteExecCall ["skipTime",2];
};

remoteExecCall ["forceWeatherChange",2];