#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void black_win()
{
	setfillcolor(RED);
	setbkcolor(RED);
	settextcolor(WHITE);
	settextstyle(30, 0, _T("Î¢ÈíÑÅºÚ"));
	RECT b_win = { 800, 480, 960, 560 };
	solidroundrect(800, 480, 960, 560, 10, 10);
	drawtext(_T("ºÚ·½»ñÊ¤£¡"), &b_win, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}