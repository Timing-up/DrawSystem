#include "Ellipse.h"

Ellipse::Ellipse()
{
}

Ellipse::Ellipse(Dot center, double a, double b)
{
	this->center = center;
	this->a = a;
	this->b = b;
}

Ellipse::~Ellipse()
{

}

void Ellipse::setCenter(Dot center)
{
	this->center = center;
}

void Ellipse::setA(double a)
{
	this->a = a;
}

void Ellipse::setB(double b)
{
this->b = b;
}

Dot Ellipse::getCenter()
{
	return Dot();
}

double Ellipse::getA()
{
	return this->a;
}

double Ellipse::getB()
{
	return this->a;
}

void Ellipse::Draw()
{
	ellipse(center.GetX(), center.GetY(), a, b);
}

void Ellipse::showInfo()
{
}
