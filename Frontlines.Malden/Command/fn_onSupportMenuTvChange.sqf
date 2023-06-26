/*
	File: fn_onSupportMenuTvChange.sqf
	Author: Dom
	Description: Called on change of selection on support menu
*/
params [
	["_control",controlNull,[controlNull]],
	["_selectionPath",[],[[]]]
];

private _display = findDisplay 9646;
private _button = _display displayCtrl 2400;
_selectionPath params ["_firstIndex"];
(parseSimpleArray (_control tvData [_firstIndex])) params ["_action","_civRepRequired","_cooldown"];

private _civRepColour = if (DT_globalReputation >= _civRepRequired) then {"#00BF00"} else {"#BF0000"};
private _text = format ["
<t align='center' font='PuristaBold' size='1.6'>%1</t><br/>
<t font='PuristaLight'>Cooldown Induced: %2 minutes</t><br/>
<t font='PuristaLight'>Civilian Reputation Required: </t> <t font='PuristaLight' color='%3'>%4%5</t>"
,_control tvText _selectionPath,ceil (_cooldown / 60),_civRepColour,_civRepRequired,"%"];

(_display displayCtrl 1100) ctrlSetStructuredText parseText _text;

if (count _selectionPath isEqualTo 1) exitWith {
	_button ctrlEnable false;
};

private _supportCooldowns = missionNamespace getVariable ["DT_supportCooldowns",[]];
_button ctrlEnable ((CBA_missionTime > (_supportCooldowns select _firstIndex)) && {DT_globalReputation >= _civRepRequired});

if (_action isEqualTo "supplyDrop") then {
	private _pos = markerPos "supportTarget";
	if (_pos isEqualTo [0,0,0]) then {
		_pos = player;
	};

	(parseSimpleArray (_control tvData _selectionPath)) params ["","","_resources"];
	private _nearbyResources = [_pos] call DT_fnc_getCurrentResources;
	if !([_nearbyResources,_resources] call DT_fnc_compareResources) then {
		_button ctrlEnable false;
	};
};

if (_action in ["infAttack","mechAttack","crateRetrieve","sectorDefence"]) then {
	private _sector = objectFromNetId (_control tvData _selectionPath);
	private _mapControl = _display displayCtrl 1205;
	_mapControl ctrlMapAnimAdd [2,0.3,_sector];
	ctrlMapAnimCommit _mapControl;
};