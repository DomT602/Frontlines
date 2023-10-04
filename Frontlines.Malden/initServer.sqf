/*
	File: initServer.sqf
	Author: Dom
	Requires: Start the server up
*/
DT_isLambsEnabled = isClass(configFile >> "CfgPatches" >> "lambs_main");
DT_isZenEnabled = isClass(configFile >> "CfgPatches" >> "ZEN_main");
DT_isTFAREnabled = isClass (configFile >> "CfgPatches" >> "task_force_radio");
publicVariable "DT_isTFAREnabled";
DT_isACREEnabled = isClass (configFile >> "CfgPatches" >> "acre_main");
publicVariable "DT_isACREEnabled";

DT_dynamicGroups = getArray(missionConfigFile >> "Dynamic_Groups" >> "group_setup");
if (DT_isTFAREnabled || {DT_isACREEnabled}) then {
	DT_swRadioFrequencies = [[],[]];
	DT_lrRadioFrequencies = [[],[]];
};
{
	_x params ["_groupName","_roles","","_swFreq","_lrFreq"];

	if (DT_isTFAREnabled || {DT_isACREEnabled}) then {
		DT_swRadioFrequencies params ["_swFreqs","_swGroups"];
		private _freqIndex = _swFreqs find _swFreq;
		if (_freqIndex isNotEqualTo -1) then {
			(_swGroups select _freqIndex) pushBack _groupName;
		} else {
			_swFreqs pushBack _swFreq;
			_swGroups pushBack [_groupName];
		};

		DT_lrRadioFrequencies params ["_lrFreqs","_lrGroups"];
		private _freqIndex = _lrFreqs find _lrFreq;
		if (_freqIndex isNotEqualTo -1) then {
			(_lrGroups select _freqIndex) pushBack _groupName;
		} else {
			_lrFreqs pushBack _lrFreq;
			_lrGroups pushBack [_groupName];
		};
	};
	_x deleteAt 4;
	_x deleteAt 3;

	private _roleCount = count _roles;
	private _playerArray = [];
	for "_i" from 1 to _roleCount do {
		_playerArray pushBack objNull;
	};

	_x pushBack grpNull;
	_x pushBack _playerArray;
} forEach DT_dynamicGroups;
if (DT_isTFAREnabled || {DT_isACREEnabled}) then {
	publicVariable "DT_swRadioFrequencies";
	publicVariable "DT_lrRadioFrequencies";
};

[DT_dynamicGroups] remoteExecCall ["DT_fnc_updateGroups",-2,"DT_DG_JIP"];

addMissionEventHandler ["HandleDisconnect",DT_fnc_handleDisconnect];
addMissionEventHandler ["BuildingChanged",DT_fnc_buildingChanged];
addMissionEventHandler ["EntityKilled",DT_fnc_entityKilled];
addMissionEventHandler ["PlayerConnected",DT_fnc_playerConnected];

DT_bluforClassesToSave = [getText(missionConfigFile >> "Logi_Setup" >> "fobBuilding")];
{
	_x params ["","_options"];
	{
		_x params ["_class"];
		if (_class isEqualType []) then {
			_class = _class select 0;
		};
		DT_bluforClassesToSave pushBackUnique _class;
	} forEach _options;
} forEach getArray(missionConfigFile >> "Logi_Setup" >> "bluforBuyables");

{
	DT_bluforClassesToSave pushbackUnique (_x select 1);
} forEach getArray(missionConfigFile >> "Logi_Setup" >> "supplyCrateTypes");
publicVariable "DT_bluforClassesToSave";

[] call DT_fnc_addClassEventHandlers;

[] call DT_fnc_setupLocations;
[profileNamespace getVariable ["DT_serverSave",[]]] call DT_fnc_createOrLoadSave;

missionNamespace setVariable ["DT_activeSectors",[],true];

private _scanRadius = getNumber(missionConfigFile >> "Settings" >> "sectorActivationRange");
private _scanHeight = getNumber(missionConfigFile >> "Settings" >> "sectorActivationHeight");
[DT_fnc_mainSectorLoop,2,[_scanRadius,_scanHeight]] call CBA_fnc_addPerFrameHandler;

private _factoryProductionInterval = getNumber(missionConfigFile >> "Settings" >> "factoryProductionInterval");
private _factories = [["factory"]] call DT_fnc_getSectorsByType;
[DT_fnc_factoryLoop,_factoryProductionInterval,_factories] call CBA_fnc_addPerFrameHandler;

[DT_fnc_startSideMission,"",getNumber(missionConfigFile >> "Settings" >> "sideMissionTimer")] call CBA_fnc_waitAndExecute;

private _ambientLandCount = getNumber(missionConfigFile >> "Settings" >> "maxAmbientCivLand");
if (_ambientLandCount isNotEqualTo 0) then {
	DT_ambientCivs = [];
	[_ambientLandCount,true] call DT_fnc_spawnAmbientCiv;
};

private _ambientAirCount = getNumber(missionConfigFile >> "Settings" >> "maxAmbientCivAir");
if (_ambientAirCount isNotEqualTo 0 && {DT_airportLocations isNotEqualTo []}) then {
	DT_ambientCivAir = [];
	[_ambientAirCount,true] call DT_fnc_spawnAmbientCivAir;
};

DT_ambientOpfor = [];
DT_ambientOpforHandle = -1;
[] call DT_fnc_spawnAmbientOpfor;

private _cooldowns = [];
private _supportActions = getArray(missionConfigFile >> "Guerilla_Setup" >> "supports");
for "_i" from 1 to (count _supportActions) do {
	_cooldowns pushBack 0;
};
missionNamespace setVariable ["DT_supportCooldowns",_cooldowns,true];

[DT_fnc_saveGame,getNumber(missionConfigFile >> "Settings" >> "autoSaveTimer")] call CBA_fnc_addPerFrameHandler;

missionNamespace setVariable ["DT_serverReady",true,true];