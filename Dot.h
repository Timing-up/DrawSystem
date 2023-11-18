#pragma once
#include<graphics.h>
#include"Graph.h"

class Dot
{	
	//ÓÑÔªÀà
	friend class Line;
	friend class Square;
	friend class Rectangle;
	friend class Circle;
	friend class Ellipse;


	public:
		Dot();
		Dot(int x, int y);
		~Dot();
		void drawDot();

		void showInfo();

		void SetX(int x);
		void SetY(int y);
		int GetX();
		int GetY();


	private:
		int x;
		int y;
};

