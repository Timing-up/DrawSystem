#include "Square.h"
#include "Rectangle.h"
#include <iostream>

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

void Square::Draw()
{
	//ʹ��Dot�������ݻ�ͼ

	 rectangle(UpperLeft.x, UpperLeft.y, LowerRight.x, LowerRight.y);

}

void Square::SetSquareStyle(int style, int thickness)
{
	//ʵ�ʵ���Line��������ʽ����
	line.SetLineStyle(style, thickness);
	
	
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
