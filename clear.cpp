#include <stdio.h>

struct Point
{
	int x;
	int y;
	int step;
};

void clear(int(*a)[20],Point (*b)[20])
{
	int i, j;
	for (i = 0; i < 20; i++)
	for (j = 0; j < 20; j++)
		a[i][j] = 0;

	for (i = 0; i < 20; i++)
	for (j = 0; j < 20; j++)
		b[i][j].step = 0;
}