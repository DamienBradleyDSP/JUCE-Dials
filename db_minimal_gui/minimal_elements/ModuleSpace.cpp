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
	
	paintModuleFrame(g);
	resized();
}


void DB::minimalGUI::ModuleSpace::resized()
{
	
	auto spaceBounds = innerBounds;
	auto tabBounds = spaceBounds.removeFromBottom(tabHeight);
	auto tabEnabledBounds = spaceBounds.removeFromTop(tabHeight);
	auto tabRightSpace = tabBounds;

	int tabCounter = 0;
	auto tabSpaceIterator = tabSpaces.begin();

	for (auto tab : tabButtons)
	{
		tabRightSpace = tabBounds.removeFromRight(tabWidth);

		if (tabEnabled[tabCounter])
		{
			tab->setBounds(tabEnabledBounds.removeFromLeft(tabWidth).toNearestInt());
		}
		else tab->setBounds(tabRightSpace.toNearestInt());

		tabCounter++;
	}

	
	for (auto&& main : mainSpace) main->setBounds(spaceBounds.toNearestInt());
	for(auto&& tab : tabSpaces) tab->setBounds(spaceBounds.toNearestInt());

	for (auto&& main : mainSpace) main->toFront(true);

	tabCounter = 0;
	for (auto&& tab : tabSpaces)
	{
		if (tabEnabled[tabCounter])
		{
			tab->toFront(true);
		}
		tabCounter++;
	}
	
	/*tabCounter = 0;
	for (auto&& tab : tabSpaces)
	{
		if (tabEnabled[tabCounter])
		{
			for (auto&& main : mainSpace) main->setBounds(0,0,0,0);
			tab->setBounds(spaceBounds.toNearestInt());
			tab->toFront(true);
		}
		else
		{
			tab->setBounds(0, 0, 0, 0);
		}
		tabCounter++;
	}*/
	//mainSpace->toFront(false);

	//*/

}


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
	tabEnabled.push_back(false);

	tabButtons.getLast()->setButtonSizes(tabCornerSize,tabStripSize,tabFontSize);
	tabButtons.getLast()->addMouseListener(this, true);
	makeTabsVisible();

}
void DB::minimalGUI::ModuleSpace::mouseUp(const MouseEvent& event)
{

	auto tabCounter = 0;
	for (auto&& tab : tabButtons)
	{

		if (tab == event.originalComponent)
		{
			tabEnabled[tabCounter].flip();
		}
		else
		{
			tabEnabled[tabCounter] = false;
		}

		tabCounter++;
	}
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

void DB::minimalGUI::ModuleSpace::paintModuleFrame(juce::Graphics& g)
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
}


