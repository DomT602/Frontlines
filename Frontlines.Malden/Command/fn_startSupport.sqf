/*
	File: fn_startSupport.sqf
	Author: Dom
	Description: Starts the support action
*/

private _display = findDisplay 9646;
private _tree = _display displayCtrl 1500;
private _selectionPath = tvCurSel _tree;
_selectionPath params ["_firstIndex"];
private _supportCooldowns = missionNamespace getVariable ["DT_supportCooldowns",[]];

(parseSimpleArray (_tree tvData [_firstIndex])) params ["_action","_civRepRequired","_cooldown"];
if (CBA_missionTime < (_supportCooldowns select _firstIndex)) exitWith {["Cooldown not finished."] call DT_fnc_notify};
if (DT_globalReputation < _civRepRequired) exitWith {["Too low civilian reputation."] call DT_fnc_notify};

private _pos = markerPos "supportTarget";
if (_action in ["mortar","supplyDrop"] && {_pos isEqualTo [0,0,0]}) exitWith {["No suitable target has been selected."] call DT_fnc_notify};

if (_action isEqualTo "mortar") then {
	private _mortarType = _tree tvText _selectionPath;
	_pos set [2,150];

	private _count = 1;
	if ("3" in _mortarType) then {
		_count = 3;
	} else {
		if ("5" in _mortarType) then {
			_count = 5;
		};
	};
	_cooldown = _cooldown * _count;

	private _roundClass = "Sh_82mm_AMOS";
	private _speed = 75;
	if ("Smoke" in _mortarType) then {
		_roundClass = "SmokeShellArty";
	} else {
		if ("Illumination" in _mortarType) then {
			_roundClass = selectRandom ["F_40mm_White","F_40mm_Yellow","F_40mm_Green","F_40mm_Red"];
			_speed = 5;
		};
	};

	for "_i" from 1 to _count do {
		[
			{
				params ["_pos","_type","_speed"];
				private _vehicle = createVehicle [_type,_pos,[],10];
				_vehicle setVectorUp [0,0,-1];
				_vehicle setVelocity [0,0,(_speed * -1)];
			},
			[_pos,_roundClass,_speed],
			20 + (random 5) + (3 * _i)
		] remoteExecCall ["CBA_fnc_waitAndExecute",2];
	};
	["Rounds are being fired as ordered, approximately 30 seconds out."] call DT_fnc_notify;
} else {
	if (_action isEqualTo "supplyDrop") then {
		[_pos] call DT_fnc_createSupplyCrate;
	} else {
		if (_action isEqualTo "crateRetrieve") then {
			private _sector = objectFromNetId (_tree tvData _selectionPath);
			[_sector] remoteExecCall ["DT_fnc_autoCrateRetrieve",2];
			[format["Guerillas are retrieving crates from %1.",_sector getVariable "DT_sectorName"]] call DT_fnc_notify;
		} else {
			private _sector = objectFromNetId (_tree tvData _selectionPath);
			[_sector,_action] remoteExecCall ["DT_fnc_spawnGuerillas",2];
		};
	};
};

_supportCooldowns set [_firstIndex,(CBA_missionTime + _cooldown)];
missionNamespace setVariable ["DT_supportCooldowns",_supportCooldowns,true];

closeDialog 0;