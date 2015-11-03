#include "BurningShipJuliaGenerator.h"


BurningShipJuliaGenerator::BurningShipJuliaGenerator()
{
}


BurningShipJuliaGenerator::~BurningShipJuliaGenerator()
{
}

float BurningShipJuliaGenerator::generatePoint(sf::Vector2<coord> pos)
{
	coord newa, newb;
	coord a = pos.x;
	coord b = pos.y;
	int loopSize = abs(log(context->worldView.w)) * 50 + 100;
	for (int count = 0; count < loopSize; count++)
	{
		newa = a*a - b*b + juliaPos.x;
		newb = 2 * abs(a*b) + juliaPos.y;

		if ((newa*newa + newb*newb) > 4)
		{
			return 1 - ((float)count / loopSize);
		}
		else
		{
			a = newa;
			b = newb;
			continue;
		}
	}
	return 0;
}

void BurningShipJuliaGenerator::onEvent(sf::Event ev)
{
	Generator::onEvent(ev);
	if (ev.type == sf::Event::MouseMoved)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			juliaPos = context->screenToWorld(ev.mouseMove.x, ev.mouseMove.y);
			run();
		}
	}
}