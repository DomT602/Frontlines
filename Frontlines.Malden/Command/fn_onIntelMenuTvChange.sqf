/*
	File: fn_onIntelMenuTvChange.sqf
	Author: Dom
	Description: Called on change of selection on intel menu
*/
params [
	["_control",controlNull,[controlNull]],
	["_selectionPath",[],[[]]]
];

private _display = findDisplay 9647;
private _button = _display displayCtrl 2400;
private _textBox = _display displayCtrl 1100;

if (count _selectionPath isEqualTo 1) exitWith {
	_button ctrlEnable false;
	_textBox ctrlSetStructuredText parseText "";
};

private _intelRequired = _control tvValue _selectionPath;
(parseSimpleArray (_control tvData _selectionPath)) params ["_conditions","_description"];

private _intelColour = if (DT_intelCount >= _intelRequired) then {"#00BF00"} else {"#BF0000"};
private _text = format ["
<t align='center' font='PuristaBold' size='1.6'>%1</t><br/>
<t font='PuristaLight'>Intel Required: </t><t font='PuristaLight' color='%2'>%3</t><br/>
<t font='PuristaLight'>%4</t>"
,_control tvText _selectionPath,_intelColour,_intelRequired,_description];

_selectionPath params ["_firstIndex"];
if (_firstIndex isEqualTo 0 && {missionNamespace getVariable ["DT_secondaryActive",""] isNotEqualTo ""}) exitWith {
	_button ctrlEnable false;
_text = format ["%1<br/><br/>
<t font='PuristaLight' color='#BFBF00'>Secondary mission already in progress.</t>
",_text];
	(_display displayCtrl 1100) ctrlSetStructuredText parseText _text;
};

(_display displayCtrl 1100) ctrlSetStructuredText parseText _text;

_button ctrlEnable ((DT_intelCount >= _intelRequired) && {[_conditions] call DT_fnc_conditionChecker});