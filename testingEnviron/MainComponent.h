/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/
/*
BEGIN_JUCE_MODULE_DECLARATION



ID:   db_minimal_gui

vendor : dbdsp

version : 1.0

name : Minimal GUI set

description : Premade GUI components and buttons

END_JUCE_MODULE_DECLARATION
*/

#pragma once



#include "../JuceLibraryCode/JuceHeader.h"
#include "../db_minimal_gui/minimal_elements/LookFeel.h"
#include "../db_minimal_gui/minimal_elements/ModuleSpace.h"
#include "../db_minimal_gui/minimal_elements/HeaderBar.h"
#include "../db_minimal_gui/minimal_elements/SidewaysModuleSpace.h"

#include "testComponent.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

class MainComponent   : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...

	DB::minimalGUI::LookFeel mylookfeel;

	juce::Slider myslider;

	juce::ToggleButton mybutton;

	juce::ComboBox mycombobox;

	DB::minimalGUI::HeaderBar headerbar;

	DB::minimalGUI::ModuleSpace modulespace;
	DB::minimalGUI::SidewaysModuleSpace modulespace2;
	
	juce::Rectangle<int> bounds;





    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
