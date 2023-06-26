/*
	File: fn_mineScanner.sqf
	Author: Dom
	Description: Scans for mines near friendly units
*/

{
	private _mines = nearestMines [_x,[],1000,false,true];
	{
		west revealMine _x;
	} forEach _mines;
} forEach playableUnits;

["Mines are now marked on the HUD of all friendly units."] call DT_fnc_notify;