/*
	File: fn_createMarker.sqf
	Author: Dom
	Description: Creates a marker according to the parameters
*/
params [
	["_variable","",[""]],
	["_pos",[],[[],objNull]],
	["_randomise",false,[true]],
	["_colour","ColorOPFOR",[""]],
	["_shape","ELLIPSE",[""]],
	["_size",1,[0]],
	["_text","",[""]],
	["_brush","Solid",[""]]
];

if (_randomise) then {
	_pos = _pos getPos [random (_size / 2),random 360];
};

private _marker = createMarkerLocal [_variable,_pos];
_marker setMarkerColorLocal _colour;
if (_shape in ["ELLIPSE","RECTANGLE","ICON","POLYLINE"]) then {
	_marker setMarkerShapeLocal _shape;
	_marker setMarkerBrushLocal _brush;
} else {
	_marker setMarkerTypeLocal _shape;
};
if (_text isNotEqualTo "") then {
	_marker setMarkerTextLocal _text;
};
_marker setMarkerSize [_size,_size];

_marker;