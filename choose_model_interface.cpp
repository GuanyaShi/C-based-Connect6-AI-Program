#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void choose0()
{
	setcolor(0);
	setfillcolor(BLUE);
	setbkcolor(BLUE);
	settextcolor(WHITE);
	settextstyle(36, 0, _T("΢���ź�"));
	int points[] = { 200, 280, 200, 480, 600, 480, 600, 280 };
	fillpoly(4, points);
	RECT r = { 240, 300, 560, 380 };
	drawtext(_T("��ѡ���սģʽ��"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(25, 0, _T("΢���ź�"));
	setfillcolor(WHITE);
	setbkcolor(WHITE);
	settextcolor(BLACK);
	fillrectangle(240, 410, 390, 450);
	fillrectangle(420, 410, 560, 450);
	RECT r1 = { 240, 410, 390, 450 };
	drawtext(_T("���˶�ս"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r2 = { 420, 410, 560, 450 };
	drawtext(_T("�˻���ս"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}