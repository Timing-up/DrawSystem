#include "Windows.h"
#include<conio.h>//������Ϣ

ExMessage Window::w_msg;//��̬��Ա������ʼ��

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
	
	Canvas* canvas = new Canvas();//�½�����

	beginDraw();	//��ʼ˫�����ͼ
	while (true)
	{

		HRGN Welcome = CreateRectRgn(0, 0, WIDTH, HEIGHT);
		setcliprgn(Welcome);

		clearcliprgn();

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
		
		//ExMessage msg;
		Window::w_msg;
		peekmessage(&w_msg, -1);//��ȡһ����Ϣ���������
		start->eventLoop(w_msg);
		exit->eventLoop(w_msg);

		flushDraw();//ˢ�»�ͼ

	
		if (start->isClicked()) {
				cout << "Start!" << endl;

				DeleteObject(Welcome);

				DeleteFile(_T("D:\\test.bmp"));	//ɾ����һ�λ��Ƶ�ͼ������
				canvas->run(&w_msg);			//��������-----------------
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
		}	////CanvasWindow�л�ȡ��Ϣ�洢���ṹ���У����ǵ��½���ҳ���޷���ʹ��ESC�˳��������������*/
		
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
