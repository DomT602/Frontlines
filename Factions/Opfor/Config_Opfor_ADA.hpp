/*
	Faction: African Desert Army
	Author: Dom
	Requires: 3CB Factions
*/
class Opfor_Setup {
	opforSquads[] = {
		{
			"UK3CB_ADA_O_SL",
			"UK3CB_ADA_O_TL",
			"UK3CB_ADA_O_MD",
			"UK3CB_ADA_O_AA",
			"UK3CB_ADA_O_AA_ASST",
			"UK3CB_ADA_O_RIF_1",
			"UK3CB_ADA_O_AR",
			"UK3CB_ADA_O_RIF_1"
		},
		{
			"UK3CB_ADA_O_SL",
			"UK3CB_ADA_O_TL",
			"UK3CB_ADA_O_MD",
			"UK3CB_ADA_O_AT",
			"UK3CB_ADA_O_AT_ASST",
			"UK3CB_ADA_O_RIF_1",
			"UK3CB_ADA_O_AR",
			"UK3CB_ADA_O_RIF_1"
		},
		{
			"UK3CB_ADA_O_SL",
			"UK3CB_ADA_O_TL",
			"UK3CB_ADA_O_MD",
			"UK3CB_ADA_O_RIF_1",
			"UK3CB_ADA_O_MK",
			"UK3CB_ADA_O_RIF_1",
			"UK3CB_ADA_O_ENG",
			"UK3CB_ADA_O_RIF_1"
		},
		{
			"UK3CB_ADA_O_SL",
			"UK3CB_ADA_O_TL",
			"UK3CB_ADA_O_MD",
			"UK3CB_ADA_O_RIF_1",
			"UK3CB_ADA_O_MG",
			"UK3CB_ADA_O_MG_ASST",
			"UK3CB_ADA_O_ENG",
			"UK3CB_ADA_O_RIF_1"
		},
		{
			"UK3CB_ADA_O_SL",
			"UK3CB_ADA_O_TL",
			"UK3CB_ADA_O_MD",
			"UK3CB_ADA_O_RIF_1",
			"UK3CB_ADA_O_LAT",
			"UK3CB_ADA_O_RIF_1",
			"UK3CB_ADA_O_ENG",
			"UK3CB_ADA_O_DEM"
		},
		{
			"UK3CB_ADA_O_SL",
			"UK3CB_ADA_O_TL",
			"UK3CB_ADA_O_MD",
			"UK3CB_ADA_O_AR",
			"UK3CB_ADA_O_RIF_1",
			"UK3CB_ADA_O_ENG",
			"UK3CB_ADA_O_AR",
			"UK3CB_ADA_O_RIF_1"
		}
	};

	opforOfficer = "UK3CB_ADA_O_OFF";
	opforPilot = "UK3CB_ADA_O_HELI_PILOT";
	opforMortar = "UK3CB_ADA_O_2b14_82mm";
	opforStatics[] = { //HMGs, AT etc
		"UK3CB_ADA_O_Igla_AA_pod",
		"UK3CB_ADA_O_DSHKM",
		"UK3CB_ADA_O_M2_TriPod",
		"UK3CB_ADA_O_PKM_High",
		"UK3CB_ADA_O_SPG9"
	};

	opforSupplyTruck = "UK3CB_ADA_O_Ural_Repair";
	opforFuelTruck = "UK3CB_ADA_O_Ural_Fuel";
	opforAmmoTruck = "UK3CB_ADA_O_Ural_Ammo";
	opforArtilleryVehicle = "UK3CB_ADA_O_BM21";

	//if the vehicle does not belong to the faction naturally, enclose in {} and add ,true
	opforLightVehicles[] = {
		"UK3CB_ADA_O_Datsun_Pickup_PKM",
		"UK3CB_ADA_O_Hilux_GMG",
		"UK3CB_ADA_O_Hilux_Rocket_Arty",
		"UK3CB_ADA_O_Hilux_Dshkm",
		"UK3CB_ADA_O_Hilux_M2",
		"UK3CB_ADA_O_Hilux_Metis",
		"UK3CB_ADA_O_Hilux_Pkm",
		"UK3CB_ADA_O_Hilux_Rocket",
		"UK3CB_ADA_O_Hilux_Spg9",
		"UK3CB_ADA_O_LR_AGS30",
		"UK3CB_ADA_O_LR_M2",
		"UK3CB_ADA_O_LR_SPG9",
		"UK3CB_ADA_O_LR_SF_AGS30",
		"UK3CB_ADA_O_LR_SF_M2",
		"UK3CB_ADA_O_Pickup_DSHKM"
	};

	opforMediumVehicles[] = {
		"UK3CB_ADA_O_BRDM2",
		"UK3CB_ADA_O_BRDM2_ATGM",
		"UK3CB_ADA_O_BMP1",
		"UK3CB_ADA_O_BMP2",
		"UK3CB_ADA_O_BMP2K",
		"UK3CB_ADA_O_BTR60",
		"UK3CB_ADA_O_BTR70",
		"UK3CB_ADA_O_BTR80",
		"UK3CB_ADA_O_BTR80a"
	};

	opforHeavyVehicles[] = {
		"UK3CB_ADA_O_T34",
		"UK3CB_ADA_O_T55",
		"UK3CB_ADA_O_T72A",
		"UK3CB_ADA_O_T72B",
		"UK3CB_ADA_O_T72BM",
		"UK3CB_ADA_O_T72BA",
		"UK3CB_ADA_O_T72BB",
		"UK3CB_ADA_O_T72BC"
	};

	opforTroopCarriers[] = {
		"UK3CB_ADA_O_Ural_Open",
		"UK3CB_ADA_O_Ural",
		"UK3CB_ADA_O_V3S_Open",
		"UK3CB_ADA_O_V3S_Closed",
		"UK3CB_ADA_O_Pickup",
		"UK3CB_ADA_O_LR_Open",
		"UK3CB_ADA_O_Hilux_Open",
		"UK3CB_ADA_O_Datsun_Pickup",
		"UK3CB_ADA_O_M113_unarmed"
	};

	opforAAVehicles[] = {
		"UK3CB_ADA_O_MTLB_ZU23",
		"UK3CB_ADA_O_ZsuTank"
	};

	opforAttackHelicopters[] = {
		"UK3CB_ADA_O_Mi_24P",
		"UK3CB_ADA_O_Mi_24V",
		"UK3CB_ADA_O_Mi8AMTSh",
		"UK3CB_ADA_O_UH1H_M240",
		"UK3CB_ADA_O_UH1H_GUNSHIP"
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
