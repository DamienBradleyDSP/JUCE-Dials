/*
  ==============================================================================

    DB_Knob.h
    Created: 19 Dec 2019 12:09:34am
    Author:  damob

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class DB_Knob    : public Component
{
public:
    DB_Knob();
    ~DB_Knob();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DB_Knob)
};
