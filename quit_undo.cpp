#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int quit_undo()
{
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 320 && m.x <= 480 && m.y >= 460 && m.y <= 500)
		{
			return 1;
			break;
		}
	}
}