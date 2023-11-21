#include "Windows.h"
#include"Canvas.h"
#include<conio.h>//键盘消息

ExMessage Window::w_msg;

Window::Window(int w, int h, int flag)
{
	handle = initgraph(w, h, EX_DBLCLKS | EX_SHOWCONSOLE);
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
		start->setText("开始绘图！");
		start->move((WIDTH-start->width())/2, 350);
		start->show();

		//新建按钮，“退出”
		PushButton* exit = new PushButton();
		exit->setFixedSize(200, 50);
		exit->setText("退出");
		exit->move((WIDTH - exit->width()) / 2, 450);
		exit->show();

		//在正上方显示文字“欢迎使用绘图系统！”
		char Title[] = "欢迎使用绘图系统！";
		settextstyle(60, 0, _T("宋体"));
		settextcolor(RGB(55, 170, 224));
		outtextxy((Window::width() - textwidth(Title)) / 2, 30, _T(Title));

		
		//在正下方显示文字“作者：XXX”
		char Author[] = "作者:TimingUP";
		settextstyle(30, 0, _T("宋体"));
		settextcolor(RGB(55, 170, 224));
		outtextxy(760, 500, _T(Author));

		
			ExMessage msg;
			peekmessage(&msg, -1);//获取一条消息，鼠标类型
			start->eventLoop(msg);
			exit->eventLoop(msg);
			flushDraw();//刷新绘图

			/*if (start->isin()) {
				cout << "INStart!" << endl;
			}*/
			if (start->isClicked()) {
					cout << "Start!" << endl;
					CanvasWindow();
			}
			
	

			else if (exit->isin()) {
				cout<<"INExit!"<<endl;
				if (exit->isClicked()) {
					cout << "Exited System!" << endl;
					break;
				}
			}
			/*else if (w_msg.vkcode == VK_ESCAPE) {
				break;
			}	////CanvasWindow中获取消息存储到结构体中，但是导致进入页面无法再使用ESC退出，待解决！！！*/
		
	}
	endDraw();
	return ;
}


void Window::CanvasWindow()
{
	Canvas* canvas = new Canvas();
	while (true)
	{
		

		/*for (auto btn : canvas.graph_btns)
		{
			btn->show();
		}
		for (size_t i = 0; i < canvas.graph_btns.size(); i++)
		{
			_getch();
			canvas.graph_btns[i]->eventLoop(w_msg);
			if (canvas.graph_btns[i]->isClicked())
			{
				
				cout<<"Clicked!" << i <<endl;
				_getch();
			}
		}*/


		graphdefaults();
		setbkmode(TRANSPARENT);
		//loadimage(NULL, _T("./image/3.jpg"), GetSystemMetrics(SM_CXFULLSCREEN), GetSystemMetrics(SM_CYFULLSCREEN), true);//从图片文件获取图像
		//loadimage(NULL, _T("./image/3.jpg"), 960, 540, true);//从图片文件获取图像
		setbkcolor(WHITE);
		clear();

		char Title[] = "简易图形绘制系统";
		settextcolor(RGB(255, 0, 0));	//设置文本颜色为红色
		settextstyle(30, 0, _T("楷体"));
		outtextxy((width() - textwidth(Title)) / 2, 0, _T(Title));
		
		int ButtonHeight = 50;
		int UPDISTANCE = (HEIGHT - 9 * ButtonHeight) / 2;
		//新建按钮，“线段”
		PushButton* line = new PushButton();
		line->setFixedSize(100, ButtonHeight);
		line->setText("线段");
		line->move(WIDTH/100, UPDISTANCE);
		
		

		//新建按钮，“矩形”
		PushButton* rectangle = new PushButton();
		rectangle->setFixedSize(100, ButtonHeight);
		rectangle->setText("矩形");
		rectangle->move(WIDTH / 100, UPDISTANCE + 2*ButtonHeight);
		
		

		//新建按钮，“正方形”
		PushButton* square = new PushButton();
		square->setFixedSize(100, ButtonHeight);
		square->setText("正方形");
		square->move(WIDTH / 100, UPDISTANCE + 4 * ButtonHeight);
		
		

		//新建按钮，“圆”
		PushButton* circle = new PushButton();
		circle->setFixedSize(100, ButtonHeight);
		circle->setText("圆");
		circle->move(WIDTH / 100, UPDISTANCE + 6 * ButtonHeight);
		
		

		//新建按钮，“椭圆”
		PushButton* ellipse = new PushButton();
		ellipse->setFixedSize(100, ButtonHeight);
		ellipse->setText("椭圆");
		ellipse->move(WIDTH / 100, UPDISTANCE + 8 * ButtonHeight);
		

		//统一绘制按钮
		line->show();
		rectangle->show();
		square->show();
		circle->show();
		ellipse->show();
		flushDraw();

		//按钮状态判断
		line->eventLoop(w_msg);
		rectangle->eventLoop(w_msg);
		square->eventLoop(w_msg);
		circle->eventLoop(w_msg);
		ellipse->eventLoop(w_msg);
		flushDraw();//刷新绘图




		peekmessage(&w_msg, EX_MOUSE | EX_KEY);   //获取消息存储到结构体中，但是导致进入页面无法再使用ESC退出，待解决！！！
		switch (w_msg.message)
		{
		case WM_KEYDOWN:
			if (w_msg.vkcode == VK_ESCAPE)
				return;
		case WM_LBUTTONDOWN:
			if (line->isClicked())
			{
				cout << "Line!" << endl;
				canvas->run();
			}
			else if (rectangle->isClicked())
			{
				cout << "Rectangle!" << endl;
				canvas->run();
			}
			else if (square->isClicked())
			{
				cout << "Square!" << endl;
				canvas->run();
			}
			else if (circle->isClicked())
			{
				cout << "Circle!" << endl;
				canvas->run();
			}
			else if (ellipse->isClicked())
			{
				cout << "Ellipse!" << endl;
				canvas->run();
			}
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
