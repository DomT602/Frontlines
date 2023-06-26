/*
	File: fn_retrieveResources.sqf
	Author: Dom
	Description: Pulls desired resources out of a location
*/
private _display = findDisplay 9648;
private _desiredSupplies = ctrlText (_display displayCtrl 1400);
private _desiredFuel = ctrlText (_display displayCtrl 1401);
private _desiredAmmo = ctrlText (_display displayCtrl 1402);
if (!([_desiredSupplies] call DT_fnc_checkNumber) || {!([_desiredFuel] call DT_fnc_checkNumber) || {!([_desiredAmmo] call DT_fnc_checkNumber)}}) exitWith {};
private _desiredArray = [];
_desiredArray pushBack (parseNumber _desiredSupplies);
_desiredArray pushBack (parseNumber _desiredFuel);
_desiredArray pushBack (parseNumber _desiredAmmo);

private _isAtFOB = [player] call DT_fnc_isNearFOB;
private _safePosition = (getPosATL player) findEmptyPosition [0,75,"Land_HelipadEmpty_F"];
if (_safePosition isEqualTo []) exitWith {["No suitable position to spawn crates, move somewhere else."] call DT_fnc_notify};

private _storedResources = [];
private "_nearestFactory";
if (_isAtFOB) then {
	_storedResources = [player] call DT_fnc_getCurrentResources;
} else {
	_nearestFactory = [player,["factory"]] call DT_fnc_getNearestSector;
	_storedResources = _nearestFactory getVariable "DT_factoryResources";
};
_storedResources = _storedResources apply {_x / 100};

private _enoughResources = true;
{
	if (_x > (_storedResources select _forEachIndex)) exitWith {
		_enoughResources = false;
	};
} forEach _desiredArray;
if !(_enoughResources) exitWith {["Not enough resources are stored here."] call DT_fnc_notify};
closeDialog 0;

private _crateTypes = getArray(missionConfigFile >> "Logi_Setup" >> "bluforCrates");
private _offset = 2.5;

{
	for "_i" from 1 to _x do {
		private _spawnPos = _safePosition getPos [_offset,90 * _forEachIndex];
		private _crate = createVehicle [_crateTypes select _forEachIndex,_spawnPos];
		_offset = _offset + 2;
	};

	_offset = 2.5;
} forEach _desiredArray;

_desiredArray = _desiredArray apply {_x * 100};
if (_isAtFOB) then {
	[player,_desiredArray,false] call DT_fnc_adjustResources;
} else {
	_nearestFactory setVariable ["DT_factoryResources",_storedResources vectorDiff _desiredArray,true];
};