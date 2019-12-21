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
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (Colours::grey);   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::white);
    g.setFont (14.0f);
    g.drawText ("ModuleSpace", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void ModuleSpace::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
