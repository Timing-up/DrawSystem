#include "Windows.h"
#include<conio.h>//?

ExMessage Window::s_message;
	Window::Window(int w, int h, int flag)
	{
		handle = initgraph(w, h, flag);
		setbkmode(TRANSPARENT);
	}

	Window::~Window()
	{
		closegraph();
	}


void Window::run()
{
	MenuWindow();
}

void Window::setWindowTitle(const std::string& title)
{
	SetWindowText(handle, title.c_str());
}

void Window::setWindowColor(COLORREF c)
{
	::setbkcolor(c);
	clear();
}

void Window::MenuWindow()
{
	IMAGE Menu;
	loadimage(&Menu, "./image/1.jpg");
	putimage(0, 0, &Menu);

	//����
	settextcolor(RGB(212, 73, 182));
	settextstyle(50, 0,"�ֻ�24��-�������");
	outtextxy(400, 300,"��ʼ��ͼ��");
}

void Window::CanvasWindow()
{
	IMAGE Canvas;
	
}

int Window::width()
{
	return getwidth();
}

int Window::height()
{
	return ::getheight();
}

void Window::clear()
{
	::cleardevice();
}

void Window::beginDraw()
{
	::BeginBatchDraw();//˫�����ͼ����ֹ��˸
}

void Window::flushDraw()
{
	::FlushBatchDraw();//ˢ��,::��ʾȫ�ֺ���
}

void Window::endDraw()
{
	::EndBatchDraw();//������ͼ
}
