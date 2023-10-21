// DrawSystem.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include "Dot.h"
#include "Line.h"
#include "Square.h"


using namespace std;	

int main()
{
	initgraph(640, 480);	// 创建绘图窗口，大小为 640x480 像素
	
	int URx, URy;
	int DLx, DLy;
	int ULx, ULy;
	int DRx, DRy;

	//第一条线
	cin >> ULx >> ULy;
	cin >> DRx >> DRy;

	Dot dotUL(ULx, ULy);
	Dot dotDR(DRx, DRy);


	//第二条线
	cin >> URx >> URy;
	cin >> DLx >> DLy;

	
	Dot dotUR(URx,URy);
	Dot dotDL(DLx,DLy);
	//Line对象
	Line line;
	

	int style=0;
	int thickness=1;
	unsigned long color=RED;
	/*cout << "请输入要设置的线条样式，线宽，颜色" << endl;
	cout << "----------------------------------" << endl;
	cin >> style >> thickness >> color;*/



	line.SetLineStyle(style,thickness,color);
	line.DrawLine(dotUL,dotDR);
	line.DrawLine(dotUR,dotDL);
	


	//Dot对象
//	Dot dot1(200, 300);
//	dot1.drawDot();
	//Square对象
	
	Square squ1(dotUL,dotDR);
	/*cout << "请输入要设置的线条样式，线宽，颜色" << endl;
	cout << "----------------------------------" << endl;
	cin >> style >> thickness >> color;*/
	squ1.SetSquareStyle(style, thickness, color);
	squ1.DrawSquare();










	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口

}


