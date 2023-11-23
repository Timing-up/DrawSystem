#include "Rectangle.h"
#include "Windows.h"




void Rect::Draw()
{

	//设置剪辑区域
	//HRGN rect = CreateRectRgn(0, 0, 960, 540);
	//setcliprgn(rect);

	char s[10];
	InputBox(s, 10, "请输入矩形左上角顶点横坐标","矩形","500", 500, 0, false);
	UpperLeft.x = atof(s);
	InputBox(s, 10, "请输入矩形左上角顶点纵坐标","矩形","200", 500, 0, false);
	UpperLeft.y = atof(s);
	InputBox(s, 10, "请输入矩形长", "矩形", "300", 500, 0, false);
	width = atof(s);
	InputBox(s, 10, "请输入矩形宽", "矩形", "200", 500, 0, false);
	height = atof(s);
	InputBox(s, 10, "请输入线条宽度", "矩形", "5", 500, 0, false);

	LowerRight.x = UpperLeft.x + width;
	LowerRight.y = UpperLeft.y + height;
	line.setThickness(atof(s));
	line.SetLineStyle();
	HRGN rect = CreateRectRgn(150, 0, 960, 540);
	setcliprgn(rect);
	int flag = 1;
	while (flag)
	{
		////设置剪辑区域
		
		clearcliprgn();
		ExMessage msg;
		peekmessage(&msg);
		switch (msg.message)
		{
		case WM_KEYDOWN:
			if (msg.vkcode == VK_RETURN) {
				flag = 0;
				break;
			}//两条语句，请把大括号带上！！！
			

			if (GetAsyncKeyState(VK_UP)) {
				UpperLeft.y -= 1;
				LowerRight.y -= 1;
			}
			if (GetAsyncKeyState(VK_DOWN)) {
				UpperLeft.y += 1;
				LowerRight.y += 1;
			}
			if (GetAsyncKeyState(VK_LEFT)) {
				UpperLeft.x -= 1;
				LowerRight.x -= 1;
			}
			if (GetAsyncKeyState(VK_RIGHT)) {
				UpperLeft.x += 1;
				LowerRight.x += 1;
			}
		}

	rectangle(UpperLeft.x, UpperLeft.y, LowerRight.x, LowerRight.y);
	Window::flushDraw();
	}
	/*rectangle(UpperLeft.x, UpperLeft.y, LowerRight.x, LowerRight.y);
	Window::flushDraw();*/
	/*DeleteObject(rect);*/
}

Rect::Rect()
{
}



Rect::Rect(int x1, int y1, int widght, int height) :UpperLeft(x1, y1),LowerRight(x1 + widght, y1 + height), width(widght), height(height)
{
}




Rect::~Rect()
{
}
