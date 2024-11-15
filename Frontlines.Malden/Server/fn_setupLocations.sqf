/*
	File: fn_setupLocations.sqf
	Author: Dom
	Requires: Setups up all types of locations
*/

private _sectors = [];
{
	(_x splitString "_") params ["_type"];
	if (_type in ["tower","factory","military","city","town"]) then {
		private _pos = markerPos _x;
		_pos set [2,0];
		if (_type isEqualTo "tower") then {
			_x setMarkerText format ["%1 - %2",markerText _x,mapGridPosition _pos];
		};

		private _sectorNamespace = createSimpleObject ["CBA_NamespaceDummy",_pos];
		_sectorNamespace setPosATL _pos;
		_sectorNamespace setVariable ["DT_sectorVariable",_x,true];
		_sectorNamespace setVariable ["DT_sectorName",markerText _x,true];
		_sectorNamespace setVariable ["DT_sectorType",_type,true];

		_sectors pushBack _sectorNamespace;
	};
} forEach allMapMarkers;
missionNamespace setVariable ["DT_allSectors",_sectors,true];

DT_airportLocations = [];
private _config = configFile >> "cfgWorlds" >> worldName;
private _primAirport = getArray(_config >> "ilsPosition");
_primAirport set [2,0];
private _ilsDirection = getArray(_config >> "ilsDirection");
private _primAirportDirection = (_ilsDirection # 0) atan2 (_ilsDirection # 2) - 180;
DT_airportLocations pushBack [_primAirport,_primAirportDirection];

{
	private _secAirport = getArray(_x >> "ilsPosition");
	_secAirport set [2,0];
	private _ilsDirection = getArray(_x >> "ilsDirection");
	private _secAirportDirection = (_ilsDirection # 0) atan2 (_ilsDirection # 2) - 180;
	DT_airportLocations pushBack [_secAirport,_secAirportDirection];
} forEach ("true" configClasses (_config >> "SecondaryAirports")); 