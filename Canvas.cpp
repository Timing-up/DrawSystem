#include "Canvas.h"
#include "Windows.h"
#include <conio.h>



Canvas::Canvas()
{
	//c_bk = Image("./image/1.jpg", Window::width(), Window::height());

}

Canvas::~Canvas()
{
}

void Canvas::run(ExMessage *w_msg)
{

		Window::clear();
		graphdefaults();
		setbkmode(TRANSPARENT);
		//loadimage(NULL, _T("./image/3.jpg"), GetSystemMetrics(SM_CXFULLSCREEN), GetSystemMetrics(SM_CYFULLSCREEN), true);//��ͼƬ�ļ���ȡͼ��
		//loadimage(NULL, _T("./image/3.jpg"), 960, 540, true);//��ͼƬ�ļ���ȡͼ��
		setbkcolor(WHITE);
		

		char Title[] = "����ͼ�λ���ϵͳ";
		settextcolor(RGB(255, 0, 0));	//�����ı���ɫΪ��ɫ
		settextstyle(30, 0, _T("����"));
		outtextxy((Window::width() - textwidth(Title)) / 2, 0, _T(Title));

		int ButtonHeight = 50;
		int UPDISTANCE = (HEIGHT - 9 * ButtonHeight) / 2;

	

	while (true)
	{
		//���ü�������
		HRGN rgn = CreateRectRgn(0, 0, 150, 540);
		setcliprgn(rgn);
		clearcliprgn();//-------------------------------------------------!!!!!!!!!
		//Window::clear();
		//�½���ť�����߶Ρ�
		PushButton* line = new PushButton();
		line->setFixedSize(100, ButtonHeight);
		line->setText("�߶�");
		line->move(WIDTH / 100, UPDISTANCE);



		//�½���ť�������Ρ�
		PushButton* rectangle = new PushButton();
		rectangle->setFixedSize(100, ButtonHeight);
		rectangle->setText("����");
		rectangle->move(WIDTH / 100, UPDISTANCE + 2 * ButtonHeight);



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

		//����ť��������
		graph_btns.push_back(line);
		graph_btns.push_back(rectangle);
		graph_btns.push_back(square);
		graph_btns.push_back(circle);
		graph_btns.push_back(ellipse);

		//ͳһ���ư�ť
		line->show();
		rectangle->show();
		square->show();
		circle->show();
		ellipse->show();
		//Window::flushDraw();

		
		peekmessage(w_msg);
		line->eventLoop	(*w_msg);
		rectangle->eventLoop(*w_msg);
		square->eventLoop(*w_msg);
		circle->eventLoop(*w_msg);
		ellipse->eventLoop(*w_msg);

		Window::flushDraw();//ˢ�»�ͼ
		c_msg = *w_msg;	//ͬ����Ϣ
		//peekmessage(&c_msg, EX_MOUSE | EX_KEY);   //��ȡ��Ϣ�洢���ṹ���У����ǵ��½���ҳ���޷���ʹ��ESC�˳��������������//�뷨��ͨ����ͬ����Ĳ�ͬ��Ϣ�ṹ�����ж����ĸ��������Ϣ��
		switch (c_msg.message)
		{
		case WM_KEYDOWN:
			if (c_msg.vkcode == VK_ESCAPE)
				return;
		}
		if (line->isClicked())
		{
			//Graph* graph = new Line(100,100,200,200);
			//graph->Draw();
			//graphs.push_back(new Line());
			
			cout << "Line!" << endl;
		
		}
		else if (rectangle->isClicked())
		{
			cout << "Rectangle!" << endl;
	
		}
		else if (square->isClicked())
		{
			cout << "Square!" << endl;
	
		}
		else if (circle->isClicked())
		{
			Graph* graph = new Circle(400,200, 50);
			graph->Draw();
			cout << "Circle!" << endl;
	
		}
		else if (ellipse->isClicked())
		{
			cout << "Ellipse!" << endl;
	
		}

		DeleteObject(rgn);
	}
	
	return;
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
