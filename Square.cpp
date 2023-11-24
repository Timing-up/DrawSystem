#include "Square.h"
#include "Rectangle.h"
#include <iostream>
#include "Windows.h"

using namespace std;

void Square::showInfo()
{
	cout << "正方形信息：" << endl;
	cout<<"左上角坐标：("<<UpperLeft.x<<","<<UpperLeft.y<<")"<<endl;
	cout<<"右下角坐标：("<<LowerRight.x<<","<<LowerRight.y<<")"<<endl;
	cout<<"边长："<<side<<endl;
	cout<<"面积："<<side*side<<endl;
	cout << "---------------------" << endl;
}

Square::Square(int x1, int y1, int side) :UpperLeft(x1, y1), LowerRight(x1 + side, y1 + side),side(side)
{

}


Image* Square::Draw()
{




	char s[10];
	InputBox(s, 10, "请输入正方形的左上角顶点横坐标", "正方形", "200", 500, 0, false);
	UpperLeft.x = atof(s);
	InputBox(s, 10, "请输入正方形的左上角顶点纵坐标", "正方形", "100", 500, 0, false);
	UpperLeft.y = atof(s);
	InputBox(s, 10, "请输入正方形的边长", "正方形", "200", 500, 0, false);
	side = atof(s);

	InputBox(s, 10, "请输入线条宽度", "正方形", "5", 500, 0, false);

	LowerRight.x = UpperLeft.x + side;
	LowerRight.y = UpperLeft.y + side;
	line.setThickness(atof(s));
	line.SetLineStyle();
	line.setDot1(UpperLeft);
	line.setDot2(LowerRight);

	//设置剪辑区域
	HRGN rect = CreateRectRgn(150, 0, 960, 540);
	setcliprgn(rect);

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
					Image* SquImage = new Image();

					fillrectangle(UpperLeft.x, UpperLeft.y, LowerRight.x, LowerRight.y);

					Window::flushDraw();
					SquImage->Getimage(150, 0, 810, 540);
					saveimage(_T("D:\\test.bmp"), SquImage);
					return SquImage;
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

			//循环绘制
			fillrectangle(UpperLeft.x, UpperLeft.y, LowerRight.x, LowerRight.y);
			Window::flushDraw();
		}
		/*rectangle(UpperLeft.x, UpperLeft.y, LowerRight.x, LowerRight.y);

		Window::flushDraw();
		DeleteObject(rect);*/



	}
}

	



void Square::SetSquareStyle(int style, int thickness)
{
	//实际调用Line的设置样式函数
	line.SetLineStyle();
	
	
}
void Square::resize(double scaleFactor)
{
	/*width *= scaleFactor;
	height *= scaleFactor;*/
//	LowerRight.x += (LowerLeft.x - UpperLeft.x)*scaleFactor;
//	LowerRight.y += (LowerLeft.y - UpperLeft.y)*scaleFactor;
	
		double centerX = (UpperLeft.x + LowerRight.x) / 2.0;
		double centerY = (UpperLeft.y + LowerRight.y) / 2.0;

		// 更新 UpperLeft 和 LowerRight 点的位置
		UpperLeft.x = centerX - (centerX - UpperLeft.x) * scaleFactor;
		UpperLeft.y = centerY - (centerY - UpperLeft.y) * scaleFactor;
		LowerRight.x = centerX + (LowerRight.x - centerX) * scaleFactor;
		LowerRight.y = centerY + (LowerRight.y - centerY) * scaleFactor;
	

}
//构造函数
Square::Square()
{
}

Square::Square(Dot &UpperLeft, Dot &LowerRight):UpperLeft(UpperLeft),LowerRight(LowerRight)
{
	this->side =abs(LowerRight.x - UpperLeft.x);

}


//析构函数
Square::~Square()
{
	cout << "图形已删除" << endl;
}

//Get函数和Set函数
void Square::SetUpperLeft(Dot UpperLeft)
{
	this->UpperLeft = UpperLeft;
}

void Square::SetLowerLeft(Dot LowerLeft)
{
	this->LowerLeft = LowerLeft;
}

void Square::SetUpperRight(Dot UpperRight)
{
	this->UpperRight = UpperRight;
}

void Square::SetLowerRight(Dot LowerRight)
{
	this->LowerRight = LowerRight;
}






void Square::SetStyle(int style)
{
}


void Square::SetFillStyle(int fillstyle)
{
}

int Square::GetSide()
{
	return side;
}

int Square::GetArea()
{
	return side*side;
}
