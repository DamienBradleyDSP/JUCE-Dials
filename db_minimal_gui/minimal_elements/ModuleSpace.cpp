#ifdef DB_MODULE_TESTING
#include "JuceHeader.h"
#endif 

#include "ModuleSpace.h"

DB::ModuleSpace::ModuleSpace() {};

DB::ModuleSpace::ModuleSpace(juce::String text)
{
	module_text = text;
}

DB::ModuleSpace::ModuleSpace(juce::String text, bool inverted)
{
	module_text = text;
	inverted_flag = inverted;
}

void DB::ModuleSpace::paint(juce::Graphics& g)
{
	if (!inverted_flag)
	{
		juce::Colour light_grey = findColour(0, true);
		juce::Colour grey = findColour(1, true);
		juce::Colour dark_grey = findColour(2, true);

		auto bounds = getLocalBounds().toFloat();
		auto text_bounds = bounds;
		auto corner_size = 25.0f;

		g.setColour(dark_grey);
		g.fillRoundedRectangle(bounds, corner_size);


		auto bottom_height = 25.0f;
		auto edited_bounds = bounds.reduced(5).removeFromTop(bounds.getHeight() - bottom_height);

		g.setColour(grey);
		g.fillRoundedRectangle(edited_bounds, corner_size);



		g.setColour(dark_grey);
		g.fillRect(edited_bounds.removeFromBottom(bottom_height));

		innerBounds = edited_bounds;

		g.setColour(grey);
		//g.fillRect(text_bounds.removeFromBottom(bottom_height));
		g.setFont(30);
		g.drawText(module_text, text_bounds.removeFromBottom(bottom_height * 2.0f), juce::Justification::centred, true);


	}

	if (inverted_flag)
	{
		juce::Colour light_grey = findColour(0, true);
		juce::Colour grey = findColour(1, true);
		juce::Colour dark_grey = findColour(2, true);

		auto bounds = getLocalBounds().toFloat();
		auto text_bounds = bounds;
		auto corner_size = 25.0f;

		g.setColour(dark_grey);
		g.fillRoundedRectangle(bounds, corner_size);


		auto top_height = 15.0f;
		auto edited_bounds = bounds.reduced(5).removeFromBottom(bounds.getHeight() - top_height);

		g.setColour(grey);
		g.fillRoundedRectangle(edited_bounds, corner_size);

		g.setColour(dark_grey);
		g.fillRect(edited_bounds.removeFromTop(top_height));

		innerBounds = edited_bounds;

		g.setColour(grey);
		//g.fillRect(text_bounds.removeFromBottom(bottom_height));
		g.setFont(20.0f);
		g.drawText(module_text, text_bounds.removeFromTop(top_height * 1.6f), juce::Justification::centred, true);
	}
}

void DB::ModuleSpace::resized()
{
}

void DB::ModuleSpace::setText(juce::String text)
{
	module_text = text;
}

void DB::ModuleSpace::setRotation(bool inverted)
{
	inverted_flag = inverted;
}

juce::Rectangle<float> DB::ModuleSpace::getInternalBounds()
{
	return innerBounds;
}
