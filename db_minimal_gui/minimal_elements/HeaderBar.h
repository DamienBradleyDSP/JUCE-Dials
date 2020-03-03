#pragma once
namespace DB
{

class HeaderBar : public juce::Component
{
public:
	HeaderBar();
	HeaderBar(juce::String my_text);

	void paint(juce::Graphics& g) override;
	void resized() override;

	void setText(juce::String header_text);
	int getHeaderHeight();

private:

	juce::String header = " ";
	const int headerHeight = 90;


	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(HeaderBar)
};

}

