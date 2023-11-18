#pragma once
#include "Dot.h"
class Ellipse:public Graph
{

	public:
	//³ÉÔ±º¯Êý
		Ellipse();
		Ellipse(Dot center, double a, double b);
		~Ellipse();

		void setCenter(Dot center);
		void setA(double a);
		void setB(double b);
		Dot getCenter();
		double getA();
		double getB();

		void Draw();
		void showInfo();

	/*bool isInside(Dot dot);
	bool isOnBoundary(Dot dot);
	bool isOnEllipse(Dot dot);
	bool isOutside(Dot dot);*/


private:
	Dot center;
	double a;
	double b;
	double c;
	

};

