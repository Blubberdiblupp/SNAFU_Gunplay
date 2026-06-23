class SNAFUDisplayStats
{
	static SNAFUDisplayData GetDisplay(EntityAI item, string itemType = "", array<string> attachmentTypes = null)
	{
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
		
		SNAFUTierEffect effect = GetEffect(item, itemType, attachmentTypes);
		if (!effect)
		{
			return null;
		}
		
		return GetWeaponDisplay(effect);
	}
	
	static SNAFUTierEffect GetEffect(EntityAI item, string itemType = "", array<string> attachmentTypes = null)
	{
		Weapon_Base weapon = Weapon_Base.Cast(item);
		if (weapon)
		{
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
		
		SNAFUTierEffect effect = new SNAFUTierEffect("Weapon", "Total", baseRecoil * config.GlobalRecoilMultiplier, baseSway * config.GlobalSwayMultiplier, baseAimSpeed * config.GlobalAimSpeedMultiplier, basePrecision, 1.0);
		ApplyAttachmentTypes(effect, attachmentTypes);
		
		return effect;
	}
	
	protected static SNAFUDisplayData GetWeaponDisplay(SNAFUTierEffect effect)
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
		
		return data;
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
