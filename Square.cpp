#include "Square.h"
#include "Rectangle.h"
#include <iostream>

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

void Square::Draw()
{
	//使用Dot对象数据绘图

	 rectangle(UpperLeft.x, UpperLeft.y, LowerRight.x, LowerRight.y);

}

void Square::SetSquareStyle(int style, int thickness)
{
	//实际调用Line的设置样式函数
	line.SetLineStyle(style, thickness);
	
	
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
