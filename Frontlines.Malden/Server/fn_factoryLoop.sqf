/*
	File: fn_mainSectorLoop.sqf
	Author: Dom
	Description: Handles factory production
*/
params ["_factories"];

private _factoryProductionAmount = getNumber(missionConfigFile >> "Settings" >> "factoryProductionAmount");
private _factoryProductionCap = getNumber(missionConfigFile >> "Settings" >> "factoryProductionCap");
{
	if (_x getVariable ["DT_sectorOwned",false]) then {
		private _type = _x getVariable ["DT_factoryType",-1];
		if (_type isNotEqualTo -1) then {
			private _resources = _x getVariable ["DT_factoryResources",[0,0,0]];
			private _totalRes = (_resources select 0) + (_resources select 1) + (_resources select 2);
			if (_totalRes > _factoryProductionCap) exitWith {};

			_resources set [_type,((_resources select _type) + _factoryProductionAmount) min _factoryProductionCap];
			_x setVariable ["DT_factoryResources",_resources,true];
		};
	};
} forEach _factories;