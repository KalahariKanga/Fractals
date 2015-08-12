#include "DrawContext.h"


DrawContext::DrawContext(View world, View screen)
{
	canvas = new Canvas(screen.w, screen.h);
	worldView = world;
	screenView = screen;
}


DrawContext::~DrawContext()
{
	delete canvas;

}

sf::Vector2<coord> DrawContext::screenToWorld(int x, int y)
{
	coord newX = worldView.x + ((coord)(x - screenView.x) / screenView.w)*worldView.w;
	coord newY = worldView.y + ((coord)(y - screenView.y) / screenView.h)*worldView.h;
	return sf::Vector2<coord>(newX, newY);
}

sf::Vector2i DrawContext::worldToScreen(coord x, coord y)
{
	return sf::Vector2i();
}

void DrawContext::setPoint(int x, int y, Colour col)
{
	canvas->setPoint(x - screenView.x, y - screenView.y, col);
}

