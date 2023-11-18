#pragma once
#include "Dot.h"
class Line:public Graph
{
	friend class Square;


	public:
		//������ʽ
		void SetLineStyle(int style,int thickness);
		//����
		void Draw();
		void Erase();
		void Move();
		void Resize();
	
		//���캯��
		Line();
		Line(Dot dot1, Dot dot2);
		~Line();
		void showInfo();

private:
	Dot dot1;
	Dot dot2;
	int style;
	int thickness;

	//RBG
	int R;
	int G;
	int B;

};

