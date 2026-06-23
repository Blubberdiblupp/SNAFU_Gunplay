class SNAFUTierEffect
{
	string Category;
	string Tier;
	float Recoil;
	float Sway;
	float ADS;
	float Precision;
	float HipFire;
	
	void SNAFUTierEffect(string category = "Neutral", string tier = "Neutral", float recoil = 1.0, float sway = 1.0, float ads = 1.0, float precision = 1.0, float hipFire = 1.0)
	{
		Category = category;
		Tier = tier;
		Recoil = recoil;
		Sway = sway;
		ADS = ads;
		Precision = precision;
		HipFire = hipFire;
	}
	
	string GetLabel()
	{
		return Category + " " + Tier;
	}
}

class SNAFUGunplayConfig
{
	static ref SNAFUGunplayConfig m_Instance;
	
	float GlobalRecoilMultiplier;
	float GlobalSwayMultiplier;
	float GlobalAimSpeedMultiplier;
	bool EnableHipFireNerf;
	bool EnableWeaponGeometryDamage;
	float GripRecoilReduction;
	float GripSwayReduction;
	float HeavyScopeAimSpeedPenalty;
	float LightScopeAimSpeedPenalty;
	float HipFireAccuracyDegradation;
	bool DebugMode;
	
	int RepairKit_Uses;
	float RepairKit_Time;
	bool RepairKit_AllowSuppressors;
	
	int HighCapMagazineThreshold;
	
	float Modifier_Buttstock_Recoil;
	float Modifier_Buttstock_Sway;
	float Modifier_PistolGrip_Recoil;
	float Modifier_PistolGrip_ADS;
	float Modifier_Foregrip_Recoil;
	float Modifier_Foregrip_ADS;
	float Modifier_Handguard_Sway;
	float Modifier_Handguard_Precision;
	float Modifier_Bipod_Sway;
	float Modifier_Bipod_ADS;
	float Modifier_Laser_HipFire;
	float Modifier_Flashlight_Sway;
	float Modifier_Flashlight_ADS;
	float Modifier_Bayonet_Sway;
	float Modifier_Bayonet_ADS;
	float Modifier_HighCapMag_ADS;
	float Modifier_HighCapMag_Sway;
	
	ref map<string, string> AttachmentTiers;
	ref map<string, ref SNAFUTierEffect> AttachmentTierEffects;
	
	static SNAFUGunplayConfig GetInstance()
	{
		if (!m_Instance)
		{
			m_Instance = new SNAFUGunplayConfig();
			m_Instance.Init();
		}
		return m_Instance;
	}
	
	void Init()
	{
		AttachmentTiers = new map<string, string>;
		AttachmentTierEffects = new map<string, ref SNAFUTierEffect>;
		
		ApplyDefaultValues();
		Print("[SNAFU Gunplay] Hardcoded gunplay config loaded");
	}
	
	void ApplyDefaultValues()
	{
		GlobalRecoilMultiplier = 1.08;
		GlobalSwayMultiplier = 1.08;
		GlobalAimSpeedMultiplier = 0.95;
		EnableHipFireNerf = true;
		EnableWeaponGeometryDamage = true;
		GripRecoilReduction = 0.30;
		GripSwayReduction = 0.30;
		HeavyScopeAimSpeedPenalty = 0.3;
		LightScopeAimSpeedPenalty = 0.1;
		HipFireAccuracyDegradation = 0.65;
		DebugMode = false;
		
		RepairKit_Uses = 4;
		RepairKit_Time = 7.5;
		RepairKit_AllowSuppressors = true;
		
		HighCapMagazineThreshold = 30;
		
		Modifier_Buttstock_Recoil = 0.10;
		Modifier_Buttstock_Sway = 0.55;
		Modifier_PistolGrip_Recoil = 0.55;
		Modifier_PistolGrip_ADS = 1.10;
		Modifier_Foregrip_Recoil = 0.40;
		Modifier_Foregrip_ADS = 1.10;
		Modifier_Handguard_Sway = 0.70;
		Modifier_Handguard_Precision = 1.20;
		Modifier_Bipod_Sway = 0.40;
		Modifier_Bipod_ADS = 0.85;
		Modifier_Laser_HipFire = 0.50;
		Modifier_Flashlight_Sway = 1.03;
		Modifier_Flashlight_ADS = 0.96;
		Modifier_Bayonet_Sway = 1.06;
		Modifier_Bayonet_ADS = 0.94;
		Modifier_HighCapMag_ADS = 0.98;
		Modifier_HighCapMag_Sway = 1.03;
		
		InitDefaultTierEffects();
		InitDefaultAttachmentTiers();
	}
	
	void InitDefaultTierEffects()
	{
		AttachmentTierEffects.Clear();
		
		SetTierEffect("Foregrip_T1", "Foregrip", "T1", 0.70, 0.925, 1.03, 1.05, 0.90);
		SetTierEffect("Foregrip_T2", "Foregrip", "T2", 0.40, 0.85, 1.06, 1.10, 0.80);
		SetTierEffect("Foregrip_T3", "Foregrip", "T3", 0.10, 0.775, 1.08, 1.15, 0.70);
		
		SetTierEffect("PistolGrip_T1", "Pistol Grip", "T1", 0.70, 1.00, 1.05, 1.00, 0.90);
		SetTierEffect("PistolGrip_T2", "Pistol Grip", "T2", 0.40, 0.97, 1.10, 1.02, 0.80);
		SetTierEffect("PistolGrip_T3", "Pistol Grip", "T3", 0.10, 0.94, 1.15, 1.04, 0.70);
		
		SetTierEffect("Stock_T1", "Stock", "T1", 0.70, 0.85, 1.00, 1.05, 1.00);
		SetTierEffect("Stock_T2", "Stock", "T2", 0.40, 0.70, 0.99, 1.10, 1.00);
		SetTierEffect("Stock_T3", "Stock", "T3", 0.10, 0.55, 0.98, 1.15, 1.00);
		
		SetTierEffect("Handguard_T1", "Handguard", "T1", 1.00, 0.85, 1.02, 1.10, 0.90);
		SetTierEffect("Handguard_T2", "Handguard", "T2", 0.94, 0.70, 1.04, 1.20, 0.80);
		SetTierEffect("Handguard_T3", "Handguard", "T3", 0.88, 0.55, 1.06, 1.30, 0.70);
		
		SetTierEffect("Bipod_Special", "Bipod", "Special", 0.70, 0.43, 0.86, 1.16, 1.00);
		SetTierEffect("LightOptic_T1", "Optic", "T1", 1.00, 0.985, 1.05, 1.10, 1.00);
		SetTierEffect("HeavyOptic_T2", "Optic", "T2", 1.00, 0.97, 0.95, 1.20, 1.00);
		SetTierEffect("SniperOptic_T3", "Optic", "T3", 1.00, 0.955, 0.85, 1.30, 1.00);
		SetTierEffect("Laser_Tactical", "Laser", "Tactical", 1.00, 1.00, 1.00, 1.00, 0.55);
		SetTierEffect("Flashlight_Utility", "Flashlight", "Utility", 1.00, 1.04, 0.96, 1.00, 1.00);
		SetTierEffect("Bayonet_Heavy", "Bayonet", "Heavy", 1.00, 1.08, 0.92, 1.00, 1.00);
		SetTierEffect("Muzzle_T1", "Muzzle", "T1", 0.85, 0.925, 1.00, 1.05, 0.95);
		SetTierEffect("Muzzle_T2", "Muzzle", "T2", 0.70, 0.85, 0.99, 1.10, 0.90);
		SetTierEffect("Muzzle_T3", "Muzzle", "T3", 0.55, 0.775, 0.98, 1.15, 0.85);
		SetTierEffect("Suppressor_T1", "Suppressor", "T1", 0.85, 1.00, 0.98, 1.05, 0.95);
		SetTierEffect("Suppressor_T2", "Suppressor", "T2", 0.70, 1.01, 0.96, 1.10, 0.90);
		SetTierEffect("Suppressor_T3", "Suppressor", "T3", 0.55, 1.02, 0.94, 1.15, 0.85);
		SetTierEffect("WeaponWrap_Utility", "Wrap", "Utility", 1.00, 0.925, 0.97, 1.03, 1.00);
		SetTierEffect("StandardMag_Neutral", "Magazine", "Standard", 1.00, 1.00, 1.00, 1.00, 1.00);
		SetTierEffect("HighCap_Heavy", "Magazine", "HighCap", 1.02, 1.03, 0.98, 1.00, 1.00);
		SetTierEffect("Neutral", "Neutral", "Neutral", 1.00, 1.00, 1.00, 1.00, 1.00);
	}
	
	void InitDefaultAttachmentTiers()
	{
		AttachmentTiers.Clear();
		
		SetAttachmentTier("FGRIP", "Foregrip_T1");
		SetAttachmentTier("snafuar15afg", "Foregrip_T2");
		SetAttachmentTier("weaponGripCQR", "Foregrip_T2");
		SetAttachmentTier("weaponGripKAAR", "Foregrip_T3");
		SetAttachmentTier("SNAFU_M249Grip", "Foregrip_T2");
		SetAttachmentTier("SNAFUSR3Grip", "Foregrip_T2");
		SetAttachmentTier("weaponrgripSNAFU", "Foregrip_T2");
		
		SetAttachmentTier("weaponGrip", "PistolGrip_T1");
		SetAttachmentTier("weaponGripAK", "PistolGrip_T2");
		SetAttachmentTier("weaponPistolGrip", "PistolGrip_T2");
		SetAttachmentTier("SNAFUMPXGRIP", "PistolGrip_T2");
		
		SetAttachmentTier("SNAFU_M249Stock", "Stock_T2");
		SetAttachmentTier("SNAFU_M200Stock", "Stock_T3");
		SetAttachmentTier("SNAFU_AK_AR_Stock", "Stock_T2");
		SetAttachmentTier("SNAFU_AK19_Stock", "Stock_T2");
		SetAttachmentTier("M4_OEBttstck", "Stock_T1");
		SetAttachmentTier("M4_MPBttstck", "Stock_T2");
		SetAttachmentTier("M4_CQBBttstck", "Stock_T3");
		SetAttachmentTier("AK_WoodBttstck", "Stock_T1");
		SetAttachmentTier("AK74_WoodBttstck", "Stock_T1");
		SetAttachmentTier("AK_PlasticBttstck", "Stock_T2");
		SetAttachmentTier("AK_FoldingBttstck", "Stock_T2");
		SetAttachmentTier("AKS74U_Bttstck", "Stock_T2");
		SetAttachmentTier("MP5k_StockBttstck", "Stock_T2");
		SetAttachmentTier("Red9Bttstck", "Stock_T1");
		SetAttachmentTier("Fal_OeBttstck", "Stock_T2");
		SetAttachmentTier("Fal_FoldingBttstck", "Stock_T3");
		SetAttachmentTier("Saiga_Bttstck", "Stock_T2");
		SetAttachmentTier("PP19_Bttstck", "Stock_T2");
		SetAttachmentTier("SNAFUWSR3Stock", "Stock_T2");
		
		SetAttachmentTier("SNAFU_M249HG", "Handguard_T2");
		SetAttachmentTier("SNAFUM60Handguard", "Handguard_T2");
		SetAttachmentTier("SNAFUSR3HG", "Handguard_T2");
		SetAttachmentTier("HandguardRIS", "Handguard_T2");
		SetAttachmentTier("M4_OEBHandGuard", "Handguard_T1");
		SetAttachmentTier("M4_MOLLEHandGuard", "Handguard_T2");
		SetAttachmentTier("M4_PlasticHndgrd", "Handguard_T1");
		SetAttachmentTier("M4_RISHndgrd", "Handguard_T2");
		SetAttachmentTier("M4_MPHndgrd", "Handguard_T2");
		SetAttachmentTier("AK_WoodHndgrd", "Handguard_T1");
		SetAttachmentTier("AK74_Hndgrd", "Handguard_T1");
		SetAttachmentTier("AK_PlasticHndgrd", "Handguard_T2");
		SetAttachmentTier("AK_RailHndgrd", "Handguard_T3");
		SetAttachmentTier("MP5_PlasticHndgrd", "Handguard_T1");
		SetAttachmentTier("MP5_RailHndgrd", "Handguard_T2");
		SetAttachmentTier("M249_Hndgrd", "Handguard_T1");
		SetAttachmentTier("M249_RisHndgrd", "Handguard_T2");
		SetAttachmentTier("weaponHGSNAFU10", "Handguard_T2");
		SetAttachmentTier("weaponHGSNAFU10NA", "Handguard_T2");
		SetAttachmentTier("weaponHGSNAFU14", "Handguard_T2");
		SetAttachmentTier("weaponHGSNAFU14NA", "Handguard_T2");
		SetAttachmentTier("weaponHGSNAFU16", "Handguard_T3");
		SetAttachmentTier("weaponHGSNAFU16NA", "Handguard_T3");
		
		SetAttachmentTier("snafuweaponBipod", "Bipod_Special");
		SetAttachmentTier("SNAFU_M249Bipod", "Bipod_Special");
		SetAttachmentTier("SNAFU_M200B_BK", "Bipod_Special");
		SetAttachmentTier("SNAFU_M200Bipod_Base", "Bipod_Special");
		SetAttachmentTier("snafuvsskBipod", "Bipod_Special");
		SetAttachmentTier("sr25bipod", "Bipod_Special");
		SetAttachmentTier("PKPBIPOD", "Bipod_Special");
		
		SetAttachmentTier("SNAFU_RDS", "LightOptic_T1");
		SetAttachmentTier("SNAFU_EOTech_EXPS3", "LightOptic_T1");
		SetAttachmentTier("SNAFU_Aimpoint_M5", "LightOptic_T1");
		SetAttachmentTier("SNAFU_Docter", "LightOptic_T1");
		SetAttachmentTier("SNAFU_Elcan", "LightOptic_T1");
		SetAttachmentTier("SNAFU_Hunting", "SniperOptic_T3");
		SetAttachmentTier("SNAFUM60ScopeMount", "LightOptic_T1");
		SetAttachmentTier("SNAFU_Nightforce", "SniperOptic_T3");
		SetAttachmentTier("SNAFU_AKNightforce", "SniperOptic_T3");
		SetAttachmentTier("SNAFU_HNightforce", "SniperOptic_T3");
		SetAttachmentTier("SNAFU_MNightforce", "SniperOptic_T3");
		SetAttachmentTier("SNAFU_Tango6T", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_Tango6T_Black", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_Tango6T_Tan", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_Tango6T_Wood", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_Tango6T_Snow", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_AKTango6T_Black", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_AKTango6T_Tan", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_AKTango6T_Wood", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_AKTango6T_Snow", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_MTango6T_Black", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_MTango6T_Tan", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_MTango6T_Wood", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_MTango6T_Snow", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_Leupold_MK8", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_Leupold_Mark8", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_AKLeupold_Mark8", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_HLeupold_Mark8", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_MLeupold_Mark8", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_Kahles", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_AKKahles", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_HKahles", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_MKahles", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_Walther", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_AKWalther", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_HWalther", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_MWalther", "HeavyOptic_T2");
		SetAttachmentTier("GCGN_M84_Optic", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_AKHuntingOptic", "SniperOptic_T3");
		SetAttachmentTier("SNAFU_HHuntingOptic", "SniperOptic_T3");
		SetAttachmentTier("SNAFU_HuntingOptic", "SniperOptic_T3");
		SetAttachmentTier("SNAFU_M14Optic", "HeavyOptic_T2");
		SetAttachmentTier("SNAFU_MHuntingOptic", "SniperOptic_T3");
		SetAttachmentTier("M4_CarryHandleOptic", "LightOptic_T1");
		SetAttachmentTier("BUISOptic", "LightOptic_T1");
		SetAttachmentTier("M68Optic", "LightOptic_T1");
		SetAttachmentTier("M4_T3NRDSOptic", "LightOptic_T1");
		SetAttachmentTier("FNP45_MRDSOptic", "LightOptic_T1");
		SetAttachmentTier("ReflexOptic", "LightOptic_T1");
		SetAttachmentTier("KobraOptic", "LightOptic_T1");
		SetAttachmentTier("PistolOptic", "LightOptic_T1");
		SetAttachmentTier("SportingOptic", "LightOptic_T1");
		SetAttachmentTier("ACOGOptic", "HeavyOptic_T2");
		SetAttachmentTier("ACOGOptic_6x", "HeavyOptic_T2");
		SetAttachmentTier("PSO1Optic", "HeavyOptic_T2");
		SetAttachmentTier("PSO11Optic", "HeavyOptic_T2");
		SetAttachmentTier("PSO6Optic", "HeavyOptic_T2");
		SetAttachmentTier("GrozaOptic", "HeavyOptic_T2");
		SetAttachmentTier("KashtanOptic", "LightOptic_T1");
		SetAttachmentTier("PUScopeOptic", "HeavyOptic_T2");
		SetAttachmentTier("LongrangeOptic", "SniperOptic_T3");
		SetAttachmentTier("HuntingOptic", "SniperOptic_T3");
		SetAttachmentTier("MK4Optic_ColorBase", "HeavyOptic_T2");
		SetAttachmentTier("MK4Optic_Tan", "HeavyOptic_T2");
		SetAttachmentTier("MK4Optic_Green", "HeavyOptic_T2");
		SetAttachmentTier("MK4Optic_Black", "HeavyOptic_T2");
		SetAttachmentTier("KazuarOptic", "HeavyOptic_T2");
		SetAttachmentTier("StarlightOptic", "HeavyOptic_T2");
		SetAttachmentTier("ExpansionDeltapointOptic", "LightOptic_T1");
		SetAttachmentTier("ExpansionEXPS3HoloOptic", "LightOptic_T1");
		SetAttachmentTier("ExpansionHAMROptic", "HeavyOptic_T2");
		SetAttachmentTier("ExpansionKar98ScopeOptic", "SniperOptic_T3");
		SetAttachmentTier("Expansion_PMII25Optic", "SniperOptic_T3");
		SetAttachmentTier("ExpansionReflexMRSOptic", "LightOptic_T1");
		SetAttachmentTier("Expansion_M1A_RailAtt", "Handguard_T1");
		SetAttachmentTier("Expansion_MP5_RailAtt", "Handguard_T1");
		
		SetAttachmentTier("weaponLaserPointer", "Laser_Tactical");
		SetAttachmentTier("weaponLaser", "Laser_Tactical");
		SetAttachmentTier("PistolLaserPointer", "Laser_Tactical");
		SetAttachmentTier("SNAFUPEQLASER", "Laser_Tactical");
		SetAttachmentTier("Expansion_ANPEQ15_Base", "Laser_Tactical");
		SetAttachmentTier("Expansion_ANPEQ15_Red", "Laser_Tactical");
		SetAttachmentTier("Expansion_ANPEQ15_Green", "Laser_Tactical");
		SetAttachmentTier("Expansion_ANPEQ15_GreenNV", "Laser_Tactical");
		SetAttachmentTier("Expansion_ANPEQ15_IR", "Laser_Tactical");
		
		SetAttachmentTier("weaponFlashlight", "Flashlight_Utility");
		SetAttachmentTier("weaponFlashlightRail", "Flashlight_Utility");
		SetAttachmentTier("TLRLight", "Flashlight_Utility");
		SetAttachmentTier("UniversalLight", "Flashlight_Utility");
		
		SetAttachmentTier("weaponBayonet", "Bayonet_Heavy");
		SetAttachmentTier("Bayonet", "Bayonet_Heavy");
		SetAttachmentTier("M9A1Bayonet", "Bayonet_Heavy");
		SetAttachmentTier("AK_Bayonet", "Bayonet_Heavy");
		SetAttachmentTier("M9A1_Bayonet", "Bayonet_Heavy");
		SetAttachmentTier("Mosin_Bayonet", "Bayonet_Heavy");
		SetAttachmentTier("SKS_Bayonet", "Bayonet_Heavy");
		SetAttachmentTier("SNAFU_SKS_Bayonet", "Bayonet_Heavy");
		SetAttachmentTier("GCGN_M1Garand_Bayonet", "Bayonet_Heavy");
		SetAttachmentTier("Expansion_Kar98_Bayonet", "Bayonet_Heavy");
		
		SetAttachmentTier("Mosin_Compensator", "Muzzle_T1");
		SetAttachmentTier("MP5_Compensator", "Muzzle_T1");
		SetAttachmentTier("Aug_Barrel", "Muzzle_T1");
		SetAttachmentTier("Groza_Barrel_Short", "Muzzle_T1");
		SetAttachmentTier("GCGN_M1Garand_Muzzle", "Muzzle_T1");
		SetAttachmentTier("SNAFUShotgunchoke", "Muzzle_T1");
		SetAttachmentTier("Groza_Barrel_Grip", "Muzzle_T2");
		SetAttachmentTier("sr25Muzzle", "Muzzle_T2");
		SetAttachmentTier("snafu50bmg", "Muzzle_T3");
		
		SetAttachmentTier("ImprovisedSuppressor", "Suppressor_T1");
		SetAttachmentTier("MakarovPBSuppressor", "Suppressor_T1");
		SetAttachmentTier("ItemSuppressor", "Suppressor_T1");
		SetAttachmentTier("22LRSuppressor", "Suppressor_T1");
		SetAttachmentTier("M4_Suppressor", "Suppressor_T2");
		SetAttachmentTier("AK_Suppressor", "Suppressor_T2");
		SetAttachmentTier("PistolSuppressor", "Suppressor_T2");
		SetAttachmentTier("Groza_Barrel_Suppressor", "Suppressor_T2");
		SetAttachmentTier("ASH12Suppressor", "Suppressor_T2");
		SetAttachmentTier("MP7A2Suppressor", "Suppressor_T2");
		SetAttachmentTier("Suppressor9A91", "Suppressor_T2");
		SetAttachmentTier("SNAFU_Normalized_Suppressor_Base", "Suppressor_T2");
		SetAttachmentTier("SNAFU_Normalized_Suppressor_Black", "Suppressor_T2");
		SetAttachmentTier("SNAFU_Normalized_Suppressor_Green", "Suppressor_T2");
		SetAttachmentTier("SNAFU_Standardized_Suppressor_Base", "Suppressor_T2");
		SetAttachmentTier("SNAFU_Standardized_Suppressor_Black", "Suppressor_T2");
		SetAttachmentTier("SNAFU_Standardized_Suppressor_Green", "Suppressor_T2");
		SetAttachmentTier("SNAFU_MPX_Suppressor_Base", "Suppressor_T2");
		SetAttachmentTier("SNAFU_MPX_Suppressor_Black", "Suppressor_T2");
		SetAttachmentTier("SNAFU_Agram_Suppressor_Base", "Suppressor_T2");
		SetAttachmentTier("SNAFU_Agram_Suppressor_Black", "Suppressor_T2");
		SetAttachmentTier("SNAFU_SPMOD", "Suppressor_T2");
		SetAttachmentTier("SNAFUSR3_SuppBase", "Suppressor_T2");
		SetAttachmentTier("SNAFU_SR3Vikhr_Supp", "Suppressor_T2");
		SetAttachmentTier("SR3_Vikhr_Supp", "Suppressor_T2");
		SetAttachmentTier("SNAFUAR15_SPR_SIL_Base", "Suppressor_T2");
		SetAttachmentTier("SNAFUAR15_SPR_SIL", "Suppressor_T2");
		SetAttachmentTier("HoneyBadgerSuppressor", "Suppressor_T3");
		SetAttachmentTier("QDLSuppressor", "Suppressor_T3");
		SetAttachmentTier("SNAFU338_Suppressor", "Suppressor_T3");
		SetAttachmentTier("snafu300acsupp", "Suppressor_T3");
		SetAttachmentTier("SNAFU_SR25_Supp_Base", "Suppressor_T3");
		SetAttachmentTier("SNAFU_SR25_Supp", "Suppressor_T3");
		SetAttachmentTier("SNAFUKivaari_338_Supp_Base", "Suppressor_T3");
		SetAttachmentTier("SNAFUKivaari_338_Supp", "Suppressor_T3");
		SetAttachmentTier("Snafu_ScarH_SIL_Base", "Suppressor_T3");
		SetAttachmentTier("Snafu_ScarH_SIL_Tan", "Suppressor_T3");
		SetAttachmentTier("Snafu_ScarH_SIL_Black", "Suppressor_T3");
		SetAttachmentTier("SNAFUGevar_Suppressor_Black", "Suppressor_T3");
		SetAttachmentTier("SNAFUGevar_Suppressor_Tan", "Suppressor_T3");
		SetAttachmentTier("SNAFUGevar_Suppressor_Green", "Suppressor_T3");
		SetAttachmentTier("SNAFU_LNormalized_Suppressor_Base", "Suppressor_T3");
		SetAttachmentTier("SNAFU_LNormalized_Suppressor_Black", "Suppressor_T3");
		SetAttachmentTier("SNAFU_LNormalized_Suppressor_Green", "Suppressor_T3");
		SetAttachmentTier("SNAFU_LStandardized_Suppressor_Base", "Suppressor_T3");
		SetAttachmentTier("SNAFU_LStandardized_Suppressor_Black", "Suppressor_T3");
		SetAttachmentTier("SNAFU_LStandardized_Suppressor_Green", "Suppressor_T3");
		SetAttachmentTier("SNAFU_50bmg_Suppressor_Base", "Suppressor_T3");
		SetAttachmentTier("SNAFU_50bmg_Suppressor_B", "Suppressor_T3");
		SetAttachmentTier("SNAFU_50bmg_Suppressor_M", "Suppressor_T3");
		SetAttachmentTier("SNAFU_50bmg_Suppressor_S", "Suppressor_T3");
		SetAttachmentTier("SNAFU_50bmg_Suppressor_U", "Suppressor_T3");
		SetAttachmentTier("SNAFU_50bmg_Suppressor_W", "Suppressor_T3");
		SetAttachmentTier("SNAFU_408_Suppressor_T", "Suppressor_T3");
		SetAttachmentTier("SNAFUAR15_SPR_SQSIL_Base", "Suppressor_T3");
		SetAttachmentTier("SNAFUAR15_SPR_SQSIL", "Suppressor_T3");
		
		SetAttachmentTier("GhillieAtt_ColorBase", "WeaponWrap_Utility");
		SetAttachmentTier("Groza_LowerReceiver", "Handguard_T2");
		SetAttachmentTier("GrozaGL_LowerReceiver", "Handguard_T2");
		
		SetAttachmentTier("Mag_Expansion_M9_15Rnd", "StandardMag_Neutral");
		SetAttachmentTier("Mag_Expansion_G36_30Rnd", "StandardMag_Neutral");
		SetAttachmentTier("Mag_Expansion_M14_10Rnd", "StandardMag_Neutral");
		SetAttachmentTier("Mag_Expansion_M14_20Rnd", "StandardMag_Neutral");
		SetAttachmentTier("Mag_Expansion_MPX_50Rnd", "HighCap_Heavy");
		SetAttachmentTier("Mag_Expansion_MP7_40Rnd", "HighCap_Heavy");
		SetAttachmentTier("Mag_Expansion_Kedr_20Rnd", "StandardMag_Neutral");
		SetAttachmentTier("Mag_Expansion_Vityaz_30Rnd", "StandardMag_Neutral");
		SetAttachmentTier("Mag_Expansion_AWM_5rnd", "StandardMag_Neutral");
	}
	
	void SetAttachmentTier(string className, string tierKey)
	{
		if (!AttachmentTiers) AttachmentTiers = new map<string, string>;
		AttachmentTiers.Set(className, tierKey);
	}
	
	void SetTierEffect(string key, string category, string tier, float recoil, float sway, float ads, float precision, float hipFire)
	{
		if (!AttachmentTierEffects) AttachmentTierEffects = new map<string, ref SNAFUTierEffect>;
		AttachmentTierEffects.Set(key, new SNAFUTierEffect(category, tier, recoil, sway, ads, precision, hipFire));
	}
	
	string GetAttachmentTier(string className, string fallbackTier = "Neutral")
	{
		if (AttachmentTiers && AttachmentTiers.Contains(className))
		{
			return AttachmentTiers.Get(className);
		}
		
		return fallbackTier;
	}
	
	SNAFUTierEffect GetTierEffect(string tierKey)
	{
		if (AttachmentTierEffects && AttachmentTierEffects.Contains(tierKey))
		{
			return AttachmentTierEffects.Get(tierKey);
		}
		
		if (AttachmentTierEffects && AttachmentTierEffects.Contains("Neutral"))
		{
			return AttachmentTierEffects.Get("Neutral");
		}
		
		return new SNAFUTierEffect();
	}
	
	void ResetToDefaults()
	{
		ApplyDefaultValues();
		Print("[SNAFU Gunplay] Config reset to hardcoded defaults");
	}
}
