#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int judge(int (*xc)[20])
{
	//横向或纵向是否连六？
	for(int i1=1;i1<=14;i1++)
	{
       for(int i2=1;i2<=19;i2++)
      {
			if(xc[i2][i1]==1&&xc[i2][i1+1]==1&&xc[i2][i1+2]==1&&xc[i2][i1+3]==1&&xc[i2][i1+4]==1&&xc[i2][i1+5]==1)
			{
				return 1;
			}
			if(xc[i1][i2]==1&&xc[i1+1][i2]==1&&xc[i1+2][i2]==1&&xc[i1+3][i2]==1&&xc[i1+4][i2]==1&&xc[i1+5][i2]==1)
			{
				return 1;
			}
		    if(xc[i2][i1]==2&&xc[i2][i1+1]==2&&xc[i2][i1+2]==2&&xc[i2][i1+3]==2&&xc[i2][i1+4]==2&&xc[i2][i1+5]==2)
			{
				return 2;
			}
			if(xc[i1][i2]==2&&xc[i1+1][i2]==2&&xc[i1+2][i2]==2&&xc[i1+3][i2]==2&&xc[i1+4][i2]==2&&xc[i1+5][i2]==2)
			{
				return 2;
			}
       }
	}
	//斜向是否连六？
	for(int i5=1;i5<=14;i5++)
	{
		for(int i6=1;i6<=15-i5;i6++)
		{
			if(xc[i6][i6+i5-1]==1&&xc[i6+1][i5+i6]==1&&xc[i6+2][i5+i6+1]==1&&xc[i6+3][i5+i6+2]==1&&xc[i6+4][i5+i6+3]==1&&xc[i6+5][i6+i5+4]==1)
			{
				return 1;
			}
			if(xc[i6][i6+i5-1]==2&&xc[i6+1][i5+i6]==2&&xc[i6+2][i5+i6+1]==2&&xc[i6+3][i5+i6+2]==2&&xc[i6+4][i5+i6+3]==2&&xc[i6+5][i6+i5+4]==2)
			{
				return 2;
			}
			if(xc[i6+i5-1][i6]==1&&xc[i6+i5][i6+1]==1&&xc[i6+i5+1][i6+2]==1&&xc[i6+i5+2][i6+3]==1&&xc[i6+i5+3][i6+4]==1&&xc[i6+i5+4][i6+5]==1)
			{
				return 1;
			}
			if(xc[i6+i5-1][i6]==2&&xc[i6+i5][i6+1]==2&&xc[i6+i5+1][i6+2]==2&&xc[i6+i5+2][i6+3]==2&&xc[i6+i5+3][i6+4]==2&&xc[i6+i5+4][i6+5]==2)
			{
				return 2;
			}
			if(xc[20-i6][i6+i5-1]==1&&xc[19-i6][i5+i6]==1&&xc[18-i6][i5+i6+1]==1&&xc[17-i6][i5+i6+2]==1&&xc[16-i6][i5+i6+3]==1&&xc[15-i6][i6+i5+4]==1)
			{
				return 1;
			}
			if(xc[20-i6][i6+i5-1]==2&&xc[19-i6][i5+i6]==2&&xc[18-i6][i5+i6+1]==2&&xc[17-i6][i5+i6+2]==2&&xc[16-i6][i5+i6+3]==2&&xc[15-i6][i6+i5+4]==2)
			{
				return 2;
			}
			if(xc[20-(i6+i5-1)][i6]==1&&xc[20-(i6+i5)][i6+1]==1&&xc[20-(i6+i5+1)][i6+2]==1&&xc[20-(i6+i5+2)][i6+3]==1&&xc[20-(i6+i5+3)][i6+4]==1&&xc[20-(i6+i5+4)][i6+5]==1)
			{
				return 1;
			}
			if(xc[20-(i6+i5-1)][i6]==2&&xc[20-(i6+i5)][i6+1]==2&&xc[20-(i6+i5+1)][i6+2]==2&&xc[20-(i6+i5+2)][i6+3]==2&&xc[20-(i6+i5+3)][i6+4]==2&&xc[20-(i6+i5+4)][i6+5]==2)
			{
				return 2;
			}
		}
	}

	return 0;
}