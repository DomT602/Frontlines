/*
	File: fn_zeusAction.sqf
	Author: Dom
	Description: Applys action from zeus menu
*/
params [
	["_action","",[""]]
];

private _display = findDisplay 9649;
private _editBox = _display displayCtrl 1400;
private _sectorListbox = _display displayCtrl 1500;
private _fobListbox = _display displayCtrl 1501;
private _index = lbCurSel _sectorListbox;
private _text = ctrlText _editBox;
private _sector = objectFromNetId (_sectorListbox lbData _index);
private _fob = objectFromNetId (_fobListbox lbData (lbCurSel _fobListbox));

switch _action do {
	case "adjustIntel": {
		if !([_text] call DT_fnc_checkNumber) exitWith {};
		private _number = parseNumber _text;

		[_number] remoteExecCall ["DT_fnc_updateIntel",2];
		["Intel updated."] call DT_fnc_notify;
	};

	case "adjustCivRep": {
		if !([_text] call DT_fnc_checkNumber) exitWith {};
		if (_sector getVariable "DT_sectorType" in ["military","tower"]) exitWith {["You need to select a civilian sector."] call DT_fnc_notify};
		private _number = parseNumber _text;

		[_sector,_number] remoteExecCall ["DT_fnc_adjustCivRep",2];
		[format["Civilian reputation in %1 updated.",_sector getVariable "DT_sectorName"]] call DT_fnc_notify;
	};

	case "adjustThreat": {
		if !([_text] call DT_fnc_checkNumber) exitWith {};
		private _number = parseNumber _text;

		[_number] remoteExecCall ["DT_fnc_updateThreat",2];
		["Threat level updated."] call DT_fnc_notify;
	};

	case "adjustResources": {
		if !([_text] call DT_fnc_checkNumber) exitWith {};
		private _number = parseNumber _text;
		
		private _resources = [0,0,0];
		_resources set [(_this select 1),_number];
		[_fob,_resources,true] call DT_fnc_adjustResources;
		["Resources updated."] call DT_fnc_notify;
	};

	case "forceSave": {
		[] remoteExecCall ["DT_fnc_saveGame",2];
		["Save request sent to server."] call DT_fnc_notify;
	};

	case "wipeSave": {
		private _action = [
			"Are you sure you want to wipe the server progress (this should only need to be done before switching maps)",
			"Wiping Save",
			"Confirm",
			"Cancel"
		] call BIS_fnc_guiMessage;

		if (_action) then {
			[] remoteExecCall ["DT_fnc_wipeSave",2];
			["Wipe request sent to server."] call DT_fnc_notify;
		};
	};

	case "callReinforcements": {
		if !(_sector in DT_activeSectors) exitWith {["Sector is not active."] call DT_fnc_notify};
		[_sector] remoteExecCall ["DT_fnc_callReinforcements",2];
	};

	case "activateSector": {
		if (_sector getVariable ["DT_sectorOwned",false]) exitWith {["Sector is already captured."] call DT_fnc_notify};
		if (_sector in DT_activeSectors) exitWith {["Sector must be inactive."] call DT_fnc_notify};

		[_sector] remoteExecCall ["DT_fnc_activateSector",2];
	};

	case "captureSector": {
		if (_sector getVariable ["DT_sectorOwned",false]) exitWith {["Sector is already captured."] call DT_fnc_notify};
		if (_sector in DT_activeSectors) exitWith {["Sector must be inactive."] call DT_fnc_notify};

		_sector setVariable ["DT_sectorOwned",true,true];
		(_sector getVariable "DT_sectorVariable") setMarkerColor "colorBLUFOR";
		_sector setVariable ["DT_sectorStrength",0,true];
		_sectorListbox lbSetColor [_index,[0,0.3,0.6,1]];

		private _sectorType = _sector getVariable "DT_sectorType";
		if (_sectorType isEqualTo "tower") then {
			missionNamespace setVariable [format["DT_%1CapTime",_sector],CBA_missionTime,2];
		} else {
			if (_sectorType in ["town","city","factory"]) then {
				[] remoteExecCall ["DT_fnc_updateCivRep",2];
				if (_sectorType isEqualTo "factory") then {
					_sector setVariable ["DT_factoryType",-1,true];
					_sector setVariable ["DT_factoryResources",[0,0,0],true];
				};
			};
		};
	};

	case "loseSector": {
		if !(_sector getVariable ["DT_sectorOwned",false]) exitWith {["Sector is not captured."] call DT_fnc_notify};
		if (_sector in DT_activeSectors) exitWith {["Sector must be inactive."] call DT_fnc_notify};

		_sector setVariable ["DT_sectorOwned",true,true];
		(_sector getVariable "DT_sectorVariable") setMarkerColor "colorOPFOR";
		_sector setVariable ["DT_sectorStrength",([] call DT_fnc_getAverageStrength),true];
		_sectorListbox lbSetColor [_index,[0,0.3,0.6,1]];

		private _sectorType = _sector getVariable "DT_sectorType";
		if (_sectorType isEqualTo "factory") then {
			_sector setVariable ["DT_factoryType",nil,true];
			_sector setVariable ["DT_factoryResources",nil,true];
		};
	};

	case "destroyAA": {
		[] remoteExecCall ["DT_fnc_destroyAA",2];
	};

	case "destroyJammer": {
		[] remoteExecCall ["DT_fnc_destroyJammer",2];
	};

	case "repairRequest": {
		[] remoteExecCall ["DT_fnc_repairRequest",2];
	};

	case "fobAssault": {
		if (count playableUnits < 4) exitWith {["Too few players on."] call DT_fnc_notify};
		[] remoteExecCall ["DT_fnc_fobAssault",2];
	};

	case "convoyAmbush": {
		if ((DT_logistics select 2) isEqualTo []) exitWith {["No convoys moving."] call DT_fnc_notify};
		[] remoteExecCall ["DT_fnc_ambushLogisticsConvoy",2];
	};

	case "sectorCounterAttack": {
		if (([true,1] call DT_fnc_getFrontlineSectors) isEqualTo []) exitWith {["No sectors to attack."] call DT_fnc_notify};
		[] remoteExecCall ["DT_fnc_sectorCounterAttack",2];
	};

	case "allowDamage": {
		if (isDamageAllowed player) then {
			player allowDamage false;
			["Damage disabled."] call DT_fnc_notify;
		} else {
			player allowDamage true;
			["Damage enabled."] call DT_fnc_notify;
		};
	};

	case "openArsenal": {
		[player,player,true] call ace_arsenal_fnc_openBox;
	};

	case "heal": {
		private _vehicle = objectParent player;
		if !(isNull _vehicle) then {
			_vehicle setDamage 0;
		};
		[player] call ace_medical_treatment_fnc_fullHealLocal;
	};

	case "hideObject": {
		if (isObjectHidden player) then {
			[player,false] remoteExecCall ["hideObjectGlobal",2];
			["Player object now shown."] call DT_fnc_notify;
		} else {
			[player,true] remoteExecCall ["hideObjectGlobal",2];
			["Player object now invisible."] call DT_fnc_notify;
		};
	};

	case "clearSmoke": {
		if !([_text] call DT_fnc_checkNumber) exitWith {};
		private _number = parseNumber _text;

		{
			deleteVehicle _x;
		} forEach (player nearObjects ["SmokeShell",_number]);
	};

	case "clearMines": {
		if !([_text] call DT_fnc_checkNumber) exitWith {};
		private _number = parseNumber _text;

		{
			deleteVehicle _x;
		} forEach (nearestMines [player,[],_number,false,true]);
	};
};