class Dynamic_Roles {
	#include "Config_Officer.hpp"

	#include "Config_Rifleman.hpp"
	#include "Config_Medic.hpp"
	#include "Config_Engineer.hpp"
	#include "Config_TeamLeader.hpp"
	#include "Config_SquadLeader.hpp"

	#include "Config_Pilot.hpp"
	#include "Config_UAVOp.hpp"

	#include "Config_Crewman.hpp"
	#include "Config_Commander.hpp"
};

class Common_Arsenal {
	items[] = {
		"ACE_adenosine", "ACE_epinephrine", "ACE_morphine",
		"ACE_fieldDressing", "ACE_elasticBandage", "ACE_packingBandage", "ACE_quikclot",
		"ACE_bloodIV", "ACE_bloodIV_250", "ACE_bloodIV_500",
		"ACE_plasmaIV", "ACE_plasmaIV_250", "ACE_plasmaIV_500",
		"ACE_salineIV", "ACE_salineIV_250", "ACE_salineIV_500",
		"ACE_tourniquet", "ACE_splint",
		"ACE_surgicalKit","ACE_painkillers","ACE_suture",

		"ACE_Chemlight_HiBlue", "ACE_Chemlight_HiGreen", "ACE_Chemlight_HiRed", "ACE_Chemlight_HiWhite", "ACE_Chemlight_HiYellow", "ACE_Chemlight_UltraHiOrange",
		"Chemlight_blue", "Chemlight_green", "Chemlight_red", "Chemlight_yellow", "acc_flashlight_pistol", "ACE_Flashlight_XL50", "ACE_Flashlight_MX991", "ACE_Flashlight_KSF1",
		"ACE_Chemlight_IR", "ACE_Chemlight_Orange", "ACE_Chemlight_White", "ACE_Chemlight_Shield", "ACE_Chemlight_Shield_Blue", "ACE_Chemlight_Shield_Green", "ACE_Chemlight_Shield_Orange", "ACE_Chemlight_Shield_Red", "ACE_Chemlight_Shield_White", "ACE_Chemlight_Shield_Yellow",
		"ACE_HandFlare_Green", "ACE_HandFlare_Red", "ACE_HandFlare_White", "ACE_HandFlare_Yellow", "ACE_IR_Strobe_Item",
		"SmokeShell", "SmokeShellBlue", "SmokeShellGreen", "SmokeShellOrange", "SmokeShellPurple", "SmokeShellRed", "SmokeShellYellow",
		"HandGrenade", "MiniGrenade",

		"ACE_RangeTable_82mm", "ACE_artilleryTable", "ACE_RangeCard", "ACE_Tripod", "ACE_ATragMX", "ACE_SpareBarrel", "ACE_SpottingScope", "ACE_Kestrel4500",
		"ACE_WaterBottle", "ACE_WaterBottle_Half", "ACE_WaterBottle_Empty",

		"ItemMap","ItemCompass", "ItemWatch", "ItemGPS", "ACE_Altimeter", "ACE_MapTools", "ACE_CableTie", "ACE_EarPlugs", "ACE_microDAGR", "ACE_DAGR",

		"ToolKit", "ACE_DefusalKit","ACE_wirecutter", "ACE_EntrenchingTool", "ACE_Clacker", "ACE_M26_Clacker", "MineDetector", "ACE_SpraypaintRed", "ACE_SpraypaintGreen", "ACE_SpraypaintBlue", "ACE_SpraypaintBlack", "ACE_Sandbag_empty",
		"ACE_rope3", "ACE_rope6", "ACE_rope12", "ACE_rope15", "ACE_rope18", "ACE_rope27", "ACE_rope36", "ACE_Fortify", "ACE_PlottingBoard",

		"ACE_Banana", "ACE_Can_Franta", "ACE_Can_RedGull", "ACE_Can_Spirit", "ACE_Canteen", "ACE_Canteen_Half", "ACE_Canteen_Empty", "ACE_Humanitarian_Ration", "ACE_Sunflower_Seeds",
		"ACE_MRE_BeefStew", "ACE_MRE_ChickenTikkaMasala", "ACE_MRE_ChickenHerbDumplings", "ACE_MRE_CreamChickenSoup", "ACE_MRE_CreamTomatoSoup", "ACE_MRE_LambCurry", "ACE_MRE_MeatballsPasta", "ACE_MRE_SteakVegetables",

		"B_UavTerminal", "ACE_UAVBattery", "ACE_VectorDay", "ACE_Vector", "Laserdesignator", "Laserbatteries",

		"U_B_Wetsuit", "U_B_survival_uniform","V_RebreatherB", "G_B_Diving", "G_Diving",
		"U_B_PilotCoveralls",

		"V_Rangemaster_belt",

		"B_Carryall_cbr", "B_Kitbag_cbr", "B_AssaultPack_cbr", "B_LegStrapBag_coyote_F", "B_Parachute", "ACE_NonSteerableParachute",
		
		"rhsusf_weap_m1911a1",
		"rhsusf_weap_glock17g4",
		"rhs_weap_m249_pip",
		"rhs_weap_m27iar",
		"rhs_weap_m27iar_grip",
		"rhs_weap_m16a4",
		"rhs_weap_m16a4_carryhandle",
		"rhs_weap_m16a4_carryhandle_M203",
		"rhs_weap_m16a4_imod",
		"rhs_weap_m16a4_imod_M203",
		"rhs_weap_M136",
		"rhs_weap_M136_hedp",
		"rhs_weap_M136_hp",
		"rhs_weap_maaws",
		"launch_MRAWS_green_rail_F",
		"launch_MRAWS_olive_rail_F",
		"launch_MRAWS_sand_rail_F",
		"rhs_weap_smaw",
		"rhs_weap_smaw_green",
		"rhs_weap_fim92",
		"rhs_weap_m72a7",
		"rhsusf_weap_m9",
		"rhs_weap_M320",
		"rhs_weap_m249_light_L",
		"rhs_weap_m249_light_S",
		"rhs_weap_sr25",
		"rhs_weap_sr25_ec",
		"rhs_weap_sr25_d",
		"rhs_weap_sr25_ec_d",
		"rhs_weap_m4a1_carryhandle",
		"rhsusf_weap_MP7A2",
		"rhs_weap_m40a5_d",
		"rhs_weap_m40a5",
		"rhs_weap_m4a1_m320",
		"rhs_weap_m4_carryhandle",
		"rhsusf_weap_MP7A2_folded",

		"B_IR_Grenade",
		"rhs_mag_m18_green",
		"rhs_mag_m18_purple",
		"rhs_mag_m18_red",
		"rhs_mag_m67",
		"rhs_mag_mk84",
		"rhs_mag_an_m8hc",
		"rhs_mag_an_m14_th3",

		"rhsusf_m112_mag",
		"DemoCharge_Remote_Mag",
		"rhsusf_m112x4_mag",

		"rhs_mag_M441_HE",
		"rhs_mag_M433_HEDP",
		"rhs_mag_M397_HET",
		"ACE_40mm_Flare_ir",
		"ACE_HuntIR_M203",
		"ACE_40mm_Flare_red",
		"ACE_40mm_Flare_green",
		"ACE_40mm_Flare_white",
		"rhs_mag_m713_Red",
		"rhs_mag_m714_White",

		"rhs_mag_maaws_HEAT",
		"rhs_mag_maaws_HEDP",
		"rhs_mag_maaws_HE",
		"rhs_mag_smaw_HEAA",
		"rhs_mag_smaw_HEDP",
		"rhs_mag_smaw_SR",
		"rhs_fim92_mag",

		"rhsusf_mag_15Rnd_9x19_JHP",
		"rhsusf_mag_15Rnd_9x19_FMJ",
		"rhsusf_5Rnd_300winmag_xm2010",
		"rhsusf_mag_7x45acp_MHP",
		"rhsusf_mag_17Rnd_9x19_JHP",
		"rhsusf_mag_17Rnd_9x19_FMJ",
		"rhsusf_mag_7x45acp_MHP",
		"rhsusf_mag_17Rnd_9x19_JHP",
		"rhsusf_mag_17Rnd_9x19_FMJ",

		"rhsusf_mag_40Rnd_46x30_AP",
		"rhsusf_mag_40Rnd_46x30_FMJ",
		"rhsusf_mag_40Rnd_46x30_JHP",
		"rhs_mag_30Rnd_556x45_M855A1_PMAG",
		"rhs_mag_30Rnd_556x45_M855A1_PMAG_Tracer_Red",
		"rhs_mag_30Rnd_556x45_M855A1_Stanag_Pull",
		"rhs_mag_30Rnd_556x45_M855A1_Stanag_Pull_Tracer_Red",
		"rhs_mag_30Rnd_556x45_Mk262_Stanag_Pull",
		"rhs_mag_30Rnd_556x45_Mk318_Stanag_Pull",
		"rhs_mag_30Rnd_556x45_M855A1_Stanag_Ranger",
		"rhs_mag_30Rnd_556x45_M855A1_Stanag_Ranger_Tracer_Red",
		"rhs_mag_30Rnd_556x45_Mk262_Stanag_Ranger",
		"rhs_mag_30Rnd_556x45_Mk318_Stanag_Ranger",
		"rhs_mag_30Rnd_556x45_M855A1_Stanag",
		"rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Red",
		"rhs_mag_30Rnd_556x45_Mk262_Stanag",
		"rhs_mag_30Rnd_556x45_Mk318_Stanag",
		"rhs_mag_30Rnd_556x45_Mk262_PMAG",
		"rhs_mag_30Rnd_556x45_Mk318_PMAG",
		"rhsusf_20Rnd_762x51_SR25_m118_special_Mag",
		"rhsusf_20Rnd_762x51_SR25_m62_Mag",
		"rhsusf_20Rnd_762x51_SR25_m993_Mag",
		"rhsusf_20Rnd_762x51_SR25_mk316_special_Mag",
		"rhsusf_200Rnd_556x45_soft_pouch_coyote",
		"rhsusf_10Rnd_762x51_m118_special_Mag",
		"rhsusf_10Rnd_762x51_m993_Mag",
		"rhsusf_10Rnd_762x51_m62_Mag",
		"rhsusf_200Rnd_556x45_mixed_soft_pouch_coyote",

		"rhs_uniform_FROG01_d",
		"LOP_U_ISTS_Fatigue_12",
		"U_B_HeliPilotCoveralls",

		"rhsusf_lwh_helmet_marpatd",
		"rhs_booniehat2_marpatd",
		"rhsusf_lwh_helmet_marpatd_ess",
		"rhsusf_lwh_helmet_marpatd_headset",
		"rhsusf_mich_helmet_marpatd",
		"rhsusf_mich_helmet_marpatd_alt",
		"rhsusf_mich_helmet_marpatd_alt_headset",
		"rhsusf_mich_helmet_marpatd_headset",
		"rhsusf_mich_helmet_marpatd_norotos",
		"rhsusf_mich_helmet_marpatd_norotos_arc",
		"rhsusf_mich_helmet_marpatd_norotos_arc_headset",
		"rhsusf_mich_helmet_marpatd_norotos_headset",
		"rhs_8point_marpatd",
		"rhsusf_hgu56p_black",
		"rhsusf_hgu56p_mask_black",
		"rhsusf_hgu56p_mask_black_skull",
		"rhsusf_hgu56p_visor_black",
		"rhsusf_hgu56p_visor_mask_black",
		"rhsusf_hgu56p_visor_mask_Empire_black",
		"rhsusf_hgu56p_visor_mask_black_skull",
		"rhsusf_hgu56p_visor_mask_tan",
		"rhsusf_hgu56p_visor_tan",
		"rhsusf_hgu56p_mask_tan",
		"rhsusf_hgu56p_tan",
		"rhsusf_cvc_helmet",
		"rhsusf_cvc_alt_helmet",
		"rhsusf_cvc_ess",
		"rhsusf_ach_bare_tan",
		"rhsusf_ach_bare_tan_ess",
		"rhsusf_ach_bare_tan_headset",
		"rhsusf_ach_bare_tan_headset_ess",
		"rhsusf_mich_bare_tan",
		"rhsusf_mich_bare_alt_tan",
		"rhsusf_mich_bare_tan_headset",
		"rhsusf_mich_bare_norotos_tan",
		"rhsusf_mich_bare_norotos_alt_tan",
		"rhsusf_mich_bare_norotos_alt_tan_headset",
		"rhsusf_mich_bare_norotos_arc_tan",
		"rhsusf_mich_bare_norotos_arc_alt_tan",
		"rhsusf_mich_bare_norotos_arc_alt_tan_headset",
		"rhsusf_mich_bare_norotos_tan_headset",
		"RHS_jetpilot_usaf",

		"rhsusf_spc",
		"rhsusf_spc_corpsman",
		"rhsusf_spc_crewman",
		"rhsusf_spc_iar",
		"rhsusf_spc_light",
		"rhsusf_spc_mg",
		"rhsusf_spc_marksman",
		"rhsusf_spc_rifleman",
		"rhsusf_spc_sniper",
		"rhsusf_spc_squadleader",
		"rhsusf_spc_teamleader",

		"rhs_googles_black",
		"rhs_googles_clear",
		"rhs_googles_orange",
		"rhs_googles_yellow",
		"rhs_ess_black",
		"G_Bandanna_aviator",
		"G_Bandanna_beast",
		"G_Bandanna_blk",
		"G_Bandanna_khk",
		"G_Bandanna_oli",
		"G_Bandanna_shades",
		"G_Bandanna_tan",
		"G_Lowprofile",
		"G_Shades_Black",
		"G_Shades_Blue",
		"G_Shades_Green",
		"G_Shades_Red",
		"rhsusf_shemagh_grn",
		"rhsusf_shemagh_od",
		"rhsusf_shemagh2_grn",
		"rhsusf_shemagh2_od",
		"rhsusf_shemagh_tan",
		"rhsusf_shemagh2_tan",
		"rhsusf_shemagh_gogg_grn",
		"rhsusf_shemagh2_gogg_grn",
		"rhsusf_shemagh_gogg_od",
		"rhsusf_shemagh2_gogg_od",
		"rhsusf_shemagh_gogg_tan",
		"rhsusf_shemagh2_gogg_tan",
		"rhsusf_oakley_goggles_blk",
		"rhsusf_oakley_goggles_clr",
		"rhsusf_oakley_goggles_ylw",
		"G_Spectacles",
		"G_Sport_Red",
		"G_Sport_Blackyellow",
		"G_Sport_BlackWhite",
		"G_Sport_Checkered",
		"G_Sport_Blackred",
		"G_Sport_Greenblack",
		"G_Squares_Tinted",
		"G_Squares",
		"G_Balaclava_blk",
		"G_Balaclava_oli",

		"ACE_NVG_Wide",
		"rhsusf_ANPVS_15",

		"Binocular",
		"rhsusf_bino_m24",
		"rhsusf_bino_m24_ARD",
		"rhsusf_bino_leopold_mk4",
		"ACE_VectorDay",
		"ACE_Vector",

		"TFAR_rf7800str",
		"TFAR_anprc152",
		"TFAR_microdagr",

		"ACE_HuntIR_monitor",

		"rhs_optic_maaws",
		"rhsusf_acc_eotech_xps3",
		"rhsusf_acc_ACOG_RMR",
		"rhsusf_acc_ACOG_d",
		"rhsusf_acc_ACOG_MDO",
		"rhsusf_acc_su230_mrds_c",
		"rhsusf_acc_su230_mrds",
		"rhsusf_acc_su230_c",
		"rhsusf_acc_su230",
		"rhs_weap_optic_smaw",
		"rhsusf_acc_LEUPOLDMK4_2_mrds",
		"rhsusf_acc_LEUPOLDMK4_2_d",
		"rhsusf_acc_LEUPOLDMK4_d",
		"rhsusf_acc_LEUPOLDMK4",
		"rhsusf_acc_LEUPOLDMK4_2",
		"rhsusf_acc_premier_anpvs27",
		"rhsusf_acc_premier_mrds",
		"rhsusf_acc_premier",
		"rhsusf_acc_M8541_low_d",
		"rhsusf_acc_M8541_d",
		"rhsusf_acc_M8541",
		"rhsusf_acc_M8541_low",
		"rhsusf_acc_compm4",
		"rhsusf_acc_eotech_552",
		"rhsusf_acc_ACOG",
		"rhsusf_acc_ACOG2",
		"rhsusf_acc_ACOG3",
		"rhsusf_acc_ELCAN_ard",
		"rhsusf_acc_ELCAN",
		"rhsusf_acc_g33_xps3_tan",
		"rhsusf_acc_g33_xps3",
		"rhsusf_acc_g33_T1",
		"rhsusf_acc_EOTECH",

		"rhsusf_acc_anpeq15side",
		"rhsusf_acc_anpeq15_top",
		"rhsusf_acc_anpeq15_wmx",
		"rhsusf_acc_anpeq15_wmx_light",
		"rhsusf_acc_anpeq15side_bk",
		"rhsusf_acc_anpeq15_bk_top",
		"rhsusf_acc_anpeq15",
		"rhsusf_acc_anpeq15_light",
		"rhsusf_acc_anpeq15_bk",
		"rhsusf_acc_anpeq15_bk_light",
		"rhsusf_acc_anpeq15A",
		"rhsusf_acc_anpeq16a",
		"rhsusf_acc_anpeq16a_light",
		"rhsusf_acc_anpeq16a_top",
		"rhsusf_acc_anpeq16a_light_top",
		"ACE_acc_pointer_green",
		"acc_pointer_IR",
		"rhsusf_acc_M952V",
		"rhsusf_acc_M2010S",
		"rhsusf_acc_M2010S_d",
		"rhsusf_acc_omega9k",
		"rhsusf_acc_wmx_bk",
		"rhsusf_acc_grip2",
		"rhsusf_acc_grip1",
		"rhsusf_acc_grip_m203_blk",
		"rhsusf_acc_harris_swivel",
		"rhsusf_acc_harris_bipod",
		"rhsusf_acc_kac_grip",
		"rhsusf_acc_rvg_blk",
		"rhsusf_acc_rvg_de",
		"rhsusf_acc_saw_bipod",
		"rhsusf_acc_grip4",
		"rhsusf_acc_grip4_bipod",
		"rhsusf_acc_saw_lw_bipod",
		"rhsusf_acc_tacsac_blk",
		"rhsusf_acc_tdstubby_blk",
		"rhsusf_acc_grip3",
		"rhsusf_acc_SR25S",
		"rhsusf_acc_SR25S_d",
		"rhsusf_acc_nt4_black",
		"rhsusf_acc_nt4_tan",
		"rhsusf_acc_sf3p556",
		"rhsusf_acc_sfmb556",
		"rhsusf_acc_rotex_mp7",

		"rhsusf_assault_eagleaiii_coy",
		"rhsusf_falconii_coy",
		"B_Kitbag_cbr",
		"B_AssaultPack_cbr",
		"TFAR_rt1523g_rhs",
		"TFAR_rt1523g_black",
		"TFAR_rt1523g_green",
		"TFAR_rt1523g_big"
	};
};