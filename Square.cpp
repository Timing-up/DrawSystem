#include "Square.h"
#include "Rectangle.h"
#include <iostream>

using namespace std;

void Square::DrawSquare()
{
	//使用Dot对象数据绘图
	left = UpperLeft.x;
	top = UpperLeft.y;
	right = LowerRight.x;
	bottom = LowerRight.y;

	//使用边界左边画图
	/*left = this->left;
	top = this->top;
	right = this->right;
	bottom = this->bottom;*/

	 rectangle(left,top,right,bottom);

}
void Square::SetSquareStyle(int style, int thickness, unsigned long color)
{
	//实际调用Line的设置样式函数
	line.SetLineStyle(style, thickness,color);
	
	
}
//构造函数
Square::Square()
{
}

Square::Square(Dot UpperLeft, Dot LowerRight)
{
	this->UpperLeft = UpperLeft;
	this->LowerRight = LowerRight;
}

Square::Square(int left, int top, int right, int bottom)
{
	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
}

Square::Square(int left, int top, int right, int bottom, COLORREF color)
{
}

Square::Square(int left, int top, int right, int bottom, COLORREF color, int width)
{
}

Square::Square(int left, int top, int right, int bottom, COLORREF color, int width, int style)
{
}

Square::Square(int left, int top, int right, int bottom, COLORREF color, int width, int style, COLORREF fillcolor)
{
}

Square::Square(int left, int top, int right, int bottom, COLORREF color, int width, int style, COLORREF fillcolor, int fillstyle)
{
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

void Square::SetLeft(int left)
{
	this->left = left;
}

void Square::SetTop(int top)
{
	this->top = top;
}

void Square::SetRight(int right)
{
	this->right = right;
}

void Square::SetBottom(int bottom)
{
	this->bottom = bottom;
}

void Square::SetColor(COLORREF color)
{
}

void Square::SetWidth(int width)
{
}

void Square::SetStyle(int style)
{
}

void Square::SetFillColor(COLORREF fillcolor)
{
}

void Square::SetFillStyle(int fillstyle)
{
}
