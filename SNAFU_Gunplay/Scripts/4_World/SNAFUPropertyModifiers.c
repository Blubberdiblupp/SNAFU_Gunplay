modded class PropertyModifiers
{
	override void UpdateModifiers()
	{
		super.UpdateModifiers();
		
		Weapon_Base weapon = Weapon_Base.Cast(m_OwnerItem);
		if (!weapon)
		{
			return;
		}
		
		if (!weapon.SNAFUShouldApplyGunplay())
		{
			return;
		}
		
		float recoilModifier = weapon.GetWeaponRecoilModifier();
		float swayModifier = weapon.GetAimingSwayModifier();
		float swaySpeedModifier = weapon.GetAimingSwaySpeedModifier();
		
		if (recoilModifier > 0.0)
		{
			m_RecoilModifiers[0] = recoilModifier;
			m_RecoilModifiers[1] = recoilModifier;
			m_RecoilModifiers[2] = recoilModifier;
		}
		
		if (swayModifier > 0.0)
		{
			m_SwayModifiers[0] = swayModifier;
			m_SwayModifiers[1] = swayModifier;
			m_SwayModifiers[2] = swaySpeedModifier;
		}
		
		SNAFUGunplayConfig config = SNAFUGunplayConfig.GetInstance();
		if (config && config.DebugMode)
		{
			Print("[SNAFU Gunplay] Applied weapon property modifiers: " + weapon.GetType() + " recoil=" + recoilModifier + " sway=" + swayModifier);
		}
	}
}
