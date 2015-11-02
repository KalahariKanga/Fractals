#pragma once
#include "Generator.h"
class BurningShipGenerator :
	public Generator
{
protected:
	virtual float generatePoint(sf::Vector2<coord> pos);
public:
	BurningShipGenerator();
	~BurningShipGenerator();
};

