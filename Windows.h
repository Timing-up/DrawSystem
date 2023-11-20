#pragma once
#include<easyx.h>
#include<iostream>
#include<string>
#include"pushButton.h"


using namespace std;
class Window
{

public:
	Window(int w, int h, int flag = 0);
	~Window();
	void Run();
	void setWindowTitle(const std::string& title);
	void setWindowColor(COLORREF c);
	void MenuWindow();
	void CanvasWindow();

public://static
	static int width();
	static int height();
	static void clear();
	static void beginDraw();
	static void flushDraw();
	static void endDraw();

	inline static bool hasMsg() { return peekmessage(&s_message); }//是否有消息,保存消息到s_message
	inline static const ExMessage& getMsg() { return s_message; }
private:
	HWND handle;	//当前窗口句柄
	static ExMessage s_message;
	Image W_bk;
};

