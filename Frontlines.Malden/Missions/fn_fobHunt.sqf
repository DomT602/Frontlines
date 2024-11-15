/*
	File: fn_fobHunt.sqf
	Author: Dom
	Description: Secondary objective to hunt a FOB
*/
private _position = [] call DT_fnc_findObjectivePosition;
if (_position isEqualTo []) exitWith {
	["No suitable position was found."] remoteExecCall ["DT_fnc_notify",remoteExecutedOwner];
};
_position params ["_xPos","_yPos"];

missionNamespace setVariable ["DT_secondaryActive","fobHunt",true];

private _objects = [];
private _objectives = [];

(selectRandom (getArray(missionConfigFile >> "Compositions" >> "opforFOBs"))) params ["_compositionObjects","_compositionObjectives"];

{
	_x params ["_class","_pos","_dir"];
	_pos = _pos vectorAdd [_xPos,_yPos,0];
	private _object = createVehicle [_class,_pos,[],0,"CAN_COLLIDE"];
	_object setPosATL _pos;
	_object setVectorUp [0,0,1];
	_object setDir _dir;

	_objects pushBack _object;
} forEach _compositionObjects;

{
	_x params ["_class","_pos","_dir"];
	_pos = _pos vectorAdd [_xPos,_yPos,0];
	private _object = createVehicle [_class,_pos,[],0,"CAN_COLLIDE"];
	_object setPosATL _pos;
	_object setVectorUp [0,0,1];
	_object setDir _dir;
	_object lock 2;

	if (_class isEqualTo "Land_Laptop_unfolded_F") then {
		[_object] remoteExecCall ["DT_fnc_destroyItem",0,_object];
	};

	_objectives pushBack _object;
} forEach _compositionObjectives;

private _squads = [_position,50,([1.25] call DT_fnc_calculateEnemySquads)] call DT_fnc_createPatrols;
_squads append ([_position,50,true] call DT_fnc_createDefences);

private _marker = ["fobHunt",_position,true,"ColorOPFOR","ELLIPSE",1000,"FOB Hunt","FDiagonal"] call DT_fnc_createMarker;
["The area the FOB is in has been marked.","generalNotif","FOB Hunting"] remoteExecCall ["DT_fnc_notify",0];

[
	{
		params ["_objectives"];
		(_objectives select {alive _x}) isEqualTo [] || {isNil "DT_secondaryActive"}
	},
	{
		params ["_objectives","_position","_marker","_objects","_squads"];

		if (isNil "DT_secondaryActive") then {
			["Mission cancelled.","failedNotif","FOB Hunting"] remoteExecCall ["DT_fnc_notify",0];
		} else {
			["The FOB has been destroyed.","successNotif","FOB Hunting"] remoteExecCall ["DT_fnc_notify",0];
			[-40] call DT_fnc_updateThreat;
			missionNamespace setVariable ["DT_secondaryActive",nil,true];
		};
		deleteMarker _marker;
		_objects append _objectives;

		[
			{
				params ["_pos"];
				[_pos] call DT_fnc_areaIsClear
			},
			DT_fnc_clearArea,
			[_position,_squads,_objects]
		] call CBA_fnc_waitUntilAndExecute;
	},
	[_objectives,_position,_marker,_objects,_squads]
] call CBA_fnc_waitUntilAndExecute;