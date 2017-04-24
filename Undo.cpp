#include <stdio.h>
#include <graphics.h>
#include <conio.h>

struct Point
{
	int x;
	int y;
	int step;
};

void undo(Point (*b)[20], int(*xc)[20], int *pass)
{
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 20; j++)
		{

			if (b[i][j].step == *pass)
			{
				xc[i][j] = 0;
				b[i][j].step = 0;
			}
		}
	}
	*pass = *pass - 1;
}