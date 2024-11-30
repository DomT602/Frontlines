/*
	Faction: Sahrani Liberation Army
	Author: Dom
	Requires: CUP
*/
class Opfor_Setup {
	opforSquads[] = {
		{
			"CUP_O_SLA_Soldier_SL_desert", 
			"CUP_O_SLA_Soldier_MG_desert", 
			"CUP_O_SLA_Soldier_AMG_desert", 
			"CUP_O_SLA_Soldier_AT_desert", 
			"CUP_O_SLA_Soldier_desert", 
			"CUP_O_SLA_Medic_desert", 
			"CUP_O_SLA_Soldier_GL_desert"
		},
		{
			"CUP_O_SLA_Soldier_SL_desert",
			"CUP_O_SLA_Soldier_HAT_desert", 
			"CUP_O_SLA_Soldier_AT_desert",
			"CUP_O_SLA_Soldier_AT_desert",
			"CUP_O_SLA_Soldier_desert",	
			"CUP_O_SLA_Medic_desert"
		},
		{
			"CUP_O_SLA_Soldier_SL_desert",
			"CUP_O_SLA_Soldier_AA_desert",
			"CUP_O_SLA_Soldier_AA_desert",
			"CUP_O_SLA_Soldier_LAT_desert",
			"CUP_O_SLA_Soldier_desert", 
			"CUP_O_SLA_Soldier_desert"
		},
		{
			"CUP_O_SLA_Soldier_SL_desert", 
			"CUP_O_SLA_Soldier_MG_desert", 
			"CUP_O_SLA_Soldier_AMG_desert", 
			"CUP_O_SLA_Soldier_GL_desert", 
			"CUP_O_SLA_Soldier_GL_desert", 
			"CUP_O_SLA_Medic_desert", 
			"CUP_O_SLA_Soldier_desert"
		},
		{
			"CUP_O_SLA_Soldier_SL_desert", 
			"CUP_O_SLA_Soldier_MG_desert", 
			"CUP_O_SLA_Soldier_AMG_desert", 
			"CUP_O_SLA_Medic_desert", 
			"CUP_O_SLA_Soldier_desert",
			"CUP_O_SLA_Soldier_desert"
		}
	};

	opforOfficer = "CUP_O_SLA_Commander_desert";
	opforPilot = "CUP_O_SLA_Pilot";
	opforMortar = "CUP_O_2b14_82mm_SLA";
	opforStatics[] = { //HMGs, AT etc
		"CUP_O_Igla_AA_pod_SLA",
		"CUP_O_DSHKM_MiniTripod_SLA", 
		"CUP_O_DSHKM_SLA", 
		"CUP_O_D30_SLA"
	};

	opforSupplyTruck = "CUP_O_Ural_Repair_SLA";
	opforFuelTruck = "CUP_O_Ural_Refuel_SLA";
	opforAmmoTruck = "CUP_O_Ural_Reammo_SLA";
	opforArtilleryVehicle = "CUP_O_BM21_SLA";

	//if the vehicle does not belong to the faction naturally, enclose in {} and add ,true
	opforLightVehicles[] = {
		"CUP_O_UAZ_MG_SLA",
		"CUP_O_UAZ_AGS30_SLA",
		"CUP_O_UAZ_METIS_SLA",
		"CUP_O_UAZ_SPG9_SLA",
		"CUP_O_UAZ_AA_SLA",
		"CUP_O_Tigr_233014_PK_SLA"
	};

	opforMediumVehicles[] = {
		"CUP_O_BRDM2_SLA",
		"CUP_O_BRDM2_ATGM_SLA",
		"CUP_O_BTR60_SLA",
		"CUP_O_BTR80_SLA",
		"CUP_O_BTR80A_SLA"
	};

	opforHeavyVehicles[] = {
		"CUP_O_BMP2_SLA", 
		"CUP_O_T72_SLA", 
		"CUP_O_T55_SLA"
	};

	opforTroopCarriers[] = {
		"CUP_O_Ural_SLA",
		"CUP_O_Ural_Open_SLA",
		"CUP_O_Tigr_233011_SLA", 
		"CUP_O_MTLB_pk_SLA"
	};

	opforAAVehicles[] = {
		"CUP_O_Ural_ZU23_SLA",
		"CUP_O_ZSU23_SLA",
		"CUP_O_ZSU23_Afghan_SLA"
	};

	opforAttackHelicopters[] = {
		"CUP_O_Ka50_DL_SLA", 
		"CUP_O_Mi24_D_Dynamic_SLA", 
		"CUP_O_Mi8_SLA_2",
		"CUP_O_UH1H_gunship_SLA"
	};

	opforMines[] = {
		"ATMine",
		"APERSTripMine",
		"APERSMine"
	};
};
