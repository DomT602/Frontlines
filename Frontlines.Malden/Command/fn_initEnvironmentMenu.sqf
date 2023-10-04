/*
	File: fn_initEnvironmentMenu.sqf
	Author: Dom
	Requires: Opens and populates the environmental control menu
*/

private _gusts = gusts;
private _fog = fog;
private _lightning = lightnings;
private _rain = rain;
private _overcast = overcast;
private _Waves = waves;

private _windDir = windDir toFixed 0;
private _windSpeed = vectorMagnitude wind;
fog params ["_fogValue","_fogDecay","_fogBase"];

private _display = createDialog ["DT_environmentControlMenu",true];

(_display displayCtrl 1401) ctrlSetText _windDir;
(_display displayCtrl 1402) ctrlSetText str _windSpeed;
(_display displayCtrl 1403) ctrlSetText str _gusts;
(_display displayCtrl 1404) ctrlSetText str _lightning;
(_display displayCtrl 1405) ctrlSetText str _Waves;
(_display displayCtrl 1406) ctrlSetText str _rain;
(_display displayCtrl 1407) ctrlSetText str _overcast;
(_display displayCtrl 1408) ctrlSetText str _fogValue;
(_display displayCtrl 1409) ctrlSetText str _fogDecay;
(_display displayCtrl 1410) ctrlSetText str _fogBase;