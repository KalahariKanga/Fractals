#include "View.h"

View::View()
{
	x = y = w = h = 0;
}
View::View(coord X, coord Y, coord W, coord H) : x(X), y(Y), w(W), h(H)
{
}


View::~View()
{
}

void View::translate(coord dx, coord dy)
{
	x += dx;
	y += dy;
}

void View::translateAmount(float xAmount, float yAmount)
{
	translate(w*xAmount, h*yAmount);
}

void View::scale(float amount)
{
	if (amount <= 0)
		return;
	w /= amount;
	h /= amount;
	x += (amount - 1)*(w / 2);
	y += (amount - 1)*(h / 2);
}
