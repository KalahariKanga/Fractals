#include "Canvas.h"


Canvas::Canvas(int w, int h)
{
	width = w;
	height = h;
	data = new sf::Uint8[width * height * 4];
}


Canvas::~Canvas()
{
	delete[] data;
}

void Canvas::setPoint(int x, int y, Colour col)
{
	data[4*(y*width + x)] = col.r;
	data[4*(y*width + x) + 1] = col.g;
	data[4*(y*width + x) + 2] = col.b;
	data[4 * (y*width + x) + 3] = 255;
}

sf::Image* Canvas::getImage()
{
	image.create(width, height, data);
	return &image;
}