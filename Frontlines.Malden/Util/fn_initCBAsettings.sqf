/*
	File: fn_initCBAsettings.sqf
	Author: Dom
	Description: Sets up the CBA settings
*/
[
	"DT_preserveBuildData",
	"CHECKBOX",
	["Preserve build data","Saves height and direction when building."],
	["Frontlines","Building"]
] call CBA_fnc_addSetting;
DT_buildElevation = 0;
DT_buildRotation = 0;

[
	"DT_buildRotationIncrement",
	"SLIDER",
	["Build rotation increment","Select your desired rotation increment."],
	["Frontlines","Building"],
	[1,90,45,0]
] call CBA_fnc_addSetting;

[
	"DT_buildHeightIncrement",
	"SLIDER",
	["Build height increment","Select your desired height increment when moving an object up or down."],
	["Frontlines","Building"],
	[0.01,1,0.2,2]
] call CBA_fnc_addSetting;

[
	"DT_postBuildAction",
	"LIST",
	["Post build action","Choose what action should happen after a build occurs, repeat will not work with any vehicles."],
	["Frontlines","Building"],
	[[0,1,2],["None","Repeat Build","Re-open Menu"]]
] call CBA_fnc_addSetting;

[
	"DT_uiUpdateInterval",
	"SLIDER",
	["UI Update Interval","Choose the time interval between UI updates, the longer the interval the slower the update which may help performance for lower end systems."],
	["Frontlines","User Interface"],
	[0,10,0.5,2],
	nil,
	{
		if !(isNil "DT_uiHandle") then {
			[DT_uiHandle] call CBA_fnc_removePerFrameHandler;

			private _markerVar = "";
			private _sector = [player,["town","city","factory","military","tower"]] call DT_fnc_getNearestSector;
			private _radius = (getArray(missionConfigFile >> "Settings" >> "sectorRadius")) select ([_sector getVariable "DT_sectorType"] call DT_fnc_getSectorTypeIndex);
			if (player distance2D _sector < _radius) then {
				_markerVar = format ["%1Marker",_sector];
			};
			DT_uiHandle = [DT_fnc_updateUI,DT_uiUpdateInterval,[true,_markerVar]] call CBA_fnc_addPerFrameHandler;
		};
	}
] call CBA_fnc_addSetting;

[
	"DT_mapUpdateInterval",
	"SLIDER",
	["Map Update Interval","Choose the time interval between blufor map marker updates."],
	["Frontlines","Map"],
	[0,5,0,2]
] call CBA_fnc_addSetting;

[
	"DT_showIntro",
	"CHECKBOX",
	["Show intro screen","Shows the welcome screen, deselect to load straight in."],
	["Frontlines","User Interface"],
	true
] call CBA_fnc_addSetting;

[
	"DT_showCaptureBar",
	"CHECKBOX",
	["Show capture bar","Shows the capture bar when inside an objectives radius."],
	["Frontlines","User Interface"],
	true,
	nil,
	{
		if !(DT_showCaptureBar) then {
			private _hud = uiNamespace getVariable ["DT_HUD",displayNull];
			private _control = _hud displayCtrl 1000;
			if (ctrlShown _control) then {
				_control ctrlShow false;
				(_hud displayCtrl 1000) ctrlShow false;
				(_hud displayCtrl 1901) ctrlShow false;
			};
		};
	}
] call CBA_fnc_addSetting;

[
	"DT_autoSaveLoadout",
	"CHECKBOX",
	["Automatically save loadout","Automatically saves your loadout when the arsenal is closed."],
	["Frontlines","Arsenal"],
	true
] call CBA_fnc_addSetting;

[
	"DT_weightWarningThreshold",
	"SLIDER",
	["Weight Warning Threshold","Select the weight threshold which triggers the heavy weight warning message when leaving the arsenal."],
	["Frontlines","Arsenal"],
	[30,50,40,1]
] call CBA_fnc_addSetting;

[
	"DT_autoRadioOption",
	"LIST",
	["Automatic Radio Channel Selection","Choose what radio channel selection should happen once you recieve your radio (TFAR only)."],
	["Frontlines","Radio"],
	[[0,1,2],["Disabled","Group default","Last selected channel"],1]
] call CBA_fnc_addSetting;