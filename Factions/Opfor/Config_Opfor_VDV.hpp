/*
	Faction: VDV (Russian Airborne Forces)
	Author: Dom
	Requires: None
*/
class Opfor_Setup {
	opforSquads[] = {
		{
			"rhs_vdv_sergeant",
			"rhs_vdv_junior_sergeant",
			"rhs_vdv_junior_sergeant",
			"rhs_vdv_medic",
			"rhs_vdv_engineer",
			"rhs_vdv_rifleman",
			"rhs_vdv_marksman",
			"rhs_vdv_LAT",
			"rhs_vdv_machinegunner"
		},
		{
			"rhs_vdv_sergeant",
			"rhs_vdv_junior_sergeant",
			"rhs_vdv_junior_sergeant",
			"rhs_vdv_medic",
			"rhs_vdv_engineer",
			"rhs_vdv_at",
			"rhs_vdv_at",
			"rhs_vdv_LAT",
			"rhs_vdv_machinegunner"
		},
		{
			"rhs_vdv_sergeant",
			"rhs_vdv_junior_sergeant",
			"rhs_vdv_junior_sergeant",
			"rhs_vdv_medic",
			"rhs_vdv_engineer",
			"rhs_vdv_LAT",
			"rhs_vdv_aa",
			"rhs_vdv_aa",
			"rhs_vdv_machinegunner"
		},
		{
			"rhs_vdv_sergeant",
			"rhs_vdv_junior_sergeant",
			"rhs_vdv_junior_sergeant",
			"rhs_vdv_medic",
			"rhs_vdv_engineer",
			"rhs_vdv_rifleman",
			"rhs_vdv_marksman",
			"rhs_vdv_aa",
			"rhs_vdv_at",
			"rhs_vdv_machinegunner"
		}
	};

	opforOfficer = "rhs_vdv_officer";
	opforPilot = "rhs_pilot_transport_heli";
	opforMortar = "rhs_2b14_82mm_vdv";
	opforStatics[] = { //HMGs, AT etc
		"rhs_Metis_9k115_2_vdv",
		"rhs_Kornet_9M113_2_vdv",
		"rhs_Igla_AA_pod_vdv",
		"rhs_AGS30_TriPod_VDV",
		"rhs_KORD_VDV",
		"rhs_KORD_high_VDV",
		"RHS_NSV_TriPod_VDV",
		"rhs_SPG9M_VDV",
		"RHS_ZU23_VDV"
	};

	opforSupplyTruck = "RHS_Ural_Repair_VDV_01";
	opforFuelTruck = "RHS_Ural_Fuel_VDV_01";
	opforAmmoTruck = "rhs_gaz66_ammo_vdv";
	opforArtilleryVehicle = "RHS_BM21_VDV_01";

	//if the vehicle does not belong to the faction naturally, enclose in {} and add ,true
	opforLightVehicles[] = {
		"rhs_tigr_sts_vdv",
		"rhs_btr60_vdv",
		"rhsgref_BRDM2_vdv",
		"rhsgref_BRDM2_ATGM_vdv"
	};

	opforMediumVehicles[] = {
		"rhs_bmd4ma_vdv",
		"rhs_bmd2m"
	};

	opforHeavyVehicles[] = {
		"rhs_sprut_vdv",
		"rhs_t72ba_tv"
	};

	opforTroopCarriers[] = {
		"rhs_tigr_vdv",
		"rhs_tigr_sts_vdv",
		"rhs_btr60_vdv",
		"RHS_Ural_VDV_01",
		"rhs_gaz66_vdv"
	};

	opforAAVehicles[] = {
		"RHS_Ural_Zu23_VDV_01",
	};

	opforAttackHelicopters[] = {
		"RHS_Mi24P_vdv",
		"RHS_mi24V_vdv",
		"RHS_Mi8MTV3_vdv"

	};

	opforMines[] = {
		"ATMine",
		"APERSTripMine",
		"APERSMine",
		"APERSBoundingMine",
		"IEDUrbanBig_F",
		"IEDLandBig_F",
		"IEDUrbanSmall_F",
		"IEDLandSmall_F"
	};
};
