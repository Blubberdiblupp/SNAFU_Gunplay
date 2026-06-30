class SNAFUAttachmentTierOverride
{
	string ClassName;
	string TierKey;
	
	void SNAFUAttachmentTierOverride(string className = "", string tierKey = "")
	{
		ClassName = className;
		TierKey = tierKey;
	}
}

class SNAFUTierMultiplierOverride
{
	string TierKey;
	float Recoil;
	float Sway;
	float ADS;
	float Precision;
	float HipFire;
	
	void SNAFUTierMultiplierOverride(string tierKey = "", float recoil = 1.0, float sway = 1.0, float ads = 1.0, float precision = 1.0, float hipFire = 1.0)
	{
		TierKey = tierKey;
		Recoil = recoil;
		Sway = sway;
		ADS = ads;
		Precision = precision;
		HipFire = hipFire;
	}
}

class SNAFUAttachmentStatOverride
{
	string ClassName;
	string Category;
	string Tier;
	float Recoil;
	float Sway;
	float ADS;
	float Precision;
	float HipFire;
	
	void SNAFUAttachmentStatOverride(string className = "", string category = "Custom", string tier = "Custom", float recoil = 1.0, float sway = 1.0, float ads = 1.0, float precision = 1.0, float hipFire = 1.0)
	{
		ClassName = className;
		Category = category;
		Tier = tier;
		Recoil = recoil;
		Sway = sway;
		ADS = ads;
		Precision = precision;
		HipFire = hipFire;
	}
}

class SNAFUGunplayAdminConfig
{
	static const int CurrentConfigVersion = 1;
	static const string ConfigDir = "$profile:\\SNAFU_Gunplay";
	static const string ConfigPath = "$profile:\\SNAFU_Gunplay\\SNAFU_Gunplay.json";
	
	int ConfigVersion;
	int CrosshairMode;
	bool EnableTooltipStats;
	bool EnableInspectStats;
	bool EnableExpansionMarketStats;
	bool EnableHipFireNerf;
	bool EnableWeaponGeometryDamage;
	bool DebugMode;
	
	float GlobalRecoilMultiplier;
	float GlobalSwayMultiplier;
	float GlobalAimSpeedMultiplier;
	float GlobalHipFireMultiplier;
	float GlobalPrecisionMultiplier;
	int HighCapMagazineThreshold;
	
	ref array<ref SNAFUAttachmentTierOverride> AttachmentTierOverrides;
	ref array<ref SNAFUTierMultiplierOverride> TierMultiplierOverrides;
	ref array<ref SNAFUAttachmentStatOverride> AttachmentStatOverrides;
	
	void SNAFUGunplayAdminConfig()
	{
		SetDefaults();
	}
	
	void SetDefaults()
	{
		ConfigVersion = CurrentConfigVersion;
		CrosshairMode = 1;
		EnableTooltipStats = true;
		EnableInspectStats = true;
		EnableExpansionMarketStats = true;
		EnableHipFireNerf = true;
		EnableWeaponGeometryDamage = true;
		DebugMode = false;
		
		GlobalRecoilMultiplier = 1.08;
		GlobalSwayMultiplier = 1.08;
		GlobalAimSpeedMultiplier = 0.95;
		GlobalHipFireMultiplier = 1.0;
		GlobalPrecisionMultiplier = 1.0;
		HighCapMagazineThreshold = 30;
		
		AttachmentTierOverrides = new array<ref SNAFUAttachmentTierOverride>;
		TierMultiplierOverrides = new array<ref SNAFUTierMultiplierOverride>;
		AttachmentStatOverrides = new array<ref SNAFUAttachmentStatOverride>;
	}
	
	void EnsureDefaults()
	{
		if (!AttachmentTierOverrides)
		{
			AttachmentTierOverrides = new array<ref SNAFUAttachmentTierOverride>;
		}
		
		if (!TierMultiplierOverrides)
		{
			TierMultiplierOverrides = new array<ref SNAFUTierMultiplierOverride>;
		}
		
		if (!AttachmentStatOverrides)
		{
			AttachmentStatOverrides = new array<ref SNAFUAttachmentStatOverride>;
		}
		
		MigrateConfig();
		
		if (CrosshairMode < 0)
		{
			CrosshairMode = 0;
		}
		
		if (CrosshairMode > 2)
		{
			CrosshairMode = 2;
		}
		
		if (GlobalRecoilMultiplier <= 0.0)
		{
			GlobalRecoilMultiplier = 1.08;
		}
		
		if (GlobalSwayMultiplier <= 0.0)
		{
			GlobalSwayMultiplier = 1.08;
		}
		
		if (GlobalAimSpeedMultiplier <= 0.0)
		{
			GlobalAimSpeedMultiplier = 0.95;
		}
		
		if (GlobalHipFireMultiplier <= 0.0)
		{
			GlobalHipFireMultiplier = 1.0;
		}
		
		if (GlobalPrecisionMultiplier <= 0.0)
		{
			GlobalPrecisionMultiplier = 1.0;
		}
		
		if (HighCapMagazineThreshold <= 0)
		{
			HighCapMagazineThreshold = 30;
		}
		
		SNAFUGunplayAdminDefaults.FillMissingDefaults(this);
		Validate();
	}
	
	bool MigrateConfig()
	{
		bool changed = false;
		
		if (ConfigVersion <= 0)
		{
			ConfigVersion = 1;
			changed = true;
		}
		
		if (ConfigVersion < CurrentConfigVersion)
		{
			ConfigVersion = CurrentConfigVersion;
			changed = true;
		}
		
		return changed;
	}
	
	void Validate()
	{
		if (ConfigVersion < 1) ConfigVersion = CurrentConfigVersion;
		if (CrosshairMode < 0) CrosshairMode = 0;
		if (CrosshairMode > 2) CrosshairMode = 2;
		
		GlobalRecoilMultiplier = ClampFloat(GlobalRecoilMultiplier, 0.01, 5.0);
		GlobalSwayMultiplier = ClampFloat(GlobalSwayMultiplier, 0.01, 5.0);
		GlobalAimSpeedMultiplier = ClampFloat(GlobalAimSpeedMultiplier, 0.01, 5.0);
		GlobalHipFireMultiplier = ClampFloat(GlobalHipFireMultiplier, 0.01, 5.0);
		GlobalPrecisionMultiplier = ClampFloat(GlobalPrecisionMultiplier, 0.01, 5.0);
		
		if (HighCapMagazineThreshold < 1) HighCapMagazineThreshold = 1;
		if (HighCapMagazineThreshold > 500) HighCapMagazineThreshold = 500;
		
		foreach (SNAFUTierMultiplierOverride tierOverride : TierMultiplierOverrides)
		{
			ValidateTierMultiplierOverride(tierOverride);
		}
		
		foreach (SNAFUAttachmentStatOverride statOverride : AttachmentStatOverrides)
		{
			ValidateAttachmentStatOverride(statOverride);
		}
	}
	
	float ClampFloat(float value, float minValue, float maxValue)
	{
		if (value < minValue)
		{
			return minValue;
		}
		
		if (value > maxValue)
		{
			return maxValue;
		}
		
		return value;
	}
	
	void ValidateTierMultiplierOverride(SNAFUTierMultiplierOverride tierOverride)
	{
		if (!tierOverride)
		{
			return;
		}
		
		tierOverride.Recoil = ClampFloat(tierOverride.Recoil, 0.01, 5.0);
		tierOverride.Sway = ClampFloat(tierOverride.Sway, 0.01, 5.0);
		tierOverride.ADS = ClampFloat(tierOverride.ADS, 0.01, 5.0);
		tierOverride.Precision = ClampFloat(tierOverride.Precision, 0.01, 5.0);
		tierOverride.HipFire = ClampFloat(tierOverride.HipFire, 0.01, 5.0);
	}
	
	void ValidateAttachmentStatOverride(SNAFUAttachmentStatOverride statOverride)
	{
		if (!statOverride)
		{
			return;
		}
		
		statOverride.Recoil = ClampFloat(statOverride.Recoil, 0.01, 5.0);
		statOverride.Sway = ClampFloat(statOverride.Sway, 0.01, 5.0);
		statOverride.ADS = ClampFloat(statOverride.ADS, 0.01, 5.0);
		statOverride.Precision = ClampFloat(statOverride.Precision, 0.01, 5.0);
		statOverride.HipFire = ClampFloat(statOverride.HipFire, 0.01, 5.0);
	}
	
	void Load()
	{
		if (!GetGame().IsServer())
		{
			EnsureDefaults();
			return;
		}
		
		if (FileExist(ConfigPath))
		{
			JsonFileLoader<SNAFUGunplayAdminConfig>.JsonLoadFile(ConfigPath, this);
			EnsureDefaults();
			Save();
			Print("[SNAFU Gunplay] Admin JSON loaded");
			return;
		}
		
		MakeDirectory(ConfigDir);
		EnsureDefaults();
		Save();
		Print("[SNAFU Gunplay] Admin JSON created with defaults");
	}
	
	void Save()
	{
		if (GetGame().IsServer())
		{
			JsonFileLoader<SNAFUGunplayAdminConfig>.JsonSaveFile(ConfigPath, this);
		}
	}
}

static ref SNAFUGunplayAdminConfig m_SNAFUGunplayAdminConfig;

static SNAFUGunplayAdminConfig SNAFUGetAdminConfig()
{
	if (!m_SNAFUGunplayAdminConfig)
	{
		m_SNAFUGunplayAdminConfig = new SNAFUGunplayAdminConfig();
		m_SNAFUGunplayAdminConfig.Load();
	}
	
	return m_SNAFUGunplayAdminConfig;
}

static void SNAFUSetAdminConfig(SNAFUGunplayAdminConfig config)
{
	if (!config)
	{
		return;
	}
	
	config.EnsureDefaults();
	m_SNAFUGunplayAdminConfig = config;
	
	if (SNAFUGunplayConfig.m_Instance)
	{
		SNAFUGunplayConfig.m_Instance.ResetToDefaults();
	}
}
