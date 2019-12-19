/*
  ==============================================================================

    DB_LookFeel.h
    Created: 19 Dec 2019 3:26:59pm
    Author:  damob

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/

class DB_LookFeel    : public LookAndFeel_V4
{
public:

	DB_LookFeel();

	~DB_LookFeel();

	void drawRotarySlider(Graphics& g, int x, int y, int width, int height,
		float sliderPosProportional, float rotaryStartAngle,
		float rotaryEndAngle, Slider& slider) override;

private:
	

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DB_LookFeel)
};
