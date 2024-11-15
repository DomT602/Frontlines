/*
	Faction: AAF
	Author: TacticalError, Rickard
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
		{"rhs_weap_vhsd2_ct15x","","","",{"rhsgref_30rnd_556x45_vhs2",30},{},""},{},{"rhsusf_weap_m9","","","",{"rhsusf_mag_15Rnd_9x19_FMJ",15},{},""},{"UK3CB_AAF_B_U_CombatUniform_DIGI_GRN",{{"ACE_adenosine",1},{"ACE_packingBandage",10},{"ACE_EarPlugs",1},{"ACE_epinephrine",1},{"ACE_MapTools",1},{"ACE_morphine",1},{"ACE_splint",1},{"ACE_tourniquet",2}}},{"UK3CB_AAF_B_V_RFL_Vest_DIGI_GRN",{{"ACE_EntrenchingTool",1},{"rhsgref_30rnd_556x45_vhs2",10,30},{"rhsusf_mag_15Rnd_9x19_FMJ",2,15},{"rhs_mag_m67",2,1},{"I_IR_Grenade",1,1}}},{"B_AssaultPack_dgtl",{{"ToolKit",1}}},"UK3CB_AAF_B_H_PASGT_RHINO_DIGI_GRN","",{"Binocular","","","",{},{},""},{"ItemMap","","TFAR_anprc152","ItemCompass","ItemWatch",""}
	};

	arsenalItems[] = {

	};
};