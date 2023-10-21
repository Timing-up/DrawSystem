#pragma once
#include "Dot.h"
#include "Line.h"

class Circle
{
public:
	//����
	Dot Center;
	int Radius;
	Line line;

	//��Ա����
	Circle();
	~Circle();
	void Draw();
	void SetCenter(Dot center);
	Dot GetCenter();
	void SetRadius(int radius);
	int GetRadius();
};

