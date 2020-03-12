/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() : bounds(30, 30, 100, 50)
{
	
    setSize (800, 800);

	setLookAndFeel(&mylookfeel);


	myslider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	myslider.setTextBoxStyle(juce::Slider::TextBoxRight, true, 10, 10);
	addAndMakeVisible(myslider);

	addAndMakeVisible(modulespace);
	modulespace.setText("SYNTHESISER");

	Component* theTabSpaceComponent = new testComponent;
	modulespace.addTab("BAR VARIATION", theTabSpaceComponent);

	Component* otherComp = new testComponent;
	modulespace.addTab("BEAT VARIATION", otherComp);
	//Component* anotherComponent = new Component;
	//modulespace.addTab("HUMANISE", anotherComponent);

	Component* testing = new testComponent;
	modulespace.addMainSpace(testing);

	//addAndMakeVisible(modulespace2);
	modulespace2.setText("Blah blah");
	modulespace2.setTabWidth(160);

}

MainComponent::~MainComponent()
{
	setLookAndFeel(nullptr);
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    
	g.fillAll(mylookfeel.findColour(1));

	//g.fillRect(bounds);
	
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.

	headerbar.setBounds(getLocalBounds());

	modulespace.setBounds(getLocalBounds());
	modulespace2.setBounds(getLocalBounds());



}
