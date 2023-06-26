/*
	File: fn_initialiseObject.sqf
	Author: Dom
	Description: Initialises any extra properties for an object
*/
params [
	["_object",objNull,[objNull]],
	["_moving",false,[false]]
];
if (isNull _object) exitWith {};

private _class = typeOf _object;

if !(_moving) then {
	private _helipads = getArray(missionConfigFile >> "Logi_Setup" >> "helipads");
	if (_class in _helipads) then {
		private _maxHeliCount = missionNamespace getVariable ["DT_maxHelicopterCount",0];
		missionNamespace setVariable ["DT_maxHelicopterCount",_maxHeliCount + 1,true];
	} else {
		private _hangars = getArray(missionConfigFile >> "Logi_Setup" >> "hangars");
		if (_class in _hangars) then {
			private _maxPlaneCount = missionNamespace getVariable ["DT_maxPlaneCount",0];
			missionNamespace setVariable ["DT_maxPlaneCount",_maxPlaneCount + 1,true];
		};
	};

	private _radar = getText(missionConfigFile >> "Logi_Setup" >> "radar");
	if (_class isEqualTo _radar) then {
		missionNamespace setVariable ["DT_canPurchaseAir",true,true];
	};
};

{
	_x params ["_classes","_code"];

	if (_classes isEqualType "") then {
		_classes = [_classes];
	};

	if (_class in _classes) then {
		_object call compile _code;
	};
} forEach (getArray(missionConfigFile >> "Settings" >> "objectInits"));