/*
	File: fn_createOrLoadSave.sqf
	Author: Dom
	Requires: Creates or loads a save file
*/
params [
	["_save",[],[[]]]
];

if (_save isEqualTo []) then {
	private _fobPosition = markerPos "manualFobMarker";
	if (_fobPosition isEqualTo [0,0,0]) then {
		private _radius = (getNumber(missionConfigFile >> "Settings" >> "sectorActivationRange") * 1.25);
		private _startPos = [worldSize / 2,worldSize / 2];

		while {_fobPosition isEqualTo [0,0,0]} do {
			private _testPos = _startPos getPos [random (worldSize / 2),random 360];
			if (
				_testPos isFlatEmpty [-1,-1,0.1,5,0,false,objNull] isNotEqualTo [] &&
				{lineIntersectsSurfaces [AGLtoASL _testPos,AGLToASL _testPos vectorAdd [0,0,15],objNull,objNull,false,1,"GEOM","NONE"] isNotEqualTo [] &&
				{nearestTerrainObjects [_testPos,[],25,false] isEqualTo [] &&
				{DT_allSectors findIf {_x distance _testPos < _radius} isEqualTo -1}}}
			) then {
				_fobPosition = _testPos;
			};
		};
	};

	private _fobBuildingClass = getText(missionConfigFile >> "Logi_Setup" >> "fobBuilding");
	private _startRes = getArray(missionConfigFile >> "Settings" >> "startingResources");
	(getArray(missionConfigFile >> "Settings" >> "defaultFOBNames")) params ["_name"];

	private _fobBuilding = createVehicle [_fobBuildingClass,_fobPosition];
	_fobBuilding setPosATL _fobPosition;
	private _fobNamespace = createSimpleObject ["CBA_NamespaceDummy",_fobPosition];
	_fobNamespace setPosATL _fobPosition;
	private _fobVariable = "FOB_0";
	_fobNamespace setVariable ["DT_fobVariable",_fobVariable,true];
	_fobNamespace setVariable ["DT_fobName",_name,true];
	if (getNumber(missionConfigFile >> "Settings" >> "fobGlobalResourcePool") isEqualTo 0) then {
		_fobNamespace setVariable ["DT_fobResources",_startRes,true];
	} else {
		missionNamespace setVariable ["DT_globalResources",_startRes,true];
	};
	missionNamespace setVariable ["DT_allFOBs",[_fobNamespace],true];

	private _marker = createMarker [_fobVariable,_fobPosition];
	_marker setMarkerType "b_hq";
	_marker setMarkerSize [1.5,1.5];
	_marker setMarkerText _name;

	DT_logistics = [0,0,[]];
	[DT_logistics] remoteExecCall ["DT_fnc_updateLogistics",-2,"DT_Logi_JIP"];
	missionNamespace setVariable ["DT_threatLevel",0,true];
	missionNamespace setVariable ["DT_intelCount",0,true];
	[] call DT_fnc_updateCivRep;

	DT_playtime = 0;
	DT_bluforDeaths = 0;
	DT_opforDeaths = 0;
	DT_guerillaDeaths = 0;
	DT_civilianDeaths = 0;
} else {
	_save params ["_date","_sectors","_fobs","_logistics","_threat","_intel","_stats"];

	/*
	[
		[
			["DT_sectorStrength",1],
			["DT_sectorReputation",0],
			["DT_sectorOwned",true],
			["DT_sectorCivsKilled",2],
			["DT_destroyedBuildingCount",0],
			["DT_towerDestroyed",false],
			["DT_factoryType",0],
			["DT_factoryResources",[0,0,0]]
		],
	]

	[
		[
			"FOB Alpha",
			[0,0,0],
			[0,0,0]
			[
				objects
			]
		]
	]
	*/

	setDate _date;

	{
		private _sectorNamespace = _x;
		private _sectorInfo = _sectors select _forEachIndex;

		{
			_x params ["_var","_value"];
			_sectorNamespace setVariable [_var,_value,true];

			if (_var isEqualTo "dt_sectorowned" && {_value}) then {
				(_sectorNamespace getVariable "DT_sectorVariable") setMarkerColor "ColorBLUFOR";
			};
		} forEach _sectorInfo;
	} forEach DT_allSectors;

	private _fobNamespaces = [];
	{
		_x params ["_name","_position","_resources","_objects"];
		private _fobNamespace = createSimpleObject ["CBA_NamespaceDummy",_position];
		_fobNamespace setPosATL _position;
		_fobNamespaces pushBack _fobNamespace;
		private _fobVariable = format ["FOB_%1",_forEachIndex];
		_fobNamespace setVariable ["DT_fobVariable",_fobVariable,true];
		_fobNamespace setVariable ["DT_fobName",_name,true];
		if (getNumber(missionConfigFile >> "Settings" >> "fobGlobalResourcePool") isEqualTo 0) then {
			_fobNamespace setVariable ["DT_fobResources",_resources,true];
		} else {
			if (_forEachIndex isEqualTo 0) then {
				missionNamespace setVariable ["DT_globalResources",_resources,true];
			};
		};

		private _marker = createMarker [_fobVariable,_position];
		_marker setMarkerType "b_hq";
		_marker setMarkerSize [1.5,1.5];
		_marker setMarkerText _name;

		{
			_x params ["_class","_pos","_dir","_up",["_damageArray",[]],["_itemArray",[]]];

			private _object = createVehicle [_class,_pos,[],0,"CAN_COLLIDE"];
			_object setPosWorld _pos;
			_object setVectorDirAndUp [_dir,_up];
			{
				_object setHitIndex [_forEachIndex,_x,false];
			} forEach _damageArray;

			[_object] call DT_fnc_initialiseObject;

			if (unitIsUAV _object) then {
				[_object] call DT_fnc_setupUAV;
			};

			{
				_x params ["_items","_counts"];
				private _backpacks = _forEachIndex isEqualTo 3;
				{
					if (_backpacks) then {
						_object addBackpackCargoGlobal [_x,_counts select _forEachIndex];
					} else {
						_object addItemCargoGlobal [_x,_counts select _forEachIndex];
					};
				} forEach _items;
			} forEach _itemArray;
		} forEach _objects;
	} forEach _fobs;
	missionNamespace setVariable ["DT_allFOBs",_fobNamespaces,true];

	private _curRoutes = _logistics select 2;
	if (_curRoutes isNotEqualTo []) then {
		{
			_x params ["_from","_to","","_startTransitTime","_endTransitTime"];

			if ("FOB_" in _from) then {
				private _fromIndex  = DT_allFOBs findIf {_x getVariable "DT_fobVariable" == _from};
				_x set [0,DT_allFOBs select _fromIndex];
			} else {
				private _fromIndex  = DT_allSectors findIf {_x getVariable "DT_sectorVariable" == _from};
				_x set [0,DT_allSectors select _fromIndex];
			};

			if ("FOB_" in _to) then {
				private _toIndex  = DT_allFOBs findIf {_x getVariable "DT_fobVariable" == _to};
				_x set [1,DT_allFOBs select _toIndex];
			} else {
				private _toIndex  = DT_allSectors findIf {_x getVariable "DT_sectorVariable" == _to};
				_x set [1,DT_allSectors select _toIndex];
			};

			private _fullTransitTime = _endTransitTime - _startTransitTime;
			_x set [3,CBA_missionTime];
			_x set [4,(CBA_missionTime + _fullTransitTime)];
		} forEach _curRoutes;

		_logistics set [2,_curRoutes];
		DT_logisticsHandle = [DT_fnc_logisticsLoop,10] call CBA_fnc_addPerFrameHandler;
	};

	DT_logistics = _logistics;
	[DT_logistics] remoteExecCall ["DT_fnc_updateLogistics",-2,"DT_Logi_JIP"];

	missionNamespace setVariable ["DT_threatLevel",_threat,true];
	missionNamespace setVariable ["DT_intelCount",_intel,true];
	[] call DT_fnc_updateCivRep;

	DT_playtime = _stats select 0;
	DT_bluforDeaths = _stats select 1;
	DT_opforDeaths = _stats select 2;
	DT_guerillaDeaths = _stats select 3;
	DT_civilianDeaths = _stats select 4;
};

deleteMarker "manualFobMarker";
[] call DT_fnc_saveGame;

[
	{
		{
			[_x] call DT_fnc_createTower;
		} forEach ([["tower"]] call DT_fnc_getSectorsByType);
	},
	[],
	5
] call CBA_fnc_waitAndExecute;