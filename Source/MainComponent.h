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
#include "DB_LookFeel.cpp"
#include "HeaderBar.cpp"
#include "ModuleSpace.cpp"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

class MainComponent   : public Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...

	DB_LookFeel mylookfeel;

	Slider myslider;

	ToggleButton mybutton;

	ComboBox mycombobox;

	HeaderBar headerbar;

	ModuleSpace modulespace;
	
	Rectangle<int> bounds;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
