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
		//loadimage(NULL, _T("./image/3.jpg"), GetSystemMetrics(SM_CXFULLSCREEN), GetSystemMetrics(SM_CYFULLSCREEN), true);//从图片文件获取图像
		//loadimage(NULL, _T("./image/3.jpg"), 960, 540, true);//从图片文件获取图像
		setbkcolor(WHITE);
		

		char Title[] = "简易图形绘制系统";
		settextcolor(RGB(255, 0, 0));	//设置文本颜色为红色
		settextstyle(30, 0, _T("楷体"));
		outtextxy((Window::width() - textwidth(Title)) / 2, 0, _T(Title));

		int ButtonHeight = 50;
		int UPDISTANCE = (HEIGHT - 9 * ButtonHeight) / 2;

	

	while (true)
	{
		
		//设置剪辑区域
		HRGN rgn = CreateRectRgn(0, 0, 150, 540);
		//HRGN rgn = CreateRectRgn(0, 0, 960, 540);
		setcliprgn(rgn);
		clearcliprgn();//-------------------------------------------------!!!!!!!!!
		//Window::clear();
		//新建按钮，“线段”
		PushButton* line = new PushButton();
		line->setFixedSize(100, ButtonHeight);
		line->setText("线段");
		line->move(WIDTH / 100, UPDISTANCE);



		//新建按钮，“矩形”
		PushButton* rectangle = new PushButton();
		rectangle->setFixedSize(100, ButtonHeight);
		rectangle->setText("矩形");
		rectangle->move(WIDTH / 100, UPDISTANCE + 2 * ButtonHeight);



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

		//将按钮存入容器
		graph_btns.push_back(line);
		graph_btns.push_back(rectangle);
		graph_btns.push_back(square);
		graph_btns.push_back(circle);
		graph_btns.push_back(ellipse);

		//统一绘制按钮
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


		//遍历输出GraphList中的图形,使用putimage函数输出
		//初始化it
		for (int i = 0; i < GraphList.size(); i++) {
			putimage(150,0, GraphList.back());
		}
		

		Window::flushDraw();//刷新绘图
		c_msg = *w_msg;	//同步消息
		//peekmessage(&c_msg, EX_MOUSE | EX_KEY);   //获取消息存储到结构体中，但是导致进入页面无法再使用ESC退出，待解决！！！//想法：通过不同窗体的不同消息结构体来判断是哪个窗体的消息？
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

			setlinestyle(0, 1);	//防止绘制线段样式影响画布按钮
		
		}
		else if (rectangle->isClicked())
		{
			Graph* rect = new Rect(300, 300, 100, 150);
			GraphList.push_back(rect->Draw());
			cout << "Rectangle!" << endl;
			setlinestyle(0, 1);	//防止绘制线段样式影响画布按钮
		}
		else if (square->isClicked())
		{
			Graph* square = new Square(300, 300, 500);
			square->Draw();
			cout << "Square!" << endl;
			setlinestyle(0, 1);	//防止绘制线段样式影响画布按钮
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
			//setlinestyle(0, 1);	//防止绘制线段样式影响画布按钮
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
