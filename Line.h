#pragma once
#include "Dot.h"
class Line
{
	public:
		Dot dot1;
		Dot dot2;
		void SetLineStyle(int style,int thickness, unsigned long color);
		void DrawLine(Dot dot1,Dot dot2);
	

		int style;
		int thickness;

		//RBG
		int R;
		int G;
		int B;

		//���캯��
		Line();
		Line(Dot dot1, Dot dot2);
		~Line();
};

