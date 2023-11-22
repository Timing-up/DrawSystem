#include "Ellipse.h"
#include "Windows.h"

Ellip::Ellip()
{
}



Ellip::Ellip(int left, int top, int right, int bottom):UpperLeft(left,top),LowerRight(right,bottom)
{
}

Ellip::Ellip(Dot UpperLeft, Dot LowerRight) :UpperLeft(UpperLeft), LowerRight(LowerRight)
{
	
}


Ellip::~Ellip()
{

}


void Ellip::Draw()
{
	//设置剪辑区域
	HRGN ellip = CreateRectRgn(0, 0, 960, 540);
	setcliprgn(ellip);

	char s[10];
	InputBox(s, 10, "请输入椭圆外切矩形左上角顶点横坐标", "矩形", "500", 500, 0, false);
	UpperLeft.x = atof(s);
	InputBox(s, 10, "请输入椭圆外切矩形左上角顶点纵坐标", "矩形", "200", 500, 0, false);
	UpperLeft.y = atof(s);
	InputBox(s, 10, "请输入椭圆外切矩形右下角顶点横坐标", "矩形", "900", 500, 0, false);
	LowerRight.x = atof(s);
	InputBox(s, 10, "请输入椭圆外切矩形右下角顶点纵坐标", "矩形", "400", 500, 0, false);
	LowerRight.y = atof(s);
	
	//InputBox(s, 10, "请输入线条宽度", "线条宽度", "5", 500, 0, false);
	//line.setThickness(atof(s));
	//line.SetLineStyle();



	setfillcolor(BLUE);
	fillellipse(UpperLeft.x, UpperLeft.y, LowerRight.x, LowerRight.y);

	Window::flushDraw();
	DeleteObject(ellip);

}

void Ellip::showInfo()
{
}
