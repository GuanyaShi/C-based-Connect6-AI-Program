#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void no_undo()
{
	setcolor(0);
	setfillcolor(BLUE);
	setbkcolor(BLUE);
	settextcolor(WHITE);
	int points[] = { 200, 280, 200, 520, 600, 520, 600, 280 };
	fillpoly(4, points);
	settextstyle(28, 0, _T("΢���ź�"));
	RECT r1 = { 200, 320, 600, 340 };
	drawtext(_T("������˼���Ѷȹ��ڼ�"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(33, 0, _T("����"));
	RECT r2 = { 200, 340, 600, 460 };
	drawtext(_T("��֧�ֻ���Ӵ~ - _,-!!!"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	setfillcolor(YELLOW);
	setbkcolor(YELLOW);
	fillroundrect(320, 460, 480, 500, 20, 20);
	setcolor(0);
	settextstyle(24, 0, _T("΢���ź�"));
	RECT r3 = { 320, 460, 480, 500 };
	drawtext(_T("�ǺǼ�����ɡ���"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}