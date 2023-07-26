/*
	Faction: Middle Eastern Extremists
	Author: Dom
	Requires: 3CB Factions
*/
class Opfor_Setup {
	opforSquads[] = {
		{
			"UK3CB_MEE_O_SL",
			"UK3CB_MEE_O_TL",
			"UK3CB_MEE_O_MD",
			"UK3CB_MEE_O_AR",
			"UK3CB_MEE_O_RIF_1",
			"UK3CB_MEE_O_ENG",
			"UK3CB_MEE_O_RIF_2",
			"UK3CB_MEE_O_MK"
		},
		{
			"UK3CB_MEE_O_SL",
			"UK3CB_MEE_O_TL",
			"UK3CB_MEE_O_MD",
			"UK3CB_MEE_O_MK",
			"UK3CB_MEE_O_LAT",
			"UK3CB_MEE_O_RIF_1",
			"UK3CB_MEE_O_ENG",
			"UK3CB_MEE_O_DEM"
		},
		{
			"UK3CB_MEE_O_SL",
			"UK3CB_MEE_O_TL",
			"UK3CB_MEE_O_MD",
			"UK3CB_MEE_O_MK",
			"UK3CB_MEE_O_MG",
			"UK3CB_MEE_O_MG_ASST",
			"UK3CB_MEE_O_ENG",
			"UK3CB_MEE_O_RIF_1"
		},
		{
			"UK3CB_MEE_O_SL",
			"UK3CB_MEE_O_TL",
			"UK3CB_MEE_O_MD",
			"UK3CB_MEE_O_AT",
			"UK3CB_MEE_O_AT_ASST",
			"UK3CB_MEE_O_MK",
			"UK3CB_MEE_O_AR",
			"UK3CB_MEE_O_RIF_1"
		},
		{
			"UK3CB_MEE_O_SL",
			"UK3CB_MEE_O_TL",
			"UK3CB_MEE_O_MD",
			"UK3CB_MEE_O_AA",
			"UK3CB_MEE_O_AA_ASST",
			"UK3CB_MEE_O_RIF_2",
			"UK3CB_MEE_O_AR",
			"UK3CB_MEE_O_RIF_1"
		}
	};

	opforOfficer = "UK3CB_MEE_O_COM";
	opforPilot = "UK3CB_MEE_O_CREW";
	opforMortar = "UK3CB_MEE_O_2b14_82mm";
	opforStatics[] = { //HMGs, AT etc
		"UK3CB_MEE_O_Igla_AA_pod",
		"UK3CB_MEE_O_DSHKM",
		"UK3CB_MEE_O_KORD_high",
		"UK3CB_MEE_O_PKM_High",
		"UK3CB_MEE_O_SPG9"
	};

	opforSupplyTruck = "UK3CB_MEE_O_V3S_Repair";
	opforFuelTruck = "UK3CB_MEE_O_V3S_Refuel";
	opforAmmoTruck = "UK3CB_MEE_O_V3S_Reammo";
	opforArtilleryVehicle = "UK3CB_ADE_O_Hilux_Rocket_Arty";

	//if the vehicle does not belong to the faction naturally, enclose in {} and add ,true
	opforLightVehicles[] = {
		"UK3CB_MEE_O_Datsun_Pkm",
		"UK3CB_MEE_O_Hilux_Igla_Chair",
		"UK3CB_MEE_O_Hilux_GMG",
		"UK3CB_MEE_O_Hilux_Dshkm",
		"UK3CB_MEE_O_Hilux_M2",
		"UK3CB_MEE_O_Hilux_Metis",
		"UK3CB_MEE_O_Hilux_Pkm",
		"UK3CB_MEE_O_Hilux_Rocket",
		"UK3CB_MEE_O_Hilux_Spg9",
		"UK3CB_MEE_O_LR_AGS30",
		"UK3CB_MEE_O_LR_M2",
		"UK3CB_MEE_O_LR_SPG9",
		"UK3CB_MEE_O_M1025_MK19",
		"UK3CB_MEE_O_M1025_M2",
		"UK3CB_MEE_O_M1025_TOW",
		"UK3CB_MEE_O_M1025_TOW",
		"UK3CB_MEE_O_Offroad_AT",
		"UK3CB_MEE_O_Pickup_DSHKM",
		"UK3CB_MEE_O_Pickup_M2"
	};

	opforMediumVehicles[] = {
		"UK3CB_MEE_O_BRDM2",
		"UK3CB_MEE_O_BRDM2_ATGM",
		"UK3CB_MEE_O_BRDM2_HQ",
		"UK3CB_MEE_O_Hilux_BMP",
		"UK3CB_MEE_O_Hilux_BTR",
	};

	opforHeavyVehicles[] = {
		"UK3CB_MEE_O_T55"
	};

	opforTroopCarriers[] = {
		"UK3CB_MEE_O_V3S_Closed",
		"UK3CB_MEE_O_V3S_Open",
		"UK3CB_MEE_O_M998_2DR",
		"UK3CB_MEE_O_M998_4DR"
	};

	opforAAVehicles[] = {
		"UK3CB_MEE_O_MTLB_ZU23",
		"UK3CB_MEE_O_V3S_Zu23"
	};

	opforAttackHelicopters[] = {
		{"UK3CB_ADA_O_UH1H_GUNSHIP",true},
		{"UK3CB_ADA_O_UH1H_M240",true}
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
