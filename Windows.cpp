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
		
		//�½���ť������ʼ��ͼ����
		PushButton* start = new PushButton();
		start->setFixedSize(200, 50);
		start->move(400, 350);
		start->setText("��ʼ��ͼ��");
		start->show();
		//�½���ť�����˳���
		PushButton* exit = new PushButton();
		exit->setFixedSize(200, 50);
		exit->move(400, 450);
		exit->setText("�˳�");
		exit->show();

		//�����Ϸ���ʾ���֡���ӭʹ�û�ͼϵͳ����
		char Title[] = "��ӭʹ�û�ͼϵͳ��";
		settextstyle(60, 0, _T("����"));
		settextcolor(RGB(55, 170, 224));
		outtextxy((Window::width() - textwidth(Title)) / 2, 30, _T(Title));

		flushDraw();//ˢ�»�ͼ

		//flushmessage(-1);	//���������Ϣ����
		//�Կ�ʼ��ͼ��ť���м���������е���¼���������ͼ����


		//Window::hasMsg();//�ж��Ƿ�����Ϣ���������Ϣ���򱣴���Ϣ��s_message������true�����򷵻�false
		//start->_msg = Window::getMsg();

		//Window::s_message;
		//start->eventLoop(m);
		
			ExMessage msg;
			peekmessage(&msg, -1);//��ȡһ����Ϣ���������
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
