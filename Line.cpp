#include "Line.h"
#include <iostream>
using namespace std;

void Line::Draw()
{
	line(dot1.x, dot1.y, dot2.x, dot2.y);
}

void Line::Erase()
{
}

void Line::Move()
{
}

void Line::Resize()
{
}

void Line::SetLineStyle(int style,int thickness)
{	//setlinestyle(线型, 线宽, 颜色);
/*	PS_SOLID				0 实线
* 	PS_DASH					1 虚线
* 	PS_DOT					2 点线
* 	PS_DASHDOT				3 点划线
* 	PS_DASHDOTDOT			4 双点划线
* 	PS_NULL					5 空线
*/
	//设置线条样式
	//setlinestyle(style, thickness);

	//设置线条颜色
	setcolor(RED);

	this->style = style;
	this->thickness = thickness;

}
void Line::showInfo()
{
	cout << "Line:(" << dot1.x << "," << dot1.y << ")-(" << dot2.x << "," << dot2.y << ")" << endl;
	if (style == 0) {
		cout << "线条样式：实线，";
	}
	else if (style == 1) {
		cout << "线条样式：虚线，";
	}
	cout << "线宽；" << thickness << "像素" << endl << endl;

}



Line::Line()
{
}

Line::Line(Dot dot1, Dot dot2)
{
	this->dot1 = dot1;
	this->dot2 = dot2;
}

Line::~Line()
{
}

