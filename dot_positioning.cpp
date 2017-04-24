#include <stdio.h>
#include <graphics.h>
#include <conio.h>

struct Point
{
	int x;
	int y;
	int step;
};

void dot(Point(*b)[20],int *pass)
{
	for (int i = 0; i<20; i++)
	{
		for (int j = 0; j<20; j++)
		{
			b[i][j].x = 40 * j ;
			b[i][j].y = 40 * i ;
		}
	}
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{
			if (b[i][j].step == *pass-2 || b[i][j].step == *pass-1)
			{
				setfillcolor(RED);
				solidcircle(b[i][j].x, b[i][j].y, 5);
			}
		}
	}
}
