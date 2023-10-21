#include "Line.h"

void Line::DrawLine(Dot dot1,Dot dot2)
{
	int x1 = dot1.x;
	int y1 = dot1.y;
	int x2 = dot2.x;
	int y2 = dot2.y;
	line(x1, y1, x2, y2);
}

void Line::SetLineStyle(int style,int thickness, unsigned long color)
{	//setlinestyle(线型, 线宽, 线条风格, 点画线的点数);
/*	PS_SOLID 0 实线
* 	PS_DASH 1 虚线
* 	PS_DOT 2 点线
* 	PS_DASHDOT 3 点划线
* 	PS_DASHDOTDOT 4 双点划线
* 	PS_NULL 5 空线
*/
	
	setlinestyle(style, thickness);

	//设置线条颜色
	setcolor(color);
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
