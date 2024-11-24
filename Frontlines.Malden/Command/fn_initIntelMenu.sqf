/*
	File: fn_initIntelMenu.sqf
	Author: Dom
	Description: Opens and populates the support menu
*/

private _display = createDialog ["DT_intelMenu",true];
private _tree = _display displayCtrl 1500;
private _repLoss = getNumber (missionConfigFile >> "Settings" >> "killedCivRepLoss");
private _missions = [
	["FOB Hunt",25,"","[] remoteExecCall [""DT_fnc_fobHunt"",2]","We have recieved some intel that a FOB is located inside the red zone on your map.<br/>
Destroying this FOB would disrupt the enemies supply lines and command and control effectiveness.<br/>
You will need to locate and destroy the FOB's assets (laptops, supply trucks and containers) to complete this mission.<br/><br/>
<t color='#00FF00'>Reward: -40 Opfor Threat</t>"],
	["Raid Enemy Depot",15,"","[] remoteExecCall [""DT_fnc_raidSupplyDepot"",2]","We have recieved some intel that a supply depot has been setup behind enemy lines.<br/>
This depot could provide us plenty of resources to continue our efforts while disrupting the enemy and preventing them from fielding heavy vehicles for a time.<br/>
Bring the trucks back to the FOB to secure the resources.<br/><br/>
<t color='#00FF00'>Reward: +400 Resources per truck, -5 Opfor Threat, Opfor Heavy Vehicles Temporarily Disabled</t>"],
	["Secure Downed UAV",10,"","[] remoteExecCall [""DT_fnc_captureUAV"",2]","We have recieved some intel that an enemy UAV has crashed inside the red zone on your map.<br/>
Capturing this UAV would provide us with intel on the enemies movements and plans.<br/>
The enemy are looking to secure it, and will be done within approximately 20 minutes, go there and secure it before they can!<br/><br/>
<t color='#00FF00'>Reward: +30 Intel<br/></t>"],
	["Setup Listening Post",0,"([['town','city','factory','military']] call DT_fnc_getSectorsByType) isNotEqualTo []","[""init""] remoteExecCall [""DT_fnc_listeningPost"",2]","We are able to setup a Listening Post nearby to our frontlines to gain more intel.<br/>
Setting this post up would provide us a continuous stream of intel for 30 minutes.<br/>
The post can be found in the Logistics section of the Build Menu.<br/>
Once active, it is likely to be attacked by the enemy, ensure it is protected.<br/><br/>
<t color='#00FF00'>Reward: +2 Intel per minute active<br/></t>
<t color='#ffa000'>Failure: If destroyed by enemy, +5 Opfor Threat</t>"],
	["Clear UXOs",3,"([['town','city','factory'],true] call DT_fnc_getSectorsByType) isNotEqualTo []","[] remoteExecCall [""DT_fnc_clearUXOs"",2]","The local population has requested our help to clear an area of UXOs that were left behind.<br/>
The UXOs will most likely be left near roads so keep an eye out as you travel in.<br/>
Completing this task will improve our relations with the locals.<br/><br/>
<t color='#00FF00'>Reward: +30 Civilian Reputation in the sector</t>"],
	["Humanitarian Relief",0,"([['town','city','factory'],true] call DT_fnc_getSectorsByType) isNotEqualTo []","[""init""] remoteExecCall [""DT_fnc_humanitarianRelief"",2]","We have recieved a request from a local village elder for some Humanitarian Aid.<br/>
They have requested you bring as many relief trucks as you can from your FOB.<br/>
These trucks can be found in the Logistics section of the Build Menu.<br/>
The enemy will be looking to intercept these trucks, so be careful.<br/><br/>
<t color='#00FF00'>Reward: +20 Civilian Reputation per truck in the sector</t>"],
	["Provide Medical Aid",0,"([['town','city','factory'],true] call DT_fnc_getSectorsByType) isNotEqualTo []","[] remoteExecCall [""DT_fnc_provideAid"",2]",format["A local town has been hit hard by the conflict and has taken casualties.<br/>
They have requested our help treating these people.<br/>
A medic will be required for this mission.<br/>
You need to head to the marked location ASAP, these people are needing immediate assistance.<br/><br/>
<t color='#00FF00'>Reward: %1 Civilian Reputation per civilian saved in the sector<br/></t>
<t color='#ffa000'>Failure: %2 Civilian Reputation per civilian lost in the sector</t>",abs(_repLoss * 2),_repLoss]]
];

private _intelActions = [
	["Mine Scanner",ceil ((count allMines) / 15),"","[] call DT_fnc_mineScanner","Utilise some of our intelligence to detect all mines within 1000m of any player.<br/>The intel cost of this action increases with the number of mines placed."],
	["Opfor Scanner",ceil ((count (groups east)) / 2),"","[] remoteExecCall ['DT_fnc_opforScanner',2]","Utilise some of our intelligence to detect all opfor groups and mark them on the map for 5 minutes.<br/>The intel cost of this action increases with the number of opfor units alive."]
];

private _titles = ["Missions","Intelligence"];
{
	private _firstIndex = _tree tvAdd [[],_titles select _forEachIndex];
	{
		_x params ["_title","_intelRequired","_conditions","_code","_description"];
		private _index = _tree tvAdd [[_firstIndex],_title];
		_tree tvSetValue [[_firstIndex,_index],_intelRequired];
		_tree tvSetData [[_firstIndex,_index],str([_conditions,_description,_code])];

		private _colour = [1,0,0,1];
		if (DT_intelCount >= _intelRequired && {[_conditions] call DT_fnc_conditionChecker}) then {
			_colour = [0,1,0,1];
		};
		_tree tvSetColor [[_firstIndex,_index],_colour];
	} forEach _x;
} forEach [_missions,_intelActions];

_tree tvSetCurSel [0];