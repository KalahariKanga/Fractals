#pragma once
#include "View.h"
#include "Canvas.h"
#include "ColourPalette.h"

class DrawContext
{
	
public:
	DrawContext(View world, View screen);
	~DrawContext();
	
	std::shared_ptr<Canvas> canvas;
	View worldView, screenView;
	sf::Vector2<coord> screenToWorld(int x, int y);
	sf::Vector2i worldToScreen(coord x, coord y);

	void setPoint(int x, int y, Colour col);
	Colour getPoint(int x, int y);
	void mergeContext(DrawContext* from);
	sf::Image* getImage();
};

