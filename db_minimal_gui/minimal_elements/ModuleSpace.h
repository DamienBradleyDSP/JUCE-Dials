#pragma once
#include "ModuleSpaceElements/TabElement.h"

namespace DB
{
namespace minimalGUI
{

class ModuleSpace : public juce::Component
{
public:
	ModuleSpace();
	~ModuleSpace();

	void paint(juce::Graphics& g) override;
	void resized() override;

	void setText(juce::String text);

	void addTab(juce::String tabName, juce::Component* tabSpace);

private:

	void makeTabsVisible();
	

	juce::String module_text = " ";

	OwnedArray<DB::minimalGUI::_moduleInternalElements::TabElement> tabButtons;
	OwnedArray<juce::Component> tabSpaces;

	juce::Rectangle<float> innerBounds;

	const float moduleBarHeight = 25.0f;
	const float moduleFrameThickness  = 5.0f;
	const float moduleCornerSize = 25.0f;
	const float moduleFontSize = 33.0f;

	const float tabHeight = 20.0f;
	const float tabWidth = 180.0f;
	const float tabCornerSize = 10.0f;
	const float tabStripSize = 3.0f;
	const float tabFontSize = 13.0f;

	juce::Colour light_grey;
	juce::Colour grey;
	juce::Colour dark_grey;
	juce::Colour textColour;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ModuleSpace)
};

}
}

