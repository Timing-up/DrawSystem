// DrawSystem.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include "Dot.h"
#include "Line.h"
#include "Square.h"
#include "Painter.h"
#include "Circle.h"
#include "Rectangle.h"
#include"Canvas.h"

using namespace std;	

int main()
{

	Window windows(960,540);
	windows.setWindowTitle("简易图形绘制系统");
	windows.MenuWindow();

	
	





	//_getch();

	

















//	cout<<"画布创建完成。"<<endl;
//	
//
//	//Dot对象
//
////	Dot dotUR(URx,URy);
////	Dot dotDL(DLx,DLy);
//	Dot dot1(100,100);
//	Dot dot2(400,400);
//	dot1.drawDot();
//	dot2.drawDot();
//	dot1.showInfo();
//	dot2.showInfo();
//
//
//
//	//Line对象
//	Line line(dot1,dot2);
//
//	//利用Line对象设置线条样式
//
//	cout << "请设置线条类型和线宽" << endl;
//	cout << "实线输入\"0\",虚线输入\"1\"" << endl;
//	cout << "线宽输入\"1\"-\"10\"" << endl;
//	cout << "---------------------" << endl;
//	int style=0 ;	//实线 0
//	int thickness=2 ;	//线宽 2
//	//cin>>style>>thickness;
//
//	line.SetLineStyle(style, thickness);
//	line.showInfo();
//	line.Draw();
//
//
//
//
//	//正方形对象
//	Square squ1(dot1,dot2);
//	squ1.showInfo();
//	squ1.Draw();
//
//
//
//	//圆
//	int r=60;
//	cout << "请输入半径:" << endl;
//	//cin >> r;
//	Circle circle1(dot1,r);
//	circle1.showInfo();
//	circle1.DrawCircle();
//
//	//矩形对象
//	Dot dotUL(200,200);
//	Dot dotDR(500,600);
//	class Rectangle rect1(dotUL,dotDR);
//	rect1.showInfo();
//	rect1.DrawRectangle();
//	
//


	//Square对象
	
//	Square squ1(dotUL,dotDR);

	//squ1.SetSquareStyle(style, thickness, color);
	//squ1.DrawSquare();




	//键鼠事件以及缩放实现


	

	//bool isExit = false;
	//bool isLPress = false;
	//double saturate = 1;
	//double scaleFactor = 1.0;
	//ExMessage msg;
	//while (!isExit)//Exit退出循环
	//{
	//	while (peekmessage(&msg, EM_KEY | EM_MOUSE))//peekmessage检测键盘和鼠标消息
	//	{
	//		if (msg.message == WM_KEYDOWN)//WM_KEYDOWN键盘按下
	//		{

	//			if (msg.vkcode == VK_ESCAPE) isExit = true;// VK_ESCAPE退出
	//		}
	//		// WM_MOUSEMOVE鼠标移动 , WM_LBUTTONDOWN鼠标左键按下 , WM_LBUTTONUP鼠标左键抬起
	//		else if (msg.message == WM_MOUSEMOVE || msg.message == WM_LBUTTONDOWN || msg.message == WM_LBUTTONUP)
	//			
	//		{
	//			if (!isLPress && msg.lbutton)//鼠标左键按下
	//			{
	//				isLPress = true;// 初始化按下状态标识符为true
	//			}
	//			else if (isLPress && msg.lbutton)//鼠标左键按下并拖动，进行主要操作步骤
	//			{
	//				//循环-根据鼠标实时移动坐标信息进行图形缩放算法并重新绘制缩放处理后图形（删除旧图形，更新新图形）
	//				// 计算鼠标水平移动距离
	//				
	//				int deltaX = 1.0;
	//				deltaX = msg.x - dotDR.GetX(); // 计算鼠标水平移动的距离

	//				if (deltaX > 0)
	//				{
	//					// 向右拖动，增加缩放因子
	//					double newScaleFactor = 1.0 + (deltaX / 6000.0);
	//					scaleFactor = newScaleFactor;
	//				}
	//				else if (deltaX < 0)
	//				{
	//					std::cout << "缩小" << std::endl;
	//					// 向左拖动，减小缩放因子
	//					double newScaleFactor = (deltaX / 100000000000000.0);
	//					scaleFactor = newScaleFactor;
	//				}
	//				else
	//				{
	//					// 没有移动，缩放因子不变
	//					scaleFactor = 1.0;
	//				}



	//				// 更新矩形的大小
	//				squ1.resize(scaleFactor);


	//				cleardevice();//清空屏幕
	//				// 重新绘制矩形
	//				squ1.Draw();


	//			}
	//			else if (isLPress && !msg.lbutton)//鼠标左键抬起，结束主要操作步骤
	//			{
	//				isLPress = false;// 更新按下状态标识符为false，按键抬起状态
	//			}
	//		}
	//	}
	//	//cleardevice();//清空屏幕
	//	FlushBatchDraw();//刷新缓冲区
	//}


	






	return 0;
}


