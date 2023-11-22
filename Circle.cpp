#include "Circle.h"
#include <iostream>
#include "Windows.h"
using namespace std;
Circle::Circle()
{
}

Circle::Circle(Dot& Center, int Radius)
{
	this->Center = Center;
	this->Radius = Radius;
}

Circle::Circle(int x, int y, int Radius):Center(x,y),Radius(Radius)
{
}

Circle::~Circle()
{
}

void Circle::Draw()
{
std::cout << "Circle::Draw()" << std::endl;
setfillcolor(RED);
fillcircle(Center.GetX(), Center.GetY(), Radius);
Window::flushDraw();//ˢ�»�ͼ
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
	cout << "Բ������Ϊ��(" << Center.GetX() << "," << Center.GetY() << ")" << endl;
	cout << "�뾶Ϊ��" << Radius << endl << endl;
	cout << "---------------------" << endl;
}

void Circle::DrawCircle()
{
	circle(Center.GetX(), Center.GetY(), Radius);
}