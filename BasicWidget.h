#pragma once
#include"Color.h"
#include"Font.h"
#include<easyx.h>
class BasicWidget
{
public:
	BasicWidget(int x, int y, int w, int h);
	int width() const;
	int height()const;
	void setFixedSize(int w, int h);

	int x()const;
	int y()const;
	void move(int x, int y);

	//δʵ��
	void setBackgroundColor(const Color& color);
	Color BackgroundColor();

	void setFont(const Font& font);
	const Font& font();
	virtual void show();

protected:
	int m_x;
	int m_y;
	int m_w;
	int m_h;

	Color m_bkColor;	//������ɫ
	Font m_font;		//����
};

