/*
  ==============================================================================

    DB_LookFeel.cpp
    Created: 19 Dec 2019 3:26:59pm
    Author:  damob

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "DB_LookFeel.h"

//==============================================================================

DB_LookFeel::DB_LookFeel()
{
	setColour(Slider::ColourIds::backgroundColourId, Colour::fromRGB(34,34,34));
	setColour(Slider::ColourIds::rotarySliderFillColourId, Colour::fromRGB(136,136,136));
	setColour(Slider::ColourIds::rotarySliderOutlineColourId, Colour::fromRGB(25,25,25));
	setColour(Slider::ColourIds::trackColourId, Colour::fromRGB(25,25,25));
}

DB_LookFeel::~DB_LookFeel()
{
}

void DB_LookFeel::drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
{

	auto outline = slider.findColour(Slider::rotarySliderOutlineColourId);
	auto fill = slider.findColour(Slider::rotarySliderFillColourId);

	auto bounds = Rectangle<int>(x, y, width, height).toFloat().reduced(10);

	auto radius = jmin(bounds.getWidth(), bounds.getHeight()) / 2.0f;
	auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
	auto lineW = jmin(8.0f, radius * 0.5f);
	auto arcRadius = radius - lineW * 0.5f;

	Path backgroundArc;
	backgroundArc.addCentredArc(bounds.getCentreX(),
		bounds.getCentreY(),
		arcRadius,
		arcRadius,
		0.0f,
		rotaryStartAngle,
		rotaryEndAngle,
		true);

	g.setColour(outline);
	g.strokePath(backgroundArc, PathStrokeType(lineW, PathStrokeType::curved, PathStrokeType::rounded));

	if (slider.isEnabled())
	{
		Path valueArc;
		valueArc.addCentredArc(bounds.getCentreX(),
			bounds.getCentreY(),
			arcRadius,
			arcRadius,
			0.0f,
			rotaryStartAngle,
			toAngle,
			true);

		g.setColour(fill);
		g.strokePath(valueArc, PathStrokeType(lineW, PathStrokeType::curved, PathStrokeType::rounded));
	}

	auto thumbWidth = lineW * 2.0f;
	Point<float> thumbPoint(bounds.getCentreX() + arcRadius * std::cos(toAngle - MathConstants<float>::halfPi),
		bounds.getCentreY() + arcRadius * std::sin(toAngle - MathConstants<float>::halfPi));

	g.setColour(slider.findColour(Slider::thumbColourId));
	g.fillEllipse(Rectangle<float>(thumbWidth, thumbWidth).withCentre(thumbPoint));

}
