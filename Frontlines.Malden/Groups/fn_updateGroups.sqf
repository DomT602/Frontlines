/*
	File: fn_updateGroups.sqf
	Author: Dom
	Description: Updates the group variable and then the menu if its open
*/
params [
	["_groups",[],[[]]],
	["_oldSelectionPath",[],[[]]],
	["_newSelectionPath",[],[[]]],
	["_unit",objNull,[objNull]]
];

DT_dynamicGroups = _groups;

private _display = findDisplay 9702;
if !(isNull _display) then {
	private _tree = _display displayCtrl 1500;
	if (_oldSelectionPath isNotEqualTo []) then {
		private _oldData = parseSimpleArray (_tree tvData _oldSelectionPath);
		_oldData set [0,netID objNull];
		_tree tvSetData [_oldSelectionPath,str(_oldData)];

		private _roleName = getText(missionConfigFile >> "Dynamic_Roles" >> (_oldData select 1) >> "name");
		_tree tvSetText [_oldSelectionPath,format["%1: ",_roleName]];
		_tree tvSetColor [_oldSelectionPath,[1,1,1,1]];

		_tree tvSetPictureColor [_oldSelectionPath,[1,1,1,1]];
		_tree tvSetPictureRightColor [_oldSelectionPath,[1,1,1,1]];
	};

	if (_newSelectionPath isNotEqualTo []) then {
		private _newData = parseSimpleArray (_tree tvData _newSelectionPath);
		_newData set [0,netID _unit];
		_tree tvSetData [_newSelectionPath,str(_newData)];

		private _roleName = getText(missionConfigFile >> "Dynamic_Roles" >> (_newData select 1) >> "name");
		_tree tvSetText [_newSelectionPath,format["%1: %2",_roleName,name _unit]];
		_tree tvSetColor [_newSelectionPath,[1,1,1,0.4]];

		_tree tvSetPictureColor [_newSelectionPath,[1,1,1,0.4]];
		_tree tvSetPictureRightColor [_newSelectionPath,[1,1,1,0.4]];
	};

	_tree tvSetCurSel (tvCurSel _tree);
};