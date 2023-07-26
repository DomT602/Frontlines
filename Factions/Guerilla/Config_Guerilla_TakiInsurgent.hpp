/*
	Faction: Takistan Insurgents
	Author: Reidy
	Requires: Project Opfor
*/
class Guerilla_Setup {
	guerillaSquads[] = {
		{
			"LOP_AM_Infantry_SL",
			"LOP_AM_Infantry_AR",
			"LOP_AM_Infantry_Marksman",
			"LOP_AM_Infantry_AT",
			"LOP_AM_Infantry_Corpsman",
			"LOP_AM_Infantry_Rifleman",
			"LOP_AM_Infantry_Rifleman_6",
			"LOP_AM_Infantry_GL"
		};
	};

	guerillaVehicles[] = {
		"LOP_AM_Nissan_PKM",
		"LOP_AM_Offroad_M2"
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
