/*
	File: fn_mainSectorLoop.sqf
	Author: Dom
	Description: Monitors all sectors for nearby players
*/
params ["_args"];
_args params ["_radius","_height"];

private _units = playableUnits;
{
	if !(_x getVariable ["DT_sectorOwned",false]) then {
		private _playersAtSector = _units inAreaArray [getPosATL _x,_radius,_radius,0,false,_height];
		if (_playersAtSector isNotEqualTo []) then {
			if !(_x in DT_activeSectors) then {
				[_x] call DT_fnc_activateSector;
			};
		};
	};
} forEach DT_allSectors;