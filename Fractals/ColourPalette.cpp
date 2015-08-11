#include "ColourPalette.h"


ColourPalette::ColourPalette()
{
}


ColourPalette::~ColourPalette()
{
}

Colour ColourPalette::getColour(float pos)
{
	return Colour(pos * 255, pos * 255, pos * 255);
}