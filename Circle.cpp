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

Image* Circle::Draw()
{
	char s[10];
	InputBox(s, 10, "请输入圆心横坐标", "圆", "400", 500, 0, false);
	this->Center.x = atof(s);
	InputBox(s, 10, "请输入圆心纵坐标", "圆", "250", 500, 0, false);
	this->Center.y = atof(s);
	InputBox(s, 10, "请输入圆半径", "圆", "100", 500, 0, false);
	this->Radius = atof(s);

	//设置剪辑区域
	HRGN circle = CreateRectRgn(150, 0, 960, 540);
	setcliprgn(circle);

	while (true)
	{
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
					Image* circleImage = new Image();

					fillcircle(Center.GetX(), Center.GetY(), Radius);
					Window::flushDraw();

					circleImage->Getimage(150, 0, 810, 540);
					saveimage(_T("D:\\test.bmp"), circleImage);
					return circleImage;
				}//多条语句，请把大括号带上！！！


				if (GetAsyncKeyState(VK_UP)) {
					Center.y -= 1;
					Center.y -= 1;
				}
				if (GetAsyncKeyState(VK_DOWN)) {
					Center.y += 1;
					Center.y += 1;
				}
				if (GetAsyncKeyState(VK_LEFT)) {
					Center.x -= 1;
					Center.x -= 1;
				}
				if (GetAsyncKeyState(VK_RIGHT)) {
					Center.x += 1;
					Center.x += 1;
				}if (GetAsyncKeyState(0x46)) {
					int R, G, B;
					InputBox(s, 10, "请输入填充颜色RGB：R值(0-255)", "填充颜色", "255", 500, 0, false);
					R = atoi(s);
					InputBox(s, 10, "请输入填充颜色RGB：G值(0-255)", "填充颜色", "255", 500, 0, false);
					G = atoi(s);
					InputBox(s, 10, "请输入填充颜色RGB：B值(0-255)", "填充颜色", "255", 500, 0, false);
					B = atoi(s);
					setfillcolor(RGB(R, G, B));

				}if (GetAsyncKeyState(0x4C)) {
					int R, G, B;
					InputBox(s, 10, "请输入线条颜色RGB：R值(0-255)", "填充颜色", "255", 500, 0, false);
					R = atoi(s);
					InputBox(s, 10, "请输入线条颜色RGB：G值(0-255)", "填充颜色", "255", 500, 0, false);
					G = atoi(s);
					InputBox(s, 10, "请输入线条颜色RGB：B值(0-255)", "填充颜色", "255", 500, 0, false);
					B = atoi(s);
					setlinecolor(RGB(R, G, B));
				}
			}

			//循环绘制


			fillcircle(Center.GetX(), Center.GetY(), Radius);
			Window::flushDraw();//刷新绘图

		}



		//DeleteObject(circle);

	}
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