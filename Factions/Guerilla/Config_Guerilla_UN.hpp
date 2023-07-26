/*
	Faction: UN
	Author: Damo3D
	Requires: Project Opfor
*/
class Guerilla_Setup {
	guerillaSquads[] = {
		{
			"LOP_UN_Infantry_SL",
			"LOP_UN_Infantry_MG",
			"LOP_UN_Infantry_MG_Asst",
			"LOP_UN_Infantry_Rifleman",
			"LOP_UN_Infantry_Rifleman_2",
			"LOP_UN_Infantry_GL",
			"LOP_UN_Infantry_AT",
			"LOP_UN_Infantry_AA",
			"LOP_UN_Infantry_GL"
		};
	};

	guerillaVehicles[] = {
		"LOP_UN_Offroad",
		"LOP_UN_UAZ_DshKM",
		"LOP_UN_BTR70"
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
