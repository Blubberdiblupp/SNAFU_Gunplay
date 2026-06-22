modded class Weapon_Base
{
	protected ref SNAFUWeaponStatsManager m_StatsManager;
	protected bool m_StatsDirty = true;
	
	protected bool m_WasInIronsights;
	protected int m_LastZeroing;
	protected float m_LastZoomLevel;
	
	void Weapon_Base()
	{
		m_StatsManager = new SNAFUWeaponStatsManager();
		m_WasInIronsights = false;
		m_LastZeroing = 0;
		m_LastZoomLevel = 0;
	}
	
	void ~Weapon_Base()
	{
		if (m_StatsManager)
		{
			delete m_StatsManager;
		}
	}
	
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		
		if (!item) return;
		
		string itemType = item.GetType();
		
		SNAFUNetworkOptimizer optimizer = SNAFUNetworkOptimizer.GetInstance();
		
		if (!optimizer.ShouldTriggerStatRecalc(itemType, slot_name))
		{
			if (GetGame().IsServer())
			{
				SNAFUGunplayConfig debugConfigAttached = SNAFUGunplayConfig.GetInstance();
				if (debugConfigAttached.DebugMode)
				{
					Print("[SNAFU Gunplay] Cosmetic attachment ignored: " + itemType + " (slot: " + slot_name + ")");
				}
			}
			return;
		}
		
		m_StatsDirty = true;
		
		if (GetGame().IsServer())
		{
			SNAFUGunplayConfig attachConfig = SNAFUGunplayConfig.GetInstance();
			if (attachConfig.DebugMode)
			{
				Print("[SNAFU Gunplay] Stat-affecting item attached: " + itemType + " to slot: " + slot_name);
			}
			
			RecalculateStats();
		}
	}
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if (!item) return;
		
		string itemType = item.GetType();
		
		SNAFUNetworkOptimizer optimizer = SNAFUNetworkOptimizer.GetInstance();
		
		if (!optimizer.ShouldTriggerStatRecalc(itemType, slot_name))
		{
			if (GetGame().IsServer())
			{
				SNAFUGunplayConfig debugConfigDetached = SNAFUGunplayConfig.GetInstance();
				if (debugConfigDetached.DebugMode)
				{
					Print("[SNAFU Gunplay] Cosmetic detachment ignored: " + itemType + " (slot: " + slot_name + ")");
				}
			}
			return;
		}
		
		m_StatsDirty = true;
		
		if (GetGame().IsServer())
		{
			SNAFUGunplayConfig detachConfig = SNAFUGunplayConfig.GetInstance();
			if (detachConfig.DebugMode)
			{
				Print("[SNAFU Gunplay] Stat-affecting item detached: " + itemType + " from slot: " + slot_name);
			}
			
			RecalculateStats();
		}
	}
	
	void RecalculateStats()
	{
		if (!m_StatsManager)
		{
			m_StatsManager = new SNAFUWeaponStatsManager();
		}
		
		m_StatsManager.CalculateStats(this);
		m_StatsDirty = false;
		
		SNAFUGunplayConfig config = SNAFUGunplayConfig.GetInstance();
		
		if (config.DebugMode && m_StatsManager)
		{
			Print(m_StatsManager.GetStatsString());
		}
	}
	
	override RecoilBase SpawnRecoilObject()
	{
		if (m_StatsDirty)
		{
			RecalculateStats();
		}
		
		return super.SpawnRecoilObject();
	}
	
	float GetWeaponRecoilModifier()
	{
		if (m_StatsDirty)
		{
			RecalculateStats();
		}
		
		if (m_StatsManager)
		{
			return m_StatsManager.GetCurrentRecoil();
		}
		
		return 1.0;
	}
	
	float GetDispersion()
	{
		if (m_StatsDirty)
		{
			RecalculateStats();
		}
		
		if (m_StatsManager)
		{
			return m_StatsManager.GetCurrentSway() / m_StatsManager.GetCurrentPrecision();
		}
		
		return 0.0;
	}
	
	float GetOpticsDisableLookOverride()
	{
		if (m_StatsDirty)
		{
			RecalculateStats();
		}
		
		if (m_StatsManager)
		{
			return m_StatsManager.GetCurrentAimSpeed();
		}
		
		return 1.0;
	}
	
	float GetHipFireSpreadModifier()
	{
		if (m_StatsDirty)
		{
			RecalculateStats();
		}
		
		if (m_StatsManager)
		{
			return m_StatsManager.GetHipFireSpreadModifier();
		}
		
		return 1.0;
	}
	
	bool HasGripAttached()
	{
		if (FindAttachmentBySlotName("snafuar15afg")) return true;
		if (FindAttachmentBySlotName("FGRIP")) return true;
		if (FindAttachmentBySlotName("weaponGripCQR")) return true;
		if (FindAttachmentBySlotName("weaponGripKAAR")) return true;
		if (FindAttachmentBySlotName("SNAFUM249Grip")) return true;
		
		return false;
	}
	
	bool HasScopeAttached()
	{
		if (FindAttachmentBySlotName("weaponOptics")) return true;
		if (FindAttachmentBySlotName("weaponOpticsHunting")) return true;
		if (FindAttachmentBySlotName("weaponOpticsSniper")) return true;
		
		return false;
	}
	
	bool IsHeavyScopeAttached()
	{
		return false;
	}
	
	string GetGunplayStatsDisplay()
	{
		if (m_StatsDirty)
		{
			RecalculateStats();
		}
		
		if (m_StatsManager)
		{
			return m_StatsManager.GetStatsString();
		}
		
		return "";
	}
	
}
