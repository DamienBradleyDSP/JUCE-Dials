#ifdef DB_MODULE_TESTING
#include "JuceHeader.h"
#endif 

#include "ModuleSpace.h"

DB::minimalGUI::ModuleSpace::ModuleSpace()
{
}

DB::minimalGUI::ModuleSpace::~ModuleSpace()
{
}

void DB::minimalGUI::ModuleSpace::paint(juce::Graphics& g)
{
	
	light_grey = findColour(0, true);
	grey = findColour(1, true);
	dark_grey = findColour(2, true);
	textColour = light_grey;

	auto bounds = getLocalBounds().toFloat();
	auto text_bounds = bounds;

	g.setColour(dark_grey);
	g.fillRoundedRectangle(bounds, moduleCornerSize);

	auto edited_bounds = bounds.reduced(moduleFrameThickness).removeFromTop(bounds.getHeight() - moduleBarHeight);

	g.setColour(grey);
	g.fillRoundedRectangle(edited_bounds, moduleCornerSize);



	g.setColour(dark_grey);
	g.fillRect(edited_bounds.removeFromBottom(moduleBarHeight));

	innerBounds = edited_bounds;

	g.setColour(textColour);
	//g.fillRect(text_bounds.removeFromBottom(bottom_height));
	g.setFont(moduleFontSize);
	g.drawText(module_text, text_bounds.removeFromBottom(moduleBarHeight * 2.0f), juce::Justification::centred, true);


	/*
	juce::Colour light_grey = findColour(0, true);
	juce::Colour grey = findColour(1, true);
	juce::Colour dark_grey = findColour(2, true);

	auto bounds = getLocalBounds().toFloat();
	auto text_bounds = bounds;
	auto corner_size = 25.0f;

	g.setColour(dark_grey);
	g.fillRoundedRectangle(bounds, corner_size);


	auto top_height = 15.0f;
	auto edited_bounds = bounds.reduced(5).removeFromBottom(bounds.getHeight() - top_height);

	g.setColour(grey);
	g.fillRoundedRectangle(edited_bounds, corner_size);

	g.setColour(dark_grey);
	g.fillRect(edited_bounds.removeFromTop(top_height));

	innerBounds = edited_bounds;

	g.setColour(grey);
	//g.fillRect(text_bounds.removeFromBottom(bottom_height));
	g.setFont(20.0f);
	g.drawText(module_text, text_bounds.removeFromTop(top_height * 1.6f), juce::Justification::centred, true);
	*/

	resized();
}


void DB::minimalGUI::ModuleSpace::resized()
{

	auto spaceBounds = innerBounds;
	auto tabBounds = spaceBounds.removeFromBottom(tabHeight);

	for (auto tab : tabButtons)
	{
		tab->setBounds(tabBounds.removeFromRight(tabWidth).toNearestInt());
	}


	for (auto&& tab : tabSpaces)
	{
		tab->setBounds(spaceBounds.toNearestInt());
	}
}


void DB::minimalGUI::ModuleSpace::setText(juce::String text)
{
	module_text = text;
}

void DB::minimalGUI::ModuleSpace::addTab(juce::String name, juce::Component* tabSpace)
{
	tabButtons.add(new DB::minimalGUI::_moduleInternalElements::TabElement(name));
	tabSpaces.add(tabSpace);

	tabButtons.getLast()->setButtonSizes(tabCornerSize,tabStripSize,tabFontSize);

	makeTabsVisible();
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


