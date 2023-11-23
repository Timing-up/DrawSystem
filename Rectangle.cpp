#include "Rectangle.h"
#include "Windows.h"





Image* Rect::Draw()
{

	//设置剪辑区域
	//HRGN rect = CreateRectRgn(0, 0, 960, 540);
	//setcliprgn(rect);

	//输入图形信息
	char s[10];
	InputBox(s, 10, "请输入矩形左上角顶点横坐标","矩形","300", 500, 0, false);
	UpperLeft.x = atof(s);
	InputBox(s, 10, "请输入矩形左上角顶点纵坐标","矩形","200", 500, 0, false);
	UpperLeft.y = atof(s);
	InputBox(s, 10, "请输入矩形长", "矩形", "500", 500, 0, false);
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
	int fill = 0;
	int color;
	
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
				Image *rectImage = new Image();
				
				rectangle(UpperLeft.x, UpperLeft.y, LowerRight.x, LowerRight.y);
				Window::flushDraw();

				rectImage->Getimage(150, 0, 810, 540);
				saveimage(_T("D:\\test.bmp"), rectImage);
				return rectImage; 
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
			}
			//如果按r，旋转90度
			if (GetAsyncKeyState(0x52)) {

				UpperLeft.x = 850- UpperLeft.y;
				UpperLeft.y = UpperLeft.x-250;
				
				LowerRight.x = 850- LowerRight.y;
				LowerRight.y = LowerRight.x-250;

				//如果按r，旋转5度
				/*LowerRight.x = LowerRight.x *cos(5*3.14/180)+ LowerRight.y*sin(5 * 3.14 / 180);
				LowerRight.y = (-1)* LowerRight.x* sin(5 * 3.14 / 180)+ LowerRight.y*cos(5 * 3.14 / 180);*/



				/*UpperLeft.x = UpperLeft.x *cos(5*3.14/180)+ UpperLeft.y*sin(5 * 3.14 / 180);
				UpperLeft.y = (-1)*UpperLeft.x* sin(5 * 3.14 / 180)+ UpperLeft.y*cos(5 * 3.14 / 180);

				LowerRight.x = LowerRight.x *cos(5*3.14/180)+ LowerRight.y*sin(5 * 3.14 / 180);
				LowerRight.y = (-1)* LowerRight.x* sin(5 * 3.14 / 180)+ LowerRight.y*cos(5 * 3.14 / 180);*/

			
			}
			//如果按f，添加填充InputBox(s, 10, "请输入填充颜色", "填充", "0", 500, 0, false);
			/*if (GetAsyncKeyState(	0x46)) {
				
				fill = 1;
				InputBox(s, 10, "请输入填充颜色", "填充", "", 500, 0, false);
				int color = atoi(s);
			}
			break;*/

		/*case WM_MOUSEWHEEL:
			if (msg.wheel == 240) {
				UpperLeft.x += 1;
				LowerRight.x += 1;
			}
			if (msg.wheel == -240) {
				UpperLeft.x -= 1;
				LowerRight.x -= 1;
			}*/
		}
		
		//循环绘制
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
