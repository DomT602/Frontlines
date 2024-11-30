class Dynamic_Groups { //format: {"Group Name",{"Group","Roles","Matching","Role","Configs"},"Conditions for the group to be shown","SW TFAR/ACRE Freq","LR TFAR/ACRE Freq"}
	faction_name = "AAF";
	group_setup[] = {
		{"Command",{"officer","medic","uavop"},"true","40","30"},
		{"Alpha",{"squadlead","teamlead","medic","rifleman","rifleman","teamlead","engineer","rifleman","rifleman"},"true","50","30"},
		{"Beta",{"squadlead","teamlead","medic","rifleman","rifleman","teamlead","engineer","rifleman","rifleman"},"count playableUnits > 5","51","30"},
		{"Gamma",{"squadlead","teamlead","medic","rifleman","rifleman","teamlead","engineer","rifleman","rifleman"},"count playableUnits > 15","52","30"},
		{"Delta",{"squadlead","teamlead","medic","rifleman","rifleman","teamlead","engineer","rifleman","rifleman"},"count playableUnits > 25","53","30"},
		{"Athena",{"pilot","pilot"},"true","60","30"},
		{"Apollo",{"pilot","pilot"},"count playableUnits > 10","60","30"},
		{"Zeus",{"commander","crewman","crewman"},"true","61","30"},
		{"Hera",{"commander","crewman","crewman"},"count playableUnits > 14","61","30"},
		{"FSG",{"squadlead","rifleman","rifleman"},"true","62","30"}
	};
};

#include "Config_Roles.hpp"
#include "Config_Logi.hpp"