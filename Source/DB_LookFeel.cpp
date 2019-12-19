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

DB_LookFeel::DB_LookFeel() : grey(34,34,34), dark_grey(25,25,25), light_grey(136,136,136)
{
	
}

DB_LookFeel::~DB_LookFeel()
{
}



void DB_LookFeel::drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
{

	auto bounds = Rectangle<int>(x, y, width, height).toFloat().reduced(5); // add .reduced for smaller bounds
	rotaryStartAngle = -MathConstants<float>::pi*2.0*3.0/8.0;				// starting angle in radians
	rotaryEndAngle = MathConstants<float>::pi * 2.0*3.0 / 8.0;				// finish angle in radians
	auto radius = jmin(bounds.getWidth(), bounds.getHeight()) / 2.0f;		// radius of circle based on bounds
	auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle); // total angle traversed by slider

	auto lineW = jmin(8.0f, radius * 0.5f);
	auto arcRadius = radius - lineW * 0.5f;

	bounds = bounds.constrainedWithin(Rectangle<int>(x, y, jmin(width,height), jmin(width, height)).toFloat());
	auto bottom_edge = bounds.getHeight();
	auto bottom_length = height-bottom_edge;
	auto bottom_halved = bottom_length / 2;
	bounds.setPosition(x, y + bottom_halved);

	/*
	g.drawEllipse(bounds, 0);
	g.setColour(grey);
	g.fillEllipse(bounds);
	*/

	auto scaling_val = bounds.getHeight(); // 520
	auto key_arc = bounds.reduced(scaling_val * (100.0 / scaling_val));

	Point<float> p1(bounds.getCentre());
	Point<float> p2(key_arc.getTopLeft());
	ColourGradient black_fade(Colours::black, p1,grey, p2, true); // move this

	g.setGradientFill(black_fade);
	g.fillEllipse(bounds);

	g.setColour(light_grey);

	Point<float> circle_edge(bounds.reduced(85).getTopLeft().getX(), bounds.getCentreY()); // scale around to make full circle
	circle_edge.applyTransform(AffineTransform::rotation(-2 * MathConstants<float>::pi * 40 / 360, bounds.getCentreX(), bounds.getCentreY()));
	Line<float> horizontal_line(bounds.getCentre(), circle_edge);
	g.drawLine(horizontal_line, scaling_val * (3.5 / scaling_val));
	/*
	circle_edge.applyTransform(AffineTransform::rotation(2*MathConstants<float>::pi*180/360, bounds.getCentreX(), bounds.getCentreY()));
	horizontal_line.setEnd(circle_edge);
	g.drawLine(horizontal_line, scaling_val * (3.5 / 520.0));
	*/
	
	for (int degree = 0; degree < 26; degree++)
	{
		circle_edge.applyTransform(AffineTransform::rotation(2 * MathConstants<float>::pi * 10 / 360, bounds.getCentreX(), bounds.getCentreY()));
		horizontal_line.setEnd(circle_edge);
		g.drawLine(horizontal_line, scaling_val * (3.5 / scaling_val));
	}
	
	g.setColour(grey);
	g.fillEllipse(key_arc);
	

	arcRadius = key_arc.getWidth() / 2.0;
	
	/*
	Path backgroundArc;
	backgroundArc.addCentredArc(bounds.getCentreX(),
		bounds.getCentreY(),
		arcRadius,
		arcRadius,
		0.0f,
		rotaryStartAngle,
		rotaryEndAngle,
		true);

	g.setColour(light_grey);
	g.strokePath(backgroundArc, PathStrokeType(lineW, PathStrokeType::curved, PathStrokeType::rounded));
	*/
	/*
	if (slider.isEnabled())
	{
		Path valueArc;
		valueArc.addCentredArc(key_arc.getCentreX(),
			key_arc.getCentreY(),
			arcRadius,
			arcRadius,
			0.0f,
			rotaryStartAngle,
			toAngle,
			true);

		g.setColour(grey);
		g.strokePath(valueArc, PathStrokeType(lineW, PathStrokeType::curved, PathStrokeType::rounded));
	}
	*/

	auto thumbWidth = lineW * 2.0f;


	Point<float> LineEndPoint(bounds.getCentreX() + arcRadius * std::cos(toAngle - MathConstants<float>::halfPi), bounds.getCentreY() + arcRadius * std::sin(toAngle - MathConstants<float>::halfPi));

	g.setColour(light_grey);

	Line<float> marker_line(bounds.getCentre(), circle_edge);
	g.drawLine(horizontal_line, scaling_val * (3.5 / scaling_val));
	g.fillEllipse(Rectangle<float>(thumbWidth, thumbWidth).withCentre(thumbPoint));
	

}

void DB_LookFeel::drawLabel(Graphics& g, Label& l)
{
}
