/*
	Faction: BAF
	Author: Dom
*/
class pilot {
	name = $STR_B_PILOT_F0;
	rank = "Lieutenant";
	description = $STR_DT_Pilot_Description;
	traits[] = {

	};
	customVariables[] = {
		{"ace_isEngineer",1,true},
		{"ACE_GForceCoef",0.55,false}
	};
	icon = "a3\ui_f\data\map\vehicleicons\iconManOfficer_ca.paa";

	defaultLoadout[] = {
		{"UK3CB_BAF_L22A2_SUSAT","","","UK3CB_BAF_SUSAT",{"UK3CB_BAF_556_30Rnd",30},{},""},
		{},
		{"UK3CB_BAF_L131A1","","","",{"UK3CB_BAF_9_17Rnd",17},{},""},
		{"UK3CB_BAF_U_HeliPilotCoveralls_Army",{{"ACE_EarPlugs",1},{"ACE_quikclot",2},{"ACE_elasticBandage",1},{"UK3CB_BAF_9_17Rnd",1,17},{"Chemlight_green",1,1},{"Chemlight_blue",1,1},{"UK3CB_BAF_SmokeShellBlue",1,1},{"UK3CB_BAF_SmokeShellRed",1,1},{"UK3CB_BAF_SmokeShell",2,1},{"HandGrenade",1,1}}},
		{"UK3CB_BAF_V_Pilot_A",{{"ACE_elasticBandage",2},{"ACE_packingBandage",2},{"ACE_tourniquet",2},{"ACE_morphine",2},{"ACE_epinephrine",3},{"ACE_microDAGR",1},{"ACE_MapTools",1},{"ACE_Flashlight_XL50",1},{"ACE_IR_Strobe_Item",1},{"HandGrenade",1,1},{"UK3CB_BAF_556_30Rnd",3,30},{"UK3CB_BAF_556_30Rnd_T",1,30}}},
		{},
		"UK3CB_BAF_H_PilotHelmetHeli_A","",
		{"ACE_Vector","","","",{},{},""},
		{"ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch",""}
	};

	arsenalItems[] = {

	};
};