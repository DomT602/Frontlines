/*
	Faction: Engineer
	Author: Dom
*/
class engineer {
	name = $STR_B_ENGINEER_F0;
	rank = "Corporal";
	description = $STR_DT_Engineer_Description;
	traits[] = {
		{"Engineer",true},
		{"explosiveSpecialist",true}
	};
	customVariables[] = {
		{"ace_isEngineer",2,true}
	};
	icon = "a3\ui_f\data\map\vehicleicons\iconManEngineer_ca.paa";

	defaultLoadout[] = {
		{"arifle_MXC_Holo_pointer_F","","acc_pointer_IR","optic_Holosight",{"30Rnd_65x39_caseless_mag",30},{},""},
		{},
		{"hgun_P07_F","","","",{"16Rnd_9x21_Mag",16},{},""},
		{"U_B_CTRG_3",{{"ACE_elasticBandage",5},{"ACE_packingBandage",5},{"ACE_fieldDressing",5},{"ACE_EarPlugs",1},{"ACE_tourniquet",2},{"ACE_splint",2},{"ACE_morphine",1},{"ACE_CableTie",2},{"ACE_EntrenchingTool",1}}},
		{"V_PlateCarrierL_CTRG",{{"30Rnd_65x39_caseless_mag",5,30},{"16Rnd_9x21_Mag",2,16},{"HandGrenade",2,1},{"SmokeShell",1,1},{"SmokeShellGreen",1,1},{"SmokeShellBlue",1,1},{"SmokeShellOrange",1,1},{"Chemlight_green",1,1}}},
		{"B_Kitbag_cbr",{{"ToolKit",1},{"ACE_DefusalKit",1},{"ACE_M26_Clacker",1},{"MineDetector",1},{"DemoCharge_Remote_Mag",3,1},{"ACE_wirecutter",1}}},
		"H_HelmetB_desert","G_Tactical_Clear",{},
		{"ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","NVGogglesB_blk_F"}
	};

	arsenalItems[] = {

	};
};