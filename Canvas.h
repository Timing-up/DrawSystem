#include "Dot.h"
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Square.h"
#include"Windows.h"
#include"pushButton.h"
class Canvas
{
public:
	Canvas();
	~Canvas();
	void run();
	void menu();
	
	void drawBackground();


	void draw(Graph *graph);
	void erase(Graph* graph);
	void move(Graph* graph);
	void resize(Graph* graph);

	Image c_bk;

private:
	int opt = 66;
	ExMessage c_msg;
	
	Line line;
	class Rectangle rectangle;
	Circle circle;
	Square square;
	class Ellipse ellipse;
	Quadrilateral quadrilateral;
};

