/*
	Faction: Squad Leader
	Author: Dom
*/
class squadlead {
	name = $STR_B_SOLDIER_SL_F0;
	rank = "Lieutenant";
	description = $STR_DT_SqLe_Description;
	traits[] = {

	};
	customVariables[] = {

	};
	icon = "a3\ui_f\data\map\vehicleicons\iconManLeader_ca.paa";

	defaultLoadout[] = {
		{"arifle_MX_Hamr_pointer_F","","acc_pointer_IR","optic_Hamr",{"30Rnd_65x39_caseless_mag",30},{},""},
		{},
		{"hgun_P07_F","","","",{"16Rnd_9x21_Mag",16},{},""},
		{"U_B_CTRG_3",{{"ACE_elasticBandage",5},{"ACE_packingBandage",5},{"ACE_fieldDressing",5},{"ACE_EarPlugs",1},{"ACE_tourniquet",2},{"ACE_splint",2},{"ACE_morphine",1},{"ACE_CableTie",2},{"ACE_EntrenchingTool",1}}},
		{"V_PlateCarrierH_CTRG",{{"30Rnd_65x39_caseless_mag",5,30},{"30Rnd_65x39_caseless_mag_Tracer",2,30},{"16Rnd_9x21_Mag",2,16},{"HandGrenade",2,1},{"B_IR_Grenade",2,1},{"SmokeShell",1,1},{"SmokeShellGreen",1,1},{"SmokeShellBlue",1,1},{"SmokeShellOrange",1,1},{"Chemlight_green",1,1}}},
		{"TFAR_rt1523g_green",{}},
		"H_HelmetB_desert","",{"Binocular","","","",{},{},""},
		{"ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","NVGogglesB_blk_F"}
	};

	arsenalItems[] = {
		
	};
};