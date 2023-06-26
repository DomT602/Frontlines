class Dynamic_Groups { //format: {"Group Name",{"Group","Roles","Matching","Role","Configs"},"Conditions for the group to be shown","SW TFAR/ACRE Freq","LR TFAR/ACRE Freq"}
	faction_name = "CTRG";
	group_setup[] = {
		{"Command",{"officer","medic","uavop"},"true","40","30"},
		{"Alpha",{"squadlead","teamlead","medic","rifleman","rifleman","teamlead","engineer","rifleman","rifleman"},"true","50","31"},
		{"Bravo",{"squadlead","teamlead","medic","rifleman","rifleman","teamlead","engineer","rifleman","rifleman"},"count playableUnits > 5","51","31"},
		{"Charlie",{"squadlead","teamlead","medic","rifleman","rifleman","teamlead","engineer","rifleman","rifleman"},"count playableUnits > 15","52","31"},
		{"Delta",{"squadlead","teamlead","medic","rifleman","rifleman","teamlead","engineer","rifleman","rifleman"},"count playableUnits > 25","53","31"},
		{"Raptor",{"pilot","pilot"},"true","60","32"},
		{"Spectre",{"pilot","pilot"},"count playableUnits > 10","60","32"},
		{"Warpig",{"commander","crewman","crewman"},"true","61","33"},
		{"Black Widow",{"commander","crewman","crewman"},"count playableUnits > 14","61","33"},
		{"FSG",{"squadlead","rifleman","rifleman"},"true","62","33"}
	};
};

#include "Config_Roles.hpp"
#include "Config_Logi.hpp"