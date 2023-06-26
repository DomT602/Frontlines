/*
	File: secureUAV.sqf
	Author: Dom
	Description: ACE Action to secure a UAV
*/
params [
	["_object",objNull,[objNull]]
];

private _action = [
	"secureUAV",
	"Secure UAV",
	"\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\download_ca.paa",
	{
		[
			15,
			[_target],
			{
				params ["_args"];
				_args params ["_uav"];
				_uav setVariable ["DT_intelDownloaded",true,true];
			},
			{
				["Download cancelled."] call DT_fnc_notify;
			},
			"Downloading",
			{
				params ["_args"];
				_args params ["_uav"];
				!(_uav getVariable ["DT_intelDownloaded",false])
			}
		] call ace_common_fnc_progressBar;
	},
	{
		alive _target && {!(_target getVariable ["DT_intelDownloaded",false])}
	}
] call ace_interact_menu_fnc_createAction;
[_object,0,["ACE_MainActions"],_action] call ace_interact_menu_fnc_addActionToObject;