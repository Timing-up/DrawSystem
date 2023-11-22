/*pushButton 按钮类*/
#ifndef __PUSHBUTTON_H_
#define __PUSHBUTTON_H_

#include"Image.h"
#include"BasicWidget.h"

class PushButton :public BasicWidget
{
public:
	PushButton(std::string text = "PushButton", int x = 0, int y = 0, int w = 100, int h = 30);
	void show();

	void setText(std::string text);
	//void setBackgroundImage(std::string imgPath);
	void setBackgroundColor(Color color);

	void setHover(COLORREF c);
	//void setHover(std::string imgPath);

	//事件循环
	void eventLoop(const ExMessage&);

	//鼠标是否在按钮上面
	bool isin();
	//鼠标是否点击了按钮
	bool isClicked();

	void setmsg(ExMessage msg) { _msg = msg; }

	~PushButton();

public:
	std::string text;				//按钮文字
	bool  isshow = false;			//显示状态
	ExMessage _msg;					//鼠标消息


public:	
	////current
	//COLORREF cur_color =RGB(232,232,236);
	////normal
	//COLORREF nor_color = RGB(232, 232, 236);
	////hover
	//COLORREF h_color = RED;

	int button_color = CYAN;        //按钮颜色
    int in_color = LIGHTBLUE;       //当鼠标在按钮上的颜色
    int click_clolor = LIGHTGREEN;  //当按下按钮时按钮的颜色
};
#endif