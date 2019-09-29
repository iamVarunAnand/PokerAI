#include<iostream.h>
#include<conio.h>
#include"function.cpp"


long float is3kind(int size,int N,int r,int a[])
{
	for(int i=0;i<size-1;i++) //sorts best cards on the basis of cards
	{
		for(int j=0;j<size-i-1;j++)
		{
			if(a[j]<a[j+1])
			{
				int t=a[j];     	    // char ts=ssuit[j];
				a[j]=a[j+1];         //	     ssuit[j]=ssuit[j+1];
				a[j+1]=t;        	     //	     ssuit[j+1]=ts;
			}
		}
	}

	int c[13]={0};// Stores no. of cards for each card
	int j=0;

	for(i=0;((i<13)&&(j<size));i++) //Loop to assign values to 'c';
	{
		char t=a[j];
		while(a[j]==t)
		{
			c[i]++;
			j++;
		}
	}
	long float p3kind=0;
	for(i=0;i<13;i++) //4 of a kind probability calculation
	{
		if((c[i]!=0)&&(3-c[i]<=r))
		{
			if(3-c[i]==r)p3kind=p3kind+float(fact(4-c[i]))/combine(N,r);
			else p3kind=p3kind+float((permute(r,3-c[i])*permute(c[i]+N-3,c[i]+r-3)))/combine(N,r);
		}
	}
	return p3kind;
}
void main()
{
	clrscr();

	int a[5]={3,3,2,6,1};
	int N=47,R=2,size=5;
	long float p=is3kind(size,N,R,a);
	cout<<p;

	getch();
}