#pragma once
#include "Dot.h"
#include "Line.h"
#include<graphics.h>
#include"Graph.h"
#include<iostream>
using namespace std;
class Square:public Graph

{
private:

	//组合关系
	Dot UpperLeft;
	Dot LowerRight;

	Dot LowerLeft;
	Dot UpperRight;

	Line line;
	
	int side;//边长

	int area;

	public:

	Square(int x1,int y1,int side);

	//画正方形
	void Draw();

	//设置样式
	void SetSquareStyle(int style, int thickness);

	void resize(double scaleFactor);

	void showInfo();





	//构造函数
	Square();
	Square(Dot &UpperLeft, Dot &LowerRight);

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
	int GetSide();
	int GetArea();




};
