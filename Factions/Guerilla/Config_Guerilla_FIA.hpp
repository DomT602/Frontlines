/*
	Faction: Freedom and Independence Army
	Author: Dom
	Requires: None
*/
class Guerilla_Setup {
	guerillaSquads[] = {
		{
			"I_G_Soldier_F",
			"I_G_Soldier_lite_F",
			"I_G_Soldier_SL_F",
			"I_G_Soldier_TL_F",
			"I_G_Soldier_AR_F",
			"I_G_medic_F",
			"I_G_engineer_F",
			"I_G_Soldier_exp_F",
			"I_G_Soldier_GL_F",
			"I_G_Soldier_M_F",
			"I_G_Soldier_LAT_F",
			"I_G_Soldier_A_F",
			"I_G_Sharpshooter_F",
			"I_G_officer_F"
		};
	};

	guerillaVehicles[] = {
		"I_G_Offroad_01_armed_F",
		"I_G_Offroad_01_AT_F"
	};

	//format {"Title","actionCode",requiredGlobalCivRep,cooldown in seconds}
	supports[] = {
		{"Infantry Attack","infAttack",40,2700},
		{"Mechanized Attack","mechAttack",50,3600},
		{"Mortar Support","mortar",30,60},
		{"Crate Retrieval","crateRetrieve",25,1200},
		{"Supply Drop","supplyDrop",35,1200},
		{"Sector Defence","sectorDefence",50,5400}
	};
};
