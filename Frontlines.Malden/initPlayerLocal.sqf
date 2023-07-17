/*
	Faction: initPlayerLocal.sqf
	Author: Dom
	Requires: Start us up
*/

waitUntil {missionNamespace getVariable ["DT_serverReady",false] && {!isNull player && {!isNull (findDisplay 46)}}};

addMissionEventHandler ["Map",DT_fnc_checkMap];

player addEventHandler ["HandleRating",{0}];
player addEventHandler ["GetInMan",DT_fnc_getInMan];
player addEventHandler ["SeatSwitchedMan",DT_fnc_seatSwitchedMan];
player addEventHandler ["Respawn",DT_fnc_onRespawn];

if (DT_isTFAREnabled) then {
	["radioSetup","OnRadiosReceived",DT_fnc_initSwRadios] call TFAR_fnc_addEventHandler;
	["radioSwChange","OnSWchannelSet",{DT_lastSwChannel = _this select 2}] call TFAR_fnc_addEventHandler;
	["radioLrChange","OnLRchannelSet",{DT_lastLrChannel = _this select 3}] call TFAR_fnc_addEventHandler;
} else {
	if (DT_isACREEnabled) then {
		DT_swRadioFrequencies params ["_frequencies","_groupArrays"];
		{
			private _freq = parseNumber _x;
			private _index = (_forEachIndex + 1);
			(_groupArrays select _forEachIndex) params ["_groupName"];

			{
				[_x,"default",_index,"label",_groupName] call acre_api_fnc_setPresetChannelField;
				[_x,"default",_index,"frequencyRX",_freq] call acre_api_fnc_setPresetChannelField;
				[_x,"default",_index,"frequencyTX",_freq] call acre_api_fnc_setPresetChannelField;
			} forEach ["ACRE_PRC343","ACRE_PRC148","ACRE_PRC152"];
		} forEach _frequencies;

		DT_lrRadioFrequencies params ["_frequencies","_groupArrays"];
		{
			private _freq = parseNumber _x;
			private _index = (_forEachIndex + 1);
			(_groupArrays select _forEachIndex) params ["_groupName"];

			{
				[_x,"default",_index,"label",_groupName] call acre_api_fnc_setPresetChannelField;
				[_x,"default",_index,"frequencyRX",_freq] call acre_api_fnc_setPresetChannelField;
				[_x,"default",_index,"frequencyTX",_freq] call acre_api_fnc_setPresetChannelField;
			} forEach ["ACRE_PRC117F","ACRE_PRC77"];
		} forEach _frequencies;
	};
};

["ace_arsenal_displayClosed",{
	if (DT_isTFAREnabled && {call TFAR_fnc_haveLRRadio}) then {call DT_fnc_initLrRadio};

	if (DT_autoSaveLoadout) then {
		DT_savedLoadout = [player] call CBA_fnc_getLoadout;	
		["Loadout saved."] call DT_fnc_notify;
	};

	if (parseNumber([player] call ace_common_fnc_getWeight) > DT_weightWarningThreshold) then {["You are carrying a lot of equipment which will affect your ability to operate. It may be worth reviewing your loadout to reduce your weight."] call DT_fnc_notify};
}] call CBA_fnc_addEventHandler;

["ace_treatmentSucceded",{
	params ["_caller","_target","_selectionName","_className","_itemUser","_usedItem"];

	private _medicalItems = [
		"ACE_fieldDressing","ACE_elasticBandage","ACE_packingBandage","ACE_quikclot",
		"ACE_splint",
		"ACE_bloodIV_250","ACE_bloodIV_500","ACE_bloodIV",
		"ACE_plasmaIV_250","ACE_plasmaIV_500","ACE_plasmaIV",
		"ACE_salineIV_250","ACE_salineIV_500","ACE_salineIV"
	];

	if (([typeOf _target] call DT_fnc_getConfigSide) isEqualTo civilian && {_usedItem in _medicalItems}) then {
		[_nearestSector,getNumber (missionConfigFile >> "Settings" >> "healedCivRepGain")] remoteExecCall ["DT_fnc_updateCivRep",2];
		[format["%1 thanks you for the treatment.",name _target]] call DT_fnc_notify;
	};
}] call CBA_fnc_addEventHandler;

[] call DT_fnc_initCBAsettings;
[] call DT_fnc_addAceActions;

658 cutRsc ["DT_HUD","PLAIN",-1];
DT_uiHandle = [DT_fnc_updateUI,DT_uiUpdateInterval,[true,""]] call CBA_fnc_addPerFrameHandler;

DT_isZeus = (getPlayerUID player) in (getArray(missionConfigFile >> "Settings" >> "zeusUIDs"));
if (DT_isZeus) then { 
	[player] remoteExecCall ["DT_fnc_assignZeus",2];

	private _zeusMenu = [
		"zeusMenu",
		"Zeus Suite",
		"\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\navigate_ca.paa",
		DT_fnc_initZeusMenu,
		{true}
	] call ace_interact_menu_fnc_createAction;
	[player,1,["ACE_SelfActions"],_zeusMenu] call ace_interact_menu_fnc_addActionToObject;
};

[] call DT_fnc_initGroupMenu;
[] call DT_fnc_initDeployMenu;

if (DT_showIntro) then {
	private _display = createDialog ["RscDisplayWelcome",true];
	private _text = _display displayCtrl 1100;
	private _message = "
		<t align='center' size='6' shadow='0'><br/>Frontlines</t><br/>
		Welcome to Frontlines, a sector control gamemode made for Arma 3.<br/>
		This is a Beta version of the original Frontlines, with a full rewrite from the ground up and work still ongoing to improve the mode.<br/><br/>
		<a color='#00DFFF'></a> Github: <a href='https://github.com/DomT602/Frontlines' color='#56BDD6'> https://github.com/DomT602/Frontlines</a><br/>
		<a color='#00DFFF'></a> Discord: <a href='https://discord.gg/FewM2Wfc9y' color='#56BDD6'> https://discord.gg/82tAKdsT79</a>
	";

	_text ctrlSetStructuredText (parseText _message);
	(ctrlPosition _text) params ["_xPos","_yPos","_width"];
	private _height = ctrlTextHeight _text;
	_text ctrlSetPosition [_xPos,_yPos,_width,_height];
	_text ctrlCommit 0;
};