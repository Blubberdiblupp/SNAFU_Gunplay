modded class CrossHairSelector
{
	override protected void SelectCrossHair()
	{
		SNAFUGunplayAdminConfig adminConfig = SNAFUGetAdminConfig();
		if (adminConfig && adminConfig.CrosshairMode == 0)
		{
			super.SelectCrossHair();
			return;
		}
		
		if (!m_AM)
		{
			return;
		}
		
		Weapon_Base weapon = Weapon_Base.Cast(m_Player.GetItemInHands());
		if (!weapon || !weapon.SNAFUShouldApplyGunplay())
		{
			super.SelectCrossHair();
			return;
		}
		
		HumanInputController hic = m_Player.GetInputController();
		ActionBase action = m_AM.GetRunningAction();
		
		if (m_Player.IsFireWeaponRaised() && hic && !hic.CameraIsFreeLook() && !m_Player.GetCommand_Melee2())
		{
			ShowCrossHair(null);
			return;
		}
		
		if (action && action.GetActionCategory() == AC_CONTINUOUS)
		{
			int actionState = m_AM.GetActionState(action);
			if (actionState != UA_NONE)
			{
				ShowCrossHair(null);
				return;
			}
		}
		
		if (m_Player.IsRaised() || m_Player.GetCommand_Melee2() || GetGame().GetUIManager().GetMenu() != null)
		{
			ShowCrossHair(null);
			return;
		}
		
		if (m_Player.GetCommand_Unconscious())
		{
			ShowCrossHair(null);
			return;
		}
		
		ShowCrossHair(GetCrossHairByName("dot"));
	}
}

class SNAFUHipFireCrosshair: Managed
{
	protected const float SNAFU_CROSSHAIR_BASE_SIZE = 64.0;
	protected const float SNAFU_CROSSHAIR_MIN_SIZE = 40.0;
	protected const float SNAFU_CROSSHAIR_MAX_SIZE = 88.0;
	protected const float SNAFU_PROJECT_DISTANCE = 100.0;
	protected const float SNAFU_SMOOTHNESS = 0.035;
	
	protected ref Widget m_Root;
	protected ref Widget m_DynamicRoot;
	protected ref ImageWidget m_DynamicImage;
	protected PlayerBase m_Player;
	protected vector m_ScreenPosition;
	protected float m_VelocityX[1];
	protected float m_VelocityY[1];
	
	void SNAFUHipFireCrosshair()
	{
		m_Root = GetGame().GetWorkspace().CreateWidgets("SNAFU_Gunplay/GUI/layouts/SNAFUHipFireCrosshair.layout");
		if (!m_Root)
		{
			return;
		}
		
		m_DynamicRoot = m_Root.FindAnyWidget("SNAFUHipFireCrosshairRoot");
		m_DynamicImage = ImageWidget.Cast(m_Root.FindAnyWidget("SNAFUHipFireCrosshairImage"));
		
		if (m_DynamicImage)
		{
			m_DynamicImage.LoadImageFile(0, "set:dayz_crosshairs image:crossT_128x128");
			m_DynamicImage.SetImage(0);
			m_DynamicImage.SetColor(ARGB(170, 255, 255, 255));
			m_DynamicImage.Show(false);
		}
	}
	
	void ~SNAFUHipFireCrosshair()
	{
		if (m_Root)
		{
			m_Root.Unlink();
		}
	}
	
	void OnUpdate(float timeslice)
	{
		if (!m_Root || !m_DynamicRoot || !m_DynamicImage)
		{
			return;
		}
		
		Weapon_Base weapon;
		if (!CanShow(weapon))
		{
			Hide();
			return;
		}
		
		vector worldPosition;
		if (!GetWeaponProjectedPosition(weapon, worldPosition))
		{
			Hide();
			return;
		}
		
		vector targetPosition = GetGame().GetScreenPosRelative(worldPosition);
		m_ScreenPosition[0] = Math.SmoothCD(m_ScreenPosition[0], targetPosition[0], m_VelocityX, SNAFU_SMOOTHNESS, 1000.0, timeslice);
		m_ScreenPosition[1] = Math.SmoothCD(m_ScreenPosition[1], targetPosition[1], m_VelocityY, SNAFU_SMOOTHNESS, 1000.0, timeslice);
		
		float size = GetCrosshairSize(weapon);
		float halfSize = size * 0.5;
		
		m_DynamicImage.SetSize(size, size);
		m_DynamicImage.SetPos(-halfSize, -halfSize);
		m_DynamicRoot.SetPos(m_ScreenPosition[0], m_ScreenPosition[1]);
		
		if (!m_DynamicImage.IsVisible())
		{
			m_DynamicImage.Show(true);
		}
	}
	
	protected bool CanShow(out Weapon_Base weapon)
	{
		SNAFUGunplayAdminConfig adminConfig = SNAFUGetAdminConfig();
		if (!adminConfig || adminConfig.CrosshairMode == 0)
		{
			return false;
		}
		
		if (!g_Game.GetProfileOption(EDayZProfilesOptions.CROSSHAIR) || g_Game.GetWorld().IsCrosshairDisabled())
		{
			return false;
		}
		
		m_Player = PlayerBase.Cast(GetGame().GetPlayer());
		if (!m_Player || !m_Player.IsPlayerSelected() || !m_Player.IsFireWeaponRaised())
		{
			return false;
		}
		
		HumanInputController hic = m_Player.GetInputController();
		if (!hic || hic.CameraIsFreeLook())
		{
			return false;
		}
		
		if (m_Player.IsInIronsights() || m_Player.IsInOptics() || m_Player.GetCommand_Melee2() || GetGame().IsInventoryOpen() || GetGame().GetUIManager().GetMenu() != null)
		{
			return false;
		}
		
		if (!Class.CastTo(weapon, m_Player.GetItemInHands()))
		{
			return false;
		}
		
		if (!weapon.SNAFUShouldApplyGunplay())
		{
			return false;
		}
		
		if (adminConfig.CrosshairMode == 2 && !HasHipfireLaser(weapon))
		{
			return false;
		}
		
		if (weapon.IsInOptics())
		{
			return false;
		}
		
		return true;
	}
	
	protected bool HasHipfireLaser(Weapon_Base weapon)
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
				if (attachment && IsLaserType(attachment.GetType()))
				{
					return true;
				}
			}
		}
		
		return false;
	}
	
	protected bool IsLaserType(string itemType)
	{
		if (itemType.Contains("Laser")) return true;
		if (itemType.Contains("PEQ")) return true;
		if (itemType.Contains("ANPEQ")) return true;
		if (itemType.Contains("NGAL")) return true;
		if (itemType.Contains("DBAL")) return true;
		if (itemType.Contains("MAWL")) return true;
		
		return false;
	}
	
	protected bool GetWeaponProjectedPosition(Weapon_Base weapon, out vector worldPosition)
	{
		vector barrelPosition = weapon.GetSelectionPositionLS("konec hlavne");
		vector muzzlePosition = weapon.GetSelectionPositionLS("usti hlavne");
		vector beginPoint = weapon.ModelToWorld(barrelPosition);
		vector endPoint = weapon.ModelToWorld(muzzlePosition);
		vector direction = endPoint - beginPoint;
		
		if (direction.LengthSq() < 0.0001)
		{
			return false;
		}
		
		direction.Normalize();
		vector traceEnd = endPoint + (direction * SNAFU_PROJECT_DISTANCE);
		vector contactDir;
		int contactComponent;
		
		if (DayZPhysics.RaycastRV(endPoint, traceEnd, worldPosition, contactDir, contactComponent, null, weapon, m_Player, false, false, ObjIntersectFire))
		{
			return true;
		}
		
		worldPosition = traceEnd;
		return true;
	}
	
	protected float GetCrosshairSize(Weapon_Base weapon)
	{
		float hipFireModifier = Math.Clamp(weapon.GetHipFireSpreadModifier(), 0.45, 1.45);
		return Math.Clamp(SNAFU_CROSSHAIR_BASE_SIZE * hipFireModifier, SNAFU_CROSSHAIR_MIN_SIZE, SNAFU_CROSSHAIR_MAX_SIZE);
	}
	
	protected void Hide()
	{
		if (m_DynamicImage && m_DynamicImage.IsVisible())
		{
			m_DynamicImage.Show(false);
		}
	}
}

modded class IngameHud
{
	protected ref SNAFUHipFireCrosshair m_SNAFUHipFireCrosshair;
	
	void IngameHud()
	{
		m_SNAFUHipFireCrosshair = new SNAFUHipFireCrosshair();
	}
	
	override void Update(float timeslice)
	{
		super.Update(timeslice);
		
		if (m_SNAFUHipFireCrosshair)
		{
			m_SNAFUHipFireCrosshair.OnUpdate(timeslice);
		}
	}
}
