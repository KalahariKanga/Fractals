#include "View.h"

View::View()
{
	x = y = w = h = 0;
}
View::View(float X, float Y, float W, float H) : x(X), y(Y), w(W), h(H)
{
}


View::~View()
{
}
