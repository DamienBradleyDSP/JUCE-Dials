/*
  ==============================================================================

    DB_LookFeel.h
    Created: 19 Dec 2019 3:26:59pm
    Author:  damob

  ==============================================================================
*/

#pragma once
//#include "db_BinaryData.cpp"

//==============================================================================
/*
*/

namespace DB
{

class DB_LookFeel : public juce::LookAndFeel_V4
{
public:

	DB_LookFeel() {
		//setDefaultSansSerifTypeface(tface);

		setColour(0, light_grey);
		setColour(1, grey);
		setColour(2, dark_grey);
	};

	~DB_LookFeel() {};

	void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height,
		float sliderPos, float rotaryStartAngle,
		float rotaryEndAngle, juce::Slider& slider) override {

		// Setting Bounds and Angles

		auto bounds = juce::Rectangle<int>(x, y, width, height).toFloat().reduced(0); // add .reduced for smaller bounds
		rotaryStartAngle = -juce::MathConstants<float>::pi * 2.0 * 3.0 / 8.0;				// starting angle in radians
		rotaryEndAngle = juce::MathConstants<float>::pi * 2.0 * 3.0 / 8.0;				// finish angle in radians
		auto radius = juce::jmin(bounds.getWidth(), bounds.getHeight()) / 2.0f;		// radius of circle based on bounds
		auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle); // total angle traversed by slider


		// Setting the inner square where the knob will sit

		bounds = bounds.constrainedWithin(juce::Rectangle<int>(x, y, juce::jmin(width, height), juce::jmin(width, height)).toFloat());
		auto bottom_edge = y + bounds.getHeight();
		auto bottom_length = height - bottom_edge;
		auto bottom_halved = bottom_length / 2;
		bounds.setPosition(0, 0);

		// Setting Scaling Values

		auto scaling_val = bounds.getHeight(); // 420 @ 600,600
		auto key_arc = bounds.reduced(scaling_val / 7.0);
		auto minute_arc = bounds.reduced(scaling_val / 8.4);
		auto minute_marker_thickness = scaling_val / 120.0;


		// Creating Gradient

		juce::Point<float> p1(bounds.getCentre());
		juce::Point<float> p2(key_arc.reduced(scaling_val / 19.0).getTopLeft());
		juce::ColourGradient black_fade(juce::Colours::black, p1, grey, p2, true); // move this

		g.setGradientFill(black_fade);
		g.fillEllipse(bounds);

		// Creating minute markers

		g.setColour(light_grey);

		juce::Point<float> circle_edge(minute_arc.getTopLeft().getX(), bounds.getCentreY()); // scale around to make full circle
		circle_edge.applyTransform(juce::AffineTransform::rotation(-2 * juce::MathConstants<float>::pi * 40 / 360, bounds.getCentreX(), bounds.getCentreY()));
		juce::Line<float> horizontal_line(bounds.getCentre(), circle_edge);
		g.drawLine(horizontal_line, minute_marker_thickness);

		for (int degree = 0; degree < 26; degree++)
		{
			circle_edge.applyTransform(juce::AffineTransform::rotation(2 * juce::MathConstants<float>::pi * 10 / 360, bounds.getCentreX(), bounds.getCentreY()));
			horizontal_line.setEnd(circle_edge);
			g.drawLine(horizontal_line, minute_marker_thickness);
		}


		// Creating knob face

		g.setColour(grey);
		g.fillEllipse(key_arc);


		// Creating Knob Indicator

		auto arcRadius = key_arc.getWidth() / 2.0;

		juce::Point<float> LineEndPoint(bounds.getCentreX() + arcRadius * std::cos(toAngle - juce::MathConstants<float>::halfPi), bounds.getCentreY() + arcRadius * std::sin(toAngle - juce::MathConstants<float>::halfPi));
		auto LineStartX = (bounds.getCentre().getX() + LineEndPoint.getX()) / 2;
		auto LineStartY = (bounds.getCentre().getY() + LineEndPoint.getY()) / 2;
		juce::Point<float> LinesStartPoint(LineStartX, LineStartY);

		juce::Line<float> marker_line(LinesStartPoint, LineEndPoint);

		g.setColour(light_grey);
		g.drawLine(marker_line, minute_marker_thickness * 2);


	};

	void drawLabel(juce::Graphics& g, juce::Label& label) override {
		//g.fillAll(label.findColour(Label::backgroundColourId));
		/*
		if (!label.isBeingEdited())
		{

			g.setColour(light_grey);

			auto area = label.getLocalBounds();

			g.setFont(label.getHeight() / 2.0);
			g.drawFittedText(label.getText(), area, label.getJustificationType(), 1, 0);

		}
		else if (label.isEnabled())
		{
			g.setColour(label.findColour(juce::Label::outlineColourId));
		}
		*/
		//g.drawRect(label.getLocalBounds());




	};

	juce::Slider::SliderLayout getSliderLayout(juce::Slider& slider) override {

		// Override isnt working, look for V2

		juce::Slider::SliderLayout layout;

		layout.textBoxBounds = slider.getBounds().reduced(100000000);
		layout.sliderBounds = slider.getBounds();

		return layout;
	};

	void drawToggleButton(juce::Graphics& g, juce::ToggleButton& button,
		bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override {

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

	};

	void drawComboBox(juce::Graphics& g, int width, int height, bool isButtonDown,
		int buttonX, int buttonY, int buttonW, int buttonH,
		juce::ComboBox& box) override {


		auto cornerSize = box.findParentComponentOfClass<juce::ChoicePropertyComponent>() != nullptr ? 0.0f : 3.0f;
		auto bounds = box.getLocalBounds().toFloat();
		auto scale_value = bounds.getHeight();

		g.setColour(dark_grey);
		g.fillRoundedRectangle(bounds, scale_value / 5.5);

		g.setColour(grey);
		g.fillRoundedRectangle(bounds.reduced(scale_value / 15.0), scale_value / 5.5);

		juce::Rectangle<int> arrowZone(width - scale_value / 5.0, 0, 20, height);
		juce::Path path;
		path.startNewSubPath(arrowZone.getX() + 3.0f, arrowZone.getCentreY() - 2.0f);
		path.lineTo(static_cast<float> (arrowZone.getCentreX()), arrowZone.getCentreY() + 3.0f);
		path.lineTo(arrowZone.getRight() - 3.0f, arrowZone.getCentreY() - 2.0f);

		g.setColour(box.findColour(juce::ComboBox::arrowColourId).withAlpha((box.isEnabled() ? 0.9f : 0.2f)));
		g.strokePath(path, juce::PathStrokeType(2.0f));
	};




private:

	juce::Colour grey = juce::Colour::fromRGB(40, 40, 40);				//(34, 34, 34);
	juce::Colour light_grey = juce::Colour::fromRGB(100, 100, 100);			//(136, 136, 136);
	juce::Colour dark_grey = juce::Colour::fromRGB(25, 25, 25);			//(25, 25, 25);

	//juce::Typeface::Ptr tface = juce::Typeface::createSystemTypefaceFor(db_BinaryData::DB_font, db_BinaryData::DB_fontSize);



	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DB_LookFeel)
};

}