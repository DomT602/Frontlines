/*
	File: fn_initLrRadio.sqf
	Author: Dom
	Description: Sets up the backpack radio on designated frequencies
*/
private _activeLR = call TFAR_fnc_activeLrRadio;
private _myGroupName = groupId group player;
DT_lrRadioFrequencies params ["_frequencies","_groupArrays"];

{
	[_activeLR,1 + _forEachIndex,_x] call TFAR_fnc_setChannelFrequency;

	if (DT_autoRadioOption isEqualTo 1 && {_myGroupName in (_groupArrays select _forEachIndex)}) then {
		[_activeLR,_forEachIndex] call TFAR_fnc_setLrChannel;
	};
} forEach _frequencies;

if (DT_autoRadioOption isEqualTo 2) then {
	[_activeLR,missionNamespace getVariable ["DT_lastLrChannel",0]] call TFAR_fnc_setLrChannel;
};