/*
	File: fn_wipeSave.sqf
	Author: Dom
	Description: Wipes the current progress on the game and prevents future saving
*/
profileNamespace setVariable ["DT_serverSave",nil];
missionNamespace setVariable ["DT_stopServerSave",true];
saveProfileNamespace;

["Server wiped and disabled saving."] remoteExecCall ["DT_fnc_notify",remoteExecutedOwner];