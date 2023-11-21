#include "Windows.h"
#include<conio.h>//������Ϣ

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
		W_bk.draw();//���Ʊ���ͼƬ
		
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

		
		//�����·���ʾ���֡����ߣ�XXX��
		char Author[] = "���ߣ�ԽGG";
		settextstyle(30, 0, _T("����"));
		settextcolor(RGB(55, 170, 224));
		outtextxy(770, 500, _T(Author));

		
			ExMessage msg;
			peekmessage(&msg, -1);//��ȡһ����Ϣ���������
			start->eventLoop(msg);
			exit->eventLoop(msg);
			flushDraw();//ˢ�»�ͼ
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
		//loadimage(NULL, _T("./image/3.jpg"), GetSystemMetrics(SM_CXFULLSCREEN), GetSystemMetrics(SM_CYFULLSCREEN), true);//��ͼƬ�ļ���ȡͼ��
		loadimage(NULL, _T("./image/3.jpg"), 960, 540, true);//��ͼƬ�ļ���ȡͼ��
	//	setbkcolor(WHITE);
		//clear();
	
		settextcolor(RGB(255, 0, 0));	//�����ı���ɫΪ��ɫ
		settextstyle(100, 50, _T("����"));
		outtextxy(270, 0, _T("�򵥼���ͼ�λ���ϵͳ"));
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
