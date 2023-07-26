/*
	Faction: Karzeghistan Royal Guard
	Author: Dom
	Requires: 3CB Factions
*/
class Opfor_Setup {
	opforSquads[] = {
		{
			"UK3CB_KRG_O_SL",
			"UK3CB_KRG_O_TL",
			"UK3CB_KRG_O_MD",
			"UK3CB_KRG_O_AA",
			"UK3CB_KRG_O_AA_ASST",
			"UK3CB_KRG_O_RIF_2",
			"UK3CB_KRG_O_AR",
			"UK3CB_KRG_O_RIF_1"
		},
		{
			"UK3CB_KRG_O_SL",
			"UK3CB_KRG_O_TL",
			"UK3CB_KRG_O_MD",
			"UK3CB_KRG_O_AT",
			"UK3CB_KRG_O_AT_ASST",
			"UK3CB_KRG_O_RIF_2",
			"UK3CB_KRG_O_AR",
			"UK3CB_KRG_O_RIF_1"
		},
		{
			"UK3CB_KRG_O_SL",
			"UK3CB_KRG_O_TL",
			"UK3CB_KRG_O_MD",
			"UK3CB_KRG_O_RIF_1",
			"UK3CB_KRG_O_MG",
			"UK3CB_KRG_O_MG_ASST",
			"UK3CB_KRG_O_ENG",
			"UK3CB_KRG_O_RIF_1"
		},
		{
			"UK3CB_KRG_O_SL",
			"UK3CB_KRG_O_TL",
			"UK3CB_KRG_O_MD",
			"UK3CB_KRG_O_AR",
			"UK3CB_KRG_O_RIF_1",
			"UK3CB_KRG_O_ENG",
			"UK3CB_KRG_O_AR",
			"UK3CB_KRG_O_RIF_1"
		},
		{
			"UK3CB_KRG_O_SL",
			"UK3CB_KRG_O_TL",
			"UK3CB_KRG_O_MD",
			"UK3CB_KRG_O_RIF_1",
			"UK3CB_KRG_O_MK",
			"UK3CB_KRG_O_RIF_1",
			"UK3CB_KRG_O_ENG",
			"UK3CB_KRG_O_DEM"
		},
		{
			"UK3CB_KRG_O_SL",
			"UK3CB_KRG_O_TL",
			"UK3CB_KRG_O_MD",
			"UK3CB_KRG_O_RIF_1",
			"UK3CB_KRG_O_LAT",
			"UK3CB_KRG_O_RIF_1",
			"UK3CB_KRG_O_ENG",
			"UK3CB_KRG_O_DEM"
		}
	};

	opforOfficer = "UK3CB_KRG_O_OFF";
	opforPilot = "UK3CB_KRG_O_HELI_PILOT";
	opforMortar = "UK3CB_KRG_O_2b14_82mm";
	opforStatics[] = { //HMGs, AT etc
		"UK3CB_KRG_O_Stinger_AA_pod",
		"UK3CB_KRG_O_DSHKM",
		"UK3CB_KRG_O_M240_High",
		"UK3CB_KRG_O_M2_TriPod",
		"UK3CB_KRG_O_TOW_TriPod"
	};

	opforSupplyTruck = "UK3CB_KRG_O_MTVR_Repair";
	opforFuelTruck = "UK3CB_KRG_O_MTVR_Refuel";
	opforAmmoTruck = "UK3CB_KRG_O_MTVR_Reammo";
	opforArtilleryVehicle = "UK3CB_KRG_O_M109";

	//if the vehicle does not belong to the faction naturally, enclose in {} and add ,true
	opforLightVehicles[] = {
		"UK3CB_KRG_O_M1025_MK19",
		"UK3CB_KRG_O_M1025_M2",
		"UK3CB_KRG_O_M1025_TOW",
		"UK3CB_KRG_O_Pickup_DSHKM",
		"UK3CB_KRG_O_Pickup_M2"
	};

	opforMediumVehicles[] = {
		"UK3CB_KRG_O_BTR60",
		"UK3CB_KRG_O_M2A2"
	};

	opforHeavyVehicles[] = {
		"UK3CB_KRG_O_FV4201",
		"UK3CB_KRG_O_M60A1",
		"UK3CB_KRG_O_M60A3"
	};

	opforTroopCarriers[] = {
		"UK3CB_KRG_O_M939_Closed",
		"UK3CB_KRG_O_M939_Open",
		"UK3CB_KRG_O_M998_2DR",
		"UK3CB_KRG_O_MTVR_Closed",
		"UK3CB_KRG_O_MTVR_Open",
		"UK3CB_KRG_O_M113tank_unarmed"
	};

	opforAAVehicles[] = {
		"UK3CB_KRG_O_MTLB_ZU23",
		"UK3CB_KRG_O_M270_Avenger",
		"UK3CB_KRG_O_ZsuTank"
	};

	opforAttackHelicopters[] = {
		"UK3CB_KRG_O_Bell412_Armed",
		"UK3CB_KRG_O_Bell412_Armed_AT",
		"UK3CB_KRG_O_Bell412_Armed_dynamicLoadout",
		"UK3CB_KRG_O_UH1H_M240",
		"UK3CB_KRG_O_UH1H_GUNSHIP"
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
