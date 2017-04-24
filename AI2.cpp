#include <graphics.h>
#include <conio.h>
#include <math.h>

struct Point
{
	int x;
	int y;
	int step;
};

void AI2(int(*xc)[20], int(*vv)[20], int *pass, Point (*a)[20])
{
    int s,k;

	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			vv[i][j]=0;
		}
	}

    //********************************�����ֵ*********************************************
	//*************************************************************************************
	//*************************************************************************************

	for(int i=1;i<=19;i++)
	{
		for(int j=1;j<=14;j++)
		{
			s=xc[i][j]+xc[i][j+1]+xc[i][j+2]+xc[i][j+3]+xc[i][j+4]+xc[i][j+5];
			k=0;

		    for(int i1=0;i1<=5;i1++)
			{
				if(xc[i][j+i1]==0)
				{
					k=k+1;
				}
			}

			if(s==10&&k==1)
			{
				for(int i1=0;i1<=5;i1++)
				{
					if(xc[i][j+i1]==0)
					{
                        vv[i][j+i1]+=100000;
					}
				}
			}
			if(s==8&&k==2)
			{
				for(int i1=0;i1<=5;i1++)
				{
					if(xc[i][j+i1]==0)
					{
                        vv[i][j+i1]+=30000;
					}
				}
			}
			if(s==5&&k==1)
			{
				for(int i1=0;i1<=5;i1++)
				{
					if(xc[i][j+i1]==0)
					{
                        vv[i][j+i1]+=10000;
					}
				}
			}
			if(s==4&&k==2)
			{
				for(int i1=0;i1<=5;i1++)
				{
					if(xc[i][j+i1]==0)
					{
                        vv[i][j+i1]+=4000;
					}
				}
			}
			if(s==6&&k==3)
			{
				for(int i1=0;i1<=5;i1++)
				{
					if(xc[i][j+i1]==0)
					{
                        vv[i][j+i1]+=1500;
					}
				}
			}
			if(s==3&&k==3)
			{
				for(int i1=0;i1<=5;i1++)
				{
					if(xc[i][j+i1]==0)
					{
                        vv[i][j+i1]+=700;
					}
				}
			}
			if(s==4&&k==4)
			{
				for(int i1=0;i1<=5;i1++)
				{
					if(xc[i][j+i1]==0)
					{
                        vv[i][j+i1]+=300;
					}
				}
			}
			if(s==2&&k==4)
			{
				for(int i1=0;i1<=5;i1++)
				{
					if(xc[i][j+i1]==0)
					{
                        vv[i][j+i1]+=100;
					}
				}
			}
			if(s==2&&k==5)
			{
				for(int i1=0;i1<=5;i1++)
				{
					if(xc[i][j+i1]==0)
					{
                        vv[i][j+i1]+=40;
					}
				}
			}
			if(s==1&&k==5)
			{
				for(int i1=0;i1<=5;i1++)
				{
					if(xc[i][j+i1]==0)
					{
                        vv[i][j+i1]+=15;
					}
				}
			}
		}
	}

		//********************************�����ֵ*********************************************
	    //*************************************************************************************
	    //*************************************************************************************
	for(int i=1;i<=19;i++)
	{
		for(int j=1;j<=14;j++)
		{
			s=xc[j][i]+xc[j+1][i]+xc[j+2][i]+xc[j+3][i]+xc[j+4][i]+xc[j+5][i];
			k=0;

		    for(int i1=0;i1<=5;i1++)
			{
				if(xc[j+i1][i]==0)
				{
					k=k+1;
				}
			}

			if(s==10&&k==1)
			{
				for(int i1=0;i1<=5;i1++)
				{
					if(xc[j+i1][i]==0)
					{
                        vv[j+i1][i]+=100000;
					}
				}
			}
			if(s==8&&k==2)
			{
				for(int i1=0;i1<=5;i1++)
				{
					if(xc[j+i1][i]==0)
					{
                        vv[j+i1][i]+=30000;
					}
				}
			}
			if(s==5&&k==1)
			{
				for(int i1=0;i1<=5;i1++)
				{
					if(xc[j+i1][i]==0)
					{
                        vv[j+i1][i]+=10000;
					}
				}
			}
			if(s==4&&k==2)
			{
				for(int i1=0;i1<=5;i1++)
				{
					if(xc[j+i1][i]==0)
					{
                        vv[j+i1][i]+=4000;
					}
				}
			}
			if(s==6&&k==3)
			{
				for(int i1=0;i1<=5;i1++)
				{
					if(xc[j+i1][i]==0)
					{
                        vv[j+i1][i]+=1500;
					}
				}
			}
			if(s==3&&k==3)
			{
				for(int i1=0;i1<=5;i1++)
				{
					if(xc[j+i1][i]==0)
					{
                        vv[j+i1][i]+=700;
					}
				}
			}
			if(s==4&&k==4)
			{
				for(int i1=0;i1<=5;i1++)
				{
					if(xc[j+i1][i]==0)
					{
                        vv[j+i1][i]+=300;
					}
				}
			}
			if(s==2&&k==4)
			{
				for(int i1=0;i1<=5;i1++)
				{
					if(xc[j+i1][i]==0)
					{
                        vv[j+i1][i]+=100;
					}
				}
			}
			if(s==2&&k==5)
			{
				for(int i1=0;i1<=5;i1++)
				{
					if(xc[j+i1][i]==0)
					{
                        vv[j+i1][i]+=40;
					}
				}
			}
			if(s==1&&k==5)
			{
				for(int i1=0;i1<=5;i1++)
				{
					if(xc[j+i1][i]==0)
					{
                        vv[j+i1][i]+=15;
					}
				}
			}
		}
	}

	//********************************\��ֵ************************************************
	//*************************************************************************************
	//*************************************************************************************

	for(int i=1;i<=14;i++)
	{
		for(int j=1;j<=15-i;j++)
		{
	    //***************��\���Ϸ�*************************
			s=xc[j][j+i-1]+xc[j+1][i+j]+xc[j+2][i+j+1]+xc[j+3][i+j+2]+xc[j+4][i+j+3]+xc[j+5][j+i+4];
			k=0;

			for(int i1=0;i1<=5;i1++)
			{
				if(xc[j+i1][j+i-1+i1]==0)
				{
					k=k+1;
				}
			}
       
			if(s==10&&k==1)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[j+i1][j+i-1+i1]==0)
					{
						vv[j+i1][j+i-1+i1]+=100000;
					}
				}
			}
			if(s==5&&k==1)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[j+i1][j+i-1+i1]==0)
					{
						vv[j+i1][j+i-1+i1]+=10000;
					}
				}
			}
			if(s==8&&k==2)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[j+i1][j+i-1+i1]==0)
					{
						vv[j+i1][j+i-1+i1]+=30000;
					}
				}
			}
			if(s==4&&k==2)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[j+i1][j+i-1+i1]==0)
					{
						vv[j+i1][j+i-1+i1]+=4000;
					}
				}
			}
			if(s==6&&k==3)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[j+i1][j+i-1+i1]==0)
					{
						vv[j+i1][j+i-1+i1]+=1500;
					}
				}
			}
			if(s==3&&k==3)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[j+i1][j+i-1+i1]==0)
					{
						vv[j+i1][j+i-1+i1]+=700;
					}
				}
			}
			if(s==4&&k==4)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[j+i1][j+i-1+i1]==0)
					{
						vv[j+i1][j+i-1+i1]+=300;
					}
				}
			}
			if(s==2&&k==4)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[j+i1][j+i-1+i1]==0)
					{
						vv[j+i1][j+i-1+i1]+=100;
					}
				}
			}
			if(s==2&&k==5)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[j+i1][j+i-1+i1]==0)
					{
						vv[j+i1][j+i-1+i1]+=40;
					}
				}
			}
			if(s==1&&k==5)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[j+i1][j+i-1+i1]==0)
					{
						vv[j+i1][j+i-1+i1]+=15;
					}
				}
			}

		    s=xc[j+i-1][j]+xc[j+i][j+1]+xc[j+i+1][j+2]+xc[j+i+2][j+3]+xc[j+i+3][j+4]+xc[j+i+4][j+5];
			k=0;

			for(int i1=0;i1<=5;i1++)
			{
				if(xc[j+i-1+i1][j+i1]==0)
				{
					k=k+1;
				}
			}
            
			if(s==10&&k==1)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[j+i-1+i1][j+i1]==0)
					{
						vv[j+i-1+i1][j+i1]+=100000;
					}
				}
			}
			if(s==5&&k==1)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[j+i-1+i1][j+i1]==0)
					{
						vv[j+i-1+i1][j+i1]+=10000;
					}
				}
			}
			if(s==8&&k==2)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[j+i-1+i1][j+i1]==0)
					{
						vv[j+i-1+i1][j+i1]+=30000;
					}
				}
			}
			if(s==4&&k==2)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[j+i-1+i1][j+i1]==0)
					{
						vv[j+i-1+i1][j+i1]+=4000;
					}
				}
			}
			if(s==6&&k==3)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[j+i-1+i1][j+i1]==0)
					{
						vv[j+i-1+i1][j+i1]+=1500;
					}
				}
			}
			if(s==3&&k==3)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[j+i-1+i1][j+i1]==0)
					{
						vv[j+i-1+i1][j+i1]+=700;
					}
				}
			}
			if(s==4&&k==4)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[j+i-1+i1][j+i1]==0)
					{
						vv[j+i-1+i1][j+i1]+=300;
					}
				}
			}
			if(s==2&&k==4)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[j+i-1+i1][j+i1]==0)
					{
						vv[j+i-1+i1][j+i1]+=100;
					}
				}
			}
			if(s==2&&k==5)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[j+i-1+i1][j+i1]==0)
					{
						vv[j+i-1+i1][j+i1]+=40;
					}
				}
			}
			if(s==1&&k==5)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[j+i-1+i1][j+i1]==0)
					{
						vv[j+i-1+i1][j+i1]+=15;
					}
				}
			}
		}
	}

	//******************/********************************
	//***************************************************
	//***************************************************
	for(int i=1;i<=14;i++)
	{
		for(int j=1;j<=15-i;j++)
		{
	    //***************��/���Ϸ�*************************
			s=xc[20-j][j+i-1]+xc[20-(j+1)][i+j]+xc[20-(j+2)][i+j+1]+xc[20-(j+3)][i+j+2]+xc[20-(j+4)][i+j+3]+xc[20-(j+5)][j+i+4];
			k=0;

			for(int i1=0;i1<=5;i1++)
			{
				if(xc[20-(j+i1)][j+i-1+i1]==0)
				{
					k=k+1;
				}
			}

			if(s==10&&k==1)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[20-(j+i1)][j+i-1+i1]==0)
					{
						vv[20-(j+i1)][j+i-1+i1]+=100000;
					}
				}
			}
			if(s==5&&k==1)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[20-(j+i1)][j+i-1+i1]==0)
					{
						vv[20-(j+i1)][j+i-1+i1]+=10000;
					}
				}
			}
			if(s==8&&k==2)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[20-(j+i1)][j+i-1+i1]==0)
					{
						vv[20-(j+i1)][j+i-1+i1]+=30000;
					}
				}
			}
			if(s==4&&k==2)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[20-(j+i1)][j+i-1+i1]==0)
					{
						vv[20-(j+i1)][j+i-1+i1]+=4000;
					}
				}
			}
			if(s==6&&k==3)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[20-(j+i1)][j+i-1+i1]==0)
					{
						vv[20-(j+i1)][j+i-1+i1]+=1500;
					}
				}
			}
			if(s==3&&k==3)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[20-(j+i1)][j+i-1+i1]==0)
					{
						vv[20-(j+i1)][j+i-1+i1]+=700;
					}
				}
			}
			if(s==4&&k==4)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[20-(j+i1)][j+i-1+i1]==0)
					{
						vv[20-(j+i1)][j+i-1+i1]+=300;
					}
				}
			}
			if(s==2&&k==4)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[20-(j+i1)][j+i-1+i1]==0)
					{
						vv[20-(j+i1)][j+i-1+i1]+=100;
					}
				}
			}
			if(s==2&&k==5)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[20-(j+i1)][j+i-1+i1]==0)
					{
						vv[20-(j+i1)][j+i-1+i1]+=40;
					}
				}
			}
			if(s==1&&k==5)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[20-(j+i1)][j+i-1+i1]==0)
					{
						vv[20-(j+i1)][j+i-1+i1]+=15;
					}
				}
			}

			s=xc[20-(j+i-1)][j]+xc[20-(j+i)][j+1]+xc[20-(j+i+1)][j+2]+xc[20-(j+i+2)][j+3]+xc[20-(j+i+3)][j+4]+xc[20-(j+i+4)][j+5];
			k=0;

			for(int i1=0;i1<=5;i1++)
			{
				if(xc[20-(j+i-1+i1)][j+i1]==0)
				{
					k=k+1;
				}
			}

			if(s==10&&k==1)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[20-(j+i-1+i1)][j+i1]==0)
					{
						vv[20-(j+i-1+i1)][j+i1]+=100000;
					}
				}
			}
			if(s==5&&k==1)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[20-(j+i-1+i1)][j+i1]==0)
					{
						vv[20-(j+i-1+i1)][j+i1]+=10000;
					}
				}
			}
			if(s==8&&k==2)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[20-(j+i-1+i1)][j+i1]==0)
					{
						vv[20-(j+i-1+i1)][j+i1]+=30000;
					}
				}
			}
			if(s==4&&k==2)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[20-(j+i-1+i1)][j+i1]==0)
					{
						vv[20-(j+i-1+i1)][j+i1]+=4000;
					}
				}
			}
			if(s==6&&k==3)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[20-(j+i-1+i1)][j+i1]==0)
					{
						vv[20-(j+i-1+i1)][j+i1]+=1500;
					}
				}
			}
			if(s==3&&k==3)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[20-(j+i-1+i1)][j+i1]==0)
					{
						vv[20-(j+i-1+i1)][j+i1]+=700;
					}
				}
			}
			if(s==4&&k==4)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[20-(j+i-1+i1)][j+i1]==0)
					{
						vv[20-(j+i-1+i1)][j+i1]+=300;
					}
				}
			}
			if(s==2&&k==4)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[20-(j+i-1+i1)][j+i1]==0)
					{
						vv[20-(j+i-1+i1)][j+i1]+=100;
					}
				}
			}
			if(s==2&&k==5)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[20-(j+i-1+i1)][j+i1]==0)
					{
						vv[20-(j+i-1+i1)][j+i1]+=40;
					}
				}
			}
			if(s==1&&k==5)
			{
				for(int i1=0;i1<=5;i1++)
			    {
					if(xc[20-(j+i-1+i1)][j+i1]==0)
					{
						vv[20-(j+i-1+i1)][j+i1]+=15;
					}
				}
			}
		}
	}

	//****************����λ�����֣���Ԫ���***************
	for(int i=1;i<=19;i++)
	{
		for(int j=1;j<=19;j++)
		{
			vv[i][j]=vv[i][j]+7-abs(10-i)+7-abs(10-j);
		}
	}

	//****************�������ֵ***************************

	for(int i=1;i<=19;i++)
	{
		for(int j=1;j<=19;j++)
		{
			int bigger;
			bigger=0;
			for(int i1=1;i1<=19;i1++)
			{
				for(int j1=1;j1<=19;j1++)
				{
					if(vv[i][j]>=vv[i1][j1])
					{
						bigger=bigger+1;
					}
				}
			}
			if(bigger==361&&xc[i][j]==0)
			{
				fillcircle(j*40,i*40,15);

				xc[i][j]=2;
				a[i][j].step = *pass;
				*pass=*pass+1;
                return;
			}
		}
	}
}