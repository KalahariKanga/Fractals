#include "Generator.h"

int main()
{
	sf::RenderWindow window;
	sf::Image image;
	sf::Sprite sprite;
	sf::Texture texture;

	window.create(sf::VideoMode(640, 480), "Fractals");
	

	Generator gen;
	DrawContext context(View(-2, -2, 4, 4), View(0, 0, 640, 480));
	gen.context = &context;
	gen.run();

	texture.loadFromImage(*(context.canvas->getImage()));
	sprite.setTexture(texture);
	window.draw(sprite);
	window.display();
	while (1){};
	return 0;
}