class Gunplay_WeaponRepairKit: Inventory_Base
{
	protected int m_Uses;
	protected int m_MaxUses;
	
	void Gunplay_WeaponRepairKit()
	{
		SNAFUGunplayConfig config = SNAFUGunplayConfig.GetInstance();
		m_MaxUses = config.RepairKit_Uses;
		m_Uses = m_MaxUses;
	}
	
	override void EEInit()
	{
		super.EEInit();
		
		SNAFUGunplayConfig config = SNAFUGunplayConfig.GetInstance();
		m_MaxUses = config.RepairKit_Uses;
		m_Uses = m_MaxUses;
		
		SetGunplayUses(m_Uses);
	}
	
	void SetGunplayUses(int quantity)
	{
		m_Uses = quantity;
		
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.UpdateVisualState, 100);
	}
	
	int GetUses()
	{
		return m_Uses;
	}
	
	void AddUses(int amount)
	{
		m_Uses = m_Uses + amount;
		if (m_Uses < 0) m_Uses = 0;
		if (m_Uses > m_MaxUses) m_Uses = m_MaxUses;
		UpdateVisualState();
	}

	int GetMaxUses()
	{
		return m_MaxUses;
	}
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
	}
	
	override string GetDisplayName()
	{
		return "Weapon Repair Kit (" + m_Uses + "/" + m_MaxUses + " uses)";
	}
	
	protected void UpdateVisualState()
	{
		if (m_Uses <= 0)
		{
			SetHealth(0);
		}
	}
	
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		return false;
	}
	
	override bool CanReleaseAttachment(EntityAI attachment)
	{
		return false;
	}
}
