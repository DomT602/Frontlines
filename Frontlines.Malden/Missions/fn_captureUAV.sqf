/*
	File: fn_captureUAV.sqf
	Author: Dom
	Description: Secondary objective to secure a downed UAV
*/
private _position = [] call DT_fnc_findObjectivePosition;
if (_position isEqualTo []) exitWith {
	["No suitable position was found."] remoteExecCall ["DT_fnc_notify",remoteExecutedOwner];
};
_position params ["_xPos","_yPos"];

[-10] call DT_fnc_updateIntel;
missionNamespace setVariable ["DT_secondaryActive","captureUAV",true];

private _craters = [];
_craters pushBack (createVehicle ["CraterLong",_position,[],0,"CAN_COLLIDE"]);
_craters pushBack (createVehicle ["CraterLong",(_position getPos [6,180]),[],0,"CAN_COLLIDE"]);
_craters pushBack (createVehicle ["CraterLong",(_position getPos [12,180]),[],0,"CAN_COLLIDE"]);

private _uav = createVehicle ["O_UAV_02_F",_position,[],0,"CAN_COLLIDE"];
_uav attachTo [(_craters select 0),[0,-1,1]];
_uav allowDamage false;
_uav setDamage 0.75;
_uav setVectorUp [0.5,0,1];
[_uav] remoteExecCall ["DT_fnc_secureUAV",0,_uav];

private _squads = [_position,100,([1] call DT_fnc_calculateEnemySquads)] call DT_fnc_createPatrols;

private _marker = ["captureUAV",_position,true,"ColorOPFOR","ELLIPSE",1000,"UAV Hunt","FDiagonal"] call DT_fnc_createMarker;
["The area the UAV went down in has been marked.","generalNotif","Downed UAV"] remoteExecCall ["DT_fnc_notify",0];

[
	{
		params ["_uav"];
		_uav getVariable ["DT_intelDownloaded",false] || {isNil "DT_secondaryActive"}
	},
	{
		params ["_uav","_craters","_marker","_squads"];

		if (isNil "DT_secondaryActive") then {
			["Mission cancelled.","failedNotif","Downed UAV"] remoteExecCall ["DT_fnc_notify",0];
		} else {	
			["The UAV data was downloaded.","successNotif","Downed UAV"] remoteExecCall ["DT_fnc_notify",0];
			[30] call DT_fnc_updateIntel;
			missionNamespace setVariable ["DT_secondaryActive",nil,true];
		};
		deleteMarker _marker;

		[
			{
				params ["_uav"];
				[_uav] call DT_fnc_areaIsClear;
			},
			DT_fnc_clearArea,
			[_uav,_squads,_craters]
		] call CBA_fnc_waitUntilAndExecute;
	},
	[_uav,_craters,_marker,_squads],
	1200 + (random 300),
	{
		params ["_uav","_craters","_marker","_squads"];
		deleteMarker _marker;
		["The UAV data was downloaded by the enemy.","failedNotif","Downed UAV"] remoteExecCall ["DT_fnc_notify",0];
		deleteMarker _marker;
		missionNamespace setVariable ["DT_secondaryActive",nil,true];

		[
			{
				params ["_uav"];
				[_uav] call DT_fnc_areaIsClear;
			},
			DT_fnc_clearArea,
			[_uav,_squads,_craters]
		] call CBA_fnc_waitUntilAndExecute;
	}
] call CBA_fnc_waitUntilAndExecute;