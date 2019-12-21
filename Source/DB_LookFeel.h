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

	void drawLabel(Graphics& g, Label& l) override;

	Slider::SliderLayout getSliderLayout(Slider&) override;

	void drawToggleButton(Graphics&, ToggleButton&,
		bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;

	void drawComboBox(Graphics&, int width, int height, bool isButtonDown,
		int buttonX, int buttonY, int buttonW, int buttonH,
		ComboBox&) override;


	Colour grey;
	Colour light_grey;
	Colour dark_grey;
	Font text;

private:

	Typeface::Ptr tface = Typeface::createSystemTypefaceFor(BinaryData::MyriadProRegular_otf, BinaryData::MyriadProRegular_otfSize);
	
	

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DB_LookFeel)
};
