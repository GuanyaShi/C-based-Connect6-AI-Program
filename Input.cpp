#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int input()
{
	int x, y;
	MOUSEMSG m;
	while (true)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 40 && m.x <= 760 && m.y >= 40 && m.y <= 760)//棋盘
		{
			x = (m.x+20) / 40;
			y = (m.y+20) / 40;
			return 100*x+y;
			break;
		}
		else if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 800 && m.x <= 960 && m.y >= 40 && m.y <= 80)//新开局
		{
			return 22222;
			break;
		}
		else if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 800 && m.x <= 960 && m.y >= 120 && m.y <= 160)//悔棋
		{
			return 33333;
			break;
		}
		else if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 800 && m.x <= 960 && m.y >= 200 && m.y <= 240)//认输
		{
			return 44444;
			break;
		}
		else if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 800 && m.x <= 960 && m.y >= 280 && m.y <= 320)//换模式
		{
			return 55555;
			break;
		}
		else if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 800 && m.x <= 960 && m.y >= 360 && m.y <= 400)//帮助
		{
			return 66666;
			break;
		}
	}
}