/*
	File: fn_repairRequest.sqf
	Author: Dom
	Description: Side mission for a sector requesting assistance to repair their village
*/

private _possibleSectors = [["town","city","factory"],true] call DT_fnc_getSectorsByType;
_possibleSectors = _possibleSectors select {(_x getVariable ["DT_destroyedBuildingCount",0]) isNotEqualTo 0};

private _chosenSector = selectRandom _possibleSectors;
private _sectorName = _chosenSector getVariable "DT_sectorName";
private _buildingsLost = _chosenSector getVariable "DT_destroyedBuildingCount";
private _suppliesRequired = _buildingsLost * 100;

private _marker = ["repairTarget",_chosenSector,false,"ColorYellow","mil_objective",1.5,format["%1 supplies requested",_suppliesRequired]] call DT_fnc_createMarker;
[format["%1 has requested %2 supplies for repairs.",_sectorName,_suppliesRequired],"generalNotif","Repair Request"] remoteExecCall ["DT_fnc_notify",0];

(getArray(missionConfigFile >> "Logi_Setup" >> "bluforCrates")) params ["_crateClass"];
private _sectorIndex = [_chosenSector getVariable "DT_sectorType"] call DT_fnc_getSectorTypeIndex;
private _radius = (getArray(missionConfigFile >> "Settings" >> "sectorRadius")) select _sectorIndex;

[
	{
		params ["_sector","_crateClass","_radius","_cratesRequired"];
		count ((nearestObjects [_sector,[_crateClass],_radius,true]) select {isNull attachedTo _x}) >= _cratesRequired
	},
	{
		params ["_sector","_crateClass","_radius","_cratesRequired","_marker","_sectorName"];
		private _nearCrates = (nearestObjects [_sector,[_crateClass],_radius,true]) select {isNull attachedTo _x};
		for "_i" from 0 to (_cratesRequired - 1) do {
			deleteVehicle (_nearCrates select _i);
		};

		private _civRepGain = (getNumber(missionConfigFile >> "Settings" >> "damagedBuildingRepLoss")) * 1.5;
		[abs(_civRepGain * _cratesRequired)] call DT_fnc_updateCivRep;

		deleteMarker _marker;
		[format["%1 thanks you for the supplies.",_sectorName],"successNotif","Repair Request"] remoteExecCall ["DT_fnc_notify",0];
		_sector setVariable ["DT_destroyedBuildingCount",nil,true];
	},
	[_chosenSector,_crateClass,_radius,_buildingsLost,_marker,_sectorName],
	getNumber(missionConfigFile >> "Settings" >> "sideMissionTimer"),
	{
		params ["_sector","","","","_marker","_sectorName"];

		deleteMarker _marker;
		[format["You took too long to deliver supplies to %1.",_sectorName],"failedNotif","Repair Request"] remoteExecCall ["DT_fnc_notify",0];
		_sector setVariable ["DT_destroyedBuildingCount",nil,true];
	}
] call CBA_fnc_waitUntilAndExecute;