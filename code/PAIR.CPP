#include<iostream.h>
#include<conio.h>
#include"function.cpp"
long float ispair(int size,int N,int r)
{
	int	c[13]={0};
	long float ppair=0;
	for(int i=0,j=0;i<13&&j<size;i++)
	{
			int t=scard[j];

			while(scard[++j]==t)
			{
				c[i]++;

			}
			c[i]++; // used to assign c-stores no. of each cards
	}

	for(i=0;(i<13)&&(ppair!=1)&&c[i]!=0;i++) //PROBABILITY CALCULATION FOR PAIR
	{
		if(c[i]>2)ppair=1;
		else if((c[i]<=r)&&r!=0&&r!=1)
		{
				if(c[i]==2)ppair=1;
					else if(c[i]==1)ppair=ppair+float(combine(r,1)*combine(3,1)*permute(N-1,r-1)/combine(N,r));
						else ppair=ppair+float(combine(r,2)*combine(4,2)*permute(N-2,r-2)/combine(N,r));
		}
		else if((c[i]<=r)&&r==1)
		{
			if(c[i]==1)ppair=ppair+float(combine(3,1))/combine(N,1);
				else ppair=0;
		}
		else
		{
			int j=0;
			while(c[j]!=0&&ppair!=1)
			{
				if(c[j]==2)ppair=1;
					else ppair=0;

				j++;
			}
		}
	}
	return ppair;
}
void main()
{
	clrscr();

	int a[5]={2,2};
	int N=50,R=5,size=2;
	long float p=ispair(size,N,R,a);
	cout<<p;

	getch();
}
