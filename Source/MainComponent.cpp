/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (800, 800);

	setLookAndFeel(&mylookfeel);

	myslider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	addAndMakeVisible(myslider);

	

}

MainComponent::~MainComponent()
{
	setLookAndFeel(nullptr);
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    
	g.fillAll(Colour::fromRGB(34,34,34));
	
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.

	myslider.setBounds(getBounds().reduced(50));


}
