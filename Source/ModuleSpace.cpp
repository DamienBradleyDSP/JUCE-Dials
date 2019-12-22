/*
  ==============================================================================

    ModuleSpace.cpp
    Created: 21 Dec 2019 6:03:44pm
    Author:  damob

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "ModuleSpace.h"

//==============================================================================
ModuleSpace::ModuleSpace()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

ModuleSpace::~ModuleSpace()
{
}

void ModuleSpace::paint (Graphics& g)
{
	Colour light_grey = findColour(0, true);
	Colour grey = findColour(1, true);
	Colour dark_grey = findColour(2, true);

	auto bounds = getLocalBounds().toFloat();
	auto scaling_val = bounds.getHeight();
	auto corner_size = 40;

	g.setColour(dark_grey);
	g.fillRoundedRectangle(bounds, corner_size);

	
	auto bottom_height = 50;
	auto edited_bounds = bounds.reduced(5).removeFromTop(bounds.getHeight() - bottom_height);

	g.setColour(grey);
	g.fillRoundedRectangle(edited_bounds, corner_size);

	g.setColour(dark_grey);
	g.fillRect(edited_bounds.removeFromBottom(50));


}

void ModuleSpace::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
