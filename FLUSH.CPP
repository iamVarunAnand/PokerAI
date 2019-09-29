#include<iostream.h>
#include<conio.h>
#include"function.cpp"



long float isflush(int size,int N,int r,char ssuit[])
{
	for(int i=0;i<size-1;i++) //sorts game cards on the basis of suits
	{
		for(int j=0;j<size-i-1;j++)
		{
			if(ssuit[j]<ssuit[j+1])
			{
				/*int t=scard[j]; */    	     char ts=ssuit[j];
				/*scard[j]=scard[j+1];*/      	     ssuit[j]=ssuit[j+1];
				/*scard[j+1]=t;*/        	     ssuit[j+1]=ts;
			}
		}
	}

	int c[4]={0};// Stores no. of cards of same suit for each suit
	int j=0;
	for(i=0;(i<4&&j<size);i++) //Loop to assign values to 'c';
	{
		char t=ssuit[j];
		while(ssuit[j]==t)
		{
			c[i]++;
			j++;
		}
	}
	long float pflush=0;

	for(i=0;i<4;i++) //FLUSH probability calculation
	{
		if((c[i]!=0)&&(5-c[i]<=r))
		{
			if(5-c[i]==r)pflush=pflush+float(permute(13-c[i],5-c[i]))/combine(N,r);
			 else pflush=pflush+float(combine(r,5-c[i])*permute(13-c[i],5-c[i])*permute(c[i]+N-5,c[i]+r-5))/combine(N,r);
		}
	}
	return pflush;
}
void main()
{
	clrscr();

	char a[6]={2,2,2,2,3,'\0'};
	int N=47,R=1,size=5;
	long float p=isflush(size,N,R,a);
	cout<<p;
	getch();
}