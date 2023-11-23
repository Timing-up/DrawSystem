#include "Dot.h"
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Square.h"
#include"pushButton.h"
#include"Image.h"
#include <vector>
#ifndef	 _CANVAS_H_
#define  _CANVAS_H_

#define WIDTH 960
#define HEIGHT 540
class Canvas
{
public:
	Canvas();
	~Canvas();
	void run(ExMessage *w_msg);
	void menu();
	
	void drawBackground();


	void draw(Graph *graph);
	void erase(Graph* graph);
	void move(Graph* graph);
	void resize(Graph* graph);

	Image c_bk;

public:

	ExMessage c_msg;

	std::vector<PushButton*> graph_btns;//ͼ�ΰ�ť����
	//�����ͼ��Ϣ��Image����
	vector<Image*> GraphList;		// ͼ���б�


private:
	vector<Graph*> graphs;//ͼ������



	friend class Window;

	/*Line line;
	class Rectangle rectangle;
	Circle circle;
	Square square;
	class Ellipse ellipse;
	Quadrilateral quadrilateral;*/
};
#endif
