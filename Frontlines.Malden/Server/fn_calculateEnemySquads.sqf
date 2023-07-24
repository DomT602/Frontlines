/*
	File: fn_calculateEnemySquads.sqf
	Author: Dom
	Description: Calculates enemy squads on player count and chosen modifier
*/
params [
	["_finalModifier",1,[0]],
	["_manualAddition",[0,0,0,0]]
];

private _baseCount = round(DT_threatLevel / 25) max 1;
_baseCount = _baseCount * (((0.1 * (count playableUnits)) max 0.75) min 2);
_baseCount = _baseCount * (getNumber(missionConfigFile >> "Settings" >> "difficultyModifier"));
_baseCount = _baseCount * _finalModifier;

private _infantryCount = 1 + (ceil _baseCount);
private _lightVehCount = ceil (_baseCount / 2);
private _mediumVehCount = round (_baseCount / 3);
private _heavyVehCount = if (DT_threatLevel > 66) then {round (_baseCount / 4)} else {0};

private _return = [_infantryCount,_lightVehCount,_mediumVehCount,_heavyVehCount];
_return vectorAdd _manualAddition;

_return;