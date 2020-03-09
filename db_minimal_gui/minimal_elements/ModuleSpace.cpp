#ifdef DB_MODULE_TESTING
#include "JuceHeader.h"
#endif 

#include "ModuleSpace.h"

void DB::minimalGUI::ModuleSpace::paint(juce::Graphics& g)
{
	light_grey = findColour(0, true);
	grey = findColour(1, true);
	dark_grey = findColour(2, true);
	textColour = light_grey;

	
	layoutSpaces();
	paintModuleFrame(g);
	//if (!mainSpaceSelected) paintTabFrame(g);
	
}

void DB::minimalGUI::ModuleSpace::resized() {}

void DB::minimalGUI::ModuleSpace::setText(juce::String text)
{
	module_text = text;
}

void DB::minimalGUI::ModuleSpace::addMainSpace(juce::Component* space)
{
	mainSpace.add(space);
	addAndMakeVisible(mainSpace.getFirst());
}

void DB::minimalGUI::ModuleSpace::addTab(juce::String name, juce::Component* tabSpace)
{
	tabButtons.add(new DB::minimalGUI::_moduleInternalElements::TabElement(name));
	tabSpaces.add(tabSpace);

	tabButtons.getLast()->setButtonSizes(tabCornerSize,tabStripSize,tabFontSize);
	tabButtons.getLast()->addMouseListener(this, true);
	makeTabsVisible();

}
void DB::minimalGUI::ModuleSpace::mouseDown(const juce::MouseEvent&)
{
	repaint();
}
void DB::minimalGUI::ModuleSpace::mouseUp(const juce::MouseEvent& event)
{
	// Change whether tab enabled on click

	for (auto&& tab : tabButtons)
	{
		if (tab == event.originalComponent) tab->enabledFlip();
		else tab->setDisabled();
	}

	//Repaint to reflect tab selection change
	repaint();
}


void DB::minimalGUI::ModuleSpace::makeTabsVisible()
{
	for (auto&& tab : tabButtons)
	{
		addAndMakeVisible(tab);
	}
	for (auto&& tab : tabSpaces)
	{
		addAndMakeVisible(tab);
	}

}

void DB::minimalGUI::ModuleSpace::layoutSpaces()
{
	auto spaceBounds = innerBounds;
	auto tabBounds = spaceBounds.removeFromBottom(tabHeight);
	auto tabEnabledBounds = spaceBounds.removeFromTop(tabHeight);
	auto tabRightSpace = tabBounds;

	// Place tab buttons, if enabled tab is drawn at the top of frame

	for (auto tab : tabButtons)
	{
		tabRightSpace = tabBounds.removeFromRight(tabWidth);

		if (tab->getButtonState()) tab->setBounds(tabEnabledBounds.removeFromLeft(tabWidth).toNearestInt());
		else tab->setBounds(tabRightSpace.toNearestInt());

	}

	// Set bounds of spaces to be the inner space within the module frame

	for (auto&& main : mainSpace) main->setBounds(spaceBounds.toNearestInt());
	for (auto&& tab : tabSpaces) tab->setBounds(spaceBounds.toNearestInt());

	// Set main to front

	for (auto&& main : mainSpace) main->toFront(true);
	mainSpaceSelected = true;

	// For each tab in children, if a tab is enabled, set that to the front

	int tabCounter = 0;
	for (auto&& tab : tabSpaces)
	{
		if (tabButtons[tabCounter]->getButtonState())
		{
			tab->toFront(true);
			mainSpaceSelected = false;
		}
		tabCounter++;
	}
}

void DB::minimalGUI::ModuleSpace::paintModuleFrame(juce::Graphics& g)
{

	auto bounds = getLocalBounds().toFloat();
	auto text_bounds = bounds;

	//Fill outer rounded rect
	g.setColour(dark_grey);
	g.fillRoundedRectangle(bounds, moduleCornerSize);

	auto edited_bounds = bounds.reduced(moduleFrameThickness).removeFromTop(bounds.getHeight() - moduleBarHeight);

	// Fill inner rounded rect
	
	if (!mainSpaceSelected)
	{
		auto gradient = juce::ColourGradient::vertical(dark_grey, juce::Point<float>(edited_bounds.getBottomLeft()).getY(),
													   grey, juce::Point<float>(edited_bounds.getTopRight()).getY());
		auto heightOfBounds = edited_bounds.getHeight();
		auto bottomOfTabAsRatio = (heightOfBounds - tabHeight+tabStripSize) / heightOfBounds;
		gradient.addColour(bottomOfTabAsRatio, dark_grey);
		g.setGradientFill(gradient);
		g.fillRoundedRectangle(edited_bounds, moduleCornerSize);

		auto boundsCopy = edited_bounds;
		boundsCopy.removeFromTop(tabHeight-tabStripSize);
		g.setFillType(juce::FillType(grey));
		g.setColour(grey);
		g.fillRect(boundsCopy);

		auto tabStrip = boundsCopy.removeFromTop(tabStripSize);
		g.setColour(dark_grey);
		g.fillRect(tabStrip);
	}
	else
	{
		g.setColour(grey);
		g.fillRoundedRectangle(edited_bounds, moduleCornerSize);
	}
	

	// Fill bottom rectangle
	g.setColour(dark_grey);
	g.fillRect(edited_bounds.removeFromBottom(moduleBarHeight));

	innerBounds = edited_bounds;

	// Draw module text
	g.setColour(textColour);
	g.setFont(moduleFontSize);
	g.drawText(module_text, text_bounds.removeFromBottom(moduleBarHeight * 2.0f), juce::Justification::centred, true);
}

void DB::minimalGUI::ModuleSpace::paintTabFrame(juce::Graphics& g)
{

	auto selectedTabSpace = innerBounds;
	selectedTabSpace = selectedTabSpace.removeFromTop(tabHeight);
	auto selectedTabLine = selectedTabSpace.removeFromBottom(tabStripSize);
	
	g.setGradientFill(
	juce::ColourGradient::vertical(dark_grey, juce::Point<float>(selectedTabSpace.getBottomLeft()).getY(),
								   grey,      juce::Point<float>(selectedTabSpace.getTopRight()).getY()));
	g.fillRoundedRectangle(selectedTabSpace,tabCornerSize);

	
	auto unselectedTabLine = selectedTabSpace.removeFromBottom(tabStripSize);
	


	//g.setColour(dark_grey);
	//g.fillRect(unselectedTabLine);

	//if (isMouseButtonDown(false)) g.fillRect(selectedTabLine);

}




