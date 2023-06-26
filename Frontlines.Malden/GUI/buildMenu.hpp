class DT_buildMenu : RscDisplayTeamSwitch
{
	idd=9641;
	name="DT_buildMenu";
	movingEnable=0;
	onLoad = "";
	onUnload = "";
	class controls : Controls
	{
		class Title : CA_TSTitle
		{
			text = "Build Menu";
		};
		class BuildList : DT_RscTreeSearch
		{
			idc = 1500;
			onTreeSelChanged = "_this call DT_fnc_onBuildMenuTvChange;";
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "2.3 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "15 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "19.4 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class VehicleInformationControlGroup: RscControlsGroup
		{
			delete HScrollBar;

			idc = 1205;

			h = 20.4 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25);
			w = 22.5 * (((safezoneW / safezoneH) min 1.2) / 40);
			x = 16.5 * (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX + (safezoneW - ((safezoneW / safezoneH) min 1.2))/2);
			y = 2.3 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((safezoneW / safezoneH) min 1.2) / 1.2))/2);

			class Controls
			{
				class Information: RscStructuredText
				{
					idc = 1100;
					text = "";
					h = 20.4 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25);
					w = 21.8 * (((safezoneW / safezoneH) min 1.2) / 40);
					x = 0;
					y = 0;

					class Attributes {
						align = "center";
					};
				};
			};
		};
		class CancelBtn : CA_ButtonCancel
		{
			text = "$STR_DISP_CANCEL";
		};
		class SelectVehicleBtn : CA_ButtonContinue
		{
			idc = 2400;
			text = "$STR_A3_RSCDISPLAYDYNAMICGROUPS_BUTTON_CREATE";
			onButtonClick = "[] call DT_fnc_startBuild;";
		};
		class SearchText: RscText
		{
			idc = -1;
			text = "$STR_3DEN_DISPLAY3DEN_MENUBAR_SEARCH_TEXT";
			x = "1.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "21.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "3 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
		class TreeSearch: RscEdit
		{
			idc = 645;
			x = "4.2 * 					(			((safezoneW / safezoneH) min 1.2) / 40) + 		(safezoneX + (safezoneW - 					((safezoneW / safezoneH) min 1.2))/2)";
			y = "21.7 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + 		(safezoneY + (safezoneH - 					(			((safezoneW / safezoneH) min 1.2) / 1.2))/2)";
			w = "12 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
			h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
		};
	};
};