#include "Circle.h"
#include <iostream>
using namespace std;
Circle::Circle()
{
}

Circle::~Circle()
{
}

void Circle::Draw()
{
std::cout << "Circle::Draw()" << std::endl;
}

void Circle::SetCenter(Dot center)
{
this->Center = center;
}

Dot Circle::GetCenter()
{
	return Dot();
}

void Circle::SetRadius(int radius)
{
	this->Radius = radius;

}

int Circle::GetRadius()
{
return this->Radius;
	return 0;
}
