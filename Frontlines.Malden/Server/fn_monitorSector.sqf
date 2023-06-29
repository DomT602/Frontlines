/*
	File: fn_monitorSector.sqf
	Author: Dom
	Description: Sets up a sector and begins monitoring it
*/
params ["_args","_handle"];
_args params ["_sectorObj","_radius","_squads","_objectsToDelete","_timeoutCount"];

if (([_sectorObj,_radius] call DT_fnc_getCaptureRatio) > getNumber(missionConfigFile >> "Settings" >> "sectorCaptureRatio")) then {
	[_handle] call CBA_fnc_removePerFrameHandler;
	_sectorObj setVariable ["DT_sectorOwned",true,true];
	_sectorObj setVariable ["DT_sectorStrength",0,true];

	(_sectorObj getVariable "DT_sectorVariable") setMarkerColor "ColorBLUFOR";
	private _sectorName = _sectorObj getVariable "DT_sectorName";
	[format["%1 has been successfully captured.",_sectorName],"successNotif","Sector Secured"] remoteExecCall ["DT_fnc_notify",0];
	private _sectorType = _sectorObj getVariable "DT_sectorType";

	{
		{
			if (alive _x && {isNull objectParent _x && {50 > (random 100) && {_x distance2D _sectorObj < _radius}}}) then {
				[_x] call DT_fnc_surrenderUnit;
			};
		} forEach units _x;
	} forEach _squads;

	private _threatIncreaseArray = getArray(missionConfigFile >> "Settings" >> "sectorThreatIncreaseRate");
	private _sectorIndex = [_sectorType] call DT_fnc_getSectorTypeIndex;
	[_threatIncreaseArray select _sectorIndex] call DT_fnc_updateThreat;
	missionNamespace setVariable ["DT_canGatherIntel",true,true];

	if (_sectorType isEqualTo "tower") then {
		missionNamespace setVariable [format["DT_%1CapTime",_sector],CBA_missionTime];
	} else {
		if (_sectorType in ["town","city","factory"]) then {
			[] call DT_fnc_updateCivRep;
			if (_sectorType isEqualTo "factory") then {
				_sectorObj setVariable ["DT_factoryType",-1,true];
				_sectorObj setVariable ["DT_factoryResources",[0,0,0],true];
			};
		};
	};

	private _endedIndex = DT_allSectors findIf {!(_x getVariable ["DT_sectorOwned",false])};
	if (_endedIndex isEqualTo -1) then {
		[DT_totalPlaytime,DT_bluforDeaths,DT_opforDeaths,DT_guerillaDeaths,DT_civilianDeaths] remoteExec ["DT_fnc_endGame",0];
		[] call DT_fnc_wipeSave;
	} else {
		[
			DT_fnc_areaIsClear,
			{
				params ["_obj","_rad","_obj"];
				[_obj] call DT_fnc_clearArea;
				DT_activeSectors deleteAt (DT_activeSectors find _obj);
				publicVariable "DT_activeSectors";
			},
			[_sectorObj,_radius * 1.5,_sectorObj]
		] call CBA_fnc_waitUntilAndExecute;
	};
} else {
	if ([_sectorObj,_radius * 3] call DT_fnc_areaIsClear) then {
		_timeoutCount = _timeoutCount + 1;

		if (_timeoutCount > 600) then {
			[_handle] call CBA_fnc_removePerFrameHandler;

			private _endUnitCount = 0;
			{
				_endUnitCount = _endUnitCount + (count units _x);
			} forEach _squads;
			private _sectorStrength = (_endUnitCount / (_sectorObj getVariable ["DT_sectorUnitCount",10])) max 0.25;
			_sectorObj setVariable ["DT_sectorUnitCount",nil];
			_sectorObj setVariable ["DT_sectorStrength",_sectorStrength,true];

			[_sectorObj,_squads,_objectsToDelete] call DT_fnc_clearArea;

			DT_activeSectors deleteAt (DT_activeSectors find _sectorObj);
			publicVariable "DT_activeSectors";
		} else {
			_args set [4,_timeoutCount];
		};
	} else {
		if (_timeoutCount isNotEqualTo 0) then {
			_args set [4,0];
		};
	};
};