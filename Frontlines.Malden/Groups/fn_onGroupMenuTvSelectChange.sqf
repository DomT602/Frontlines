/*
	File: fn_onGroupMenuTvSelectChange.sqf
	Author: Dom
	Description: Updates the group menu
*/
params [
	["_control",controlNull,[controlNull]],
	["_selectionPath",[],[[]]]
];
private _display = findDisplay 9702;
private _textBox = _display displayCtrl 1100;
private _button = _display displayCtrl 2400;

_selectionPath params ["_groupIndex",["_unitIndex",-1]];

if (_unitIndex isEqualTo -1) exitWith {
	_button ctrlEnable false;
	private _text = format ["
		<t align='center' font='PuristaBold' size='1.6'>%1</t>
		",
		((DT_dynamicGroups select _groupIndex) select 0)
	];
	_textBox ctrlSetStructuredText parseText _text;
};

(parseSimpleArray (_control tvData _selectionPath)) params ["_unitNetID","_selectedRole"];
private _unit = objectFromNetId _unitNetID;

_button ctrlEnable (isNull _unit);

private _roleData = missionConfigFile >> "Dynamic_Roles" >> _selectedRole;
private _roleName = getText(_roleData >> "name");
private _roleRank = getText(_roleData >> "rank");
private _roleDesc = getText(_roleData >> "description");

private _defaultLoadout = getArray(_roleData >> "defaultLoadout");
private _defaultLoadoutText = [];

for "_i" from 0 to 5 do {
	private _array = _defaultLoadout select _i;
	_array params [["_className",""]];
	if (_className isEqualTo "") then {
		_defaultLoadoutText pushBack "-";
	} else {
		if (_i isEqualTo 5) then {
			_defaultLoadoutText pushBack (getText(configFile >> "CfgVehicles" >> _className >> "displayName"));
		} else {
			_defaultLoadoutText pushBack (getText(configFile >> "CfgWeapons" >> _className >> "displayName"));
		};
	};
};
private _helmetClass = _defaultLoadout select 6;
if (_helmetClass isEqualTo "") then {
	_defaultLoadoutText pushBack "-";
} else {
	_defaultLoadoutText pushBack (getText(configFile >> "CfgWeapons" >> _helmetClass >> "displayName"));
};

_defaultLoadoutText = _defaultLoadoutText apply {(_x splitString "&") joinString "and"};

private _text = format ["
<t align='center' font='PuristaBold' size='1.6'>%1</t>
<br/>
<t align='center' font='PuristaLight'>%2</t>

<br/><br/>

<t font='PuristaLight' valign='bottom' align='left'>%3</t>
<t font='PuristaBold' align='Right' valign='bottom'><img size='0.8' image='a3\ui_f\data\gui\cfg\ranks\%4_gs.paa'/> %4</t>

<br/><br/>

<t font='PuristaBold' size='1.2'>%5</t>

<br/>

<t font='PuristaLight' valign='bottom' align='left'>%6</t>
<t font='PuristaBold' align='Right' valign='bottom'>%7</t>

<br/>

<t font='PuristaLight' valign='bottom' align='left'>%8</t>
<t font='PuristaBold' align='Right' valign='bottom'>%9</t>

<br/>

<t font='PuristaLight' valign='bottom' align='left'>%10</t>
<t font='PuristaBold' align='Right' valign='bottom'>%11</t>

<br/><br/>

<t font='PuristaLight' valign='bottom' align='left'>%12</t>
<t font='PuristaBold' align='Right' valign='bottom'>%13</t>

<br/>

<t font='PuristaLight' valign='bottom' align='left'>%14</t>
<t font='PuristaBold' align='Right' valign='bottom'>%15</t>

<br/>

<t font='PuristaLight' valign='bottom' align='left'>%16</t>
<t font='PuristaBold' align='Right' valign='bottom'>%17</t>

<br/>

<t font='PuristaLight' valign='bottom' align='left'>%18</t>
<t font='PuristaBold' align='Right' valign='bottom'>%19</t>

",
	_roleName,_roleDesc,localize "STR_LIVE_STATS_RANK",_roleRank,
	localize "STR_DT_Role_Menu_Default_Loadout",localize "STR_A3_RSCDISPLAYGEAR_FILTERS_PRIMARY0",_defaultLoadoutText#0,localize "STR_A3_RSCDISPLAYARSENAL_TAB_SECONDARYWEAPON",
	_defaultLoadoutText#1,localize "STR_A3_RSCDISPLAYGEAR_FILTERS_SECONDARY0",_defaultLoadoutText#2,
	localize "STR_A3_RSCDISPLAYARSENAL_TAB_UNIFORM",_defaultLoadoutText#3,localize "STR_A3_RSCDISPLAYARSENAL_TAB_VEST", _defaultLoadoutText#4,
	localize "STR_A3_RSCDISPLAYARSENAL_TAB_BACKPACK",_defaultLoadoutText#5,localize "STR_A3_RSCDISPLAYARSENAL_TAB_HEADGEAR",_defaultLoadoutText#6
];
_textBox ctrlSetStructuredText parseText _text;

(ctrlPosition _textBox) params ["_xPos","_yPos","_width"];
private _height = ctrlTextHeight _textBox;
_textBox ctrlSetPosition [_xPos,_yPos,_width,_height];
_textBox ctrlCommit 0;