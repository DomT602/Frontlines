/*
	File: fn_initSwRadios.sqf
	Author: Dom
	Description: Sets up the handheld radios on designated frequencies
*/
params [
	["_unit",objNull,[objNull]],
	["_radios",[],[[]]]
];

private _myGroupName = groupId group player;
DT_swRadioFrequencies params ["_frequencies","_groupArrays"];

{
	private _radio = _x;
	{
		[_radio,1 + _forEachIndex,_x] call TFAR_fnc_setChannelFrequency;

		if (DT_autoRadioOption isEqualTo 1 && {_myGroupName in (_groupArrays select _forEachIndex)}) then {
			[_radio,_forEachIndex] call TFAR_fnc_setSwChannel;
		};
	} forEach _frequencies;
	if (DT_autoRadioOption isEqualTo 2) then {
		[_radio,missionNamespace getVariable ["DT_lastSwChannel",0]] call TFAR_fnc_setSwChannel;
	};
} forEach _radios;