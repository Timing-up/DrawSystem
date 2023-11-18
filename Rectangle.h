#pragma once
#include "Quadrilateral.h"
#include "Dot.h"
#include"Line.h"
using namespace std;

class Rectangle	:public Quadrilateral
{
public:
	

	int getArea()  {
		return side1 * side2;
	}

	void showInfo()  {
		cout << "This is a rectangle." << endl;
		cout << "Length: " << side1 << endl;
		cout << "Width: " << side2 << endl;

	}
	void DrawRectangle();

	Rectangle();
	Rectangle(Dot&dot1,Dot dot2);
	~Rectangle();


private:
	Dot UpperLeft;
	Dot LowerRight;
	Line line;

	

};

