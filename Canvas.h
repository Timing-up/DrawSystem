#include "Dot.h"
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Square.h"
#include"pushButton.h"
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

	std::vector<PushButton*> graph_btns;//Í¼ÐÎ°´Å¥ÈÝÆ÷



private:
	vector<Graph*> graphs;//Í¼ÐÎÈÝÆ÷

	friend class Window;

	/*Line line;
	class Rectangle rectangle;
	Circle circle;
	Square square;
	class Ellipse ellipse;
	Quadrilateral quadrilateral;*/
};
#endif
