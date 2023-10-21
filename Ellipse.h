#pragma once
#include "Dot.h"
class Ellipse
{
	Dot center;
	double a;
	double b;
	double c;
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


	/*bool isInside(Dot dot);
	bool isOnBoundary(Dot dot);
	bool isOnEllipse(Dot dot);
	bool isOutside(Dot dot);*/
	

};

