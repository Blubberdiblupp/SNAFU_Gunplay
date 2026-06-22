class SNAFUGUINetworkManager
{
	protected static ref SNAFUGUINetworkManager m_Instance;
	
	protected bool m_IsClientSideOnly;
	protected int m_LastStatUpdateFrame;
	protected int m_LocalFrameCounter;
	protected const int MIN_UPDATE_FRAMES = 10;
	
	static SNAFUGUINetworkManager GetInstance()
	{
		if (!m_Instance)
		{
			m_Instance = new SNAFUGUINetworkManager();
			m_Instance.Init();
		}
		return m_Instance;
	}
	
	void SNAFUGUINetworkManager()
	{
	}
	
	void Init()
	{
		m_IsClientSideOnly = GetGame().IsClient();
		m_LastStatUpdateFrame = 0;
		m_LocalFrameCounter = 0;
		
		Print("[SNAFU Gunplay] GUI Network Manager initialized");
		Print("[SNAFU Gunplay] Client-side only calculations: " + m_IsClientSideOnly);
	}
	
	bool ShouldUpdateGUI()
	{
		m_LocalFrameCounter++;
		int currentFrame = m_LocalFrameCounter;
		
		if (currentFrame - m_LastStatUpdateFrame < MIN_UPDATE_FRAMES)
		{
			return false;
		}
		
		m_LastStatUpdateFrame = currentFrame;
		return true;
	}
	
	void ForceGUIUpdate()
	{
		m_LastStatUpdateFrame = 0;
		m_LocalFrameCounter = 0;
	}
	
	bool IsClientSideOnly()
	{
		return m_IsClientSideOnly;
	}
	
	void LogGUICalculation(string context)
	{
		SNAFUGunplayConfig config = SNAFUGunplayConfig.GetInstance();
		
		if (!config.DebugMode) return;
		
		if (m_IsClientSideOnly)
		{
			Print("[SNAFU Gunplay] [CLIENT] GUI Update: " + context);
		}
		else
		{
			Print("[SNAFU Gunplay] [SERVER] GUI Update: " + context);
		}
	}
}
