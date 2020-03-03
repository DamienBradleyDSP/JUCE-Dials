/*
  ==============================================================================

    SidewaysModuleSpace.cpp
    Created: 2 Mar 2020 5:59:42pm
    Author:  damob

  ==============================================================================
*/

#ifdef DB_MODULE_TESTING
#include "JuceHeader.h"
#include "SidewaysModuleSpace.h"
#endif 

#ifndef DB_MODULE_TESTING
#include "SidewaysModuleSpace.h"
#include "BinaryData/BinaryData.cpp"
#endif // !DB_MODULE_TESTING





//==============================================================================


namespace DB
{

SidewaysModuleSpace::SidewaysModuleSpace()
{

}

SidewaysModuleSpace::SidewaysModuleSpace(juce::String text)
{

	moduleText = text;
}

SidewaysModuleSpace::~SidewaysModuleSpace()
{
}

void SidewaysModuleSpace::paint(juce::Graphics& g)
{
	juce::Colour light_grey = findColour(0, true);
	juce::Colour grey = findColour(1, true);
	juce::Colour dark_grey = findColour(2, true);

	auto bounds = getLocalBounds().toFloat();
	auto text_bounds = bounds;
	auto corner_size = 25.0f;

	g.setColour(dark_grey);
	g.fillRoundedRectangle(bounds, corner_size);


	auto edited_bounds = bounds.reduced(5.0f).removeFromRight(bounds.getWidth() - tabWidth);

	g.setColour(grey);
	g.fillRoundedRectangle(edited_bounds, corner_size);

	g.setColour(dark_grey);
	g.fillRect(edited_bounds.removeFromLeft(tabWidth));

	innerBounds = edited_bounds;

	g.setColour(light_grey);
	g.setFont(30.0f);
	g.drawText(moduleText, text_bounds.removeFromLeft(tabWidth), juce::Justification::centred, true);

}

void SidewaysModuleSpace::resized()
{
	// This method is where you should set the bounds of any child
	// components that your component contains..

}

void SidewaysModuleSpace::setText(juce::String text)
{
	moduleText = text;
}

void SidewaysModuleSpace::setTabWidth(float newWidth)
{
	tabWidth = newWidth;
}

juce::Rectangle<float> SidewaysModuleSpace::getInternalBounds()
{
	return innerBounds;
}

}