#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void help()
{
	setfillcolor(RGB(200, 200, 200));
	setcolor(0);
	setbkcolor(RGB(200, 200, 200));
	fillrectangle(120, 280, 680, 520);
	setfont(30, 0, _T("隶书"));
	RECT r8 = { 120, 300, 680, 350 };
	drawtext(_T("帮助：执黑子者先下一颗棋子，此后每"), &r8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r9 = { 120, 350, 680, 400 };
	drawtext(_T("人每回合下两颗棋子，在横、竖或对角"), &r9, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r10 = { 120, 400, 680, 450 };
	drawtext(_T("方向先连成六子者获胜。"), &r10, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	setfillcolor(YELLOW);
	setbkcolor(YELLOW);
	fillroundrect(350, 460, 450, 500, 10, 10);
	RECT r11 = { 350, 460, 450, 500 };
	drawtext(_T("关闭"), &r11, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}