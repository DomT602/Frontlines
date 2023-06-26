class DT_zeusMenu : RscDisplayTeamSwitch
{
	idd=9649;
	name="DT_zeusMenu";
	movingEnable=0;
	onLoad = "";
	onUnload = "";
	class Controls : Controls
	{
		class Title: CA_TSTitle
		{
			text = "Zeus Menu";
		};
		class SectorList: RscListbox
		{
			idc = 1500;
			x = 0.267969 * safezoneW + safezoneX;
			y = 0.28 * safezoneH + safezoneY;
			w = 0.103125 * safezoneW;
			h = 0.22 * safezoneH;
		};
		class FOBList: RscListbox
		{
			idc = 1501;
			x = 0.267969 * safezoneW + safezoneX;
			y = 0.511 * safezoneH + safezoneY;
			w = 0.103125 * safezoneW;
			h = 0.209 * safezoneH;
		};
		class RscEdit_1400: RscEdit
		{
			idc = 1400;
			text = "0";
			x = 0.381406 * safezoneW + safezoneX;
			y = 0.511 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2400: RscButtonMenu
		{
			idc = 2400;
			text = "Activate Sector"; //--- ToDo: Localize;
			onButtonClick="[""activateSector""] call DT_fnc_zeusAction";
			x = 0.381406 * safezoneW + safezoneX;
			y = 0.28 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2401: RscButtonMenu
		{
			idc = 2401;
			text = "Capture Sector"; //--- ToDo: Localize;
			onButtonClick="[""captureSector""] call DT_fnc_zeusAction";
			x = 0.381406 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2402: RscButtonMenu
		{
			idc = 2402;
			text = "Lose Sector"; //--- ToDo: Localize;
			onButtonClick="[""loseSector""] call DT_fnc_zeusAction";
			x = 0.381406 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2403: RscButtonMenu
		{
			idc = 2403;
			text = "Call Reinforcements"; //--- ToDo: Localize;
			onButtonClick="[""callReinforcements""] call DT_fnc_zeusAction";
			x = 0.381406 * safezoneW + safezoneX;
			y = 0.379 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2404: RscButtonMenu
		{
			idc = 2404;
			text = "Add Supplies"; //--- ToDo: Localize;
			onButtonClick="[""adjustResources"",0] call DT_fnc_zeusAction";
			x = 0.381406 * safezoneW + safezoneX;
			y = 0.544 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2405: RscButtonMenu
		{
			idc = 2405;
			text = "Add Fuel"; //--- ToDo: Localize;
			onButtonClick="[""adjustResources"",1] call DT_fnc_zeusAction";
			x = 0.381406 * safezoneW + safezoneX;
			y = 0.577 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2406: RscButtonMenu
		{
			idc = 2406;
			text = "Add Ammo"; //--- ToDo: Localize;
			onButtonClick="[""adjustResources"",2] call DT_fnc_zeusAction";
			x = 0.381406 * safezoneW + safezoneX;
			y = 0.61 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2407: RscButtonMenu
		{
			idc = 2407;
			text = "Destroy AA"; //--- ToDo: Localize;
			onButtonClick="[""destroyAA""] call DT_fnc_zeusAction";
			x = 0.618594 * safezoneW + safezoneX;
			y = 0.28 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2408: RscButtonMenu
		{
			idc = 2408;
			text = "Destroy Jammer"; //--- ToDo: Localize;
			onButtonClick="[""destroyJammer""] call DT_fnc_zeusAction";
			x = 0.618594 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2409: RscButtonMenu
		{
			idc = 2409;
			text = "FOB Assault"; //--- ToDo: Localize;
			onButtonClick="[""fobAssault""] call DT_fnc_zeusAction";
			x = 0.618594 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2410: RscButtonMenu
		{
			idc = 2410;
			text = "Convoy Ambush"; //--- ToDo: Localize;
			onButtonClick="[""convoyAmbush""] call DT_fnc_zeusAction";
			x = 0.618594 * safezoneW + safezoneX;
			y = 0.379 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2411: RscButtonMenu
		{
			idc = 2411;
			text = "Repair Request"; //--- ToDo: Localize;
			onButtonClick="[""repairRequest""] call DT_fnc_zeusAction";
			x = 0.618594 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2412: RscButtonMenu
		{
			idc = 2412;
			text = "Counter-Attack"; //--- ToDo: Localize;
			onButtonClick="[""sectorCounterAttack""] call DT_fnc_zeusAction";
			x = 0.618594 * safezoneW + safezoneX;
			y = 0.445 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2413: RscButtonMenu
		{
			idc = 2413;
			text = "Update Threat"; //--- ToDo: Localize;
			onButtonClick="[""adjustThreat""] call DT_fnc_zeusAction";
			x = 0.381406 * safezoneW + safezoneX;
			y = 0.643 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2414: RscButtonMenu
		{
			idc = 2414;
			text = "Update Intel"; //--- ToDo: Localize;
			onButtonClick="[""adjustIntel""] call DT_fnc_zeusAction";
			x = 0.381406 * safezoneW + safezoneX;
			y = 0.676 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2415: RscButtonMenu
		{
			idc = 2415;
			text = "Update Civ Rep"; //--- ToDo: Localize;
			onButtonClick="[""adjustCivRep""] call DT_fnc_zeusAction";
			x = 0.381406 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2416: RscButtonMenu
		{
			idc = 2416;
			text = "Force Save"; //--- ToDo: Localize;
			onButtonClick="[""forceSave""] call DT_fnc_zeusAction";
			x = 0.5 * safezoneW + safezoneX;
			y = 0.28 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2417: RscButtonMenu
		{
			idc = 2417;
			text = "Wipe Save"; //--- ToDo: Localize;
			onButtonClick="[""wipeSave""] spawn DT_fnc_zeusAction";
			x = 0.5 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
			colorBackground[]={0.52899998,0,0,1};
		};
		class RscButtonMenu_2418: RscButtonMenu
		{
			idc = 2418;
			text = "Toggle Damage"; //--- ToDo: Localize;
			onButtonClick="[""allowDamage""] call DT_fnc_zeusAction";
			x = 0.5 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2419: RscButtonMenu
		{
			idc = 2419;
			text = "Heal/Fix Self"; //--- ToDo: Localize;
			onButtonClick="[""heal""] call DT_fnc_zeusAction";
			x = 0.5 * safezoneW + safezoneX;
			y = 0.379 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2420: RscButtonMenu
		{
			idc = 2420;
			text = "Full Arsenal"; //--- ToDo: Localize;
			onButtonClick="[""openArsenal""] call DT_fnc_zeusAction";
			x = 0.5 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2421: RscButtonMenu
		{
			idc = 2421;
			text = "Hide Player Object"; //--- ToDo: Localize;
			onButtonClick="[""hideObject""] call DT_fnc_zeusAction";
			x = 0.5 * safezoneW + safezoneX;
			y = 0.445 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2422: RscButtonMenu
		{
			idc = 2422;
			text = "Clear Smoke"; //--- ToDo: Localize;
			onButtonClick="[""clearSmoke""] call DT_fnc_zeusAction";
			x = 0.5 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class RscButtonMenu_2423: RscButtonMenu
		{
			idc = 2423;
			text = "Clear Mines"; //--- ToDo: Localize;
			onButtonClick="[""clearMines""] call DT_fnc_zeusAction";
			x = 0.5 * safezoneW + safezoneX;
			y = 0.511 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.022 * safezoneH;
		};
	};
};