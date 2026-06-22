modded class Weapon_Base
{
	protected bool m_WeaponGeometryDamageEnabled;
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		SNAFUGunplayConfig config = SNAFUGunplayConfig.GetInstance();
		m_WeaponGeometryDamageEnabled = config.EnableWeaponGeometryDamage;
	}
	
	override bool EEOnDamageCalculated(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		SNAFUGunplayConfig config = SNAFUGunplayConfig.GetInstance();
		
		if (!config.EnableWeaponGeometryDamage)
		{
			if (damageType == DamageType.FIRE_ARM)
			{
				if (config.DebugMode)
				{
					Print("[SNAFU Gunplay] Weapon geometry damage BLOCKED for: " + GetType());
				}
				
				return false;
			}
		}
		
		return super.EEOnDamageCalculated(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
	}
	
	override void SetHealth(float health)
	{
		SNAFUGunplayConfig config = SNAFUGunplayConfig.GetInstance();
		
		if (!config.EnableWeaponGeometryDamage)
		{
			if (health < GetHealth())
			{
				PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
				if (player && GetHierarchyRoot() == player.GetHumanInventory().GetEntityInHands())
				{
					if (config.DebugMode)
					{
						Print("[SNAFU Gunplay] Weapon health reduction prevented");
					}
					return;
				}
			}
		}
		
		super.SetHealth(health);
	}
	
	override void EEKilled(Object killer)
	{
		SNAFUGunplayConfig config = SNAFUGunplayConfig.GetInstance();
		
		if (!config.EnableWeaponGeometryDamage)
		{
			if (config.DebugMode)
			{
				Print("[SNAFU Gunplay] Weapon ruined event prevented");
			}
			
			SetHealth(GetMaxHealth());
			return;
		}
		
		super.EEKilled(killer);
	}
}
