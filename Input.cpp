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
		if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 40 && m.x <= 760 && m.y >= 40 && m.y <= 760)//����
		{
			x = (m.x+20) / 40;
			y = (m.y+20) / 40;
			return 100*x+y;
			break;
		}
		else if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 800 && m.x <= 960 && m.y >= 40 && m.y <= 80)//�¿���
		{
			return 22222;
			break;
		}
		else if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 800 && m.x <= 960 && m.y >= 120 && m.y <= 160)//����
		{
			return 33333;
			break;
		}
		else if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 800 && m.x <= 960 && m.y >= 200 && m.y <= 240)//����
		{
			return 44444;
			break;
		}
		else if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 800 && m.x <= 960 && m.y >= 280 && m.y <= 320)//��ģʽ
		{
			return 55555;
			break;
		}
		else if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 800 && m.x <= 960 && m.y >= 360 && m.y <= 400)//����
		{
			return 66666;
			break;
		}
	}
}