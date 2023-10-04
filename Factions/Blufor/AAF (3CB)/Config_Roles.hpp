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
		"rhs_weap_vhsd2", //service rifle
		"rhs_weap_vhsd2_ct15x",
		"rhs_weap_vhsd2_bg",
		"rhs_weap_vhsd2_bg_ct15x",
		"rhs_weap_vhsk2",
		
		"rhs_weap_m4a1_blockII", //spec ops rifle
		"rhs_weap_m4a1_blockII_bk",
		"rhs_weap_m4a1_blockII_M203_bk",
		"rhs_weap_m4a1_blockII_KAC_bk",
		"rhs_weap_m4a1_blockII_M203",
		"rhs_weap_m4a1_blockII_KAC",
		
		"rhs_weap_m249_light_L", //LMG
		"rhs_weap_m249_pip_L_para",
		"rhs_weap_m249_light_S",
		"rhs_weap_m249_pip_S_para",
		
		"rhs_weap_XM2010", //sniper rifle
		"rhs_weap_XM2010_d",
		"rhs_weap_XM2010_sa",
		
		"rhs_weap_M107", //anti-material rifle
		
		"rhsusf_weap_glock17g4", //pistol
		"rhsusf_weap_m9",
		"rhs_weap_M320",
		
		"ACE_Flashlight_Maglite_ML300L", //equipment
		"rhs_weap_rsp30_white",
		"rhs_weap_rsp30_green",
		"rhs_weap_rsp30_red",
		"rhs_weap_tr8",
		"ACE_VMM3",
		
		"rhs_weap_fim92", //MANPADS
		
		"rhs_weap_m72a7", //RPG
		"rhs_weap_smaw",
		"rhs_weap_smaw_green",
		
		"UK3CB_BAF_Javelin_Slung_Tube", //Javelin
		
		"UK3CB_BAF_M6", //mortar

		"rhs_mag_m4009", //grenades
		"ACE_HuntIR_M203",
		"rhs_mag_M397_HET",
		"rhs_mag_M433_HEDP",
		"rhs_mag_M441_HE",
		"rhs_mag_m576",
		"ACE_40mm_Flare_white",
		"rhs_mag_M583A1_white",
		"rhs_mag_M585_white_cluster",
		"rhs_mag_m661_green",
		"ACE_40mm_Flare_green",
		"ACE_40mm_Flare_red",
		"rhs_mag_m662_red",
		"rhs_mag_M663_green_cluster",
		"rhs_mag_M664_red_cluster",
		"rhs_mag_m713_Red",
		"rhs_mag_m714_White",
		"rhs_mag_m715_Green",
		"rhs_mag_m716_yellow",
		"rhs_mag_M781_Practice",
		"ACE_40mm_Flare_ir",
		
		"rhsgref_30rnd_556x45_vhs2", //vhs
		"rhsgref_30rnd_556x45_vhs2_t",
		
		"rhs_mag_30Rnd_556x45_M855_Stanag", //m4
		"rhs_mag_30Rnd_556x45_M855A1_Stanag",
		"rhs_mag_30Rnd_556x45_M855_Stanag_Tracer_Red",
		"rhs_mag_30Rnd_556x45_M855A1_Stanag_Tracer_Red",
		"rhs_mag_30Rnd_556x45_M855_Stanag_Ranger",
		"rhs_mag_30Rnd_556x45_M855A1_Stanag_Ranger",
		"rhs_mag_30Rnd_556x45_M855_Stanag_Ranger_Tracer_Red",
		"rhs_mag_30Rnd_556x45_M855A1_Stanag_Ranger_Tracer_Red",
		"rhs_mag_30Rnd_556x45_M855A1_Stanag_Ranger_Tracer_Red",
		"rhs_mag_30Rnd_556x45_M855A1_Stanag_Pull",
		"rhs_mag_30Rnd_556x45_M855_Stanag_Pull_Tracer_Red",
		"rhs_mag_30Rnd_556x45_M855A1_Stanag_Pull_Tracer_Red",
		"rhs_mag_30Rnd_556x45_M855_PMAG",
		"rhs_mag_30Rnd_556x45_M855A1_PMAG",
		"rhs_mag_30Rnd_556x45_M855_PMAG_Tracer_Red",
		"rhs_mag_30Rnd_556x45_M855A1_PMAG_Tracer_Red",
		
		"rhsusf_100Rnd_556x45_M855_soft_pouch_coyote", //m249
		"rhsusf_100Rnd_556x45_M855_mixed_soft_pouch_coyote",
		"rhsusf_100Rnd_556x45_soft_pouch_coyote",
		"rhsusf_100Rnd_556x45_mixed_soft_pouch_coyote",
		"rhsusf_100Rnd_556x45_M995_soft_pouch_coyote",
		"rhsusf_200rnd_556x45_M855_box",
		"rhsusf_200rnd_556x45_M855_mixed_box",
		"rhsusf_200Rnd_556x45_box",
		"rhsusf_200rnd_556x45_mixed_box",
		"rhsusf_200Rnd_556x45_M855_soft_pouch_coyote",
		"rhsusf_200Rnd_556x45_M855_mixed_soft_pouch_coyote",
		"rhsusf_200Rnd_556x45_soft_pouch_coyote",
		"rhsusf_200Rnd_556x45_mixed_soft_pouch_coyote",
		
		"rhsusf_5Rnd_300winmag_xm2010", //m2010
		
		"rhsusf_mag_10Rnd_STD_50BMG_M33", //m107
		"rhsusf_mag_10Rnd_STD_50BMG_mk211",
		
		"rhsusf_mag_17Rnd_9x19_FMJ", //g17
		"rhsusf_mag_17Rnd_9x19_JHP",
		
		"rhsusf_mag_15Rnd_9x19_FMJ", //m9
		"rhsusf_mag_15Rnd_9x19_JHP",
		
		"rhs_mag_rsp30_white", //flare
		"rhs_mag_rsp30_green",
		"rhs_mag_rsp30_red",
		
		"rhs_fim92_mag", //fim92
		
		"rhs_mag_smaw_HEDP", //smaw
		"rhs_mag_smaw_HEAA",
		
		"UK3CB_BAF_1Rnd_60mm_Mo_AB_Shells", //m6
		"UK3CB_BAF_1Rnd_60mm_Mo_Shells",
		"UK3CB_BAF_1Rnd_60mm_Mo_Smoke_Red",
		"UK3CB_BAF_1Rnd_60mm_Mo_Flare_White",
		"UK3CB_BAF_1Rnd_60mm_Mo_WPSmoke_White",
		"UK3CB_BAF_1Rnd_60mm_Mo_Smoke_White",
		
		"ACE_1Rnd_82mm_Mo_HE_LaserGuided", //static ammo
		"ACE_1Rnd_82mm_Mo_HE",
		"ACE_1Rnd_82mm_Mo_Illum",
		"ACE_1Rnd_82mm_Mo_Smoke",
		"ACE_1Rnd_82mm_Mo_HE_Guided",
		"ace_csw_50Rnd_127x108_mag",
		"ace_compat_rhs_afrf3_mag_VOG30_30",
		"ace_csw_20Rnd_20mm_G_belt",
		"ace_csw_100Rnd_127x99_mag_red",
		"ace_compat_rhs_usf3_48Rnd_40mm_MK19_M430A1",
		"ace_compat_rhs_usf3_mag_TOW2A",
		"ace_compat_rhs_afrf3_mag_PG9V",
		"ace_compat_rhs_afrf3_mag_OG9V",
		"ace_compat_rhs_usf3_mag_TOW2bb",
		"ace_compat_rhs_afrf3_mag_9M131M",
		"ace_compat_rhs_afrf3_mag_9M131F",
		"ace_compat_rhs_afrf3_mag_9m133",

		"rhsusf_acc_acog", //scope
		"rhsusf_acc_acog2",
		"rhsusf_acc_acog3",
		"rhsusf_acc_elcan",
		"rhsusf_acc_elcan_ard",
		"rhsusf_acc_su230",
		"rhsusf_acc_su230_c",
		"rhsusf_acc_su230_mrds",
		"rhsusf_acc_su230_mrds_c",
		"rhsusf_acc_su230a",
		"rhsusf_acc_su230a_c",
		"rhsusf_acc_su230a_mrds",
		"rhsusf_acc_su230a_mrds_c",
		"rhsusf_acc_eotech_xps3",
		"rhsusf_acc_t1_high",
		"rhsusf_acc_t1_low",
		"rhsusf_acc_g33_t1",
		"rhsusf_acc_g33_xps3",
		"rhsusf_acc_anpvs27",
		"rhsusf_acc_premier_anpvs27",
		"rhsusf_acc_premier",
		"rhsusf_acc_premier_mrds",
		"rksl_optic_pmii_525",
		"rhsusf_acc_nxs_3515x50f1_md_sun",
		"rhsusf_acc_nxs_3515x50f1_md",
		
		"rhsusf_acc_grip1", //grip and bipods
		"rhsusf_acc_harris_bipod",
		"rhsusf_acc_kac_grip",
		"rhsusf_acc_rvg_blk",
		"rhsusf_acc_rvg_de",
		"rhsusf_acc_tdstubby_blk",
		"rhsusf_acc_tdstubby_tan",
		"rhsusf_acc_grip3",
		"rhsusf_acc_grip2",
		"rhsusf_acc_saw_lw_bipod",
		"rhsusf_acc_saw_bipod",
		"rhsusf_acc_kac_grip_saw_bipod",
		
		"rhsusf_acc_anpeq15side", //attachment
		"rhsusf_acc_anpeq15_top",
		"rhsusf_acc_anpeq15_wmx",
		"rhsusf_acc_anpeq15_wmx_light",
		"rhsusf_acc_anpeq15side_bk",
		"rhsusf_acc_anpeq15_bk_top",
		"rhsusf_acc_anpeq15",
		"rhsusf_acc_anpeq15_light",
		"rhsusf_acc_anpeq15_bk",
		"rhsusf_acc_anpeq15_bk_light",
		"rhsusf_acc_m952v",
		"rhsusf_acc_wmx",
		"rhsusf_acc_wmx_bk",
		"acc_flashlight_pistol",
		
		"rhsusf_acc_omega9k", //muzzle
		"rhsusf_acc_nt4_black",
		"rhsusf_acc_nt4_tan",
		"rhsusf_acc_rotex5_grey",
		"rhsusf_acc_sf3p556",
		"rhsusf_acc_sfmb556",
		"rhsusf_acc_m2010s",
		"rhsusf_acc_m2010s_d",
		"rhsusf_acc_m2010s_sa",
		
		"UK3CB_AAF_B_U_CombatUniform_Shortsleeve_DIGI_BRN", //uniforms
		"UK3CB_AAF_B_U_CombatUniform_DIGI_BRN",
		"UK3CB_AAF_B_U_CombatUniform_Shortsleeve_DIGI_GRN",
		"UK3CB_AAF_B_U_CombatUniform_DIGI_GRN",
		"UK3CB_AAF_B_U_CombatUniform_Shortsleeve_Digi_Mix_01",
		"UK3CB_AAF_B_U_CombatUniform_Digi_Mix_01",
		"UK3CB_AAF_B_U_CombatUniform_Shortsleeve_Digi_Mix_02",
		"UK3CB_AAF_B_U_CombatUniform_Digi_Mix_02",
		"UK3CB_AAF_B_U_CombatUniform_Shortsleeve_Navy_DIGI_BLK",
		"UK3CB_AAF_B_U_CombatUniform_Navy_DIGI_BLK",
		"UK3CB_AAF_B_U_Officer_DIGI_BRN",
		"UK3CB_AAF_B_U_Officer_DIGI_GRN",
		"UK3CB_AAF_B_U_SF_Officer_DIGI_MIX",
		"U_I_FullGhillie_ard",
		"U_I_FullGhillie_lsh",
		"U_I_FullGhillie_sard",
		"UK3CB_AAF_I_U_H_Pilot_DIGI_GRN",
		"U_I_pilotCoveralls",
		"U_Tank_green_F",
		"UK3CB_AAF_B_U_Diving_Uniform_DIGI_BLK",
		"U_I_ParadeUniform_01_AAF_decorated_F",
		"U_I_ParadeUniform_01_AAF_F",
		"UK3CB_AAF_B_U_JumperUniform_Navy_DIGI_BLK",
		"UK3CB_AAF_B_U_JumperUniform_DIGI_GRN",
		"UK3CB_AAF_B_U_JumperUniform_Digi_Mix_01",
		"UK3CB_AAF_B_U_JumperUniform_Digi_Mix_02",
		
		"V_RebreatherIA", //vests
		"UK3CB_AAF_B_V_Vest_DIGI_BLK",
		"UK3CB_AAF_B_V_Vest_DIGI_BRN",
		"UK3CB_AAF_B_V_MD_Vest_DIGI_BRN",
		"UK3CB_AAF_B_V_CREW_Vest_DIGI_BRN",
		"UK3CB_AAF_B_V_MG_Vest_DIGI_BRN",
		"UK3CB_AAF_B_V_MK_Vest_DIGI_BRN",
		"UK3CB_AAF_B_V_RFL_Vest_DIGI_BRN",
		"UK3CB_AAF_B_V_SL_Vest_DIGI_BRN",
		"UK3CB_AAF_B_V_Vest_DIGI_GRN",
		"UK3CB_AAF_B_V_MD_Vest_DIGI_GRN",
		"UK3CB_AAF_B_V_CREW_Vest_DIGI_GRN",
		"UK3CB_AAF_B_V_MG_Vest_DIGI_GRN",
		"UK3CB_AAF_B_V_MK_Vest_DIGI_GRN",
		"UK3CB_AAF_B_V_RFL_Vest_DIGI_GRN",
		"UK3CB_AAF_B_V_SL_Vest_DIGI_GRN",
		"UK3CB_AAF_B_V_TacVest_DIGI_BLK",
		"UK3CB_AAF_B_V_TacVest_DIGI_BRN",
		"UK3CB_AAF_B_V_TacVest_DIGI_GRN",
		"V_TacChestrig_cbr_F",
		"V_TacChestrig_oli_F",
		"V_LegStrapBag_coyote_F",
		"V_LegStrapBag_olive_F",
		
		"UK3CB_AAF_B_H_Beret_Airforce_Off", //headgear
		"UK3CB_AAF_B_H_Beret_AIR",
		"UK3CB_AAF_B_H_Beret_Army_Off",
		"UK3CB_AAF_B_H_Beret_Army",
		"UK3CB_AAF_B_H_Beret_Navy_Off",
		"UK3CB_AAF_B_H_Beret_Navy",
		"UK3CB_AAF_B_H_Beret_SF_Off",
		"UK3CB_AAF_B_H_Beret_SF",
		"H_Booniehat_dgtl",
		"H_Cap_blk_Raven",
		"H_HelmetCrew_I",
		"H_CrewHelmetHeli_I",
		"H_PilotHelmetHeli_I",
		"H_MilCap_dgtl",
		"H_ParadeDressCap_01_AAF_F",
		"UK3CB_AAF_B_H_PASGT_DIGI_BLK",
		"UK3CB_AAF_B_H_PASGT_RHINO_DIGI_BLK",
		"UK3CB_AAF_B_H_PASGT_DIGI_BRN",
		"UK3CB_AAF_B_H_PASGT_RHINO_DIGI_BRN",
		"UK3CB_AAF_B_H_PASGT_DIGI_GRN",
		"UK3CB_AAF_B_H_PASGT_RHINO_DIGI_GRN",
		"H_PilotHelmetFighter_I",
		
		"G_Aviator", //facewear
		"rhs_balaclava",
		"UK3CB_G_Balaclava_DES",
		"rhs_balaclava1_olive",
		"UK3CB_G_Balaclava2_DES",
		"rhs_googles_black",
		"rhs_googles_clear",
		"rhs_googles_orange",
		"rhs_googles_yellow",
		"G_Bandanna_beast",
		"G_Bandanna_blk",
		"G_Bandanna_khk",
		"G_Bandanna_oli",
		"G_I_Diving",
		"G_Lowprofile",
		"UK3CB_G_Neck_Shemag_Oli",
		"UK3CB_G_Neck_Shemag_Tan",
		"UK3CB_G_Neck_Shemag",
		"UK3CB_G_KLR_BLK",
		"UK3CB_G_KLR_Oli",
		"UK3CB_G_KLR_TAN",
		"UK3CB_G_KL_BLK",
		"UK3CB_G_KL_Oli",
		"UK3CB_G_KL_TAN",
		"UK3CB_G_Neck_Shemag_KLR_blk",
		"UK3CB_G_Neck_Shemag_KLR_tan",
		"UK3CB_G_Neck_Shemag_KL_blk",
		"UK3CB_G_Neck_Shemag_KL_tan",
		"UK3CB_G_Neck_Shemag_KR_blk",
		"UK3CB_G_Neck_Shemag_KR_tan",
		"UK3CB_G_KR_BLK",
		"UK3CB_G_KR_Oli",
		"UK3CB_G_KR_TAN",
		"rhsusf_shemagh_grn",
		"rhsusf_shemagh2_grn",
		"rhsusf_shemagh_od",
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
		"UK3CB_BAF_G_Tactical_Black",
		"UK3CB_BAF_G_Tactical_Clear",
		"UK3CB_BAF_G_Tactical_Grey",
		"UK3CB_BAF_G_Tactical_Orange",
		"UK3CB_BAF_G_Tactical_Yellow",
		
		"UK3CB_BAF_Javelin_CLU", //binoculars
		"ACE_VectorDay",
		"ACE_Vector",
		"Binocular",
		"Laserdesignator_03",
		"Laserdesignator",
		"rhsusf_bino_leopold_mk4",
		"rhs_tr8_periscope",
		
		"TFAR_anprc152", //radios
		
		"NVGogglesB_blk_F", //nvg
		"NVGogglesB_grn_F",
		"NVGogglesB_gry_F",
		"ACE_NVG_Gen4_Black",
		"ACE_NVG_Gen4_Green",
		"ACE_NVG_Wide_Black",
		"ACE_NVG_Wide_Green",
		
		"ItemMap", //equipment
		"ItemGPS",
		"B_UavTerminal",
		"ItemCompass",
		"ItemWatch",
		
		"ACE_adenosine", //items
		"ACE_artilleryTable",
		"ACE_ATragMX",
		"ACE_fieldDressing",
		"ACE_elasticBandage",
		"ACE_packingBandage",
		"ACE_quikclot",
		"ACE_bloodIV",
		"ACE_bloodIV_250",
		"ACE_bloodIV_500",
		"ACE_bodyBag",
		"ACE_CableTie",
		"ACE_DAGR",
		"ACE_DefusalKit",
		"ACE_EarPlugs",
		"ACE_EntrenchingTool",
		"ACE_epinephrine",
		"ACE_HuntIR_monitor",
		"ACE_IR_Strobe_Item",
		"ACE_Kestrel4500",
		"ACE_M26_Clacker",
		"UK3CB_BAF_M6_RangeTable",
		"ACE_Flashlight_XL50",
		"ACE_MapTools",
		"ACE_microDAGR",
		"ACE_morphine",
		"ACE_plasmaIV",
		"ACE_plasmaIV_250",
		"ACE_plasmaIV_500",
		"ACE_RangeCard",
		"ACE_salineIV",
		"ACE_salineIV_250",
		"ACE_salineIV_500",
		"ACE_SpareBarrel_Item",
		"ACE_splint",
		"ACE_SpottingScope",
		"ACE_SpraypaintBlack",
		"ACE_SpraypaintBlue",
		"ACE_SpraypaintGreen",
		"ACE_SpraypaintRed",
		"ACE_Tripod",
		"ACE_surgicalKit",
		"ToolKit",
		"ACE_tourniquet",
		"ACE_UAVBattery",
		"ACE_WaterBottle",
		"ACE_WaterBottle_Empty",
		"ACE_WaterBottle_Half",
		"ACE_wirecutter",
		
		"rhs_grenade_m15_mag", //grenades
		"rhs_mag_m18_green",
		"rhs_mag_m18_purple",
		"rhs_mag_m18_red",
		"rhs_mag_m18_yellow",
		"rhs_mag_m67",
		"rhs_mag_m7a3_cs",
		"rhs_mag_mk84",
		"ACE_HandFlare_Green",
		"ACE_HandFlare_Red",
		"ACE_HandFlare_White",
		"ACE_HandFlare_Yellow",
		"I_IR_Grenade",
		"rhs_mag_an_m14_th3",
		"rhs_mag_an_m8hc",
		"ACE_Chemlight_HiBlue",
		"ACE_Chemlight_HiGreen",
		"ACE_Chemlight_HiRed",
		"ACE_Chemlight_HiWhite",
		"ACE_Chemlight_HiYellow",
		"ACE_Chemlight_IR",
		"ACE_Chemlight_UltraHiOrange",
		
		"rhsusf_mine_m14_mag", //explosives
		"rhs_mine_M19_mag",
		"rhsusf_mine_m49a1_10m_mag",
		"rhsusf_mine_m49a1_3m_mag",
		"rhsusf_mine_m49a1_6m_mag",
		"SatchelCharge_Remote_Mag",
		"DemoCharge_Remote_Mag",

		"UK3CB_AAF_B_B_ASS_DIGI_BLK", //backpacks
		"UK3CB_AAF_B_B_ASS_DIGI_BRN",
		"B_AssaultPack_dgtl",
		"UK3CB_AAF_B_B_CARRYALL_DIGI_BRN",
		"UK3CB_AAF_B_B_CARRYALL_DIGI_GRN",
		"UK3CB_AAF_B_B_FIELDPACK_DIGI_BLK",
		"UK3CB_AAF_B_B_FIELDPACK_DIGI_BRN",
		"UK3CB_AAF_B_B_FIELDPACK_DIGI_GRN",
		"UK3CB_AAF_B_B_FIELDPACK_DIGI_BLK_Radio",
		"UK3CB_AAF_B_B_FIELDPACK_DIGI_BRN_Radio",
		"UK3CB_AAF_B_B_FIELDPACK_DIGI_GRN_Radio",
		"I_UAV_01_backpack_F",
		"I_UGV_02_Demining_backpack_F",
		"ace_gunbag",
		"ace_gunbag_Tan",
		"ACE_TacticalLadder_Pack",
		"B_LegStrapBag_coyote_F",
		"B_LegStrapBag_olive_F",
		"B_Parachute"
	};
};