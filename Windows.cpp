#include "Windows.h"
#include<conio.h>//?

ExMessage Window::s_message;

Window::Window(int w, int h, int flag)
{
	handle = initgraph(w, h, flag);
	setbkmode(TRANSPARENT);
	W_bk = Image("./image/1.jpg", Window::width(), Window::height());

}

Window::~Window()
{
	closegraph();
}

void Window::Run()
{

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
	beginDraw();
	while (true)
	{
		W_bk.draw();
		
		//新建按钮，“开始绘图！”
		PushButton* start = new PushButton();
		start->setFixedSize(200, 50);
		start->move(400, 350);
		start->setText("开始绘图！");
		start->show();
		//新建按钮，“退出”
		PushButton* exit = new PushButton();
		exit->setFixedSize(200, 50);
		exit->move(400, 450);
		exit->setText("退出");
		exit->show();

		//在正上方显示文字“欢迎使用绘图系统！”
		char Title[] = "欢迎使用绘图系统！";
		settextstyle(60, 0, _T("宋体"));
		settextcolor(RGB(55, 170, 224));
		outtextxy((Window::width() - textwidth(Title)) / 2, 30, _T(Title));

		flushDraw();//刷新绘图

		//flushmessage(-1);	//清空所有消息类型
		//对开始绘图按钮进行监听，如果有点击事件，则进入绘图界面


		//Window::hasMsg();//判断是否有消息，如果有消息，则保存消息到s_message，返回true，否则返回false
		//start->_msg = Window::getMsg();

		//Window::s_message;
		//start->eventLoop(m);
		
			ExMessage msg;
			peekmessage(&msg, -1);//获取一条消息，鼠标类型
			start->eventLoop(msg);
			exit->eventLoop(msg);
			if (start->isin()) {
				start->setBackgroundColor(RGB(255, 255, 255));
				cout << "IN" << endl;
				start->show();
				if (start->isClicked()) {
					cout << "clicked!" << endl;

					fillcircle(100, 100, 50);

	


				}
			}
	

			else if (exit->isin()) {
				cout << "IN222" << endl;
				exit->setBackgroundColor(RGB(0, 0, 255));

				if (exit->isClicked()) {
					cout << "Exited System!" << endl;
					break;
				}
			}

	}
	endDraw();
	return ;
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
