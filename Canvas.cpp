#include "Canvas.h"
#include "Windows.h"
#include <conio.h>
#include"Rectangle.h"
#include"Ellipse.h"



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
		//HRGN rgn = CreateRectRgn(0, 0, 960, 540);
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


		//�������GraphList�е�ͼ��,ʹ��putimage�������
		//��ʼ��it
		for (int i = 0; i < GraphList.size(); i++) {
			putimage(150,0, GraphList.back());
		}
		

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
			Graph* line = new Line(300,300,50,50);
			line->Draw();
			//graphs.push_back(new Line());
			
			cout << "Line!" << endl;

			setlinestyle(0, 1);	//��ֹ�����߶���ʽӰ�컭����ť
		
		}
		else if (rectangle->isClicked())
		{
			Graph* rect = new Rect(300, 300, 100, 150);
			GraphList.push_back(rect->Draw());
			cout << "Rectangle!" << endl;
			setlinestyle(0, 1);	//��ֹ�����߶���ʽӰ�컭����ť
		}
		else if (square->isClicked())
		{
			Graph* square = new Square(300, 300, 500);
			square->Draw();
			cout << "Square!" << endl;
			setlinestyle(0, 1);	//��ֹ�����߶���ʽӰ�컭����ť
		}
		else if (circle->isClicked())
		{
			Graph* circle = new Circle(400,200, 50);
			circle->Draw();
			cout << "Circle!" << endl;
	
		}
		else if (ellipse->isClicked())
		{
			Graph* ellipse = new Ellip(300, 300, 100, 50);
			ellipse->Draw();
			cout << "Ellipse!" << endl;
			//setlinestyle(0, 1);	//��ֹ�����߶���ʽӰ�컭����ť
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
