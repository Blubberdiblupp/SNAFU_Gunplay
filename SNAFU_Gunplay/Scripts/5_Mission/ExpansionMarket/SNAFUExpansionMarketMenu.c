#ifdef EXPANSIONMODMARKET
modded class ExpansionMarketMenu
{
	protected Widget m_SNAFUMarketStatsDisplay;
	
	void ExpansionMarketMenu()
	{
		EnsureSNAFUMarketStatsDisplay();
	}
	
	override void UpdatePreview()
	{
		super.UpdatePreview();
		UpdateSNAFUMarketStats(EntityAI.Cast(m_CurrentPreviewObject), GetSNAFUMarketItemType(), GetSNAFUMarketAttachmentTypes());
	}
	
	protected void UpdateSNAFUMarketStats(EntityAI item, string itemType, array<string> attachmentTypes)
	{
		EnsureSNAFUMarketStatsDisplay();
		if (!m_SNAFUMarketStatsDisplay)
		{
			return;
		}
		
		SNAFUDisplayData displayData = SNAFUDisplayStats.GetDisplay(item, itemType, attachmentTypes);
		if (!displayData)
		{
			m_SNAFUMarketStatsDisplay.Show(false);
			return;
		}
		
		UpdateSNAFUMarketStatsDisplay(displayData);
		
		m_SNAFUMarketStatsDisplay.Show(true);
	}
	
	protected void UpdateSNAFUMarketStatsDisplay(SNAFUDisplayData displayData)
	{
		SetSNAFUMarketText("tier_value", displayData.TierLabel, 0xFFFFFFFF);
		SetSNAFUMarketText("recoil_label", displayData.Line1Label, 0xFFAF9442);
		SetSNAFUMarketText("recoil_value", displayData.Line1Value, displayData.Line1Color);
		SetSNAFUMarketText("sway_label", displayData.Line2Label, 0xFFAF9442);
		SetSNAFUMarketText("sway_value", displayData.Line2Value, displayData.Line2Color);
		SetSNAFUMarketText("ads_label", displayData.Line3Label, 0xFFAF9442);
		SetSNAFUMarketText("ads_value", displayData.Line3Value, displayData.Line3Color);
		SetSNAFUMarketText("precision_label", displayData.Line4Label, 0xFFAF9442);
		SetSNAFUMarketText("precision_value", displayData.Line4Value, displayData.Line4Color);
		SetSNAFUMarketText("hipfire_label", displayData.Line5Label, 0xFFAF9442);
		SetSNAFUMarketText("hipfire_value", displayData.Line5Value, displayData.Line5Color);
		SetSNAFUMarketLineVisible("hipfire", displayData.ShowLine5);
	}
	
	protected string GetSNAFUMarketItemType()
	{
		if (m_CurrentPreviewObject)
		{
			return m_CurrentPreviewObject.GetType();
		}
		
		ExpansionMarketItem marketItem = GetSelectedMarketItem();
		if (marketItem)
		{
			return marketItem.ClassName;
		}
		
		return "";
	}
	
	protected array<string> GetSNAFUMarketAttachmentTypes()
	{
		array<string> attachmentTypes = new array<string>;
		ExpansionMarketItem marketItem = GetSelectedMarketItem();
		if (!marketItem || !marketItem.SpawnAttachments)
		{
			return attachmentTypes;
		}
		
		foreach (string attachmentType : marketItem.SpawnAttachments)
		{
			if (attachmentType != "")
			{
				attachmentTypes.Insert(attachmentType);
			}
		}
		
		return attachmentTypes;
	}
	
	protected void EnsureSNAFUMarketStatsDisplay()
	{
		if (m_SNAFUMarketStatsDisplay)
		{
			return;
		}
		
		if (!m_LayoutRoot)
		{
			return;
		}
		
		Widget parent = m_LayoutRoot.FindAnyWidget("market_item_description_container");
		if (!parent)
		{
			parent = m_LayoutRoot;
		}
		
		m_SNAFUMarketStatsDisplay = GetGame().GetWorkspace().CreateWidgets("SNAFU_Gunplay/GUI/layouts/SNAFUExpansionMarketStats.layout", parent);
		if (m_SNAFUMarketStatsDisplay)
		{
			m_SNAFUMarketStatsDisplay.Show(false);
		}
	}
	
	protected void SetSNAFUMarketText(string widgetName, string text, int color)
	{
		TextWidget widget = TextWidget.Cast(m_SNAFUMarketStatsDisplay.FindAnyWidget(widgetName));
		if (!widget)
		{
			return;
		}
		
		widget.SetText(text);
		widget.SetColor(color);
	}
	
	protected void SetSNAFUMarketLineVisible(string widgetName, bool visible)
	{
		Widget widget = m_SNAFUMarketStatsDisplay.FindAnyWidget(widgetName);
		if (widget)
		{
			widget.Show(visible);
		}
	}
}
#endif
