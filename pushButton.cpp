#include "pushButton.h"


PushButton::PushButton(std::string text, int x, int y, int w, int h)
	:text(text), BasicWidget(x, y, w, h)
{
	memset(&_msg, 0, sizeof(ExMessage));

}

void PushButton::show()
{
	BasicWidget::show();
	if (cur_img)
	{
		cur_img->draw();
	}
	else
	{
		//设置Button框样式
		setlinecolor(MAGENTA);
		//setfillcolor(cur_color);
		::roundrect(m_x, m_y, m_x + m_w, m_y + m_h, 10, 10);
	}
	//文字设置
	//居中显示文本
	int tx = m_x + (m_w - textwidth(text.data())) / 2;
	int ty = m_y + (m_h - textheight(text.data())) / 2;
	settextcolor(RGB(255, 255, 255));
	settextstyle(35, 0, "字魂24号-镇魂手书");
	outtextxy(tx, ty, text.data());
}

void PushButton::setText(std::string text)
{
	this->text = text;
}

void PushButton::setBackgroundImage(std::string imgPath)
{
	if (!nor_img)
		nor_img = new Image(imgPath.data(), this->m_w, this->m_h);
	this->cur_img = nor_img;
	this->show();
}

void PushButton::setBackgroundColor(Color color)
{
	this->nor_color = color;
}

void PushButton::setHover(COLORREF c)
{
	h_color = c;
}

void PushButton::setHover(std::string imgPath)
{
	if (!h_img)
		h_img = new Image(imgPath.c_str(), m_w, m_h);
}

void PushButton::eventLoop(const ExMessage& msg)
{
	this->_msg = msg;
	if (isin())
	{
		if (cur_img)
		{
			cur_img = h_img;
		}
		else
		{
			cur_color = h_color;
		}
	}
	else
	{
		if (cur_img)
		{
			cur_img = nor_img;
		}
		else
		{
			cur_color = nor_color;
		}

	}

	//this->show();
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
