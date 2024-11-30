/*
	Faction: United States Marine Corps (Woodland)
	Author: Reidy
	Requires: RHSUSF, TFAR
*/
class Logi_Setup {
	fobBuilding = "Land_Cargo_HQ_V1_F";

	bluforCrates[] = { //the order links to the variable containing all resources
		"CargoNet_01_box_F", //supplies
		"CargoNet_01_barrels_F", //fuel
		"B_CargoNet_01_ammo_F" //ammo
	};

	fobBoxes[] = { //vehicles that FOBs can be created from
		"B_Slingload_01_Cargo_F",
		"rhsusf_M1078A1P2_B_D_CP_fmtv_usarmy"
	};

	mobileRespawns[] = { //vehicles that act as mobile respawns
		"rhsusf_M1230a1_usarmy_wd",
		"rhsusf_CH53E_USMC_D"
	};

	medicalBuildings[] = { //buildings to add heal actions onto
		"Land_Medevac_house_V1_F"
	};

	/*
		The build menu can have as many categories as you want, with any number of elements in it;
		Format is:
		{
			"Category Title",
			{
				{"Classname",{supplies,fuel,ammo},"any conditions to buy"}
				If first element is array, you can overwrite default name as shown below
				{{"B_Slingload_01_Cargo_F", "FOB Container"}, {300,500,0}, "(count DT_allFOBs) < (getNumber(missionConfigFile >> 'Settings' >> 'maxFobs'))"}
			}
		}
	*/
	bluforBuyables[] = {
		{
			"Light Vehicles",
			{
				{"I_G_Quadbike_01_F", {50,25,0}, ""},

				{"rhsusf_m998_w_s_4dr_halftop", {60,25,0}, ""},
				{"rhsusf_m1043_w_s", {60,25,0}, ""},
				{"rhsusf_m1045_w_s", {125,50,100}, ""},

				{"rhsusf_m1151_mk19_v3_usmc_wd", {75,25,50}, ""},
				{"rhsusf_m1151_m240_v3_usmc_wd", {75,25,50}, ""},
				{"rhsusf_m1151_m2_v3_usmc_wd", {75,25,50}, ""},

				{"rhsusf_m1240a1_usmc_wd", {100,50,75}, ""},

				{"rhsusf_m1240a1_m2_usmc_wd", {125,50,50}, ""},
				{"rhsusf_m1240a1_m240_usmc_wd", {125,50,50}, ""},
				{"rhsusf_m1240a1_mk19_usmc_wd", {125,50,50}, ""},
				{"rhsusf_m1240a1_mk19crows_usmc_wd", {250,50,100}, ""},
				{"rhsusf_m1240a1_m2crows_usmc_wd", {250,50,100}, ""},

				{"rhsusf_M1084A1P2_B_WD_fmtv_usarmy", {100,100,0}, ""},
				{"rhsusf_M1083A1P2_B_M2_WD_fmtv_usarmy", {100,100,0}, ""}
			}
		},
		{
			"Heavy Vehicles",
			{
				{"rhsusf_M1117_W", {200,150,250}, ""},

				{"rhsusf_stryker_m1126_m2_wd", {250,150,250}, ""},
				{"rhsusf_stryker_m1126_mk19_wd", {250,150,250}, ""},
				{"rhsusf_stryker_m1132_m2_np_wd", {250,150,250}, ""},
				{"rhsusf_stryker_m1132_m2_wd", {250,150,250}, ""},
				{"rhsusf_stryker_m1134_wd", {250,150,250}, ""},

				{"rhsusf_m1a1fep_wd", {400,200,400}, "DT_globalReputation > 50 && {call DT_fnc_getMissionProgress > 0.3}"},

				{"rhsusf_M142_usmc_WD", {400,200,400}, ""}
			}
		},
		{
			"Air Vehicles",
			{
				{"B_UAV_01_F", {50,100,0}, ""},
				{"B_UAV_06_F", {75,100,0}, ""},
				{"B_UAV_02_dynamicLoadout_F", {300,200,200}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {DT_globalReputation > 50 && {call DT_fnc_getMissionProgress > 0.35}}"},

				{"RHS_UH1Y_UNARMED_d", {200,150,100}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},
				{"RHS_UH1Y_FFAR_d", {225,150,150}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},
				{"RHS_UH1Y_d", {250,150,200}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},

				{"rhsusf_CH53E_USMC_D", {250,150,250}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},
				{"rhsusf_CH53E_USMC_GAU21_D", {250,150,250}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},

				{"RHS_AH1Z", {400,200,400}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},

				{"RHS_C130J", {600,300,0}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentPlanes',[]]) < DT_maxPlaneCount}"},
				{"RHS_C130J_Cargo", {600,300,0}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentPlanes',[]]) < DT_maxPlaneCount}"},

				{"rhsusf_f22", {800,800,800}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentPlanes',[]]) < DT_maxPlaneCount && {DT_globalReputation > 30 && {call DT_fnc_getMissionProgress > 0.4}}}"},
				{"RHS_A10", {800,800,800}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentPlanes',[]]) < DT_maxPlaneCount && {DT_globalReputation > 30 && {call DT_fnc_getMissionProgress > 0.35}}}"}
			}
		},
		{
			"Naval Vehicles",
			{
				{"I_C_Boat_Transport_02_F", {40,25,0}, ""},
				{"rhsusf_mkvsoc", {100,40,70}, ""}
			}
		},
		{
			"Defences",
			{
				{"RHS_Stinger_AA_pod_d", {100,0,100}, ""},
				{"RHS_M119_D", {150,0,150}, ""}
			}
		},
		{
			"Buildings",
			{
				{"Land_Medevac_house_V1_F", {30,0,0}, ""},

				{"Camp", {10,0,0}, ""},
				{"CampEast", {15,0,0}, ""},
				{"Land_tent_east", {15,0,0}, ""},
				{"USMC_WarfareBVehicleServicePoint", {15,0,0}, ""},
				{"USMC_WarfareBUAVterminal", {15,0,0}, ""},
				{"Land_GuardTower_02_F", {10,0,0}, ""},

				{"FlagCarrierUSA", {5,0,0}, ""},
				{"Flag_RedCrystal_F", {5,0,0}, ""},

				{"Land_PortableLight_single_F", {10,0,0}, ""},
				{"Land_PortableLight_double_F", {10,0,0}, ""},
				{"PortableHelipadLight_01_blue_F", {10,0,0}, ""},
				{"PortableHelipadLight_01_green_F", {10,0,0}, ""},
				{"PortableHelipadLight_01_red_F", {10,0,0}, ""},
				{"Land_Camping_Light_F", {10,0,0}, ""},
				{"Land_TentLamp_01_standing_F", {10,0,0}, ""},
				{"Land_TentLamp_01_standing_red_F", {10,0,0}, ""},
				{"Land_TentLamp_01_suspended_F", {10,0,0}, ""},
				{"Land_TentLamp_01_suspended_red_F", {10,0,0}, ""},

				{"Land_BagFence_01_round_green_F", {10,0,0}, ""},
				{"Land_BagFence_01_long_green_F", {10,0,0}, ""},
				{"Land_BagFence_01_corner_green_F", {10,0,0}, ""},
				{"Land_BagFence_01_end_green_F", {10,0,0}, ""},
				{"Land_BagBunker_01_small_green_F", {15,0,0}, ""},
				{"Land_BagBunker_01_large_green_F", {15,0,0}, ""},
				{"Land_HBarrier_01_tower_green_F", {75,0,0}, ""},

				{"Land_HBarrier_01_line_1_green_F", {5,0,0}, ""},
				{"Land_HBarrier_01_line_3_green_F", {15,0,0}, ""},
				{"Land_HBarrier_01_line_5_green_F", {20,0,0}, ""},
				{"Land_HBarrier_01_big_4_green_F", {50,0,0}, ""},
				{"Land_HBarrier_01_wall_4_green_F", {20,0,0}, ""},
				{"Land_HBarrier_01_wall_corner_green_F", {25,0,0}, ""},
				{"Land_HBarrier_01_wall_6_green_F", {50,0,0}, ""},
				{"Land_HBarrier_01_wall_corridor_green_F", {25,0,0}, ""},
				{"Land_HBarrier_01_big_tower_green_F", {100,0,0}, ""},

				{"BlockConcrete_F", {30,0,0}, ""},
				{"Land_RampConcrete_F", {30,0,0}, ""},
				{"Land_RampConcreteHigh_F", {30,0,0}, ""},

				{"Land_Razorwire_F", {15,0,0}, ""},
				{"Land_Mil_WiredFence_F", {25,0,0}, ""},
				{"Land_ConcreteHedgehog_01_F", {15,0,0}, ""},
				{"Land_CzechHedgehog_01_old_F", {15,0,0}, ""},

				{"Land_CampingChair_V1_F", {5,0,0}, ""},
				{"Land_CampingChair_V2_F", {5,0,0}, ""},
				{"Land_CampingTable_F", {5,0,0}, ""},
				{"Land_ConnectorTent_01_floor_light_F", {5,0,0}, ""},

				{"Land_Sign_WarningMilitaryArea_F", {5,0,0}, ""},
				{"Land_SignM_WarningMilitaryArea_english_F", {5,0,0}, ""},
				{"Land_Sign_WarningMilAreaSmall_F", {5,0,0}, ""},
				{"Land_SignM_WarningMilAreaSmall_english_F", {5,0,0}, ""},
				{"Land_Sign_WarningMilitaryVehicles_F", {5,0,0}, ""},
				{"Land_SignM_WarningMilitaryVehicles_english_F", {5,0,0}, ""},
				{"Land_Sign_MinesDanger_English_F", { 5,0,0}, ""},

				{"Land_BarGate_01_open_F", { 10,0,0}, ""},
				{"Land_Mil_WiredFence_Gate_F", { 10,0,0}, ""}
			}
		},
		{
			"Logistics",
			{
				{{"B_Slingload_01_Cargo_F", "FOB Container"}, {300,500,0}, "(count DT_allFOBs) < (getNumber(missionConfigFile >> 'Settings' >> 'maxFobs'))"},
				{{"rhsusf_M1078A1P2_B_D_CP_fmtv_usarmy", "FOB Truck"}, {350,500,0}, "(count DT_allFOBs) < (getNumber(missionConfigFile >> 'Settings' >> 'maxFobs'))"},

				{{"Land_RepairDepot_01_tan_F", "Recycle Building"}, {250,0,0}, ""},
				{{"B_Radar_System_01_F", "Radar"}, {1000,0,0}, ""},
				{"Land_HelipadSquare_F", {250,0,0}, ""},
				{"Land_HelipadCircle_F", {250,0,0}, ""},
				{"Land_HelipadRescue_F", {250,0,0}, ""},
				{"Land_TentHangar_V1_F", {500,0,0}, ""},

				{"rhsusf_M977A4_REPAIR_BKIT_usarmy_wd", {250,50,0}, ""},
				{"rhsusf_M977A4_AMMO_usarmy_wd", {200,50,50}, ""},
				{"rhsusf_M978A4_usarmy_wd", {200,100,0}, ""},

				{{"rhsusf_M1230a1_usarmy_wd","Mobile Respawn Vehicle"}, {200,100,0}, ""},
				{{"rhsusf_CH53E_USMC_D","Mobile Respawn Helicopter"}, {200,100,100}, ""},

				{"B_Slingload_01_Repair_F", {600,0,0}, ""},
				{"B_Slingload_01_Fuel_F", {100,500,0}, ""},
				{"B_Slingload_01_Ammo_F", {100,0,500}, ""},

				{"TFAR_Land_Communication_F", {100,0,0}, ""},

				{{"C_IDAP_Truck_02_water_F", "Relief Truck"}, {50,50,0}, "missionNamespace getVariable [""DT_secondaryActive"",""""] isEqualTo ""humanitarianRelief"""},
				{{"Land_PortableWeatherStation_01_olive_F", "Listening Post"}, {250,0,0}, "missionNamespace getVariable [""DT_secondaryActive"",""""] isEqualTo ""listeningPost"""}
			}
		}
	};
	recycleBuilding = "Land_RepairDepot_01_tan_F"; //Allows recycling of building, needs one per FOB
	radar = "B_Radar_System_01_F"; //Allows purchasing of air vehicles, only requires one map-wide
	helipads[] = {"Land_HelipadSquare_F","Land_HelipadCircle_F","Land_HelipadRescue_F"}; //Helipads to increase rotary capacity
	hangars[] = {"Land_TentHangar_V1_F"}; //Hangar to increase fixed wing capacity

	supplyCrateTypes[] = { //crate types to be used below, format {sizeName, classname}
		{"medical", "ACE_medicalSupplyCrate_advanced"},
		{"small", "Box_NATO_Ammo_F"},
		{"medium", "Box_NATO_Wps_F"},
		{"large", "Box_NATO_WpsSpecial_F"}
	};
	//categories supported: medicalCrateCategory,lightWeaponCrateCategory,heavyWeaponCrateCategory,staticWeaponCrateCategory,miscWeaponCrateCategory
	supplyCrates[] = { //format {"category","title","box size",{resources},{contents}}
		{"medicalCrateCategory","Medical Crate","medical",{25,0,0},{
			{"ACE_EarPlugs",10},
			{"ACE_packingBandage",50},
			{"ACE_fieldDressing",50},
			{"ACE_quikclot",50},
			{"ACE_elasticBandage",50},
			{"ACE_tourniquet",20},
			{"ACE_morphine",20},
			{"ACE_epinephrine",10},
			{"ACE_splint",20},
			{"ACE_salineIV",5},
			{"ACE_salineIV_500",8},
			{"ACE_salineIV_250",10},
			{"ACE_surgicalKit",5}
		}},
		{"medicalCrateCategory","Advanced Medical Crate","medical",{75,0,0},{
			{"ACE_EarPlugs",10},
			{"ACE_packingBandage",100},
			{"ACE_fieldDressing",100},
			{"ACE_quikclot",100},
			{"ACE_elasticBandage",100},
			{"ACE_tourniquet",40},
			{"ACE_morphine",40},
			{"ACE_epinephrine",20},
			{"ACE_adenosine",10},
			{"ACE_splint",40},
			{"ACE_salineIV",10},
			{"ACE_salineIV_500",16},
			{"ACE_salineIV_250",20},
			{"ACE_plasmaIV",10},
			{"ACE_plasmaIV_500",16},
			{"ACE_plasmaIV_250",20},
			{"ACE_bloodIV",10},
			{"ACE_bloodIV_500",16},
			{"ACE_bloodIV_250",20},
			{"ACE_surgicalKit",10}
		}},
		{"staticWeaponCrateCategory","M252 Mortar","large",{25,0,50},{
			{"ACE_EarPlugs",2},
			{"ACE_MapTools",2},
			{"ACE_Vector",2},
			{"ACE_artilleryTable",2},
			{"rhs_M252_Gun_Bag",2},
			{"rhs_M252_Bipod_Bag",2}
		}},
		{"staticWeaponCrateCategory","M2 HMG","large",{25,0,50},{
			{"ACE_EarPlugs",2},
			{"ACE_MapTools",2},
			{"ACE_Vector",2},
			{"RHS_M2_Gun_Bag",2},
			{"RHS_M2_Tripod_Bag",2},
			{"RHS_M2_MiniTripod_Bag",2}
		}},
		{"staticWeaponCrateCategory","TOW Launcher","large",{25,0,50},{
			{"ACE_EarPlugs",2},
			{"rhs_TOW_Tripod_Bag",2},
			{"rhs_Tow_Gun_Bag",2}
		}},
		{"staticWeaponCrateCategory","Mk19 GMG","large",{25,0,50},{
			{"ACE_EarPlugs",2},
			{"RHS_Mk19_Tripod_Bag",1},
			{"RHS_Mk19_Gun_Bag",1}
		}},
		{"miscWeaponCrateCategory","Raven","small",{25,0,25},{
			{"B_rhsusf_B_BACKPACK",1}
		}},
		{"heavyWeaponCrateCategory","Javelin","medium",{25,0,50},{
			{"rhs_weap_fgm148",2},
			{"rhs_fgm148_magazine_AT",6}
		}},
		{"heavyWeaponCrateCategory","M3 MAAWS","medium",{25,0,50},{
			{"ACE_EarPlugs",2},
			{"ACE_Vector",2},
			{"RHS_weap_maaws",1},
			{"rhs_optic_maaws",1},
			{"rhs_mag_maaws_HE",5},
			{"rhs_mag_maaws_HEAT",10}
		}},
		{"lightWeaponCrateCategory","Light AT","medium",{25,0,50},{
			{"ACE_EarPlugs",2},
			{"ACE_Vector",2},
			{"rhs_weap_m72a7",4},
			{"rhs_weap_M136_hp",2},
			{"rhs_weap_M136",4},
			{"rhs_weap_M136_hedp",2}
		}},
		{"heavyWeaponCrateCategory","M240 MMG","medium",{25,0,50},{
			{"ACE_EarPlugs",3},
			{"ACE_Vector",3},
			{"rhs_weap_m240B",1},
			{"rhsusf_acc_ELCAN_ard",1},
			{"rhsusf_100Rnd_762x51_m80a1epr",5},
			{"rhsusf_100Rnd_762x51",5},
			{"rhsusf_100Rnd_762x51_m61_ap",5},
			{"rhsusf_100Rnd_762x51_m62_tracer",5}
		}},
		{"lightWeaponCrateCategory","Standard Resupply","medium",{25,0,75},{
			{"rhsusf_mag_15Rnd_9x19_FMJ",4},
			{"rhsusf_mag_17Rnd_9x19_FMJ",4},
			{"rhsusf_200Rnd_556x45_soft_pouch_coyote",8},
			{"rhsusf_200Rnd_556x45_mixed_soft_pouch_coyote",8},
			{"rhs_mag_30Rnd_556x45_M855A1_PMAG",20},
			{"rhs_mag_30Rnd_556x45_M855A1_PMAG_Tracer_Red",20},
			{"rhsusf_20Rnd_762x51_SR25_m62_Mag",10},
			{"rhsusf_20Rnd_762x51_SR25_m993_Mag",10},
			{"rhs_mag_an_m8hc",6},
			{"rhs_mag_m18_green",4},
			{"rhs_mag_m18_purple",4},
			{"rhs_mag_m18_red",4},
			{"rhs_mag_M397_HET",10},
			{"rhs_mag_M433_HEDP",10},
			{"rhs_mag_M441_HE",10},
			{"rhs_mag_m67",10},
			{"rhs_mag_m713_Red",5},
			{"rhs_mag_m714_White",5}
		}},
		{"miscWeaponCrateCategory","Explosives","small",{25,0,50},{
			{"DemoCharge_Remote_Mag",6},
			{"ACE_Clacker",2},
			{"ACE_DefusalKit",2},
			{"MineDetector",2}
		}},
		{"miscWeaponCrateCategory","Empty Crate (Small)","small",{0,0,0},{

		}},
		{"miscWeaponCrateCategory","Empty Crate (Medium)","medium",{0,0,0},{

		}},
		{"heavyWeaponCrateCategory","Javelin Ammo","medium",{25,0,75},{
			{"rhs_fgm148_magazine_AT",12}
		}}
	};
};