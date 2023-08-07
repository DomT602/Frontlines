/*
	File: fn_recycleObject.sqf
	Author: Dom
	Description: Handles recycling an object
*/
params [
	["_object",objNull,[objNull]]
];

private _className = typeOf _object;
private _bluforBuildables = [];
{
	_x params ["","_options"];
	{
		if (_x select 0 isEqualType []) then {
			_x set [0,(_x select 0) select 0];
		};
		_bluforBuildables pushBackUnique _x;
	} forEach _options;
} forEach (getArray(missionConfigFile >> "Logi_Setup" >> "bluforBuyables"));

private _index = _bluforBuildables findIf {_x select 0 == _className};
private _resourcesToReturn = if (_index isEqualTo -1) then {getArray(missionConfigFile >> "Settings" >> "maxRecycleGain")} else {(_bluforBuildables select _index) select 1};

if (_object isKindOf "LandVehicle" || {_object isKindOf "Ship" || {_object isKindOf "Air"}}) then {
	private _damageArray = (getAllHitPointsDamage _object) select 2;
	private _maxDamage = count _damageArray;
	private _currentDamage = 0;
	{
		_currentDamage = _currentDamage + _x;
	} forEach _damageArray;
	_currentDamage = abs (_currentDamage / _maxDamage);
	_resourcesToReturn set [0,(_resourcesToReturn select 0) * (1 - _currentDamage)];

	private _fuel = fuel _object;
	_resourcesToReturn set [1,(_fuel * (_resourcesToReturn select 1))];

	private _ammo = 0;
	private _magazineArray = magazinesAmmo [_object,false];
	if (_magazineArray isNotEqualTo []) then {
		private _maxAmmo = 0;
		{
			_x params ["_class","_count"];
			_ammo = _ammo + _count;
			_maxAmmo = _maxAmmo + getNumber(configFile >> "CfgMagazines" >> _class >> "count");
		} forEach _magazineArray;
		_ammo = _ammo / _maxAmmo;
	};
	_resourcesToReturn set [2,_ammo * (_resourcesToReturn select 2)];
} else {
	_resourcesToReturn = _resourcesToReturn vectorMultiply 0.5;
};

_resourcesToReturn = _resourcesToReturn apply {floor _x};
_resourcesToReturn params ["_supplies","_fuel","_ammo"];
private _action = [
	format ["Recycling this will return %1 supplies, %2 fuel and %3 ammunition.",_supplies,_fuel,_ammo],
	"Recycling",
	"Recycle",
	"Cancel"
] call BIS_fnc_guiMessage;

if (_action) then {
	private _mobileRespawnIndex = (missionNamespace getVariable ["DT_mobileRespawns",[]]) find _object;
	if (_mobileRespawnIndex isNotEqualTo -1) then {
		DT_mobileRespawns deleteAt _mobileRespawnIndex;
		publicVariable "DT_mobileRespawns";
	};

	if (_object isKindOf "Air") then {
		private _heliIndex = (missionNamespace getVariable ["DT_currentHelicopters",[]]) find _object;
		if (_heliIndex isNotEqualTo -1) then {
			DT_currentHelicopters deleteAt _heliIndex;
			publicVariable "DT_currentHelicopters";
		} else {
			private _planeIndex = (missionNamespace getVariable ["DT_currentPlanes",[]]) find _object;
			if (_planeIndex isNotEqualTo -1) then {
				DT_currentPlanes deleteAt _planeIndex;
				publicVariable "DT_currentPlanes";
			};
		};
	};

	private _helipads = getArray(missionConfigFile >> "Logi_Setup" >> "helipads");
	if (_className in _helipads) then {
		private _maxHeliCount = missionNamespace getVariable ["DT_maxHelicopterCount",0];
		missionNamespace setVariable ["DT_maxHelicopterCount",_maxHeliCount - 1,true];
	};

	private _hangars = getArray(missionConfigFile >> "Logi_Setup" >> "hangars");
	if (_className in _hangars) then {
		private _maxPlaneCount = missionNamespace getVariable ["DT_maxPlaneCount",0];
		missionNamespace setVariable ["DT_maxPlaneCount",_maxPlaneCount - 1,true];
	};

	[_object,_resourcesToReturn,true] call DT_fnc_adjustResources;
	deleteVehicle _object;
};