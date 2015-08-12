#pragma once
#include "Generator.h"
class MandelbrotGenerator :
	public Generator
{
protected:
	virtual float generatePoint(sf::Vector2<coord> pos);
public:
	MandelbrotGenerator();
	~MandelbrotGenerator();
};



