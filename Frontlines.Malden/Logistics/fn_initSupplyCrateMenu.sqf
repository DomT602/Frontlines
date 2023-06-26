/*
	File: fn_initSupplyCrate.sqf
	Author: Dom
	Description: Sets up the supply crate using config values
*/

private _display = createDialog ["DT_crateMenu",true];
private _tree = _display displayCtrl 1500;

{
	_tree tvAdd [[],_x];
} forEach ["Medical","Light Weapons","Heavy Weapons","Static Weapons","Miscellaneous"];

private _allSupplyBoxes = getArray(missionConfigFile >> "Logi_Setup" >> "supplyCrates");
{
	_x params ["_category","_title","_crateSize","_resources","_contents"];

	private _treeIndex = switch _category do {
		case "medicalCrateCategory": {0};
		case "lightWeaponCrateCategory": {1};
		case "heavyWeaponCrateCategory": {2};
		case "staticWeaponCrateCategory": {3};
		default {4};
	};

	private _crateIndex = _tree tvAdd [[_treeIndex],format ["%1 - %2",_title,_resources]];
	_tree tvSetData [[_treeIndex,_crateIndex],str([_crateSize,_contents,_resources])];
} forEach _allSupplyBoxes;

_tree tvSetCurSel [0];