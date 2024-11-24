/*
	File: fn_playerConnected.sqf
	Author: Dom
	Description: Handles a players connection
*/
params ["_id","_uid","_name","_jip","_owner","_idstr"];

if (missionNamespace getVariable ["DT_currentPlaytime",0] isEqualTo 0) then {
	DT_currentPlaytime = CBA_missionTime;
};