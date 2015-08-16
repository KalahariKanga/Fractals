#pragma once
#include "Generator.h"
class JuliaGenerator : public Generator
{
	coord juliaX, juliaY;
protected:
	virtual float generatePoint(sf::Vector2<coord> pos);
public:
	JuliaGenerator();
	~JuliaGenerator();
};

