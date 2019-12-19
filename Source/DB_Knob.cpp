/*
  ==============================================================================

    DB_Knob.cpp
    Created: 19 Dec 2019 12:09:34am
    Author:  damob

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "DB_Knob.h"

//==============================================================================
DB_Knob::DB_Knob()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

DB_Knob::~DB_Knob()
{
}

void DB_Knob::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

    g.drawText ("DB_Knob", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void DB_Knob::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
