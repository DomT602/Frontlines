/*
	Faction: CTRG
	Author: Dom
	Requires: TFAR
*/
class Logi_Setup {
	fobBuilding = "Land_Cargo_HQ_V1_F";

	bluforCrates[] = {
		"CargoNet_01_box_F", //supplies
		"CargoNet_01_barrels_F", //fuel
		"B_CargoNet_01_ammo_F" //ammo
	};

	fobBoxes[] = { //vehicles that FOBs can be created from
		"B_Slingload_01_Cargo_F",
		"B_Truck_01_box_F"
	};

	mobileRespawns[] = { //vehicles that act as mobile respawns
		"B_Truck_01_medical_F",
		"B_Heli_Transport_03_unarmed_F"
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
				{"B_Quadbike_01_F", {50,25,0}, ""},

				{"B_Truck_01_transport_F", {200,50,0}, ""},

				{"B_MRAP_01_F", {100,25,0}, ""},
				{"B_MRAP_01_gmg_F", {150,50,75}, ""},
				{"B_MRAP_01_hmg_F", {150,50,50}, ""},
				{"B_CTRG_LSV_01_light_F", {75,25,0}, ""}
			}
		},
		{
			"Heavy Vehicles",
			{
				{"B_UGV_01_rcws_F", {400,150,200}, ""},

				{"B_APC_Tracked_01_CRV_F", {300,200,200}, ""},

				{"B_APC_Wheeled_01_cannon_F", {300,150,250}, ""},
				{"B_APC_Tracked_01_AA_F", {400,200,400}, ""}
			}
		},
		{
			"Air Vehicles",
			{
				{"B_UAV_01_F", {50,100,0}, ""},
				{"B_UAV_06_F", {75,100,0}, ""},
				{"B_UAV_02_dynamicLoadout_F", {300,200,200}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {DT_globalReputation > 25 && {call DT_fnc_getMissionProgress > 0.35}}"},
				{"B_UAV_05_F", {300,300,250}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {DT_globalReputation > 25 && {call DT_fnc_getMissionProgress > 0.35}}"},
				{"B_T_UAV_03_dynamicLoadout_F", {500,300,350}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {DT_globalReputation > 25 && {call DT_fnc_getMissionProgress > 0.35 && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}}}"},

				{"B_Heli_Light_01_F", {200,150,0}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},                      
				{"B_Heli_Light_01_dynamicLoadout_F", {250,150,150}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},
				
				{"B_Heli_Transport_03_F", {300,200,250}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},							
				{"B_Heli_Transport_01_F", {200,200,100}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},
				{"B_CTRG_Heli_Transport_01_sand_F", {200,200,100}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},
				{"B_CTRG_Heli_Transport_01_tropic_F", {200,200,100}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentHelicopters',[]]) < DT_maxHelicopterCount}"},   

				{"B_T_VTOL_01_infantry_F", {600,300,0}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentPlanes',[]]) < DT_maxPlaneCount}"},
				{"B_T_VTOL_01_vehicle_F", {600,300,0}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentPlanes',[]]) < DT_maxPlaneCount}"},
				{"B_T_VTOL_01_armed_F", {600,300,700}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentPlanes',[]]) < DT_maxPlaneCount}"}, 
				
				{"B_Plane_Fighter_01_F", {900,800,800}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentPlanes',[]]) < DT_maxPlaneCount && {call DT_fnc_getMissionProgress > 0.4}}"},
				{"B_Plane_CAS_01_dynamicLoadout_F", {800,800,900}, "missionNamespace getVariable ['DT_canPurchaseAir',false] && {count (missionNamespace getVariable ['DT_currentPlanes',[]]) < DT_maxPlaneCount && {call DT_fnc_getMissionProgress > 0.35}}"}
			}
		},
		{
			"Naval Vehicles",
			{
				{"B_Boat_Armed_01_minigun_F", {200,75,100}, ""},
				{"B_Boat_Transport_01_F", {100,25,0}, ""},
				{"B_SDV_01_F", {100,25,0}, ""}
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

				{"Flag_CTRG_F", {5,0,0}, ""},
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
				{{"B_Slingload_01_Cargo_F", "FOB Container"}, {300,500,0}, "(count DT_allFOBs) < (getNumber(missionConfigFile >> 'Settings' >> 'maxFobs'))"},
				{{"B_Truck_01_box_F", "FOB Truck"}, {350,500,0}, "(count DT_allFOBs) < (getNumber(missionConfigFile >> 'Settings' >> 'maxFobs'))"},

				{{"Land_RepairDepot_01_tan_F", "Recycle Building"}, {250,0,0}, ""},
				{{"B_Radar_System_01_F", "Radar"}, {1000,0,0}, ""},
				{"Land_HelipadSquare_F", {250,0,0}, ""},
				{"Land_HelipadCircle_F", {250,0,0}, ""},
				{"Land_HelipadRescue_F", {250,0,0}, ""},
				{"Land_TentHangar_V1_F", {500,0,0}, ""},
				
				{"B_Truck_01_repair_F", {250,50,0}, ""},
				{"B_Truck_01_ammo_F", {200,50,50}, ""},
				{"B_Truck_01_fuel_F", {200,100,0}, ""},

				{{"B_Truck_01_medical_F","Mobile Respawn Vehicle"}, {200,100,0}, ""},
				{{"B_Heli_Transport_03_unarmed_F","Mobile Respawn Helicopter"}, {200,100,100}, ""},

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
		{"large", "Box_NATO_WpsSpecial_F"},
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
		{"staticWeaponCrateCategory","Mk6 Mortar","large",{50,0,0},{
			{"ACE_EarPlugs",2},
			{"ACE_MapTools",2},
			{"ACE_Vector",2},
			{"ACE_artilleryTable",2},
			{"B_Mortar_01_weapon_F",2},
			{"B_Mortar_01_support_F",2}
		}},
		{"staticWeaponCrateCategory","Mk30 HMG","large",{50,0,0},{
			{"ACE_EarPlugs",2},
			{"B_HMG_01_weapon_F",1},
			{"B_HMG_01_high_weapon_F",1},
			{"B_HMG_01_support_F",1},
			{"B_HMG_01_support_high_F",1}
		}},
		{"staticWeaponCrateCategory","Mk32 GMG","large",{50,0,0},{
			{"ACE_EarPlugs",2},
			{"B_GMG_01_high_weapon_F",1},
			{"B_GMG_01_weapon_F",1},
			{"B_HMG_01_support_F",1},
			{"B_HMG_01_support_high_F",1}
		}},
		{"lightWeaponCrateCategory","Standard Resupply","medium",{50,0,0},{
			{"30Rnd_65x39_caseless_mag",25},
			{"30Rnd_556x45_Stanag_Sand",25},
			{"20Rnd_762x51_Mag",20},
			{"100Rnd_65x39_caseless_mag",10},
			{"150Rnd_556x45_Drum_Mag_F",8},
						
			{"HandGrenade",6},
			{"MiniGrenade",6},
			{"SmokeShell",4},
			{"SmokeShellBlue",4},
			{"SmokeShellOrange",4},
			{"1Rnd_HE_Grenade_shell",10},
			{"UGL_FlareGreen_F",10},
			{"UGL_FlareYellow_F",10},
			{"1Rnd_Smoke_Grenade_shell",5},
			{"1Rnd_SmokeRed_Grenade_shell",5}
		}},
		{"miscWeaponCrateCategory","Explosives","small",{75,0,0},{
			{"DemoCharge_Remote_Mag",6},
			{"ACE_Clacker",2},
			{"ACE_DefusalKit",2},
			{"MineDetector",2}
		}},
		{"miscWeaponCrateCategory","Empty Crate (Small)","small",{0,0,0},{

		}},
		{"miscWeaponCrateCategory","Empty Crate (Medium)","medium",{0,0,0},{
			
		}}
	};
};