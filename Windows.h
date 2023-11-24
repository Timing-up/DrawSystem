#pragma once
#include<easyx.h>
#include<iostream>
#include<string>
#include"pushButton.h"
#include"Canvas.h"
#include<math.h>


using namespace std;
class Window
{

public:
	Window(int w, int h, int flag = 0);
	~Window();

	void setWindowTitle(const std::string& title);
	void setWindowColor(COLORREF c);
	void MenuWindow();


public://static
	static int width();
	static int height();
	static void clear();
	static void beginDraw();
	static void flushDraw();
	static void endDraw();

	inline static bool hasMsg() { return peekmessage(&w_msg); }//是否有消息,保存消息到s_message
	inline static const ExMessage& getMsg() { return w_msg; }
	static ExMessage w_msg;
private:
	HWND handle;	//当前窗口句柄
	
	Image W_bk;
};

