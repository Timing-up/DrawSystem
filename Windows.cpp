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




void Window::setWindowTitle(const std::string& title)
{
	SetWindowText(handle, title.c_str());
}

void Window::setWindowColor(COLORREF c)
{
	::setbkcolor(c);
	clear();
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
	::BeginBatchDraw();//Ë«»º³å»æÍ¼£¬·ÀÖ¹ÉÁË¸
}

void Window::flushDraw()
{
	::FlushBatchDraw();//Ë¢ÐÂ,::±íÊ¾È«¾Öº¯Êý
}

void Window::endDraw()
{
	::EndBatchDraw();//½áÊø»æÍ¼
}
