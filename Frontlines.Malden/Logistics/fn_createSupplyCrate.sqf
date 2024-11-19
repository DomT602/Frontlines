/*
	File: fn_createSupplyCrate.sqf
	Author: Dom
	Description: Creates the supply crate
*/
params [
	["_target",[],[[]]]
];

private _display = findDisplay 9642;
private _airDrop = _target isNotEqualTo [];
if (_airDrop) then {
	_display = findDisplay 9646;
};

private _tree = _display displayCtrl 1500;
private _selectionPath = tvCurSel _tree;

(parseSimpleArray (_tree tvData _selectionPath)) params ["_type","_contents","_resources"];
private _localResources = [player] call DT_fnc_getCurrentResources;
if !([_localResources,_resources] call DT_fnc_compareResources) exitWith {
	["You don't have enough resources."] call DT_fnc_notify;
};

closeDialog 0;
[player,_resources,false] call DT_fnc_adjustResources;

private _allSupplyClasses = getArray(missionConfigFile >> "Logi_Setup" >> "supplyCrateTypes");
private _crateIndex = _allSupplyClasses findIf {_x select 0 == _type};
private _crateClass = (_allSupplyClasses select _crateIndex) select 1;

private _crate = objNull;
if (_airDrop) then {
	_target = _target vectorAdd [0,0,100];
	_crate = createVehicle [_crateClass,_target,[],10];
	private _chute = createVehicle ["B_Parachute_02_F",_target,[],0,"FLY"];
	_chute setPosASL (getPosASL _crate);
	_crate attachTo [_chute];
} else {
	_crate = createVehicle [_crateClass,player];
	[player,_crate] call ace_dragging_fnc_carryObject;
};

[_crate] call DT_fnc_clearCargo;
[_crate,true,[0,2,0],0,true] remoteExecCall ["ace_dragging_fnc_setDraggable",0,_crate];

{
	_x params ["_class","_count"];
	if (isClass(configFile >> "CfgVehicles" >> _class) && {getNumber(configFile >> "CfgVehicles" >> _class >> "isBackpack") isEqualTo 1}) then {
		_crate addBackpackCargoGlobal [_class,_count];
	} else {
		_crate addItemCargoGlobal [_class,_count];
	};
} forEach _contents;