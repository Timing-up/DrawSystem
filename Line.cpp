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
{	//setlinestyle(����, �߿�, �������, �㻭�ߵĵ���);
/*	PS_SOLID 0 ʵ��
* 	PS_DASH 1 ����
* 	PS_DOT 2 ����
* 	PS_DASHDOT 3 �㻮��
* 	PS_DASHDOTDOT 4 ˫�㻮��
* 	PS_NULL 5 ����
*/
	
	setlinestyle(style, thickness);

	//����������ɫ
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
