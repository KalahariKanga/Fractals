#pragma once
#include "DrawContext.h"
class Generator
{
	
	std::vector<std::shared_ptr<DrawContext>> incompleteContexts;
	std::vector<std::shared_ptr<DrawContext>> contexts;
	std::mutex contextsMutex;
	
	void subdivideContext();
	void worker();
	unsigned workers;
	unsigned jobs;

protected:
	virtual float generatePoint(sf::Vector2<coord> pos) = 0;
public:
	Generator();
	virtual ~Generator();
	DrawContext* context; //make private
	void run();
};

