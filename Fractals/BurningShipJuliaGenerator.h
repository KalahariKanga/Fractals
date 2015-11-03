#pragma once
#include "Generator.h"
class BurningShipJuliaGenerator :
	public Generator
{
	sf::Vector2<coord> juliaPos;
protected:
	virtual float generatePoint(sf::Vector2<coord> pos);
public:
	BurningShipJuliaGenerator();
	~BurningShipJuliaGenerator();
	virtual void onEvent(sf::Event ev);
};

