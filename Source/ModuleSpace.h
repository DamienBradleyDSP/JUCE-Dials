/*
  ==============================================================================

    ModuleSpace.h
    Created: 21 Dec 2019 6:03:44pm
    Author:  damob

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "DB_LookFeel.cpp"

//==============================================================================
/*
*/

class ModuleSpace    : public Component
{
public:
	ModuleSpace() {};
    ModuleSpace(String text)
	{
		module_text = text;
	};
    ModuleSpace(String text, bool inverted, bool sideways)
	{
		module_text = text;
		inverted_flag = inverted;
		sideways_flag = sideways;
	};
	~ModuleSpace() {};

    void paint(Graphics& g) override
	{
		if (!inverted_flag && !sideways_flag)
		{
			Colour light_grey = findColour(0, true);
			Colour grey = findColour(1, true);
			Colour dark_grey = findColour(2, true);

			auto bounds = getLocalBounds().toFloat();
			auto text_bounds = bounds;
			auto scaling_val = bounds.getHeight();
			auto corner_size = 25;

			g.setColour(dark_grey);
			g.fillRoundedRectangle(bounds, corner_size);


			auto bottom_height = 25;
			auto edited_bounds = bounds.reduced(5).removeFromTop(bounds.getHeight() - bottom_height);

			g.setColour(grey);
			g.fillRoundedRectangle(edited_bounds, corner_size);

			g.setColour(dark_grey);
			g.fillRect(edited_bounds.removeFromBottom(bottom_height));

			g.setColour(grey);
			//g.fillRect(text_bounds.removeFromBottom(bottom_height));
			g.setFont(30);
			g.drawText(module_text, text_bounds.removeFromBottom(bottom_height * 2.0), Justification::centred, true);
		}

		if (inverted_flag)
		{
			Colour light_grey = findColour(0, true);
			Colour grey = findColour(1, true);
			Colour dark_grey = findColour(2, true);

			auto bounds = getLocalBounds().toFloat();
			auto text_bounds = bounds;
			auto scaling_val = bounds.getHeight();
			auto corner_size = 25;

			g.setColour(dark_grey);
			g.fillRoundedRectangle(bounds, corner_size);


			auto top_height = 15;
			auto edited_bounds = bounds.reduced(5).removeFromBottom(bounds.getHeight() - top_height);

			g.setColour(grey);
			g.fillRoundedRectangle(edited_bounds, corner_size);

			g.setColour(dark_grey);
			g.fillRect(edited_bounds.removeFromTop(top_height));

			g.setColour(grey);
			//g.fillRect(text_bounds.removeFromBottom(bottom_height));
			g.setFont(20);
			g.drawText(module_text, text_bounds.removeFromTop(top_height * 1.6), Justification::centred, true);
		}
		if (sideways_flag)
		{


			Colour light_grey = findColour(0, true);
			Colour grey = findColour(1, true);
			Colour dark_grey = findColour(2, true);

			auto bounds = getLocalBounds().toFloat();
			auto text_bounds = bounds;
			auto scaling_val = bounds.getHeight();
			auto corner_size = 25;

			g.setColour(dark_grey);
			g.fillRoundedRectangle(bounds, corner_size);


			auto side_width = 25;
			auto edited_bounds = bounds.reduced(5).removeFromRight(bounds.getWidth() - side_width);

			g.setColour(grey);
			g.fillRoundedRectangle(edited_bounds, corner_size);

			g.setColour(dark_grey);
			g.fillRect(edited_bounds.removeFromLeft(side_width));

			g.setColour(light_grey);
			g.setFont(30);
			//g.drawText(module_text, text_bounds.removeFromTop(side_width), Justification::centred, true);

		}

	};
	void resized() override {};

	void set_text(String text)
	{
		module_text = text;
	};
	void set_rotation(bool inverted, bool sideways)
	{
		inverted_flag = inverted;
		sideways_flag = sideways;
	};


private:

	String module_text = " ";

	bool inverted_flag = false, sideways_flag = false;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModuleSpace)
};
