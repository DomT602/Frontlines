/*
	File: fn_listeningPost.sqf
	Author: Dom
	Description: Secondary objective to setup a listening post to obtain intel
*/
params [
	["_stage","init",[""]],
	["_data",objNull,[objNull,[]]]
];

switch _stage do {
	case "init": {
		missionNamespace setVariable ["DT_secondaryActive","listeningPost",true];

		private _targetSector = selectRandom ([true] call DT_fnc_getFrontlineSectors);
		private _marker = ["listeningPost",_targetSector,false,"ColorYellow","mil_objective",1.5,"Listening Post Setup Location"] call DT_fnc_createMarker;
		["The location for the listening post is marked.","generalNotif","Listening Post"] remoteExecCall ["DT_fnc_notify",0];
	};

	case "cancel": {
		deleteMarker "listeningPost";
		["Mission cancelled.","failedNotif","Listening Post"] remoteExecCall ["DT_fnc_notify",0];
	};

	case "initPost": {
		if (owner _data isNotEqualTo 2) then {
			_data setOwner 2;
		};

		[_data,2] call ace_cargo_fnc_setSize;
		[_data,true,[0,1,1]] remoteExecCall ["ace_dragging_fnc_setCarryable",0,_data];

		_data addEventHandler ["Deleted",{["postKilled",_this] call DT_fnc_listeningPost}];

		[
			{
				params ["_post","_targetPos"];
				!alive _post || {isNil "DT_secondaryActive" || {isNull attachedTo _post && {_post distance2D _targetPos < 75}}}
			},
			{
				params ["_post"];

				if (isNil "DT_secondaryActive") then {
					deleteVehicle _post;
				};

				if (alive _post) then {
					["The listening post is now active.","generalNotif","Listening Post"] remoteExecCall ["DT_fnc_notify",0];
					["startPost",_post] call DT_fnc_listeningPost;
				};
			},
			[_data,markerPos "listeningPost"]
		] call CBA_fnc_waitUntilAndExecute;
	};

	case "postKilled": {
		missionNamespace setVariable ["DT_secondaryActive",nil,true];
		deleteMarker "listeningPost";
		["The listening post was destroyed.","failedNotif","Listening Post"] remoteExecCall ["DT_fnc_notify",0];
	};

	case "startPost": {
		private _counter = 1;
		missionNamespace setVariable ["DT_secondaryActive","listeningPostNoCancel",true];
		[
			{
				params ["_args","_handle"];
				_args params ["_post","_count"];

				if !(alive _post) exitWith {
					[_handle] call CBA_fnc_removePerFrameHandler;
				};

				if (_count mod 1800 isEqualTo 0) exitWith {
					[_handle] call CBA_fnc_removePerFrameHandler;
					_post removeAllEventHandlers "Deleted";
					deleteVehicle _post;
					deleteMarker "listeningPost";
					missionNamespace setVariable ["DT_secondaryActive",nil,true];
					["The listening post mission finished.","successNotif","Listening Post"] remoteExecCall ["DT_fnc_notify",0];
					["The full 60 intel was obtained."] remoteExecCall ["DT_fnc_notify",0];
				};

				private _nearPlayers = playableUnits findIf {_x distance _post < 50};
				private _enemyCount = {side _x isEqualTo east} count (_post nearEntities ["CAManBase",30]);
				if (_nearPlayers isEqualTo -1 && {_enemyCount > 0}) exitWith {
					[5] call DT_fnc_updateThreat;
					private _pos = getPosATL _post;
					deleteVehicle _post;

					[
						{
							params ["_pos"];
							[_pos] call DT_fnc_areaIsClear
						},
						DT_fnc_clearArea,
						[_pos,true]
					] call CBA_fnc_waitUntilAndExecute;
				};

				if (_count mod 60 isEqualTo 0) then {
					[2] call DT_fnc_updateIntel;
				};

				_args set [1,(_count + 1)];
			},
			1,
			[_data,_counter]
		] call CBA_fnc_addPerFrameHandler;

		private _counterAttackWaves = ceil(DT_threatLevel / 25);
		private _nearestSector = [_data,["tower","military","city"],true] call DT_fnc_getNearestSector;
		private _counterAttackTime = round (150 + random 150);
		for "_i" from 1 to _counterAttackWaves do {
			[DT_fnc_spawnAssault,[_data,_nearestSector],(_counterAttackTime * _i)] call CBA_fnc_waitAndExecute;
		};
	};
};