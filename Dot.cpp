#include "Dot.h"
#include <iostream>
using namespace std;

Dot::Dot()
{
}

Dot::Dot(int x, int y):x(x),y(y)
{
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
void Dot::showInfo()
{
	cout << "This is a Dot" << endl;
	cout << "×ø±êÎª£º(" << x << "," << y << ")" << endl << endl;
	cout << "---------------------" << endl;
}



void Dot::SetX(int x)
{
	this->x = x;

}

void Dot::SetY(int y)
{
	this->y = y;
}

int Dot::GetX()
{
	return x;
}

int Dot::GetY()
{
	return y;
}

