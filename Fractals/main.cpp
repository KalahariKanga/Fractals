#include "MandelbrotGenerator.h"

int main()
{
	sf::RenderWindow window;
	sf::Image image;
	sf::Sprite sprite;
	sf::Texture texture;

	window.create(sf::VideoMode(640, 640), "Fractals");
	

	MandelbrotGenerator gen;
	DrawContext context(View(-2, -2, 4, 4), View(0, 0, 640, 640));
	gen.context = &context;
	gen.run();

	
	sf::Event event;
	bool needUpdate = 0;
	while (1)
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Z)
				{
					context.worldView.scale(2);
					needUpdate = 1;
				}
				if (event.key.code == sf::Keyboard::X)
				{
					context.worldView.scale(0.5);
					needUpdate = 1;
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					context.worldView.translateAmount(0, -0.25);
					needUpdate = 1;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					context.worldView.translateAmount(0, 0.25);
					needUpdate = 1;
				}
				if (event.key.code == sf::Keyboard::Left)
				{
					context.worldView.translateAmount(-0.25, 0);
					needUpdate = 1;
				}
				if (event.key.code == sf::Keyboard::Right)
				{
					context.worldView.translateAmount(0.25, 0);
					needUpdate = 1;
				}
			}
		}

		if (needUpdate)
		{
			gen.run();
			needUpdate = 0;
		}

		texture.loadFromImage(*(context.canvas->getImage()));
		sprite.setTexture(texture);
		window.draw(sprite);
		window.display();
	}
	return 0;
}

