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
private _defaultLoadout = getArray(_roleConfig >> "defaultLoadout");

if (_isRespawn) then {
	[player,missionNamespace getVariable ["DT_savedLoadout",_defaultLoadout],true] call CBA_fnc_setLoadout;
} else {
	DT_savedLoadout = _defaultLoadout;
	[player,_defaultLoadout,true] call CBA_fnc_setLoadout;

	private _items = getArray(_roleConfig >> "arsenalItems");
	_items append getArray(missionConfigFile >> "Common_Arsenal" >> "items");

	[player,true,false] call ace_arsenal_fnc_removeVirtualItems;
	[player,_items,false] call ace_arsenal_fnc_addVirtualItems;
	private _roleName = getText(_roleConfig >> "name");
	[_roleName,_defaultLoadout] call ace_arsenal_fnc_addDefaultLoadout;

	private _roleRank = getText(_roleConfig >> "rank");
	player setUnitRank _roleRank;

	private _roleTraits = getArray(_roleConfig >> "traits");
	{
		_x params ["_trait","_value"];
		if (_value isEqualType true && {_value}) then {
			player setUnitTrait [_trait,false];
		};
	} forEach (getAllUnitTraits player);

	{
		_x params ["_trait","_value",["_custom","false"]];
		if (_value in ["true","false"]) then {_value = call compile _value};
		player setUnitTrait [_trait,_value,call compile _custom];
	} forEach _roleTraits;

	private _customVariables = getArray(_roleConfig >> "customVariables");
	{
		player setVariable [_x,nil,true];
	} forEach (missionNamespace getVariable ["DT_myCustomVariables",[]]);

	DT_myCustomVariables = [];
	{
		_x params ["_variable","_value","_global"];
		if (_value in ["true","false"]) then {_value = call compile _value};
		player setVariable [_variable,_value,call compile _global];
		DT_myCustomVariables pushBack _variable;
	} forEach _customVariables;

	player setVariable ["DT_role",_desiredRole,true];
};