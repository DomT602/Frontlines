/*
	File: fn_setupPlayer.sqf
	Author: Dom
	Description: Finishes setting up the player in their new role/group
*/
params [
	["_desiredRole","rifleman",[""]],
	["_isRespawn",false,[true]]
];

private _roleConfig = missionConfigFile >> "Dynamic_Roles" >> _desiredRole;

if (isNil "AW_respawnLoadout") then {
	private _defaultLoadout = getArray(_roleConfig >> "defaultLoadout");
	player setUnitLoadout _defaultLoadout;
} else {
	player setUnitLoadout AW_respawnLoadout;
};
if (_isRespawn) exitWith {};

private _weapons = getArray(_roleConfig >> "arsenalWeapons");
_weapons append getArray(missionConfigFile >> "Common_Arsenal" >> "weapons");
private _magazines = getArray(_roleConfig >> "arsenalMagazines");
_magazines append getArray(missionConfigFile >> "Common_Arsenal" >> "magazines");
private _items = getArray(_roleConfig >> "arsenalItems");
_items append getArray(missionConfigFile >> "Common_Arsenal" >> "items");
_items append getArray(missionConfigFile >> "Core_Settings" >> "AW_arsenalCommon");
private _backpacks = getArray(_roleConfig >> "arsenalBackpacks");
_backpacks append getArray(missionConfigFile >> "Common_Arsenal" >> "backpacks");

[player,true,false] call ace_arsenal_fnc_removeVirtualItems;
{
	[player,_x,false] call ace_arsenal_fnc_addVirtualItems;
} forEach [_weapons,_magazines,_items,_backpacks];

private _roleRank = getText(_roleConfig >> "rank");
[player,_roleRank] remoteExecCall ["setUnitRank",0,player];

private _roleTraits = getArray(_roleConfig >> "traits");
{
	_x params ["_trait","_value"];
	if (_value isEqualType true && {_value}) then {
		player setUnitTrait [_trait,false];
	};
} forEach (getAllUnitTraits player);

{
	_x params ["_trait","_value",["_custom",false]];
	if (_value isEqualTo "true") then {_value = true} else {if (_value isEqualTo "false") then {_value = false}};
	player setUnitTrait [_trait,_value,_custom];
} forEach _roleTraits;

private _customVariables = getArray(_roleConfig >> "customVariables");
{
	player setVariable [_x,nil,true];
} forEach (missionNamespace getVariable ["DT_myCustomVariables",[]]);

DT_myCustomVariables = [];
{
	_x params ["_variable","_value","_global"];
	player setVariable [_variable,_value,call compile _global];
	DT_myCustomVariables pushBack _variable;
} forEach _customVariables;

player setVariable ["DT_role",_desiredRole,true];