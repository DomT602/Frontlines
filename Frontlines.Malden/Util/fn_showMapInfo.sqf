/*
	File: fn_showMapInfo.sqf
	Author: Dom
	Description: Shows sector/FOB info if the player clicks on the marker
*/
params ["_control"];

(ctrlMapMouseOver _control) params ["_type","_value"];
if (_type isEqualTo "marker") then {
	private _sectorIndex = DT_allSectors findIf {_x getVariable ["DT_sectorVariable",""] isEqualTo _value};
	if (_sectorIndex isNotEqualTo -1) exitWith {
		private _sector = DT_allSectors select _sectorIndex;
		private _sectorType = _sector getVariable "DT_sectorType";
		private _sectorOwned = _sector getVariable ["DT_sectorOwned",false];

		private _ownedColour = if (_sectorOwned) then {"#004D99"} else {"#800000"};
		private _text = format ["<t color='%1'font='PuristaBold' align='center' size='1.4'>%2</t><br/>",_ownedColour,_sector getVariable "DT_sectorName"];

		if !(_sectorOwned) then {
			private _sectorStrength = _sector getVariable ["DT_sectorStrength",1];
			(call {
				if (_sectorStrength > 0.8) exitWith {["Reinforced","#E60000"]}; //red
				if (_sectorStrength > 0.5) exitWith {["Defended","#D96600"]}; //orange
				["Weakened","#D9D900"] //yellow
			}) params ["_descriptor","_colour"];

			_text = _text + format ["<br/><t font='PuristaBold' align='left'>Strength:</t><t color='%1' font='PuristaLight' align='right'>%2</t>",_colour,_descriptor];
		};

		if (_sectorType isEqualTo "tower") then {
			(if (_sector getVariable ["DT_towerDestroyed",false]) then {["Destroyed","#E60000"]} else {["Operating","#008000"]}) params ["_descriptor","_colour"]; //green

			_text = _text + format ["<br/><t font='PuristaBold' align='left'>Status:</t><t color='%1' font='PuristaLight' align='right'>%2</t>",_colour,_descriptor];
		};

		if (_sectorType in ["town","city","factory"]) then {
			private _sectorRep = _sector getVariable ["DT_sectorReputation",1];
			(call {
				if (_sectorRep > 75) exitWith {["Loved","#008000"]};
				if (_sectorRep > 25) exitWith {["Liked","#D9D900"]};
				if (_sectorRep > -25) exitWith {["Neutral","#FFFFFF"]};
				if (_sectorRep > -75) exitWith {["Disliked","#D96600"]};
				["Hated","#E60000"]
			}) params ["_descriptor","_colour"];

			_text = _text + format ["<br/><t font='PuristaBold' align='left'>Reputation:</t><t color='%1' font='PuristaLight' align='right'>%2</t>",_colour,_descriptor];

			if (_sectorType isEqualTo "factory" && {_sectorOwned}) then {
				(switch (_sector getVariable ["DT_factoryType",-1]) do {
					case -1: {["None","#FFFFFF"]};
					case 0: {["Supplies","#008000"]};
					case 1: {["Fuel","#D9D900"]};
					case 2: {["Ammunition","#E60000"]};
				}) params ["_descriptor","_colour"];

				_text = _text + format ["<br/><t font='PuristaBold' align='left'>Producing:</t><t color='%1' font='PuristaLight' align='right'>%2</t>",_colour,_descriptor];

				(_sector getVariable ["DT_factoryResources",[0,0,0]]) params ["_supplies","_fuel","_ammo"];
				_text = _text + format ["<br/><t font='PuristaBold' align='left'>Supplies:</t><t color='#008000' font='PuristaLight' align='right'>%1</t>",_supplies];
				_text = _text + format ["<br/><t font='PuristaBold' align='left'>Fuel:</t><t color='#D9D900' font='PuristaLight' align='right'>%1</t>",_fuel];
				_text = _text + format ["<br/><t font='PuristaBold' align='left'>Ammo:</t><t color='#E60000' font='PuristaLight' align='right'>%1</t>",_ammo];
			};
		};
		hintSilent parseText _text;
	};

	private _fobIndex = DT_allFOBs findIf {_x getVariable ["DT_fobVariable",""] isEqualTo _value};
	if (_fobIndex isNotEqualTo -1) exitWith {
		private _fob = DT_allFOBs select _fobIndex;
		([_fob] call DT_fnc_getCurrentResources) params ["_supplies","_fuel","_ammo"];
		private _text = format ["<t color='004D99'font='PuristaBold' align='center' size='1.4'>%1</t><br/>",_fob getVariable "DT_fobName"];

		_text = _text + format ["<br/><t font='PuristaBold' align='left'>Supplies:</t><t color='#008000' font='PuristaLight' align='right'>%1</t>",_supplies];
		_text = _text + format ["<br/><t font='PuristaBold' align='left'>Fuel:</t><t color='#D9D900' font='PuristaLight' align='right'>%1</t>",_fuel];
		_text = _text + format ["<br/><t font='PuristaBold' align='left'>Ammo:</t><t color='#E60000' font='PuristaLight' align='right'>%1</t>",_ammo];

		_text = _text + format ["<br/><t font='PuristaBold' align='left'>Helicopters:</t><t font='PuristaLight' align='right'>%1/%2</t>",count (missionNamespace getVariable ["DT_currentHelicopters",[]]),missionNamespace getVariable ["DT_maxHelicopterCount",0]];
		_text = _text + format ["<br/><t font='PuristaBold' align='left'>Planes:</t><t font='PuristaLight' align='right'>%1/%2</t>",count (missionNamespace getVariable ["DT_currentPlanes",[]]),missionNamespace getVariable ["DT_maxPlaneCount",0]];
		hintSilent parseText _text;
	};
};