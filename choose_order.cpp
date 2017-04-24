#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int choose_order()
{
	void choose_order0();
	choose_order0();
	MOUSEMSG m1;
	while (true)
	{
		m1 = GetMouseMsg();
		if (m1.uMsg == WM_LBUTTONDOWN && m1.x > 240 && m1.x < 390 && m1.y > 410 && m1.y < 450)
			return 1;
		if (m1.uMsg == WM_LBUTTONDOWN && m1.x > 420 && m1.x < 560 && m1.y > 410 && m1.y < 450)
			return 2;
	}
}