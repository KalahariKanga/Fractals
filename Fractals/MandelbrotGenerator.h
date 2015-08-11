#pragma once
#include "Generator.h"
class MandelbrotGenerator :
	public Generator
{
protected:
	virtual float generatePoint(sf::Vector2f pos);
public:
	MandelbrotGenerator();
	~MandelbrotGenerator();
};

