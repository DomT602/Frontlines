/*
	Faction: Private Military Contractors
	Author: Stanhope
	Requires: Project Opfor
*/
class Guerilla_Setup {
	guerillaSquads[] = {
		{
			"LOP_PMC_Infantry_SL",
			"LOP_PMC_Infantry_MG",
			"LOP_PMC_Infantry_Marksman",
			"LOP_PMC_Infantry_Rifleman_2",
			"LOP_PMC_Infantry_Corpsman",
			"LOP_PMC_Infantry_Rifleman",
			"LOP_PMC_Infantry_Rifleman_4",
			"LOP_PMC_Infantry_GL"
		};
	};

	guerillaVehicles[] = {
		"LOP_PMC_Offroad_M2"
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
