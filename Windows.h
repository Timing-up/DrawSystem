#pragma once
#include<easyx.h>
#include<string>



class Window
{

public:
	Window(int w, int h, int flag = 0);
	~Window();
	void run();
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

	inline static bool hasMsg() { return peekmessage(&s_message); }
	inline static const ExMessage& getMsg() { return s_message; }
private:
	HWND handle;	//µ±Ç°´°¿Ú¾ä±ú
	static ExMessage s_message;
};

