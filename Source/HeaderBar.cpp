/*
  ==============================================================================

    HeaderBar.cpp
    Created: 21 Dec 2019 5:29:10pm
    Author:  damob

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "HeaderBar.h"

//==============================================================================
HeaderBar::HeaderBar()
{

	


}
HeaderBar::HeaderBar(String my_text)
{

	header = my_text;

}

HeaderBar::~HeaderBar()
{
	setLookAndFeel(nullptr);
}

void HeaderBar::paint (Graphics& g)
{

	Colour light_grey = findColour(0, true);
	Colour grey = findColour(1, true);
	Colour dark_grey = findColour(2, true);

	Rectangle<int> header_bounds(0, 0, getLocalBounds().getWidth(), 90);

    g.fillAll (grey);
	g.setColour(dark_grey);

	auto bottom_bar = header_bounds.removeFromBottom(20);
	g.fillRect(bottom_bar);

	g.setFont(45);
	auto text_bounds = header_bounds;
	text_bounds.removeFromLeft(40);

	g.drawText(header,text_bounds,Justification::centredLeft);

	g.setColour(grey);
	g.setFont(14);

	auto left_text = bottom_bar;
	left_text.removeFromLeft(10);
	
	auto right_text = bottom_bar;
	right_text.removeFromRight(10);

	g.drawText("db", left_text, Justification::centredLeft);
	g.drawText("db", right_text, Justification::centredRight);
	g.drawText("digital garden", bottom_bar, Justification::centred);
	
	//g.fillRect(text_bounds);
}

void HeaderBar::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void HeaderBar::set_text(String header_text)
{
	header = header_text;
}

