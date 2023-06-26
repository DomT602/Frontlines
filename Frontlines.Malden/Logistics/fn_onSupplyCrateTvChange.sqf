/*
	File: fn_onSupplyCrateTvChange.sqf
	Author: Dom
	Description: Called on a new selection in the crate menu
*/
params [
	["_control",controlNull,[controlNull]],
	["_selectionPath",[],[[]]]
];

private _display = findDisplay 9642;
private _textBox = _display displayCtrl 1100;
private _button = _display displayCtrl 2400;
if (count _selectionPath isEqualTo 1) exitWith {_button ctrlEnable false; _textBox ctrlSetStructuredText parseText ""};

_button ctrlEnable true;

private _text = _control tvText _selectionPath;
(parseSimpleArray (_control tvData _selectionPath)) params ["_type","_contents","_resources"];

private _localResources = [player] call DT_fnc_getCurrentResources;
_button ctrlEnable ([_localResources,_resources] call DT_fnc_compareResources);

private _text = format ["<t align='center' font='PuristaBold' size='1.6'>%1</t><br/>",_text];

{
	_x params ["_class","_count"];

	([_class] call DT_fnc_fetchDetails) params ["_name"];
	_text = format ["%1<t font='PuristaLight'>%2x %3</t><br/>",_text,_count,_name];
} forEach _contents;

_textBox ctrlSetStructuredText parseText _text;