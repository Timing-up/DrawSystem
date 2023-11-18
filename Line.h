#pragma once
#include "Dot.h"
class Line:public Graph
{
	friend class Square;


	public:
		//设置样式
		void SetLineStyle(int style,int thickness);
		//画线
		void Draw();
		void Erase();
		void Move();
		void Resize();
	
		//构造函数
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

