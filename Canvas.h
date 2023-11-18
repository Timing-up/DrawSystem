#include "Dot.h"
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Square.h"
class Canvas
{
public:
	Canvas();
	~Canvas();

	void draw(Graph *graph);
	void erase(Graph* graph);
	void move(Graph* graph);
	void resize(Graph* graph);

private:

	Line line;
	class Rectangle rectangle;
	Circle circle;
	Square square;
	class Ellipse ellipse;
	Quadrilateral quadrilateral;
};

