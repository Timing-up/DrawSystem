#include "Line.h"
#include <iostream>
#include "Windows.h"
using namespace std;

Image* Line::Draw()
{
	
	char s[10];
	InputBox(s, 10, "请输入线段左顶点横坐标", "线段", "300", 500, 0, false);
	this->dot1.x = atof(s);
	InputBox(s, 10, "请输入线段左顶点纵坐标", "线段", "300", 500, 0, false);
	this->dot1.y = atof(s);
	InputBox(s, 10, "请输入线段右顶点横坐标", "线段", "800", 500, 0, false);
	this->dot2.x = atof(s);
	InputBox(s, 10, "请输入线段右顶点纵坐标", "线段", "500", 500, 0, false);
	this->dot2.y = atof(s);
	InputBox(s, 10, "请输入线段样式：0 实线，1虚线", "线段样式", "0", 500, 0, false);
	this->style	 = atoi(s);
	InputBox(s, 10, "请输入线段粗细", "线段粗细", "5", 500, 0, false);
	this->thickness = atoi(s);


	SetLineStyle();

	//设置剪辑区域
	HRGN Line = CreateRectRgn(150, 0, 960, 540);
	setcliprgn(Line);


	int flag = 1;
	while (flag)
	{


		clearcliprgn();
		IMAGE img;
		loadimage(&img, _T("D:\\test.bmp"));
		putimage(150, 0, &img);
		ExMessage msg;
		peekmessage(&msg);
		switch (msg.message)
		{
		case WM_KEYDOWN:
			if (msg.vkcode == VK_RETURN) {
				flag = 0;
				Image* rectImage = new Image();

				line(dot1.x, dot1.y, dot2.x, dot2.y);

				Window::flushDraw();
				rectImage->Getimage(150, 0, 810, 540);
				saveimage(_T("D:\\test.bmp"), rectImage);
				return rectImage;
			}//多条语句，请把大括号带上！！！


			if (GetAsyncKeyState(VK_UP)) {
				dot1.y -= 1;
				dot1.y -= 1;
				dot2.y -= 1;
				dot2.y -= 1;
			}
			if (GetAsyncKeyState(VK_DOWN)) {
				dot1.y += 1;
				dot1.y += 1;
				dot2.y += 1;
				dot2.y += 1;
			}
			if (GetAsyncKeyState(VK_LEFT)) {
				dot1.x -= 1;
				dot1.x -= 1;
				dot2.x -= 1;
				dot2.x -= 1;
			}
			if (GetAsyncKeyState(VK_RIGHT)) {
				dot1.x += 1;
				dot1.x += 1;
				dot2.x += 1;
				dot2.x += 1;
			}
		}

		//循环绘制
		line(dot1.x, dot1.y, dot2.x, dot2.y);
		Window::flushDraw();
		Window::flushDraw();
	}
	

	

	DeleteObject(Line);

	return NULL;
}

void Line::Erase()
{
}

void Line::Move()
{
}

void Line::Resize()
{
}

void Line::SetLineStyle()
{	//setlinestyle(线型, 线宽, 颜色);
/*	PS_SOLID				0 实线
* 	PS_DASH					1 虚线
* 	PS_DOT					2 点线
* 	PS_DASHDOT				3 点划线
* 	PS_DASHDOTDOT			4 双点划线
* 	PS_NULL					5 空线
*/
	this->style = style;
	this->thickness = thickness;
	//设置线条样式
	setlinestyle(style, thickness);

	//设置线条颜色
	setcolor(RED);



}
void Line::showInfo()
{
	cout << "Line:(" << dot1.x << "," << dot1.y << ")-(" << dot2.x << "," << dot2.y << ")" << endl;
	if (style == 0) {
		cout << "线条样式：实线，";
	}
	else if (style == 1) {
		cout << "线条样式：虚线，";
	}
	cout << "线宽；" << thickness << "像素" << endl << endl;

}



Line::Line()
{
	dot1.x = 0;
	dot1.y = 0;
	dot2.x = 0;
	dot2.y = 0;
	style = 0;
	thickness = 0;
}

Line::Line(int x1, int y1, int x2, int y2) :dot1(x1, y1), dot2(x2, y2)
{
	this->style = 0;
	this->thickness = 1;
}




Line::~Line()
{
}

void Line::setDot1(Dot dot1)
{
	this->dot1 = dot1;

}

void Line::setDot2(Dot dot2)
{
	this->dot2 = dot2;
}

Dot Line::getDot1()
{
	return this->dot1;
}

Dot Line::getDot2()
{
	return this->dot2;
}

void Line::setStyle(int style)
{
	this->style = style;
}

void Line::setThickness(int thickness)
{
	this->thickness = thickness;
}

int Line::getStyle()
{
	return style;
}

int Line::getThickness()
{
	return thickness;
}

