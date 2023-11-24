#pragma once
#include"Image.h"
class Graph
{
public:
	Graph();
	~Graph();


	virtual Image* Draw()= 0 ;
	virtual void showInfo() = 0;


	//virtual void Draw()=0 ;
	/*virtual void Erase() = 0;
	virtual void Move() = 0;
	virtual void Resize() = 0;*/


};

