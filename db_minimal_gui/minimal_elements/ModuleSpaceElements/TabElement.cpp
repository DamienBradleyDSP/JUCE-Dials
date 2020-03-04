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
	repaint();
}

void DB::minimalGUI::_moduleInternalElements::TabElement::mouseUp(const MouseEvent& event)
{
	repaint();
}

void DB::minimalGUI::_moduleInternalElements::TabElement::paintMouseOver(juce::Graphics& g)
{
	auto light_grey = findColour(0, true);
	auto grey = findColour(1, true);
	auto dark_grey = findColour(2, true);
	auto textColour = light_grey;

	g.setColour(dark_grey);
	auto tabBounds = getLocalBounds();
	g.fillRoundedRectangle(tabBounds.toFloat(), cornerSize);

	auto fillBottom = tabBounds;
	fillBottom.removeFromTop(fillBottom.getHeight() / 2);
	g.fillRect(fillBottom);

	auto colourStrip = tabBounds;
	colourStrip = colourStrip.removeFromBottom(stripSize);
	g.setColour(grey);
	g.fillRect(colourStrip);

	g.setColour(dark_grey);
	auto thirdWidth = colourStrip.getWidth() / 3;
	colourStrip.removeFromLeft(thirdWidth);
	colourStrip.removeFromRight(thirdWidth);
	Path lines;
	Line<float> left, right;
	left.setStart(colourStrip.getBottomLeft().toFloat());
	right.setStart(colourStrip.getBottomRight().toFloat());
	colourStrip.removeFromLeft(5);
	colourStrip.removeFromRight(5);
	left.setEnd(colourStrip.getTopLeft().toFloat());
	right.setEnd(colourStrip.getTopRight().toFloat());
	lines.addLineSegment(left, 10);
	lines.addLineSegment(right, 10);
	g.fillPath(lines);

	g.fillRect(colourStrip);


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

	g.setColour(dark_grey);
	auto tabBounds = getLocalBounds();
	g.fillRoundedRectangle(tabBounds.toFloat(), cornerSize);

	auto fillBottom = tabBounds;
	fillBottom.removeFromTop(fillBottom.getHeight() / 2);
	g.fillRect(fillBottom);

	auto colourStrip = tabBounds;
	colourStrip = colourStrip.removeFromBottom(stripSize);
	g.setColour(grey);
	g.fillRect(colourStrip);

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

	g.setColour(dark_grey);
	auto tabBounds = getLocalBounds();
	g.fillRoundedRectangle(tabBounds.toFloat(), cornerSize);

	auto fillBottom = tabBounds;
	fillBottom.removeFromTop(fillBottom.getHeight() / 2);
	g.fillRect(fillBottom);

	auto colourStrip = tabBounds;
	colourStrip = colourStrip.removeFromBottom(stripSize);
	g.setColour(grey);
	//g.fillRect(colourStrip);

	auto textBounds = tabBounds;
	textBounds.removeFromBottom(stripSize);
	g.setColour(textColour);
	g.setFont(fontSize);

	//g.drawText(tabName, textBounds, juce::Justification::centred, true);
}
