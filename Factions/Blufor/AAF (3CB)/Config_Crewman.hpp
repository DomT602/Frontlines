/*
	Faction: AAF
	Author: TacticalError, Rickard
*/
class crewman {
	name = $STR_B_CREW_F0;
	rank = "Private";
	description = $STR_DT_Crewman_Description;
	traits[] = {
		{"Engineer",true}
	};
	customVariables[] = {
		{"ace_isEngineer",1,true}
	};
	icon = "a3\ui_f\data\map\vehicleicons\iconMan_ca.paa";

	defaultLoadout[] = {
		{"rhs_weap_vhsk2","","","",{"rhsgref_30rnd_556x45_vhs2",30},{},""},{},{},{"UK3CB_AAF_B_U_CombatUniform_DIGI_GRN",{{"ACE_adenosine",1},{"ACE_packingBandage",10},{"ACE_EarPlugs",1},{"ACE_epinephrine",1},{"ACE_MapTools",1},{"ACE_morphine",1},{"ACE_splint",1},{"ACE_tourniquet",2}}},{"UK3CB_AAF_B_V_CREW_Vest_DIGI_GRN",{{"rhsgref_30rnd_556x45_vhs2",4,30},{"rhs_mag_m67",1,1}}},{"B_AssaultPack_dgtl",{{"ToolKit",1}}},"H_HelmetCrew_I","",{"Binocular","","","",{},{},""},{"ItemMap","","TFAR_anprc152","ItemCompass","ItemWatch",""}
	};

	arsenalItems[] = {
		
	};
};