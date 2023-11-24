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


Image* Ellip::Draw()
{
	char s[10];
	InputBox(s, 10, "请输入椭圆外切矩形左上角顶点横坐标", "矩形", "500", 500, 0, false);
	UpperLeft.x = atof(s);
	InputBox(s, 10, "请输入椭圆外切矩形左上角顶点纵坐标", "矩形", "200", 500, 0, false);
	UpperLeft.y = atof(s);
	InputBox(s, 10, "请输入椭圆外切矩形右下角顶点横坐标", "矩形", "900", 500, 0, false);
	LowerRight.x = atof(s);
	InputBox(s, 10, "请输入椭圆外切矩形右下角顶点纵坐标", "矩形", "400", 500, 0, false);
	LowerRight.y = atof(s);

	//设置剪辑区域
	HRGN ellip = CreateRectRgn(150, 0, 960, 540);
	setcliprgn(ellip);

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
					Image* ellipseImage = new Image();

					fillellipse(UpperLeft.x, UpperLeft.y, LowerRight.x, LowerRight.y);

					Window::flushDraw();
					ellipseImage->Getimage(150, 0, 810, 540);
					saveimage(_T("D:\\test.bmp"), ellipseImage);
					return ellipseImage;
				}//多条语句，请把大括号带上！！！


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

			fillellipse(UpperLeft.x, UpperLeft.y, LowerRight.x, LowerRight.y);
			Window::flushDraw();
		}







		//DeleteObject(ellip);

	
	}
}

void Ellip::showInfo()
{
}
