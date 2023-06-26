class DT_deployMenu
{
	idd=9640;
	name="DT_deployMenu";
	movingEnable=0;
	onLoad = "";
	onUnload = "DT_spawnCamera cameraEffect ['terminate','back']; camDestroy DT_spawnCamera;";
	class controls {
		class MainBackground: RscText
		{
			idc = 1082;
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.247 * safezoneH + safezoneY;
			w = 0.154687 * safezoneW;
			h = 0.506 * safezoneH;
			colorBackground[] = {0,0,0,0.7};
		};
		class Title: RscText
		{
			idc = 1002;
			text = "Deployment";
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.225 * safezoneH + safezoneY;
			w = 0.154687 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])","(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"};
		};
		class Tree: RscTree 
		{
			idc = 1500;
			onTreeSelChanged = "_this call DT_fnc_onDeployMenuTvChange;";
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.247 * safezoneH + safezoneY;
			w = 0.154687 * safezoneW;
			h = 0.286 * safezoneH;
		};
		class DeployButton: DT_RscButtonMenu
		{
			idc = 2400;
			onButtonClick = "[] call DT_fnc_deployPlayer";
			text = "Deploy"; //--- ToDo: Localize;
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.753 * safezoneH + safezoneY;
			w = 0.154687 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class DeployMap: RscMapControl
		{
			idc = 1200;
			x = 0.0153125 * safezoneW + safezoneX;
			y = 0.533 * safezoneH + safezoneY;
			w = 0.154687 * safezoneW;
			h = 0.22 * safezoneH;
		};
	};
};