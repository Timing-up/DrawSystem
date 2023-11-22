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
{	//Ä¿Ç°ÊÇ¾²Ì¬Ô²£¬ÎÞ·¨±à¼­

	//ÉèÖÃ¼ô¼­ÇøÓò
	HRGN circle = CreateRectRgn(0, 0, 960, 540);
	setcliprgn(circle);
	
	char s[10];
	InputBox(s, 10, "ÇëÊäÈëÔ²ÐÄºá×ø±ê", "Ô²", "400", 500, 0, false);
	this->Center.x = atof(s);
	InputBox(s, 10, "ÇëÊäÈëÔ²ÐÄ×Ý×ø±ê", "Ô²", "250", 500, 0, false);
	this->Center.y = atof(s);
	InputBox(s, 10, "ÇëÊäÈëÔ²°ë¾¶", "Ô²", "100", 500, 0, false);
	this->Radius = atof(s);

	std::cout << "Circle::Draw()" << std::endl;
	setfillcolor(RED);
	fillcircle(Center.GetX(), Center.GetY(), Radius);
	Window::flushDraw();//Ë¢ÐÂ»æÍ¼
	
	DeleteObject(circle);
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
	cout << "Ô²ÐÄ×ø±êÎª£º(" << Center.GetX() << "," << Center.GetY() << ")" << endl;
	cout << "°ë¾¶Îª£º" << Radius << endl << endl;
	cout << "---------------------" << endl;
}

void Circle::DrawCircle()
{
	circle(Center.GetX(), Center.GetY(), Radius);
}