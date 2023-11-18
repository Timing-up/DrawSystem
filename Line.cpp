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
{	//setlinestyle(����, �߿�, ��ɫ);
/*	PS_SOLID				0 ʵ��
* 	PS_DASH					1 ����
* 	PS_DOT					2 ����
* 	PS_DASHDOT				3 �㻮��
* 	PS_DASHDOTDOT			4 ˫�㻮��
* 	PS_NULL					5 ����
*/
	//����������ʽ
	//setlinestyle(style, thickness);

	//����������ɫ
	setcolor(RED);

	this->style = style;
	this->thickness = thickness;

}
void Line::showInfo()
{
	cout << "Line:(" << dot1.x << "," << dot1.y << ")-(" << dot2.x << "," << dot2.y << ")" << endl;
	if (style == 0) {
		cout << "������ʽ��ʵ�ߣ�";
	}
	else if (style == 1) {
		cout << "������ʽ�����ߣ�";
	}
	cout << "�߿�" << thickness << "����" << endl << endl;

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

