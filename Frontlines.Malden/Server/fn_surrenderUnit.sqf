/*
	File: fn_monitorSurrender.sqf
	Author: Dom
	Description: Monitors surrender state of an AI
*/
params [
	["_unit",objNull,[objNull]]
];

[_unit,"radioProtocol"] remoteExecCall ["disableAI",_unit];
[_unit,true] remoteExecCall ["ACE_captives_fnc_setSurrendered",_unit];

[
	{
		params ["_unit"];
		if (alive _unit) then {
			if ([_unit] call DT_fnc_areaIsClear) then {
				deleteVehicle _unit;
			} else {
				[_unit,"radioProtocol"] remoteExecCall ["enableAI",_unit];
				[_unit,false] remoteExecCall ["ACE_captives_fnc_setSurrendered",_unit];
			};
		};
	},
	_unit,
	150 + (random 450)
] call CBA_fnc_waitAndExecute;