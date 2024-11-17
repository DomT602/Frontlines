/*
	Faction: USSOCOM
	Author: SiegeSix
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
		{"rhs_weap_m4a1_blockII_KAC_d","rhsusf_acc_nt4_tan","rhsusf_acc_anpeq15_bk","rhsusf_acc_ACOG_RMR",{"ACE_30Rnd_556x45_Stanag_M995_AP_mag",30},{},"rhsusf_acc_tacsac_blk"},
		{},
		{},
		{"rhs_uniform_g3_mc",{{"ACE_fieldDressing",5},{"ACE_elasticBandage",5},{"ACE_packingBandage",5},{"ACE_quikclot",5},{"ACE_CableTie",2},{"ACE_epinephrine",2},{"ACE_EarPlugs",1},{"ACE_Flashlight_XL50",1},{"ACE_morphine",2},{"ACE_IR_Strobe_Item",2},{"ACE_tourniquet",2},{"ACE_splint",2}}},
		{"rhsusf_mbav_rifleman",{{"SmokeShell",2,1},{"rhs_mag_m67",2,1},{"ACE_30Rnd_556x45_Stanag_M995_AP_mag",10,30}}},
		{"B_Kitbag_cbr",{{"ToolKit",1},{"ACE_DefusalKit",1},{"ACE_M26_Clacker",1},{"MineDetector",1},{"rhsusf_m112x4_mag",3,1},{"ACE_wirecutter",1}}},
		"rhsusf_opscore_mc_cover_pelt","",
		{"ACE_Vector","","","",{},{},""},
		{"ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","ACE_NVG_Wide"}
	};

	arsenalItems[] = {

	};
};