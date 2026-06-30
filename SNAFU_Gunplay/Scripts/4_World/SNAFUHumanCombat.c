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
		
		SNAFUGunplayAdminConfig adminConfig = SNAFUGetAdminConfig();
		if (adminConfig && adminConfig.CrosshairMode == 0)
		{
			return super.IsShootingFromCamera();
		}

		PlayerBase player = PlayerBase.Cast(this);
		if (player && SNAFUVehicleCombatHandler.IsPlayerInVehicle(player))
		{
			return super.IsShootingFromCamera();
		}
		
		if (player)
		{
			Weapon_Base weapon = Weapon_Base.Cast(player.GetItemInHands());
			if (SNAFUIsInAimingView(player, weapon))
			{
				return super.IsShootingFromCamera();
			}
			
			if (weapon && !weapon.SNAFUShouldApplyGunplay())
			{
				return super.IsShootingFromCamera();
			}
			
			if (adminConfig && adminConfig.CrosshairMode == 2 && !SNAFUHasHipfireLaser(weapon))
			{
				return super.IsShootingFromCamera();
			}
		}

		return false;
	}
	
	protected bool SNAFUIsInAimingView(PlayerBase player, Weapon_Base weapon)
	{
		if (m_bADS || m_CameraIronsight || m_CameraOptics)
		{
			return true;
		}
		
		if (player && (player.IsInIronsights() || player.IsInOptics()))
		{
			return true;
		}
		
		if (weapon && weapon.IsInOptics())
		{
			return true;
		}
		
		return false;
	}
	
	protected bool SNAFUHasHipfireLaser(Weapon_Base weapon)
	{
		if (!weapon)
		{
			return false;
		}
		
		if (weapon.FindAttachmentBySlotName("weaponLaserPointer")) return true;
		if (weapon.FindAttachmentBySlotName("weaponLaser")) return true;
		if (weapon.FindAttachmentBySlotName("PistolLaserPointer")) return true;
		if (weapon.FindAttachmentBySlotName("SNAFUPEQLASER")) return true;
		if (weapon.FindAttachmentBySlotName("Expansion_ANPEQ15_Base")) return true;
		
		if (weapon.GetInventory())
		{
			for (int i = 0; i < weapon.GetInventory().AttachmentCount(); i++)
			{
				EntityAI attachment = weapon.GetInventory().GetAttachmentFromIndex(i);
				if (attachment && SNAFUIsLaserType(attachment.GetType()))
				{
					return true;
				}
			}
		}
		
		return false;
	}
	
	protected bool SNAFUIsLaserType(string itemType)
	{
		if (itemType.Contains("Laser")) return true;
		if (itemType.Contains("PEQ")) return true;
		if (itemType.Contains("ANPEQ")) return true;
		if (itemType.Contains("NGAL")) return true;
		if (itemType.Contains("DBAL")) return true;
		if (itemType.Contains("MAWL")) return true;
		
		return false;
	}
}
