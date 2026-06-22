class SNAFUDisplayData
{
	string TierLabel;
	string Line1Label;
	string Line1Value;
	int Line1Color;
	string Line2Label;
	string Line2Value;
	int Line2Color;
	string Line3Label;
	string Line3Value;
	int Line3Color;
	string Line4Label;
	string Line4Value;
	int Line4Color;
	string Line5Label;
	string Line5Value;
	int Line5Color;
	bool ShowLine5;
	
	void SNAFUDisplayData()
	{
		TierLabel = "";
		Line1Label = "";
		Line1Value = "";
		Line1Color = 0xFFFFFFFF;
		Line2Label = "";
		Line2Value = "";
		Line2Color = 0xFFFFFFFF;
		Line3Label = "";
		Line3Value = "";
		Line3Color = 0xFFFFFFFF;
		Line4Label = "";
		Line4Value = "";
		Line4Color = 0xFFFFFFFF;
		Line5Label = "";
		Line5Value = "";
		Line5Color = 0xFFFFFFFF;
		ShowLine5 = true;
	}
}

class SNAFUArmorStats
{
	static SNAFUDisplayData GetArmorDisplay(EntityAI item)
	{
		if (!item)
		{
			return null;
		}
		
		if (!IsClothingType(item.GetType()))
		{
			return null;
		}
		
		return GetArmorDisplayByType(item.GetType());
	}
	
	static SNAFUDisplayData GetArmorDisplayByType(string itemType)
	{
		if (!IsClothingType(itemType))
		{
			return null;
		}
		
		float projectile = GetProtectionPercent(itemType, "Projectile");
		float melee = GetProtectionPercent(itemType, "Melee");
		float infected = GetProtectionPercent(itemType, "Infected");
		float frag = GetProtectionPercent(itemType, "FragGrenade");
		
		SNAFUDisplayData data = new SNAFUDisplayData();
		data.TierLabel = GetArmorTier(projectile);
		data.Line1Label = "Projectile:";
		data.Line1Value = FormatProtection(projectile);
		data.Line1Color = GetProtectionColor(projectile);
		data.Line2Label = "Melee:";
		data.Line2Value = FormatProtection(melee);
		data.Line2Color = GetProtectionColor(melee);
		data.Line3Label = "Infected:";
		data.Line3Value = FormatProtection(infected);
		data.Line3Color = GetProtectionColor(infected);
		data.Line4Label = "Frag:";
		data.Line4Value = FormatProtection(frag);
		data.Line4Color = GetProtectionColor(frag);
		data.ShowLine5 = false;
		
		return data;
	}
	
	protected static bool IsClothingType(string itemType)
	{
		if (itemType == "")
		{
			return false;
		}
		
		if (!GetGame().ConfigIsExisting("CfgVehicles " + itemType))
		{
			return false;
		}
		
		TStringArray slots = new TStringArray;
		GetGame().ConfigGetTextArray("CfgVehicles " + itemType + " inventorySlot", slots);
		
		foreach (string slot : slots)
		{
			if (IsClothingSlot(slot))
			{
				return true;
			}
		}
		
		string singleSlot;
		GetGame().ConfigGetText("CfgVehicles " + itemType + " inventorySlot", singleSlot);
		return IsClothingSlot(singleSlot);
	}
	
	protected static bool IsClothingSlot(string slot)
	{
		if (slot == "Headgear") return true;
		if (slot == "Mask") return true;
		if (slot == "Eyewear") return true;
		if (slot == "Gloves") return true;
		if (slot == "Body") return true;
		if (slot == "Vest") return true;
		if (slot == "Back") return true;
		if (slot == "Hips") return true;
		if (slot == "Legs") return true;
		if (slot == "Feet") return true;
		if (slot == "Armband") return true;
		
		return false;
	}
	
	protected static float GetProtectionPercent(string itemType, string damageClass)
	{
		string path = "CfgVehicles " + itemType + " DamageSystem GlobalArmor " + damageClass + " Health damage";
		if (!GetGame().ConfigIsExisting(path))
		{
			return 0.0;
		}
		
		float damage = GetGame().ConfigGetFloat(path);
		float protection = 100.0 - (damage * 100.0);
		if (protection < 0.0)
		{
			return 0.0;
		}
		
		if (protection > 100.0)
		{
			return 100.0;
		}
		
		return protection;
	}
	
	protected static string GetArmorTier(float projectileProtection)
	{
		if (projectileProtection >= 90.0)
		{
			return "Armor Tier 3";
		}
		
		if (projectileProtection >= 76.0)
		{
			return "Armor Tier 2";
		}
		
		if (projectileProtection >= 50.0)
		{
			return "Armor Tier 1";
		}
		
		return "Clothing 0";
	}
	
	protected static string FormatProtection(float protection)
	{
		return string.Format("%1%%", Math.Round(protection));
	}
	
	protected static int GetProtectionColor(float protection)
	{
		if (protection >= 76.0)
		{
			return 0xFF22DD66;
		}
		
		if (protection >= 50.0)
		{
			return 0xFFFFFFFF;
		}
		
		return 0xFFFF5555;
	}
}
