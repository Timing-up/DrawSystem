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

	//文字
	settextcolor(RGB(212, 73, 182));
	settextstyle(50, 0,"字魂24号-镇魂手书");
	outtextxy(400, 300,"开始绘图！");
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
	::BeginBatchDraw();//双缓冲绘图，防止闪烁
}

void Window::flushDraw()
{
	::FlushBatchDraw();//刷新,::表示全局函数
}

void Window::endDraw()
{
	::EndBatchDraw();//结束绘图
}
