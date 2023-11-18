#pragma once
class Graph
{
public:
	Graph();
	~Graph();
	virtual void Draw() = 0;
	/*virtual void Erase() = 0;
	virtual void Move() = 0;
	virtual void Resize() = 0;*/
	

	virtual void showInfo() = 0;
};

