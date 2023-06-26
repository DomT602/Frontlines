/*
	File: fn_setupSuicideBomber.sqf
	Author: Dom
	Description: Sets up suicide bomber and manages his actions
*/
params [
	["_unit",objNull,[objNull]]
];

_unit disableAI "FSM";
private _suicideVests = getArray(missionConfigFile >> "Civilian_Setup" >> "civilianBombVests");
_unit addVest selectRandom _suicideVests;
_unit addItemToVest "DemoCharge_Remote_Mag";
_unit addEventHandler ["Hit",{
	params ["_unit"];
	private _bomb = createVehicle ["DemoCharge_Remote_Ammo_Scripted",_unit,[],0,"CAN_COLLIDE"];
	_bomb setDamage 1;
}];

[
	{
		params ["_unit","_handle"];

		if (!alive _unit || {captive _unit || {!("DemoCharge_Remote_Mag" in magazines _unit)}}) exitWith {[_handle] call CBA_fnc_removePerFrameHandler};

		private _possibleTargets = playableUnits select {_unit distance2D _x < 50 && {civilian knowsAbout _x > 3.5}};
		if (_possibleTargets isNotEqualTo []) then {
			_possibleTargets params ["_target"];
			if !(_unit getVariable ["DT_suicideSetup",false]) then {
				[_unit] call CBA_fnc_clearWaypoints;
				_unit setBehaviour "CARELESS";
				_unit setCombatMode "BLUE";
				_unit setUnitPos "UP";
				_unit disableAI "AUTOCOMBAT";
				_unit setSpeedMode "FULL";
				_unit setVariable ["DT_suicideSetup",true];
			};
			if (_unit distance2D _target < 4) then {
				private _bomb = createVehicle ["DemoCharge_Remote_Ammo_Scripted",_unit,[],0,"CAN_COLLIDE"];
				_bomb setDamage 1;
			} else {
				_unit doMove (getPosATL _target);
			};
		};
	},
	1,
	_unit
] call CBA_fnc_addPerFrameHandler;