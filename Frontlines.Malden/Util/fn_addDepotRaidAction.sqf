/*
	File: fn_addDepotRaidAction.sqf
	Author: Dom
	Description: Adds the secure resource action to selected object
*/
params [
	["_object",objNull,[objNull]],
	["_type","supplies",[""]]
];

private _action = [
	"secureResources",
	"Secure Resources",
	"\a3\ui_f\data\IGUI\Cfg\simpleTasks\types\truck_ca.paa",
	{
		private _type = param [2];

		deleteVehicle _target;
		private _index = call {
			if (_type isEqualTo "opforSupplyTruck") exitWith {0};
			if (_type isEqualTo "opforFuelTruck") exitWith {1};
			2
		};
		private _array = [0,0,0];
		_array set [_index,400];
		[player,_array,true] call DT_fnc_adjustResources;
		["Resources stored."] call DT_fnc_notify;
	},
	{
		isNull objectParent player &&
		{[player,50] call DT_fnc_isNearFOB}
	},
	{},
	_type
] call ace_interact_menu_fnc_createAction;
[_object,0,["ACE_MainActions"],_action] call ace_interact_menu_fnc_addActionToObject;