#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void chessboard()
{
	//显示屏幕
	initgraph(1000, 800);
	setfillcolor(YELLOW);
	solidrectangle(0, 0, 1000, 800);
    //显示棋盘
	setfillcolor(RGB(254, 212, 65));
	setcolor(0);
	fillrectangle(40, 40, 760, 760);
	//画线（黑色）19X19
	setlinecolor(BLACK);
	for (int i = 1; i < 20; i++)
	{
		line(40 * i, 40, 40 * i, 760);
		line(40, 40 + 40 * i, 760, 40 + 40 * i);
	}
	setfillcolor(BLUE);
	setbkcolor(BLUE);
	settextcolor(WHITE);
	settextstyle(25, 0, _T("微软雅黑"));
	solidroundrect(800, 40, 960, 80, 10, 10);
	RECT replay = { 800, 40, 960, 80 };
	drawtext(_T("再战一盘！"), &replay, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	solidroundrect(800, 120, 960, 160, 10, 10);
	RECT undo = { 800, 120, 960, 160 };
	drawtext(_T("我后悔了！"), &undo, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	solidroundrect(800, 200, 960, 240, 10, 10);
	RECT exit = { 800, 200, 960, 240 };
	drawtext(_T("我不玩了！"), &exit, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	solidroundrect(800, 280, 960, 320, 10, 10);
	RECT mode= { 800, 280, 960, 320 };
	drawtext(_T("换个模式！"), &mode, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	solidroundrect(800, 360, 960,400, 10, 10);
	RECT help = { 800, 360, 960, 400 };
	drawtext(_T("怎么玩呀？"), &help, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}