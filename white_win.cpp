#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void white_win()
{
	setfillcolor(RED);
	setbkcolor(RED);
	settextcolor(WHITE);
	settextstyle(30, 0, _T("Î¢ÈíÑÅºÚ"));
	solidroundrect(800, 480, 960, 560, 10, 10);
	RECT w_win = { 800, 480, 960, 560 };
	drawtext(_T("°×·½»ñÊ¤£¡"), &w_win, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}