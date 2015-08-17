#pragma once
#include "Generator.h"
class JuliaGenerator : public Generator
{
	sf::Vector2<coord> juliaPos;
protected:
	virtual float generatePoint(sf::Vector2<coord> pos);
public:
	JuliaGenerator();
	~JuliaGenerator();
	virtual void onEvent(sf::Event ev);
};

