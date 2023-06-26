/*
	File: fn_entityKilled.sqf
	Author: Dom
	Description: Called when any entity is killed
*/
params ["_unit","_killer","_instigator"];
if (isNull _unit) exitWith {};

if (_unit isKindOf "CAManBase") then {
	private _side = side (group _unit);
	if (_side isEqualTo west) exitWith {
		DT_bluforDeaths = DT_bluforDeaths + 1
	};
	if (_side isEqualTo east) exitWith {
		DT_opforDeaths = DT_opforDeaths + 1;
		private _opforThreatCount = getNumber(missionConfigFile >> "Settings" >> "opforDeathsThreatIncreaseCount");
		if (DT_opforDeaths % _opforThreatCount isEqualTo 0) then {
			[1] call DT_fnc_updateThreat;
		};
	};
	if (_side isEqualTo resistance) exitWith {
		DT_guerillaDeaths = DT_guerillaDeaths + 1;
	};
	if (_side isEqualTo civilian) exitWith {
		DT_civilianDeaths = DT_civilianDeaths + 1;
	};
} else {
	if (_unit isKindOf "AllVehicles") then {
		private _mobileRespawnIndex = (missionNamespace getVariable ["DT_mobileRespawns",[]]) find _unit;
		if (_mobileRespawnIndex isNotEqualTo -1) then {
			DT_mobileRespawns deleteAt _mobileRespawnIndex;
			publicVariable "DT_mobileRespawns";
		};

		if (_unit isKindOf "Air") then {
			private _heliIndex = (missionNamespace getVariable ["DT_currentHelicopters",[]]) find _unit;
			if (_heliIndex isNotEqualTo -1) then {
				DT_currentHelicopters deleteAt _heliIndex;
				publicVariable "DT_currentHelicopters";
			} else {
				private _planeIndex = (missionNamespace getVariable ["DT_currentPlanes",[]]) find _unit;
				if (_planeIndex isNotEqualTo -1) then {
					DT_currentPlanes deleteAt _planeIndex;
					publicVariable "DT_currentPlanes";
				};
			};
		};

		private _civVehicles = getArray(missionConfigFile >> "Civilian_Setup" >> "civilianVehicleTypes");
		_civVehicles append (getArray(missionConfigFile >> "Civilian_Setup" >> "civilianAircraftTypes"));
		if (_class in _civVehicles) exitWith {
			if (side _killer isEqualTo west) then {
				["A civilian vehicle has been destroyed."] remoteExecCall ["DT_fnc_notify",0];

				private _nearestSector = [_unit,["town","city","factory"]] call DT_fnc_getNearestSector;
				if !(isNull _nearestSector) then {
					[_nearestSector,getNumber (missionConfigFile >> "Settings" >> "seizedCivVehicleRepLoss")] call DT_fnc_updateCivRep;

					private _civsKilled = _nearestSector getVariable ["DT_sectorCivsKilled",0];
					_nearestSector setVariable ["DT_sectorCivsKilled",_civsKilled + 1];
				};
			};
		};
	};
};