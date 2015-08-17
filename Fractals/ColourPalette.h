#pragma once
#include "Colour.h"

class ColourPalette
{
public:
	ColourPalette();
	~ColourPalette();

	static int noColours;
	static Colour* colours;
	static void buildPalette(int cols);
	static Colour getColour(float pos);
};

