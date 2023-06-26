class DT_nameMenu
{
	idd=9650;
	name="DT_nameMenu";
	movingEnable=0;
	class controls
	{
		class MainBackground: RscText
		{
			idc = 1082;
			x = 0.422656 * safezoneW + safezoneX;
			y = 0.489 * safezoneH + safezoneY;
			w = 0.154687 * safezoneW;
			h = 0.044 * safezoneH;
			colorBackground[] = {0,0,0,0.7};
		};
		class Title: RscText
		{
			idc = 1002;
			text = "Name Forward Operating Base"; //--- ToDo: Localize;
			x = 0.422656 * safezoneW + safezoneX;
			y = 0.467 * safezoneH + safezoneY;
			w = 0.154687 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
		};
		class SetButton: DT_RscButtonMenu
		{
			idc = 2400;
			onButtonClick = "[] call DT_fnc_nameFob";
			text = "Set"; //--- ToDo: Localize;
			x = 0.422656 * safezoneW + safezoneX;
			y = 0.533 * safezoneH + safezoneY;
			w = 0.154687 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",1};
		};
		class NameEdit: RscEdit
		{
			idc = 1400;
			x = 0.427812 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.022 * safezoneH;
		};
	};
};