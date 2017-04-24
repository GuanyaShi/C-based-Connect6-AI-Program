#include <graphics.h>
#include <conio.h>

struct Point
{
	int x;
	int y;
};

void show_com(int xm, int ym)
{
	//结构体赋值
	struct Point a[20][20];
	for (int i = 0; i<20; i++)
	{
		for (int j = 0; j<20; j++)
		{
			a[i][j].x = 40 * j ;
			a[i][j].y = 40 * i ;
		}
	}
	fillcircle(a[xm][ym].x, a[xm][ym].y, 15);
}

void AI_xian(int(*xc)[20], int *pass)
{
	//确定填充颜色为白色
	setfillcolor(WHITE);
	//chess代表现在AI下了几步棋了
	int chess;
	chess = 0;
	//起手*****************************************************************************************************************
	if (*pass == 2)
	{
		for (int i = 1; i<20; i++)
		for (int j = 1; j<20; j++)
		{
			if (xc[i][j] == 1)
			{
				show_com(i, j - 1);
				show_com(i + 1, j);
				xc[i][j - 1] = 2;
				xc[i + 1][j] = 2;
				*pass = *pass + 2;
				return;
			}
		}
	}
	if (*pass <= 7)
	{
		for (int i = 2; i<20; i++)
		for (int j = 3; j<20; j++)
		{
			if (xc[i][j] == 1 && xc[i][j - 1] == 2 && xc[i + 1][j] == 2 && xc[i - 1][j - 1] == 1 && xc[i - 1][j - 2] == 1)
			{
				show_com(i - 1, j);
				show_com(i + 1, j + 1);
				xc[i - 1][j] = 2;
				xc[i + 1][j + 1] = 2;
				*pass = *pass + 2;
				return;
			}
		}
	}

	//*******************************五子进攻之0XXXXX或XXXXX0**************************************************************
	//****横*****
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			if (xc[i][j] == 0 && xc[i][j + 1] == 2 && xc[i][j + 2] == 2 && xc[i][j + 3] == 2 && xc[i][j + 4] == 2 && xc[i][j + 5] == 2)
			{
				show_com(i, j);
				xc[i][j] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (xc[i][j] == 2 && xc[i][j + 1] == 2 && xc[i][j + 2] == 2 && xc[i][j + 3] == 2 && xc[i][j + 4] == 2 && xc[i][j + 5] == 0)
			{
				show_com(i, j + 5);
				xc[i][j + 5] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}
	//******竖******
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			if (xc[j][i] == 0 && xc[j + 1][i] == 2 && xc[j + 2][i] == 2 && xc[j + 3][i] == 2 && xc[j + 4][i] == 2 && xc[j + 5][i] == 2)
			{
				show_com(j, i);
				xc[j][i] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (xc[j][i] == 2 && xc[j + 1][i] == 2 && xc[j + 2][i] == 2 && xc[j + 3][i] == 2 && xc[j + 4][i] == 2 && xc[j + 5][i] == 0)
			{
				show_com(j + 5, i);
				xc[j + 5][i] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}
	//****‘\’斜*******
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			if (xc[j][j + i - 1] == 0 && xc[j + 1][i + j] == 2 && xc[j + 2][i + j + 1] == 2 && xc[j + 3][i + j + 2] == 2 && xc[j + 4][i + j + 3] == 2 && xc[j + 5][j + i + 4] == 2)
			{
				show_com(j, j + i - 1);
				xc[j][j + i - 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (xc[j][j + i - 1] == 2 && xc[j + 1][i + j] == 2 && xc[j + 2][i + j + 1] == 2 && xc[j + 3][i + j + 2] == 2 && xc[j + 4][i + j + 3] == 2 && xc[j + 5][j + i + 4] == 0)
			{
				show_com(j + 5, j + i + 4);
				xc[j + 5][j + i + 4] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (xc[j + i - 1][j] == 2 && xc[j + i][j + 1] == 2 && xc[j + i + 1][j + 2] == 2 && xc[j + i + 2][j + 3] == 2 && xc[j + i + 3][j + 4] == 2 && xc[j + i + 4][j + 5] == 0)
			{
				show_com(i + j + 4, j + 5);
				xc[i + j + 4][j + 5] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (xc[j + i - 1][j] == 0 && xc[j + i][j + 1] == 2 && xc[j + i + 1][j + 2] == 2 && xc[j + i + 2][j + 3] == 2 && xc[j + i + 3][j + 4] == 2 && xc[j + i + 4][j + 5] == 2)
			{
				show_com(i + j - 1, j);
				xc[i + j - 1][j] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}
	//******'/'斜******
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			if (xc[20 - j][j + i - 1] == 0 && xc[19 - j][i + j] == 2 && xc[18 - j][i + j + 1] == 2 && xc[17 - j][i + j + 2] == 2 && xc[16 - j][i + j + 3] == 2 && xc[15 - j][j + i + 4] == 2)
			{
				show_com(20 - j, j + i - 1);
				xc[20 - j][j + i - 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (xc[20 - j][j + i - 1] == 2 && xc[19 - j][i + j] == 2 && xc[18 - j][i + j + 1] == 2 && xc[17 - j][i + j + 2] == 2 && xc[16 - j][i + j + 3] == 2 && xc[15 - j][j + i + 4] == 0)
			{
				show_com(15 - j, j + i + 4);
				xc[15 - j][j + i + 4] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (xc[20 - (j + i - 1)][j] == 2 && xc[20 - (j + i)][j + 1] == 2 && xc[20 - (j + i + 1)][j + 2] == 2 && xc[20 - (j + i + 2)][j + 3] == 2 && xc[20 - (j + i + 3)][j + 4] == 2 && xc[20 - (j + i + 4)][j + 5] == 0)
			{
				show_com(20 - (i + j + 4), j + 5);
				xc[20 - (i + j + 4)][j + 5] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (xc[20 - (j + i - 1)][j] == 0 && xc[20 - (j + i)][j + 1] == 2 && xc[20 - (j + i + 1)][j + 2] == 2 && xc[20 - (j + i + 2)][j + 3] == 2 && xc[20 - (j + i + 3)][j + 4] == 2 && xc[20 - (j + i + 4)][j + 5] == 2)
			{
				show_com(20 - (i + j - 1), j);
				xc[20 - (i + j - 1)][j] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}

	int s, k;//s代表6子中有多少个白子，k代表有多少个空子

	//******五子与四子必杀进攻***************************************************************************
	//***************************************************************************************************
	//***************************************************************************************************

	//**********横***********************************************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[i][j] + xc[i][j + 1] + xc[i][j + 2] + xc[i][j + 3] + xc[i][j + 4] + xc[i][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[i][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//**********************五子必杀进攻*********************************************
			if (s == 10 && k == 1)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[i][j + i1] == 0)
					{
						show_com(i, j + i1);
						xc[i][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
			//**********************四子必杀进攻********************************************
			if (s == 8 && k == 2)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[i][j + i1] == 0)
					{
						show_com(i, j + i1);
						xc[i][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//********竖，五子与四子必杀进攻***********************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[j][i] + xc[j + 1][i] + xc[j + 2][i] + xc[j + 3][i] + xc[j + 4][i] + xc[j + 5][i];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][i] == 0)
				{
					k = k + 1;
				}
			}
			//**********************五子必杀进攻*********************************************
			if (s == 10 && k == 1)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[j + i1][i] == 0)
					{
						show_com(j + i1, i);
						xc[j + i1][i] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
			//**********************四子必杀进攻********************************************
			if (s == 8 && k == 2)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[j + i1][i] == 0)
					{
						show_com(j + i1, i);
						xc[j + i1][i] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//**********'\'斜五子与四子必杀进攻********************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			//***************‘\’上方*************************
			s = xc[j][j + i - 1] + xc[j + 1][i + j] + xc[j + 2][i + j + 1] + xc[j + 3][i + j + 2] + xc[j + 4][i + j + 3] + xc[j + 5][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************五子必杀***********************
			if (s == 10 && k == 1)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[j + i1][j + i - 1 + i1] == 0)
					{
						show_com(j + i1, j + i - 1 + i1);
						xc[j + i1][j + i - 1 + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
			//*************四子必杀***********************
			if (s == 8 && k == 2)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[j + i1][j + i - 1 + i1] == 0)
					{
						show_com(j + i1, j + i - 1 + i1);
						xc[j + i1][j + i - 1 + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
			//**********‘\’下方***************
			s = xc[j + i - 1][j] + xc[j + i][j + 1] + xc[j + i + 1][j + 2] + xc[j + i + 2][j + 3] + xc[j + i + 3][j + 4] + xc[j + i + 4][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i - 1 + i1][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************五子必杀***********************
			if (s == 10 && k == 1)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[j + i - 1 + i1][j + i1] == 0)
					{
						show_com(j + i - 1 + i1, j + i1);
						xc[j + i - 1 + i1][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
			//*************四子必杀***********************
			if (s == 8 && k == 2)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[j + i - 1 + i1][j + i1] == 0)
					{
						show_com(j + i - 1 + i1, j + i1);
						xc[j + i - 1 + i1][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}
	//**********'/'斜五子与四子必杀进攻********************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			//***************‘/’上方*************************
			s = xc[20 - j][j + i - 1] + xc[20 - (j + 1)][i + j] + xc[20 - (j + 2)][i + j + 1] + xc[20 - (j + 3)][i + j + 2] + xc[20 - (j + 4)][i + j + 3] + xc[20 - (j + 5)][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i1)][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************五子必杀***********************
			if (s == 10 && k == 1)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[20 - (j + i1)][j + i - 1 + i1] == 0)
					{
						show_com(20 - (j + i1), j + i - 1 + i1);
						xc[20 - (j + i1)][j + i - 1 + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
			//*************四子必杀***********************
			if (s == 8 && k == 2)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[20 - (j + i1)][j + i - 1 + i1] == 0)
					{
						show_com(20 - (j + i1), j + i - 1 + i1);
						xc[20 - (j + i1)][j + i - 1 + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
			//**********‘\’下方***************
			s = xc[20 - (j + i - 1)][j] + xc[20 - (j + i)][j + 1] + xc[20 - (j + i + 1)][j + 2] + xc[20 - (j + i + 2)][j + 3] + xc[20 - (j + i + 3)][j + 4] + xc[20 - (j + i + 4)][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i - 1 + i1)][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************五子必杀***********************
			if (s == 10 && k == 1)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[20 - (j + i - 1 + i1)][j + i1] == 0)
					{
						show_com(20 - (j + i - 1 + i1), j + i1);
						xc[20 - (j + i - 1 + i1)][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
			//*************四子必杀***********************
			if (s == 8 && k == 2)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[20 - (j + i - 1 + i1)][j + i1] == 0)
					{
						show_com(20 - (j + i - 1 + i1), j + i1);
						xc[20 - (j + i - 1 + i1)][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}
	//******(7,5)必须防御********************************************************************
	//***************************************************************************************
	//***************************************************************************************

	//******横**********************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 13; j++)
		{
			s = xc[i][j] + xc[i][j + 1] + xc[i][j + 2] + xc[i][j + 3] + xc[i][j + 4] + xc[i][j + 5] + xc[i][j + 6];
			k = 0;

			for (int i1 = 0; i1 <= 6; i1++)
			{
				if (xc[i][j + i1] == 0)
				{
					k = k + 1;
				}
			}

			//******（7,5）防御*****************
			if (s == 5 && k == 2 && xc[i][j] == 0 && xc[i][j + 6] == 0)
			{
				show_com(i, j);
				xc[i][j] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(i, j + 6);
				xc[i][j + 6] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}
	//*********竖*****************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 13; j++)
		{
			s = xc[j][i] + xc[j + 1][i] + xc[j + 2][i] + xc[j + 3][i] + xc[j + 4][i] + xc[j + 5][i] + xc[j + 6][i];
			k = 0;

			for (int i1 = 0; i1 <= 6; i1++)
			{
				if (xc[j + i1][i] == 0)
				{
					k = k + 1;
				}
			}

			//******（7,5）防御*****************
			if (s == 5 && k == 2 && xc[j][i] == 0 && xc[j + 6][i] == 0)
			{
				show_com(j, i);
				xc[j][i] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(j + 6, i);
				xc[j + 6][i] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}

	//*********'\'斜************
	for (int i = 1; i <= 13; i++)
	{
		for (int j = 1; j <= 14 - i; j++)
		{
			//*********右上******************************
			s = xc[j][i + j - 1] + xc[j + 1][i + j] + xc[j + 2][i + j + 1] + xc[j + 3][i + j + 2] + xc[j + 4][i + j + 3] + xc[j + 5][i + j + 4] + xc[j + 6][i + j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 6; i1++)
			{
				if (xc[j + i1][i + j - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*********(7,5)防御*************
			if (s == 5 && k == 2 && xc[j][i + j - 1] == 0 && xc[j + 6][i + j + 5] == 0)
			{
				show_com(j, i + j - 1);
				xc[j][i + j - 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(j + 6, i + j + 5);
				xc[j + 6][i + j + 5] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			//************左下******************************
			s = xc[i + j - 1][j] + xc[i + j][j + 1] + xc[i + j + 1][j + 2] + xc[i + j + 2][j + 3] + xc[i + j + 3][j + 4] + xc[i + j + 4][j + 5] + xc[i + j + 5][j + 6];
			k = 0;

			for (int i1 = 0; i1 <= 6; i1++)
			{
				if (xc[i + j - 1 + i1][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*********(7,5)防御*************
			if (s == 5 && k == 2 && xc[i + j - 1][j] == 0 && xc[i + j + 5][j + 6] == 0)
			{
				show_com(i + j - 1, j);
				xc[i + j - 1][j] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(i + j + 5, j + 6);
				xc[i + j + 5][j + 6] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}

	//***********'/'斜***************
	for (int i = 1; i <= 13; i++)
	{
		for (int j = 1; j <= 14 - i; j++)
		{
			//*********右上******************************
			s = xc[20 - j][i + j - 1] + xc[19 - j][i + j] + xc[18 - j][i + j + 1] + xc[17 - j][i + j + 2] + xc[16 - j][i + j + 3] + xc[15 - j][i + j + 4] + xc[14 - j][i + j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 6; i1++)
			{
				if (xc[20 - (j + i1)][i + j - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*********(7,5)防御*************
			if (s == 5 && k == 2 && xc[20 - j][i + j - 1] == 0 && xc[14 - j][i + j + 5] == 0)
			{
				show_com(20 - j, i + j - 1);
				xc[20 - j][i + j - 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(14 - j, i + j + 5);
				xc[14 - j][i + j + 5] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			//************左下******************************
			s = xc[20 - (i + j - 1)][j] + xc[20 - (i + j)][j + 1] + xc[20 - (i + j + 1)][j + 2] + xc[20 - (i + j + 2)][j + 3] + xc[20 - (i + j + 3)][j + 4] + xc[20 - (i + j + 4)][j + 5] + xc[20 - (i + j + 5)][j + 6];
			k = 0;

			for (int i1 = 0; i1 <= 6; i1++)
			{
				if (xc[20 - (i + j - 1 + i1)][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*********(7,5)防御*************
			if (s == 5 && k == 2 && xc[20 - (i + j - 1)][j] == 0 && xc[20 - (i + j + 5)][j + 6] == 0)
			{
				show_com(20 - (i + j - 1), j);
				xc[20 - (i + j - 1)][j] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(20 - (i + j + 5), j + 6);
				xc[20 - (i + j + 5)][j + 6] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}

	//****************************(8,4)(8,5)防御*****************************************************
	//***********************************************************************************************
	//***********************************************************************************************

	//**********横*************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 12; j++)
		{
			s = xc[i][j] + xc[i][j + 1] + xc[i][j + 2] + xc[i][j + 3] + xc[i][j + 4] + xc[i][j + 5] + xc[i][j + 6] + xc[i][j + 7];
			k = 0;

			for (int i1 = 0; i1 <= 7; i1++)
			{
				if (xc[i][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//********（8,4）防御**************************************
			if (s == 4 && k == 4 && xc[i][j] == 0 && xc[i][j + 1] == 0 && xc[i][j + 6] == 0 && xc[i][j + 7] == 0)
			{
				show_com(i, j + 1);
				xc[i][j + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(i, j + 6);
				xc[i][j + 6] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			//*******(8,5)防御一***************************************
			if (s == 5 && k == 3 && xc[i][j + 1] == 0 && xc[i][j + 6] == 0 && xc[i][j + 7] == 0)
			{
				show_com(i, j + 1);
				xc[i][j + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(i, j + 6);
				xc[i][j + 6] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			//*******(8,5)防御二**************************************
			if (s == 5 && k == 3 && xc[i][j] == 0 && xc[i][j + 1] == 0 && xc[i][j + 6] == 0)
			{
				show_com(i, j + 1);
				xc[i][j + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(i, j + 6);
				xc[i][j + 6] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}

	//**********竖***************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 12; j++)
		{
			s = xc[j][i] + xc[j + 1][i] + xc[j + 2][i] + xc[j + 3][i] + xc[j + 4][i] + xc[j + 5][i] + xc[j + 6][i] + xc[j + 7][i];
			k = 0;

			for (int i1 = 0; i1 <= 7; i1++)
			{
				if (xc[j + i1][i] == 0)
				{
					k = k + 1;
				}
			}
			//********（8,4）防御**************************************
			if (s == 4 && k == 4 && xc[j][i] == 0 && xc[j + 1][i] == 0 && xc[j + 6][i] == 0 && xc[j + 7][i] == 0)
			{
				show_com(j + 1, i);
				xc[j + 1][i] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(j + 6, i);
				xc[j + 6][i] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			//*******(8,5)防御一***************************************
			if (s == 5 && k == 3 && xc[j + 1][i] == 0 && xc[j + 6][i] == 0 && xc[j + 7][i] == 0)
			{
				show_com(j + 1, i);
				xc[j + 1][i] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(j + 6, i);
				xc[j + 6][i] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			//*******(8,5)防御二**************************************
			if (s == 5 && k == 3 && xc[j][i] == 0 && xc[j + 1][i] == 0 && xc[j + 6][i] == 0)
			{
				show_com(j + 1, i);
				xc[j + 1][i] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(j + 6, i);
				xc[j + 6][i] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}

	//*********'\'斜****************
	for (int i = 1; i <= 12; i++)
	{
		for (int j = 1; j <= 13 - i; j++)
		{
			//*********右上******************************
			s = xc[j][i + j - 1] + xc[j + 1][i + j] + xc[j + 2][i + j + 1] + xc[j + 3][i + j + 2] + xc[j + 4][i + j + 3] + xc[j + 5][i + j + 4] + xc[j + 6][i + j + 5] + xc[j + 7][i + j + 6];
			k = 0;

			for (int i1 = 0; i1 <= 7; i1++)
			{
				if (xc[j + i1][i + j - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//********(8,4)防御**************************
			if (s == 4 && k == 4 && xc[j][i + j - 1] == 0 && xc[j + 1][i + j] == 0 && xc[j + 6][i + j + 5] == 0 && xc[j + 7][i + j + 6] == 0)
			{
				show_com(j + 1, i + j);
				xc[j + 1][i + j] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(j + 6, i + j + 5);
				xc[j + 6][i + j + 5] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			//*******(8,5)防御一**************************
			if (s == 5 && k == 3 && xc[i + 1][i + j] == 0 && xc[j + 6][i + j + 5] == 0 && xc[j + 7][i + j + 6] == 0)
			{
				show_com(j + 1, i + j);
				xc[j + 1][i + j] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(j + 6, i + j + 5);
				xc[j + 6][i + j + 5] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			//*******(8,5)防御二*************************
			if (s == 5 && k == 3 && xc[i][i + j - 1] == 0 && xc[i + 1][i + j] == 0 && xc[j + 6][i + j + 5] == 0)
			{
				show_com(j + 1, i + j);
				xc[j + 1][i + j] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(j + 6, i + j + 5);
				xc[j + 6][i + j + 5] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}

			//**********左下*********************************
			s = xc[i + j - 1][j] + xc[i + j][j + 1] + xc[i + j + 1][j + 2] + xc[i + j + 2][j + 3] + xc[i + j + 3][j + 4] + xc[i + j + 4][j + 5] + xc[i + j + 5][j + 6] + xc[i + j + 6][j + 7];
			k = 0;

			for (int i1 = 0; i1 <= 7; i1++)
			{
				if (xc[i + j - 1 + i1][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//********(8,4)防御**************************
			if (s == 4 && k == 4 && xc[i + j - 1][j] == 0 && xc[i + j][j + 1] == 0 && xc[i + j + 5][j + 6] == 0 && xc[i + j + 6][j + 7] == 0)
			{
				show_com(i + j, j + 1);
				xc[i + j][j + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(i + j + 5, j + 6);
				xc[i + j + 5][j + 6] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			//*******(8,5)防御一**************************
			if (s == 5 && k == 3 && xc[i + j][j + 1] == 0 && xc[i + j + 5][j + 6] == 0 && xc[i + j + 6][j + 7] == 0)
			{
				show_com(i + j, j + 1);
				xc[i + j][j + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(i + j + 5, j + 6);
				xc[i + j + 5][j + 6] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			//*******(8,5)防御二*************************
			if (s == 5 && k == 3 && xc[i + j - 1][j] == 0 && xc[i + j][j + 1] == 0 && xc[i + j + 5][j + 6] == 0)
			{
				show_com(i + j, j + 1);
				xc[i + j][j + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(i + j + 5, j + 6);
				xc[i + j + 5][j + 6] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}

	//*********'/'斜****************
	for (int i = 1; i <= 12; i++)
	{
		for (int j = 1; j <= 13 - i; j++)
		{
			//*********右上******************************
			s = xc[20 - j][i + j - 1] + xc[19 - j][i + j] + xc[18 - j][i + j + 1] + xc[17 - j][i + j + 2] + xc[16 - j][i + j + 3] + xc[15 - j][i + j + 4] + xc[14 - j][i + j + 5] + xc[13 - j][i + j + 6];
			k = 0;

			for (int i1 = 0; i1 <= 7; i1++)
			{
				if (xc[20 - (j + i1)][i + j - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//********(8,4)防御**************************
			if (s == 4 && k == 4 && xc[20 - j][i + j - 1] == 0 && xc[19 - j][i + j] == 0 && xc[14 - j][i + j + 5] == 0 && xc[13 - j][i + j + 6] == 0)
			{
				show_com(19 - j, i + j);
				xc[19 - j][i + j] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(14 - j, i + j + 5);
				xc[14 - j][i + j + 5] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			//*******(8,5)防御一**************************
			if (s == 5 && k == 3 && xc[19 - i][i + j] == 0 && xc[14 - j][i + j + 5] == 0 && xc[13 - j][i + j + 6] == 0)
			{
				show_com(19 - j, i + j);
				xc[19 - j][i + j] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(14 - j, i + j + 5);
				xc[14 - j][i + j + 5] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			//*******(8,5)防御二*************************
			if (s == 5 && k == 3 && xc[20 - i][i + j - 1] == 0 && xc[19 - i][i + j] == 0 && xc[14 - j][i + j + 5] == 0)
			{
				show_com(19 - j, i + j);
				xc[19 - j][i + j] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(14 - j, i + j + 5);
				xc[14 - j][i + j + 5] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}

			//**********左下*********************************
			s = xc[20 - (i + j - 1)][j] + xc[20 - (i + j)][j + 1] + xc[20 - (i + j + 1)][j + 2] + xc[20 - (i + j + 2)][j + 3] + xc[20 - (i + j + 3)][j + 4] + xc[20 - (i + j + 4)][j + 5] + xc[20 - (i + j + 5)][j + 6] + xc[20 - (i + j + 6)][j + 7];
			k = 0;

			for (int i1 = 0; i1 <= 7; i1++)
			{
				if (xc[20 - (i + j - 1 + i1)][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//********(8,4)防御**************************
			if (s == 4 && k == 4 && xc[20 - (i + j - 1)][j] == 0 && xc[20 - (i + j)][j + 1] == 0 && xc[20 - (i + j + 5)][j + 6] == 0 && xc[20 - (i + j + 6)][j + 7] == 0)
			{
				show_com(20 - (i + j), j + 1);
				xc[20 - (i + j)][j + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(20 - (i + j + 5), j + 6);
				xc[20 - (i + j + 5)][j + 6] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			//*******(8,5)防御一**************************
			if (s == 5 && k == 3 && xc[20 - (i + j)][j + 1] == 0 && xc[20 - (i + j + 5)][j + 6] == 0 && xc[20 - (i + j + 6)][j + 7] == 0)
			{
				show_com(20 - (i + j), j + 1);
				xc[20 - (i + j)][j + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(20 - (i + j + 5), j + 6);
				xc[20 - (i + j + 5)][j + 6] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			//*******(8,5)防御二*************************
			if (s == 5 && k == 3 && xc[20 - (i + j - 1)][j] == 0 && xc[20 - (i + j)][j + 1] == 0 && xc[20 - (i + j + 5)][j + 6] == 0)
			{
				show_com(20 - (i + j), j + 1);
				xc[20 - (i + j)][j + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
				show_com(20 - (i + j + 5), j + 6);
				xc[20 - (i + j + 5)][j + 6] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}

	//******(7,4)必须防御********************************************************************
	//***************************************************************************************
	//***************************************************************************************

	//******横**********************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 13; j++)
		{
			s = xc[i][j] + xc[i][j + 1] + xc[i][j + 2] + xc[i][j + 3] + xc[i][j + 4] + xc[i][j + 5] + xc[i][j + 6];
			k = 0;

			for (int i1 = 0; i1 <= 6; i1++)
			{
				if (xc[i][j + i1] == 0)
				{
					k = k + 1;
				}
			}

			//******（7,4）防御*****************
			if (s == 4 && k == 3 && xc[i][j] == 0 && xc[i][j + 5] == 0 && xc[i][j + 6] == 0)
			{
				show_com(i, j + 5);
				xc[i][j + 5] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 3 && xc[i][j] == 0 && xc[i][j + 1] == 0 && xc[i][j + 6] == 0)
			{
				show_com(i, j + 1);
				xc[i][j + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}
	//*********竖*****************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 13; j++)
		{
			s = xc[j][i] + xc[j + 1][i] + xc[j + 2][i] + xc[j + 3][i] + xc[j + 4][i] + xc[j + 5][i] + xc[j + 6][i];
			k = 0;

			for (int i1 = 0; i1 <= 6; i1++)
			{
				if (xc[j + i1][i] == 0)
				{
					k = k + 1;
				}
			}

			//******（7,4）防御*****************
			if (s == 4 && k == 3 && xc[j][i] == 0 && xc[j + 6][i] == 0 && xc[j + 5][i] == 0)
			{
				show_com(j + 5, i);
				xc[j + 5][i] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 3 && xc[j][i] == 0 && xc[j + 6][i] == 0 && xc[j + 1][i] == 0)
			{
				show_com(j + 1, i);
				xc[j + 1][i] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}

	//*********'\'斜************
	for (int i = 1; i <= 13; i++)
	{
		for (int j = 1; j <= 14 - i; j++)
		{
			//*********右上******************************
			s = xc[j][i + j - 1] + xc[j + 1][i + j] + xc[j + 2][i + j + 1] + xc[j + 3][i + j + 2] + xc[j + 4][i + j + 3] + xc[j + 5][i + j + 4] + xc[j + 6][i + j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 6; i1++)
			{
				if (xc[j + i1][i + j - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*********(7,4)防御*************
			if (s == 4 && k == 3 && xc[j][i + j - 1] == 0 && xc[j + 6][i + j + 5] == 0 && xc[j + 5][i + j + 4] == 0)
			{
				show_com(j + 5, i + j + 4);
				xc[j + 5][i + j + 4] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 3 && xc[j][i + j - 1] == 0 && xc[j + 6][i + j + 5] == 0 && xc[j + 1][i + j] == 0)
			{
				show_com(j + 1, i + j);
				xc[j + 1][i + j] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			//************左下******************************
			s = xc[i + j - 1][j] + xc[i + j][j + 1] + xc[i + j + 1][j + 2] + xc[i + j + 2][j + 3] + xc[i + j + 3][j + 4] + xc[i + j + 4][j + 5] + xc[i + j + 5][j + 6];
			k = 0;

			for (int i1 = 0; i1 <= 6; i1++)
			{
				if (xc[i + j - 1 + i1][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*********(7,4)防御*************
			if (s == 4 && k == 3 && xc[i + j - 1][j] == 0 && xc[i + j + 5][j + 6] == 0 && xc[i + j + 4][j + 5] == 0)
			{
				show_com(i + j + 4, j + 5);
				xc[i + j + 4][j + 5] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 3 && xc[i + j - 1][j] == 0 && xc[i + j + 5][j + 6] == 0 && xc[i + j][j + 1] == 0)
			{
				show_com(i + j, j + 1);
				xc[i + j][j + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}

	//***********'/'斜***************
	for (int i = 1; i <= 13; i++)
	{
		for (int j = 1; j <= 14 - i; j++)
		{
			//*********右上******************************
			s = xc[20 - j][i + j - 1] + xc[19 - j][i + j] + xc[18 - j][i + j + 1] + xc[17 - j][i + j + 2] + xc[16 - j][i + j + 3] + xc[15 - j][i + j + 4] + xc[14 - j][i + j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 6; i1++)
			{
				if (xc[20 - (j + i1)][i + j - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*********(7,4)防御*************
			if (s == 4 && k == 3 && xc[20 - j][i + j - 1] == 0 && xc[14 - j][i + j + 5] == 0 && xc[15 - j][i + j + 4] == 0)
			{
				show_com(15 - j, i + j + 4);
				xc[15 - j][i + j + 4] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 3 && xc[20 - j][i + j - 1] == 0 && xc[14 - j][i + j + 5] == 0 && xc[19 - j][i + j] == 0)
			{
				show_com(19 - j, i + j);
				xc[19 - j][i + j] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			//************左下******************************
			s = xc[20 - (i + j - 1)][j] + xc[20 - (i + j)][j + 1] + xc[20 - (i + j + 1)][j + 2] + xc[20 - (i + j + 2)][j + 3] + xc[20 - (i + j + 3)][j + 4] + xc[20 - (i + j + 4)][j + 5] + xc[20 - (i + j + 5)][j + 6];
			k = 0;

			for (int i1 = 0; i1 <= 6; i1++)
			{
				if (xc[20 - (i + j - 1 + i1)][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*********(7,4)防御*************
			if (s == 4 && k == 3 && xc[20 - (i + j - 1)][j] == 0 && xc[20 - (i + j + 5)][j + 6] == 0 && xc[20 - (i + j + 4)][j + 5] == 0)
			{
				show_com(20 - (i + j + 4), j + 5);
				xc[20 - (i + j + 4)][j + 5] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 3 && xc[20 - (i + j - 1)][j] == 0 && xc[20 - (i + j + 5)][j + 6] == 0 && xc[20 - (i + j)][j + 1] == 0)
			{
				show_com(20 - (i + j), j + 1);
				xc[20 - (i + j)][j + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}

	//************（6,4)防守*********************************************************************
	//*******************************************************************************************
	//*******************************************************************************************

	//**********横***********************************************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[i][j] + xc[i][j + 1] + xc[i][j + 2] + xc[i][j + 3] + xc[i][j + 4] + xc[i][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[i][j + i1] == 0)
				{
					k = k + 1;
				}
			}

			//**********************（6,4）防守*********************************************
			if (s == 4 && k == 2 && xc[i][j] == 0 && xc[i][j + 1] == 0)
			{
				show_com(i, j + 1);
				xc[i][j + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[i][j + 4] == 0 && xc[i][j + 5] == 0)
			{
				show_com(i, j + 4);
				xc[i][j + 4] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[i][j] == 0 && xc[i][j + 5] == 0)
			{
				show_com(i, j);
				xc[i][j] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}

	//********竖*************************************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[j][i] + xc[j + 1][i] + xc[j + 2][i] + xc[j + 3][i] + xc[j + 4][i] + xc[j + 5][i];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][i] == 0)
				{
					k = k + 1;
				}
			}

			//**********************（6,4）防守********************************************
			if (s == 4 && k == 2 && xc[j + 1][i] == 0 && xc[j][i] == 0)
			{
				show_com(j + 1, i);
				xc[j + 1][i] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[j + 4][i] == 0 && xc[j + 5][i] == 0)
			{
				show_com(j + 4, i);
				xc[j + 4][i] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[j + 5][i] == 0 && xc[j][i] == 0)
			{
				show_com(j, i);
				xc[j][i] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}

	//**********'\'斜**************************************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			//***************‘\’上方*************************
			s = xc[j][j + i - 1] + xc[j + 1][i + j] + xc[j + 2][i + j + 1] + xc[j + 3][i + j + 2] + xc[j + 4][i + j + 3] + xc[j + 5][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}

			//*************（6,4）防守***********************
			if (s == 4 && k == 2 && xc[j + 1][i + j] == 0 && xc[j][i + j - 1] == 0)
			{
				show_com(j + 1, i + j);
				xc[j + 1][i + j] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[j + 4][i + j + 3] == 0 && xc[j + 5][i + j + 4] == 0)
			{
				show_com(j + 4, i + j + 3);
				xc[j + 4][i + j + 3] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[j][i + j - 1] == 0 && xc[j + 5][i + j + 4] == 0)
			{
				show_com(j, i + j - 1);
				xc[j][i + j - 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}


			//**********‘\’下方***************
			s = xc[j + i - 1][j] + xc[j + i][j + 1] + xc[j + i + 1][j + 2] + xc[j + i + 2][j + 3] + xc[j + i + 3][j + 4] + xc[j + i + 4][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i - 1 + i1][j + i1] == 0)
				{
					k = k + 1;
				}
			}

			//*************(6,4)防守***********************
			if (s == 4 && k == 2 && xc[i + j][j + 1] == 0 && xc[i + j - 1][j] == 0)
			{
				show_com(i + j, j + 1);
				xc[i + j][j + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[i + j + 3][j + 4] == 0 && xc[i + j + 4][j + 5] == 0)
			{
				show_com(i + j + 3, j + 4);
				xc[i + j + 3][j + 4] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[i + j - 1][j] == 0 && xc[i + j + 4][j + 5] == 0)
			{
				show_com(i + j - 1, j);
				xc[i + j - 1][j] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}

	//**********'/'斜************************************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			//***************‘/’上方*************************
			s = xc[20 - j][j + i - 1] + xc[20 - (j + 1)][i + j] + xc[20 - (j + 2)][i + j + 1] + xc[20 - (j + 3)][i + j + 2] + xc[20 - (j + 4)][i + j + 3] + xc[20 - (j + 5)][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i1)][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************（6,4）防御***********************
			if (s == 4 && k == 2 && xc[20 - (j + 1)][i + j] == 0 && xc[20 - j][i + j - 1] == 0)
			{
				show_com(20 - (j + 1), i + j);
				xc[20 - (j + 1)][i + j] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[20 - (j + 4)][i + j + 3] == 0 && xc[20 - (j + 5)][i + j + 4] == 0)
			{
				show_com(20 - (j + 4), i + j + 3);
				xc[20 - (j + 4)][i + j + 3] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[20 - (j)][i + j - 1] == 0 && xc[20 - (j + 5)][i + j + 4] == 0)
			{
				show_com(20 - (j), i + j - 1);
				xc[20 - (j)][i + j - 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}

			//**********‘\’下方***************
			s = xc[20 - (j + i - 1)][j] + xc[20 - (j + i)][j + 1] + xc[20 - (j + i + 1)][j + 2] + xc[20 - (j + i + 2)][j + 3] + xc[20 - (j + i + 3)][j + 4] + xc[20 - (j + i + 4)][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i - 1 + i1)][j + i1] == 0)
				{
					k = k + 1;
				}
			}

			//*************（6,4）防御***********************
			if (s == 4 && k == 2 && xc[20 - (i + j)][j + 1] == 0 && xc[20 - (i + j - 1)][j] == 0)
			{
				show_com(20 - (i + j), j + 1);
				xc[20 - (i + j)][j + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[20 - (i + j + 3)][j + 4] == 0 && xc[20 - (i + j + 4)][j + 5] == 0)
			{
				show_com(20 - (i + j + 3), j + 4);
				xc[20 - (i + j + 3)][j + 4] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[20 - (i + j - 1)][j] == 0 && xc[20 - (i + j - 1)][j] == 0)
			{
				show_com(20 - (i + j - 1), j);
				xc[20 - (i + j - 1)][j] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}

	//************非致命（一子挡住）（6,4）（6,5）防守*******************************************
	//*******************************************************************************************
	//*******************************************************************************************

	//**********横***********************************************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[i][j] + xc[i][j + 1] + xc[i][j + 2] + xc[i][j + 3] + xc[i][j + 4] + xc[i][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[i][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//**********************（6,5）防守*********************************************
			if (s == 5 && k == 1)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[i][j + i1] == 0)
					{
						show_com(i, j + i1);
						xc[i][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
			//**********************（6,4）防守*********************************************
			if (s == 4 && k == 2 && xc[i][j] == 0 && xc[i][j + 1] == 0)
			{
				show_com(i, j + 1);
				xc[i][j + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[i][j + 4] == 0 && xc[i][j + 5] == 0)
			{
				show_com(i, j + 4);
				xc[i][j + 4] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			//************这一部分还需要完善**********
			if (s == 4 && k == 2 && xc[i][j + 1] == 0 && xc[i][j + 5] == 0)
			{
				show_com(i, j + 1);
				xc[i][j + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && ((xc[i][j] == 0 && xc[i][j + 2] == 0) || (xc[i][j + 1] == 0 && xc[i][j + 2] == 0) || (xc[i][j + 2] == 0 && xc[i][j + 4] == 0) || (xc[i][j + 2] == 0 && xc[i][j + 5] == 0)))
			{
				show_com(i, j + 2);
				xc[i][j + 2] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[i][j + 3] == 0 && (xc[i][j] == 0 || xc[i][j + 1] == 0 || xc[i][j + 2] == 0 || xc[i][j + 4] == 0 || xc[i][j + 5] == 0))
			{
				show_com(i, j + 3);
				xc[i][j + 3] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[i][j + 4] == 0 && (xc[i][j] == 0 || xc[i][j + 1] == 0))
			{
				show_com(i, j + 4);
				xc[i][j + 4] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}

	//********竖*************************************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[j][i] + xc[j + 1][i] + xc[j + 2][i] + xc[j + 3][i] + xc[j + 4][i] + xc[j + 5][i];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][i] == 0)
				{
					k = k + 1;
				}
			}
			//**********************（6,5）防守*********************************************
			if (s == 5 && k == 1)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[j + i1][i] == 0)
					{
						show_com(j + i1, i);
						xc[j + i1][i] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
			//**********************（6,4）防守********************************************
			if (s == 4 && k == 2 && xc[j + 1][i] == 0 && xc[j + 5][i] == 0)
			{
				show_com(j + 1, i);
				xc[j + 1][i] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && ((xc[j][i] == 0 && xc[j + 2][i] == 0) || (xc[j + 1][i] == 0 && xc[j + 2][i] == 0) || (xc[j + 2][i] == 0 && xc[j + 4][i] == 0) || (xc[j + 2][i] == 0 && xc[j + 5][i] == 0)))
			{
				show_com(j + 2, i);
				xc[j + 2][i] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[j + 3][i] == 0 && (xc[j][i] == 0 || xc[j + 1][i] == 0 || xc[j + 2][i] == 0 || xc[j + 4][i] == 0 || xc[j + 5][i] == 0))
			{
				show_com(j + 3, i);
				xc[j + 3][i] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[j + 4][i] == 0 && (xc[j][i] == 0 || xc[j + 1][i] == 0))
			{
				show_com(j + 4, i);
				xc[j + 4][i] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}

	//**********'\'斜**************************************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			//***************‘\’上方*************************
			s = xc[j][j + i - 1] + xc[j + 1][i + j] + xc[j + 2][i + j + 1] + xc[j + 3][i + j + 2] + xc[j + 4][i + j + 3] + xc[j + 5][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,5)防守***********************
			if (s == 5 && k == 1)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[j + i1][j + i - 1 + i1] == 0)
					{
						show_com(j + i1, j + i - 1 + i1);
						xc[j + i1][j + i - 1 + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}

			//*************（6,4）防守***********************
			if (s == 4 && k == 2 && xc[j + 1][i + j] == 0 && xc[j + 5][i + j + 4] == 0)
			{
				show_com(j + 1, i + j);
				xc[j + 1][i + j] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[j + 2][i + j + 1] == 0 && (xc[j][j + i - 1] == 0 || xc[j + 1][i + j] == 0 || xc[j + 4][i + j + 3] == 0 || xc[j + 5][j + i + 4] == 0))
			{
				show_com(j + 2, j + i + 1);
				xc[j + 2][j + i + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[j + 3][j + i + 2] == 0 && (xc[j][i + j - 1] == 0 || xc[j + 1][i + j] == 0 || xc[j + 2][i + j + 1] == 0 || xc[j + 4][i + j + 3] == 0 || xc[j + 5][i + j + 4] == 0))
			{
				show_com(j + 3, i + j + 2);
				xc[j + 3][i + j + 2] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[j + 4][i + j + 3] == 0 && (xc[j][j + i - 1] == 0 || xc[j + 1][j + i] == 0))
			{
				show_com(j + 4, i + j + 3);
				xc[j + 4][i + j + 3] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}

			//**********‘\’下方***************
			s = xc[j + i - 1][j] + xc[j + i][j + 1] + xc[j + i + 1][j + 2] + xc[j + i + 2][j + 3] + xc[j + i + 3][j + 4] + xc[j + i + 4][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i - 1 + i1][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,5)防守***********************
			if (s == 5 && k == 1)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[j + i - 1 + i1][j + i1] == 0)
					{
						show_com(j + i - 1 + i1, j + i1);
						xc[j + i - 1 + i1][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
			//*************(6,4)防守***********************
			if (s == 4 && k == 2 && xc[i + j][j + 1] == 0 && xc[i + j + 4][j + 5] == 0)
			{
				show_com(i + j, j + 1);
				xc[i + j][j + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[i + j + 1][j + 2] == 0 && (xc[i + j - 1][j] == 0 || xc[i + j][j + 1] == 0 || xc[i + j + 3][j + 4] == 0 || xc[i + j + 4][j + 5] == 0))
			{
				show_com(i + j + 1, j + 2);
				xc[i + j + 1][j + 2] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[i + j + 2][j + 3] == 0 && (xc[i + j - 1][j] == 0 || xc[i + j][j + 1] == 0 || xc[i + j + 1][j + 2] == 0 || xc[i + j + 3][j + 4] == 0 || xc[i + j + 4][j + 5] == 0))
			{
				show_com(i + j + 2, j + 3);
				xc[i + j + 2][j + 3] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[i + j + 3][j + 4] == 0 && (xc[i + j - 1][j] == 0 || xc[i + j][j + 1] == 0))
			{
				show_com(i + j + 3, j + 4);
				xc[i + j + 3][j + 4] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}
	//**********'/'斜************************************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			//***************‘/’上方*************************
			s = xc[20 - j][j + i - 1] + xc[20 - (j + 1)][i + j] + xc[20 - (j + 2)][i + j + 1] + xc[20 - (j + 3)][i + j + 2] + xc[20 - (j + 4)][i + j + 3] + xc[20 - (j + 5)][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i1)][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,5)防御***********************
			if (s == 5 && k == 1)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[20 - (j + i1)][j + i - 1 + i1] == 0)
					{
						show_com(20 - (j + i1), j + i - 1 + i1);
						xc[20 - (j + i1)][j + i - 1 + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
			//*************（6,4）防御***********************
			if (s == 4 && k == 2 && xc[20 - (j + 1)][i + j] == 0 && xc[20 - (j + 5)][i + j + 4] == 0)
			{
				show_com(20 - (j + 1), i + j);
				xc[20 - (j + 1)][i + j] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[20 - (j + 2)][i + j + 1] == 0 && (xc[20 - j][j + i - 1] == 0 || xc[20 - (j + 1)][i + j] == 0 || xc[20 - (j + 4)][i + j + 3] == 0 || xc[20 - (j + 5)][j + i + 4] == 0))
			{
				show_com(18 - j, j + i + 1);
				xc[18 - j][j + i + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[20 - (j + 3)][j + i + 2] == 0 && (xc[20 - j][i + j - 1] == 0 || xc[20 - (j + 1)][i + j] == 0 || xc[20 - (j + 2)][i + j + 1] == 0 || xc[20 - (j + 4)][i + j + 3] == 0 || xc[20 - (j + 5)][i + j + 4] == 0))
			{
				show_com(20 - (j + 3), i + j + 2);
				xc[20 - (j + 3)][i + j + 2] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[20 - (j + 4)][i + j + 3] == 0 && (xc[20 - j][j + i - 1] == 0 || xc[20 - (j + 1)][j + i] == 0))
			{
				show_com(20 - (j + 4), i + j + 3);
				xc[20 - (j + 4)][i + j + 3] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}

			//**********‘\’下方***************
			s = xc[20 - (j + i - 1)][j] + xc[20 - (j + i)][j + 1] + xc[20 - (j + i + 1)][j + 2] + xc[20 - (j + i + 2)][j + 3] + xc[20 - (j + i + 3)][j + 4] + xc[20 - (j + i + 4)][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i - 1 + i1)][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,5)防御***********************
			if (s == 5 && k == 1)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[20 - (j + i - 1 + i1)][j + i1] == 0)
					{
						show_com(20 - (j + i - 1 + i1), j + i1);
						xc[20 - (j + i - 1 + i1)][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
			//*************（6,4）防御***********************
			if (s == 4 && k == 2 && xc[20 - (i + j)][j + 1] == 0 && xc[20 - (i + j + 4)][j + 5] == 0)
			{
				show_com(20 - (i + j), j + 1);
				xc[20 - (i + j)][j + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[20 - (i + j + 1)][j + 2] == 0 && (xc[20 - (i + j - 1)][j] == 0 || xc[20 - (i + j)][j + 1] == 0 || xc[20 - (i + j + 3)][j + 4] == 0 || xc[20 - (i + j + 4)][j + 5] == 0))
			{
				show_com(20 - (i + j + 1), j + 2);
				xc[20 - (i + j + 1)][j + 2] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[20 - (i + j + 2)][j + 3] == 0 && (xc[20 - (i + j - 1)][j] == 0 || xc[20 - (i + j)][j + 1] == 0 || xc[20 - (i + j + 1)][j + 2] == 0 || xc[20 - (i + j + 3)][j + 4] == 0 || xc[20 - (i + j + 4)][j + 5] == 0))
			{
				show_com(20 - (i + j + 2), j + 3);
				xc[20 - (i + j + 2)][j + 3] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 4 && k == 2 && xc[20 - (i + j + 3)][j + 4] == 0 && (xc[20 - (i + j - 1)][j] == 0 || xc[20 - (i + j)][j + 1] == 0))
			{
				show_com(20 - (i + j + 3), j + 4);
				xc[20 - (i + j + 3)][j + 4] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}

	//*************************************活三进攻*********************************************
	//******************************************************************************************
	//******************************************************************************************

	//***********横**********************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[i][j] + xc[i][j + 1] + xc[i][j + 2] + xc[i][j + 3] + xc[i][j + 4] + xc[i][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[i][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//**********************活三进攻*********************************************
			if (s == 6 && k == 3 && xc[i][j] == 0 && xc[i][j + 1] == 0 && xc[i][j + 5] == 0)
			{
				show_com(i, j + 1);
				xc[i][j + 1] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 6 && k == 3 && xc[i][j] == 0 && xc[i][j + 4] == 0 && xc[i][j + 5] == 0)
			{
				show_com(i, j + 4);
				xc[i][j + 4] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 6 && k == 3 && xc[i][j] == 0 && xc[i][j + 2] == 0 && xc[i][j + 5] == 0)
			{
				show_com(i, j + 2);
				xc[i][j + 2] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
			if (s == 6 && k == 3 && xc[i][j] == 0 && xc[i][j + 5] == 0 && xc[i][j + 3] == 0)
			{
				show_com(i, j + 3);
				xc[i][j + 3] = 2;
				*pass = *pass + 1;
				chess = chess + 1;
				if (chess == 2)
				{
					return;
				}
			}
		}
	}

	//*********************竖***********************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[j][i] + xc[j + 1][i] + xc[j + 2][i] + xc[j + 3][i] + xc[j + 4][i] + xc[j + 5][i];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][i] == 0)
				{
					k = k + 1;
				}
			}
			//**********************活三进攻***************************************
			if (s == 6 && k == 3 && xc[j][i] == 0 && xc[j + 5][i] == 0)
			{
				for (int i2 = 1; i2 <= 4; i2++)
				{
					if (xc[j + i2][i] == 0)
					{
						show_com(j + i2, i);
						xc[j + i2][i] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//***************'\'斜活三进攻********************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{

			//***************‘\’上方*************************
			s = xc[j][j + i - 1] + xc[j + 1][i + j] + xc[j + 2][i + j + 1] + xc[j + 3][i + j + 2] + xc[j + 4][i + j + 3] + xc[j + 5][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//****************活三进攻***********************
			if (s == 6 && k == 3 && xc[j][j + i - 1] == 0 && xc[j + 5][j + i + 4] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[j + i1][j + i - 1 + i1] == 0)
					{
						show_com(j + i1, j + i - 1 + i1);
						xc[j + i1][j + i - 1 + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}

			//**********‘\’下方***************
			s = xc[j + i - 1][j] + xc[j + i][j + 1] + xc[j + i + 1][j + 2] + xc[j + i + 2][j + 3] + xc[j + i + 3][j + 4] + xc[j + i + 4][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i - 1 + i1][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************活三进攻***********************
			if (s == 6 && k == 3 && xc[j + i - 1][j] == 0 && xc[j + i + 4][j + 5] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[j + i - 1 + i1][j + i1] == 0)
					{
						show_com(j + i - 1 + i1, j + i1);
						xc[j + i - 1 + i1][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//*************'/'斜活三进攻********************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			//***************‘/’上方*************************
			s = xc[20 - j][j + i - 1] + xc[20 - (j + 1)][i + j] + xc[20 - (j + 2)][i + j + 1] + xc[20 - (j + 3)][i + j + 2] + xc[20 - (j + 4)][i + j + 3] + xc[20 - (j + 5)][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i1)][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************活三进攻***********************
			if (s == 6 && k == 3 && xc[20 - j][i + j - 1] == 0 && xc[20 - (j + 5)][i + j + 4] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[20 - (j + i1)][j + i - 1 + i1] == 0)
					{
						show_com(20 - (j + i1), j + i - 1 + i1);
						xc[20 - (j + i1)][j + i - 1 + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}

			//**********‘\’下方***************
			s = xc[20 - (j + i - 1)][j] + xc[20 - (j + i)][j + 1] + xc[20 - (j + i + 1)][j + 2] + xc[20 - (j + i + 2)][j + 3] + xc[20 - (j + i + 3)][j + 4] + xc[20 - (j + i + 4)][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i - 1 + i1)][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************活三进攻***********************
			if (s == 6 && k == 3 && xc[20 - (j + i - 1)][j] == 0 && xc[20 - (j + i + 4)][j + 5] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[20 - (j + i - 1 + i1)][j + i1] == 0)
					{
						show_com(20 - (j + i - 1 + i1), j + i1);
						xc[20 - (j + i - 1 + i1)][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//************************************真•活二进攻************************************
	//******************************************************************************************
	//******************************************************************************************

	//**********横*************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 12; j++)
		{
			s = xc[i][j] + xc[i][j + 1] + xc[i][j + 2] + xc[i][j + 3] + xc[i][j + 4] + xc[i][j + 5] + xc[i][j + 6] + xc[i][j + 7];
			k = 0;

			for (int i1 = 0; i1 <= 7; i1++)
			{
				if (xc[i][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//***************（8,2）进攻**************************************
			if (s == 4 && k == 4 && xc[i][j] == 0 && xc[i][j + 1] == 0 && xc[i][j + 6] == 0 && xc[i][j + 7] == 0)
			{
				for (int i2 = 2; i2 <= 5; i2++)
				{
					if (xc[i][j + i2] == 0)
					{
						show_com(i, j + i2);
						xc[i][j + i2] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//**********竖***************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 12; j++)
		{
			s = xc[j][i] + xc[j + 1][i] + xc[j + 2][i] + xc[j + 3][i] + xc[j + 4][i] + xc[j + 5][i] + xc[j + 6][i] + xc[j + 7][i];
			k = 0;

			for (int i1 = 0; i1 <= 7; i1++)
			{
				if (xc[j + i1][i] == 0)
				{
					k = k + 1;
				}
			}
			//**************（8,2）进攻**************************************
			if (s == 4 && k == 4 && xc[j][i] == 0 && xc[j + 1][i] == 0 && xc[j + 6][i] == 0 && xc[j + 7][i] == 0)
			{
				for (int i2 = 2; i2 <= 5; i2++)
				{
					if (xc[j + i2][i] == 0)
					{
						show_com(j + i2, i);
						xc[j + i2][i] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//*********'\'斜****************
	for (int i = 1; i <= 12; i++)
	{
		for (int j = 1; j <= 13 - i; j++)
		{
			//*********右上******************************
			s = xc[j][i + j - 1] + xc[j + 1][i + j] + xc[j + 2][i + j + 1] + xc[j + 3][i + j + 2] + xc[j + 4][i + j + 3] + xc[j + 5][i + j + 4] + xc[j + 6][i + j + 5] + xc[j + 7][i + j + 6];
			k = 0;

			for (int i1 = 0; i1 <= 7; i1++)
			{
				if (xc[j + i1][i + j - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//***********(8,2)进攻**************************
			if (s == 4 && k == 4 && xc[j][i + j - 1] == 0 && xc[j + 1][i + j] == 0 && xc[j + 6][i + j + 5] == 0 && xc[j + 7][i + j + 6] == 0)
			{
				for (int i2 = 2; i2 <= 5; i2++)
				{
					if (xc[j + i2][i + j - 1 + i2] == 0)
					{
						show_com(j + i2, i + j - 1 + i2);
						xc[j + i2][i + j - 1 + i2] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}

			//**********左下*********************************
			s = xc[i + j - 1][j] + xc[i + j][j + 1] + xc[i + j + 1][j + 2] + xc[i + j + 2][j + 3] + xc[i + j + 3][j + 4] + xc[i + j + 4][j + 5] + xc[i + j + 5][j + 6] + xc[i + j + 6][j + 7];
			k = 0;

			for (int i1 = 0; i1 <= 7; i1++)
			{
				if (xc[i + j - 1 + i1][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(8,2)进攻**************************
			if (s == 4 && k == 4 && xc[i + j - 1][j] == 0 && xc[i + j][j + 1] == 0 && xc[i + j + 5][j + 6] == 0 && xc[i + j + 6][j + 7] == 0)
			{
				for (int i2 = 2; i2 <= 5; i2++)
				{
					if (xc[i + j - 1 + i2][j + i2] == 0)
					{
						show_com(i + j - 1 + i2, j + i2);
						xc[i + j - 1 + i2][j + i2] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//*********'/'斜****************
	for (int i = 1; i <= 12; i++)
	{
		for (int j = 1; j <= 13 - i; j++)
		{
			//*********右上******************************
			s = xc[20 - j][i + j - 1] + xc[19 - j][i + j] + xc[18 - j][i + j + 1] + xc[17 - j][i + j + 2] + xc[16 - j][i + j + 3] + xc[15 - j][i + j + 4] + xc[14 - j][i + j + 5] + xc[13 - j][i + j + 6];
			k = 0;

			for (int i1 = 0; i1 <= 7; i1++)
			{
				if (xc[20 - (j + i1)][i + j - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//************(8,2)进攻**************************
			if (s == 4 && k == 4 && xc[20 - j][i + j - 1] == 0 && xc[19 - j][i + j] == 0 && xc[14 - j][i + j + 5] == 0 && xc[13 - j][i + j + 6] == 0)
			{
				for (int i2 = 2; i2 <= 5; i2++)
				{
					if (xc[20 - (j + i2)][i + j - 1 + i2] == 0)
					{
						show_com(20 - (j + i2), i + j - 1 + i2);
						xc[20 - (j + i2)][i + j - 1 + i2] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}

			//**********左下*********************************
			s = xc[20 - (i + j - 1)][j] + xc[20 - (i + j)][j + 1] + xc[20 - (i + j + 1)][j + 2] + xc[20 - (i + j + 2)][j + 3] + xc[20 - (i + j + 3)][j + 4] + xc[20 - (i + j + 4)][j + 5] + xc[20 - (i + j + 5)][j + 6] + xc[20 - (i + j + 6)][j + 7];
			k = 0;

			for (int i1 = 0; i1 <= 7; i1++)
			{
				if (xc[20 - (i + j - 1 + i1)][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//**********(8,2)进攻**************************
			if (s == 4 && k == 4 && xc[20 - (i + j - 1)][j] == 0 && xc[20 - (i + j)][j + 1] == 0 && xc[20 - (i + j + 5)][j + 6] == 0 && xc[20 - (i + j + 6)][j + 7] == 0)
			{
				for (int i2 = 2; i2 <= 5; i2++)
				{
					if (xc[20 - (i + j - 1 + i2)][j + i2] == 0)
					{
						show_com(20 - (i + j - 1 + i2), j + i2);
						xc[20 - (i + j - 1 + i2)][j + i2] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//**************************活二进攻*****************************************
	//***************************************************************************
	//***************************************************************************

	//***********横**********************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[i][j] + xc[i][j + 1] + xc[i][j + 2] + xc[i][j + 3] + xc[i][j + 4] + xc[i][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[i][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//**********************活二进攻*********************************************
			if (s == 4 && k == 4 && xc[i][j] == 0 && xc[i][j + 5] == 0)
			{
				for (int i2 = 1; i2 <= 4; i2++)
				{
					if (xc[i][j + i2] == 0)
					{
						show_com(i, j + i2);
						xc[i][j + i2] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//*********************竖***********************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[j][i] + xc[j + 1][i] + xc[j + 2][i] + xc[j + 3][i] + xc[j + 4][i] + xc[j + 5][i];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][i] == 0)
				{
					k = k + 1;
				}
			}
			//**********************活二进攻***************************************
			if (s == 4 && k == 4 && xc[j][i] == 0 && xc[j + 5][i] == 0)
			{
				for (int i2 = 1; i2 <= 4; i2++)
				{
					if (xc[j + i2][i] == 0)
					{
						show_com(j + i2, i);
						xc[j + i2][i] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//***************'\'斜活二进攻********************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{

			//***************‘\’上方*************************
			s = xc[j][j + i - 1] + xc[j + 1][i + j] + xc[j + 2][i + j + 1] + xc[j + 3][i + j + 2] + xc[j + 4][i + j + 3] + xc[j + 5][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//****************活二进攻***********************
			if (s == 4 && k == 4 && xc[j][j + i - 1] == 0 && xc[j + 5][j + i + 4] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[j + i1][j + i - 1 + i1] == 0)
					{
						show_com(j + i1, j + i - 1 + i1);
						xc[j + i1][j + i - 1 + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}

			//**********‘\’下方***************
			s = xc[j + i - 1][j] + xc[j + i][j + 1] + xc[j + i + 1][j + 2] + xc[j + i + 2][j + 3] + xc[j + i + 3][j + 4] + xc[j + i + 4][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i - 1 + i1][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************活二进攻***********************
			if (s == 4 && k == 4 && xc[j + i - 1][j] == 0 && xc[j + i + 4][j + 5] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[j + i - 1 + i1][j + i1] == 0)
					{
						show_com(j + i - 1 + i1, j + i1);
						xc[j + i - 1 + i1][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//*************'/'斜活二进攻********************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			//***************‘/’上方*************************
			s = xc[20 - j][j + i - 1] + xc[20 - (j + 1)][i + j] + xc[20 - (j + 2)][i + j + 1] + xc[20 - (j + 3)][i + j + 2] + xc[20 - (j + 4)][i + j + 3] + xc[20 - (j + 5)][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i1)][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************活二进攻***********************
			if (s == 4 && k == 4 && xc[20 - j][i + j - 1] == 0 && xc[20 - (j + 5)][i + j + 4] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[20 - (j + i1)][j + i - 1 + i1] == 0)
					{
						show_com(20 - (j + i1), j + i - 1 + i1);
						xc[20 - (j + i1)][j + i - 1 + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}

			//**********‘\’下方***************
			s = xc[20 - (j + i - 1)][j] + xc[20 - (j + i)][j + 1] + xc[20 - (j + i + 1)][j + 2] + xc[20 - (j + i + 2)][j + 3] + xc[20 - (j + i + 3)][j + 4] + xc[20 - (j + i + 4)][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i - 1 + i1)][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************活二进攻***********************
			if (s == 4 && k == 4 && xc[20 - (j + i - 1)][j] == 0 && xc[20 - (j + i + 4)][j + 5] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[20 - (j + i - 1 + i1)][j + i1] == 0)
					{
						show_com(20 - (j + i - 1 + i1), j + i1);
						xc[20 - (j + i - 1 + i1)][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//*******************************（8,3）活三防守************************************
	//**********************************************************************************
	//**********************************************************************************

	//**********横*************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 12; j++)
		{
			s = xc[i][j] + xc[i][j + 1] + xc[i][j + 2] + xc[i][j + 3] + xc[i][j + 4] + xc[i][j + 5] + xc[i][j + 6] + xc[i][j + 7];
			k = 0;

			for (int i1 = 0; i1 <= 7; i1++)
			{
				if (xc[i][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//********（8,3）活三防御****************************************
			if (s == 3 && k == 5 && xc[i][j] == 0 && xc[i][j + 1] == 0 && xc[i][j + 6] == 0 && xc[i][j + 7] == 0)
			{
				if (xc[i][j + 5] == 0)
				{
					show_com(i, j + 5);
					xc[i][j + 5] = 2;
					*pass = *pass + 1;
					chess = chess + 1;
					if (chess == 2)
					{
						return;
					}
					/*show_com(i,j+1);
					xc[i][j+1]=2;
					*pass=*pass+1;
					chess=chess+1;
					if(chess==2)
					{
					return;
					}*/
				}
				if (xc[i][j + 2] == 0)
				{
					show_com(i, j + 2);
					xc[i][j + 2] = 2;
					*pass = *pass + 1;
					chess = chess + 1;
					if (chess == 2)
					{
						return;
					}
					/*show_com(i,j+6);
					xc[i][j+6]=2;
					*pass=*pass+1;
					chess=chess+1;
					if(chess==2)
					{
					return;
					}*/
				}
			}
		}
	}

	//**********竖***************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 12; j++)
		{
			s = xc[j][i] + xc[j + 1][i] + xc[j + 2][i] + xc[j + 3][i] + xc[j + 4][i] + xc[j + 5][i] + xc[j + 6][i] + xc[j + 7][i];
			k = 0;

			for (int i1 = 0; i1 <= 7; i1++)
			{
				if (xc[j + i1][i] == 0)
				{
					k = k + 1;
				}
			}
			//***************（8,3）活三防御**************************************
			if (s == 3 && k == 5 && xc[j][i] == 0 && xc[j + 1][i] == 0 && xc[j + 6][i] == 0 && xc[j + 7][i] == 0)
			{
				if (xc[j + 2][i] == 0)
				{
					show_com(j + 2, i);
					xc[j + 2][i] = 2;
					*pass = *pass + 1;
					chess = chess + 1;
					if (chess == 2)
					{
						return;
					}
					/*show_com(j+6,i);
					xc[j+6][i]=2;
					*pass=*pass+1;
					chess=chess+1;
					if(chess==2)
					{
					return;
					}*/
				}
				if (xc[j + 5][i] == 0)
				{
					show_com(j + 5, i);
					xc[j + 5][i] = 2;
					*pass = *pass + 1;
					chess = chess + 1;
					if (chess == 2)
					{
						return;
					}
					/*show_com(j+1,i);
					xc[j+1][i]=2;
					*pass=*pass+1;
					chess=chess+1;
					if(chess==2)
					{
					return;
					}*/
				}
			}
		}
	}

	//*********'\'斜****************
	for (int i = 1; i <= 12; i++)
	{
		for (int j = 1; j <= 13 - i; j++)
		{
			//*********右上******************************
			s = xc[j][i + j - 1] + xc[j + 1][i + j] + xc[j + 2][i + j + 1] + xc[j + 3][i + j + 2] + xc[j + 4][i + j + 3] + xc[j + 5][i + j + 4] + xc[j + 6][i + j + 5] + xc[j + 7][i + j + 6];
			k = 0;

			for (int i1 = 0; i1 <= 7; i1++)
			{
				if (xc[j + i1][i + j - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*********活三防御**************************
			if (s == 3 && k == 5 && xc[j][i + j - 1] == 0 && xc[j + 1][i + j] == 0 && xc[j + 6][i + j + 5] == 0 && xc[j + 7][i + j + 6] == 0)
			{
				if (xc[j + 2][i + j + 1] == 0)
				{
					show_com(j + 2, i + j + 1);
					xc[j + 2][i + j + 1] = 2;
					*pass = *pass + 1;
					chess = chess + 1;
					if (chess == 2)
					{
						return;
					}
					/*show_com(j+6,i+j+5);
					xc[j+6][i+j+5]=2;
					*pass=*pass+1;
					chess=chess+1;
					if(chess==2)
					{
					return;
					}*/
				}
				if (xc[j + 5][i + j + 4] == 0)
				{
					show_com(j + 5, i + j + 4);
					xc[j + 5][i + j + 4] = 2;
					*pass = *pass + 1;
					chess = chess + 1;
					if (chess == 2)
					{
						return;
					}
					/*show_com(j+1,i+j);
					xc[j+1][i+j]=2;
					*pass=*pass+1;
					chess=chess+1;
					if(chess==2)
					{
					return;
					}*/
				}
			}

			//**********左下*********************************
			s = xc[i + j - 1][j] + xc[i + j][j + 1] + xc[i + j + 1][j + 2] + xc[i + j + 2][j + 3] + xc[i + j + 3][j + 4] + xc[i + j + 4][j + 5] + xc[i + j + 5][j + 6] + xc[i + j + 6][j + 7];
			k = 0;

			for (int i1 = 0; i1 <= 7; i1++)
			{
				if (xc[i + j - 1 + i1][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//************活三防御**************************
			if (s == 3 && k == 5 && xc[i + j - 1][j] == 0 && xc[i + j][j + 1] == 0 && xc[i + j + 5][j + 6] == 0 && xc[i + j + 6][j + 7] == 0)
			{
				if (xc[i + j + 1][j + 2] == 0)
				{
					show_com(i + j + 1, j + 2);
					xc[i + j + 1][j + 2] = 2;
					*pass = *pass + 1;
					chess = chess + 1;
					if (chess == 2)
					{
						return;
					}
					/*show_com(i+j+5,j+6);
					xc[i+j+5][j+6]=2;
					*pass=*pass+1;
					chess=chess+1;
					if(chess==2)
					{
					return;
					}*/
				}
				if (xc[i + j + 4][j + 5] == 0)
				{
					show_com(i + j + 4, j + 5);
					xc[i + j + 4][j + 5] = 2;
					*pass = *pass + 1;
					chess = chess + 1;
					if (chess == 2)
					{
						return;
					}
					/*show_com(i+j,j+1);
					xc[i+j][j+1]=2;
					*pass=*pass+1;
					chess=chess+1;
					if(chess==2)
					{
					return;
					}*/
				}
			}
		}
	}

	//*********'/'斜****************
	for (int i = 1; i <= 12; i++)
	{
		for (int j = 1; j <= 13 - i; j++)
		{
			//*********右上******************************
			s = xc[20 - j][i + j - 1] + xc[19 - j][i + j] + xc[18 - j][i + j + 1] + xc[17 - j][i + j + 2] + xc[16 - j][i + j + 3] + xc[15 - j][i + j + 4] + xc[14 - j][i + j + 5] + xc[13 - j][i + j + 6];
			k = 0;

			for (int i1 = 0; i1 <= 7; i1++)
			{
				if (xc[20 - (j + i1)][i + j - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//***********活三防御**************************
			if (s == 3 && k == 5 && xc[20 - j][i + j - 1] == 0 && xc[19 - j][i + j] == 0 && xc[14 - j][i + j + 5] == 0 && xc[13 - j][i + j + 6] == 0)
			{
				if (xc[18 - j][i + j + 1] == 0)
				{
					show_com(18 - j, i + j + 1);
					xc[18 - j][i + j + 1] = 2;
					*pass = *pass + 1;
					chess = chess + 1;
					if (chess == 2)
					{
						return;
					}
					/*show_com(14-j,i+j+5);
					xc[14-j][i+j+5]=2;
					*pass=*pass+1;
					chess=chess+1;
					if(chess==2)
					{
					return;
					}*/
				}
				if (xc[15 - j][i + j + 4 == 0])
				{
					show_com(15 - j, i + j + 4);
					xc[15 - j][i + j + 4] = 2;
					*pass = *pass + 1;
					chess = chess + 1;
					if (chess == 2)
					{
						return;
					}
					/*show_com(19-j,i+j);
					xc[19-j][i+j]=2;
					*pass=*pass+1;
					chess=chess+1;
					if(chess==2)
					{
					return;
					}*/
				}
			}

			//**********左下*********************************
			s = xc[20 - (i + j - 1)][j] + xc[20 - (i + j)][j + 1] + xc[20 - (i + j + 1)][j + 2] + xc[20 - (i + j + 2)][j + 3] + xc[20 - (i + j + 3)][j + 4] + xc[20 - (i + j + 4)][j + 5] + xc[20 - (i + j + 5)][j + 6] + xc[20 - (i + j + 6)][j + 7];
			k = 0;

			for (int i1 = 0; i1 <= 7; i1++)
			{
				if (xc[20 - (i + j - 1 + i1)][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//**********活三防御**************************
			if (s == 3 && k == 5 && xc[20 - (i + j - 1)][j] == 0 && xc[20 - (i + j)][j + 1] == 0 && xc[20 - (i + j + 5)][j + 6] == 0 && xc[20 - (i + j + 6)][j + 7] == 0)
			{
				if (xc[20 - (i + j + 1)][j + 2] == 0)
				{
					show_com(20 - (i + j + 1), j + 2);
					xc[20 - (i + j + 1)][j + 2] = 2;
					*pass = *pass + 1;
					chess = chess + 1;
					if (chess == 2)
					{
						return;
					}
					/*show_com(20-(i+j+5),j+6);
					xc[20-(i+j+5)][j+6]=2;
					*pass=*pass+1;
					chess=chess+1;
					if(chess==2)
					{
					return;
					}*/
				}
				if (xc[20 - (i + j + 4)][j + 5] == 0)
				{
					show_com(20 - (i + j + 4), j + 5);
					xc[20 - (i + j + 4)][j + 5] = 2;
					*pass = *pass + 1;
					chess = chess + 1;
					if (chess == 2)
					{
						return;
					}
					/*show_com(20-(i+j),j+1);
					xc[20-(i+j)][j+1]=2;
					*pass=*pass+1;
					chess=chess+1;
					if(chess==2)
					{
					return;
					}*/
				}
			}
		}
	}

	//******************眠三朦胧三进攻***********************************************
	//*******************************************************************************
	//*******************************************************************************

	//**************横***********************************************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[i][j] + xc[i][j + 1] + xc[i][j + 2] + xc[i][j + 3] + xc[i][j + 4] + xc[i][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[i][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//**********************(6,3)进攻*********************************************
			if (s == 6 && k == 3)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[i][j + i1] == 0)
					{
						show_com(i, j + i1);
						xc[i][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
						break;
					}
				}
			}
		}
	}

	//*********************竖***********************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[j][i] + xc[j + 1][i] + xc[j + 2][i] + xc[j + 3][i] + xc[j + 4][i] + xc[j + 5][i];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][i] == 0)
				{
					k = k + 1;
				}
			}
			//**********************(6,3)进攻*********************************************
			if (s == 6 && k == 3)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[j + i1][i] == 0)
					{
						show_com(j + i1, i);
						xc[j + i1][i] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
						break;
					}
				}
			}
		}
	}

	//******************'\'斜********************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			//***************‘\’上方*************************
			s = xc[j][j + i - 1] + xc[j + 1][i + j] + xc[j + 2][i + j + 1] + xc[j + 3][i + j + 2] + xc[j + 4][i + j + 3] + xc[j + 5][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//**************(6,3)进攻***********************
			if (s == 6 && k == 3)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[j + i1][j + i - 1 + i1] == 0)
					{
						show_com(j + i1, j + i - 1 + i1);
						xc[j + i1][j + i - 1 + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
						break;
					}
				}
			}

			//**********‘\’下方***************
			s = xc[j + i - 1][j] + xc[j + i][j + 1] + xc[j + i + 1][j + 2] + xc[j + i + 2][j + 3] + xc[j + i + 3][j + 4] + xc[j + i + 4][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i - 1 + i1][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,3)进攻***********************
			if (s == 6 && k == 3)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[j + i - 1 + i1][j + i1] == 0)
					{
						show_com(j + i - 1 + i1, j + i1);
						xc[j + i - 1 + i1][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
						break;
					}
				}
			}
		}
	}
	//********************'/'斜**********************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			//***************‘/’上方*************************
			s = xc[20 - j][j + i - 1] + xc[20 - (j + 1)][i + j] + xc[20 - (j + 2)][i + j + 1] + xc[20 - (j + 3)][i + j + 2] + xc[20 - (j + 4)][i + j + 3] + xc[20 - (j + 5)][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i1)][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,3)进攻***********************
			if (s == 6 && k == 3)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[20 - (j + i1)][j + i - 1 + i1] == 0)
					{
						show_com(20 - (j + i1), j + i - 1 + i1);
						xc[20 - (j + i1)][j + i - 1 + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
						break;
					}
				}
			}

			//**********‘\’下方***************
			s = xc[20 - (j + i - 1)][j] + xc[20 - (j + i)][j + 1] + xc[20 - (j + i + 1)][j + 2] + xc[20 - (j + i + 2)][j + 3] + xc[20 - (j + i + 3)][j + 4] + xc[20 - (j + i + 4)][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i - 1 + i1)][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,3)进攻***********************
			if (s == 6 && k == 3)
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[20 - (j + i - 1 + i1)][j + i1] == 0)
					{
						show_com(20 - (j + i - 1 + i1), j + i1);
						xc[20 - (j + i - 1 + i1)][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
						break;
					}
				}
			}
		}
	}

	//******************真•活二防守*************************************************
	//*******************************************************************************
	//*******************************************************************************

	//*****************横***********************************************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[i][j] + xc[i][j + 1] + xc[i][j + 2] + xc[i][j + 3] + xc[i][j + 4] + xc[i][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[i][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//**********************(6,2)防守*********************************************
			if (s == 2 && k == 4 && xc[i][j] == 0 && xc[i][j + 5] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[i][j + i1] == 1 && xc[i][j + i1 + 1] == 1)
					{
						show_com(i, j + i1 - 1);
						xc[i][j + i1 - 1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//*********************竖***********************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[j][i] + xc[j + 1][i] + xc[j + 2][i] + xc[j + 3][i] + xc[j + 4][i] + xc[j + 5][i];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][i] == 0)
				{
					k = k + 1;
				}
			}
			//**********************(6,2)防守*********************************************
			if (s == 2 && k == 4 && xc[j][i] == 0 && xc[j + 5][i] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[j + i1][i] == 1 && xc[j + i1 + 1][i] == 1)
					{
						show_com(j + i1 - 1, i);
						xc[j + i1 - 1][i] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//******************'\'斜********************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			//***************‘\’上方*************************
			s = xc[j][j + i - 1] + xc[j + 1][i + j] + xc[j + 2][i + j + 1] + xc[j + 3][i + j + 2] + xc[j + 4][i + j + 3] + xc[j + 5][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//***************(6,2)防守***********************
			if (s == 2 && k == 4 && xc[j][j + i - 1] == 0 && xc[j + 5][j + i + 4] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[j + i1][j + i - 1 + i1] == 1 && xc[j + i1 + 1][j + i + i1] == 1)
					{
						show_com(j + i1 - 1, j + i - 1 + i1 - 1);
						xc[j + i1 - 1][j + i - 1 + i1 - 1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}

			//**********‘\’下方***************
			s = xc[j + i - 1][j] + xc[j + i][j + 1] + xc[j + i + 1][j + 2] + xc[j + i + 2][j + 3] + xc[j + i + 3][j + 4] + xc[j + i + 4][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i - 1 + i1][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,2)防守***********************
			if (s == 2 && k == 4 && xc[j + i - 1][j] == 0 && xc[j + i + 4][j + 5] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[j + i - 1 + i1][j + i1] == 1 && xc[j + i + i1][j + i1 + 1] == 1)
					{
						show_com(j + i - 1 + i1 - 1, j + i1 - 1);
						xc[j + i - 1 + i1 - 1][j + i1 - 1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}
	//********************'/'斜**********************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			//***************‘/’上方*************************
			s = xc[20 - j][j + i - 1] + xc[20 - (j + 1)][i + j] + xc[20 - (j + 2)][i + j + 1] + xc[20 - (j + 3)][i + j + 2] + xc[20 - (j + 4)][i + j + 3] + xc[20 - (j + 5)][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i1)][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,2)防守***********************
			if (s == 2 && k == 4 && xc[20 - j][i + j - 1] == 0 && xc[20 - (j + 5)][i + j + 4] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[20 - (j + i1)][j + i - 1 + i1] == 1 && xc[20 - (j + i1 + 1)][j + i + i1] == 1)
					{
						show_com(20 - (j + i1 - 1), j + i - 1 + i1 - 1);
						xc[20 - (j + i1 - 1)][j + i - 1 + i1 - 1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}

			//**********‘\’下方***************
			s = xc[20 - (j + i - 1)][j] + xc[20 - (j + i)][j + 1] + xc[20 - (j + i + 1)][j + 2] + xc[20 - (j + i + 2)][j + 3] + xc[20 - (j + i + 3)][j + 4] + xc[20 - (j + i + 4)][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i - 1 + i1)][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,2)防守***********************
			if (s == 2 && k == 4 && xc[20 - (j + i - 1)][j] == 0 && xc[20 - (j + i + 4)][j + 5] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[20 - (j + i - 1 + i1)][j + i1] == 1 && xc[20 - (j + i + i1)][j + i1 + 1] == 1)
					{
						show_com(20 - (j + i - 2 + i1), j + i1 - 1);
						xc[20 - (j + i - 2 + i1)][j + i1 - 1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//******************活二防守*****************************************************
	//*******************************************************************************
	//*******************************************************************************

	//*****************横***********************************************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[i][j] + xc[i][j + 1] + xc[i][j + 2] + xc[i][j + 3] + xc[i][j + 4] + xc[i][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[i][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//**********************(6,2)防守*********************************************
			if (s == 2 && k == 4 && xc[i][j] == 0 && xc[i][j + 5] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[i][j + i1] == 0)
					{
						show_com(i, j + i1);
						xc[i][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//*********************竖***********************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[j][i] + xc[j + 1][i] + xc[j + 2][i] + xc[j + 3][i] + xc[j + 4][i] + xc[j + 5][i];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][i] == 0)
				{
					k = k + 1;
				}
			}
			//**********************(6,2)进攻*********************************************
			if (s == 2 && k == 4 && xc[j][i] == 0 && xc[j + 5][i] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[j + i1][i] == 0)
					{
						show_com(j + i1, i);
						xc[j + i1][i] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//******************'\'斜********************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			//***************‘\’上方*************************
			s = xc[j][j + i - 1] + xc[j + 1][i + j] + xc[j + 2][i + j + 1] + xc[j + 3][i + j + 2] + xc[j + 4][i + j + 3] + xc[j + 5][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//***************(6,2)防守***********************
			if (s == 2 && k == 4 && xc[j][j + i - 1] == 0 && xc[j + 5][j + i + 4] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[j + i1][j + i - 1 + i1] == 0)
					{
						show_com(j + i1, j + i - 1 + i1);
						xc[j + i1][j + i - 1 + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}

			//**********‘\’下方***************
			s = xc[j + i - 1][j] + xc[j + i][j + 1] + xc[j + i + 1][j + 2] + xc[j + i + 2][j + 3] + xc[j + i + 3][j + 4] + xc[j + i + 4][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i - 1 + i1][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,2)防守***********************
			if (s == 2 && k == 4 && xc[j + i - 1][j] == 0 && xc[j + i + 4][j + 5] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[j + i - 1 + i1][j + i1] == 0)
					{
						show_com(j + i - 1 + i1, j + i1);
						xc[j + i - 1 + i1][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}
	//********************'/'斜**********************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			//***************‘/’上方*************************
			s = xc[20 - j][j + i - 1] + xc[20 - (j + 1)][i + j] + xc[20 - (j + 2)][i + j + 1] + xc[20 - (j + 3)][i + j + 2] + xc[20 - (j + 4)][i + j + 3] + xc[20 - (j + 5)][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i1)][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,2)防守***********************
			if (s == 2 && k == 4 && xc[20 - j][i + j - 1] == 0 && xc[20 - (j + 5)][i + j + 4] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[20 - (j + i1)][j + i - 1 + i1] == 0)
					{
						show_com(20 - (j + i1), j + i - 1 + i1);
						xc[20 - (j + i1)][j + i - 1 + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}

			//**********‘\’下方***************
			s = xc[20 - (j + i - 1)][j] + xc[20 - (j + i)][j + 1] + xc[20 - (j + i + 1)][j + 2] + xc[20 - (j + i + 2)][j + 3] + xc[20 - (j + i + 3)][j + 4] + xc[20 - (j + i + 4)][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i - 1 + i1)][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,2)防守***********************
			if (s == 2 && k == 4 && xc[20 - (j + i - 1)][j] == 0 && xc[20 - (j + i + 4)][j + 5] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[20 - (j + i - 1 + i1)][j + i1] == 0)
					{
						show_com(20 - (j + i - 1 + i1), j + i1);
						xc[20 - (j + i - 1 + i1)][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//******************眠二进攻*****************************************************
	//*******************************************************************************
	//*******************************************************************************

	//*****************横***********************************************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[i][j] + xc[i][j + 1] + xc[i][j + 2] + xc[i][j + 3] + xc[i][j + 4] + xc[i][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[i][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//**********************(6,2)进攻*********************************************
			if (s == 4 && k == 4 && xc[i][j] == 0 && xc[i][j + 5] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[i][j + i1] == 0)
					{
						show_com(i, j + i1);
						xc[i][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
						break;
					}
				}
			}
		}
	}

	//*********************竖***********************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[j][i] + xc[j + 1][i] + xc[j + 2][i] + xc[j + 3][i] + xc[j + 4][i] + xc[j + 5][i];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][i] == 0)
				{
					k = k + 1;
				}
			}
			//**********************(6,2)进攻*********************************************
			if (s == 4 && k == 4 && xc[j][i] == 0 && xc[j + 5][i] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[j + i1][i] == 0)
					{
						show_com(j + i1, i);
						xc[j + i1][i] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
						break;
					}
				}
			}
		}
	}

	//******************'\'斜********************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			//***************‘\’上方*************************
			s = xc[j][j + i - 1] + xc[j + 1][i + j] + xc[j + 2][i + j + 1] + xc[j + 3][i + j + 2] + xc[j + 4][i + j + 3] + xc[j + 5][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//***************(6,2)进攻***********************
			if (s == 4 && k == 4 && xc[j][j + i - 1] == 0 && xc[j + 5][j + i + 4] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[j + i1][j + i - 1 + i1] == 0)
					{
						show_com(j + i1, j + i - 1 + i1);
						xc[j + i1][j + i - 1 + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
						break;
					}
				}
			}

			//**********‘\’下方***************
			s = xc[j + i - 1][j] + xc[j + i][j + 1] + xc[j + i + 1][j + 2] + xc[j + i + 2][j + 3] + xc[j + i + 3][j + 4] + xc[j + i + 4][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i - 1 + i1][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,2)进攻***********************
			if (s == 4 && k == 4 && xc[j + i - 1][j] == 0 && xc[j + i + 4][j + 5] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[j + i - 1 + i1][j + i1] == 0)
					{
						show_com(j + i - 1 + i1, j + i1);
						xc[j + i - 1 + i1][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
						break;
					}
				}
			}
		}
	}
	//********************'/'斜**********************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			//***************‘/’上方*************************
			s = xc[20 - j][j + i - 1] + xc[20 - (j + 1)][i + j] + xc[20 - (j + 2)][i + j + 1] + xc[20 - (j + 3)][i + j + 2] + xc[20 - (j + 4)][i + j + 3] + xc[20 - (j + 5)][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i1)][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,2)进攻***********************
			if (s == 4 && k == 4 && xc[20 - j][i + j - 1] == 0 && xc[20 - (j + 5)][i + j + 4] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[20 - (j + i1)][j + i - 1 + i1] == 0)
					{
						show_com(20 - (j + i1), j + i - 1 + i1);
						xc[20 - (j + i1)][j + i - 1 + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
						break;
					}
				}
			}

			//**********‘\’下方***************
			s = xc[20 - (j + i - 1)][j] + xc[20 - (j + i)][j + 1] + xc[20 - (j + i + 1)][j + 2] + xc[20 - (j + i + 2)][j + 3] + xc[20 - (j + i + 3)][j + 4] + xc[20 - (j + i + 4)][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i - 1 + i1)][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,2)进攻***********************
			if (s == 4 && k == 4 && xc[20 - (j + i - 1)][j] == 0 && xc[20 - (j + i + 4)][j + 5] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[20 - (j + i - 1 + i1)][j + i1] == 0)
					{
						show_com(20 - (j + i - 1 + i1), j + i1);
						xc[20 - (j + i - 1 + i1)][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
						break;
					}
				}
			}
		}
	}

	//******************眠二进攻*****************************************************
	//*******************************************************************************
	//*******************************************************************************

	//*****************横***********************************************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[i][j] + xc[i][j + 1] + xc[i][j + 2] + xc[i][j + 3] + xc[i][j + 4] + xc[i][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[i][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//**********************(6,2)进攻*********************************************
			if (s == 4 && k == 4 && (xc[i][j] == 2 || xc[i][j + 5] == 2))
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[i][j + i1] == 0)
					{
						show_com(i, j + i1);
						xc[i][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//*********************竖***********************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[j][i] + xc[j + 1][i] + xc[j + 2][i] + xc[j + 3][i] + xc[j + 4][i] + xc[j + 5][i];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][i] == 0)
				{
					k = k + 1;
				}
			}
			//**********************(6,2)进攻*********************************************
			if (s == 4 && k == 4 && (xc[j][i] == 2 || xc[j + 5][i] == 2))
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[j + i1][i] == 0)
					{
						show_com(j + i1, i);
						xc[j + i1][i] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//******************'\'斜********************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			//***************‘\’上方*************************
			s = xc[j][j + i - 1] + xc[j + 1][i + j] + xc[j + 2][i + j + 1] + xc[j + 3][i + j + 2] + xc[j + 4][i + j + 3] + xc[j + 5][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//***************(6,2)进攻***********************
			if (s == 4 && k == 4 && (xc[j][j + i - 1] == 2 || xc[j + 5][j + i + 4] == 2))
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[j + i1][j + i - 1 + i1] == 0)
					{
						show_com(j + i1, j + i - 1 + i1);
						xc[j + i1][j + i - 1 + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}

			//**********‘\’下方***************
			s = xc[j + i - 1][j] + xc[j + i][j + 1] + xc[j + i + 1][j + 2] + xc[j + i + 2][j + 3] + xc[j + i + 3][j + 4] + xc[j + i + 4][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i - 1 + i1][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,2)进攻***********************
			if (s == 4 && k == 4 && (xc[j + i - 1][j] == 2 || xc[j + i + 4][j + 5] == 2))
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[j + i - 1 + i1][j + i1] == 0)
					{
						show_com(j + i - 1 + i1, j + i1);
						xc[j + i - 1 + i1][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}
	//********************'/'斜**********************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			//***************‘/’上方*************************
			s = xc[20 - j][j + i - 1] + xc[20 - (j + 1)][i + j] + xc[20 - (j + 2)][i + j + 1] + xc[20 - (j + 3)][i + j + 2] + xc[20 - (j + 4)][i + j + 3] + xc[20 - (j + 5)][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i1)][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,2)进攻***********************
			if (s == 4 && k == 4 && (xc[20 - j][i + j - 1] == 2 || xc[20 - (j + 5)][i + j + 4] == 2))
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[20 - (j + i1)][j + i - 1 + i1] == 0)
					{
						show_com(20 - (j + i1), j + i - 1 + i1);
						xc[20 - (j + i1)][j + i - 1 + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}

			//**********‘\’下方***************
			s = xc[20 - (j + i - 1)][j] + xc[20 - (j + i)][j + 1] + xc[20 - (j + i + 1)][j + 2] + xc[20 - (j + i + 2)][j + 3] + xc[20 - (j + i + 3)][j + 4] + xc[20 - (j + i + 4)][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i - 1 + i1)][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,2)进攻***********************
			if (s == 4 && k == 4 && (xc[20 - (j + i - 1)][j] == 2 || xc[20 - (j + i + 4)][j + 5] == 2))
			{
				for (int i1 = 0; i1 <= 5; i1++)
				{
					if (xc[20 - (j + i - 1 + i1)][j + i1] == 0)
					{
						show_com(20 - (j + i - 1 + i1), j + i1);
						xc[20 - (j + i - 1 + i1)][j + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//*************************其余进攻***********************************
	//********************************************************************
	//********************************************************************

	//*****************横*************************************************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[i][j] + xc[i][j + 1] + xc[i][j + 2] + xc[i][j + 3] + xc[i][j + 4] + xc[i][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[i][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//**********************(6,1)进攻*******************************************
			if (s == 2 && k == 5 && xc[i][j] == 0 && xc[i][j + 5] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[i][j + i1] == 2)
					{
						show_com(i, j + i1 + 1);
						xc[i][j + i1 + 1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//*********************竖***********************
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 14; j++)
		{
			s = xc[j][i] + xc[j + 1][i] + xc[j + 2][i] + xc[j + 3][i] + xc[j + 4][i] + xc[j + 5][i];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][i] == 0)
				{
					k = k + 1;
				}
			}
			//**********************(6,1)进攻*********************************************
			if (s == 2 && k == 5 && xc[j][i] == 0 && xc[j + 5][i] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[j + i1][i] == 2)
					{
						show_com(j + i1 + 1, i);
						xc[j + i1 + 1][i] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}

	//******************'\'斜********************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			//***************‘\’上方*************************
			s = xc[j][j + i - 1] + xc[j + 1][i + j] + xc[j + 2][i + j + 1] + xc[j + 3][i + j + 2] + xc[j + 4][i + j + 3] + xc[j + 5][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i1][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//***************(6,1)进攻***********************
			if (s == 2 && k == 5 && xc[j][j + i - 1] == 0 && xc[j + 5][j + i + 4] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[j + i1][j + i - 1 + i1] == 2)
					{
						show_com(j + i1 + 1, j + i + i1);
						xc[j + i1 + 1][j + i + i1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}

			//**********‘\’下方***************
			s = xc[j + i - 1][j] + xc[j + i][j + 1] + xc[j + i + 1][j + 2] + xc[j + i + 2][j + 3] + xc[j + i + 3][j + 4] + xc[j + i + 4][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[j + i - 1 + i1][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,1)进攻***********************
			if (s == 2 && k == 5 && xc[j + i - 1][j] == 0 && xc[j + i + 4][j + 5] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[j + i - 1 + i1][j + i1] == 2)
					{
						show_com(j + i - 1 + i1 + 1, j + i1 + 1);
						xc[j + i - 1 + i1 + 1][j + i1 + 1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}
	//********************'/'斜**********************
	for (int i = 1; i <= 14; i++)
	{
		for (int j = 1; j <= 15 - i; j++)
		{
			//***************‘/’上方*************************
			s = xc[20 - j][j + i - 1] + xc[20 - (j + 1)][i + j] + xc[20 - (j + 2)][i + j + 1] + xc[20 - (j + 3)][i + j + 2] + xc[20 - (j + 4)][i + j + 3] + xc[20 - (j + 5)][j + i + 4];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i1)][j + i - 1 + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,1)进攻***********************
			if (s == 2 && k == 5 && xc[20 - j][i + j - 1] == 0 && xc[20 - (j + 5)][i + j + 4] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[20 - (j + i1)][j + i - 1 + i1] == 2)
					{
						show_com(20 - (j + i1 + 1), j + i - 1 + i1 + 1);
						xc[20 - (j + i1 + 1)][j + i - 1 + i1 + 1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}

			//**********‘\’下方***************
			s = xc[20 - (j + i - 1)][j] + xc[20 - (j + i)][j + 1] + xc[20 - (j + i + 1)][j + 2] + xc[20 - (j + i + 2)][j + 3] + xc[20 - (j + i + 3)][j + 4] + xc[20 - (j + i + 4)][j + 5];
			k = 0;

			for (int i1 = 0; i1 <= 5; i1++)
			{
				if (xc[20 - (j + i - 1 + i1)][j + i1] == 0)
				{
					k = k + 1;
				}
			}
			//*************(6,1)进攻***********************
			if (s == 2 && k == 5 && xc[20 - (j + i - 1)][j] == 0 && xc[20 - (j + i + 4)][j + 5] == 0)
			{
				for (int i1 = 1; i1 <= 4; i1++)
				{
					if (xc[20 - (j + i - 1 + i1)][j + i1] == 2)
					{
						show_com(20 - (j + i - 1 + i1 + 1), j + i1 + 1);
						xc[20 - (j + i - 1 + i1 + 1)][j + i1 + 1] = 2;
						*pass = *pass + 1;
						chess = chess + 1;
						if (chess == 2)
						{
							return;
						}
					}
				}
			}
		}
	}
}
