/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent() : bounds(0, 0, 800, 800)
{
    setSize (800, 800);

	setLookAndFeel(&mylookfeel);


	auto button_width = 800;
	auto button_height = 800;

	myslider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
	myslider.setTextBoxStyle(Slider::TextBoxRight, true, 10, 10);


	//addAndMakeVisible(myslider);

	//addAndMakeVisible(mybutton);

	//addAndMakeVisible(mycombobox);

	addAndMakeVisible(headerbar);
	headerbar.set_text("HEADER BAR");

	//addAndMakeVisible(modulespace);
	

}

MainComponent::~MainComponent()
{
	setLookAndFeel(nullptr);
}

//==============================================================================
void MainComponent::paint (Graphics& g)
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

	myslider.setBounds(bounds);
	mybutton.setBounds(bounds.reduced(30));
	mycombobox.setBounds(bounds);
	headerbar.setBounds(bounds);
	modulespace.setBounds(bounds);
	//myslider.setBounds(getLocalBounds());


}
