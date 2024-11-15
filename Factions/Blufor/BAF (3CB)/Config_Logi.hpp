/*
	Faction: British Armed Forces
	Author: Dom
	Requires: UK3CB, RHSUSF, RKSL, TFAR
*/
class Logi_Setup {
	fobBuilding = "Land_Cargo_HQ_V1_F";

	bluforCrates[] = { //the order links to the variable containing all resources
		"CargoNet_01_box_F", //supplies
		"CargoNet_01_barrels_F", //fuel
		"B_CargoNet_01_ammo_F" //ammo
	};

	fobBoxes[] = { //vehicles that FOBs can be created from
		"UK3CB_BAF_MAN_HX58_Container_Green",
		"UK3CB_BAF_MAN_HX58_Cargo_Green_B"
	};

	mobileRespawns[] = { //vehicles that act as mobile respawns
		"UK3CB_BAF_LandRover_Amb_FFR_Green_A",
		"UK3CB_BAF_Merlin_HC4_CSAR"
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
				{"UK3CB_BAF_LandRover_Soft_Green_A", {60,25,0}, ""},
				{"UK3CB_BAF_LandRover_Soft_FFR_Green_A", {60,25,0}, ""},
				{"UK3CB_BAF_LandRover_Hard_Green_A", {70,25,0}, ""},
				{"UK3CB_BAF_LandRover_Hard_FFR_Green_A", {70,25,0}, ""},
				{"UK3CB_BAF_LandRover_Snatch_Green_A", {80,25,0}, ""},
				{"UK3CB_BAF_LandRover_Snatch_FFR_Green_A", {80,25,0}, ""},

				{"UK3CB_BAF_LandRover_WMIK_GPMG_Green_A", {75,25,50}, ""},
				{"UK3CB_BAF_LandRover_WMIK_GPMG_FFR_Green_A", {75,25,50}, ""},
				{"UK3CB_BAF_LandRover_WMIK_HMG_Green_A", {80,25,50}, ""},
				{"UK3CB_BAF_LandRover_WMIK_HMG_FFR_Green_A", {80,25,50}, ""},
				{"UK3CB_BAF_LandRover_WMIK_GMG_Green_A", {80,25,75}, ""},
				{"UK3CB_BAF_LandRover_WMIK_GMG_FFR_Green_A", {80,25,75}, ""},
				{"UK3CB_BAF_LandRover_WMIK_Milan_Green_A", {100,25,100}, ""},
				{"UK3CB_BAF_LandRover_WMIK_Milan_FFR_Green_A", {100,25,100}, ""},

				{"UK3CB_BAF_Jackal2_L111A1_G", {100,50,75}, ""},
				{"UK3CB_BAF_Jackal2_L134A1_G", {100,50,100}, ""},

				{"UK3CB_BAF_Coyote_Passenger_L111A1_G", {100,50,75}, ""},
				{"UK3CB_BAF_Coyote_Passenger_L134A1_G", {100,50,100}, ""},
				{"UK3CB_BAF_Coyote_Logistics_L111A1_G", {100,50,75}, ""},
				{"UK3CB_BAF_Coyote_Logistics_L134A1_G", {100,50,100}, ""},

				{"UK3CB_BAF_Husky_Passenger_GPMG_Green", {150,50,50}, ""},
				{"UK3CB_BAF_Husky_Passenger_HMG_Green", {150,50,75}, ""},
				{"UK3CB_BAF_Husky_Passenger_GMG_Green", {150,50,75}, ""},
				{"UK3CB_BAF_Husky_Logistics_GPMG_Green", {150,50,50}, ""},
				{"UK3CB_BAF_Husky_Logistics_HMG_Green", {150,50,75}, ""},
				{"UK3CB_BAF_Husky_Logistics_GMG_Green", {150,50,75}, ""},
				{"UK3CB_BAF_Panther_GPMG_Green_A", {150,50,50}, ""},

				{"UK3CB_BAF_MAN_HX60_Cargo_Green_A", {100,100,0}, ""},
				{"UK3CB_BAF_MAN_HX60_Transport_Green", {100,100,0}, ""},

				{"UK3CB_BAF_MAN_HX58_Cargo_Green_A", {120,100,0}, ""},
				{"UK3CB_BAF_MAN_HX58_Transport_Green", {120,100,0}, ""}
			}
		},
		{
			"Heavy Vehicles",
			{
				{"UK3CB_BAF_FV432_Mk3_GPMG_Green", {200,100,150}, ""},
				{"UK3CB_BAF_FV432_Mk3_RWS_Green", {200,100,150}, ""},

				{"UK3CB_BAF_Warrior_A3_W", {250,150,250}, ""},
				{"UK3CB_BAF_Warrior_A3_W_Camo", {250,150,250}, ""},
				{"UK3CB_BAF_Warrior_A3_W_Cage", {250,150,250}, ""},
				{"UK3CB_BAF_Warrior_A3_W_Cage_Camo", {250,150,250}, ""},

				{"rhsusf_m1a1aim_tuski_wd", {400,200,400}, "DT_globalReputation > 25 && {call DT_fnc_getMissionProgress > 0.5}"},

				{"rhsusf_m109_usarmy", {400,200,400}, ""}
			}
		},
		{
			"Air Vehicles",
			{
				{"B_UAV_01_F", {50,100,0}, ""},
				{"B_UAV_06_F", {75,100,0}, ""},
				{"UK3CB_BAF_MQ9_Reaper", {300,200,200}, "missionNamespace getVariable ['DT_canPurchaseAir',false] isNotEqualTo [] && {DT_globalReputation > 50 && {call DT_fnc_getMissionProgress > 0.35}}"},

				{"UK3CB_BAF_Wildcat_AH1_CAS_6A", {250,150,250}, "missionNamespace getVariable ['DT_canPurchaseAir',false] isNotEqualTo [] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},
				{"UK3CB_BAF_Wildcat_AH1_CAS_6B", {250,150,250}, "missionNamespace getVariable ['DT_canPurchaseAir',false] isNotEqualTo [] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},
				{"UK3CB_BAF_Wildcat_AH1_CAS_6C", {250,150,250}, "missionNamespace getVariable ['DT_canPurchaseAir',false] isNotEqualTo [] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},
				{"UK3CB_BAF_Wildcat_AH1_CAS_6D", {250,150,250}, "missionNamespace getVariable ['DT_canPurchaseAir',false] isNotEqualTo [] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},
				{"UK3CB_BAF_Wildcat_AH1_HEL_6A", {250,150,250}, "missionNamespace getVariable ['DT_canPurchaseAir',false] isNotEqualTo [] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},

				{"UK3CB_BAF_Wildcat_AH1_TRN_8A", {250,150,250}, "missionNamespace getVariable ['DT_canPurchaseAir',false] isNotEqualTo [] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},
				{"UK3CB_BAF_Wildcat_AH1_CAS_8A", {250,150,250}, "missionNamespace getVariable ['DT_canPurchaseAir',false] isNotEqualTo [] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},
				{"UK3CB_BAF_Wildcat_AH1_CAS_8B", {250,150,250}, "missionNamespace getVariable ['DT_canPurchaseAir',false] isNotEqualTo [] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},
				{"UK3CB_BAF_Wildcat_AH1_CAS_8C", {250,150,250}, "missionNamespace getVariable ['DT_canPurchaseAir',false] isNotEqualTo [] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},
				{"UK3CB_BAF_Wildcat_AH1_CAS_8D", {250,150,250}, "missionNamespace getVariable ['DT_canPurchaseAir',false] isNotEqualTo [] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},
				{"UK3CB_BAF_Wildcat_AH1_HEL_8A", {250,150,250}, "missionNamespace getVariable ['DT_canPurchaseAir',false] isNotEqualTo [] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},

				{"UK3CB_BAF_Merlin_HC3_18", {250,150,0}, "missionNamespace getVariable ['DT_canPurchaseAir',false] isNotEqualTo [] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},
				{"UK3CB_BAF_Merlin_HC3_24", {250,150,0}, "missionNamespace getVariable ['DT_canPurchaseAir',false] isNotEqualTo [] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},
				{"UK3CB_BAF_Merlin_HC3_32", {250,150,0}, "missionNamespace getVariable ['DT_canPurchaseAir',false] isNotEqualTo [] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},
				{"UK3CB_BAF_Merlin_HC3_Cargo", {250,150,0}, "missionNamespace getVariable ['DT_canPurchaseAir',false] isNotEqualTo [] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},

				{"UK3CB_BAF_Apache_AH1", {500,200,500}, "missionNamespace getVariable ['DT_canPurchaseAir',false] isNotEqualTo [] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},

				{"RHS_C130J", {600,300,0}, "missionNamespace getVariable ['DT_canPurchaseAir',false] isNotEqualTo [] && {count (missionNamespace getVariable ['DT_currentPlanes',[]]) < DT_maxPlaneCount}"},
				{"RHS_C130J_Cargo", {600,300,0}, "missionNamespace getVariable ['DT_canPurchaseAir',false] isNotEqualTo [] && {count (missionNamespace getVariable ['DT_currentPlanes',[]]) < DT_maxPlaneCount}"}
			}
		},
		{
			"Naval Vehicles",
			{
				{"B_Boat_Transport_01_F", {40,25,0}, ""},
				{"UK3CB_BAF_RHIB_GPMG", {90,20,70}, ""},
				{"UK3CB_BAF_RHIB_HMG", {100,40,70}, ""}
			}
		},
		{
			"Defences",
			{
				{"B_SAM_System_03_F", {400,0,500}, ""},
				{"B_AAA_System_01_F", {400,0,500}, ""},
				{"B_static_AA_F", {100,0,50}, ""}
			}
		},
		{
			"Buildings",
			{
				{"Land_Medevac_house_V1_F", {30,0,0}, ""},

				{"FlagCarrierBAF", {5,0,0}, ""},
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
				{{"UK3CB_BAF_Vehicles_Servicing_Ground_Point", "BAF Servicing Point"}, {200,0,200}, ""},
				{{"UK3CB_BAF_MAN_HX58_Container_Green", "FOB Container"}, {300,500,0}, "(count DT_allFOBs) < (getNumber(missionConfigFile >> 'Settings' >> 'maxFobs'))"},
				{{"UK3CB_BAF_MAN_HX58_Cargo_Green_B", "FOB Truck"}, {350,500,0}, "(count DT_allFOBs) < (getNumber(missionConfigFile >> 'Settings' >> 'maxFobs'))"},

				{{"Land_RepairDepot_01_tan_F", "Recycle Building"}, {250,0,0}, ""},
				{{"B_Radar_System_01_F", "Radar"}, {1000,0,0}, ""},
				{"Land_HelipadSquare_F", {250,0,0}, ""},
				{"Land_HelipadCircle_F", {250,0,0}, ""},
				{"Land_HelipadRescue_F", {250,0,0}, ""},
				{"Land_TentHangar_V1_F", {500,0,0}, ""},

				{"UK3CB_BAF_MAN_HX58_Repair_Green", {250,50,0}, ""},
				{"rhsusf_M977A4_AMMO_usarmy_wd", {200,50,50}, ""},
				{"UK3CB_BAF_MAN_HX58_Fuel_Green", {200,100,0}, ""},

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
		{"staticWeaponCrateCategory","M6 Mortar","large",{50,0,0},{
			{"ACE_EarPlugs",2},
			{"ACE_MapTools",2},
			{"ACE_Vector",2},
			{"UK3CB_BAF_M6",1},
			{"UK3CB_BAF_1Rnd_60mm_Mo_Shells",20},
			{"UK3CB_BAF_1Rnd_60mm_Mo_Smoke_White",10},
			{"UK3CB_BAF_1Rnd_60mm_Mo_AB_Shells",10},
			{"UK3CB_BAF_1Rnd_60mm_Mo_Flare_White",10},
			{"UK3CB_BAF_1Rnd_60mm_Mo_WPSmoke_White",10}
		}},
		{"staticWeaponCrateCategory","L16 Mortar","large",{50,0,0},{
			{"ACE_EarPlugs",2},
			{"ACE_MapTools",2},
			{"ACE_Vector",2},
			{"UK3CB_BAF_L16",1},
			{"UK3CB_BAF_L16_Tripod",1},
			{"UK3CB_BAF_1Rnd_81mm_Mo_Shells",10},
			{"UK3CB_BAF_1Rnd_81mm_Mo_Smoke_White",5},
			{"UK3CB_BAF_1Rnd_81mm_Mo_WPSmoke_White",5},
			{"UK3CB_BAF_1Rnd_81mm_Mo_Flare_White",5},
			{"UK3CB_BAF_1Rnd_81mm_Mo_IRFlare_White",5}
		}},
		{"staticWeaponCrateCategory","L111A1 HMG","large",{50,0,0},{
			{"ACE_EarPlugs",2},
			{"UK3CB_BAF_L111A1",1},
			{"UK3CB_BAF_Tripod",1},
			{"UK3CB_BAF_127_100Rnd",5}
		}},
		{"staticWeaponCrateCategory","L134A1 HMG","large",{50,0,0},{
			{"ACE_EarPlugs",2},
			{"UK3CB_BAF_L134A1",1},
			{"UK3CB_BAF_Tripod",1},
			{"UK3CB_BAF_32Rnd_40mm_G_Box",5}
		}},
		{"lightWeaponCrateCategory","Light AT","medium",{75,0,0},{
			{"ACE_EarPlugs",2},
			{"ACE_Vector",2},
			{"rhs_weap_M136_hp",4},
			{"rhs_weap_M136",4},
			{"rhs_weap_M136_hedp",2}
		}},
		{"lightWeaponCrateCategory","Standard Resupply","medium",{50,0,0},{
			{"UK3CB_BAF_556_30Rnd",20},
			{"UK3CB_BAF_556_30Rnd_T",10},
			{"UK3CB_BAF_762_L42A1_20Rnd",20},
			{"UK3CB_BAF_762_L42A1_20Rnd_T",10},
			{"UK3CB_BAF_338_5Rnd",10},
			{"UK3CB_BAF_338_5Rnd_Tracer",5},
			{"UK3CB_BAF_556_200Rnd",5},
			{"UK3CB_BAF_762_200Rnd",5},
			{"rhs_mag_m18_purple",5},
			{"rhs_mag_m18_red",5},
			{"rhs_mag_m18_blue",5},
			{"rhs_mag_m18_green",5},
			{"rhs_mag_m67",10}
		}},
		{"miscWeaponCrateCategory","Raven","small",{50,0,50},{
			{"B_rhsusf_B_BACKPACK",1}
		}},
		{"miscWeaponCrateCategory","Empty Crate (Small)","small",{5,0,0},{

		}},
		{"miscWeaponCrateCategory","Empty Crate (Medium)","medium",{5,0,0},{

		}},
		{"heavyWeaponCrateCategory","Javelin","medium",{50,0,50},{
			{"UK3CB_BAF_Javelin_CLU",1},
			{"UK3CB_BAF_Javelin_Slung_Tube",5}
		}},
		{"heavyWeaponCrateCategory","Javelin Ammo","medium",{0,0,75},{
			{"UK3CB_BAF_Javelin_Slung_Tube",10}
		}}
	};
};