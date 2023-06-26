class DT_environmentControlMenu
{
	idd=9644;
	name="DT_environmentControlMenu";
	movingEnable=0;
	onLoad = "";
	onUnload = "";
	class controls {
		class MainTitleBackground: RscText
		{
			idc = 1080;
			x = 0.441219 * safezoneW + safezoneX;
			y = 0.291 * safezoneH + safezoneY;
			w = 0.118594 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
		};
		class MainBackground: RscText
		{
			idc = 1082;
			x = 0.441219 * safezoneW + safezoneX;
			y = 0.3152 * safezoneH + safezoneY;
			w = 0.118594 * safezoneW;
			h = 0.374 * safezoneH;
			colorBackground[] = {0,0,0,0.7};
		};
		class Title: RscText
		{
			idc = 1002;
			text = "$STR_A3_CFGEDITORCATEGORIES_EDCAT_ENVIRONMENT0";
			x = 0.441219 * safezoneW + safezoneX;
			y = 0.291 * safezoneH + safezoneY;
			w = 0.118594 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class CancelBtn: RscButtonMenu
		{
			idc = 1004;
			text = "$STR_DISP_CANCEL";
			onButtonClick = "closeDialog 0";
			x = 0.441219 * safezoneW + safezoneX;
			y = 0.6914 * safezoneH + safezoneY;
			w = 0.059297 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class UpdateBtn: RscButtonMenu
		{
			idc = 2400;
			onButtonClick = "[] call DT_fnc_updateEnvironment;";
			text = "$STR_A3_RSCDISPLAYPUBLISHMISSION_BUTTONDOUPDATE";
			x = 0.500516 * safezoneW + safezoneX;
			y = 0.6914 * safezoneH + safezoneY;
			w = 0.059297 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscText_1003: RscText
		{
			idc = -1;
			text = "$STR_A3_CFGVEHICLES_MODULEDATE_F_ARGUMENTS_SKIPTIME_0";
			x = 0.443281 * safezoneW + safezoneX;
			y = 0.324 * safezoneH + safezoneY;
			w = 0.0567187 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscText_1006: RscText_1003
		{
			text = "Wind Direction"; //--- ToDo: Localize;
			y = 0.357 * safezoneH + safezoneY;
		};
		class RscText_1007: RscText_1003
		{
			text = "Wind Speed"; //--- ToDo: Localize;
			y = 0.39 * safezoneH + safezoneY;
		};
		class RscText_1008: RscText_1003
		{
			text = "Gusts"; //--- ToDo: Localize;
			y = 0.423 * safezoneH + safezoneY;
		};
		class RscText_1009: RscText_1003
		{
			text = "Lightning"; //--- ToDo: Localize;
			y = 0.456 * safezoneH + safezoneY;
		};
		class RscText_1010: RscText_1003
		{
			text = "Waves"; //--- ToDo: Localize;
			y = 0.489 * safezoneH + safezoneY;
		};
		class RscText_1011: RscText_1003
		{
			text = "Overcast"; //--- ToDo: Localize;
			y = 0.555 * safezoneH + safezoneY;
		};
		class RscText_1012: RscText_1003
		{
			text = "Rain"; //--- ToDo: Localize;
			y = 0.522 * safezoneH + safezoneY;
		};
		class RscText_1013: RscText_1003
		{
			text = "Fog Value"; //--- ToDo: Localize;
			y = 0.588 * safezoneH + safezoneY;
		};
		class RscText_1014: RscText_1003
		{
			text = "Fog Decay"; //--- ToDo: Localize;
			y = 0.621 * safezoneH + safezoneY;
		};
		class RscText_1015: RscText_1003
		{
			text = "Fog Base"; //--- ToDo: Localize;
			y = 0.654 * safezoneH + safezoneY;
		};
		class RscEdit_1400: RscEdit
		{
			idc = 1400;
			text = "0";
			x = 0.505156 * safezoneW + safezoneX;
			y = 0.324 * safezoneH + safezoneY;
			w = 0.0464063 * safezoneW;
			h = 0.022 * safezoneH;
			maxChars = 2;
		};
		class RscEdit_1401: RscEdit_1400
		{
			idc = 1401;
			y = 0.357 * safezoneH + safezoneY;
			maxChars = 3;
		};
		class RscEdit_1402: RscEdit_1400
		{
			idc = 1402;
			y = 0.39 * safezoneH + safezoneY;
			maxChars = 3;
		};
		class RscEdit_1403: RscEdit_1400
		{
			idc = 1403;
			y = 0.423 * safezoneH + safezoneY;
			maxChars = 3;
		};
		class RscEdit_1404: RscEdit_1400
		{
			idc = 1404;
			y = 0.456 * safezoneH + safezoneY;
			maxChars = 3;
		};
		class RscEdit_1405: RscEdit_1400
		{
			idc = 1405;
			y = 0.489 * safezoneH + safezoneY;
			maxChars = 3;
		};
		class RscEdit_1406: RscEdit_1400
		{
			idc = 1406;
			y = 0.522 * safezoneH + safezoneY;
			maxChars = 3;
		};
		class RscEdit_1407: RscEdit_1400
		{
			idc = 1407;
			y = 0.555 * safezoneH + safezoneY;
			maxChars = 3;
		};
		class RscEdit_1408: RscEdit_1400
		{
			idc = 1408;
			y = 0.588 * safezoneH + safezoneY;
			maxChars = 3;
		};
		class RscEdit_1409: RscEdit_1400
		{
			idc = 1409;
			y = 0.621 * safezoneH + safezoneY;
			maxChars = 4;
		};
		class RscEdit_1410: RscEdit_1400
		{
			idc = 1410;
			y = 0.654 * safezoneH + safezoneY;
			maxChars = 5;
		};
	};
};