modded class DayZPlayerImplement
{
	override void SwitchOptics(ItemOptics optic, bool state)
	{
		super.SwitchOptics(optic, state);
	}
	
	override bool IsShootingFromCamera()
	{
		SNAFUGunplayConfig config = SNAFUGunplayConfig.GetInstance();
		if (!config)
		{
			return super.IsShootingFromCamera();
		}

		if (!config.EnableHipFireNerf)
		{
			return super.IsShootingFromCamera();
		}

		PlayerBase player = PlayerBase.Cast(this);
		if (player && SNAFUVehicleCombatHandler.IsPlayerInVehicle(player))
		{
			return super.IsShootingFromCamera();
		}

		return false;
	}
}
