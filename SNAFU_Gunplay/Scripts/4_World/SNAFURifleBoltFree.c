modded class RifleBoltFree_Base
{
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		
		if (m_StatsManager)
		{
			m_StatsDirty = true;
			RecalculateStats();
		}
	}
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if (m_StatsManager)
		{
			m_StatsDirty = true;
			RecalculateStats();
		}
	}
}
