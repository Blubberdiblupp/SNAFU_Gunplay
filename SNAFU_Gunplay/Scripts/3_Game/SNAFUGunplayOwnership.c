class SNAFUGunplayOwnership
{
	static bool IsModLoaded(string modName)
	{
		return GetGame().ConfigIsExisting("CfgPatches " + modName);
	}
	
	static bool IsAJClass(string className)
	{
		if (className == "") return false;
		if (className.Contains("AJW_")) return true;
		if (className.Contains("AJs_")) return true;
		
		return false;
	}
	
	static bool ShouldSkipBecauseAJOwns(string itemType)
	{
		if (!IsModLoaded("AJ_Gunplay"))
		{
			return false;
		}
		
		return IsAJClass(itemType);
	}
}
