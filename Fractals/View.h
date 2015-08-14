#pragma once
#include "core.h"
class View
{
public:
	View();
	View(coord x, coord y, coord w, coord h);
	~View();
	coord x, y, w, h;

	void translate(coord dx, coord dy);
	void translateAmount(float xAmount, float yAmount);
	void scale(float amount);
};

