#include "ColourPalette.h"

int ColourPalette::noColours = 100;
Colour* ColourPalette::colours = nullptr;

ColourPalette::ColourPalette()
{
}


ColourPalette::~ColourPalette()
{
}

void ColourPalette::buildPalette(int cols)
{
	delete colours;
	noColours = cols;
	colours = new Colour[noColours];
	colours[0] = Colour(0, 0, 0);
	for (int c = 1; c < noColours; c++)
	{
		Colour newcol;
		newcol.setHSV(255*((float)c/noColours), 200, 200);
		colours[c] = newcol;
	}
}

Colour ColourPalette::getColour(float pos)
{
	//return Colour(pos * 255, pos * 255, pos * 255);
	return colours[(int)(pos*(noColours-1))];
}