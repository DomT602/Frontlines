/*
	Faction: Ardistan Army
	Author: Dom
	Requires: 3CB Factions
*/
class Opfor_Setup {
	opforSquads[] = {
		{
			"UK3CB_ARD_O_SL",
			"UK3CB_ARD_O_TL",
			"UK3CB_ARD_O_MD",
			"UK3CB_ARD_O_AA",
			"UK3CB_ARD_O_AA_ASST",
			"UK3CB_ARD_O_RIF_2",
			"UK3CB_ARD_O_AR",
			"UK3CB_ARD_O_RIF_1"
		},
		{
			"UK3CB_ARD_O_SL",
			"UK3CB_ARD_O_TL",
			"UK3CB_ARD_O_MD",
			"UK3CB_ARD_O_AT",
			"UK3CB_ARD_O_AT_ASST",
			"UK3CB_ARD_O_RIF_1",
			"UK3CB_ARD_O_AR",
			"UK3CB_ARD_O_RIF_1"
		},
		{
			"UK3CB_ARD_O_SL",
			"UK3CB_ARD_O_TL",
			"UK3CB_ARD_O_MD",
			"UK3CB_ARD_O_RIF_1",
			"UK3CB_ARD_O_MK",
			"UK3CB_ARD_O_RIF_1",
			"UK3CB_ARD_O_ENG",
			"UK3CB_ARD_O_DEM"
		},
		{
			"UK3CB_ARD_O_SL",
			"UK3CB_ARD_O_TL",
			"UK3CB_ARD_O_MD",
			"UK3CB_ARD_O_RIF_1",
			"UK3CB_ARD_O_MG",
			"UK3CB_ARD_O_MG_ASST",
			"UK3CB_ARD_O_ENG",
			"UK3CB_ARD_O_RIF_1"
		},
		{
			"UK3CB_ARD_O_SL",
			"UK3CB_ARD_O_TL",
			"UK3CB_ARD_O_MD",
			"UK3CB_ARD_O_RIF_1",
			"UK3CB_ARD_O_LAT",
			"UK3CB_ARD_O_RIF_1",
			"UK3CB_ARD_O_ENG",
			"UK3CB_ARD_O_DEM"
		},
		{
			"UK3CB_ARD_O_SL",
			"UK3CB_ARD_O_TL",
			"UK3CB_ARD_O_MD",
			"UK3CB_ARD_O_AR",
			"UK3CB_ARD_O_RIF_1",
			"UK3CB_ARD_O_ENG",
			"UK3CB_ARD_O_AR",
			"UK3CB_ARD_O_RIF_1"
		}
	};

	opforOfficer = "UK3CB_ARD_O_OFF";
	opforPilot = "UK3CB_ARD_O_HELI_PILOT";
	opforMortar = "UK3CB_ARD_O_2b14_82mm";
	opforStatics[] = { //HMGs, AT etc
		"UK3CB_ARD_O_Igla_AA_pod",
		"UK3CB_ARD_O_DSHKM",
		"UK3CB_ARD_O_Metis",
		"UK3CB_ARD_O_PKM_High",
		"UK3CB_ARD_O_SPG9"
	};

	opforSupplyTruck = "UK3CB_ARD_O_Ural_Repair";
	opforFuelTruck = "UK3CB_ARD_O_Ural_Fuel";
	opforAmmoTruck = "UK3CB_ARD_O_Ural_Ammo";
	opforArtilleryVehicle = "UK3CB_ARD_O_BM21";

	//if the vehicle does not belong to the faction naturally, enclose in {} and add ,true
	opforLightVehicles[] = {
		"UK3CB_ARD_O_GAZ_Vodnik_Cannon",
		"UK3CB_ARD_O_GAZ_Vodnik_KVPT",
		"UK3CB_ARD_O_GAZ_Vodnik_PKT",
		"UK3CB_ARD_O_Hilux_GMG",
		"UK3CB_ARD_O_Hilux_Rocket_Arty",
		"UK3CB_ARD_O_Hilux_Dshkm",
		"UK3CB_ARD_O_Hilux_M2",
		"UK3CB_ARD_O_Hilux_Metis",
		"UK3CB_ARD_O_Hilux_Pkm",
		"UK3CB_ARD_O_Hilux_Rocket",
		"UK3CB_ARD_O_Hilux_Spg9",
		"UK3CB_ARD_O_UAZ_AGS30",
		"UK3CB_ARD_O_UAZ_MG",
		"UK3CB_ARD_O_UAZ_SPG9"
	};

	opforMediumVehicles[] = {
		"UK3CB_ARD_O_BRDM2",
		"UK3CB_ARD_O_BRDM2_ATGM",
		"UK3CB_ARD_O_BRDM2_HQ",
		"UK3CB_ARD_O_BMP1",
		"UK3CB_ARD_O_BMP2",
		"UK3CB_ARD_O_BMP2K",
		"UK3CB_ARD_O_BRM1K",
		"UK3CB_ARD_O_BTR60",
		"UK3CB_ARD_O_BTR70",
		"UK3CB_ARD_O_BTR80",
		"UK3CB_ARD_O_BTR80a"
	};

	opforHeavyVehicles[] = {
		"UK3CB_ARD_O_T34",
		"UK3CB_ARD_O_T55",
		"UK3CB_ARD_O_T72A",
		"UK3CB_ARD_O_T72B",
		"UK3CB_ARD_O_T72BM",
		"UK3CB_ARD_O_T72BA",
		"UK3CB_ARD_O_T72BB",
		"UK3CB_ARD_O_T72BC"
	};

	opforTroopCarriers[] = {
		"UK3CB_ARD_O_Zil131_Open",
		"UK3CB_ARD_O_Zil131_Covered",
		"UK3CB_ARD_O_Ural_Open",
		"UK3CB_ARD_O_Ural",
		"UK3CB_ARD_O_Hilux_Open"
	};

	opforAAVehicles[] = {
		"UK3CB_ARD_O_2S6M_Tunguska",
		"UK3CB_ARD_O_MTLB_ZU23",
		"UK3CB_ARD_O_ZsuTank"
	};

	opforAttackHelicopters[] = {
		"UK3CB_ARD_O_Mi_24P",
		"UK3CB_ARD_O_Mi_24V",
		"UK3CB_ARD_O_Mi8AMTSh"
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
