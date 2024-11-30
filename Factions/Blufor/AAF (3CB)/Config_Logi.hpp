/*
	Faction: AAF
	Author: TacticalError, Rickard
	Requires: TFAR, 3CB
*/
class Logi_Setup {
	fobBuilding = "Campfire_burning_F";

	bluforCrates[] = { //the order links to the variable containing all resources
		"CargoNet_01_box_F", //supplies
		"CargoNet_01_barrels_F", //fuel
		"B_CargoNet_01_ammo_F" //ammo
	};

	fobBoxes[] = { //vehicles that FOBs can be created from
		"UK3CB_AAF_B_MTVR_Closed",
		"B_Slingload_01_Cargo_F"
	};

	mobileRespawns[] = { //vehicles that act as mobile respawns
        "UK3CB_AAF_B_M998_2DR",
		"UK3CB_AAF_B_UH60M2",
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
				{"UK3CB_AAF_B_M1030", {10,10,0}, ""},
				{"UK3CB_AAF_B_Quadbike", {25,25,0}, ""},
				{"UK3CB_AAF_B_M1025_TOW", {50,50,100}, ""},
				{"UK3CB_AAF_B_M1151_OGPK_M2", {50,50,50}, ""},
				{"UK3CB_AAF_B_M1151_OGPK_MK19", {50,50,50}, ""},
				{"UK3CB_AAF_B_M1151_OGPK_M240", {50,50,50}, ""},
				{"UK3CB_AAF_B_MTVR_Recovery", {50,0,0}, ""},
				{"UK3CB_AAF_B_MTVR_Open", {50,0,0}, ""},
				{"UK3CB_AAF_B_M1117", {100,50,50}, ""},
				{"UK3CB_AAF_B_LAV25_HQ", {100,50,50}, ""},
				{"UK3CB_AAF_B_LAV25", {100,50,100}, ""},
				{"UK3CB_AAF_B_AAV", {150,50,100}, ""}
			}
		},
		{
			"Heavy Vehicles",
			{
				{"UK3CB_AAF_B_M1A1", {1000,250,500}, ""},
				{"UK3CB_AAF_B_M109", {500,250,1000}, "DT_globalReputation > 25"},
				{"UK3CB_AAF_B_M270_MLRS_CLUSTER", {500,250,1000}, "DT_globalReputation > 50"},
				{"UK3CB_AAF_B_M270_MLRS_HE", {500,250,1000}, "DT_globalReputation > 50"}
			}
		},
		{
			"Air Vehicles",
			{
				{"UK3CB_AAF_B_Unarmed_MH9", {250,250,0}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},
				{"UK3CB_AAF_B_Benches_MH9", {250,250,0}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},
				{"UK3CB_AAF_B_AH9", {250,250,250}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {DT_globalReputation > 25 && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}}"},
				{"UK3CB_AAF_B_UH60M", {250,250,150}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},
				{"UK3CB_AAF_B_AH1Z", {500,250,500}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {DT_globalReputation > 25 && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}}"},
				{"UK3CB_AAF_B_Gripen_G", {1000,500,500}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {DT_globalReputation > 25 && {count (missionNamespace getVariable ['DT_currentPlanes',[]]) < DT_maxPlaneCount}}"},
				{"UK3CB_AAF_B_C130J_G_CARGO", {500,250,0}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentPlanes',[]]) < DT_maxPlaneCount}"},
				{"UK3CB_AAF_B_C130J_G", {500,250,0}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentPlanes',[]]) < DT_maxPlaneCount}"},
				{"I_UAV_02_dynamicLoadout_F", {250,100,250}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {DT_globalReputation > 25 && {count (missionNamespace getVariable ['DT_currentPlanes',[]]) < DT_maxPlaneCount}}"}
			}
		},
		{
			"Naval Vehicles",
			{
				{"UK3CB_AAF_B_RHIB", {150,100,100}, ""},
				{"UK3CB_AAF_B_RHIB_Gunboat", {150,100,150}, ""},
			}
		},
		{
			"Defences",
			{
				{"UK3CB_AAF_B_Stinger_AA_pod", {100,0,100}, ""},
				{"UK3CB_AAF_B_M119", {100,0,100}, ""},
				{"UK3CB_AAF_B_M240_High", {100,0,100}, ""},
				{"UK3CB_AAF_B_M240_Low", {100,0,100}, ""},
				{"UK3CB_AAF_B_M2_TriPod", {100,0,100}, ""},
				{"UK3CB_AAF_B_M2_MiniTripod", {100,0,100}, ""},
				{"UK3CB_AAF_B_TOW_TriPod", {100,0,250}, ""},
				{"UK3CB_AAF_B_MK19_TriPod", {100,0,150}, ""},
				{"UK3CB_AAF_B_M240_nest_des", {150,0,100}, ""},
				{"UK3CB_AAF_B_M240_nest", {150,0,100}, ""},
				{"UK3CB_AAF_B_Searchlight", {10,0,10}, ""}
			}
		},
		{
			"Buildings",
			{
				{"Land_Medevac_house_V1_F", {30,0,0}, ""},

				{"Flag_AAF_Airforce", {5,0,0}, ""},
				{"Flag_AAF_Army", {5,0,0}, ""},
				{"Flag_AAF_Navy", {5,0,0}, ""},
				{"Flag_AAF_SF", {5,0,0}, ""},
				{"Flag_AAF_F", {5,0,0}, ""},

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

				{"Land_BagFence_round_F", {10,0,0}, ""},
				{"Land_BagFence_long_F", {10,0,0}, ""},
				{"Land_BagFence_corner_F", {10,0,0}, ""},
				{"Land_BagFence_end_F", {10,0,0}, ""},
				{"Land_BagBunker_small_F", {15,0,0}, ""},
				{"Land_BagBunker_large_F", {15,0,0}, ""},
				{"Land_HBarrierTower_F", {75,0,0}, ""},

				{"Land_HBarrier_1_F", {5,0,0}, ""},
				{"Land_HBarrier_3_F", {15,0,0}, ""},
				{"Land_HBarrier_5_F", {20,0,0}, ""},
				{"Land_HBarrier_Big_F", {50,0,0}, ""},
				{"Land_HBarrierWall4_F", {20,0,0}, ""},
				{"Land_HBarrierWall6_F", {25,0,0}, ""},
				{"Land_HBarrierWall_corner_F", {50,0,0}, ""},
				{"Land_HBarrierWall_corridor_F", {25,0,0}, ""},
				{"Land_HBarrierTower_F", {100,0,0}, ""},

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
				{{"UK3CB_AAF_B_MTVR_Closed", "FOB Truck"}, {350,500,0}, "(count DT_allFOBs) < (getNumber(missionConfigFile >> 'Settings' >> 'maxFobs'))"},

				{{"Land_RepairDepot_01_green_F", "Recycle Building"}, {250,0,0}, ""},
				{{"B_Radar_System_01_F", "Radar"}, {1000,0,0}, ""},
				{"Land_HelipadSquare_F", {250,0,0}, ""},
				{"Land_HelipadCircle_F", {250,0,0}, ""},
				{"Land_HelipadRescue_F", {250,0,0}, ""},
				{"Land_TentHangar_V1_F", {500,0,0}, ""},

				{"UK3CB_AAF_B_MTVR_Repair", {250,50,0}, ""},
				{"UK3CB_AAF_B_MTVR_Reammo", {200,50,50}, ""},
				{"UK3CB_AAF_B_MTVR_Refuel", {200,100,0}, ""},

				{{"UK3CB_AAF_B_M998_2DR","Mobile Respawn Vehicle"}, {200,100,0}, ""},
				{{"UK3CB_AAF_B_UH60M2","Mobile Respawn Helicopter"}, {200,100,100}, ""},

				{"B_Slingload_01_Repair_F", {600,0,0}, ""},
				{"B_Slingload_01_Fuel_F", {100,500,0}, ""},
				{"B_Slingload_01_Ammo_F", {100,0,500}, ""},

				{"TFAR_Land_Communication_F", {100,0,0}, ""},

				{{"C_IDAP_Truck_02_water_F", "Relief Truck"}, {50,50,0}, "missionNamespace getVariable [""DT_secondaryActive"",""""] isEqualTo ""humanitarianRelief"""},
				{{"Land_PortableWeatherStation_01_olive_F", "Listening Post"}, {250,0,0}, "missionNamespace getVariable [""DT_secondaryActive"",""""] isEqualTo ""listeningPost"""}
			}
		}
	};
	recycleBuilding = "Land_RepairDepot_01_green_F"; //Allows recycling of building, needs one per FOB
	radar = "B_Radar_System_01_F"; //Allows purchasing of air vehicles, only requires one map-wide
	helipads[] = {"Land_HelipadSquare_F","Land_HelipadCircle_F","Land_HelipadRescue_F"}; //Helipads to increase rotary capacity
	hangars[] = {"Land_TentHangar_V1_F"}; //Hangar to increase fixed wing capacity

    supplyCrateTypes[] = { //crate types to be used below, format {sizeName, classname}
        {"medical", "ACE_medicalSupplyCrate_advanced"},
        {"small", "Box_IND_Wps_F"},
        {"medium", "Box_IND_WpsSpecial_F"},
        {"large", "Box_AAF_Equip_F"},
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
		{"miscWeaponCrateCategory","Empty Crate (Small)","small",{0,0,0},{

		}},
		{"miscWeaponCrateCategory","Empty Crate (Medium)","medium",{0,0,0},{

		}}
	};
};