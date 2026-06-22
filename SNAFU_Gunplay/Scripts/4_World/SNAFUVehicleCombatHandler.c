class SNAFUVehicleCombatHandler
{
	static bool IsPlayerInVehicle(PlayerBase player)
	{
		if (!player) return false;
		
		if (player.IsInTransport())
		{
			return true;
		}
		
		return false;
	}
	
	static bool IsPlayerInHelicopter(PlayerBase player)
	{
		if (!player) return false;
		
		if (!player.IsInTransport()) return false;
		
		return false;
	}
	
	static bool ShouldDisableHipFireNerf(PlayerBase player)
	{
		if (!player) return false;
		
		if (player.IsInTransport())
		{
			SNAFUGunplayConfig config = SNAFUGunplayConfig.GetInstance();
			if (config.DebugMode)
			{
				Print("[SNAFU Gunplay] Vehicle detected - Hip-Fire Nerf DISABLED");
			}
			return true;
		}
		
		return false;
	}
	
	static string GetVehicleType(PlayerBase player)
	{
		if (!player) return "";
		
		if (player.IsInTransport())
		{
			return "vehicle";
		}

		return "";
	}
}
