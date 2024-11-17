/*
	Faction: USSOCOM
	Author: SiegeSix
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
		{"rhs_weap_m16a4_carryhandle","","","rhsusf_acc_ACOG3",{"rhs_mag_30Rnd_556x45_M855A1_PMAG",30},{},""},
		{},
		{},
		{"U_B_HeliPilotCoveralls",{{"ACE_elasticBandage",5},{"ACE_packingBandage",5},{"ACE_fieldDressing",5},{"ACE_EarPlugs",1},{"ACE_tourniquet",2},{"ACE_splint",2},{"ACE_morphine",1},{"ACE_CableTie",2}}},
		{"rhsusf_mbav_light",{{"rhs_mag_30Rnd_556x45_M855A1_PMAG",6,30},{"rhs_mag_30Rnd_556x45_M855A1_PMAG_Tracer_Red",2,30},{"rhs_mag_m67",2,1},{"rhs_mag_an_m8hc",1,1}}},
		{"TFAR_rt1523g_green",{}},
		"rhsusf_hgu56p_black","",
		{"ACE_Vector","","","",{},{},""},
		{"ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","ACE_NVG_Wide"}
	};

	arsenalItems[] = {

	};
};