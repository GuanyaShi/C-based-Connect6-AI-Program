#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void draw()
{
	setfillcolor(RED);
	setbkcolor(RED);
	settextcolor(WHITE);
	settextstyle(30, 0, _T("Î¢ÈíÑÅºÚ"));
	RECT draw = { 800, 480, 960, 560 };
	solidroundrect(800, 480, 960, 560, 10, 10);
	drawtext(_T("Æ½¾Ö£¡"), &draw, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}