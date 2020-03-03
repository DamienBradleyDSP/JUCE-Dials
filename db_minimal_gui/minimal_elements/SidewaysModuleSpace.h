/*
  ==============================================================================

    SidewaysModuleSpace.h
    Created: 2 Mar 2020 5:59:42pm
    Author:  damob

  ==============================================================================
*/

#pragma once


//==============================================================================
/*
*/

namespace DB
{
namespace minimalGUI
{

class SidewaysModuleSpace : public juce::Component
{
public:
	SidewaysModuleSpace();
	SidewaysModuleSpace(juce::String text);

	~SidewaysModuleSpace();

	void paint(juce::Graphics&) override;
	void resized() override;

	void setText(juce::String text);
	void setTabWidth(float newWidth);

	juce::Rectangle<float> getInternalBounds();


private:

	juce::String moduleText = " ";
	float tabWidth = 20;
	juce::Rectangle<float> innerBounds;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SidewaysModuleSpace)
};

}
}