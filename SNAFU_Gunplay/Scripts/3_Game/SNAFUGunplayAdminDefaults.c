class SNAFUGunplayAdminDefaults
{
	static void FillMissingDefaults(SNAFUGunplayAdminConfig config)
	{
		if (!config)
		{
			return;
		}

		if (!config.AttachmentTierOverrides)
		{
			config.AttachmentTierOverrides = new array<ref SNAFUAttachmentTierOverride>;
		}

		if (!config.TierMultiplierOverrides)
		{
			config.TierMultiplierOverrides = new array<ref SNAFUTierMultiplierOverride>;
		}

		if (!config.AttachmentStatOverrides)
		{
			config.AttachmentStatOverrides = new array<ref SNAFUAttachmentStatOverride>;
		}

		FillDefaultTierMultipliers(config);
		FillDefaultAttachmentTiers(config);
		FillDefaultAttachmentStats(config);
	}

	static void FillDefaultTierMultipliers(SNAFUGunplayAdminConfig config)
	{
		AddDefaultTierMultiplier(config, "Foregrip_T1");
		AddDefaultTierMultiplier(config, "Foregrip_T2");
		AddDefaultTierMultiplier(config, "Foregrip_T3");
		AddDefaultTierMultiplier(config, "PistolGrip_T1");
		AddDefaultTierMultiplier(config, "PistolGrip_T2");
		AddDefaultTierMultiplier(config, "PistolGrip_T3");
		AddDefaultTierMultiplier(config, "Stock_T1");
		AddDefaultTierMultiplier(config, "Stock_T2");
		AddDefaultTierMultiplier(config, "Stock_T3");
		AddDefaultTierMultiplier(config, "Handguard_T1");
		AddDefaultTierMultiplier(config, "Handguard_T2");
		AddDefaultTierMultiplier(config, "Handguard_T3");
		AddDefaultTierMultiplier(config, "Bipod_Special");
		AddDefaultTierMultiplier(config, "LightOptic_T1");
		AddDefaultTierMultiplier(config, "HeavyOptic_T2");
		AddDefaultTierMultiplier(config, "SniperOptic_T3");
		AddDefaultTierMultiplier(config, "Laser_Tactical");
		AddDefaultTierMultiplier(config, "Flashlight_Utility");
		AddDefaultTierMultiplier(config, "Bayonet_Heavy");
		AddDefaultTierMultiplier(config, "Muzzle_T1");
		AddDefaultTierMultiplier(config, "Muzzle_T2");
		AddDefaultTierMultiplier(config, "Muzzle_T3");
		AddDefaultTierMultiplier(config, "Suppressor_T1");
		AddDefaultTierMultiplier(config, "Suppressor_T2");
		AddDefaultTierMultiplier(config, "Suppressor_T3");
		AddDefaultTierMultiplier(config, "WeaponWrap_Utility");
		AddDefaultTierMultiplier(config, "StandardMag_Neutral");
		AddDefaultTierMultiplier(config, "HighCap_Heavy");
		AddDefaultTierMultiplier(config, "Neutral");
	}

	static void FillDefaultAttachmentTiers(SNAFUGunplayAdminConfig config)
	{
		AddDefaultAttachmentTier(config, "FGRIP", "Foregrip_T1");
		AddDefaultAttachmentTier(config, "snafuar15afg", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "FGrip_Base", "Foregrip_T1");
		AddDefaultAttachmentTier(config, "SA58_FGrip", "Foregrip_T1");
		AddDefaultAttachmentTier(config, "SNAFU_AFG_02_Base", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "SNAFU_AFG_02_Black", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "SNAFU_AFG_02_OD", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "SNAFU_AFG_02_Tan", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "SNAFUAR15_AFG", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "SNAFUScar_AFG_BK", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "SNAFUScar_AFG_Tan", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "weaponGripCQR", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "weaponGripKAAR", "Foregrip_T3");
		AddDefaultAttachmentTier(config, "SNAFU_M249Grip", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "SNAFUSR3Grip", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "SNAFU_SR3Grip", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "weaponrgripSNAFU", "Foregrip_T2");
		AddDefaultAttachmentTier(config, "weaponGrip", "PistolGrip_T1");
		AddDefaultAttachmentTier(config, "weaponGripAK", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "weaponPistolGrip", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "SNAFUMPXGRIP", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "SNAFUMPX_Grip", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "SNAFUMPX_Grip_Base", "PistolGrip_T2");
		AddDefaultAttachmentTier(config, "SNAFU_M249Stock", "Stock_T2");
		AddDefaultAttachmentTier(config, "SNAFU_M200Stock", "Stock_T3");
		AddDefaultAttachmentTier(config, "SNAFU_AK_AR_Stock", "Stock_T2");
		AddDefaultAttachmentTier(config, "SNAFU_AK19_Stock", "Stock_T2");
		AddDefaultAttachmentTier(config, "M4_OEBttstck", "Stock_T1");
		AddDefaultAttachmentTier(config, "M4_MPBttstck", "Stock_T2");
		AddDefaultAttachmentTier(config, "M4_CQBBttstck", "Stock_T3");
		AddDefaultAttachmentTier(config, "AK_WoodBttstck", "Stock_T1");
		AddDefaultAttachmentTier(config, "AK74_WoodBttstck", "Stock_T1");
		AddDefaultAttachmentTier(config, "AK_PlasticBttstck", "Stock_T2");
		AddDefaultAttachmentTier(config, "AK_FoldingBttstck", "Stock_T2");
		AddDefaultAttachmentTier(config, "AKS74U_Bttstck", "Stock_T2");
		AddDefaultAttachmentTier(config, "MP5k_StockBttstck", "Stock_T2");
		AddDefaultAttachmentTier(config, "Red9Bttstck", "Stock_T1");
		AddDefaultAttachmentTier(config, "Fal_OeBttstck", "Stock_T2");
		AddDefaultAttachmentTier(config, "Fal_FoldingBttstck", "Stock_T3");
		AddDefaultAttachmentTier(config, "Saiga_Bttstck", "Stock_T2");
		AddDefaultAttachmentTier(config, "PP19_Bttstck", "Stock_T2");
		AddDefaultAttachmentTier(config, "SNAFUWSR3Stock", "Stock_T2");
		AddDefaultAttachmentTier(config, "SNAFU_M249HG", "Handguard_T2");
		AddDefaultAttachmentTier(config, "SNAFUM60Handguard", "Handguard_T2");
		AddDefaultAttachmentTier(config, "SNAFUSR3HG", "Handguard_T2");
		AddDefaultAttachmentTier(config, "HandguardRIS", "Handguard_T2");
		AddDefaultAttachmentTier(config, "M4_OEBHandGuard", "Handguard_T1");
		AddDefaultAttachmentTier(config, "M4_MOLLEHandGuard", "Handguard_T2");
		AddDefaultAttachmentTier(config, "M4_PlasticHndgrd", "Handguard_T1");
		AddDefaultAttachmentTier(config, "M4_RISHndgrd", "Handguard_T2");
		AddDefaultAttachmentTier(config, "M4_MPHndgrd", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AK_WoodHndgrd", "Handguard_T1");
		AddDefaultAttachmentTier(config, "AK74_Hndgrd", "Handguard_T1");
		AddDefaultAttachmentTier(config, "AK_PlasticHndgrd", "Handguard_T2");
		AddDefaultAttachmentTier(config, "AK_RailHndgrd", "Handguard_T3");
		AddDefaultAttachmentTier(config, "MP5_PlasticHndgrd", "Handguard_T1");
		AddDefaultAttachmentTier(config, "MP5_RailHndgrd", "Handguard_T2");
		AddDefaultAttachmentTier(config, "M249_Hndgrd", "Handguard_T1");
		AddDefaultAttachmentTier(config, "M249_RisHndgrd", "Handguard_T2");
		AddDefaultAttachmentTier(config, "weaponHGSNAFU10", "Handguard_T2");
		AddDefaultAttachmentTier(config, "weaponHGSNAFU10NA", "Handguard_T2");
		AddDefaultAttachmentTier(config, "weaponHGSNAFU14", "Handguard_T2");
		AddDefaultAttachmentTier(config, "weaponHGSNAFU14NA", "Handguard_T2");
		AddDefaultAttachmentTier(config, "weaponHGSNAFU16", "Handguard_T3");
		AddDefaultAttachmentTier(config, "weaponHGSNAFU16NA", "Handguard_T3");
		AddDefaultAttachmentTier(config, "snafuweaponBipod", "Bipod_Special");
		AddDefaultAttachmentTier(config, "SNAFU_AtlasBipod", "Bipod_Special");
		AddDefaultAttachmentTier(config, "SNAFU_Atlasbipod_Base", "Bipod_Special");
		AddDefaultAttachmentTier(config, "SNAFU_Bipod", "Bipod_Special");
		AddDefaultAttachmentTier(config, "SNAFU_Bipod_Base", "Bipod_Special");
		AddDefaultAttachmentTier(config, "SNAFU_ModBipod", "Bipod_Special");
		AddDefaultAttachmentTier(config, "SNAFU_M249Bipod", "Bipod_Special");
		AddDefaultAttachmentTier(config, "SNAFU_M200B_BK", "Bipod_Special");
		AddDefaultAttachmentTier(config, "SNAFU_M200Bipod_Base", "Bipod_Special");
		AddDefaultAttachmentTier(config, "snafuvsskBipod", "Bipod_Special");
		AddDefaultAttachmentTier(config, "SNAFU_VSSKbipod", "Bipod_Special");
		AddDefaultAttachmentTier(config, "SNAFU_VSSKbipod_Base", "Bipod_Special");
		AddDefaultAttachmentTier(config, "sr25bipod", "Bipod_Special");
		AddDefaultAttachmentTier(config, "PKPBIPOD", "Bipod_Special");
		AddDefaultAttachmentTier(config, "SNAFU_NPKPBIPOD", "Bipod_Special");
		AddDefaultAttachmentTier(config, "SNAFU_PKPBIPOD", "Bipod_Special");
		AddDefaultAttachmentTier(config, "SNAFU_PKPBIPOD_Base", "Bipod_Special");
		AddDefaultAttachmentTier(config, "SNAFU_RDS", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "SNAFU_EOTech_EXPS3", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "SNAFU_Aimpoint_M5", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "SNAFU_Docter", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "SNAFU_Elcan", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "SNAFU_Hunting", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "SNAFUM60ScopeMount", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "SNAFU_Nightforce", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "SNAFU_AKNightforce", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "SNAFU_HNightforce", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "SNAFU_MNightforce", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "SNAFU_Tango6T", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_Tango6T_Black", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_Tango6T_Tan", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_Tango6T_Wood", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_Tango6T_Snow", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_AKTango6T_Black", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_AKTango6T_Tan", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_AKTango6T_Wood", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_AKTango6T_Snow", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_MTango6T_Black", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_MTango6T_Tan", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_MTango6T_Wood", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_MTango6T_Snow", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_Leupold_MK8", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_Leupold_Mark8", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_AKLeupold_Mark8", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_HLeupold_Mark8", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_MLeupold_Mark8", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_Kahles", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_AKKahles", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_HKahles", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_MKahles", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_Walther", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_AKWalther", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_HWalther", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_MWalther", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "GCGN_M84_Optic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_AKHuntingOptic", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "SNAFU_HHuntingOptic", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "SNAFU_HuntingOptic", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "SNAFU_M14Optic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "SNAFU_MHuntingOptic", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "M4_CarryHandleOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "BUISOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "M68Optic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "M4_T3NRDSOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "FNP45_MRDSOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "ReflexOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "KobraOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "PistolOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "SportingOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "ACOGOptic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "ACOGOptic_6x", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "PSO1Optic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "PSO11Optic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "PSO6Optic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "GrozaOptic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "KashtanOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "PUScopeOptic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "LongrangeOptic", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "HuntingOptic", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "MK4Optic_ColorBase", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "MK4Optic_Tan", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "MK4Optic_Green", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "MK4Optic_Black", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "KazuarOptic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "StarlightOptic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "ExpansionDeltapointOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "ExpansionEXPS3HoloOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "ExpansionHAMROptic", "HeavyOptic_T2");
		AddDefaultAttachmentTier(config, "ExpansionKar98ScopeOptic", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "Expansion_PMII25Optic", "SniperOptic_T3");
		AddDefaultAttachmentTier(config, "ExpansionReflexMRSOptic", "LightOptic_T1");
		AddDefaultAttachmentTier(config, "Expansion_M1A_RailAtt", "Handguard_T1");
		AddDefaultAttachmentTier(config, "Expansion_MP5_RailAtt", "Handguard_T1");
		AddDefaultAttachmentTier(config, "weaponLaserPointer", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "weaponLaser", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "PistolLaserPointer", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "SNAFUPEQLASER", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "Expansion_ANPEQ15_Base", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "Expansion_ANPEQ15_Red", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "Expansion_ANPEQ15_Green", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "Expansion_ANPEQ15_GreenNV", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "Expansion_ANPEQ15_IR", "Laser_Tactical");
		AddDefaultAttachmentTier(config, "weaponFlashlight", "Flashlight_Utility");
		AddDefaultAttachmentTier(config, "weaponFlashlightRail", "Flashlight_Utility");
		AddDefaultAttachmentTier(config, "TLRLight", "Flashlight_Utility");
		AddDefaultAttachmentTier(config, "UniversalLight", "Flashlight_Utility");
		AddDefaultAttachmentTier(config, "weaponBayonet", "Bayonet_Heavy");
		AddDefaultAttachmentTier(config, "Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentTier(config, "M9A1Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentTier(config, "AK_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentTier(config, "M9A1_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentTier(config, "Mosin_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentTier(config, "SKS_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentTier(config, "SNAFU_SKS_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentTier(config, "GCGN_M1Garand_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentTier(config, "Expansion_Kar98_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentTier(config, "Mosin_Compensator", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "MP5_Compensator", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "Aug_Barrel", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "Groza_Barrel_Short", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "GCGN_M1Garand_Muzzle", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "SNAFUShotgunchoke", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "SNAFU_Shotgunchoke_Base", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "SNAFU_Shotgunchoke_Black", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "SNAFU_Shotgunchoke_Blue", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "SNAFU_Shotgunchoke_Brown", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "SNAFU_Shotgunchoke_Green", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "SNAFU_Shotgunchoke_Purple", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "SNAFU_Shotgunchoke_Red", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "SNAFU_Shotgunchoke_Tur", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "SNAFU_Shotgunchoke_Yellow", "Muzzle_T1");
		AddDefaultAttachmentTier(config, "Groza_Barrel_Grip", "Muzzle_T2");
		AddDefaultAttachmentTier(config, "sr25Muzzle", "Muzzle_T2");
		AddDefaultAttachmentTier(config, "snafu50bmg", "Muzzle_T3");
		AddDefaultAttachmentTier(config, "ImprovisedSuppressor", "Suppressor_T1");
		AddDefaultAttachmentTier(config, "MakarovPBSuppressor", "Suppressor_T1");
		AddDefaultAttachmentTier(config, "ItemSuppressor", "Suppressor_T1");
		AddDefaultAttachmentTier(config, "22LRSuppressor", "Suppressor_T1");
		AddDefaultAttachmentTier(config, "M4_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "AK_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "PistolSuppressor", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "Groza_Barrel_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "ASH12Suppressor", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "MP7A2Suppressor", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "Suppressor9A91", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "SNAFU_Normalized_Suppressor_Base", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "SNAFU_Normalized_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "SNAFU_Normalized_Suppressor_Green", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "SNAFU_Standardized_Suppressor_Base", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "SNAFU_Standardized_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "SNAFU_Standardized_Suppressor_Green", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "SNAFU_MPX_Suppressor_Base", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "SNAFU_MPX_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "SNAFU_Agram_Suppressor_Base", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "SNAFU_Agram_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "SNAFU_SPMOD", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "SNAFUSR3_SuppBase", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "SNAFU_SR3Vikhr_Supp", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "SR3_Vikhr_Supp", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "SNAFUAR15_SPR_SIL_Base", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "SNAFUAR15_SPR_SIL", "Suppressor_T2");
		AddDefaultAttachmentTier(config, "HoneyBadgerSuppressor", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "QDLSuppressor", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFU338_Suppressor", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "snafu300acsupp", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFU_SR25_Supp_Base", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFU_SR25_Supp", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFUKivaari_338_Supp_Base", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFUKivaari_338_Supp", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "Snafu_ScarH_SIL_Base", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "Snafu_ScarH_SIL_Tan", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "Snafu_ScarH_SIL_Black", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFUGevar_Suppressor_Black", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFUGevar_Suppressor_Tan", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFUGevar_Suppressor_Green", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFU_LNormalized_Suppressor_Base", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFU_LNormalized_Suppressor_Black", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFU_LNormalized_Suppressor_Green", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFU_LStandardized_Suppressor_Base", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFU_LStandardized_Suppressor_Black", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFU_LStandardized_Suppressor_Green", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFU_50bmg_Suppressor_Base", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFU_50bmg_Suppressor_B", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFU_50bmg_Suppressor_M", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFU_50bmg_Suppressor_S", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFU_50bmg_Suppressor_U", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFU_50bmg_Suppressor_W", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFU_408_Suppressor_T", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFUAR15_SPR_SQSIL_Base", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "SNAFUAR15_SPR_SQSIL", "Suppressor_T3");
		AddDefaultAttachmentTier(config, "GhillieAtt_ColorBase", "WeaponWrap_Utility");
		AddDefaultAttachmentTier(config, "Groza_LowerReceiver", "Handguard_T2");
		AddDefaultAttachmentTier(config, "GrozaGL_LowerReceiver", "Handguard_T2");
		AddDefaultAttachmentTier(config, "Mag_Expansion_M9_15Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentTier(config, "Mag_Expansion_G36_30Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentTier(config, "Mag_Expansion_M14_10Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentTier(config, "Mag_Expansion_M14_20Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentTier(config, "Mag_Expansion_MPX_50Rnd", "HighCap_Heavy");
		AddDefaultAttachmentTier(config, "Mag_Expansion_MP7_40Rnd", "HighCap_Heavy");
		AddDefaultAttachmentTier(config, "Mag_Expansion_Kedr_20Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentTier(config, "Mag_Expansion_Vityaz_30Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentTier(config, "Mag_Expansion_AWM_5rnd", "StandardMag_Neutral");
		AddDefaultAttachmentTier(config, "Mag_Expansion_Taser", "StandardMag_Neutral");
	}

	static void FillDefaultAttachmentStats(SNAFUGunplayAdminConfig config)
	{
		AddDefaultAttachmentStatFromTier(config, "FGRIP", "Foregrip_T1");
		AddDefaultAttachmentStatFromTier(config, "snafuar15afg", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "FGrip_Base", "Foregrip_T1");
		AddDefaultAttachmentStatFromTier(config, "SA58_FGrip", "Foregrip_T1");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_AFG_02_Base", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_AFG_02_Black", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_AFG_02_OD", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_AFG_02_Tan", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFUAR15_AFG", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFUScar_AFG_BK", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFUScar_AFG_Tan", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "weaponGripCQR", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "weaponGripKAAR", "Foregrip_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_M249Grip", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFUSR3Grip", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_SR3Grip", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "weaponrgripSNAFU", "Foregrip_T2");
		AddDefaultAttachmentStatFromTier(config, "weaponGrip", "PistolGrip_T1");
		AddDefaultAttachmentStatFromTier(config, "weaponGripAK", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "weaponPistolGrip", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFUMPXGRIP", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFUMPX_Grip", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFUMPX_Grip_Base", "PistolGrip_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_M249Stock", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_M200Stock", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_AK_AR_Stock", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_AK19_Stock", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "M4_OEBttstck", "Stock_T1");
		AddDefaultAttachmentStatFromTier(config, "M4_MPBttstck", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "M4_CQBBttstck", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "AK_WoodBttstck", "Stock_T1");
		AddDefaultAttachmentStatFromTier(config, "AK74_WoodBttstck", "Stock_T1");
		AddDefaultAttachmentStatFromTier(config, "AK_PlasticBttstck", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AK_FoldingBttstck", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "AKS74U_Bttstck", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "MP5k_StockBttstck", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "Red9Bttstck", "Stock_T1");
		AddDefaultAttachmentStatFromTier(config, "Fal_OeBttstck", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "Fal_FoldingBttstck", "Stock_T3");
		AddDefaultAttachmentStatFromTier(config, "Saiga_Bttstck", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "PP19_Bttstck", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFUWSR3Stock", "Stock_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_M249HG", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFUM60Handguard", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFUSR3HG", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "HandguardRIS", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "M4_OEBHandGuard", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "M4_MOLLEHandGuard", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "M4_PlasticHndgrd", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "M4_RISHndgrd", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "M4_MPHndgrd", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AK_WoodHndgrd", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "AK74_Hndgrd", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "AK_PlasticHndgrd", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "AK_RailHndgrd", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "MP5_PlasticHndgrd", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "MP5_RailHndgrd", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "M249_Hndgrd", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "M249_RisHndgrd", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "weaponHGSNAFU10", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "weaponHGSNAFU10NA", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "weaponHGSNAFU14", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "weaponHGSNAFU14NA", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "weaponHGSNAFU16", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "weaponHGSNAFU16NA", "Handguard_T3");
		AddDefaultAttachmentStatFromTier(config, "snafuweaponBipod", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_AtlasBipod", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Atlasbipod_Base", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Bipod", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Bipod_Base", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_ModBipod", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_M249Bipod", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_M200B_BK", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_M200Bipod_Base", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "snafuvsskBipod", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_VSSKbipod", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_VSSKbipod_Base", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "sr25bipod", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "PKPBIPOD", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_NPKPBIPOD", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_PKPBIPOD", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_PKPBIPOD_Base", "Bipod_Special");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_RDS", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_EOTech_EXPS3", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Aimpoint_M5", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Docter", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Elcan", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Hunting", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFUM60ScopeMount", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Nightforce", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_AKNightforce", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_HNightforce", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_MNightforce", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Tango6T", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Tango6T_Black", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Tango6T_Tan", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Tango6T_Wood", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Tango6T_Snow", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_AKTango6T_Black", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_AKTango6T_Tan", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_AKTango6T_Wood", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_AKTango6T_Snow", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_MTango6T_Black", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_MTango6T_Tan", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_MTango6T_Wood", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_MTango6T_Snow", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Leupold_MK8", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Leupold_Mark8", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_AKLeupold_Mark8", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_HLeupold_Mark8", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_MLeupold_Mark8", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Kahles", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_AKKahles", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_HKahles", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_MKahles", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Walther", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_AKWalther", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_HWalther", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_MWalther", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "GCGN_M84_Optic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_AKHuntingOptic", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_HHuntingOptic", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_HuntingOptic", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_M14Optic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_MHuntingOptic", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "M4_CarryHandleOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "BUISOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "M68Optic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "M4_T3NRDSOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "FNP45_MRDSOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "ReflexOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "KobraOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "PistolOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "SportingOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "ACOGOptic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "ACOGOptic_6x", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "PSO1Optic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "PSO11Optic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "PSO6Optic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "GrozaOptic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "KashtanOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "PUScopeOptic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "LongrangeOptic", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "HuntingOptic", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "MK4Optic_ColorBase", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "MK4Optic_Tan", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "MK4Optic_Green", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "MK4Optic_Black", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "KazuarOptic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "StarlightOptic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "ExpansionDeltapointOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "ExpansionEXPS3HoloOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "ExpansionHAMROptic", "HeavyOptic_T2");
		AddDefaultAttachmentStatFromTier(config, "ExpansionKar98ScopeOptic", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "Expansion_PMII25Optic", "SniperOptic_T3");
		AddDefaultAttachmentStatFromTier(config, "ExpansionReflexMRSOptic", "LightOptic_T1");
		AddDefaultAttachmentStatFromTier(config, "Expansion_M1A_RailAtt", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "Expansion_MP5_RailAtt", "Handguard_T1");
		AddDefaultAttachmentStatFromTier(config, "weaponLaserPointer", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "weaponLaser", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "PistolLaserPointer", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "SNAFUPEQLASER", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "Expansion_ANPEQ15_Base", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "Expansion_ANPEQ15_Red", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "Expansion_ANPEQ15_Green", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "Expansion_ANPEQ15_GreenNV", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "Expansion_ANPEQ15_IR", "Laser_Tactical");
		AddDefaultAttachmentStatFromTier(config, "weaponFlashlight", "Flashlight_Utility");
		AddDefaultAttachmentStatFromTier(config, "weaponFlashlightRail", "Flashlight_Utility");
		AddDefaultAttachmentStatFromTier(config, "TLRLight", "Flashlight_Utility");
		AddDefaultAttachmentStatFromTier(config, "UniversalLight", "Flashlight_Utility");
		AddDefaultAttachmentStatFromTier(config, "weaponBayonet", "Bayonet_Heavy");
		AddDefaultAttachmentStatFromTier(config, "Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentStatFromTier(config, "M9A1Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentStatFromTier(config, "AK_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentStatFromTier(config, "M9A1_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentStatFromTier(config, "Mosin_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentStatFromTier(config, "SKS_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_SKS_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentStatFromTier(config, "GCGN_M1Garand_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentStatFromTier(config, "Expansion_Kar98_Bayonet", "Bayonet_Heavy");
		AddDefaultAttachmentStatFromTier(config, "Mosin_Compensator", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "MP5_Compensator", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "Aug_Barrel", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "Groza_Barrel_Short", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "GCGN_M1Garand_Muzzle", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "SNAFUShotgunchoke", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Shotgunchoke_Base", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Shotgunchoke_Black", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Shotgunchoke_Blue", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Shotgunchoke_Brown", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Shotgunchoke_Green", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Shotgunchoke_Purple", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Shotgunchoke_Red", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Shotgunchoke_Tur", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Shotgunchoke_Yellow", "Muzzle_T1");
		AddDefaultAttachmentStatFromTier(config, "Groza_Barrel_Grip", "Muzzle_T2");
		AddDefaultAttachmentStatFromTier(config, "sr25Muzzle", "Muzzle_T2");
		AddDefaultAttachmentStatFromTier(config, "snafu50bmg", "Muzzle_T3");
		AddDefaultAttachmentStatFromTier(config, "ImprovisedSuppressor", "Suppressor_T1");
		AddDefaultAttachmentStatFromTier(config, "MakarovPBSuppressor", "Suppressor_T1");
		AddDefaultAttachmentStatFromTier(config, "ItemSuppressor", "Suppressor_T1");
		AddDefaultAttachmentStatFromTier(config, "22LRSuppressor", "Suppressor_T1");
		AddDefaultAttachmentStatFromTier(config, "M4_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "AK_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "PistolSuppressor", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "Groza_Barrel_Suppressor", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "ASH12Suppressor", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "MP7A2Suppressor", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "Suppressor9A91", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Normalized_Suppressor_Base", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Normalized_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Normalized_Suppressor_Green", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Standardized_Suppressor_Base", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Standardized_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Standardized_Suppressor_Green", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_MPX_Suppressor_Base", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_MPX_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Agram_Suppressor_Base", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_Agram_Suppressor_Black", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_SPMOD", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFUSR3_SuppBase", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_SR3Vikhr_Supp", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "SR3_Vikhr_Supp", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFUAR15_SPR_SIL_Base", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "SNAFUAR15_SPR_SIL", "Suppressor_T2");
		AddDefaultAttachmentStatFromTier(config, "HoneyBadgerSuppressor", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "QDLSuppressor", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU338_Suppressor", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "snafu300acsupp", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_SR25_Supp_Base", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_SR25_Supp", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFUKivaari_338_Supp_Base", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFUKivaari_338_Supp", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "Snafu_ScarH_SIL_Base", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "Snafu_ScarH_SIL_Tan", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "Snafu_ScarH_SIL_Black", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFUGevar_Suppressor_Black", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFUGevar_Suppressor_Tan", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFUGevar_Suppressor_Green", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_LNormalized_Suppressor_Base", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_LNormalized_Suppressor_Black", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_LNormalized_Suppressor_Green", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_LStandardized_Suppressor_Base", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_LStandardized_Suppressor_Black", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_LStandardized_Suppressor_Green", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_50bmg_Suppressor_Base", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_50bmg_Suppressor_B", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_50bmg_Suppressor_M", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_50bmg_Suppressor_S", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_50bmg_Suppressor_U", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_50bmg_Suppressor_W", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFU_408_Suppressor_T", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFUAR15_SPR_SQSIL_Base", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "SNAFUAR15_SPR_SQSIL", "Suppressor_T3");
		AddDefaultAttachmentStatFromTier(config, "GhillieAtt_ColorBase", "WeaponWrap_Utility");
		AddDefaultAttachmentStatFromTier(config, "Groza_LowerReceiver", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "GrozaGL_LowerReceiver", "Handguard_T2");
		AddDefaultAttachmentStatFromTier(config, "Mag_Expansion_M9_15Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentStatFromTier(config, "Mag_Expansion_G36_30Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentStatFromTier(config, "Mag_Expansion_M14_10Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentStatFromTier(config, "Mag_Expansion_M14_20Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentStatFromTier(config, "Mag_Expansion_MPX_50Rnd", "HighCap_Heavy");
		AddDefaultAttachmentStatFromTier(config, "Mag_Expansion_MP7_40Rnd", "HighCap_Heavy");
		AddDefaultAttachmentStatFromTier(config, "Mag_Expansion_Kedr_20Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentStatFromTier(config, "Mag_Expansion_Vityaz_30Rnd", "StandardMag_Neutral");
		AddDefaultAttachmentStatFromTier(config, "Mag_Expansion_AWM_5rnd", "StandardMag_Neutral");
		AddDefaultAttachmentStatFromTier(config, "Mag_Expansion_Taser", "StandardMag_Neutral");
	}

	static bool HasTierMultiplier(SNAFUGunplayAdminConfig config, string tierKey)
	{
		foreach (SNAFUTierMultiplierOverride tierOverride : config.TierMultiplierOverrides)
		{
			if (tierOverride && tierOverride.TierKey == tierKey)
			{
				return true;
			}
		}

		return false;
	}

	static bool HasAttachmentTier(SNAFUGunplayAdminConfig config, string className)
	{
		foreach (SNAFUAttachmentTierOverride tierOverride : config.AttachmentTierOverrides)
		{
			if (tierOverride && tierOverride.ClassName == className)
			{
				return true;
			}
		}

		return false;
	}

	static bool HasAttachmentStat(SNAFUGunplayAdminConfig config, string className)
	{
		foreach (SNAFUAttachmentStatOverride statOverride : config.AttachmentStatOverrides)
		{
			if (statOverride && statOverride.ClassName == className)
			{
				return true;
			}
		}

		return false;
	}

	static void AddDefaultTierMultiplier(SNAFUGunplayAdminConfig config, string tierKey)
	{
		if (HasTierMultiplier(config, tierKey))
		{
			return;
		}

		config.TierMultiplierOverrides.Insert(new SNAFUTierMultiplierOverride(tierKey, 1.0, 1.0, 1.0, 1.0, 1.0));
	}

	static void AddDefaultAttachmentTier(SNAFUGunplayAdminConfig config, string className, string tierKey)
	{
		if (HasAttachmentTier(config, className))
		{
			return;
		}

		config.AttachmentTierOverrides.Insert(new SNAFUAttachmentTierOverride(className, tierKey));
	}

	static void AddDefaultAttachmentStatFromTier(SNAFUGunplayAdminConfig config, string className, string tierKey)
	{
		if (HasAttachmentStat(config, className))
		{
			return;
		}

		if (tierKey == "Foregrip_T1")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Foregrip", "T1", 0.70, 0.925, 1.03, 1.05, 0.90));
			return;
		}

		if (tierKey == "Foregrip_T2")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Foregrip", "T2", 0.40, 0.85, 1.06, 1.10, 0.80));
			return;
		}

		if (tierKey == "Foregrip_T3")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Foregrip", "T3", 0.10, 0.775, 1.08, 1.15, 0.70));
			return;
		}

		if (tierKey == "PistolGrip_T1")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Pistol Grip", "T1", 0.70, 1.00, 1.05, 1.00, 0.90));
			return;
		}

		if (tierKey == "PistolGrip_T2")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Pistol Grip", "T2", 0.40, 0.97, 1.10, 1.02, 0.80));
			return;
		}

		if (tierKey == "PistolGrip_T3")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Pistol Grip", "T3", 0.10, 0.94, 1.15, 1.04, 0.70));
			return;
		}

		if (tierKey == "Stock_T1")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Stock", "T1", 0.70, 0.85, 1.00, 1.05, 1.00));
			return;
		}

		if (tierKey == "Stock_T2")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Stock", "T2", 0.40, 0.70, 0.99, 1.10, 1.00));
			return;
		}

		if (tierKey == "Stock_T3")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Stock", "T3", 0.10, 0.55, 0.98, 1.15, 1.00));
			return;
		}

		if (tierKey == "Handguard_T1")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Handguard", "T1", 1.00, 0.85, 1.02, 1.10, 0.90));
			return;
		}

		if (tierKey == "Handguard_T2")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Handguard", "T2", 0.94, 0.70, 1.04, 1.20, 0.80));
			return;
		}

		if (tierKey == "Handguard_T3")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Handguard", "T3", 0.88, 0.55, 1.06, 1.30, 0.70));
			return;
		}

		if (tierKey == "Bipod_Special")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Bipod", "Special", 0.70, 0.43, 0.86, 1.16, 1.00));
			return;
		}

		if (tierKey == "LightOptic_T1")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Optic", "T1", 1.00, 0.985, 1.05, 1.10, 1.00));
			return;
		}

		if (tierKey == "HeavyOptic_T2")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Optic", "T2", 1.00, 0.97, 0.95, 1.20, 1.00));
			return;
		}

		if (tierKey == "SniperOptic_T3")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Optic", "T3", 1.00, 0.955, 0.85, 1.30, 1.00));
			return;
		}

		if (tierKey == "Laser_Tactical")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Laser", "Tactical", 1.00, 1.00, 1.00, 1.00, 0.55));
			return;
		}

		if (tierKey == "Flashlight_Utility")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Flashlight", "Utility", 1.00, 1.04, 0.96, 1.00, 1.00));
			return;
		}

		if (tierKey == "Bayonet_Heavy")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Bayonet", "Heavy", 1.00, 1.08, 0.92, 1.00, 1.00));
			return;
		}

		if (tierKey == "Muzzle_T1")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Muzzle", "T1", 0.85, 0.925, 1.00, 1.05, 0.95));
			return;
		}

		if (tierKey == "Muzzle_T2")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Muzzle", "T2", 0.70, 0.85, 0.99, 1.10, 0.90));
			return;
		}

		if (tierKey == "Muzzle_T3")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Muzzle", "T3", 0.55, 0.775, 0.98, 1.15, 0.85));
			return;
		}

		if (tierKey == "Suppressor_T1")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Suppressor", "T1", 0.85, 1.00, 0.98, 1.05, 0.95));
			return;
		}

		if (tierKey == "Suppressor_T2")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Suppressor", "T2", 0.70, 1.01, 0.96, 1.10, 0.90));
			return;
		}

		if (tierKey == "Suppressor_T3")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Suppressor", "T3", 0.55, 1.02, 0.94, 1.15, 0.85));
			return;
		}

		if (tierKey == "WeaponWrap_Utility")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Wrap", "Utility", 1.00, 0.925, 0.97, 1.03, 1.00));
			return;
		}

		if (tierKey == "StandardMag_Neutral")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Magazine", "Standard", 1.00, 1.00, 1.00, 1.00, 1.00));
			return;
		}

		if (tierKey == "HighCap_Heavy")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Magazine", "HighCap", 1.02, 1.03, 0.98, 1.00, 1.00));
			return;
		}

		if (tierKey == "Neutral")
		{
			config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Neutral", "Neutral", 1.00, 1.00, 1.00, 1.00, 1.00));
			return;
		}

		config.AttachmentStatOverrides.Insert(new SNAFUAttachmentStatOverride(className, "Custom", tierKey, 1.0, 1.0, 1.0, 1.0, 1.0));
	}
}
