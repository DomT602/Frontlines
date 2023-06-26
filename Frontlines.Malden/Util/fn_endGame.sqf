/*
	File: fn_endGame.sqf
	Author: Dom
	Description: Handles ending of the game
*/
params ["_totalPlaytime","_bluforDeaths","_opforDeaths","_guerDeaths","_civDeaths"];

private _hours = floor(_totalPlaytime / 3600);
private _minutes = floor((_totalPlaytime mod 3600) / 60);
private _seconds = floor(_totalPlaytime % 60);

private _pages = [];
_pages pushBack (format ["<t size='1.5'>Total Playtime: %1:%2:%3<br/>",_hours,_minutes,_seconds]);
//_pages pushBack (format ["<t size='1.5'>Secondary Missions Completed: %1<br/>Secondary Missions Failed: %2",_secondaryComplete,_secondaryFailed]);
_pages pushBack (format ["<t size='1.5'>Blufor Deaths: %1<br/>Opfor Deaths: %2<br/>Guerilla Deaths: %3<br/>Civilian Deaths: %4",_bluforDeaths,_opforDeaths,_guerDeaths,_civDeaths]);
//_pages pushBack (format ["<t size='1.5'>Blufor Vehicles Destroyed: %1<br/>Blufor Armour Destroyed: %2<br/>Blufor Naval Destroyed: %3<br/>Blufor Air Destroyed: %4",_bluforVehLost,_bluforArmourLost,_bluforNavalLost,_bluforAirLost]);
//_pages pushBack (format ["<t size='1.5'>Opfor Vehicles Destroyed: %1<br/>Opfor Armour Destroyed: %2<br/>Opfor Naval Destroyed: %3<br/>Opfor Air Destroyed: %4",_opforVehLost,_opforArmourLost,_opforNavalLost,_opforAirLost]);
//_pages pushBack (format ["<t size='1.5'>Guerilla Vehicles Destroyed: %1<br/>Civilian Vehicles Destroyed: %2",_guerVehLost,_civVehLost]);
_pages pushBack ("<t size='1.5'>Thanks for playing Frontlines<br/>A gamemode made by Dom<br/>We hope to see you again soon");
{
	[
		_x,
		[0,1],[0,1],10
	] spawn BIS_fnc_dynamicText;
	diag_log parseText _x;
	sleep 12.5; //sleep as this is what BIS_fnc_dynamicText uses
} forEach _pages;