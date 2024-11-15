import RscStructuredText;
import RscTree;
import RscDisplayTeamSwitch;
import RscControlsGroup;
import RscText;
import RscMapControl;
import RscButtonMenu;
import RscListbox;
import RscToolbox;
import RscEdit;
import RscCombo;
import RscProgress;
import RscPicture;

class DT_RscButtonMenu: RscButtonMenu
{
	colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",1};
	colorBackgroundFocused[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",1};
	colorBackgroundActive[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",1};
	colorFocused[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",1};
};

class DT_RscTreeSearch: RscTree
{
	idcSearch=645;
};

class DT_mapButton: RscButtonMenu
{
	idc = -1;
	text = "Mission Status";
	x = 0.914 * safezoneW + safezoneX;
	y = 0.071 * safezoneH + safezoneY;
	w = 0.071 * safezoneW;
	onButtonClick = "call DT_fnc_showMissionInfo";
};

#include "buildMenu.hpp"
#include "crateMenu.hpp"
#include "deployMenu.hpp"
#include "environmentControlMenu.hpp"
#include "factoryMenu.hpp"
#include "groupMenu.hpp"
#include "intelMenu.hpp"
#include "logisticsMenu.hpp"
#include "nameMenu.hpp"
#include "retrieveMenu.hpp"
#include "supportMenu.hpp"
#include "zeusMenu.hpp"