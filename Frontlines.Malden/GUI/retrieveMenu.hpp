class DT_retrieveMenu
{
	idd=9648;
	name="DT_retrieveMenu";
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
			text = "Retrieve Resource Crates"; //--- ToDo: Localize;
			x = 0.422656 * safezoneW + safezoneX;
			y = 0.467 * safezoneH + safezoneY;
			w = 0.154687 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
		};
		class DeployButton: DT_RscButtonMenu
		{
			idc = 2400;
			onButtonClick = "[] call DT_fnc_retrieveResources";
			text = "Retrieve"; //--- ToDo: Localize;
			x = 0.422656 * safezoneW + safezoneX;
			y = 0.533 * safezoneH + safezoneY;
			w = 0.154687 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])",1};
		};
		class SupplyEdit: RscEdit
		{
			idc = 1400;
			x = 0.427812 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.04125 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {0,0.75,0,1};
			tooltip="Supplies";
		};
		class FuelEdit: SupplyEdit
		{
			idc = 1401;
			x = 0.479375 * safezoneW + safezoneX;
			colorText[] = {0.75,0.75,0,1};
			tooltip="Fuel";
		};
		class AmmoEdit: SupplyEdit
		{
			idc = 1402;
			x = 0.530938 * safezoneW + safezoneX;
			colorText[] = {0.75,0,0,1};
			tooltip="Ammo";
		};
	};
};