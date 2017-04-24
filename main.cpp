#include <stdio.h>
#include <graphics.h>
#include <conio.h>

struct Point
{
	int x;
	int y;
	int step;
};

void main()
{
	int xc[20][20];
	int vv[20][20];
	int quit_help();
	int quit_undo();
	void chessboard();
	void help();
	void no_undo();
	void AI_xian(int(*xc)[20], int *pass);
	void AI_hou(int(*xc)[20], int *pass);
	void AI2(int (*xc)[20],int (*vv)[20],int *pass,Point (*a)[20]);
	void show(int(*xc)[20], Point(*b)[20]);
	void show1(int(*xc)[20], Point(*b)[20]);
	int judge(int(*xc)[20]);
	void clear(int(*xc)[20], Point(*a)[20]);
	void undo(Point(*a)[20], int(*xc)[20],int *pass);
	void dot(Point(*b)[20], int *pass);
	void end();
	void black_win();
	void white_win();
	void draw();
	int input();
	int inputi;
	int choose();
	int choosei;
	int choose_ai();
	int choose_aii;
	int choose_order();
	int choose_orderi;
	int choose();
	int pass;
	int p = 1, q = 1;
	struct Point a[20][20];

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			a[i][j].x = 40 * j;
			a[i][j].y = 40 * i;
			a[i][j].step = 0;
		}
	}
	while (true)
	{
		pass = 1;
		clear(xc, a);
		chessboard();
		choosei = choose();

		/*************************************人人***************************************/
		if (choosei == 1)
		{
			clear(xc, a);
			chessboard();
			while (true)
			{
				inputi = input();
				q = inputi % 100;
				p = (inputi - (inputi % 100)) / 100;
				if ((inputi <= 1818 && inputi >= 0) && (xc[q][p] == 0))
				{
					if (pass == 361)
					{
						draw();
					}
					else if (pass == 1)
					{
						xc[q][p] = 1;
						pass = pass + 1;
						a[q][p].step = pass;
						show(xc, a);
					}
					else if ((pass % 4 == 0 || pass % 4 == 1) && xc[q][p] == 0)
					{
						xc[q][p] = 1;
						pass = pass + 1;
						a[q][p].step = pass;
						show(xc, a);
						//判断黑子是否连六
						if (judge(xc) == 1)
						{
							black_win();
						}
					}
					else if ((pass % 4 == 2 || pass % 4 == 3) && xc[q][p] == 0)
					{
						xc[q][p] = 2;
						pass = pass + 1;
						a[q][p].step = pass;
						show(xc, a);
						//判断白子是否连六
						if (judge(xc) == 2)
						{
							white_win();
						}
					}
				}
				else if (inputi == 22222)//新开局
				{
					chessboard();
					clear(xc, a);
					pass = 1;
				}
				else if (inputi == 33333)//悔棋
				{
					undo(a, xc, &pass);
					chessboard();
					show(xc, a);
				}
				else if (inputi == 44444)//退出
				{
					end();
				}
				else if (inputi == 55555)//重选模式
				{
					break;
				}
				else if (inputi == 66666)//帮助
				{
					help();
					if (quit_help() == 1)
					{
						chessboard();
						show(xc, a);
					}
				}
			}//循环
		}//choosei=1

		/********************************************************************************/
		/*************************************人机***************************************/
		/********************************************************************************/

		if (choosei == 2)
		{
			clear(xc, a);
			chessboard();
			choose_aii = choose_ai();
			choose_orderi = choose_order();

			if(choose_aii == 1)
			{
			/*************************************先手***************************************/
			if (choose_orderi == 1)
			{
				chessboard();
				while (true)
				{
					if (pass == 361)
						draw();

					else if (pass == 1)
					{
						inputi = input();
						q = inputi % 100;
						p = (inputi - (inputi % 100)) / 100;
						if ((inputi <= 1818 && inputi >= 0) && (xc[q][p] == 0))
						{
							xc[q][p] = 1;
							pass = pass + 1;
							a[q][p].step = pass;
							setfillcolor(WHITE);
							show(xc, a);
						}
						else if (inputi == 22222)//新开局
						{
							chessboard();
							clear(xc, a);
							pass = 1;
						}
						else if (inputi == 44444)//退出
							end();
						else if (inputi == 55555)//重选模式
							break;
						else if (inputi == 66666)//帮助
						{
							help();
							if (quit_help() == 1)
							{
								chessboard();
								show(xc, a);
							}
						}
					}

					else if (pass % 4 == 0 || pass % 4 == 1)
					{
						inputi = input();
						q = inputi % 100;
						p = (inputi - (inputi % 100)) / 100;
						if ((inputi <= 1818 && inputi >= 0) && (xc[q][p] == 0))
						{
							xc[q][p] = 1;
							pass = pass + 1;
							a[q][p].step = pass;
							setfillcolor(WHITE);
							show(xc, a);
							if (judge(xc) == 1)
							{
								black_win();
								break;
							}
						}
						else if (inputi == 22222)//新开局
						{
							chessboard();
							clear(xc, a);
							pass = 1;
						}
						else if (inputi == 33333)//悔棋
						{
							no_undo();
							if (quit_undo() == 1)
							{
								chessboard();
								show(xc, a);
							}
						}
						else if (inputi == 44444)//退出
						{
							end();
						}
						else if (inputi == 55555)//重选模式
						{
							break;
						}
						else if (inputi == 66666)//帮助
						{
							help();
							if (quit_help() == 1)
							{
								chessboard();
								show(xc, a);
							}
						}
					}


					else if (pass % 4 == 2 || pass % 4 == 3)
					{
						setfillcolor(WHITE);
						AI_xian(xc, &pass);
						a[q][p].step = pass;
						//判断白子是否连六
						if (judge(xc) == 2)
							white_win();
						
					}
				}
			}//choose_orderi=1


			/*************************************后手***************************************/
			if (choose_orderi == 2)
			{
				chessboard();
				while (true)
				{
					if (pass == 361)
						draw();

					else if (pass == 1)
					{
						setfillcolor(BLACK);
						xc[10][10] = 2;
						show1(xc, a);
						a[10][10].step = pass;
						pass = pass + 1;
					}

					else if (pass % 4 == 2 || pass % 4 == 3)
					{
						inputi = input();
						q = inputi % 100;
						p = (inputi - (inputi % 100)) / 100;
						if ((inputi <= 1818 && inputi >= 0) && (xc[q][p] == 0))
						{
							xc[q][p] = 1;
							pass = pass + 1;
							a[q][p].step = pass;
							show1(xc, a);
							if (judge(xc) == 1)
								white_win();
						}
						else if (inputi == 22222)//新开局
						{
							chessboard();
							clear(xc, a);
							pass = 1;
						}
						else if (inputi == 33333)//悔棋
						{
							no_undo();
							if (quit_undo() == 1)
							{
								chessboard();
								show(xc, a);
							}
						}
						else if (inputi == 44444)//退出
						{
							end();
						}
						else if (inputi == 55555)//重选模式
						{
							break;
						}
						else if (inputi == 66666)//帮助
						{
							help();
							if (quit_help() == 1)
							{
								chessboard();
								show1(xc, a);
							}
						}
					}


					else if (pass % 4 == 0 || pass % 4 == 1)
					{
						setfillcolor(BLACK);
						AI_hou(xc, &pass);
						a[q][p].step = pass;
						//判断黑子是否连六
						if (judge(xc) == 2)
							black_win();
					}
				}
			}//choose_orderi=2
			}


			//**********************************AI2******************************************
			if (choose_aii == 2 || choose_aii == 3)
			{
			//*************************************先手**************************************
			if (choose_orderi == 1)
			{
				chessboard();
				while (true)
				{
					if (pass == 361)
						draw();

					else if (pass == 1)
					{
						inputi = input();
						q = inputi % 100;
						p = (inputi - (inputi % 100)) / 100;
						if ((inputi <= 1818 && inputi >= 0) && (xc[q][p] == 0))
						{
							xc[q][p] = 1;
							pass = pass + 1;
							a[q][p].step = pass;
							setfillcolor(WHITE);
							show(xc, a);
						}
						else if (inputi == 22222)//新开局
						{
							chessboard();
							clear(xc, a);
							pass = 1;
						}
						else if (inputi == 44444)//退出
							end();
						else if (inputi == 55555)//重选模式
							break;
						else if (inputi == 66666)//帮助
						{
							help();
							if (quit_help() == 1)
							{
								chessboard();
								show(xc, a);
							}
						}
					}

					else if (pass % 4 == 0 || pass % 4 == 1)
					{
						inputi = input();
						q = inputi % 100;
						p = (inputi - (inputi % 100)) / 100;
						if ((inputi <= 1818 && inputi >= 0) && (xc[q][p] == 0))
						{
							xc[q][p] = 1;
							pass = pass + 1;
							a[q][p].step = pass;
							setfillcolor(WHITE);
							show(xc, a);
							if (judge(xc) == 1)
							{
								black_win();
							}
						}
						else if (inputi == 22222)//新开局
						{
							chessboard();
							clear(xc, a);
							pass = 1;
						}
						else if (inputi == 33333)//悔棋
						{
							if (pass % 4 == 1)
							{
								undo(a, xc, &pass);
							}
							else if (pass % 4 == 0)
							{
								undo(a, xc, &pass);
								undo(a, xc, &pass);
								undo(a, xc, &pass);
							}
							chessboard();
							show(xc, a);
						}
						else if (inputi == 44444)//退出
						{
							end();
						}
						else if (inputi == 55555)//重选模式
						{
							break;
						}
						else if (inputi == 66666)//帮助
						{
							help();
							if (quit_help() == 1)
							{
								chessboard();
								show(xc, a);
							}
						}
					}


					else if (pass % 4 == 2 || pass % 4 == 3)
					{
						setfillcolor(WHITE);
						AI2(xc,vv,&pass,a);
						AI2(xc,vv,&pass,a);
						dot(a, &pass);
						//判断白子是否连六
						if (judge(xc) == 2)
						{
							white_win();
						}
						
					}
				}
			}//choose_orderi=1


			/*************************************后手***************************************/
			if (choose_orderi == 2)
			{
				chessboard();
				while (true)
				{
					if (pass == 361)
						draw();

					else if (pass == 1)
					{
						setfillcolor(BLACK);
						xc[10][10] = 2;
						show1(xc, a);
						a[10][10].step = pass;
						pass = pass + 1;
					}

					else if (pass % 4 == 2 || pass % 4 == 3)
					{
						inputi = input();
						q = inputi % 100;
						p = (inputi - (inputi % 100)) / 100;
						if ((inputi <= 1818 && inputi >= 0) && (xc[q][p] == 0))
						{
							xc[q][p] = 1;
							pass = pass + 1;
							a[q][p].step = pass;
							show1(xc, a);
							if (judge(xc) == 1)
								white_win();
						}
						else if (inputi == 22222)//新开局
						{
							chessboard();
							clear(xc, a);
							pass = 1;
						}
						else if (inputi == 33333)//悔棋
						{
							if (pass % 4 == 2)
							{
								undo(a, xc, &pass);
								undo(a, xc, &pass);
								undo(a, xc, &pass);
							}
							else if (pass % 4 == 3)
							{
								undo(a, xc, &pass);
							}
							chessboard();
							show1(xc, a);
						}
						else if (inputi == 44444)//退出
						{
							end();
						}
						else if (inputi == 55555)//重选模式
						{
							break;
						}
						else if (inputi == 66666)//帮助
						{
							help();
							if (quit_help() == 1)
							{
								chessboard();
								show1(xc, a);
							}
						}
					}


					else if (pass % 4 == 0 || pass % 4 == 1)
					{
						setfillcolor(BLACK);
						AI2(xc,vv,&pass,a);
						AI2(xc,vv,&pass,a);
						show1(xc, a);
						dot(a, &pass);
						//判断黑子是否连六
						if (judge(xc) == 2)
							black_win();
						
					}
				}
			}//choose_orderi=2

			}//choose_aii = 2


		}//choosei=2
	}//整体循环

}