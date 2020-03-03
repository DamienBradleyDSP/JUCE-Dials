#pragma once


namespace DB
{
namespace minimalGUI
{

class ModuleSpace : public juce::Component
{
public:
	ModuleSpace();
	ModuleSpace(juce::String text);
	ModuleSpace(juce::String text, bool inverted);

	void paint(juce::Graphics& g) override;
	void resized() override;

	void setText(juce::String text);
	void setRotation(bool inverted);
	juce::Rectangle<float> getInternalBounds();


private:

	juce::String module_text = " ";

	bool inverted_flag = false;
	juce::Rectangle<float> innerBounds;


	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ModuleSpace)
};

}
}

