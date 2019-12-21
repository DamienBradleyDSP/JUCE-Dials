/*
  ==============================================================================

    HeaderBar.h
    Created: 21 Dec 2019 5:29:10pm
    Author:  damob

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class HeaderBar    : public Component
{
public:
    HeaderBar();
    HeaderBar(String mytext);
    ~HeaderBar();

    void paint (Graphics&) override;
    void resized() override;

	void set_text(String header_text);

private:

	String header = " ";
	

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HeaderBar)
};
