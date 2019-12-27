
#pragma once

namespace DB
{

//==============================================================================
/*
*/

class ModuleSpace : public juce::Component
{
public:
	ModuleSpace() {};
	ModuleSpace(juce::String text)
	{
		module_text = text;
	};
	ModuleSpace::ModuleSpace(juce::String text, bool inverted, bool sideways)
	{
		module_text = text;
		inverted_flag = inverted;
		sideways_flag = sideways;
	};
	~ModuleSpace() {};

	void ModuleSpace::paint(juce::Graphics& g) override
	{
		if (!inverted_flag && !sideways_flag)
		{
			juce::Colour light_grey = findColour(0, true);
			juce::Colour grey = findColour(1, true);
			juce::Colour dark_grey = findColour(2, true);

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
			g.drawText(module_text, text_bounds.removeFromBottom(bottom_height * 2.0), juce::Justification::centred, true);
		}

		if (inverted_flag)
		{
			juce::Colour light_grey = findColour(0, true);
			juce::Colour grey = findColour(1, true);
			juce::Colour dark_grey = findColour(2, true);

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
			g.drawText(module_text, text_bounds.removeFromTop(top_height * 1.6), juce::Justification::centred, true);
		}
		if (sideways_flag)
		{


			juce::Colour light_grey = findColour(0, true);
			juce::Colour grey = findColour(1, true);
			juce::Colour dark_grey = findColour(2, true);

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
	void ModuleSpace::resized() override {};

	void set_text(juce::String text)
	{
		module_text = text;
	};
	void ModuleSpace::rotate(bool inverted, bool sideways)
	{
		inverted_flag = inverted;
		sideways_flag = sideways;
	};


private:

	juce::String module_text = " ";

	bool inverted_flag = false, sideways_flag = false;


	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ModuleSpace)
};

}