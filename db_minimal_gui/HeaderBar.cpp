/*
  ==============================================================================

    HeaderBar.h
    Created: 21 Dec 2019 5:29:10pm
    Author:  damob

  ==============================================================================
*/

#pragma once

namespace DB
{

//==============================================================================
/*
*/
class HeaderBar : public juce::Component
{
public:
	HeaderBar() {};
	HeaderBar(juce::String mytext) {

		header = mytext;

	};
	~HeaderBar() {};

	void paint(juce::Graphics& g) override {

		juce::Colour light_grey = findColour(0, true);
		juce::Colour grey = findColour(1, true);
		juce::Colour dark_grey = findColour(2, true);

		juce::Rectangle<int> header_bounds(0, 0, getLocalBounds().getWidth(), 90);

		g.fillAll(grey);
		g.setColour(dark_grey);

		auto bottom_bar = header_bounds.removeFromBottom(20);
		g.fillRect(bottom_bar);

		g.setFont(45);
		auto text_bounds = header_bounds;
		text_bounds.removeFromLeft(40);

		g.drawText(header, text_bounds, juce::Justification::centredLeft);

		g.setColour(grey);
		g.setFont(14);

		auto left_text = bottom_bar;
		left_text.removeFromLeft(10);

		auto right_text = bottom_bar;
		right_text.removeFromRight(10);

		g.drawText("db", left_text, juce::Justification::centredLeft);
		g.drawText("db", right_text, juce::Justification::centredRight);
		g.drawText("digital garden", bottom_bar, juce::Justification::centred);

		//g.fillRect(text_bounds);
	};
	void resized() override {};

	void set_text(juce::String header_text) {
		header = header_text;
	};

private:

	juce::String header = " ";

	int bounds_value = 90; // 90 pixels depth

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HeaderBar)
};

}