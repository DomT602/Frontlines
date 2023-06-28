/*
	File: fn_onSupportMapPress.sqf
	Author: Dom
	Description: Shows a marker where the player clicks on the support menu
*/
params [
	["_control",controlNull,[controlNull]],
	["_button",0,[0]],
	["_x",0,[0]],
	["_y",0,[0]]
];

if (_button isEqualTo 0) then {
	private _position = _control ctrlMapScreenToWorld [_x,_y];
	private _markerPos = markerPos "supportTarget";
	if (_markerPos isEqualTo [0,0,0]) then {
		private _marker = createMarkerLocal ["supportTarget",_position];
		_marker setMarkerTypeLocal "mil_objective";
		_marker setMarkerColorLocal "ColorRed";
		_marker setMarkerTextLocal "Target";
	} else {
		"supportTarget" setMarkerPosLocal _position;
	};
};