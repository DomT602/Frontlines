/*
	Faction: Commander
	Author: Dom
*/
class commander {
	name = "Commander";
	rank = "Lieutenant";
	description = "The Vehicle Commander is in charge of his crew.";
	traits[] = {

	};
	customVariables[] = {

	};
	icon = "a3\ui_f\data\map\vehicleicons\iconManLeader_ca.paa";

	defaultLoadout[] = {
		{"arifle_MXC_F","","","",{"30Rnd_65x39_caseless_mag",30},{},""},
		{},
		{"hgun_P07_F","","","",{"16Rnd_9x21_Mag",16},{},""},
		{"U_B_CTRG_3",{{"ACE_elasticBandage",5},{"ACE_packingBandage",5},{"ACE_fieldDressing",5},{"ACE_EarPlugs",1},{"ACE_tourniquet",2},{"ACE_splint",2},{"ACE_morphine",1},{"ACE_CableTie",2},{"ACE_EntrenchingTool",1}}},
		{"V_PlateCarrierL_CTRG",{{"30Rnd_65x39_caseless_mag",5,30},{"16Rnd_9x21_Mag",2,16},{"HandGrenade",2,1},{"SmokeShell",1,1},{"SmokeShellGreen",1,1},{"Chemlight_green",1,1}}},
		{},
		"H_HelmetCrew_B","",{},
		{"ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","NVGogglesB_blk_F"}
	};
	
	arsenalItems[] = {
		
	};
};