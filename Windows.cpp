#include "Windows.h"
#include<conio.h>//键盘消息

ExMessage Window::w_msg;

Window::Window(int w, int h, int flag)
{
	handle = initgraph(w, h,EX_NOCLOSE);
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
		W_bk.draw();//绘制背景图片
		
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

		
		//在正下方显示文字“作者：XXX”
		char Author[] = "作者：越GG";
		settextstyle(30, 0, _T("宋体"));
		settextcolor(RGB(55, 170, 224));
		outtextxy(770, 500, _T(Author));

		
			ExMessage msg;
			peekmessage(&msg, -1);//获取一条消息，鼠标类型
			start->eventLoop(msg);
			exit->eventLoop(msg);
			flushDraw();//刷新绘图
			if (start->isin()) {
				cout << "INStart!" << endl;
			
				if (start->isClicked()) {
					cout << "Start!" << endl;
					CanvasWindow();
				}
			}
	

			else if (exit->isin()) {
				cout<<"INExit!"<<endl;
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
	
	while (true)
	{
		graphdefaults();
		setbkmode(TRANSPARENT);
		//loadimage(NULL, _T("./image/3.jpg"), GetSystemMetrics(SM_CXFULLSCREEN), GetSystemMetrics(SM_CYFULLSCREEN), true);//从图片文件获取图像
		loadimage(NULL, _T("./image/3.jpg"), 960, 540, true);//从图片文件获取图像
	//	setbkcolor(WHITE);
		//clear();
	
		settextcolor(RGB(255, 0, 0));	//设置文本颜色为红色
		settextstyle(100, 50, _T("楷体"));
		outtextxy(270, 0, _T("简单几何图形绘制系统"));
		flushDraw();
		char key = _getch();
		printf("%d,%c\n", key, key);

		if (key == 'q') {
			break;
		}
	}
	

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
