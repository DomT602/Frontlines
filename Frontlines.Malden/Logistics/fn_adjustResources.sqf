/*
	File: fn_adjustResources.sqf
	Author: Dom
	Description: Adjusts resources locally or via the global pool
*/
params [
	["_pos",[],[[],objNull]],
	["_resources",[],[[]]],
	["_add",false,[true]]
];

if (getNumber(missionConfigFile >> "Settings" >> "fobGlobalResourcePool") isEqualTo 0) then {
	private _nearFOB = [_pos] call DT_fnc_getNearestFob;
	private _localResources = _nearFob getVariable ["DT_fobResources",[0,0,0]];
	_localResources = if (_add) then {_localResources vectorAdd _resources} else {_localResources vectorDiff _resources};
	_nearFob setVariable ["DT_fobResources",_localResources,true];
} else {
	DT_globalResources = if (_add) then {DT_globalResources vectorAdd _resources} else {DT_globalResources vectorDiff _resources};
	publicVariable "DT_globalResources";
};