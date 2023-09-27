/*
	File: fn_showMissionInfo.sqf
	Author: Dom
	Description: Shows a summary of the mission status
*/

private _repColour = call {
	if (DT_globalReputation > 75) exitWith {"#008000"};
	if (DT_globalReputation > 25) exitWith {"#660080"};
	if (DT_globalReputation > -25) exitWith {"#FFFFFF"};
	if (DT_globalReputation > -75) exitWith {"#D96600"};
	"#E60000"
};

private _threatColour = call {
	if (DT_threatLevel > 80) exitWith {"#E60000"};
	if (DT_threatLevel > 50) exitWith {"#D96600"};
	if (DT_threatLevel > 20) exitWith {"#D9D900"};
	"#008000"
};

private _text = format ["
<t font='PuristaBold' align='center' size='1.4'>Mission Information</t><br/><br/>
<t font='PuristaBold' align='left'>Threat Level:</t><t font='PuristaLight' align='right' color='%1'>%2</t><br/>
<t font='PuristaBold' align='left'>Global Reputation:</t><t font='PuristaLight' align='right' color='%3'>%4</t><br/>
<t font='PuristaBold' align='left'>Intel Count:</t><t font='PuristaLight' align='right'>%5</t><br/>
<t font='PuristaBold' align='left'>Mission Progress:</t><t font='PuristaLight' align='right'>%6%7</t><br/><br/>
",_threatColour,DT_threatLevel,_repColour,DT_globalReputation,DT_intelCount,floor (([] call DT_fnc_getMissionProgress) * 100),"%"];

if (missionNamespace getVariable ["DT_canGatherIntel",false]) then {
	_text = format ["%1<t font='PuristaBold' align='left' color='#008000'>Radio Tower Intel Available</t><br/>",_text];
};

if (missionNamespace getVariable ["DT_opforAAActive",false]) then {
	_text = format ["%1<t font='PuristaBold' align='left' color='#E60000'>Enemy Anti-Air Active</t><br/>",_text];
};
if (missionNamespace getVariable ["DT_opforArtilleryActive",false]) then {
	_text = format ["%1<t font='PuristaBold' align='left' color='#E60000'>Enemy Artillery Active</t><br/>",_text];
};
if (missionNamespace getVariable ["DT_opforJammerActive",false]) then {
	_text = format ["%1<t font='PuristaBold' align='left' color='#E60000'>Enemy Jammer Active</t><br/>",_text];
};

if (DT_activeSectors isNotEqualTo []) then {
	_text = format ["%1<br/><t font='PuristaBold' align='center' size='1.4'>Active Sectors</t><br/><br/>",_text];
	{
		_text = format ["<t font='PuristaLight' align='left'>%1%2<br/>",_text,_x getVariable "DT_sectorName"];
	} forEach DT_activeSectors;
};

hintSilent parseText _text;