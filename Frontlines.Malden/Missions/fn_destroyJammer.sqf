/*
	File: fn_destroyJammer.sqf
	Author: Dom
	Description: Creates and monitors mission to destroy a radio jammer
*/

private _frontlineSectors = [false] call DT_fnc_getFrontlineSectors;
private _spawnPos = [selectRandom _frontlineSectors,0,750,15,0,0.25,0] call BIS_fnc_findSafePos;

[format["The enemy has setup a jammer at %1 that is interfering with radio communications.",mapGridPosition _spawnPos],"generalNotif","Destoy Jammer"] remoteExecCall ["DT_fnc_notify",0];

private _jammer = createVehicle ["Land_MobileRadar_01_radar_F",_spawnPos];
_jammer setDir (_jammer getDir ([_jammer] call DT_fnc_getNearestFob));
if (DT_isTFAREnabled) then {
	missionNamespace setVariable ["TFAR_globalRadioRangeCoef",0.1,true];
} else {
	if (DT_isACREEnabled) then {
		[{
			private _coreSignal = _this call acre_sys_signal_fnc_getSignalCore;
			_coreSignal params ["_Px","_maxSignal"];
			_Px = _Px * 0.1;

			[_Px,_maxSignal]
		}] remoteExecCall ["acre_api_fnc_setCustomSignalFunc",0];
	};
};

private _squads = [_spawnPos,50,([0.75] call DT_fnc_calculateEnemySquads)] call DT_fnc_createPatrols;
_squads pushBack ([_spawnPos,50] call DT_fnc_createStatic);
[_spawnPos,500] call DT_fnc_createMines;

private _marker = ["destroyJammer",_spawnPos,true,"ColorOPFOR","ELLIPSE",250,"Destroy Jammer","Grid"] call DT_fnc_createMarker;

[
	{
		params ["_jammer"];
		!alive _jammer
	},
	{
		params ["","_marker","_pos","_squads"];

		deleteMarker _marker;
		if (DT_isTFAREnabled) then {
			missionNamespace setVariable ["TFAR_globalRadioRangeCoef",1,true];
		} else {
			if (DT_isACREEnabled) then {
				[{}] remoteExecCall ["acre_api_fnc_setCustomSignalFunc",0];
			};
		};
		["The jammer has been destroyed.","successNotif","Destroy Jammer"] remoteExecCall ["DT_fnc_notify",0];
		
		[
			{
				params ["_pos"];
				[_pos] call DT_fnc_areaIsClear
			},
			DT_fnc_clearArea,
			[_pos,_squads]
		] call CBA_fnc_waitUntilAndExecute;
	},
	[_jammer,_marker,_spawnPos,_squads]
] call CBA_fnc_waitUntilAndExecute;