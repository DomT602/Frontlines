/*
	Faction: USMCd
	Author: Reidy
*/
class uavop {
	name = $STR_A3_B_SOLDIER_UAV_F0;
	rank = "Sergeant";
	description = $STR_DT_UAVOp_Description;
	traits[] = {
		{"UAVHacker",true}
	};
	customVariables[] = {

	};
	icon = "a3\ui_f\data\map\vehicleicons\iconMan_ca.paa";

	defaultLoadout[] = {
		{"rhs_weap_m16a4_carryhandle","","","rhsusf_acc_ACOG3",{"rhs_mag_30Rnd_556x45_M855A1_PMAG",30},{},""},
		{},
		{},
		{"rhs_uniform_FROG01_wd",{{"ACE_elasticBandage",5},{"ACE_packingBandage",5},{"ACE_fieldDressing",5},{"ACE_EarPlugs",1},{"ACE_tourniquet",2},{"ACE_splint",2},{"ACE_morphine",1},{"ACE_CableTie",2}}},
		{"rhsusf_spc_rifleman",{{"ACE_EntrenchingTool",1},{"rhs_mag_30Rnd_556x45_M855A1_PMAG",6,30},{"rhs_mag_30Rnd_556x45_M855A1_PMAG_Tracer_Red",2,30},{"rhs_mag_m67",2,1},{"rhs_mag_an_m8hc",1,1}}},
		{},
		"rhsusf_lwh_helmet_marpatwd_headset","",
		{"ACE_Vector","","","",{},{},""},
		{"ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","rhsusf_ANPVS_15"}
	};

	arsenalItems[] = {

	};
};