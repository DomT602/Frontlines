/*
	File: fn_calculateEnemySquads.sqf
	Author: Dom
	Description: Calculates enemy squads on player count and chosen modifier
*/
params [
	["_initialModifier",1,[0]],
	["_manualAddition",[0,0,0,0]]
];

private _squadCounts = (round(DT_threatLevel / 25) max 1) * _initialModifier;
private _playerModifier = ((0.15 * (count playableUnits)) max 0.5) min 2.5;
private _difficultyModifier = getNumber (missionConfigFile >> "Settings" >> "difficultyModifier");

private _infantryCount = ceil (_squadCounts * _difficultyModifier * _playerModifier);
private _lightVehCount = ceil ((_squadCounts / 2) * _difficultyModifier * _playerModifier);
private _mediumVehCount = round ((_squadCounts / 3) * _difficultyModifier * _playerModifier);
private _heavyVehCount = round ((_squadCounts / 4) * _difficultyModifier * _playerModifier);

private _return = [_infantryCount,_lightVehCount,_mediumVehCount,_heavyVehCount];
_return vectorAdd _manualAddition;

_return;