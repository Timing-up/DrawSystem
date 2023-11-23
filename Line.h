#pragma once
#include "Dot.h"
class Line:public Graph
{
	friend class Square;


	public:
		//������ʽ
		void SetLineStyle();
		//����
		Image* Draw();
		void Erase();
		void Move();
		void Resize();
	
		//���캯��
		Line();
		Line(int x1, int y1, int x2, int y2);
		~Line();
		void setDot1(Dot dot1);
		void setDot2(Dot dot2);
		Dot getDot1();
		Dot getDot2();
		void setStyle(int style);
		void setThickness(int thickness);
		int getStyle();
		int getThickness();
		void showInfo();

private:
	Dot dot1;
	Dot dot2;
	int style = 0;
	int thickness;



};

