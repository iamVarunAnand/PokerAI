#include<iostream.h>
#include<conio.h>
#include"function.cpp"

long float is2pair(int size,int N,int r,int a[])
{
		int c[13]={0};
		long float p2pair=0;
		for(int i=0,j=0;i<13&&j<size;i++)
		{
			int t=a[j];
			while(a[++j]==t)
			{
				c[i]++;
			}
			c[i]++; // Assign values to c
		}
		int 	npair=0;
		i=0;
		while(c[i]!=0)
		{
			if(c[i]==2)npair++;
			i++;
		}

		for(i=0;(i<13)&&(p2pair!=1)&&(c[i]!=0);i++)
		{
			if(npair==2)p2pair=1;
			else if((npair==1)&&(c[i]!=2))
			{
				if((c[i]<=r)&&r!=0&&r!=1)
				{
					if(c[i]==1)p2pair=p2pair+float(combine(r,1)*combine(3,1)*permute(N-1,r-1)/combine(N,r));
					 else p2pair=p2pair+float(combine(r,2)*combine(4,2)*permute(N-2,r-2)/combine(N,r));
				}
				else if((c[i]<=r)&&r==1)
				{
					if(c[i]==1)p2pair=p2pair+float(combine(3,1))/combine(N,1);
					 else p2pair=0;
				}
				else
				{
					int j=i;
					while(c[j]!=0&&p2pair!=1)
					{
						if(c[j]==2)p2pair=1;
						 else p2pair=0;
						j++;
					}
				}
			}
			else if(npair==0&&r>=4)
			{
				if(r==4)p2pair=float(combine(12,2)*combine(4,2)*combine(4,2)+combine(12,1)*combine(3,1)*combine(4,2))/combine(N,r);
				 else if(r==5)p2pair=5*float(combine(13,2)*combine(4,2)*combine(4,2)*combine(N-4,1))/combine(N,r);
			}
		}
		return p2pair;
}
void main()
{
	clrscr();

	int a[5]={2};
	int N=49,R=4,size=1;
	long float p;
	p=is2pair(size,N,R,a);
	cout<<p;
	getch();
}