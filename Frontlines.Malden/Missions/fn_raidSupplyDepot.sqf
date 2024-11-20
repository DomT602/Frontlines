/*
	File: fn_raidSupplyDepot.sqf
	Author: Dom
	Description: Secondary objective to raid a supply depot
*/
private _position = [] call DT_fnc_findObjectivePosition;
if (_position isEqualTo []) exitWith {
	["No suitable position was found."] remoteExecCall ["DT_fnc_notify",remoteExecutedOwner];
};
_position params ["_xPos","_yPos"];

missionNamespace setVariable ["DT_secondaryActive","supplyDepot",true];

private _objects = [];
private _objectives = [];

(selectRandom (getArray(missionConfigFile >> "Compositions" >> "opforDepots"))) params ["_compositionObjects","_compositionObjectives"];

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
	_x params ["_type","_pos","_dir"];
	_pos = _pos vectorAdd [_xPos,_yPos,0];

	private _class = getText(missionConfigFile >> "Opfor_Setup" >> _type);
	private _object = createVehicle [_class,_pos,[],0,"CAN_COLLIDE"];
	_object setPosATL _pos;
	_object setVectorUp [0,0,1];
	_object setDir _dir;
	[_object,_type] remoteExecCall ["DT_fnc_addDepotRaidAction",0,_object];

	_objectives pushBack _object;
} forEach _compositionObjectives;

private _squads = [_position,50,([1] call DT_fnc_calculateEnemySquads)] call DT_fnc_createPatrols;
_squads pushBack ([_position,50] call DT_fnc_createStatic);

private _marker = ["supplyDepot",_position,true,"ColorOPFOR","ELLIPSE",500,"Depot Raid","FDiagonal"] call DT_fnc_createMarker;
["The area the depot is in has been marked.","generalNotif","Depot Raid"] remoteExecCall ["DT_fnc_notify",0];

[
	{
		params ["_objectives","_position"];
		(_objectives select {alive _x && {(_x distance _position) < 100}}) isEqualTo [] || {isNil "DT_secondaryActive"}
	},
	{
		params ["","_position","_marker","_objects","_squads"];

		if (isNil "DT_secondaryActive") then {
			["Mission cancelled.","failedNotif","Depot Raid"] remoteExecCall ["DT_fnc_notify",0];
		} else {
			["The raid is complete.","successNotif","Depot Raid"] remoteExecCall ["DT_fnc_notify",0];
			[-5] call DT_fnc_updateThreat;
			missionNamespace setVariable ["DT_secondaryActive",nil,true];
		};
		deleteMarker _marker;

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