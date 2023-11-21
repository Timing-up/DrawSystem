#include "pushButton.h"
#include <iostream>


PushButton::PushButton(std::string text, int x, int y, int w, int h)
	:text(text), BasicWidget(x, y, w, h)
{
	memset(&_msg, 0, sizeof(ExMessage));

}

void PushButton::show()
{
	BasicWidget::show();
	
		//����Button����ʽ
		setlinecolor(MAGENTA);
		setfillcolor(button_color);
		roundrect(m_x, m_y, m_x + m_w, m_y + m_h, 10, 10);
	
	//��������
	//������ʾ�ı�
	int tx = m_x + (m_w - textwidth(text.data())) / 2;
	int ty = m_y + (m_h - textheight(text.data())) / 2;
	
	outtextxy(tx, ty, text.data());
}

void PushButton::setText(std::string text)
{
	this->text = text;
}



void PushButton::setBackgroundColor(Color color)
{
	this->in_color = color;

}

void PushButton::setHover(COLORREF c)
{
	 click_clolor= c;
}


void PushButton::eventLoop(const ExMessage& msg)
{
	this->_msg = msg;

	if (isin()) {
		// ������ʽ
		//setlinestyle(PS_SOLID, 2);
		setfillcolor(in_color);	// �����Ϻ�ť����ɫ
		BasicWidget::show();

		// ���ư�ť
		fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);

		//��������

		//������ʾ�ı�
		int tx = m_x + (m_w - textwidth(text.data())) / 2;
		int ty = m_y + (m_h - textheight(text.data())) / 2;

		outtextxy(tx, ty, text.data());

		
		FlushBatchDraw();
	
	}
}

bool PushButton::isin()
{
	if (_msg.x >= m_x && _msg.x <= m_x + m_w && _msg.y >= m_y && _msg.y <= m_y + m_h)
	{
		return true;
	}
	return false;
}

bool PushButton::isClicked()
{
	if (isin())
	{
		switch (_msg.message)
		{
		case WM_LBUTTONDOWN:
			return true;
		}
	}
	return false;
}

PushButton::~PushButton()
{
}
