#include "Square.h"
#include "Rectangle.h"
#include <iostream>
#include "Windows.h"

using namespace std;

void Square::showInfo()
{
	cout << "��������Ϣ��" << endl;
	cout<<"���Ͻ����꣺("<<UpperLeft.x<<","<<UpperLeft.y<<")"<<endl;
	cout<<"���½����꣺("<<LowerRight.x<<","<<LowerRight.y<<")"<<endl;
	cout<<"�߳���"<<side<<endl;
	cout<<"�����"<<side*side<<endl;
	cout << "---------------------" << endl;
}

Square::Square(int x1, int y1, int side) :UpperLeft(x1, y1), LowerRight(x1 + side, y1 + side),side(side)
{

}


void Square::Draw()
{	//���ü�������
	HRGN rect = CreateRectRgn(0, 0, 960, 540);
	setcliprgn(rect);

	char s[10];
	InputBox(s, 10, "�����������ε����ϽǶ��������", "������", "200", 500, 0, false);
	UpperLeft.x = atof(s); 
	InputBox(s, 10, "�����������ε����ϽǶ���������", "������", "100", 500, 0, false);
	UpperLeft.y = atof(s); 
	InputBox(s, 10, "�����������εı߳�", "������", "200", 500, 0, false);
	side = atof(s);
	
	InputBox(s, 10, "�������������", "������", "5", 500, 0, false);

	LowerRight.x = UpperLeft.x + side;
	LowerRight.y = UpperLeft.y + side;
	line.setThickness(atof(s));
	line.SetLineStyle();
	line.setDot1(UpperLeft);
	line.setDot2(LowerRight);
	rectangle(UpperLeft.x, UpperLeft.y, LowerRight.x, LowerRight.y);

	Window::flushDraw();
	DeleteObject(rect);
	return;
}

void Square::SetSquareStyle(int style, int thickness)
{
	//ʵ�ʵ���Line��������ʽ����
	line.SetLineStyle();
	
	
}
void Square::resize(double scaleFactor)
{
	/*width *= scaleFactor;
	height *= scaleFactor;*/
//	LowerRight.x += (LowerLeft.x - UpperLeft.x)*scaleFactor;
//	LowerRight.y += (LowerLeft.y - UpperLeft.y)*scaleFactor;
	
		double centerX = (UpperLeft.x + LowerRight.x) / 2.0;
		double centerY = (UpperLeft.y + LowerRight.y) / 2.0;

		// ���� UpperLeft �� LowerRight ���λ��
		UpperLeft.x = centerX - (centerX - UpperLeft.x) * scaleFactor;
		UpperLeft.y = centerY - (centerY - UpperLeft.y) * scaleFactor;
		LowerRight.x = centerX + (LowerRight.x - centerX) * scaleFactor;
		LowerRight.y = centerY + (LowerRight.y - centerY) * scaleFactor;
	

}
//���캯��
Square::Square()
{
}

Square::Square(Dot &UpperLeft, Dot &LowerRight):UpperLeft(UpperLeft),LowerRight(LowerRight)
{
	this->side =abs(LowerRight.x - UpperLeft.x);

}


//��������
Square::~Square()
{
	cout << "ͼ����ɾ��" << endl;
}

//Get������Set����
void Square::SetUpperLeft(Dot UpperLeft)
{
	this->UpperLeft = UpperLeft;
}

void Square::SetLowerLeft(Dot LowerLeft)
{
	this->LowerLeft = LowerLeft;
}

void Square::SetUpperRight(Dot UpperRight)
{
	this->UpperRight = UpperRight;
}

void Square::SetLowerRight(Dot LowerRight)
{
	this->LowerRight = LowerRight;
}






void Square::SetStyle(int style)
{
}


void Square::SetFillStyle(int fillstyle)
{
}

int Square::GetSide()
{
	return side;
}

int Square::GetArea()
{
	return side*side;
}
