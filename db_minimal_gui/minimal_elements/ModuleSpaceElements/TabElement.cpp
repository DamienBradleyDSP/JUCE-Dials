#ifdef DB_MODULE_TESTING
#include "JuceHeader.h"
#endif 

#include "TabElement.h"

DB::minimalGUI::_moduleInternalElements::TabElement::TabElement(juce::String tabText)
{
	tabName = tabText;
}

void DB::minimalGUI::_moduleInternalElements::TabElement::paint(juce::Graphics& g)
{
	if (isMouseButtonDown()) paintMouseDown(g);
	else if (isMouseOver()) paintMouseOver(g);
	else paintNormal(g);
}

void DB::minimalGUI::_moduleInternalElements::TabElement::resized()
{
}

void DB::minimalGUI::_moduleInternalElements::TabElement::setButtonSizes(const int corner, const int strip, const int font)
{
	cornerSize = corner;
	stripSize = strip;
	fontSize = font;
}

void DB::minimalGUI::_moduleInternalElements::TabElement::mouseEnter(const MouseEvent& event)
{
	repaint();
}

void DB::minimalGUI::_moduleInternalElements::TabElement::mouseExit(const MouseEvent& event)
{
	repaint();
}

void DB::minimalGUI::_moduleInternalElements::TabElement::mouseDown(const MouseEvent& event)
{
	//repaint();
}


void DB::minimalGUI::_moduleInternalElements::TabElement::enabledFlip()
{
	isEnabled = isEnabled ^ true;
}

void DB::minimalGUI::_moduleInternalElements::TabElement::setDisabled()
{
	isEnabled = false;
}

bool DB::minimalGUI::_moduleInternalElements::TabElement::getButtonState()
{
	return isEnabled;
}

void DB::minimalGUI::_moduleInternalElements::TabElement::paintMouseOver(juce::Graphics& g)
{
	auto light_grey = findColour(0, true);
	auto grey = findColour(1, true);
	auto dark_grey = findColour(2, true);
	auto textColour = light_grey;

	// Fill rounded tab part
	g.setColour(dark_grey);
	auto tabBounds = getLocalBounds();
	g.fillRoundedRectangle(tabBounds.toFloat(), cornerSize);

	// Fill rectangle for bottom half of tab
	auto fillBottom = tabBounds;
	fillBottom.removeFromTop(fillBottom.getHeight() / 2);
	g.fillRect(fillBottom);

	// Draw a strip of grey

	auto colourStrip = tabBounds;
	colourStrip = colourStrip.removeFromBottom(stripSize);
	g.setColour(grey);
	if (!isEnabled) g.fillRect(colourStrip);

	// Draw dark text
	auto textBounds = tabBounds;
	textBounds.removeFromBottom(stripSize);
	g.setColour(grey);
	g.setFont(fontSize);
	g.drawText(tabName, textBounds, juce::Justification::centred, true);
}

void DB::minimalGUI::_moduleInternalElements::TabElement::paintNormal(juce::Graphics& g)
{
	auto light_grey = findColour(0, true);
	auto grey = findColour(1, true);
	auto dark_grey = findColour(2, true);
	auto textColour = light_grey;

	// Fill rounded tab part
	g.setColour(dark_grey);
	auto tabBounds = getLocalBounds();
	g.fillRoundedRectangle(tabBounds.toFloat(), cornerSize);

	// Fill rectangle for bottom half of tab
	auto fillBottom = tabBounds;
	fillBottom.removeFromTop(fillBottom.getHeight() / 2);
	g.fillRect(fillBottom);

	// Draw a strip of grey
	auto colourStrip = tabBounds;
	colourStrip = colourStrip.removeFromBottom(stripSize);
	g.setColour(grey);
	if (!isEnabled) g.fillRect(colourStrip);

	// Draw normal text
	auto textBounds = tabBounds;
	textBounds.removeFromBottom(stripSize);
	g.setColour(textColour);
	g.setFont(fontSize);
	g.drawText(tabName, textBounds, juce::Justification::centred, true);
}

void DB::minimalGUI::_moduleInternalElements::TabElement::paintMouseDown(juce::Graphics& g)
{
	auto light_grey = findColour(0, true);
	auto grey = findColour(1, true);
	auto dark_grey = findColour(2, true);
	auto textColour = light_grey;

	// Fill rounded tab part
	g.setColour(dark_grey);
	auto tabBounds = getLocalBounds();
	g.fillRoundedRectangle(tabBounds.toFloat(), cornerSize);

	// Fill rectangle for bottom half of tab
	auto fillBottom = tabBounds;
	fillBottom.removeFromTop(fillBottom.getHeight() / 2);
	g.fillRect(fillBottom);
}
