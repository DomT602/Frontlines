/*
	File: fn_createDefences.sqf
	Author: Dom
	Description: Creates a set of defences around a location
*/
params [
	["_position",[],[[],objNull]],
	["_spawnRadius",150,[0]],
	["_mines",false,[true]]
];

private _groups = [];
if (random 100 > 50) then {
	_groups pushBack ([_position,_spawnRadius] call DT_fnc_createMortar);
};

for "_i" from 1 to ceil (DT_threatLevel / 33) do {
	_groups pushBack ([_position,_spawnRadius] call DT_fnc_createStatic);
};

if (_mines) then {
	[_position,_spawnRadius,round (DT_threatLevel / 10)] call DT_fnc_createMines;
};

_groups;