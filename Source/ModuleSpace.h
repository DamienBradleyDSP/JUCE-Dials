/*
  ==============================================================================

    ModuleSpace.h
    Created: 21 Dec 2019 6:03:44pm
    Author:  damob

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "DB_LookFeel.h"

//==============================================================================
/*
*/
class ModuleSpace    : public Component
{
public:
    ModuleSpace();
    ~ModuleSpace();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModuleSpace)
};
