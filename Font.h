#pragma once
#include"TypeDefine.h"
#include<string>
#include"Color.h"
class Font
{
public:
    Font();
    Font(const std::string& family, int Weight = 0, bool italic = false);

    void setHeight(int height);
    void setWidth(int width);
    void setBold(bool enable);
    void setItalic(bool enable);
    void setWeight(int weight);
    void setQuality(int Quality);
    void setFamily(const std::string& family);
    void setColor(const Color& color);

    const Color& color();

    int Height();
    int Width();
    bool Bold();
    bool Italic();
    int Weight();
    int Quality();
    std::string Family();

private:
    int32      lfHeight = 0;            //�ַ���ƽ���߶�
    int32      lfWidth = 0;             //�ַ���ƽ�����(0 ��ʾ����Ӧ)
    int32      lfEscapement = 0;        //�ַ�������д�Ƕ�(��λ 0.1 ��)��
    int32      lfOrientation = 0;       //ÿ���ַ�����д�Ƕ�(��λ 0.1 ��)��
    int32      lfWeight = 0;            //�ַ��ıʻ���ϸ(0 ��ʾĬ�ϴ�ϸ)��
    Byte      lfItalic = 0;             //�Ƿ�б�壻
    Byte      lfUnderline = 0;          //�Ƿ��»��ߣ�
    Byte      lfStrikeOut = 0;          //�Ƿ�ɾ����
    Byte      lfCharSet = 0;            //ָ���ַ�����
    Byte      lfOutPrecision = 0;       //ָ�����ֵ�������ȣ�
    Byte      lfClipPrecision = 0;      //ָ�����ֵļ������ȣ�
    Byte      lfQuality = 0;            //ָ�����ֵ����������
    Byte      lfPitchAndFamily = 0;     //ָ���Գ��淽ʽ�������������ϵ�С�
    char      lfFaceName[32] = { 0 };   //��������
    Color     lfcolor;
};