#include<iostream.h>
#include<conio.h>

void sort_cards(int gcard[],char gsuit[],int gsize,int pcard[],char psuit[])
{
	if(pcard[0]<pcard[1]) //sorts player's cards in descending order
	{
		int t=pcard[0];          char ts=psuit[0];
		pcard[0]=pcard[1];        psuit[0]=psuit[1];
		pcard[1]=t;               psuit[1]=ts;
	}
	for(int i=0;i<gsize-1;i++) //sorts game cards in desccending order
	{
		for(int j=0;j<gsize-i-1;j++)
			if(gcard[j]<gcard[j+1])
			{
				int t=gcard[j];     char ts=gsuit[j];
				gcard[j]=gcard[j+1];      gsuit[j]=gsuit[j+1];
				gcard[j+1]=t;        gsuit[j+1]=ts;
			}
	}
}
int straight_check(int gcard[],char gsuit[],int gsize,int pcard[],char psuit[],int scard[],char ssuit[])
{
	int I,J,K,c;
	I=J=K=c=0;

      /*	int pcard[2],gcard[5];
	for(int x=0;x<2;x++)
		pcard[x]=b[x];

	for(int y=0;y<5;y++)
		gcard[y]=a[y];   */


	int cur_card;

	if(pcard[I]>=gcard[J])
	{
		cur_card=pcard[I];
		scard[K]=pcard[I];
		ssuit[K]=psuit[I];
		c++;I++;K++;
	}
	else if(gcard[J]>pcard[I])
	{
		cur_card=gcard[J];
		scard[K]=gcard[J];
		ssuit[K]=gsuit[J];
		c++;J++;K++;
	}

	int tafter[5]={0},tbefore[5]={0};
	for(int i=0;i<4;i++)
	{
		if(cur_card+i+1<=14)tafter[i]=cur_card+i+1;
		if(cur_card-i-1>=2)tbefore[i]=cur_card-i-1;
	}
	while(I<2&&c!=5)
	{
		if(I==0)
		{
			for(int j=0,k=0;(tafter[j]!=0||tbefore[k]!=0);j++,k++)
			{
				if(tafter[j]!=0&&pcard[I]==tafter[j])
				{
					c++;
					scard[K]=pcard[I];
					ssuit[K]=psuit[I];
					K++;
				}
				else if(tbefore[k]!=0&&pcard[I]==tbefore[k])
				{
					c++;
					scard[K]=pcard[I];
					ssuit[K]=psuit[I];
					K++;
				}
			}
		}
		else if(pcard[I]!=pcard[I-1])
		{
			 for(int j=0,k=0;(tafter[j]!=0||tbefore[k]!=0);j++,k++)
			 {
				if(tafter[j]!=0&&pcard[I]==tafter[j])
				{
					c++;
					scard[K]=pcard[I];
					ssuit[K]=psuit[I];
					K++;
				}
				else if(tbefore[k]!=0&&pcard[I]==tbefore[k])
				{
					c++;
					scard[K]=pcard[I];
					ssuit[K]=psuit[I];
					K++;
				}
			 }
		}
		I++;
	}
	while(J<5&&c!=5)
	{
		if(J==0)
		{
			for(int j=0,k=0;(tafter[j]!=0||tbefore[k]!=0);j++,k++)
			{
				if(tafter[j]!=0&&gcard[J]==tafter[j])
				{
					c++;
					scard[K]=gcard[J];
					ssuit[K]=gsuit[J];
					K++;
				}
				else if(tbefore[k]!=0&&gcard[J]==tbefore[k])
				{
					c++;
					scard[K]=gcard[J];
					ssuit[K]=gsuit[J];
					K++;
				}
			}
		}
		else if(gcard[J]!=gcard[J-1])
		{
			for(int j=0,k=0;(tafter[j]!=0||tbefore[k]!=0);j++,k++)
			{
				if(tafter[j]!=0&&gcard[J]==tafter[j])
				{
					c++;
					scard[K]=gcard[J];
					ssuit[K]=gsuit[J];
					K++;
				}
				else if(tbefore[k]!=0&&gcard[J]==tbefore[k])
				{
					c++;
					scard[K]=gcard[J];
					ssuit[K]=gsuit[J];
					K++;
				}
			}
		}
		J++;
	}

	if(c!=5)
	{
		for(int i=0;i<5;i++)
		{
			scard[i]=0;
			ssuit[i]='\0';
		}
		return 0;
	}
	else if(c==5)return 1;
}
void merge_cards(int gcard[],char gsuit[],int gsize,int ssize,int pcard[],char psuit[],int scard[],char ssuit[])//merges 5 best cards
{
	int     i,j,k;
		i=j=k=0;

	if(straight_check(gcard,gsuit,gsize,pcard,psuit,scard,ssuit)==0) // scard empty
	{
		i=j=k=0;
		while((i<2)&&(j<gsize)&&(k<ssize))
		{
			if(pcard[i]<=gcard[j])
			{
				scard[k]=gcard[j];
				ssuit[k]=gsuit[j];
				j++;k++;
				if(pcard[i]==gcard[j])i++;
			}
			else if(pcard[i]>gcard[j])
			{
				scard[k]=pcard[i];
				ssuit[k]=psuit[i];
				k++;i++;
			}
			/*else if(pcard[i]==gcard[j])
			{
				i++;j++;
			}
			if(k>0&&(scard[k]==scard[k-1]))k--;
			k++;                  */
		}
		if(k!=ssize)
		{
			while((i<2)&&(k<ssize))
			{
				scard[k]=pcard[i];
				ssuit[k]=psuit[i];
				if(k>0&&(scard[k]==scard[k-1]))k--;
				k++;
				i++;
			}
		}
		if(k!=ssize)
		{
			while((j<gsize)&&(k<ssize))
			{
				scard[k]=gcard[j];
				ssuit[k]=gsuit[j];
				if(k>0&&(scard[k]==scard[k-1]))k--;
				j++;k++;
			}
		}
	}
}
void main()
{
	clrscr();

	int pcard[2]={14,2};
	char psuit[2]={3,6};

	int gcard[5]={13,10,4,1,5};
	//gcard[0]=2;gcard[1]=5;gcard[2]=8;gcard[3]=11;gcard[4]=14;
	int scard[5]={0};
	char gsuit[6]={6,6,4,3,5};
	char ssuit[6];
	int gsize=5,ssize=5;

	sort_cards(gcard,gsuit,gsize,pcard,psuit);

	cout<<pcard[0]<<'\t'<<pcard[1]<<endl;
	cout<<psuit[0]<<'\t'<<psuit[1]<<endl<<endl;

	for(int i=0;i<4;i++)
	{
		cout<<gcard[i]<<'\t';
	}
	cout<<endl;
	for(i=0;i<4;i++)
	{
		cout<<gsuit[i]<<'\t';
	}
	cout<<endl;
	cout<<"Straight?= "<<straight_check(gcard,gsuit,gsize,pcard,psuit,scard,ssuit)<<endl;

	merge_cards(gcard,gsuit,gsize,ssize,pcard,psuit,scard,ssuit);

	for(i=0;i<5;i++)
	{
		cout<<scard[i]<<'\t';
	}
	cout<<endl;
	for(i=0;i<5;i++)
	{
		cout<<ssuit[i]<<'\t';
	}

	getch();
}