#include "Rectangle.h"

void Rectangle::DrawRectangle()
{
	rectangle(UpperLeft.x, UpperLeft.y, LowerRight.x, LowerRight.y);
}

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(Dot& dot1, Dot dot2):Quadrilateral()
{
	this->UpperLeft = dot1;
	this->LowerRight = dot2;
	side1= abs(LowerRight.x - UpperLeft.x);
	side2 = abs(LowerRight.y - UpperLeft.y);
}



Rectangle::~Rectangle()
{
}
