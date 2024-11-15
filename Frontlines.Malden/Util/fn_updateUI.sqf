/*
	File: fn_updateUI.sqf
	Author: Dom
	Description: Handles all UI elements
*/
params ["_args"];
_args params ["_sectorShown","_marker"];

private _sector = [player,["town","city","factory","military","tower"]] call DT_fnc_getNearestSector;
private _radius = (getArray(missionConfigFile >> "Settings" >> "sectorRadius")) select ([_sector getVariable "DT_sectorType"] call DT_fnc_getSectorTypeIndex);
private _hud = uiNamespace getVariable ["DT_HUD",displayNull];

if (player distance2D _sector < _radius) then {
	private _closestSectorVar = format ["%1Marker",_sector];
	if (_marker isEqualTo "" || {_marker isNotEqualTo _closestSectorVar}) then {
		if (_marker isNotEqualTo _closestSectorVar) then {deleteMarkerLocal _marker};
		(_hud displayCtrl 1000) ctrlSetText (_sector getVariable "DT_sectorName");
		_marker = createMarkerLocal [_closestSectorVar,_sector];
		_marker setMarkerShapeLocal "Ellipse";
		_marker setMarkerSizeLocal [_radius,_radius];
		_marker setMarkerBrushLocal "SolidBorder";
		_args set [1,_marker];
	};

	private _ratio = [_sector,_radius] call DT_fnc_getCaptureRatio;
	if (DT_showCaptureBar) then {
		if !(_sectorShown) then {
			(_hud displayCtrl 1000) ctrlShow true;
			(_hud displayCtrl 1900) ctrlShow true;
			(_hud displayCtrl 1901) ctrlShow true;
			_args set [0,true];
		};
		(_hud displayCtrl 1900) progressSetPosition _ratio;
	};

	private _newColor = call {
		if (_ratio isEqualTo 0) exitWith {"ColorOPFOR"};
		if (_ratio isEqualTo 1) exitWith {"ColorBLUFOR"};
		"ColorCivilian"
	};
	if (_newColor isNotEqualTo (markerColor _marker)) then {
		_marker setMarkerColorLocal _newColor;
	};
} else {
	if (_sectorShown) then {
		(_hud displayCtrl 1000) ctrlShow false;
		(_hud displayCtrl 1900) ctrlShow false;
		(_hud displayCtrl 1901) ctrlShow false;
		_args set [0,false];
	};

	if (_marker isNotEqualTo "") then {
		deleteMarkerLocal _marker;
		_args set [1,""];
	};
};