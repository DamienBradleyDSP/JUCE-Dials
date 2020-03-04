#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class testComponent : public juce::Component
{
public:
	testComponent();

	void paint(juce::Graphics&) override;
	void resized() override;

	/*
	void mouseMove(const MouseEvent& event) override;
	void mouseEnter(const MouseEvent& event) override;
	void mouseExit(const MouseEvent& event) override;
	void mouseDown(const MouseEvent& event) override;
	void mouseDrag(const MouseEvent& event) override;
	void mouseUp(const MouseEvent& event) override;
	void mouseDoubleClick(const MouseEvent& event) override;
	void mouseWheelMove(const MouseEvent& event, const MouseWheelDetails& wheel) override;
	void mouseMagnify(const MouseEvent& event, float scaleFactor) override;
	*/

private:
	juce::ToggleButton newtoggle;
};

