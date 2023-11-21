#include "Windows.h"
#include"Canvas.h"
#include<conio.h>//������Ϣ

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
		W_bk.draw();//���Ʊ���ͼƬ
		
		//�½���ť������ʼ��ͼ����
		PushButton* start = new PushButton();
		start->setFixedSize(200, 50);
		start->setText("��ʼ��ͼ��");
		start->move((WIDTH-start->width())/2, 350);
		start->show();

		//�½���ť�����˳���
		PushButton* exit = new PushButton();
		exit->setFixedSize(200, 50);
		exit->setText("�˳�");
		exit->move((WIDTH - exit->width()) / 2, 450);
		exit->show();

		//�����Ϸ���ʾ���֡���ӭʹ�û�ͼϵͳ����
		char Title[] = "��ӭʹ�û�ͼϵͳ��";
		settextstyle(60, 0, _T("����"));
		settextcolor(RGB(55, 170, 224));
		outtextxy((Window::width() - textwidth(Title)) / 2, 30, _T(Title));

		
		//�����·���ʾ���֡����ߣ�XXX��
		char Author[] = "����:TimingUP";
		settextstyle(30, 0, _T("����"));
		settextcolor(RGB(55, 170, 224));
		outtextxy(760, 500, _T(Author));

		
			ExMessage msg;
			peekmessage(&msg, -1);//��ȡһ����Ϣ���������
			start->eventLoop(msg);
			exit->eventLoop(msg);
			flushDraw();//ˢ�»�ͼ

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
			}	////CanvasWindow�л�ȡ��Ϣ�洢���ṹ���У����ǵ��½���ҳ���޷���ʹ��ESC�˳��������������*/
		
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
		//loadimage(NULL, _T("./image/3.jpg"), GetSystemMetrics(SM_CXFULLSCREEN), GetSystemMetrics(SM_CYFULLSCREEN), true);//��ͼƬ�ļ���ȡͼ��
		//loadimage(NULL, _T("./image/3.jpg"), 960, 540, true);//��ͼƬ�ļ���ȡͼ��
		setbkcolor(WHITE);
		clear();

		char Title[] = "����ͼ�λ���ϵͳ";
		settextcolor(RGB(255, 0, 0));	//�����ı���ɫΪ��ɫ
		settextstyle(30, 0, _T("����"));
		outtextxy((width() - textwidth(Title)) / 2, 0, _T(Title));
		
		int ButtonHeight = 50;
		int UPDISTANCE = (HEIGHT - 9 * ButtonHeight) / 2;
		//�½���ť�����߶Ρ�
		PushButton* line = new PushButton();
		line->setFixedSize(100, ButtonHeight);
		line->setText("�߶�");
		line->move(WIDTH/100, UPDISTANCE);
		
		

		//�½���ť�������Ρ�
		PushButton* rectangle = new PushButton();
		rectangle->setFixedSize(100, ButtonHeight);
		rectangle->setText("����");
		rectangle->move(WIDTH / 100, UPDISTANCE + 2*ButtonHeight);
		
		

		//�½���ť���������Ρ�
		PushButton* square = new PushButton();
		square->setFixedSize(100, ButtonHeight);
		square->setText("������");
		square->move(WIDTH / 100, UPDISTANCE + 4 * ButtonHeight);
		
		

		//�½���ť����Բ��
		PushButton* circle = new PushButton();
		circle->setFixedSize(100, ButtonHeight);
		circle->setText("Բ");
		circle->move(WIDTH / 100, UPDISTANCE + 6 * ButtonHeight);
		
		

		//�½���ť������Բ��
		PushButton* ellipse = new PushButton();
		ellipse->setFixedSize(100, ButtonHeight);
		ellipse->setText("��Բ");
		ellipse->move(WIDTH / 100, UPDISTANCE + 8 * ButtonHeight);
		

		//ͳһ���ư�ť
		line->show();
		rectangle->show();
		square->show();
		circle->show();
		ellipse->show();
		flushDraw();

		//��ť״̬�ж�
		line->eventLoop(w_msg);
		rectangle->eventLoop(w_msg);
		square->eventLoop(w_msg);
		circle->eventLoop(w_msg);
		ellipse->eventLoop(w_msg);
		flushDraw();//ˢ�»�ͼ




		peekmessage(&w_msg, EX_MOUSE | EX_KEY);   //��ȡ��Ϣ�洢���ṹ���У����ǵ��½���ҳ���޷���ʹ��ESC�˳��������������
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
