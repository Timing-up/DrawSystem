#pragma once
#include "Dot.h"
#include "Line.h"
#include "Graph.h"

class Circle:Graph
{

public:
	//成员函数
	Circle();
	Circle(Dot &Center, int Radius);
	~Circle();

	void Draw();
	void SetCenter(Dot center);
	Dot GetCenter();
	void SetRadius(int radius);
	int GetRadius();

	void showInfo();
	void DrawCircle();
private:
	//属性
	Dot Center;
	int Radius;
	Line line;
};

