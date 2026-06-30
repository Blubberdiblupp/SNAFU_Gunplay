modded class DayZPlayerImplementAiming
{
	protected bool m_SNAFUHoldBreathFreezeActive;
	protected float m_SNAFUHoldBreathFreezeX;
	protected float m_SNAFUHoldBreathFreezeY;

	override bool ProcessAimFilters(float pDt, SDayZPlayerAimingModel pModel, int stance_index)
	{
		bool shouldFreezeHoldBreath = SNAFUShouldFreezeHoldBreathSway();
		if (!shouldFreezeHoldBreath)
		{
			m_SNAFUHoldBreathFreezeActive = false;
			return super.ProcessAimFilters(pDt, pModel, stance_index);
		}

		if (!m_SNAFUHoldBreathFreezeActive)
		{
			bool firstResult = SNAFUProcessAimFiltersWithVanillaHoldBreathSpeed(pDt, pModel, stance_index);
			m_SNAFUHoldBreathFreezeX = pModel.m_fAimXHandsOffset;
			m_SNAFUHoldBreathFreezeY = pModel.m_fAimYHandsOffset;
			m_SNAFUHoldBreathFreezeActive = true;
			return firstResult;
		}

		bool oldAimNoiseAllowed = IsAimNoiseAllowed();
		vector oldSwayModifier = m_SwayModifier;
		float oldHorizontalNoiseXAxisOffset = m_HorizontalNoiseXAxisOffset;
		float oldBreathingXAxisOffset = m_BreathingXAxisOffset;
		float oldBreathingYAxisOffset = m_BreathingYAxisOffset;

		SetAimNoiseAllowed(false);
		m_SwayModifier[2] = 1.0;
		m_HorizontalNoiseXAxisOffset = 0.0;
		m_BreathingXAxisOffset = 0.0;
		m_BreathingYAxisOffset = 0.0;

		bool result = super.ProcessAimFilters(pDt, pModel, stance_index);

		pModel.m_fAimXHandsOffset = pModel.m_fAimXHandsOffset + m_SNAFUHoldBreathFreezeX;
		pModel.m_fAimYHandsOffset = pModel.m_fAimYHandsOffset + m_SNAFUHoldBreathFreezeY;

		float absAimY = Math.AbsFloat(pModel.m_fCurrentAimY);
		pModel.m_fAimYHandsOffset = Math.Clamp(pModel.m_fAimYHandsOffset, absAimY - 89.9, 89.9 - absAimY);

		SetAimNoiseAllowed(oldAimNoiseAllowed);
		m_SwayModifier = oldSwayModifier;
		m_HorizontalNoiseXAxisOffset = oldHorizontalNoiseXAxisOffset;
		m_BreathingXAxisOffset = oldBreathingXAxisOffset;
		m_BreathingYAxisOffset = oldBreathingYAxisOffset;

		return result;
	}

	protected bool SNAFUProcessAimFiltersWithVanillaHoldBreathSpeed(float pDt, SDayZPlayerAimingModel pModel, int stance_index)
	{
		vector oldSwayModifier = m_SwayModifier;
		m_SwayModifier[2] = 1.0;

		bool result = super.ProcessAimFilters(pDt, pModel, stance_index);

		m_SwayModifier = oldSwayModifier;
		return result;
	}

	protected bool SNAFUShouldFreezeHoldBreathSway()
	{
		if (!SNAFUShouldUseVanillaHoldBreathSpeed())
		{
			return false;
		}

		return true;
	}
	
	protected bool SNAFUShouldUseVanillaHoldBreathSpeed()
	{
		if (!m_PlayerPb)
		{
			return false;
		}
		
		if (!m_PlayerPb.IsHoldingBreath())
		{
			return false;
		}
		
		if (!(m_PlayerPb.IsInIronsights() || m_PlayerPb.IsInOptics()))
		{
			return false;
		}
		
		Weapon_Base weapon = Weapon_Base.Cast(m_PlayerPb.GetItemInHands());
		if (!weapon)
		{
			return false;
		}
		
		return weapon.SNAFUShouldApplyGunplay();
	}
}
