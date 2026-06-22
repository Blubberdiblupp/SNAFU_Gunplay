modded class DayZPlayerImplement
{
	override bool IsShootingFromCamera()
	{
		SNAFUGunplayConfig config = SNAFUGunplayConfig.GetInstance();
		if (!config)
		{
			return m_IsShootingFromCamera;
		}

		if (!config.EnableHipFireNerf)
		{
			return m_IsShootingFromCamera;
		}

		PlayerBase player = PlayerBase.Cast(this);
		if (player && SNAFUVehicleCombatHandler.IsPlayerInVehicle(player))
		{
			return m_IsShootingFromCamera;
		}

		return false;
	}
}
