#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void help()
{
	setfillcolor(RGB(200, 200, 200));
	setcolor(0);
	setbkcolor(RGB(200, 200, 200));
	fillrectangle(120, 280, 680, 520);
	setfont(30, 0, _T("����"));
	RECT r8 = { 120, 300, 680, 350 };
	drawtext(_T("������ִ����������һ�����ӣ��˺�ÿ"), &r8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r9 = { 120, 350, 680, 400 };
	drawtext(_T("��ÿ�غ����������ӣ��ںᡢ����Խ�"), &r9, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r10 = { 120, 400, 680, 450 };
	drawtext(_T("���������������߻�ʤ��"), &r10, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	setfillcolor(YELLOW);
	setbkcolor(YELLOW);
	fillroundrect(350, 460, 450, 500, 10, 10);
	RECT r11 = { 350, 460, 450, 500 };
	drawtext(_T("�ر�"), &r11, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}