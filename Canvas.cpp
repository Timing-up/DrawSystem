#include "Canvas.h"

Canvas::Canvas()
{
	c_bk = Image("./image/1.jpg", Window::width(), Window::height());

}

Canvas::~Canvas()
{
}

void Canvas::run()
{
	//Window::beginDraw(); //执行后，任何绘图操作都将暂时不输出到绘图窗口上，直到执行 FlushBatchDraw 或 EndBatchDraw 才将之前的绘图输出。
	drawBackground();
	//新建按钮，“开始绘图！”
	PushButton* start = new PushButton();
	start->setFixedSize(200, 50);
	start->move(400, 350);
	start->setText("开始绘图！");
	start->show();
	//新建按钮，“退出”
	PushButton* exit = new PushButton();
	exit->setFixedSize(200, 50);
	exit->move(400, 450);
	exit->setText("退出");
	exit->show();

	//在正上方显示文字“欢迎使用绘图系统！”
	settextstyle(60, 0, _T("宋体"));
	settextcolor(WHITE);
	outtextxy(250, 60, _T("欢迎使用绘图系统！"));
	
	//flushmessage(-1);	//清空所有消息类型
	//对开始绘图按钮进行监听，如果有点击事件，则进入绘图界面


	//Window::hasMsg();//判断是否有消息，如果有消息，则保存消息到s_message，返回true，否则返回false
	//start->_msg = Window::getMsg();

	//Window::s_message;
	//start->eventLoop(m);

	ExMessage msg;
	getmessage(&msg, EX_MOUSE);//获取一条消息，鼠标类型
	start->eventLoop(msg);
	if (1) {
		start->setBackgroundColor(RGB(0, 0, 255));

	}
	
	if (start->isClicked()) {


		//打开绘图界面
		/*Window::clear();
		Window CanvasWindow(800, 600);
		CanvasWindow.setWindowTitle("绘图界面");*/
		

	}

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
			case WM_KEYDOWN:		//按键消息
				switch (c_msg.vkcode)
				{
				case VK_ESCAPE:		//ESC
					opt = 66;
					break;
				}
				break;
			default:				//其他的都是鼠标消息了
				this->eventLoop();
				break;
			}
		}

		if (opt == 66) {
			PushButton* btn = new PushButton();
			btn->setFixedSize(200, 50);
			btn->move(400, 350);
			btn->setText("开始绘图！");
			btn->show();
		}

		

		
	}
	*/
}




void Canvas::drawBackground()
{
	c_bk.draw();
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
