#pragma once
#include "Dot.h"
#include "Line.h"
class Ellip:public Graph
{

	public:
	//³ÉÔ±º¯Êý
		Ellip();
		Ellip(Dot UpperLeft,Dot LowerRight);
		Ellip(int left, int top, int right, int bottom);
		~Ellip();

	

		Image* Draw();
		void showInfo();

	/*bool isInside(Dot dot);
	bool isOnBoundary(Dot dot);
	bool isOnEllipse(Dot dot);
	bool isOutside(Dot dot);*/


private:
	Dot UpperLeft;
	Dot LowerRight;
	
	Line line;

};

