#pragma once
#include "BinaryData/BinaryData.h"

namespace DB
{
namespace minimalGUI
{

class LookFeel : public juce::LookAndFeel_V4
{
public:

	LookFeel();

	void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, juce::Slider&) override;

	void drawLabel(juce::Graphics& g, juce::Label& label) override;

	juce::Slider::SliderLayout getSliderLayout(juce::Slider& slider) override;

	void drawToggleButton(juce::Graphics& g, juce::ToggleButton& button,
		bool, bool) override;

	void drawComboBox(juce::Graphics& g, int width, int height, bool,
		int, int, int, int, juce::ComboBox& box) override;

private:

	juce::Colour grey = juce::Colour::fromRGB(34, 34, 34);				//(34, 34, 34);
	juce::Colour light_grey = juce::Colour::fromRGB(136, 136, 136);			//(136, 136, 136);
	juce::Colour dark_grey = juce::Colour::fromRGB(25, 25, 25);			//(25, 25, 25);

	juce::Typeface::Ptr tface = juce::Typeface::createSystemTypefaceFor(BinaryData::MyriadProRegular_otf, BinaryData::MyriadProRegular_otfSize);



	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LookFeel)
};

}
}

