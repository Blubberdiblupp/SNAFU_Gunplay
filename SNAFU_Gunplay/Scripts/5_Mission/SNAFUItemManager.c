modded class ItemManager
{
	protected Widget m_SNAFUStatsDisplay;
	
	void ItemManager(Widget root)
	{
		Widget statsParent;
		if (root)
		{
			statsParent = root.FindAnyWidget("GridSpacerWidget1");
		}
		
		if (statsParent)
		{
			m_SNAFUStatsDisplay = GetGame().GetWorkspace().CreateWidgets("SNAFU_Gunplay/GUI/layouts/SNAFUItemStatsToolTip.layout", statsParent);
			if (m_SNAFUStatsDisplay)
			{
				m_SNAFUStatsDisplay.Show(false);
			}
		}
	}
	
	override void PrepareTooltip(EntityAI item, int x = 0, int y = 0)
	{
		super.PrepareTooltip(item, x, y);
		
		if (!m_SNAFUStatsDisplay)
		{
			return;
		}
		
		SNAFUGunplayAdminConfig adminConfig = SNAFUGetAdminConfig();
		if (adminConfig && !adminConfig.EnableTooltipStats)
		{
			m_SNAFUStatsDisplay.Show(false);
			return;
		}
		
		if (!item)
		{
			m_SNAFUStatsDisplay.Show(false);
			return;
		}
		
		SNAFUDisplayData displayData = SNAFUDisplayStats.GetDisplay(item);
		if (!displayData)
		{
			m_SNAFUStatsDisplay.Show(false);
			return;
		}
		
		UpdateSNAFUStatsTooltip(displayData);
		m_SNAFUStatsDisplay.Show(true);
	}
	
	protected SNAFUTierEffect GetAttachmentTierDisplayLine(EntityAI item)
	{
		return SNAFUDisplayStats.GetEffect(item);
	}
	
	protected void UpdateSNAFUStatsTooltip(SNAFUDisplayData displayData)
	{
		SetSNAFUText("tier_value", displayData.TierLabel, 0xFFFFFFFF);
		SetSNAFUText("recoil_label", displayData.Line1Label, 0xFFAF9442);
		SetSNAFUText("recoil_value", displayData.Line1Value, displayData.Line1Color);
		SetSNAFUText("sway_label", displayData.Line2Label, 0xFFAF9442);
		SetSNAFUText("sway_value", displayData.Line2Value, displayData.Line2Color);
		SetSNAFUText("ads_label", displayData.Line3Label, 0xFFAF9442);
		SetSNAFUText("ads_value", displayData.Line3Value, displayData.Line3Color);
		SetSNAFUText("precision_label", displayData.Line4Label, 0xFFAF9442);
		SetSNAFUText("precision_value", displayData.Line4Value, displayData.Line4Color);
		SetSNAFUText("hipfire_label", displayData.Line5Label, 0xFFAF9442);
		SetSNAFUText("hipfire_value", displayData.Line5Value, displayData.Line5Color);
		SetSNAFULineVisible("hipfire", displayData.ShowLine5);
	}
	
	protected void SetSNAFUText(string widgetName, string text, int color)
	{
		TextWidget widget = TextWidget.Cast(m_SNAFUStatsDisplay.FindAnyWidget(widgetName));
		if (!widget)
		{
			return;
		}
		
		widget.SetText(text);
		widget.SetColor(color);
	}
	
	protected void SetSNAFULineVisible(string widgetName, bool visible)
	{
		Widget widget = m_SNAFUStatsDisplay.FindAnyWidget(widgetName);
		if (widget)
		{
			widget.Show(visible);
		}
	}
	
	protected string FormatSNAFUDelta(float multiplier)
	{
		if (Math.AbsFloat(multiplier - 1.0) < 0.001)
		{
			return "0%";
		}
		
		int rounded = Math.Round((multiplier - 1.0) * 100.0);
		if (rounded > 0)
		{
			return string.Format("+%1%%", rounded);
		}
		
		return string.Format("%1%%", rounded);
	}
	
	protected int GetSNAFUDeltaColor(float multiplier, bool higherIsBetter)
	{
		if (Math.AbsFloat(multiplier - 1.0) < 0.001)
		{
			return 0xFFFFFFFF;
		}
		
		bool improved;
		if (higherIsBetter)
		{
			improved = multiplier > 1.0;
		}
		else
		{
			improved = multiplier < 1.0;
		}
		
		if (improved)
		{
			return 0xFF22DD66;
		}
		
		return 0xFFFF5555;
	}
}
