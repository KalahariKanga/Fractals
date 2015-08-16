#include "JuliaGenerator.h"


JuliaGenerator::JuliaGenerator()
{
	juliaX = juliaY = 0.3;
}


JuliaGenerator::~JuliaGenerator()
{
}

float JuliaGenerator::generatePoint(sf::Vector2<coord> pos)
{
	coord newa, newb;
	coord a = pos.x;
	coord b = pos.y;
	int loopSize = abs(log(context->worldView.w)) * 50 + 100;
	for (int count = 0; count < loopSize; count++)
	{
		newa = a*a - b*b + juliaX;
		newb = 2 * a*b + juliaY;

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
