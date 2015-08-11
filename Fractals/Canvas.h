#pragma once
#include "Colour.h"

class Canvas
{
	sf::Image image;
	sf::Uint8* data = nullptr;
	int width, height;
public:
	Canvas(int width, int height);
	~Canvas();

	void setPoint(int x, int y, Colour col);

	sf::Image* getImage();
};

