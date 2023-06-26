/*
	File: fn_createBluforMarkers.sqf
	Author: Dom
	Description: Creates blufor markers when map is opened
*/
private _markers = [];
{
	private _leader = leader _x;
	if (isPlayer _leader) then {
		private _roleName = getText(missionConfigFile >> "Dynamic_Roles" >> (_leader getVariable ["DT_role","rifleman"]) >> "name");

		private _marker = createMarkerLocal [format["grpLdr%1",_forEachIndex],_leader];
		_marker setMarkerColorLocal "ColorBLUFOR";
		if (isNull objectParent _leader) then {
			_marker setMarkerTypeLocal "b_inf";
			_marker setMarkerTextLocal format ["%1 - %2",_roleName,name _leader];
		} else {
			private _vehicle = objectParent _leader;
			if (_vehicle isKindOf "Tank") then {
				_marker setMarkerTypeLocal "b_armor";
			} else {
				if (_vehicle isKindOf "Air") then {
					if (_vehicle isKindOf "Plane") then {
						_marker setMarkerTypeLocal "b_plane";
					} else {
						_marker setMarkerTypeLocal "b_air";
					};
				} else {
					if (_vehicle isKindOf "Ship") then {
						_marker setMarkerTypeLocal "b_naval";
					} else {
						_marker setMarkerTypeLocal "b_motor_inf";
					};
				};
			};
			private _vehName = getText(configOf _vehicle >> "displayName");
			_marker setMarkerTextLocal format ["%1 - %2 - %3",_vehName,_roleName,name _leader];
		};
		_markers pushBack [_marker,_leader];
	};
} forEach groups west;

{
	private _marker = createMarkerLocal [format["mobRespawn%1",_forEachIndex],_x];
	_marker setMarkerTypeLocal "mil_start";
	private _vehicleName = getText(configOf _x >> "displayName");
	_marker setMarkerTextLocal format ["Mobile Respawn - %1",_vehicleName];
	_marker setMarkerColorLocal "ColorBLUFOR";
	_markers pushBack [_marker,_x];
} forEach (missionNamespace getVariable ["DT_mobileRespawns",[]]);

{
	if (side driver _x isEqualTo west) then {
		private _marker = createMarkerLocal [format["uav%1",_forEachIndex],_x];
		_marker setMarkerColorLocal "ColorBLUFOR";
		_marker setMarkerTypeLocal "b_uav";
		_marker setMarkerTextLocal (getText(configOf _x >> "displayName"));
		_markers pushBack [_marker,_x];
	};
} forEach allUnitsUAV;

[
	{
		params ["_markers","_handle"];

		if !(visibleMap) exitWith {
			[_handle] call CBA_fnc_removePerFrameHandler;

			{
				_x params ["_marker"];
				deleteMarkerLocal _marker;
			} forEach _markers;
		};

		{
			_x params ["_marker",["_unit",objNull]];
			if !(isNull _unit) then {
				_marker setMarkerPosLocal _unit;
			};
		} forEach _markers;
	},
	DT_mapUpdateInterval,
	_markers
] call CBA_fnc_addPerFrameHandler;