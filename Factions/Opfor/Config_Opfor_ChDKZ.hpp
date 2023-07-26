/*
	Faction: Chernorussian Movement of the Red Star
	Author: Dom
	Requires: 3CB Factions
*/
class Opfor_Setup {
	opforSquads[] = {
		{
			"UK3CB_CHD_O_SL",
			"UK3CB_CHD_O_TL",
			"UK3CB_CHD_O_MD",
			"UK3CB_CHD_O_AA",
			"UK3CB_CHD_O_AA_ASST",
			"UK3CB_CHD_O_RIF_2",
			"UK3CB_CHD_O_AR",
			"UK3CB_CHD_O_RIF_1"
		},
		{
			"UK3CB_CHD_O_SL",
			"UK3CB_CHD_O_TL",
			"UK3CB_CHD_O_MD",
			"UK3CB_CHD_O_AT",
			"UK3CB_CHD_O_AT_ASST",
			"UK3CB_CHD_O_MK",
			"UK3CB_CHD_O_AR",
			"UK3CB_CHD_O_RIF_1"
		},
		{
			"UK3CB_CHD_O_SL",
			"UK3CB_CHD_O_TL",
			"UK3CB_CHD_O_MD",
			"UK3CB_CHD_O_MK",
			"UK3CB_CHD_O_MG",
			"UK3CB_CHD_O_MG_ASST",
			"UK3CB_CHD_O_ENG",
			"UK3CB_CHD_O_RIF_1"
		},
		{
			"UK3CB_CHD_O_SL",
			"UK3CB_CHD_O_TL",
			"UK3CB_CHD_O_MD",
			"UK3CB_CHD_O_MK",
			"UK3CB_CHD_O_LAT",
			"UK3CB_CHD_O_RIF_1",
			"UK3CB_CHD_O_ENG",
			"UK3CB_CHD_O_DEM"
		},
		{
			"UK3CB_CHD_O_SL",
			"UK3CB_CHD_O_TL",
			"UK3CB_CHD_O_MD",
			"UK3CB_CHD_O_AR",
			"UK3CB_CHD_O_RIF_1",
			"UK3CB_CHD_O_ENG",
			"UK3CB_CHD_O_RIF_2",
			"UK3CB_CHD_O_MK"
		}
	};

	opforOfficer = "UK3CB_CHD_O_OFF";
	opforPilot = "UK3CB_CHD_O_HELI_PILOT";
	opforMortar = "UK3CB_CHD_O_2b14_82mm";
	opforStatics[] = { //HMGs, AT etc
		"UK3CB_CHD_O_Igla_AA_pod",
		"UK3CB_CHD_O_DSHKM",
		"UK3CB_CHD_O_KORD_high",
		"UK3CB_CHD_O_PKM_High",
		"UK3CB_CHD_O_SPG9"
	};

	opforSupplyTruck = "UK3CB_CHD_O_Ural_Repair";
	opforFuelTruck = "UK3CB_CHD_O_Ural_Fuel";
	opforAmmoTruck = "UK3CB_CHD_O_Ural_Ammo";
	opforArtilleryVehicle = "UK3CB_CHD_O_2S1";

	//if the vehicle does not belong to the faction naturally, enclose in {} and add ,true
	opforLightVehicles[] = {
		"UK3CB_CHD_O_Datsun_Pkm",
		"UK3CB_CHD_O_Hilux_GMG",
		"UK3CB_CHD_O_Hilux_Rocket_Arty",
		"UK3CB_CHD_O_Hilux_Dshkm",
		"UK3CB_CHD_O_Hilux_M2",
		"UK3CB_CHD_O_Hilux_Pkm",
		"UK3CB_CHD_O_Hilux_Rocket",
		"UK3CB_CHD_O_Hilux_Spg9",
		"UK3CB_CHD_O_LR_AGS30",
		"UK3CB_CHD_O_LR_M2",
		"UK3CB_CHD_O_LR_SPG9",
		"UK3CB_CHD_O_LR_SF_AGS30",
		"UK3CB_CHD_O_LR_SF_M2",
		"UK3CB_CHD_O_Offroad_M2",
		"UK3CB_CHD_O_Pickup_DSHKM",
		"UK3CB_CHD_O_Pickup_M2",
		"UK3CB_CHD_O_UAZ_AGS30",
		"UK3CB_CHD_O_UAZ_MG",
		"UK3CB_CHD_O_UAZ_SPG9"
	};

	opforMediumVehicles[] = {
		"UK3CB_CHD_O_BRDM2",
		"UK3CB_CHD_O_BRDM2_ATGM",
		"UK3CB_CHD_O_BRDM2_HQ",
		"UK3CB_CHD_O_BMD1",
		"UK3CB_CHD_O_BMD1K",
		"UK3CB_CHD_O_BMD1P",
		"UK3CB_CHD_O_BMD1PK",
		"UK3CB_CHD_O_BMD1R",
		"UK3CB_CHD_O_BMD2",
		"UK3CB_CHD_O_BMP1",
		"UK3CB_CHD_O_BMP2",
		"UK3CB_CHD_O_BMP2K",
		"UK3CB_CHD_O_BRM1K",
		"UK3CB_CHD_O_BTR60",
		"UK3CB_CHD_O_BTR70"
	};

	opforHeavyVehicles[] = {
		"UK3CB_CHD_O_T34",
		"UK3CB_CHD_O_T55",
		"UK3CB_CHD_O_T72A",
		"UK3CB_CHD_O_T72B",
		"UK3CB_CHD_O_T72BM",
		"UK3CB_CHD_O_T72BA",
		"UK3CB_CHD_O_T72BB"
	};

	opforTroopCarriers[] = {
		"UK3CB_CHD_O_Gaz66_Covered",
		"UK3CB_CHD_O_Gaz66_Open",
		"UK3CB_CHD_O_Hilux_Open",
		"UK3CB_CHD_O_Kamaz_Covered",
		"UK3CB_CHD_O_Kamaz_Open",
		"UK3CB_CHD_O_Kraz255_Open",
		"UK3CB_CHD_O_LR_Closed",
		"UK3CB_CHD_O_LR_Open",
		"UK3CB_CHD_O_Ural",
		"UK3CB_CHD_O_Ural_Open",
		"UK3CB_CHD_O_Zil131_Covered",
		"UK3CB_CHD_O_Zil131_Open",
		"UK3CB_CHD_O_Van_Transport"
	};

	opforAAVehicles[] = {
		"UK3CB_CHD_O_MTLB_ZU23",
		"UK3CB_CHD_O_ZsuTank",
		"UK3CB_CHD_O_Gaz66_ZU23"
	};

	opforAttackHelicopters[] = {
		"UK3CB_CHD_O_Mi8AMTSh"
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
