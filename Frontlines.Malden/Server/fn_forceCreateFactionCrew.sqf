/*
	File: fn_forceCreateFactionCrew.sqf
	Author: Dom
	Description: Used for when a vehicles config crew is not the correct faction
*/
params [
	["_vehGroup",grpNull,[grpNull]],
	["_emptyVehicle",objNull,[objNull]],
	["_side",east,[east]]
];

private _squadComposition = if (_side isEqualTo east) then {selectRandom (getArray(missionConfigFile >> "Opfor_Setup" >> "opforSquads"))} else {selectRandom (getArray(missionConfigFile >> "Guerilla_Setup" >> "guerillaSquads"))};
private _driver = [_vehGroup,_side,selectRandom _squadComposition,_emptyVehicle] call DT_fnc_createUnit;
_driver moveInDriver _emptyVehicle;
if (fullCrew [_emptyVehicle,"gunner",true] isNotEqualTo []) then {
	private _gunner = [_vehGroup,_side,selectRandom _squadComposition,_emptyVehicle] call DT_fnc_createUnit;
	_gunner moveInGunner _emptyVehicle;
};
if (fullCrew [_emptyVehicle,"commander",true] isNotEqualTo []) then {
	private _commander = [_vehGroup,_side,selectRandom _squadComposition,_emptyVehicle] call DT_fnc_createUnit;
	_commander moveInCommander _emptyVehicle;
};