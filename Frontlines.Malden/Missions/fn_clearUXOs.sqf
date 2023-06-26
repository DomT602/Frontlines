/*
	File: fn_clearUXOs.sqf
	Author: Dom
	Description: Secondary objective to clear UXO's from a blufor sector
*/
[-3] call DT_fnc_updateIntel;
missionNamespace setVariable ["DT_secondaryActive","clearUXOs",true];

private _sectors = [["city","town","factory"],true] call DT_fnc_getSectorsByType;
private _civReps = [];
{
	_civReps pushBack (_x getVariable ["DT_sectorReputation",0]);
} forEach _sectors;
private _index = (_civReps call CBA_fnc_findMax) select 1;
private _chosenSector = _sectors select _index;

private _pos = getPosATL _chosenSector;
private _nearRoads = _pos nearRoads 150;
if (_nearRoads isEqualTo []) then {
	private _searchArea = [_pos,75,75,0,false];
	for "_i" from 0 to 10 do {
		_nearRoads pushBack ([_searchArea] call CBA_fnc_randPosArea);
	};
};
[_nearRoads,true] call CBA_fnc_shuffle;

private _uxoArray = [];
for "_i" from 1 to ((7 + round random 5) min (count _nearRoads)) do {
	private _className = format ["BombCluster_0%1_UXO%2_F",ceil (random 3),ceil (random 3)];
	private _uxo = createMine [_className,(_nearRoads select (_i - 1)),[],2];
	_uxo setDir (random 360);
	_uxoArray pushBack _uxo;

	{
		_x revealMine _uxo;
	} forEach [east,independent,civilian];
};

private _marker = ["clearUXOs",_pos,false,"ColorYellow","mil_objective",1.5,"UXOs"] call DT_fnc_createMarker;
["The town is marked, head there to assist.","generalNotif","Clearing UXOs"] remoteExecCall ["DT_fnc_notify",0];

[
	{
		params ["_mines"];
		(_mines select {!isNull _x && {mineActive _x}}) isEqualTo [] || {isNil "DT_secondaryActive"}
	},
	{
		params ["_mines","_sector","_marker"];

		if (isNil "DT_secondaryActive") then {
			["Mission cancelled.","failedNotif","Clearing UXOs"] remoteExecCall ["DT_fnc_notify",0];
			{
				deleteVehicle _x;
			} forEach _mines;
		} else {
			["The town is now clear of UXOs.","successNotif","Clearing UXOs"] remoteExecCall ["DT_fnc_notify",0];
			[_sector,30] call DT_fnc_updateCivRep;
			missionNamespace setVariable ["DT_secondaryActive",nil,true];
		};
		deleteMarker _marker;	
	},
	[_uxoArray,_chosenSector,_marker]
] call CBA_fnc_waitUntilAndExecute;