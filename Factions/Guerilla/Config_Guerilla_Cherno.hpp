/*
	Faction: Chernarussian Insurgents
	Author: Stanhope
	Requires: Project Opfor
*/
class Guerilla_Setup {
	guerillaSquads[] = {
		{
			"LOP_NAPA_Infantry_TL",
			"LOP_NAPA_Infantry_MG",
			"LOP_NAPA_Infantry_Marksman",
			"LOP_NAPA_Infantry_AT",
			"LOP_NAPA_Infantry_Corpsman",
			"LOP_NAPA_Infantry_Rifleman_3",
			"LOP_NAPA_Infantry_Rifleman",
			"LOP_NAPA_Infantry_GL_2"
		};
	};

	guerillaVehicles[] = {
		"LOP_NAPA_Landrover_M2"
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
