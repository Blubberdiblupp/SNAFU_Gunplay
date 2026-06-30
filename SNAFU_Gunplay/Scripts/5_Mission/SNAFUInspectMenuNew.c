modded class InspectMenuNew
{
	protected Widget m_SNAFUInspectStatsDisplay;
	
	override void SetItem(EntityAI item)
	{
		super.SetItem(item);
		UpdateSNAFUInspectStats(item);
	}
	
	protected void UpdateSNAFUInspectStats(EntityAI item)
	{
		EnsureSNAFUInspectStatsDisplay();
		if (!m_SNAFUInspectStatsDisplay)
		{
			return;
		}
		
		SNAFUGunplayAdminConfig adminConfig = SNAFUGetAdminConfig();
		if (adminConfig && !adminConfig.EnableInspectStats)
		{
			m_SNAFUInspectStatsDisplay.Show(false);
			return;
		}
		
		SNAFUDisplayData displayData = SNAFUDisplayStats.GetDisplay(item);
		if (!displayData)
		{
			m_SNAFUInspectStatsDisplay.Show(false);
			return;
		}
		
		UpdateSNAFUInspectStatsDisplay(displayData);
		
		m_SNAFUInspectStatsDisplay.Show(true);
	}
	
	protected void UpdateSNAFUInspectStatsDisplay(SNAFUDisplayData displayData)
	{
		SetSNAFUInspectText("tier_value", displayData.TierLabel, 0xFFFFFFFF);
		SetSNAFUInspectText("recoil_label", displayData.Line1Label, 0xFFAF9442);
		SetSNAFUInspectText("recoil_value", displayData.Line1Value, displayData.Line1Color);
		SetSNAFUInspectText("sway_label", displayData.Line2Label, 0xFFAF9442);
		SetSNAFUInspectText("sway_value", displayData.Line2Value, displayData.Line2Color);
		SetSNAFUInspectText("ads_label", displayData.Line3Label, 0xFFAF9442);
		SetSNAFUInspectText("ads_value", displayData.Line3Value, displayData.Line3Color);
		SetSNAFUInspectText("precision_label", displayData.Line4Label, 0xFFAF9442);
		SetSNAFUInspectText("precision_value", displayData.Line4Value, displayData.Line4Color);
		SetSNAFUInspectText("hipfire_label", displayData.Line5Label, 0xFFAF9442);
		SetSNAFUInspectText("hipfire_value", displayData.Line5Value, displayData.Line5Color);
		SetSNAFUInspectLineVisible("hipfire", displayData.ShowLine5);
	}
	
	protected void EnsureSNAFUInspectStatsDisplay()
	{
		if (m_SNAFUInspectStatsDisplay)
		{
			return;
		}
		
		if (!layoutRoot)
		{
			return;
		}
		
		Widget parent = layoutRoot.FindAnyWidget("ItemFrameWidgetPanel");
		if (!parent)
		{
			parent = layoutRoot;
		}
		
		m_SNAFUInspectStatsDisplay = GetGame().GetWorkspace().CreateWidgets("SNAFU_Gunplay/GUI/layouts/SNAFUItemStatsInspect.layout", parent);
		if (m_SNAFUInspectStatsDisplay)
		{
			m_SNAFUInspectStatsDisplay.Show(false);
		}
	}
	
	protected void SetSNAFUInspectText(string widgetName, string text, int color)
	{
		TextWidget widget = TextWidget.Cast(m_SNAFUInspectStatsDisplay.FindAnyWidget(widgetName));
		if (!widget)
		{
			return;
		}
		
		widget.SetText(text);
		widget.SetColor(color);
	}
	
	protected void SetSNAFUInspectLineVisible(string widgetName, bool visible)
	{
		Widget widget = m_SNAFUInspectStatsDisplay.FindAnyWidget(widgetName);
		if (widget)
		{
			widget.Show(visible);
		}
	}
}
