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

	g.setColour(dark_grey);
	g.fillRoundedRectangle(bounds,scaling_val/10.0);

}

void ModuleSpace::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
