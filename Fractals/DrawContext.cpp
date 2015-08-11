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

sf::Vector2f DrawContext::screenToWorld(int x, int y)
{
	float newX = worldView.x + ((float)(x - screenView.x) / screenView.w)*worldView.w;
	float newY = worldView.y + ((float)(y - screenView.y) / screenView.h)*worldView.h;
	return sf::Vector2f(newX, newY);
}

sf::Vector2i DrawContext::worldToScreen(float x, float y)
{
	return sf::Vector2i();
}

void DrawContext::setPoint(int x, int y, Colour col)
{
	canvas->setPoint(x - screenView.x, y - screenView.y, col);
}

