#pragma once
#include "Colour.h"

class ColourPalette
{
public:
	ColourPalette();
	~ColourPalette();

	static Colour getColour(float pos);
};

