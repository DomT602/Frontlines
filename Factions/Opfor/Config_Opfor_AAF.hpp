/*
	Faction: AAF
	Author: Dom
	Requires: None
*/
class Opfor_Setup {
	opforSquads[] = {
		{
			"I_Soldier_SL_F",
			"I_Soldier_TL_F",
			"I_Soldier_TL_F",
			"I_medic_F",
			"I_engineer_F",
			"I_Soldier_LAT_F",
			"I_Soldier_M_F",
			"I_Soldier_AR_F",
			"I_soldier_F"
		},
		{
			"I_Soldier_SL_F",
			"I_Soldier_TL_F",
			"I_Soldier_TL_F",
			"I_medic_F",
			"I_engineer_F",
			"I_Soldier_AT_F",
			"I_Soldier_AT_F",
			"I_Soldier_AR_F",
			"I_Soldier_LAT_F"
		},
		{
			"I_Soldier_SL_F",
			"I_Soldier_TL_F",
			"I_Soldier_LAT_F",
			"I_Soldier_AA_F",
			"I_Soldier_AA_F",
			"I_medic_F",
			"I_Soldier_AR_F",
			"I_Soldier_LAT_F",
			"I_soldier_F"
		},
		{
			"I_Soldier_SL_F",
			"I_Soldier_TL_F",
			"I_Soldier_TL_F",
			"I_medic_F",
			"I_engineer_F",
			"I_Soldier_LAT_F",
			"I_Soldier_M_F",
			"I_Soldier_AR_F",
			"I_soldier_F",
			"I_Soldier_LAT_F",
			"I_Soldier_AR_F"
		}
	};

	opforOfficer = "I_officer_F";
	opforPilot = "I_helipilot_F";
	opforMortar = "I_Mortar_01_F";
	opforStatics[] = { //HMGs, AT etc
		"I_HMG_01_high_F",
		"I_GMG_01_high_F",
		"I_static_AA_F",
		"I_static_AT_F"
	};

	opforSupplyTruck = "I_Truck_02_box_F";
	opforFuelTruck = "I_Truck_02_fuel_F";
	opforAmmoTruck = "I_Truck_02_ammo_F";
	opforArtilleryVehicle = "I_Truck_02_MRL_F";

	//if the vehicle does not belong to the faction naturally, enclose in {} and add ,true
	opforLightVehicles[] = {
		"I_MRAP_03_hmg_F",
		"I_MRAP_03_gmg_F",
		"I_LT_01_scout_F"
	};

	opforMediumVehicles[] = {
		"I_APC_tracked_03_cannon_F",
		"I_APC_Wheeled_03_cannon_F",
		"I_LT_01_AT_F",
		"I_LT_01_cannon_F"
	};

	opforHeavyVehicles[] = {
		"I_MBT_03_cannon_F"
	};

	opforTroopCarriers[] = {
		"I_Truck_02_covered_F",
		"I_Truck_02_transport_F"
	};

	opforAAVehicles[] = {
		"I_LT_01_AA_F"
	};

	opforAttackHelicopters[] = {
		"I_Heli_light_03_F",
		"I_Heli_light_03_dynamicLoadout_F"
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
