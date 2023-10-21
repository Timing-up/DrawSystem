#pragma once
#include "Dot.h"
#include "Line.h"
#include<graphics.h>

class Square
{
public:
	Dot UpperLeft;
	Dot LowerRight;

	Dot LowerLeft;
	Dot UpperRight;

	Line line;

	int left;
	int top;
	int right;
	int bottom;

//方法
	//画正方形
	void DrawSquare();

	//设置样式
	void SetSquareStyle(int style, int thickness, unsigned long color);




	//构造函数
	Square();
	Square(Dot UpperLeft, Dot LowerRight);
	Square(int left, int top, int right, int bottom);
	Square(int left, int top, int right, int bottom, COLORREF color);
	Square(int left, int top, int right, int bottom, COLORREF color, int width);
	Square(int left, int top, int right, int bottom, COLORREF color, int width, int style);
	Square(int left, int top, int right, int bottom, COLORREF color, int width, int style, COLORREF fillcolor);
	Square(int left, int top, int right, int bottom, COLORREF color, int width, int style, COLORREF fillcolor, int fillstyle);
	//析构函数
	~Square();


//Get方法和Set方法
	void SetUpperLeft(Dot UpperLeft);
	void SetLowerLeft(Dot LowerLeft);
	void SetUpperRight(Dot UpperRight);
	void SetLowerRight(Dot LowerRight);
	void SetLeft(int left);
	void SetTop(int top);
	void SetRight(int right);
	void SetBottom(int bottom);
	void SetColor(COLORREF color);
	void SetWidth(int width);
	void SetStyle(int style);
	void SetFillColor(COLORREF fillcolor);
	void SetFillStyle(int fillstyle);





};
