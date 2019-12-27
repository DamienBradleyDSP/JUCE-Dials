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
    ModuleSpace(String text);
    ModuleSpace(String text,bool inverted,bool sideways);
    ~ModuleSpace();

    void paint (Graphics&) override;
    void resized() override;

	void set_text(String text);
	void rotate(bool inverted, bool sideways);


private:

	String module_text = " ";

	bool inverted_flag = false, sideways_flag = false;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModuleSpace)
};
