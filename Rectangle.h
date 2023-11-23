#pragma once
//#include"Graph.h"
#include "Dot.h"
#include"Line.h"
#include <iostream>
using namespace std;

class Rect :public Graph
{
public:
	

	

	void showInfo()  {
		cout << "This is a rectangle." << endl;
		cout << "Width: " << width << endl;
		cout << "Height: " << height << endl;

	}
	Image* Draw();


	

	Rect();
	
	Rect(int x1, int y1,int widht,int height);
	~Rect();

	void setUpperLeft(int x, int y) {
		UpperLeft.x = x;
		UpperLeft.y = y;
	}
	void setLowerRight(int x, int y) {
		LowerRight.x = x;
		LowerRight.y = y;
	}
	void setWidth(int widght) {
		width = widght;
	}
	void setHeight(int height) {
		height = height;
	}

	int getWidth() {
		return width;
	}
	int getHeight() {
		return height;
	}
	int getUpperLeftX() {
		return UpperLeft.x;
	}
	int getUpperLeftY() {
		return UpperLeft.y;
	}
	int getLowerRightX() {
		return LowerRight.x;
	}
	int getLowerRightY() {
		return LowerRight.y;
	}


private:
	Dot UpperLeft;
	Dot LowerRight;
	int width;
	int height;

	Line line;

	

};

