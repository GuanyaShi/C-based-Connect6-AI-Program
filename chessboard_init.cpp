#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void chessboard()
{
	//��ʾ��Ļ
	initgraph(1000, 800);
	setfillcolor(YELLOW);
	solidrectangle(0, 0, 1000, 800);
    //��ʾ����
	setfillcolor(RGB(254, 212, 65));
	setcolor(0);
	fillrectangle(40, 40, 760, 760);
	//���ߣ���ɫ��19X19
	setlinecolor(BLACK);
	for (int i = 1; i < 20; i++)
	{
		line(40 * i, 40, 40 * i, 760);
		line(40, 40 + 40 * i, 760, 40 + 40 * i);
	}
	setfillcolor(BLUE);
	setbkcolor(BLUE);
	settextcolor(WHITE);
	settextstyle(25, 0, _T("΢���ź�"));
	solidroundrect(800, 40, 960, 80, 10, 10);
	RECT replay = { 800, 40, 960, 80 };
	drawtext(_T("��սһ�̣�"), &replay, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	solidroundrect(800, 120, 960, 160, 10, 10);
	RECT undo = { 800, 120, 960, 160 };
	drawtext(_T("�Һ���ˣ�"), &undo, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	solidroundrect(800, 200, 960, 240, 10, 10);
	RECT exit = { 800, 200, 960, 240 };
	drawtext(_T("�Ҳ����ˣ�"), &exit, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	solidroundrect(800, 280, 960, 320, 10, 10);
	RECT mode= { 800, 280, 960, 320 };
	drawtext(_T("����ģʽ��"), &mode, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	solidroundrect(800, 360, 960,400, 10, 10);
	RECT help = { 800, 360, 960, 400 };
	drawtext(_T("��ô��ѽ��"), &help, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}