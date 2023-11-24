#include "Windows.h"
#include<conio.h>//键盘消息

ExMessage Window::w_msg;//静态成员变量初始化

Window::Window(int w, int h, int flag)
{
	handle = initgraph(w, h, EX_DBLCLKS | EX_SHOWCONSOLE);
	setbkmode(TRANSPARENT);
	W_bk = Image("./image/1.jpg", Window::width(), Window::height());

}

Window::~Window()
{
	DeleteFile(_T("D:\\test.bmp"));
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
	
	Canvas* canvas = new Canvas();//新建画布

	beginDraw();	//开始双缓冲绘图
	while (true)
	{

		HRGN Welcome = CreateRectRgn(0, 0, WIDTH, HEIGHT);
		setcliprgn(Welcome);

		clearcliprgn();

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
		
		//ExMessage msg;
		Window::w_msg;
		peekmessage(&w_msg, -1);//获取一条消息，鼠标类型
		start->eventLoop(w_msg);
		exit->eventLoop(w_msg);

		flushDraw();//刷新绘图

	
		if (start->isClicked()) {
				cout << "Start!" << endl;

				DeleteObject(Welcome);

				DeleteFile(_T("D:\\test.bmp"));	//删除上一次绘制的图形数据
				canvas->run(&w_msg);			//画布运行-----------------
		}
			
		else if (exit->isin()) {
			cout<<"INExit!"<<endl;
			if (exit->isClicked()) {
				cout << "Exited System!" << endl;

				delete exit;
				delete start;
				break;
			}
		}
		/*else if (w_msg.vkcode == VK_ESCAPE) {
			break;
		}	////CanvasWindow中获取消息存储到结构体中，但是导致进入页面无法再使用ESC退出，待解决！！！*/
		
	}
	endDraw();



	delete canvas;
	return ;
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
