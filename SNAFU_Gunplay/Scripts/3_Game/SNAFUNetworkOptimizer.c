/**
 * SNAFUNetworkOptimizer.c - Phase 11 + 12 (JSON CONFIGURABLE)
 * 
 * PHASE 12 CORRECTION:
 * - ALL attachment modifiers are now JSON-configurable
 * - Only truly cosmetic items are filtered (wraps, camo, slings)
 * - All stat-affecting attachments trigger recalculation
 */

class SNAFUNetworkOptimizer
{
	protected static ref SNAFUNetworkOptimizer m_Instance;
	
	protected ref TStringArray m_StatAffectingAttachments;
	protected ref TStringArray m_CosmeticAttachments;
	
	protected bool m_IsServer;
	protected bool m_IsClient;
	
	static SNAFUNetworkOptimizer GetInstance()
	{
		if (!m_Instance)
		{
			m_Instance = new SNAFUNetworkOptimizer();
			m_Instance.Init();
		}
		return m_Instance;
	}
	
	void SNAFUNetworkOptimizer()
	{
		m_StatAffectingAttachments = new TStringArray;
		m_CosmeticAttachments = new TStringArray;
	}
	
	void Init()
	{
		m_IsServer = GetGame().IsServer();
		m_IsClient = GetGame().IsClient();
		
		InitStatAffectingAttachments();
		InitCosmeticAttachments();
		
		Print("[SNAFU Gunplay] Network optimizer initialized (Phase 12 JSON)");
		Print("[SNAFU Gunplay] Stat-affecting attachments: " + m_StatAffectingAttachments.Count());
		Print("[SNAFU Gunplay] Cosmetic attachments: " + m_CosmeticAttachments.Count());
	}
	
	protected void InitStatAffectingAttachments()
	{
		m_StatAffectingAttachments = new TStringArray;
		
		// BUTTSTOCKS (Recoil + Sway)
		m_StatAffectingAttachments.Insert("weaponButtstock");
		m_StatAffectingAttachments.Insert("weaponButtstockAK");
		m_StatAffectingAttachments.Insert("weaponStock");
		m_StatAffectingAttachments.Insert("SNAFUM249Stock");
		m_StatAffectingAttachments.Insert("SNAFUM200Stock");
		m_StatAffectingAttachments.Insert("HuntingButtstock");
		m_StatAffectingAttachments.Insert("MP5_PlasticButtstock");
		m_StatAffectingAttachments.Insert("MP5_PaddedButtstock");
		
		// PISTOL GRIPS (Recoil + ADS)
		m_StatAffectingAttachments.Insert("weaponPistolGrip");
		m_StatAffectingAttachments.Insert("weaponGripCQR");
		m_StatAffectingAttachments.Insert("weaponGripKAAR");
		m_StatAffectingAttachments.Insert("weaponGrip");
		m_StatAffectingAttachments.Insert("weaponGripAK");
		
		// FOREGRIPS (Recoil + ADS)
		m_StatAffectingAttachments.Insert("snafuar15afg");
		m_StatAffectingAttachments.Insert("FGRIP");
		m_StatAffectingAttachments.Insert("SNAFUM249Grip");
		
		// HANDGUARDS (Sway + Precision)
		m_StatAffectingAttachments.Insert("weaponHandguard");
		m_StatAffectingAttachments.Insert("SNAFUWeaponHandguardAK");
		m_StatAffectingAttachments.Insert("HandguardRIS");
		m_StatAffectingAttachments.Insert("M4_OEBHandGuard");
		m_StatAffectingAttachments.Insert("M4_MOLLEHandGuard");
		m_StatAffectingAttachments.Insert("SNAFUM249HG");
		
		// BIPODS (Sway + ADS)
		m_StatAffectingAttachments.Insert("snafuweaponBipod");
		m_StatAffectingAttachments.Insert("weaponBipod");
		m_StatAffectingAttachments.Insert("SNAFUM249Bipod");
		m_StatAffectingAttachments.Insert("SNAFUM200Bipod");
		
		// OPTICS (ADS Speed)
		m_StatAffectingAttachments.Insert("weaponOptics");
		m_StatAffectingAttachments.Insert("weaponOpticsHunting");
		m_StatAffectingAttachments.Insert("weaponOpticsSniper");
		m_StatAffectingAttachments.Insert("SNAFU_");
		
		// LASER (Hip-Fire)
		m_StatAffectingAttachments.Insert("weaponLaserPointer");
		m_StatAffectingAttachments.Insert("weaponLaser");
		m_StatAffectingAttachments.Insert("PistolLaserPointer");
		m_StatAffectingAttachments.Insert("SNAFUPEQLASER");
		
		// FLASHLIGHTS (ADS + Sway)
		m_StatAffectingAttachments.Insert("weaponFlashlight");
		m_StatAffectingAttachments.Insert("weaponFlashlightRail");
		m_StatAffectingAttachments.Insert("TLRLight");
		m_StatAffectingAttachments.Insert("UniversalLight");
		
		// BAYONETS (ADS + Sway)
		m_StatAffectingAttachments.Insert("weaponBayonet");
		m_StatAffectingAttachments.Insert("Bayonet");
		m_StatAffectingAttachments.Insert("M9A1Bayonet");
		
		// MAGAZINES (ADS if high-cap)
		m_StatAffectingAttachments.Insert("weaponMagazine");
		m_StatAffectingAttachments.Insert("Mag_");
		
		// MUZZLE ATTACHMENTS
		m_StatAffectingAttachments.Insert("suppressorBase");
		m_StatAffectingAttachments.Insert("weaponMuzzle");
		m_StatAffectingAttachments.Insert("weaponSuppressor");
	}
	
	protected void InitCosmeticAttachments()
	{
		m_CosmeticAttachments = new TStringArray;
		
		// TRULY COSMETIC ONLY
		m_CosmeticAttachments.Insert("weaponWrap");
		m_CosmeticAttachments.Insert("weaponCamo");
		m_CosmeticAttachments.Insert("weaponSling");
		m_CosmeticAttachments.Insert("RifleSling");
	}
	
	bool AttachmentAffectsStats(string attachmentType)
	{
		if (!attachmentType || attachmentType == "") return false;
		if (AttachmentIsCosmetic(attachmentType)) return false;
		return true;
	}
	
	bool AttachmentIsCosmetic(string attachmentType)
	{
		if (!attachmentType || attachmentType == "") return false;

		if (attachmentType == "weaponWrap") return true;
		if (attachmentType == "weaponCamo") return true;
		if (attachmentType == "weaponSling") return true;
		if (attachmentType == "RifleSling") return true;

		return false;
	}
	
	bool ShouldTriggerStatRecalc(string attachmentType, string slotName)
	{
		if (!attachmentType || attachmentType == "") return false;

		if (slotName == "weaponWrap") return false;
		if (slotName == "weaponCamo") return false;
		if (slotName == "weaponSling") return false;
		if (slotName == "RifleSling") return false;
		if (AttachmentIsCosmetic(attachmentType)) return false;
		
		return AttachmentAffectsStats(attachmentType);
	}
	
	bool IsServer() { return m_IsServer; }
	bool IsClient() { return m_IsClient; }
}
