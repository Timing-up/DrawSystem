#pragma once
#include "Dot.h"
#include "Line.h"

class Circle
{
public:
	//属性
	Dot Center;
	int Radius;
	Line line;

	//成员函数
	Circle();
	~Circle();
	void Draw();
	void SetCenter(Dot center);
	Dot GetCenter();
	void SetRadius(int radius);
	int GetRadius();
};

