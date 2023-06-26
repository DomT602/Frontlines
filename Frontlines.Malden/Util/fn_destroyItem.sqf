/*
	File: fn_destroyItem.sqf
	Author: Dom
	Description: ACE Action to destroy an item
*/
params [
	["_object",objNull,[objNull]]
];

private _action = [
	"destroyItem",
	"Destroy",
	"\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\destroy_ca.paa",
	{deleteVehicle _target},
	{alive _target}
] call ace_interact_menu_fnc_createAction;
[_object,0,["ACE_MainActions"],_action] call ace_interact_menu_fnc_addActionToObject;