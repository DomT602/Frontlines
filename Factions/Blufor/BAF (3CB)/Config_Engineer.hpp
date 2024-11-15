/*
	Faction: BAF
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
		{"UK3CB_BAF_L85A2_RIS_G","","","UK3CB_BAF_SpecterLDS",{"UK3CB_BAF_556_30Rnd",30},{},"UK3CB_underbarrel_acc_grippod"},
		{},
		{},
		{"UK3CB_BAF_U_CombatUniform_MTP_ShortSleeve",{{"ACE_elasticBandage",5},{"ACE_packingBandage",5},{"ACE_fieldDressing",5},{"ACE_EarPlugs",1},{"ACE_tourniquet",2},{"ACE_splint",2},{"ACE_morphine",1},{"ACE_CableTie",2}}},
		{"UK3CB_BAF_V_Osprey_Rifleman_D",{{"ACE_EntrenchingTool",1},{"UK3CB_BAF_556_30Rnd",6,30},{"UK3CB_BAF_556_30Rnd_T",2,30},{"rhs_mag_m67",2,1},{"rhs_mag_an_m8hc",1,1}}},
		{"B_Kitbag_cbr",{{"ToolKit",1},{"ACE_DefusalKit",1},{"ACE_M26_Clacker",1},{"MineDetector",1},{"rhsusf_m112x4_mag",3,1},{"ACE_wirecutter",1}}},
		"UK3CB_BAF_H_Mk7_Camo_F","",
		{"ACE_Vector","","","",{},{},""},
		{"ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","UK3CB_BAF_HMNVS"}
	};

	arsenalItems[] = {

	};
};