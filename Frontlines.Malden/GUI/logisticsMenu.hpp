class DT_logisticsMenu : RscDisplayTeamSwitch
{
	idd=9645;
	name="DT_logisticsMenu";
	movingEnable=0;
	onLoad = "";
	onUnload = "";
	class Controls : Controls
	{
		class Title : CA_TSTitle
		{
			text = "Logistics Menu";
		};
		class LogisticsList: RscListbox
		{
			idc = 1500;
			onLbSelChanged = "_this call DT_fnc_onLogisticsMenuLbChange;";

			x = 0.273125 * safezoneW + safezoneX;
			y = 0.28 * safezoneH + safezoneY;
			w = 0.180469 * safezoneW;
			h = 0.22 * safezoneH;
		};
		class LogisticsMap: RscMapControl
		{
			idc = 1200;
			onMouseButtonDown = "_this call DT_fnc_onFactoryMapPress";

			x = 0.45875 * safezoneW + safezoneX;
			y = 0.28 * safezoneH + safezoneY;
			w = 0.273281 * safezoneW;
			h = 0.154 * safezoneH;
		};
		class CancelBtn : CA_ButtonCancel
		{
			text = "$STR_DISP_CANCEL";
		};
		class SelectBtn: CA_ButtonContinue
		{
			idc = 2401;
			onButtonClick = "[] call DT_fnc_logisticsMenuStartRoute;";
			text = "Start Route"; //--- ToDo: Localize;
		};
		class LogisticsText: RscStructuredText
		{
			idc = 1100;

			x = 0.273124 * safezoneW + safezoneX;
			y = 0.511 * safezoneH + safezoneY;
			w = 0.180469 * safezoneW;
			h = 0.209 * safezoneH;
		};
		class LogisticsSecondaryText: RscStructuredText
		{
			idc = 1101;

			x = 0.45875 * safezoneW + safezoneX;
			y = 0.511 * safezoneH + safezoneY;
			w = 0.273281 * safezoneW;
			h = 0.209 * safezoneH;
		};
		class BuyTruckButton: CA_ButtonContinue
		{
			idc = 2400;
			onButtonClick = "[] call DT_fnc_buyNewTruck;";
			text = "Buy Truck"; //--- ToDo: Localize;
			x = 0.577344 * safezoneW + safezoneX;
			y = 0.731 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = "A truck costs 100 resources to build"; //--- ToDo: Localize;
		};
		class RscCombo_2100: RscCombo
		{
			idc = 2100; 
			onLBSelChanged = "_this call DT_fnc_onLogisticsMenuComboChange";
			x = 0.45875 * safezoneW + safezoneX;
			y = 0.445 * safezoneH + safezoneY;
			w = 0.128906 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = "Pickup location"; //--- ToDo: Localize;
		};
		class RscCombo_2101: RscCombo
		{
			idc = 2101;
			onLBSelChanged = "_this call DT_fnc_onLogisticsMenuComboChange";
			x = 0.603125 * safezoneW + safezoneX;
			y = 0.445 * safezoneH + safezoneY;
			w = 0.128906 * safezoneW;
			h = 0.022 * safezoneH;
			tooltip = "Drop-off location"; //--- ToDo: Localize;
		};
		class RscEdit_1400: RscEdit
		{
			idc = 1400;
			text = "0";
			x = 0.45875 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {0,0.75,0,1};
			tooltip = "Supplies"; //--- ToDo: Localize;
			onKeyUp = "[] call DT_fnc_onLogisticsMenuComboChange";
		};
		class RscEdit_1401: RscEdit
		{
			idc = 1401;
			text = "0";
			x = 0.551562 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {0.75,0.75,0,1};
			tooltip = "Fuel"; //--- ToDo: Localize;
			onKeyUp = "[] call DT_fnc_onLogisticsMenuComboChange";
		};
		class RscEdit_1402: RscEdit
		{
			idc = 1402;
			text = "0";
			x = 0.644375 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {0.75,0,0,1};
			tooltip = "Ammo"; //--- ToDo: Localize;
			onKeyUp = "[] call DT_fnc_onLogisticsMenuComboChange";
		};
	};
};