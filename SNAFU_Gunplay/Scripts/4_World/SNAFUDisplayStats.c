class SNAFUDisplayStats
{
	static SNAFUDisplayData GetDisplay(EntityAI item, string itemType = "", array<string> attachmentTypes = null)
	{
		if (item && SNAFUGunplayOwnership.ShouldSkipBecauseAJOwns(item.GetType()))
		{
			return null;
		}
		
		if (itemType != "" && SNAFUGunplayOwnership.ShouldSkipBecauseAJOwns(itemType))
		{
			return null;
		}
		
		SNAFUDisplayData armorDisplay = SNAFUArmorStats.GetArmorDisplay(item);
		if (armorDisplay)
		{
			return armorDisplay;
		}
		
		if (itemType != "")
		{
			armorDisplay = SNAFUArmorStats.GetArmorDisplayByType(itemType);
			if (armorDisplay)
			{
				return armorDisplay;
			}
		}
		
		string resolvedType = itemType;
		if (item)
		{
			resolvedType = item.GetType();
		}
		
		if (IsMagazineType(resolvedType))
		{
			return GetMagazineDisplay(resolvedType);
		}
		
		SNAFUTierEffect effect = GetEffect(item, itemType, attachmentTypes);
		if (!effect)
		{
			return null;
		}
		
		return GetWeaponDisplay(effect, resolvedType, IsWeaponType(resolvedType));
	}
	
	static SNAFUTierEffect GetEffect(EntityAI item, string itemType = "", array<string> attachmentTypes = null)
	{
		Weapon_Base weapon = Weapon_Base.Cast(item);
		if (weapon)
		{
			if (!weapon.SNAFUShouldApplyGunplay())
			{
				return null;
			}
			
			SNAFUWeaponStatsManager manager = new SNAFUWeaponStatsManager();
			manager.CalculateStats(weapon);
			return new SNAFUTierEffect("Weapon", "Total", manager.GetCurrentRecoil(), manager.GetCurrentSway(), manager.GetCurrentAimSpeed(), manager.GetCurrentPrecision(), manager.GetHipFireSpreadModifier());
		}
		
		SNAFUTierEffect attachmentEffect = SNAFUAttachmentStats.GetEffect(item);
		if (attachmentEffect)
		{
			return attachmentEffect;
		}
		
		return GetEffectByType(itemType, attachmentTypes);
	}
	
	static SNAFUTierEffect GetEffectByType(string itemType, array<string> attachmentTypes = null)
	{
		if (itemType == "")
		{
			return null;
		}
		
		if (IsWeaponType(itemType))
		{
			if (SNAFUGunplayOwnership.ShouldSkipBecauseAJOwns(itemType))
			{
				return null;
			}
			
			return GetWeaponEffectByType(itemType, attachmentTypes);
		}
		
		return SNAFUAttachmentStats.GetEffectByType(itemType);
	}
	
	protected static bool IsWeaponType(string itemType)
	{
		if (itemType == "")
		{
			return false;
		}
		
		return GetGame().ConfigIsExisting("CfgWeapons " + itemType);
	}
	
	protected static SNAFUTierEffect GetWeaponEffectByType(string itemType, array<string> attachmentTypes = null)
	{
		SNAFUGunplayConfig config = SNAFUGunplayConfig.GetInstance();
		if (!config)
		{
			return null;
		}
		
		SNAFUWeaponStatsManager manager = new SNAFUWeaponStatsManager();
		float baseRecoil = manager.GetBaseRecoilByType(itemType);
		float baseSway = manager.GetBaseSwayByType(itemType);
		float baseAimSpeed = manager.GetBaseAimSpeedByType(itemType);
		float basePrecision = manager.GetBasePrecisionByType(itemType);
		
		SNAFUTierEffect effect = new SNAFUTierEffect("Weapon", "Total", baseRecoil * config.GlobalRecoilMultiplier, baseSway * config.GlobalSwayMultiplier, baseAimSpeed * config.GlobalAimSpeedMultiplier, basePrecision * config.GlobalPrecisionMultiplier, config.GlobalHipFireMultiplier);
		ApplyAttachmentTypes(effect, attachmentTypes);
		
		return effect;
	}
	
	protected static SNAFUDisplayData GetWeaponDisplay(SNAFUTierEffect effect, string itemType = "", bool isWeapon = false)
	{
		SNAFUDisplayData data = new SNAFUDisplayData();
		data.TierLabel = effect.GetLabel();
		data.Line1Label = "Recoil:";
		data.Line1Value = SNAFUAttachmentStats.FormatDelta(effect.Recoil);
		data.Line1Color = SNAFUAttachmentStats.GetDeltaColor(effect.Recoil, false);
		data.Line2Label = "Sway:";
		data.Line2Value = SNAFUAttachmentStats.FormatDelta(effect.Sway);
		data.Line2Color = SNAFUAttachmentStats.GetDeltaColor(effect.Sway, false);
		data.Line3Label = "ADS:";
		data.Line3Value = SNAFUAttachmentStats.FormatDelta(effect.ADS);
		data.Line3Color = SNAFUAttachmentStats.GetDeltaColor(effect.ADS, true);
		data.Line4Label = "Precision:";
		data.Line4Value = SNAFUAttachmentStats.FormatDelta(effect.Precision);
		data.Line4Color = SNAFUAttachmentStats.GetDeltaColor(effect.Precision, true);
		data.Line5Label = "Hipfire:";
		data.Line5Value = SNAFUAttachmentStats.FormatDelta(effect.HipFire);
		data.Line5Color = SNAFUAttachmentStats.GetDeltaColor(effect.HipFire, false);
		data.ShowLine5 = true;
		
		if (isWeapon)
		{
			data.Line3Label = "ADS Time:";
			data.Line3Value = FormatADSTimeSeconds(effect.ADS);
			data.Line5Label = "RPM:";
			data.Line5Value = GetWeaponRPMByType(itemType) + " | Velocity: " + GetWeaponVelocityByType(itemType) + " m/s";
			data.Line5Color = 0xFFFFFFFF;
		}
		
		return data;
	}
	
	protected static SNAFUDisplayData GetMagazineDisplay(string itemType)
	{
		SNAFUTierEffect effect = SNAFUAttachmentStats.GetEffectByType(itemType);
		if (!effect)
		{
			return null;
		}
		
		SNAFUDisplayData data = new SNAFUDisplayData();
		data.TierLabel = effect.GetLabel();
		data.Line1Label = "Capacity:";
		data.Line1Value = string.Format("%1 rnd", GetMagazineCapacityByType(itemType));
		data.Line1Color = 0xFFFFFFFF;
		data.Line2Label = "Recoil:";
		data.Line2Value = SNAFUAttachmentStats.FormatDelta(effect.Recoil);
		data.Line2Color = SNAFUAttachmentStats.GetDeltaColor(effect.Recoil, false);
		data.Line3Label = "ADS:";
		data.Line3Value = SNAFUAttachmentStats.FormatDelta(effect.ADS);
		data.Line3Color = SNAFUAttachmentStats.GetDeltaColor(effect.ADS, true);
		data.Line4Label = "Sway:";
		data.Line4Value = SNAFUAttachmentStats.FormatDelta(effect.Sway);
		data.Line4Color = SNAFUAttachmentStats.GetDeltaColor(effect.Sway, false);
		data.Line5Label = "Hipfire:";
		data.Line5Value = SNAFUAttachmentStats.FormatDelta(effect.HipFire);
		data.Line5Color = SNAFUAttachmentStats.GetDeltaColor(effect.HipFire, false);
		data.ShowLine5 = true;
		
		return data;
	}
	
	protected static bool IsMagazineType(string itemType)
	{
		if (itemType == "")
		{
			return false;
		}
		
		return GetGame().ConfigIsExisting("CfgMagazines " + itemType);
	}
	
	protected static int GetMagazineCapacityByType(string itemType)
	{
		return GetGame().ConfigGetInt("CfgMagazines " + itemType + " count");
	}
	
	protected static string FormatADSTimeSeconds(float aimSpeed)
	{
		if (aimSpeed <= 0.05)
		{
			aimSpeed = 1.0;
		}
		
		float seconds = 0.7 / aimSpeed;
		return string.Format("%1s", Math.Round(seconds * 100.0) / 100.0);
	}
	
	protected static string GetWeaponRPMByType(string itemType)
	{
		int rpm = GetHighestWeaponRPMByType(itemType);
		if (rpm <= 0)
		{
			return "-";
		}
		
		return string.Format("%1", rpm);
	}
	
	protected static int GetWeaponVelocityByType(string itemType)
	{
		float initSpeedMultiplier = GetWeaponInitSpeedMultiplierByType(itemType);
		int ammoVelocity = GetWeaponVelocityByAmmoType(itemType);
		if (ammoVelocity <= 0)
		{
			return Math.Round(900.0 * initSpeedMultiplier);
		}
		
		return Math.Round(ammoVelocity * initSpeedMultiplier);
	}
	
	protected static float GetWeaponInitSpeedMultiplierByType(string itemType)
	{
		float initSpeedMultiplier = GetGame().ConfigGetFloat("CfgWeapons " + itemType + " initSpeedMultiplier");
		if (initSpeedMultiplier <= 0.0)
		{
			return 1.0;
		}
		
		return initSpeedMultiplier;
	}
	
	protected static int GetWeaponVelocityByAmmoType(string itemType)
	{
		TStringArray ammoTypes = new TStringArray;
		GetGame().ConfigGetTextArray("CfgWeapons " + itemType + " chamberableFrom", ammoTypes);
		
		float bestVelocity = 0.0;
		foreach (string ammoType : ammoTypes)
		{
			string ammoPath = "CfgAmmo " + ammoType + " initSpeed";
			if (!GetGame().ConfigIsExisting(ammoPath))
			{
				continue;
			}
			
			float ammoVelocity = GetGame().ConfigGetFloat(ammoPath);
			if (ammoVelocity > bestVelocity)
			{
				bestVelocity = ammoVelocity;
			}
		}
		
		return Math.Round(bestVelocity);
	}
	
	protected static int GetHighestWeaponRPMByType(string itemType)
	{
		int bestRPM = 0;
		TStringArray modes = new TStringArray;
		GetGame().ConfigGetTextArray("CfgWeapons " + itemType + " modes", modes);
		
		foreach (string mode : modes)
		{
			bestRPM = Math.Max(bestRPM, GetFireModeRPMByType(itemType, mode));
		}
		
		bestRPM = Math.Max(bestRPM, GetFireModeRPMByType(itemType, "FullAuto"));
		bestRPM = Math.Max(bestRPM, GetFireModeRPMByType(itemType, "Burst"));
		bestRPM = Math.Max(bestRPM, GetFireModeRPMByType(itemType, "SemiAuto"));
		bestRPM = Math.Max(bestRPM, GetFireModeRPMByType(itemType, "Single"));
		bestRPM = Math.Max(bestRPM, GetFireModeRPMByType(itemType, "Double"));
		
		return bestRPM;
	}
	
	protected static int GetFireModeRPMByType(string itemType, string fireMode)
	{
		string reloadPath = "CfgWeapons " + itemType + " " + fireMode + " reloadTime";
		if (!GetGame().ConfigIsExisting(reloadPath))
		{
			return 0;
		}
		
		float reloadTime = GetGame().ConfigGetFloat(reloadPath);
		if (reloadTime <= 0.0)
		{
			return 0;
		}
		
		return Math.Round((1.0 / reloadTime) * 60.0);
	}
	
	protected static void ApplyAttachmentTypes(SNAFUTierEffect weaponEffect, array<string> attachmentTypes)
	{
		if (!weaponEffect || !attachmentTypes)
		{
			return;
		}
		
		foreach (string attachmentType : attachmentTypes)
		{
			SNAFUTierEffect attachmentEffect = SNAFUAttachmentStats.GetEffectByType(attachmentType);
			if (!attachmentEffect)
			{
				continue;
			}
			
			weaponEffect.Recoil *= attachmentEffect.Recoil;
			weaponEffect.Sway *= attachmentEffect.Sway;
			weaponEffect.ADS *= attachmentEffect.ADS;
			weaponEffect.Precision *= attachmentEffect.Precision;
			weaponEffect.HipFire *= attachmentEffect.HipFire;
		}
	}
}
