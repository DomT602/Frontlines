/*
	Faction: Syndikat
	Author: Dom
	Requires: None
*/
class Guerilla_Setup {
	guerillaSquads[] = {
		{
			"I_C_Soldier_Bandit_1_F",
			"I_C_Soldier_Bandit_2_F",
			"I_C_Soldier_Bandit_3_F",
			"I_C_Soldier_Bandit_4_F",
			"I_C_Soldier_Bandit_5_F",
			"I_C_Soldier_Bandit_6_F",
			"I_C_Soldier_Bandit_7_F",
			"I_C_Soldier_Bandit_8_F"
		};
	};

	guerillaVehicles[] = {
		"I_C_Offroad_02_LMG_F",
		"I_C_Offroad_02_AT_F"
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
