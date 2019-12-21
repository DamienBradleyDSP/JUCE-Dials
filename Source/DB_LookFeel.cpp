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
	setDefaultSansSerifTypeface(tface);
}

DB_LookFeel::~DB_LookFeel()
{
}




void DB_LookFeel::drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
{

	// Setting Bounds and Angles

	auto bounds = Rectangle<int>(x, y, width, height).toFloat().reduced(0); // add .reduced for smaller bounds
	rotaryStartAngle = -MathConstants<float>::pi*2.0*3.0/8.0;				// starting angle in radians
	rotaryEndAngle = MathConstants<float>::pi * 2.0*3.0 / 8.0;				// finish angle in radians
	auto radius = jmin(bounds.getWidth(), bounds.getHeight()) / 2.0f;		// radius of circle based on bounds
	auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle); // total angle traversed by slider


	// Setting the inner square where the knob will sit

	bounds = bounds.constrainedWithin(Rectangle<int>(x, y, jmin(width,height), jmin(width, height)).toFloat());
	auto bottom_edge = y+bounds.getHeight();
	auto bottom_length = height-bottom_edge;
	auto bottom_halved = bottom_length / 2;
	bounds.setPosition(0, 0);

	// Setting Scaling Values

	auto scaling_val = bounds.getHeight(); // 420 @ 600,600
	auto key_arc = bounds.reduced(scaling_val/7.0);
	auto minute_arc = bounds.reduced(scaling_val/8.4);
	auto minute_marker_thickness = scaling_val/120.0;


	// Creating Gradient

	Point<float> p1(bounds.getCentre());
	Point<float> p2(key_arc.reduced(scaling_val / 19.0).getTopLeft());
	ColourGradient black_fade(Colours::black, p1,grey, p2, true); // move this

	g.setGradientFill(black_fade);
	g.fillEllipse(bounds);

	// Creating minute markers

	g.setColour(light_grey);

	Point<float> circle_edge(minute_arc.getTopLeft().getX(), bounds.getCentreY()); // scale around to make full circle
	circle_edge.applyTransform(AffineTransform::rotation(-2 * MathConstants<float>::pi * 40 / 360, bounds.getCentreX(), bounds.getCentreY()));
	Line<float> horizontal_line(bounds.getCentre(), circle_edge);
	g.drawLine(horizontal_line, minute_marker_thickness);
	
	for (int degree = 0; degree < 26; degree++)
	{
		circle_edge.applyTransform(AffineTransform::rotation(2 * MathConstants<float>::pi * 10 / 360, bounds.getCentreX(), bounds.getCentreY()));
		horizontal_line.setEnd(circle_edge);
		g.drawLine(horizontal_line,minute_marker_thickness);
	}
	

	// Creating knob face

	g.setColour(grey);
	g.fillEllipse(key_arc);
	

	// Creating Knob Indicator

	auto arcRadius = key_arc.getWidth() / 2.0;

	Point<float> LineEndPoint(bounds.getCentreX() + arcRadius * std::cos(toAngle - MathConstants<float>::halfPi), bounds.getCentreY() + arcRadius * std::sin(toAngle - MathConstants<float>::halfPi));
	auto LineStartX = (bounds.getCentre().getX() + LineEndPoint.getX()) / 2;
	auto LineStartY = (bounds.getCentre().getY() + LineEndPoint.getY()) / 2;
	Point<float> LinesStartPoint(LineStartX, LineStartY);

	Line<float> marker_line(LinesStartPoint, LineEndPoint);

	g.setColour(light_grey);
	g.drawLine(marker_line, minute_marker_thickness*2);
	

}

void DB_LookFeel::drawLabel(Graphics& g, Label& label)
{
	//g.fillAll(label.findColour(Label::backgroundColourId));
	
	if (!label.isBeingEdited())
	{

		g.setColour(light_grey);

		auto area = label.getLocalBounds();

		g.setFont(label.getHeight()/2.0);
		g.drawFittedText(label.getText(), area, label.getJustificationType(),1,0);

	}
	else if (label.isEnabled())
	{
		g.setColour(label.findColour(Label::outlineColourId));
	}

	//g.drawRect(label.getLocalBounds());

	

	
}

Slider::SliderLayout DB_LookFeel::getSliderLayout(Slider& slider)
{

	// Override isnt working, look for V2

	Slider::SliderLayout layout;

	layout.textBoxBounds = slider.getBounds();
	layout.sliderBounds = slider.getBounds();

	return layout;
}

void DB_LookFeel::drawToggleButton(Graphics& g, ToggleButton& button,
	bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
{

	auto bounds = button.getLocalBounds().toFloat();
	auto scale_value = bounds.getHeight();

	g.setColour(dark_grey);
	g.fillRoundedRectangle(bounds, scale_value / 7.5);

	g.setColour(light_grey);
	g.fillRoundedRectangle(bounds.reduced(scale_value / 16.0), scale_value / 7.5);


	if (button.getToggleState())
	{
		g.setColour(grey);
		g.fillRoundedRectangle(bounds.reduced(scale_value / 11.0), scale_value / 7.5);

	}

	if (!button.getToggleState())
	{
		if (button.isMouseOver())
		{
			if (!button.isMouseButtonDown())
			{
				g.setColour(grey);
				g.fillRoundedRectangle(bounds.reduced(scale_value / 4.0), scale_value / 7.5);
			}
			if (button.isMouseButtonDown())
			{
				g.setColour(grey);
				g.fillRoundedRectangle(bounds.reduced(scale_value / 3.5), scale_value / 5.5);
			}
		}

		
	}

}

void DB_LookFeel::drawComboBox(Graphics& g, int width, int height, bool,
	int, int, int, int, ComboBox& box)
{
	auto cornerSize = box.findParentComponentOfClass<ChoicePropertyComponent>() != nullptr ? 0.0f : 3.0f;
	Rectangle<int> boxBounds(0, 0, width, height);

	g.setColour(box.findColour(ComboBox::backgroundColourId));
	g.fillRoundedRectangle(boxBounds.toFloat(), cornerSize);

	g.setColour(box.findColour(ComboBox::outlineColourId));
	g.drawRoundedRectangle(boxBounds.toFloat().reduced(0.5f, 0.5f), cornerSize, 1.0f);

	Rectangle<int> arrowZone(width - 30, 0, 20, height);
	Path path;
	path.startNewSubPath(arrowZone.getX() + 3.0f, arrowZone.getCentreY() - 2.0f);
	path.lineTo(static_cast<float> (arrowZone.getCentreX()), arrowZone.getCentreY() + 3.0f);
	path.lineTo(arrowZone.getRight() - 3.0f, arrowZone.getCentreY() - 2.0f);

	g.setColour(box.findColour(ComboBox::arrowColourId).withAlpha((box.isEnabled() ? 0.9f : 0.2f)));
	g.strokePath(path, PathStrokeType(2.0f));
}

