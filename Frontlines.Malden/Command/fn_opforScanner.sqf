/*
	File: fn_mineScanner.sqf
	Author: Dom
	Description: Scans for opfor group leaders and marks them on the map for 5 minutes
*/

private _markers = [];
{
	private _pos = [_x] call CBA_fnc_getPos;
	_markers pushBack ([format["opfor%1",_x],_pos,true,"ColorOPFOR","RECTANGLE",150] call DT_fnc_createMarker);
} forEach (groups east);

["Opfor groups are now marked on the map, the markers will automatically be removed in 5 minutes."] call DT_fnc_notify;

[
	{
		{
			deleteMarker _x;
		} forEach _this;
	},
	_markers,
	300
] call CBA_fnc_waitAndExecute;