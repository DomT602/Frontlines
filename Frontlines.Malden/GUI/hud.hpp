class DT_HUD {
	idd=-1;
	duration=1e+012;
	onLoad="uiNamespace setVariable [""DT_HUD"",_this select 0]";
	class controls {
		class MainText: RscText
		{
			idc = 1000;
			x = 0.897656 * safezoneW + safezoneX;
			y = 0.225 * safezoneH + safezoneY;
			w = 0.0973437 * safezoneW;
			h = 0.022 * safezoneH;
			style = 0x02;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
		};
		class BarBackground: RscPicture
		{
			idc = 1901;
			text = "#(argb,8,8,3)color(0.5,0,0,1)";
			x = 0.897656 * safezoneW + safezoneX;
			y = 0.25 * safezoneH + safezoneY;
			w = 0.0973437 * safezoneW;
			h = 0.011 * safezoneH;
		};
		class CaptureBar: RscProgress
		{
			idc = 1900;
			x = 0.897656 * safezoneW + safezoneX;
			y = 0.25 * safezoneH + safezoneY;
			w = 0.0973437 * safezoneW;
			h = 0.011 * safezoneH;
			colorBar[]={0,0.3,0.6,1};
		};
	};
};