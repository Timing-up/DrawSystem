#include "Canvas.h"

Canvas::Canvas()
{
	//c_bk = Image("./image/1.jpg", Window::width(), Window::height());

}

Canvas::~Canvas()
{
}

void Canvas::run()
{
	/*
	//Window::beginDraw(); //ִ�к��κλ�ͼ����������ʱ���������ͼ�����ϣ�ֱ��ִ�� FlushBatchDraw �� EndBatchDraw �Ž�֮ǰ�Ļ�ͼ�����
	drawBackground();
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
	outtextxy((Window::width()-textwidth(Title))/2, 30, _T(Title));
	
	//flushmessage(-1);	//���������Ϣ����
	//�Կ�ʼ��ͼ��ť���м���������е���¼���������ͼ����


	//Window::hasMsg();//�ж��Ƿ�����Ϣ���������Ϣ���򱣴���Ϣ��s_message������true�����򷵻�false
	//start->_msg = Window::getMsg();

	//Window::s_message;
	//start->eventLoop(m);
	while (1) {
		ExMessage msg;
		peekmessage(&msg, -1);//��ȡһ����Ϣ���������
		start->eventLoop(msg);
		exit->eventLoop(msg);
		if (start->isin()) {
			start->setBackgroundColor(RGB(255, 255, 255));
			cout << "IN" << endl;
			if (start->isClicked()) {
				cout << "clicked!" << endl;

				fillcircle(100, 100, 50);

				//�򿪻�ͼ����
				/*Window::clear();
				Window CanvasWindow(800, 600);
				CanvasWindow.setWindowTitle("��ͼ����");


			}
		}
		//else��esc�˳�ѭ��
		
		else if(exit->isin()) {
			cout<<"IN222"<<endl;
			exit->setBackgroundColor(RGB(0, 0, 255));
			
			if (exit->isClicked()) {
				cout<<"clicked222!"<<endl;
				break;
			}
		}
		

		
		
	}
	*/

	/*while (true)
	{
		//printf("----------\n");
		Window::clear();
		//Window::beginDraw();
		

		if (Window::hasMsg())
		{
			c_msg = Window::getMsg();
			switch (c_msg.message)
			{
			case WM_KEYDOWN:		//������Ϣ
				switch (c_msg.vkcode)
				{
				case VK_ESCAPE:		//ESC
					opt = 66;
					break;
				}
				break;
			default:				//�����Ķ��������Ϣ��
				this->eventLoop();
				break;
			}
		}

		if (opt == 66) {
			PushButton* btn = new PushButton();
			btn->setFixedSize(200, 50);
			btn->move(400, 350);
			btn->setText("��ʼ��ͼ��");
			btn->show();
		}

		

		
	}
	*/
}




void Canvas::drawBackground()
{
	//c_bk.draw();
}



void Canvas::draw(Graph* graph)
{
	graph->Draw();
}

//void Canvas::erase(Graph* graph)
//{
//	graph->Erase();
//}
//
//void Canvas::move(Graph* graph)
//{
//	graph->Move();
//}
//
//void Canvas::resize(Graph* graph)
//{
//	graph->Resize();
//}
