#pragma once
#include "View.h"
#include "Canvas.h"
#include "ColourPalette.h"

class DrawContext
{
	
public:
	DrawContext(View world, View screen);
	~DrawContext();
	
	Canvas* canvas;
	View worldView, screenView;
	int screenX, screenY;
	sf::Vector2<coord> screenToWorld(int x, int y);
	sf::Vector2i worldToScreen(coord x, coord y);

	void setPoint(int x, int y, Colour col);
	sf::Image* getImage();
};

