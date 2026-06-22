class SNAFUFirearmsMechanics
{
	static const float HIP_FIRE_ACCURACY_LOSS = 0.5;
	static const float HIP_FIRE_SPREAD_MULTIPLIER = 2.5;
	
	static vector GetBarrelDirection(Weapon_Base weapon)
	{
		if (!weapon) return vector.Zero;
		
		vector direction = vector.Zero;
		
		direction = weapon.GetDirection();
		
		return direction.Normalized();
	}
	
	static vector CalculateHipFireSpread(Weapon_Base weapon, PlayerBase player, vector aimDirection)
	{
		if (!weapon || !player) return aimDirection;
		
		SNAFUGunplayConfig config = SNAFUGunplayConfig.GetInstance();
		
		if (!config.EnableHipFireNerf)
		{
			return aimDirection;
		}
		
		float spreadAngle = config.HipFireAccuracyDegradation * weapon.GetHipFireSpreadModifier();
		
		float randomX = Math.RandomFloat(-spreadAngle, spreadAngle);
		float randomY = Math.RandomFloat(-spreadAngle, spreadAngle);
		
		vector spreadVector = aimDirection;
		
		spreadVector[0] = spreadVector[0] + randomX;
		spreadVector[1] = spreadVector[1] + randomY;
		
		spreadVector = spreadVector.Normalized();
		
		if (config.DebugMode)
		{
			Print("[SNAFU Gunplay] Hip Fire Spread: " + spreadVector + " (Original: " + aimDirection + ")");
		}
		
		return spreadVector;
	}
	
	static vector GetActualMuzzleVector(Weapon_Base weapon)
	{
		if (!weapon) return vector.Zero;
		
		vector weaponDirection = weapon.GetDirection();
		return weaponDirection.Normalized();
	}
	
	static bool IsPlayerHipFiring(PlayerBase player, Weapon_Base weapon)
	{
		if (!player || !weapon) return false;
		
		return true;
	}
	
	static vector ApplyHipFireCorrection(Weapon_Base weapon, PlayerBase player, vector originalDirection)
	{
		if (!weapon || !player) return originalDirection;
		
		SNAFUGunplayConfig config = SNAFUGunplayConfig.GetInstance();
		
		if (!config.EnableHipFireNerf)
		{
			return originalDirection;
		}
		
		if (SNAFUVehicleCombatHandler.IsPlayerInVehicle(player))
		{
			if (config.DebugMode)
			{
				string vehicleType = SNAFUVehicleCombatHandler.GetVehicleType(player);
				Print("[SNAFU Gunplay] Player in " + vehicleType + " - Hip-Fire Nerf SKIPPED");
			}
			return originalDirection;
		}
		
		if (!IsPlayerHipFiring(player, weapon))
		{
			return originalDirection;
		}
		
		vector barrelDirection = GetActualMuzzleVector(weapon);
		
		vector hipFireDirection = CalculateHipFireSpread(weapon, player, barrelDirection);
		
		float dotProduct = vector.Dot(barrelDirection, originalDirection);
		
		if (dotProduct < 0.95)
		{
			hipFireDirection = barrelDirection;
		}
		
		if (config.DebugMode)
		{
			Print("[SNAFU Gunplay] Hip Fire Correction Applied");
			Print("  Original Direction: " + originalDirection);
			Print("  Barrel Direction: " + barrelDirection);
			Print("  Final Direction: " + hipFireDirection);
		}
		
		return hipFireDirection;
	}
	
	static float GetHipFireDamageMultiplier(Weapon_Base weapon)
	{
		if (!weapon) return 1.0;
		
		SNAFUGunplayConfig config = SNAFUGunplayConfig.GetInstance();
		
		if (!config.EnableHipFireNerf)
		{
			return 1.0;
		}
		
		return 0.85;
	}
}
