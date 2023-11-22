/*pushButton ��ť��*/
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

	//�¼�ѭ��
	void eventLoop(const ExMessage&);

	//����Ƿ��ڰ�ť����
	bool isin();
	//����Ƿ����˰�ť
	bool isClicked();

	void setmsg(ExMessage msg) { _msg = msg; }

	~PushButton();

public:
	std::string text;				//��ť����
	bool  isshow = false;			//��ʾ״̬
	ExMessage _msg;					//�����Ϣ


public:	
	////current
	//COLORREF cur_color =RGB(232,232,236);
	////normal
	//COLORREF nor_color = RGB(232, 232, 236);
	////hover
	//COLORREF h_color = RED;

	int button_color = CYAN;        //��ť��ɫ
    int in_color = LIGHTBLUE;       //������ڰ�ť�ϵ���ɫ
    int click_clolor = LIGHTGREEN;  //�����°�ťʱ��ť����ɫ
};
#endif