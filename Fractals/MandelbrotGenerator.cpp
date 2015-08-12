#include "MandelbrotGenerator.h"


MandelbrotGenerator::MandelbrotGenerator()
{
}


MandelbrotGenerator::~MandelbrotGenerator()
{
}

float MandelbrotGenerator::generatePoint(sf::Vector2<coord> pos)
{
	coord newa, newb;
	coord a = pos.x;
	coord b = pos.y;
	int loopSize = 100;// abs(log(double(endx - startx))) * 50 + 100;
	for (int count = 0; count < loopSize; count++)
	{
		newa = a*a - b*b + pos.x;
		newb = 2 * a*b + pos.y;
		/*newa = a*a*a - 3*a*b*b + pos.x;
		newb = 3*a*a*b - b*b*b + pos.y;*/

		if (sqrt(newa*newa + newb*newb) > 4)
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
