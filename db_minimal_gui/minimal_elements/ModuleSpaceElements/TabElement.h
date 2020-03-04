#pragma once

namespace DB
{
namespace minimalGUI
{
namespace _moduleInternalElements
{

class TabElement : public juce::Component
{
public:
	TabElement() = default;
	TabElement(juce::String tabText);

	void paint(juce::Graphics& g) override;
	void resized() override;

	void setButtonSizes(const int corner, const int strip, const int font);

	void mouseEnter(const MouseEvent& event) override;
	void mouseExit(const MouseEvent& event) override;
	void mouseDown(const MouseEvent& event) override;
	void mouseUp(const MouseEvent& event) override;
	
private:

	void paintMouseOver(juce::Graphics& g);
	void paintNormal(juce::Graphics& g);
	void paintMouseDown(juce::Graphics& g);

	juce::String tabName = "";
	int cornerSize;
	int stripSize;
	int fontSize;

	bool mouseIsDown = false;
};


}
}
}

