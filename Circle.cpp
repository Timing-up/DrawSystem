#include "Circle.h"
#include <iostream>
using namespace std;
Circle::Circle()
{
}

Circle::Circle(Dot& Center, int Radius)
{
	this->Center = Center;
	this->Radius = Radius;
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
	Radius = radius;

}

int Circle::GetRadius()
{
return this->Radius;
}

void Circle::showInfo()
{
	cout<< "This is a Circle." << endl;
	cout << "圆心坐标为：(" << Center.GetX() << "," << Center.GetY() << ")" << endl;
	cout << "半径为：" << Radius << endl << endl;
	cout << "---------------------" << endl;
}

void Circle::DrawCircle()
{
	circle(Center.GetX(), Center.GetY(), Radius);
}