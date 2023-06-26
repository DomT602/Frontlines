/*
	File: fn_deployPlayer.sqf
	Author: Dom
	Description: Deploys the player at their selected location
*/

private _display = findDisplay 9640;
private _tree = _display displayCtrl 1500;
private _selectionPath = tvCurSel _tree;
private _object = objectFromNetId (_tree tvData _selectionPath);
if ((_selectionPath select 0) isEqualTo 1) then {
	private _timer = getNumber(missionConfigFile >> "Settings" >> "mobileRespawnTimer");
	DT_nextMobileRespawnAvailable = CBA_missionTime + _timer;
};

closeDialog 0;
player setVehiclePosition [_object,[],5];