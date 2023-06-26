/*
	File: fn_gatherIntel.sqf
	Author: Dom
	Description: Adds action for gathering intel from radio towers
*/
params [
	["_object",objNull,[objNull]],
	["_sectorObj",objNull,[objNull]]
];

private _action = [
	"gatherIntelTower",
	"Download intel",
	"\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\download_ca.paa",
	{
		missionNamespace setVariable ["DT_canGatherIntel",false,true];
		private _bluforTowers = count ([["tower"],true] call DT_fnc_getSectorsByType);
		private _amount = round ((ln (_bluforTowers ^ 2)) + 1);

		[_amount] remoteExecCall ["DT_fnc_updateIntel",2];
		[format["%1 intel was obtained from the communications network.",_amount]] remoteExecCall ["DT_fnc_notify",0];
	},
	{
		private _sector = param [2];
		private _nearestTowers = nearestObjects [getPosATL _target,["Land_Communication_F","Land_TTowerSmall_2_F","Land_TTowerBig_1_F"],30,true] select {alive _x};
		missionNamespace getVariable ["DT_canGatherIntel",false] && {_sector getVariable ["DT_sectorOwned",false] && {_nearestTowers isNotEqualTo []}}
	},
	{},
	_sectorObj
] call ace_interact_menu_fnc_createAction;
[_object,0,["ACE_MainActions"],_action] call ace_interact_menu_fnc_addActionToObject;