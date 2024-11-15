/*
	Faction: AAF
	Author: TacticalError, Rickard
*/
class pilot {
	name = $STR_B_PILOT_F0;
	rank = "Lieutenant";
	description = $STR_DT_Pilot_Description;
	traits[] = {

	};
	customVariables[] = {
		{"ace_isEngineer",1,true},
		{"ACE_GForceCoef",0.55,false}
	};
	icon = "a3\ui_f\data\map\vehicleicons\iconManOfficer_ca.paa";

	defaultLoadout[] = {
		{},{},{"rhsusf_weap_glock17g4","","","",{"rhsusf_mag_17Rnd_9x19_FMJ",17},{},""},{"U_I_pilotCoveralls",{{"ACE_adenosine",1},{"ACE_packingBandage",10},{"ACE_EarPlugs",1},{"ACE_epinephrine",1},{"ACE_MapTools",1},{"ACE_morphine",1},{"ACE_splint",1},{"ACE_tourniquet",2},{"rhsusf_mag_17Rnd_9x19_FMJ",3,17},{"rhs_mag_m18_purple",1,1}}},{},{"B_Parachute",{}},"H_PilotHelmetFighter_I","",{"Binocular","","","",{},{},""},{"ItemMap","","TFAR_anprc152","ItemCompass","ItemWatch",""}
	};

	arsenalItems[] = {
		
	};
};