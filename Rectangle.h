#pragma once
class Rectangle
{
public:
	Rectangle();
	Rectangle(int x, int y, int width, int height);
	~Rectangle();

	int x;
	int y;
	int width;
	int height;

	bool contains(int x, int y);
};

