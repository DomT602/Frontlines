/*
	Faction: NATO
	Author: Dom
	Requires: None
*/
class Opfor_Setup {
	opforSquads[] = {
		{
			"B_Soldier_SL_F",
			"B_Soldier_TL_F",
			"B_Soldier_TL_F",
			"B_medic_F",
			"B_engineer_F",
			"B_soldier_LAT_F",
			"B_soldier_M_F",
			"B_soldier_AR_F",
			"B_Soldier_F"
		},
		{
			"B_Soldier_SL_F",
			"B_Soldier_TL_F",
			"B_Soldier_TL_F",
			"B_medic_F",
			"B_engineer_F",
			"B_soldier_AT_F",
			"B_soldier_AT_F",
			"B_soldier_AR_F",
			"B_soldier_LAT_F"
		},
		{
			"B_Soldier_SL_F",
			"B_Soldier_TL_F",
			"B_soldier_LAT_F",
			"B_soldier_AA_F",
			"B_soldier_AA_F",
			"B_medic_F",
			"B_soldier_AR_F",
			"B_soldier_LAT_F",
			"B_Soldier_F"
		},
		{
			"B_Soldier_SL_F",
			"B_Soldier_TL_F",
			"B_Soldier_TL_F",
			"B_medic_F",
			"B_engineer_F",
			"B_soldier_LAT_F",
			"B_soldier_M_F",
			"B_soldier_AR_F",
			"B_Soldier_F",
			"B_soldier_LAT_F",
			"B_soldier_AR_F"
		}
	};

	opforOfficer = "B_officer_F";
	opforPilot = "B_helipilot_F";
	opforMortar = "B_Mortar_01_F";
	opforStatics[] = { //HMGs, AT etc
		"B_HMG_01_high_F",
		"B_GMG_01_high_F",
		"B_static_AA_F",
		"B_static_AT_F"
	};

	opforSupplyTruck = "B_Truck_01_Repair_F";
	opforFuelTruck = "B_Truck_01_fuel_F";
	opforAmmoTruck = "B_Truck_01_ammo_F";
	opforArtilleryVehicle = "B_MBT_01_arty_F";

	//if the vehicle does not belong to the faction naturally, enclose in {} and add ,true
	opforLightVehicles[] = {
		"B_MRAP_01_hmg_F",
		"B_MRAP_01_gmg_F",
		"B_LSV_01_armed_F",
		"B_LSV_01_AT_F"
	};

	opforMediumVehicles[] = {
		"B_APC_Tracked_01_rcws_F",
		"B_APC_Tracked_01_CRV_F",
		"B_APC_Wheeled_01_cannon_F",
		"B_AFV_Wheeled_01_cannon_F"
	};

	opforHeavyVehicles[] = {
		"B_MBT_01_cannon_F",
		"B_MBT_01_TUSK_F"
	};

	opforTroopCarriers[] = {
		"B_Truck_01_covered_F",
		"B_Truck_01_transport_F"
	};

	opforAAVehicles[] = {
		"B_APC_Tracked_01_AA_F"
	};

	opforAttackHelicopters[] = {
		"B_Heli_Light_01_armed_F",
		"B_Heli_Attack_01_F"
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
