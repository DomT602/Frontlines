/*
	Faction: CSAT
	Author: Dom
	Requires: None
*/
class Opfor_Setup {
	opforSquads[] = {
		{
			"O_Soldier_SL_F",
			"O_Soldier_TL_F",
			"O_Soldier_TL_F",
			"O_medic_F",
			"O_engineer_F",
			"O_Soldier_LAT_F",
			"O_Sharpshooter_F",
			"O_HeavyGunner_F",
			"O_Soldier_F"
		},
		{
			"O_Soldier_SL_F",
			"O_Soldier_TL_F",
			"O_Soldier_TL_F",
			"O_medic_F",
			"O_engineer_F",
			"O_Soldier_LAT_F",
			"O_Sharpshooter_F",
			"O_HeavyGunner_F",
			"O_Soldier_F",
			"O_Soldier_LAT_F",
			"O_HeavyGunner_F"
		},
		{
			"O_Soldier_SL_F",
			"O_Soldier_TL_F",
			"O_Soldier_LAT_F",
			"O_Soldier_AA_F",
			"O_Soldier_AA_F",
			"O_medic_F",
			"O_HeavyGunner_F",
			"O_Soldier_LAT_F",
			"O_Soldier_F"
		},
		{
			"O_Soldier_SL_F",
			"O_Soldier_TL_F",
			"O_Soldier_TL_F",
			"O_medic_F",
			"O_engineer_F",
			"O_Soldier_AT_F",
			"O_Soldier_AT_F",
			"O_HeavyGunner_F",
			"O_Soldier_LAT_F"
		}
	};

	opforOfficer = "O_officer_F";
	opforPilot = "O_helipilot_F";
	opforMortar = "O_Mortar_01_F";
	opforStatics[] = { //HMGs, AT etc
		"O_HMG_01_high_F",
		"O_GMG_01_high_F",
		"O_static_AA_F",
		"O_static_AT_F"
	};

	opforSupplyTruck = "O_Truck_03_repair_F";
	opforFuelTruck = "O_Truck_03_fuel_F";
	opforAmmoTruck = "O_Truck_03_ammo_F";

	//if the vehicle does not belong to the faction naturally, enclose in {} and add ,true
	opforLightVehicles[] = {
		"O_MRAP_02_hmg_F",
		"O_MRAP_02_gmg_F",
		"O_LSV_02_armed_F",
		"O_LSV_02_AT_F"
	};

	opforMediumVehicles[] = {
		"O_APC_Tracked_02_cannon_F",
		"O_APC_Tracked_02_AA_F"
	};

	opforHeavyVehicles[] = {
		"O_MBT_02_cannon_F",
		"O_MBT_04_cannon_F",
		"O_MBT_04_command_F"
	};

	opforTroopCarriers[] = {
		"O_Truck_03_transport_F",
		"O_Truck_03_covered_F",
		"O_Truck_02_covered_F",
		"O_Truck_02_transport_F"
	};

	opforAAVehicles[] = {
		"O_APC_Tracked_02_AA_F",
		"O_T_APC_Tracked_02_AA_ghex_F"
	};

	opforAttackHelicopters[] = {
		"O_Heli_Attack_02_F",
		"O_Heli_Attack_02_black_F",
		"O_Heli_Light_02_F",
		"O_Heli_Light_02_v2_F"
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
