/*
	File: fn_selectPosition.sqf
	Author: Dom
	Description: Selects the position in the group
*/

private _display = findDisplay 9702;
private _tree = _display displayCtrl 1500;
private _selectionPath = tvCurSel _tree;
private _oldGroup = group player;

_selectionPath params ["_groupIndex","_unitIndex"];

(parseSimpleArray (_tree tvData _selectionPath)) params ["_unitNetID","_desiredRole"];
private _unit = objectFromNetId _unitNetID;
if !(isNull _unit) exitWith {_tree tvSetCurSel _selectionPath}; //role selected already

[player,_selectionPath,_desiredRole] remoteExecCall ["DT_fnc_assignPlayer",2];
closeDialog 0;