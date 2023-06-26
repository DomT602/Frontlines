class DT_factoryMenu : RscDisplayTeamSwitch
{
	idd=9643;
	name="DT_factoryMenu";
	movingEnable=0;
	onLoad = "";
	onUnload = "";
	class Controls : Controls
	{
		class Title : CA_TSTitle
		{
			text = "Factory Menu";
		};
		class FactoryList : RscListbox
		{
			idc = 1500;
			onLbSelChanged = "_this call DT_fnc_onFactoryMenuLbChange;";
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "15 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "20.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class FactoryMap: RscMapControl
		{
			idc = 1200;
			x = 0.456894 * safezoneW + safezoneX;
			y = 0.43114 * safezoneH + safezoneY;
			w = 0.273281 * safezoneW;
			h = 0.286 * safezoneH;
			onMouseButtonDown = "_this call DT_fnc_onFactoryMapPress";
		};
		class CancelBtn : CA_ButtonCancel
		{
			text = "$STR_DISP_CANCEL";
		};
		class ConfirmBtn : CA_ButtonContinue
		{
			idc = 2400;
			text = "Confirm";
			tooltip="Changing the production requires 100 supplies at the factory";
			onButtonClick = "[] call DT_fnc_updateFactory;";
		};
		class FactoryText: RscStructuredText
		{
			idc = 1100;
			x = 0.45875 * safezoneW + safezoneX;
			y = 0.28 * safezoneH + safezoneY;
			w = 0.273281 * safezoneW;
			h = 0.088 * safezoneH;
		};
		class TypeToolbox: RscToolbox
		{
			idc = 1600;
			x = 0.45875 * safezoneW + safezoneX;
			y = 0.379 * safezoneH + safezoneY;
			w = 0.273281 * safezoneW;
			h = 0.044 * safezoneH;
			rows = 1;
			columns = 4;
			strings[] = {"None","Supplies","Fuel","Ammo"};
			values[] = {-1,0,1,2};
		};
	};
};