/*
	Faction: Officer
	Author: Dom
*/
class officer {
	name = $STR_B_OFFICER_F0;
	rank = "Captain";
	description = $STR_DT_Officer_Description;
	traits[] = {

	};
	customVariables[] = {

	};
	icon = "a3\ui_f\data\map\vehicleicons\iconManCommander_ca.paa";

	defaultLoadout[] = {
		{"arifle_MXC_ACO_F","","","optic_Aco",{"30Rnd_65x39_caseless_mag",30},{},""},
		{},
		{"hgun_Pistol_heavy_01_MRD_F","","","optic_MRD",{"11Rnd_45ACP_Mag",11},{},""},
		{"U_B_CTRG_3",{{"ACE_elasticBandage",5},{"ACE_packingBandage",5},{"ACE_fieldDressing",5},{"ACE_EarPlugs",1},{"ACE_tourniquet",2},{"ACE_splint",2},{"ACE_morphine",1},{"ACE_CableTie",2},{"ACE_EntrenchingTool",1}}},
		{"V_PlateCarrierL_CTRG",{{"30Rnd_65x39_caseless_mag",5,30},{"11Rnd_45ACP_Mag",2,11},{"SmokeShell",1,1},{"SmokeShellGreen",1,1},{"Chemlight_green",1,1}}},
		{},
		"H_Beret_Colonel","",{},
		{"ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch",""}
	};

	arsenalItems[] = {
		"H_Beret_Colonel"
	};
};