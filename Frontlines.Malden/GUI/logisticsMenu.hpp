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

			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "15 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "10.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class LogisticsMap: RscMapControl
		{
			idc = 1200;
			onMouseButtonDown = "_this call DT_fnc_onFactoryMapPress";

			x = "16.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "22.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
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
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "13 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "15 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "9.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class LogisticsSecondaryText: RscStructuredText
		{
			idc = 1101;
			x = "16.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "13 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "22.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "9.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class BuyTruckButton: CA_ButtonViewUnit
		{
			idc = 2400;
			onButtonClick = "[player] remoteExecCall ['DT_fnc_buyNewTruck',2];";
			text = "Buy Truck"; //--- ToDo: Localize;
			tooltip = "A truck costs 100 resources to build at your nearest FOB"; //--- ToDo: Localize;
		};
		class RscCombo_2100: RscCombo
		{
			idc = 2100; 
			onLBSelChanged = "_this call DT_fnc_onLogisticsMenuComboChange";
			x = "16.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "10.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "Pickup location"; //--- ToDo: Localize;
		};
		class RscCombo_2101: RscCombo
		{
			idc = 2101;
			onLBSelChanged = "_this call DT_fnc_onLogisticsMenuComboChange";
			x = "27.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "10.6 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "11 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			tooltip = "Drop-off location"; //--- ToDo: Localize;
		};
		class RscEdit_1400: RscEdit
		{
			idc = 1400;
			text = "0";
			x = "16.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "11.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "7.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0,0.75,0,1};
			tooltip = "Supplies"; //--- ToDo: Localize;
			onKeyUp = "[] call DT_fnc_onLogisticsMenuComboChange";
		};
		class RscEdit_1401: RscEdit
		{
			idc = 1401;
			text = "0";
			x = "23.8 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "11.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "7.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0.75,0.75,0,1};
			tooltip = "Fuel"; //--- ToDo: Localize;
			onKeyUp = "[] call DT_fnc_onLogisticsMenuComboChange";
		};
		class RscEdit_1402: RscEdit
		{
			idc = 1402;
			text = "0";
			x = "31.3 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "11.9 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "7.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
			colorText[] = {0.75,0,0,1};
			tooltip = "Ammo"; //--- ToDo: Localize;
			onKeyUp = "[] call DT_fnc_onLogisticsMenuComboChange";
		};
	};
};