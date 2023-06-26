class DT_supportMenu : RscDisplayTeamSwitch
{
	idd=9646;
	name="DT_supportMenu";
	movingEnable=0;
	onLoad = "";
	onUnload = "deleteMarkerLocal ""supportTarget""";
	class Controls : Controls
	{
		class Title : CA_TSTitle
		{
			text = "Support Menu";
		};
		class SupportList : RscTree
		{
			idc = 1500;
			onTreeSelChanged = "_this call DT_fnc_onSupportMenuTvChange;";
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "15 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "20.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class SupportMap: RscMapControl
		{
			idc = 1205;
			x = 0.45875 * safezoneW + safezoneX;
			y = 0.376248 * safezoneH + safezoneY;
			w = 0.273281 * safezoneW;
			h = 0.341 * safezoneH;
			onMouseButtonDown = "_this call DT_fnc_onSupportMapPress";
		};
		class CancelBtn : CA_ButtonCancel
		{
			text = "$STR_DISP_CANCEL";
		};
		class SelectSupportBtn : CA_ButtonContinue
		{
			idc = 2400;
			text = "Select";
			onButtonClick = "[] call DT_fnc_startSupport;";
		};
		class SupportText: RscStructuredText
		{
			idc = 1100;
			x = 0.45875 * safezoneW + safezoneX;
			y = 0.28 * safezoneH + safezoneY;
			w = 0.273281 * safezoneW;
			h = 0.088 * safezoneH;
		};
	};
};