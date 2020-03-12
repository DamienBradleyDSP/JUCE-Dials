#ifdef DB_MODULE_TESTING
#include "JuceHeader.h"
#endif 

#include "HeaderBar.h"

DB::minimalGUI::HeaderBar::HeaderBar()
{
}

DB::minimalGUI::HeaderBar::HeaderBar(juce::String my_text)
{
	header = my_text;
}

void DB::minimalGUI::HeaderBar::paint(juce::Graphics& g)
{
	juce::Colour light_grey = findColour(0, true);
	juce::Colour grey = findColour(1, true);
	juce::Colour dark_grey = findColour(2, true);

	juce::Rectangle<int> header_bounds(0, 0, getLocalBounds().getWidth(), headerHeight);

	g.fillAll(grey);
	g.setColour(dark_grey);

	auto bottom_bar = header_bounds.removeFromBottom(20);
	g.fillRect(bottom_bar);

	g.setFont(45.0f);
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

	//g.fillRect(text_bounds);
}

void DB::minimalGUI::HeaderBar::resized()
{
}

void DB::minimalGUI::HeaderBar::setText(juce::String header_text)
{
	header = header_text;
}

int DB::minimalGUI::HeaderBar::getHeaderHeight()
{
	return headerHeight;
}
