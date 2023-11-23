#include "Line.h"
#include <iostream>
#include "Windows.h"
using namespace std;

Image* Line::Draw()
{
	
	char s[10];
	InputBox(s, 10, "�������߶��󶥵������", "�߶�", "300", 500, 0, false);
	this->dot1.x = atof(s);
	InputBox(s, 10, "�������߶��󶥵�������", "�߶�", "300", 500, 0, false);
	this->dot1.y = atof(s);
	InputBox(s, 10, "�������߶��Ҷ��������", "�߶�", "800", 500, 0, false);
	this->dot2.x = atof(s);
	InputBox(s, 10, "�������߶��Ҷ���������", "�߶�", "500", 500, 0, false);
	this->dot2.y = atof(s);
	InputBox(s, 10, "�������߶���ʽ��0 ʵ�ߣ�1����", "�߶���ʽ", "0", 500, 0, false);
	this->style	 = atoi(s);
	InputBox(s, 10, "�������߶δ�ϸ", "�߶δ�ϸ", "5", 500, 0, false);
	this->thickness = atoi(s);


	SetLineStyle();

	//���ü�������
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
			}//������䣬��Ѵ����Ŵ��ϣ�����


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

		//ѭ������
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
{	//setlinestyle(����, �߿�, ��ɫ);
/*	PS_SOLID				0 ʵ��
* 	PS_DASH					1 ����
* 	PS_DOT					2 ����
* 	PS_DASHDOT				3 �㻮��
* 	PS_DASHDOTDOT			4 ˫�㻮��
* 	PS_NULL					5 ����
*/
	this->style = style;
	this->thickness = thickness;
	//����������ʽ
	setlinestyle(style, thickness);

	//����������ɫ
	setcolor(RED);



}
void Line::showInfo()
{
	cout << "Line:(" << dot1.x << "," << dot1.y << ")-(" << dot2.x << "," << dot2.y << ")" << endl;
	if (style == 0) {
		cout << "������ʽ��ʵ�ߣ�";
	}
	else if (style == 1) {
		cout << "������ʽ�����ߣ�";
	}
	cout << "�߿�" << thickness << "����" << endl << endl;

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

