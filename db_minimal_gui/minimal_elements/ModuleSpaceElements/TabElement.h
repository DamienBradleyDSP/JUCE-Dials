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

	void setButtonSizes(const float corner, const float strip, const float font);

	void mouseEnter(const juce::MouseEvent& event) override;
	void mouseExit(const juce::MouseEvent& event) override;
	void mouseDown(const juce::MouseEvent& event) override;

	void enabledFlip();
	void setDisabled();
	bool getButtonState();
	
private:

	void paintMouseOver(juce::Graphics& g);
	void paintNormal(juce::Graphics& g);
	void paintMouseDown(juce::Graphics& g);

	juce::String tabName = "";
	float cornerSize;
	float stripSize;
	float fontSize;

	bool mouseIsDown = false;
	bool isEnabled = false;
};


}
}
}

