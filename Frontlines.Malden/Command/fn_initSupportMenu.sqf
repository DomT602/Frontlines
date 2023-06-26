/*
	File: fn_initSupportMenu.sqf
	Author: Dom
	Description: Opens and populates the support menu
*/

private _display = createDialog ["DT_supportMenu",true];
private _tree = _display displayCtrl 1500;
private _supportActions = getArray(missionConfigFile >> "Guerilla_Setup" >> "supports");
private _supportCooldowns = missionNamespace getVariable ["DT_supportCooldowns",[]];

{
	_x params ["_title","_action","_civRepRequired","_cooldown"];
	private _readyTime = _supportCooldowns select _forEachIndex;

	if (CBA_missionTime < _readyTime) then {_title = format ["%1 - %2 minutes till available",_title,ceil((_readyTime - CBA_missionTime) / 60)]};
	private _actionIndex = _tree tvAdd [[],_title];
	_tree tvSetData [[_actionIndex],str([_action,_civRepRequired,_cooldown])];

	private _colour = [1,0,0,1];
	if (DT_globalReputation >= _civRepRequired) then {
		_colour = [0,1,0,1];
	};
	_tree tvSetColor [[_actionIndex],_colour];

	if (_action isEqualTo "mortar") then {
		{
			_tree tvAdd [[_actionIndex],_x];
		} forEach ["HE x1","Smoke x1","Illumination x1","HE x3","Smoke x3","Illumination x3","HE x5","Smoke x5","Illumination x5"];
	} else {
		if (_action isEqualTo "supplyDrop") then {
			private _allSupplyBoxes = getArray(missionConfigFile >> "Logi_Setup" >> "supplyCrates") select {_x select 0 in ["medicalCrateCategory","lightWeaponCrateCategory"]};
			{
				_x params ["_category","_title","_crateSize","_resourcesRequired","_contents"];
				private _index = _tree tvAdd [[_actionIndex],format ["%1 - %2",_title,_resourcesRequired]];
				_tree tvSetData [[_actionIndex,_index],str([_crateSize,_contents,_resourcesRequired])];
			} forEach _allSupplyBoxes;
		} else {
			if (_action isEqualTo "crateRetrieve") then {
				private _crateTypes = getArray(missionConfigFile >> "Logi_Setup" >> "bluforCrates");
				{
					private _radius = (getArray(missionConfigFile >> "Settings" >> "sectorRadius")) select ([_x getVariable "DT_sectorType"] call DT_fnc_getSectorTypeIndex);
					private _crates = nearestObjects [_x,_crateTypes,(_radius * 1.1),true];
					if (_crates isNotEqualTo [] && {!(_x in DT_activeSectors)}) then {
						private _index = _tree tvAdd [[_actionIndex],_x getVariable "DT_sectorName"];
						_tree tvSetData [[_actionIndex,_index],netId _x];
					};
				} forEach DT_allSectors;
			} else {
				if (_action in ["infAttack","mechAttack","sectorDefence"]) then {
					private _targetSectors = if (_action isEqualTo "sectorDefence") then {DT_activeSectors select {_x getVariable ["DT_sectorOwned",false]}} else {DT_activeSectors select {!(_x getVariable ["DT_sectorOwned",false])}};
					{
						private _index = _tree tvAdd [[_actionIndex],_x getVariable "DT_sectorName"];
						_tree tvSetData [[_actionIndex,_index],netId _x];
					} forEach _targetSectors;
				};
			};
		};
	};
} forEach _supportActions;

_tree tvSetCurSel [0];