#include "testComponent.h"

testComponent::testComponent()
{
	addAndMakeVisible(newtoggle);

}

void testComponent::paint(juce::Graphics& g)
{
}

void testComponent::resized()
{
	newtoggle.setBounds(getLocalBounds().reduced(40));
}
