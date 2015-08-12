#pragma once
#include "DrawContext.h"
class Generator
{
	
	std::vector<DrawContext*> incompleteContexts;
	std::vector<DrawContext*> contexts;
	std::mutex contextsMutex;
	
	void subdivideContext();
	void worker();
	unsigned workers;
	unsigned jobs;

protected:
	virtual float generatePoint(sf::Vector2<coord> pos) = 0;
public:
	Generator();
	~Generator();
	DrawContext* context; //make private
	void run();
};

