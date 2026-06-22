class SNAFUAttachmentStats
{
	protected static ref map<string, string> m_SlotTierFallbacks;
	
	static SNAFUTierEffect GetEffect(EntityAI item)
	{
		string tierKey = GetTierKey(item);
		if (tierKey == "")
		{
			return null;
		}
		
		return SNAFUGunplayConfig.GetInstance().GetTierEffect(tierKey);
	}
	
	static SNAFUTierEffect GetEffectByType(string itemType)
	{
		string tierKey = GetTierKeyByType(itemType);
		if (tierKey == "")
		{
			return null;
		}
		
		return SNAFUGunplayConfig.GetInstance().GetTierEffect(tierKey);
	}
	
	static string GetTierKey(EntityAI item)
	{
		if (!item)
		{
			return "";
		}
		
		SNAFUGunplayConfig config = SNAFUGunplayConfig.GetInstance();
		if (!config)
		{
			return "";
		}
		
		string tierKey = config.GetAttachmentTier(item.GetType(), "");
		if (tierKey != "")
		{
			return tierKey;
		}
		
		int magCount = GetGame().ConfigGetInt("CfgMagazines " + item.GetType() + " count");
		if (magCount > config.HighCapMagazineThreshold)
		{
			return "HighCap_Heavy";
		}
		
		if (magCount > 0)
		{
			return "StandardMag_Neutral";
		}
		
		return GetTierKeyFromInventorySlot(item);
	}
	
	static string GetTierKeyByType(string itemType)
	{
		if (itemType == "")
		{
			return "";
		}
		
		SNAFUGunplayConfig config = SNAFUGunplayConfig.GetInstance();
		if (!config)
		{
			return "";
		}
		
		string tierKey = config.GetAttachmentTier(itemType, "");
		if (tierKey != "")
		{
			return tierKey;
		}
		
		int magCount = GetGame().ConfigGetInt("CfgMagazines " + itemType + " count");
		if (magCount > config.HighCapMagazineThreshold)
		{
			return "HighCap_Heavy";
		}
		
		if (magCount > 0)
		{
			return "StandardMag_Neutral";
		}
		
		return GetTierKeyFromInventorySlotByType(itemType);
	}
	
	static string GetTierKeyFromInventorySlot(EntityAI item)
	{
		if (!item)
		{
			return "";
		}
		
		EnsureSlotTierFallbacks();
		
		TStringArray slots = new TStringArray;
		item.ConfigGetTextArray("inventorySlot", slots);
		
		foreach (string slot : slots)
		{
			string tierKey = ResolveTierFromSlot(slot);
			if (tierKey != "")
			{
				return tierKey;
			}
		}
		
		string singleSlot = item.ConfigGetString("inventorySlot");
		return ResolveTierFromSlot(singleSlot);
	}
	
	static string GetTierKeyFromInventorySlotByType(string itemType)
	{
		if (itemType == "")
		{
			return "";
		}
		
		EnsureSlotTierFallbacks();
		
		TStringArray slots = new TStringArray;
		GetGame().ConfigGetTextArray("CfgVehicles " + itemType + " inventorySlot", slots);
		
		foreach (string slot : slots)
		{
			string tierKey = ResolveTierFromSlot(slot);
			if (tierKey != "")
			{
				return tierKey;
			}
		}
		
		return "";
	}
	
	static string ResolveTierFromSlot(string slotName)
	{
		if (slotName == "")
		{
			return "";
		}
		
		EnsureSlotTierFallbacks();
		
		if (m_SlotTierFallbacks.Contains(slotName))
		{
			return m_SlotTierFallbacks.Get(slotName);
		}
		
		return "";
	}
	
	static string BuildTooltipText(EntityAI item, string tooltip)
	{
		string statsText = BuildStatsText(item);
		if (statsText == "")
		{
			return tooltip;
		}
		
		if (tooltip == "")
		{
			return statsText;
		}
		
		return tooltip + "\n\n" + statsText;
	}
	
	static string BuildStatsText(EntityAI item)
	{
		SNAFUTierEffect effect = GetEffect(item);
		if (!effect)
		{
			return "";
		}
		
		string text = "SNAFU Gunplay\n";
		text += "Tier: " + effect.GetLabel() + "\n";
		text += "Recoil: " + FormatDelta(effect.Recoil) + "\n";
		text += "Sway: " + FormatDelta(effect.Sway) + "\n";
		text += "ADS: " + FormatDelta(effect.ADS) + "\n";
		text += "Precision: " + FormatDelta(effect.Precision) + "\n";
		text += "HipFire: " + FormatDelta(effect.HipFire);
		
		return text;
	}
	
	static string FormatDelta(float multiplier)
	{
		if (Math.AbsFloat(multiplier - 1.0) < 0.001)
		{
			return "0%";
		}
		
		int rounded = Math.Round((multiplier - 1.0) * 100.0);
		if (rounded > 0)
		{
			return string.Format("+%1%%", rounded);
		}
		
		return string.Format("%1%%", rounded);
	}
	
	static int GetDeltaColor(float multiplier, bool higherIsBetter)
	{
		if (Math.AbsFloat(multiplier - 1.0) < 0.001)
		{
			return 0xFFFFFFFF;
		}
		
		bool improved;
		if (higherIsBetter)
		{
			improved = multiplier > 1.0;
		}
		else
		{
			improved = multiplier < 1.0;
		}
		
		if (improved)
		{
			return 0xFF22DD66;
		}
		
		return 0xFFFF5555;
	}
	
	protected static void EnsureSlotTierFallbacks()
	{
		if (m_SlotTierFallbacks)
		{
			return;
		}
		
		m_SlotTierFallbacks = new map<string, string>;
		
		AddSlotTier("FGRIP", "Foregrip_T1");
		AddSlotTier("weaponForegrip", "Foregrip_T1");
		AddSlotTier("snafuar15afg", "Foregrip_T2");
		AddSlotTier("weaponGripCQR", "Foregrip_T2");
		AddSlotTier("weaponGripKAAR", "Foregrip_T3");
		AddSlotTier("SNAFUM249Grip", "Foregrip_T2");
		AddSlotTier("SNAFUSR3Grip", "Foregrip_T2");
		AddSlotTier("weaponrgripSNAFU", "Foregrip_T2");
		
		AddSlotTier("weaponAKPistolGrip", "PistolGrip_T2");
		AddSlotTier("weaponM4PistolGrip", "PistolGrip_T2");
		AddSlotTier("weaponFALPistolGrip", "PistolGrip_T2");
		AddSlotTier("weaponevopistolgrip", "PistolGrip_T2");
		AddSlotTier("SNAFUMPXGRIP", "PistolGrip_T2");
		
		AddSlotTier("weaponButtstock", "Stock_T1");
		AddSlotTier("weaponButtstockAK", "Stock_T2");
		AddSlotTier("weaponButtstockM4", "Stock_T2");
		AddSlotTier("weaponButtstockCQR", "Stock_T3");
		AddSlotTier("weaponButtstockADAR", "Stock_T2");
		AddSlotTier("weaponButtstockFal", "Stock_T3");
		AddSlotTier("weaponButtstockG36", "Stock_T2");
		AddSlotTier("weaponMP5Buttstock", "Stock_T2");
		AddSlotTier("weaponPKButtstock", "Stock_T2");
		AddSlotTier("weaponScarButtstock", "Stock_T2");
		AddSlotTier("weaponSpas12Buttstock", "Stock_T2");
		AddSlotTier("weaponVectorButtstock", "Stock_T2");
		AddSlotTier("weaponump45buttstock", "Stock_T2");
		AddSlotTier("weaponevobuttstock", "Stock_T2");
		AddSlotTier("MossbergStock", "Stock_T1");
		AddSlotTier("weaponTubeStockAdapterAK", "Stock_T2");
		AddSlotTier("weaponTubeStockAdapterASVAL", "Stock_T2");
		AddSlotTier("weaponTubeStockAdapterScar", "Stock_T2");
		AddSlotTier("weaponTubeStockAdapterSVD", "Stock_T2");
		AddSlotTier("weaponTubeStockAdapterVector", "Stock_T2");
		AddSlotTier("SNAFUM200Stock", "Stock_T3");
		AddSlotTier("SNAFUM249Stock", "Stock_T2");
		AddSlotTier("SNAFUWSR3Stock", "Stock_T2");
		
		AddSlotTier("weaponHandguard", "Handguard_T1");
		AddSlotTier("WeaponHandguardAK", "Handguard_T2");
		AddSlotTier("weaponHandguardASVAL", "Handguard_T2");
		AddSlotTier("weaponHandguardFAL", "Handguard_T2");
		AddSlotTier("weaponHandguardHK", "Handguard_T2");
		AddSlotTier("weaponHandguardHKG28", "Handguard_T2");
		AddSlotTier("weaponHandguardM16", "Handguard_T2");
		AddSlotTier("WeaponHandguardM4", "Handguard_T2");
		AddSlotTier("weaponHandguardM4", "Handguard_T2");
		AddSlotTier("weaponHandguardPK", "Handguard_T2");
		AddSlotTier("weaponForearmMP5", "Handguard_T1");
		AddSlotTier("weaponForearmMP5k", "Handguard_T1");
		AddSlotTier("MossbergForearm", "Handguard_T1");
		AddSlotTier("MP153Forearm", "Handguard_T1");
		AddSlotTier("weaponHGAdarNA", "Handguard_T1");
		AddSlotTier("weaponHGSNAFU10", "Handguard_T2");
		AddSlotTier("weaponHGSNAFU10NA", "Handguard_T2");
		AddSlotTier("weaponHGSNAFU14", "Handguard_T2");
		AddSlotTier("weaponHGSNAFU14NA", "Handguard_T2");
		AddSlotTier("weaponHGSNAFU16", "Handguard_T3");
		AddSlotTier("weaponHGSNAFU16NA", "Handguard_T3");
		AddSlotTier("SNAFUM249HG", "Handguard_T2");
		AddSlotTier("SNAFUM60Handguard", "Handguard_T2");
		AddSlotTier("SNAFUSR3HG", "Handguard_T2");
		AddSlotTier("SNAFUWeaponHandguardAK", "Handguard_T2");
		
		AddSlotTier("weaponBipod", "Bipod_Special");
		AddSlotTier("snafuweaponBipod", "Bipod_Special");
		AddSlotTier("SNAFUM200Bipod", "Bipod_Special");
		AddSlotTier("SNAFUM249Bipod", "Bipod_Special");
		AddSlotTier("snafuvsskBipod", "Bipod_Special");
		AddSlotTier("sr25bipod", "Bipod_Special");
		AddSlotTier("PKPBIPOD", "Bipod_Special");
		
		AddSlotTier("weaponOptics", "LightOptic_T1");
		AddSlotTier("weaponOpticsAK", "LightOptic_T1");
		AddSlotTier("weaponOpticsCrossbow", "LightOptic_T1");
		AddSlotTier("pistolOptics", "LightOptic_T1");
		AddSlotTier("SNAFUSIGHT", "LightOptic_T1");
		AddSlotTier("weaponOpticMount", "LightOptic_T1");
		AddSlotTier("weaponOpticMountAK", "LightOptic_T1");
		AddSlotTier("weaponOpticMountM16", "LightOptic_T1");
		AddSlotTier("weaponFALOpticMount", "LightOptic_T1");
		AddSlotTier("weaponMP5OpticMount", "LightOptic_T1");
		AddSlotTier("weaponPKOpticMount", "LightOptic_T1");
		AddSlotTier("weaponSKSOpticMount", "LightOptic_T1");
		AddSlotTier("MossbergOpticMount", "LightOptic_T1");
		AddSlotTier("SNAFUM60ScopeMount", "LightOptic_T1");
		AddSlotTier("GCGN_M84_Optic", "HeavyOptic_T2");
		AddSlotTier("SNAFU_Nightforce", "SniperOptic_T3");
		AddSlotTier("SNAFU_AKNightforce", "SniperOptic_T3");
		AddSlotTier("SNAFU_HNightforce", "SniperOptic_T3");
		AddSlotTier("SNAFU_MNightforce", "SniperOptic_T3");
		AddSlotTier("SNAFU_AKHuntingOptic", "SniperOptic_T3");
		AddSlotTier("SNAFU_HHuntingOptic", "SniperOptic_T3");
		AddSlotTier("SNAFU_HuntingOptic", "SniperOptic_T3");
		AddSlotTier("SNAFU_M14Optic", "HeavyOptic_T2");
		AddSlotTier("SNAFU_MHuntingOptic", "SniperOptic_T3");
		AddSlotTier("weaponOpticsHunting", "SniperOptic_T3");
		AddSlotTier("weaponOpticsMosin", "SniperOptic_T3");
		AddSlotTier("ExpansionSniperOptics", "SniperOptic_T3");
		AddSlotTier("ExpansionKar98Optics", "SniperOptic_T3");
		AddSlotTier("Expansion_M1AScopeRail", "Handguard_T1");
		AddSlotTier("Expansion_MP5ScopeRail", "Handguard_T1");
		
		AddSlotTier("weaponFlashlight", "Flashlight_Utility");
		AddSlotTier("weaponLightLeft", "Flashlight_Utility");
		AddSlotTier("weaponLightRight", "Flashlight_Utility");
		AddSlotTier("weaponLightTop", "Flashlight_Utility");
		AddSlotTier("pistolFlashlight", "Flashlight_Utility");
		AddSlotTier("helmetFlashlight", "Flashlight_Utility");
		AddSlotTier("SNAFUPEQLASER", "Laser_Tactical");
		
		AddSlotTier("weaponBayonet", "Bayonet_Heavy");
		AddSlotTier("weaponBayonetAK", "Bayonet_Heavy");
		AddSlotTier("weaponBayonetSKS", "Bayonet_Heavy");
		AddSlotTier("expansionWeaponBayonetKar", "Bayonet_Heavy");
		AddSlotTier("GCGN_M1Garand_Bayonet", "Bayonet_Heavy");
		AddSlotTier("SNAFU_SKS_Bayonet", "Bayonet_Heavy");
		
		AddSlotTier("weaponMuzzleM4", "Muzzle_T1");
		AddSlotTier("weaponMuzzleAK", "Muzzle_T1");
		AddSlotTier("weaponMuzzleSKS", "Muzzle_T1");
		AddSlotTier("weaponMuzzleFAL", "Muzzle_T1");
		AddSlotTier("weaponMuzzle277", "Muzzle_T1");
		AddSlotTier("weaponMuzzle308", "Muzzle_T1");
		AddSlotTier("weaponMuzzle338", "Muzzle_T1");
		AddSlotTier("weaponmuzzle338", "Muzzle_T1");
		AddSlotTier("weaponMuzzle408", "Muzzle_T1");
		AddSlotTier("weaponmuzzle408", "Muzzle_T1");
		AddSlotTier("weaponMuzzle86", "Muzzle_T1");
		AddSlotTier("weaponMuzzleShotgun", "Muzzle_T1");
		AddSlotTier("weaponMuzzleMosin", "Muzzle_T1");
		AddSlotTier("weaponMuzzleMP5", "Muzzle_T1");
		AddSlotTier("weaponMuzzelSNAFU", "Muzzle_T1");
		AddSlotTier("GCGN_M1Garand_Muzzle", "Muzzle_T1");
		AddSlotTier("SNAFUShotgunchoke", "Muzzle_T1");
		AddSlotTier("snafu50bmg", "Muzzle_T3");
		AddSlotTier("sr25Muzzle", "Muzzle_T2");
		
		AddSlotTier("pistolMuzzle", "Suppressor_T1");
		AddSlotTier("suppressorImpro", "Suppressor_T1");
		AddSlotTier("22LRSuppressor", "Suppressor_T1");
		AddSlotTier("ASH12Suppressor", "Suppressor_T2");
		AddSlotTier("HoneyBadgerSuppressor", "Suppressor_T3");
		AddSlotTier("MP7A2Suppressor", "Suppressor_T2");
		AddSlotTier("QDLSuppressor", "Suppressor_T3");
		AddSlotTier("SNAFU338_Suppressor", "Suppressor_T3");
		AddSlotTier("Suppressor9A91", "Suppressor_T2");
		AddSlotTier("snafu300acsupp", "Suppressor_T3");
		AddSlotTier("SR3S", "Suppressor_T2");
		
		AddSlotTier("weaponWrap", "WeaponWrap_Utility");
		AddSlotTier("weaponMagazine", "StandardMag_Neutral");
		AddSlotTier("magazine", "StandardMag_Neutral");
	}
	
	protected static void AddSlotTier(string slotName, string tierKey)
	{
		m_SlotTierFallbacks.Set(slotName, tierKey);
	}
}
