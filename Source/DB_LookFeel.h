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

namespace DB_Colours
{
	
}
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

	enum DB_Colours
	{
		light_grey = 0x1000b00, 
		grey = 0x1000a00,  
		dark_grey = 0x1000c00, 
	};
	
	Colour grey(34, 34, 34);
	Colour light_grey(136, 136, 136);
	Colour dark_grey(25, 25, 25);
	

private:


	Typeface::Ptr tface = Typeface::createSystemTypefaceFor(BinaryData::MyriadProRegular_otf, BinaryData::MyriadProRegular_otfSize);
	
	

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DB_LookFeel)
};
