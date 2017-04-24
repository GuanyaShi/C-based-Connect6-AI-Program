#include <stdio.h>
#include <graphics.h>
#include <conio.h>

struct Point
{
	int x;
	int y;
	int step;
};

void show1(int(*xc)[20], Point(*b)[20])
{
	for (int i = 0; i<20; i++)
	{
		for (int j = 0; j<20; j++)
		{
			b[i][j].x = 40 * j;
			b[i][j].y = 40 * i;
		}
	}
	int i, j;
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 2, 0, 0);
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			if (xc[i][j] == 2)
			{
				setfillcolor(BLACK);
				fillcircle(b[i][j].x, b[i][j].y, 15);
			}
			else if (xc[i][j] == 1)
			{
				setfillcolor(WHITE);
				fillcircle(b[i][j].x, b[i][j].y, 15);
			}
		}
	}
}
