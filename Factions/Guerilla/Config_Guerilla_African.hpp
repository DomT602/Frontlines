/*
	Faction: African Guerillas
	Author: Stanhope
	Requires: Project Opfor
*/
class Guerilla_Setup {
	guerillaSquads[] = {
		{
			"LOP_AFR_Infantry_SL",
			"LOP_AFR_Infantry_AR_2",
			"LOP_AFR_Infantry_Marksman",
			"LOP_AFR_Infantry_AT",
			"LOP_AFR_Infantry_Corpsman",
			"LOP_AFR_Infantry_Rifleman_8",
			"LOP_AFR_Infantry_Rifleman_2",
			"LOP_AFR_Infantry_GL"
		};
	};

	guerillaVehicles[] = {
		"LOP_AFR_Landrover_M2",
		"LOP_AFR_Landrover_SPG9"
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
