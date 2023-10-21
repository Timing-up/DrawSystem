#include "Dot.h"

Dot::Dot()
{
}

Dot::Dot(int x, int y)
{
	this->x = x;
	this->y = y;
}

Dot::~Dot()
{
}

void Dot::drawDot()
{
	x = this->x;
	y = this->y;
	putpixel(x, y,GREEN);

}


