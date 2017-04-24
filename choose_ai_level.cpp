#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int choose_ai()
{
	void choose_ai0();
	choose_ai0();
	MOUSEMSG m1;
	while (true)
	{
		m1 = GetMouseMsg();
		if (m1.uMsg == WM_LBUTTONDOWN && m1.x > 240 && m1.x < 340 && m1.y > 410 && m1.y < 450)
			return 1;
		if (m1.uMsg == WM_LBUTTONDOWN && m1.x > 350 && m1.x < 450 && m1.y > 410 && m1.y < 450)
			return 2;
		if (m1.uMsg == WM_LBUTTONDOWN && m1.x > 460 && m1.x < 560 && m1.y > 410 && m1.y < 450)
			return 3;
	}
}