/*
	File: fn_showMissionInfo.sqf
	Author: Dom
	Description: Shows a summary of the mission status
*/

private _text = format ["
<t font='PuristaBold' align='center' size='1.4'>Mission Information</t><br/><br/>
<t font='PuristaBold' align='left'>Threat Level:</t><t font='PuristaLight' align='right'>%1</t><br/>
<t font='PuristaBold' align='left'>Global Reputation:</t><t font='PuristaLight' align='right'>%2</t><br/>
<t font='PuristaBold' align='left'>Intel Count:</t><t font='PuristaLight' align='right'>%3</t><br/>
<t font='PuristaBold' align='left'>Mission Progress:</t><t font='PuristaLight' align='right'>%4%5</t><br/>
",DT_threatLevel,DT_globalReputation,DT_intelCount,floor (([] call DT_fnc_getMissionProgress) * 100),"%"];

if (DT_activeSectors isNotEqualTo []) then {
	_text = format ["%1<br/><t font='PuristaBold' align='center' size='1.4'>Active Sectors</t><br/><br/>",_text];
	{
		_text = format ["<t font='PuristaLight' align='left'>%1%2<br/>",_text,_x getVariable "DT_sectorName"];
	} forEach DT_activeSectors;
};

hintSilent parseText _text;