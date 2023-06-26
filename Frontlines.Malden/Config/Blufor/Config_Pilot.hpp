/*
	Faction: Pilot
	Author: Dom
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
		{"SMG_01_Holo_F","","","optic_Holosight_smg",{"30Rnd_45ACP_Mag_SMG_01",30},{},""},
		{},
		{},
		{"U_B_HeliPilotCoveralls",{{"ACE_elasticBandage",5},{"ACE_packingBandage",5},{"ACE_fieldDressing",5},{"ACE_EarPlugs",1},{"ACE_tourniquet",2},{"ACE_splint",2},{"ACE_morphine",1},{"ACE_CableTie",2},{"ACE_EntrenchingTool",1}}},
		{"V_PlateCarrierL_CTRG",{{"30Rnd_45ACP_Mag_SMG_01",5,30},{"SmokeShellGreen",1,1},{"SmokeShellBlue",1,1},{"SmokeShellOrange",1,1},{"Chemlight_green",1,1}}},
		{},
		"H_PilotHelmetHeli_B","",{},
		{"ItemMap","ItemGPS","TFAR_anprc152","ItemCompass","ItemWatch","NVGogglesB_blk_F"}
	};

	arsenalItems[] = {

	};
};