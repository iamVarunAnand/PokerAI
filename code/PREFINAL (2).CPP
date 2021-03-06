#include<iostream.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include"MOUSE-1.cpp"
#include"DISPLAY.cpp"
#include"WINSCREE.cpp"
#include"FRONT.cpp"
#include"D.cpp"
#include"function.cpp"

mouse M;
int N,R;

struct Deck //Main card deck
{
	int 	number[13][2];//1st int stores cards,2nd availability check
	char	suit;         //stores suit

}DOC[4];
struct player
{
		int 	pcard[2];
		char	psuit[2];
		int     scard[5];//holds best 5 cards
		int     ssuit[5];//holds suits of best 5 cards
	long    int     amt;
		int	bet_set;
		int	subset;
	long	int	bet_amt;
		int	action;


			void players()
			{
				bet_set=0;
				subset=0;
				bet_amt=0;
				action=0;
			}
			void assign_cards()
			{

				int 	asuit=random(4);
				int     bsuit=random(4);//suit variables to assign psuit values       888
				int	acard,bcard;//card variables to assign card values


					psuit[0]=DOC[asuit].suit;//initialises psuit values
					psuit[1]=DOC[bsuit].suit;
				randomize();
				do //loop to ensure card is available for distribution
				{
					acard=random(13);bcard=random(13);

				}while((DOC[asuit].number[acard][1]==0)||(DOC[bsuit].number[bcard][1]==0));

				//Player cards initialisation

				pcard[0]=DOC[asuit].number[acard][0];
					DOC[asuit].number[acard][1]=0;

				pcard[1]=DOC[bsuit].number[bcard][0];
					DOC[bsuit].number[bcard][1]=0;

			}
			void sort_cards(int gcard[],char gsuit[],int gsize)
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
			int straight_check(int gcard[],char gsuit[],int gsize)
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
void merge_cards(int gcard[],char gsuit[],int gsize,int ssize)//merges 5 best cards
{
	int     i,j,k;
		i=j=k=0;

	if(straight_check(gcard,gsuit,gsize)==0) // scard empty
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
			long float isrflush(int size,int N,int r)
			{
				for(int i=0;i<size-1;i++) //sorts game cards on the basis of suits
				{
					for(int j=0;j<size-i-1;j++)
					{
						if(ssuit[j]<ssuit[j+1])
						{
							int t=scard[j];     	     char ts=ssuit[j];
							scard[j]=scard[j+1];      	     ssuit[j]=ssuit[j+1];
							scard[j+1]=t;        	     ssuit[j+1]=ts;
						}

					}
				}

				int c[4]={0};// Stores no. of cards >=10 of same suit for each suit
				int j=0;

				for(i=0;((i<4)&&(j<size));i++) //Loop to assign values to 'c'
				{
						char t=ssuit[j];
						while(ssuit[j]==t)
						{
							if(scard[j]>=10)c[i]++;
							j++;
						}

				}
				long float prflush=0;

				for(i=0;i<4;i++) //ROYAL FLUSH probability calculation
				{
					if((c[i]!=0)&&(5-c[i]<=r))
					{
						if(5-c[i]==r)prflush=prflush+float(fact(5-c[i]))/combine(N,r);
						else prflush=prflush+float(combine(r,c[i])*fact(5-c[i])*permute(c[i]+N-5,c[i]+r-5))/combine(N,r);
					}
				}
				return prflush;
			}

			long float isstflush(int size,int N,int r)
			{
				return 0;
			}//just for now

			long float is4kind(int size,int N,int r)
			{
				for(int i=0;i<size-1;i++) //sorts best cards on the basis of cards
				{
					for(int j=0;j<size-i-1;j++)
					{
						if(scard[j]<scard[j+1])
						{
							int t=scard[j];     	     char ts=ssuit[j];
							scard[j]=scard[j+1];      	     ssuit[j]=ssuit[j+1];
							scard[j+1]=t;        	     	     ssuit[j+1]=ts;
						}

					}

				}

				int c[13]={0};// Stores no. of cards of same suit for each suit
				int j=0;

				for(i=0;((i<13)&&(j<size));i++) //Loop to assign values to 'c';
				{
						char t=scard[j];
						while(scard[j]==t)
						{
							c[i]++;
							j++;
						}

				}
				long float p4kind=0;

				for(i=0;i<13;i++) //4 of a kind probability calculation
				{
					if((c[i]!=0)&&(4-c[i]<=r))
					{
						if(4-c[i]==r)p4kind=p4kind+float(fact(4-c[i]))/combine(N,r);
						else p4kind=p4kind+float((permute(r,4-c[i])*permute(c[i]+N-4,c[i]+r-4)))/combine(N,r);
					}
				}
				return p4kind;
			}

			long float isflush(int size,int N,int r)
			{
				for(int i=0;i<size-1;i++) //sorts game cards on the basis of suits
				{
					for(int j=0;j<size-i-1;j++)
					{
						if(ssuit[j]<ssuit[j+1])
						{
							int t=scard[j];     	     char ts=ssuit[j];
							scard[j]=scard[j+1];      	     ssuit[j]=ssuit[j+1];
							scard[j+1]=t;        	     ssuit[j+1]=ts;
						}

					}
				}

				int c[4]={0};// Stores no. of cards of same suit for each suit
				int j=0;

				for(i=0;((i<4)&&j<size));i++) //Loop to assign values to 'c';
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
						else pflush=pflush+float((combine(r,c[i])*permute(13-c[i],5-c[i])*permute(c[i]+N-5,c[i]+r-5)))/combine(N,r);
					}
				}
				return pflush;
			}
			long float is3kind(int size,int N,int r)
			{
				for(int i=0;i<size-1;i++) //sorts best cards on the basis of cards
				{
					for(int j=0;j<size-i-1;j++)
					{
						if(scard[j]<scard[j+1])
						{
							int t=scard[j];     	     char ts=ssuit[j];
							scard[j]=scard[j+1];      	     ssuit[j]=ssuit[j+1];
							scard[j+1]=t;        	     	     ssuit[j+1]=ts;
						}

					}

				}

				int c[13]={0};// Stores no. of cards of same suit for each suit
				int j=0;

				for(i=0;((i<13)&&(j<size));i++) //Loop to assign values to 'c';
				{
						char t=scard[j];
						while(scard[j]==t)
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
			long float ispair(int ssize,int N,int r)
			{
				int	c[13]={0};
				long float ppair=0;
				for(int i=0,j=0;i<13&&j<ssize;i++)
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
			long float is2pair(int ssize,int N,int r)
			{
				int c[13]={0};
				long float p2pair=0;
				for(int i=0,j=0;i<13&&j<ssize;i++)
				{
					int t=scard[j];
					while(scard[++j]==t)
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

	void ACTION(int ssize)
	{
		  if(bet_set==1)
		  {
		    if(is3kind(ssize,N,R)>is2pair(ssize,N,R)&&is3kind(ssize,N,R)>ispair(ssize,N,R))subset=3;
			 else if(is2pair(ssize,N,R)>ispair(ssize,N,R))subset=2;
			   else subset=1;

			 switch(subset)
			 {
				case 1:switch(GAME_STATUS.raise!=0) // pair
				       {
					  case 1: if(GAME_STATUS.raise_amt>amt)
						   {
						   action=3;
						   GAME_STATUS.fold++;
						   }
						   else if(GAME_STATUS.raise_amt>2000)
						   {
						   action=3;//player's action
						   GAME_STATUS.fold++;
						   }
						   else if((GAME_STATUS.raise_amt>1000)&&(GAME_STATUS.raise_amt<2000))
						   {
						     action=4;
						     bet_amt=GAME_STATUS.raise_amt;
						     amt=amt-bet_amt;
						     GAME_STATUS.call++;
						     GAME_STATUS.pot_amt=GAME_STATUS.pot_amt+bet_amt;
						   }
						   else if(GAME_STATUS.raise_amt<=1000)
						   {
						    if(GAME_STATUS.fold>=2)
						    {
						     action=2;
						     bet_amt=GAME_STATUS.raise_amt+750;
						     amt=amt-bet_amt;
						     GAME_STATUS.raise++;
						     GAME_STATUS.raise_amt=bet_amt;
						     GAME_STATUS.pot_amt=GAME_STATUS.pot_amt+bet_amt;
						    }
						    else if(GAME_STATUS.check>=2)
						    {
						     action=2;
						     bet_amt=GAME_STATUS.raise_amt+500;
						     amt=amt-bet_amt;
						     GAME_STATUS.raise++;
						     GAME_STATUS.raise_amt=bet_amt;
						     GAME_STATUS.pot_amt=GAME_STATUS.pot_amt+bet_amt;
						    }
						    else
						    {
						     action=2;
						     bet_amt=GAME_STATUS.raise_amt+250;
						     amt=amt-bet_amt;
						     GAME_STATUS.raise++;
						     GAME_STATUS.raise_amt=bet_amt;
						     GAME_STATUS.pot_amt=GAME_STATUS.pot_amt+bet_amt;
						    }
						   }break;

					  case 0:{
						  action=1;
						  GAME_STATUS.check++;
						  outtextxy(300,300,"WRONG");
						 }break;
				       }break;
				case 2:switch(GAME_STATUS.raise!=0)// 2 pair
				       {
						case 1: {
							  if(GAME_STATUS.raise_amt>amt)
							  {
								action=3;
								GAME_STATUS.fold++;
							  }
							  if(GAME_STATUS.raise_amt>3000)
							  {
								action=3;//player's action
								GAME_STATUS.fold++;
							  }
							  else if((GAME_STATUS.raise_amt>2000)&&(GAME_STATUS.raise_amt<3000))
							  {
								action=4;
								bet_amt=GAME_STATUS.raise_amt;
								amt=amt-bet_amt;
								GAME_STATUS.call++;
							  }
							  else if(GAME_STATUS.raise_amt<=2000)
							  {
								if(GAME_STATUS.fold>=2)
								{
									action=2;
									bet_amt=GAME_STATUS.raise_amt+750;
									amt=amt-bet_amt;
									GAME_STATUS.raise++;
									GAME_STATUS.raise_amt=bet_amt;
								}
								else if(GAME_STATUS.check>=2)
								{
									action=2;
									bet_amt=GAME_STATUS.raise_amt+500;
									amt=amt-bet_amt;
									GAME_STATUS.raise++;
									GAME_STATUS.raise_amt=bet_amt;
								}
								else
								{
									action=2;
									bet_amt=GAME_STATUS.raise_amt+250;
									amt=amt-bet_amt;
									GAME_STATUS.raise++;
									GAME_STATUS.raise_amt=bet_amt;
								}
							  }
							 }break;
						case 0:  {
								action=2;
								bet_amt=2500;
								amt=amt-bet_amt;
								GAME_STATUS.raise++;
								GAME_STATUS.raise_amt=bet_amt;
							 }break;
				       }break;
				case 3:switch(GAME_STATUS.raise!=0)//3 of a kind
				       {
						case 1: {
							  if(GAME_STATUS.raise_amt>amt)
							  {
								action=3;
								GAME_STATUS.fold++;
							  }
							  else if(GAME_STATUS.raise_amt>5000)
							  {
								action=3;//player's action
								GAME_STATUS.fold++;
							  }
							  else if((GAME_STATUS.raise_amt>3000)&&(GAME_STATUS.raise_amt<5000))
							  {
								action=4;
								bet_amt=GAME_STATUS.raise_amt;
								amt=amt-bet_amt;
								GAME_STATUS.call++;
							  }
							  else if(GAME_STATUS.raise_amt<=3000)
							  {
								if(GAME_STATUS.fold>=2)
								{
									action=2;
									bet_amt=GAME_STATUS.raise_amt+750;
									amt=amt-bet_amt;
									GAME_STATUS.raise++;
									GAME_STATUS.raise_amt=bet_amt;
								}
								else if(GAME_STATUS.check>=2)
								{
									action=2;
									bet_amt=GAME_STATUS.raise_amt+500;
									amt=amt-bet_amt;
									GAME_STATUS.raise++;
									GAME_STATUS.raise_amt=bet_amt;
								}
								else
								{
									action=2;
									bet_amt=GAME_STATUS.raise_amt+250;
									amt=amt-bet_amt;
									GAME_STATUS.raise++;
									GAME_STATUS.raise_amt=bet_amt;
								}
							  }
							 }break;
						case 0:  {
								action=2;
								bet_amt=4500;
								amt=amt-bet_amt;
								GAME_STATUS.raise++;
								GAME_STATUS.raise_amt=bet_amt;
							 }break;
				       }break;
			 }
		  }// End of bet set 1 conditions

		  if(bet_set==3)
		  {
		       if(isrflush(ssize,N,R)>isstflush(ssize,N,R)&&isrflush(ssize,N,R)>is4kind(ssize,N,R))subset=3;
			 else if(isstflush(ssize,N,R)>is4kind(ssize,N,R))subset=2;
			      subset=1;

			 switch(subset)
			 {
				case 1:{
					if(GAME_STATUS.raise_amt>amt)
					{
						action=5;
						GAME_STATUS.allin++;
						bet_amt=amt;
						amt=0;
						GAME_STATUS.pot_amt=GAME_STATUS.pot_amt+bet_amt;
					}
					else
					{
						action=5;
						if(GAME_STATUS.max_bet==amt)GAME_STATUS.allin++;
						       else GAME_STATUS.raise++;

							bet_amt=GAME_STATUS.max_bet;
							amt=amt-bet_amt;
							GAME_STATUS.pot_amt=GAME_STATUS.pot_amt+bet_amt;
					}
				       }break; //End of royal flush conditions
				case 2:{
					if(GAME_STATUS.raise_amt>amt)
					{
						action=5;
						GAME_STATUS.allin++;
						bet_amt=amt;
						amt=0;
						GAME_STATUS.pot_amt=GAME_STATUS.pot_amt+bet_amt;
					}
					else
					{
						action=5;
						if(GAME_STATUS.max_bet==amt)GAME_STATUS.allin++;
						       else GAME_STATUS.raise++;

							bet_amt=GAME_STATUS.max_bet;
							amt=amt-bet_amt;
							GAME_STATUS.pot_amt=GAME_STATUS.pot_amt+bet_amt;
					}
				       }break; //End of st flush conditions
				case 3:{
					if(GAME_STATUS.raise_amt>amt)
					{
						action=5;
						GAME_STATUS.allin++;
						bet_amt=amt;
						amt=0;
						GAME_STATUS.pot_amt=GAME_STATUS.pot_amt+bet_amt;
					}
					else
					{
						action=5;
						if(GAME_STATUS.max_bet==amt)GAME_STATUS.allin++;
						       else GAME_STATUS.raise++;

							bet_amt=GAME_STATUS.max_bet;
							amt=amt-bet_amt;
							GAME_STATUS.pot_amt=GAME_STATUS.pot_amt+bet_amt;
					}
				       }break; //End of 4kind conditions
			 }
		  }// End of bet set 3 conditions
	}
}PLAYER[3],USER;

struct game
{
	int         check;
	int         raise;
	int         fold;
	int         call;
	int	    allin;
	long int    raise_amt;
	long int    pot_amt;
	long int    max_bet;
	int         start;
	int	    turn;

	public:     void games()
		    {
			check=raise=fold=call=allin=0;
			raise_amt=0;
			pot_amt=0;
			max_bet=0;
			start=0;
		    }
		    int count_raise()
		    {
				int c;
				for(int i=0;i<3;i++)
					if(PLAYER[i].action==2)c++;

				return c;
		    }
		    int ischeck()
		    {
				if(count_raise()==0)return 1;
					else return 0;
		    }

}GAME_STATUS;

void game()
{
	int     gcard[5]={0};
	char    gsuit[5]={0};
	int 	gsize;          //Different values for different iterations
	int	ssize; 		//Different values for different iterations

	for(int p=0;p<3;p++)
		PLAYER[p].amt=40000;

	USER.amt=40000;
	GAME_STATUS.start=0;
	GAME_STATUS.turn=0;

   for(int I=0;I<4;I++)
   {
	cleardevice();
	delay(2000);
	game_screen();
	N=50;R=5;
	GAME_STATUS.raise_amt=40000;

	for(int J=0;J<3;J++)
		PLAYER[J].players();

	USER.players();

	USER.assign_cards();

	DISPLAY_CARDS(270,365,USER.pcard[0],USER.psuit[0]);
	DISPLAY_CARDS(340,365,USER.pcard[1],USER.psuit[1]);

	for(J=0;J<3;J++)
	    PLAYER[J].assign_cards();

		int N=50; //No of cards-for counting in probability
		int R; // No. of displays left

	GAME_STATUS.games();

	if(GAME_STATUS.start==4)GAME_STATUS.start=1;
		else GAME_STATUS.start=GAME_STATUS.start+1;



	for(int i=1;i<=4;i++)  //ROUND LOOP STARTS
	{

		GAME_STATUS.turn=GAME_STATUS.start;

			if(i==1)  //if iteration is one transfer pcards to scards
			{
				ssize=2;
				gsize=0;
				R=5;
				for(int j=0;j<3;j++)
				{
					PLAYER[j].scard[0]=PLAYER[j].pcard[0];
					PLAYER[j].scard[1]=PLAYER[j].pcard[1];
					PLAYER[j].ssuit[0]=PLAYER[j].psuit[0];
					PLAYER[j].ssuit[1]=PLAYER[j].psuit[1];
				}
			}
			else if(i==2)
			{
				ssize=5;
				gsize=3;
				R=2;

				for(int j=0;j<gsize;j++)
				{
					int asuit=random(4);
					int acard;

					gsuit[j]=DOC[asuit].suit;

					do //loop to ensure card is available for distribution
					{
						acard=random(13);

					}while((DOC[asuit].number[acard][1]==0));

					gcard[j]=DOC[asuit].number[acard][0];
						DOC[asuit].number[acard][1]=0;

					N--; //Decrements total number of cards as gcard is assigned
				}
				j=0;
				for(int x1=150,y1=getmaxy()-290,x2=210,y2=getmaxy()-190;j<3;x1+=70,x2+=70,j++)
				{
						setcolor(RED);
						rectangle(x1,y1,x2,y2);//to display game cards
						DISPLAY_CARDS(x1+15,y1+15,gcard[j],gsuit[j]);

				}
			}
			else if(i==3)
			{
				ssize=5;
				gsize=4;
				R=1;

				int asuit=random(4);
				int acard;

				gsuit[3]=DOC[asuit].suit;

				do //loop to ensure card is available for distribution
				{
					acard=random(13);

				}while((DOC[asuit].number[acard][1]==0));

				gcard[3]=DOC[asuit].number[acard][0];
					DOC[asuit].number[acard][1]=0;

				N--; //Decrements total number of cards as gcard is assigned
				setcolor(RED);
				rectangle(360,getmaxy()-290,420,getmaxy()-190);
				DISPLAY_CARDS(375,getmaxy()-275,gsuit[3],gcard[3]);
			}
			else if(i==4)
			{
				ssize=5;
				gsize=5;
				R=0;

				int asuit=random(4);
				int acard;

				gsuit[4]=DOC[asuit].suit;

				do //loop to ensure card is available for distribution
				{
					acard=random(13);

				}while((DOC[asuit].number[acard][1]==0));

				gcard[4]=DOC[asuit].number[acard][0];
					DOC[asuit].number[acard][1]=0;

				N--; //Decrements total number of cards as gcard is assigned

				setcolor(RED);
				rectangle(430,getmaxy()-290,490,getmaxy()-190);
				DISPLAY_CARDS(445,getmaxy()-205,gsuit[4],gcard[4]);
			}

			for(int j=0;j<3;j++) //Sorts,merges,compares and gives final set
			{
				if(i!=1)PLAYER[j].sort_cards(gcard,gsuit,gsize);
				if(i!=1)PLAYER[j].merge_cards(gcard,gsuit,gsize,ssize);

				long float pset3=PLAYER[j].isrflush(ssize,N,R)+PLAYER[j].isstflush(ssize,N,R)+PLAYER[j].is4kind(ssize,N,R);
				long float pset2=0;
				long float pset1=PLAYER[j].is3kind(ssize,N,R)+PLAYER[j].is2pair(ssize,N,R)+PLAYER[j].ispair(ssize,N,R);

				PLAYER[j].bet_set=0;

			   if((pset3>pset2)&&(pset3>pset1))PLAYER[j].bet_set=3;
					else if(pset2>pset3>1)PLAYER[j].bet_set=2;
						else PLAYER[j].bet_set=1;
			}
		//do
		//{
			for(j=1;j<=4;j++)
			{
				settextstyle(0,0,1);
				switch(GAME_STATUS.turn)
				{
					case 1:{
						    if(USER.action!=3)
						    {
							setfillstyle(1,YELLOW);
							bar(205,350,235,380);

							M.show_mouse();
							M.get_status();
							M.hide_mouse();

							if(cx>=getmaxx()-15&&cy>=-3)exit(0);

							if((cx>390)&&(cx<445))
							{
								USER.action=1;//check
								outtextxy(135,getmaxy()-70,"CHECK");
								delay(2000);
								setfillstyle(1,BLACK);
								bar(105,getmaxy()-70,250,getmaxy()-50);//hides action
								GAME_STATUS.check++;
							}
							else if((cx>450)&&(cx<495))
							{
								USER.action=4;//call
								delay(2000);
								outtextxy(135,getmaxy()-70,"CALL");

								USER.amt=USER.amt-GAME_STATUS.raise_amt;
								setfillstyle(1,BLACK);
								bar(195,getmaxy()-90,250,getmaxy()-75);//hides amount

								char t[6];
								ltoa(USER.amt,t,10);
								setcolor(CYAN);
								outtextxy(195,getmaxy()-90,t);
								delay(2000);
								setfillstyle(1,BLACK);
								bar(105,getmaxy()-70,250,getmaxy()-50);//hides action
								GAME_STATUS.call++;
								GAME_STATUS.pot_amt=GAME_STATUS.pot_amt+USER.amt;
							}
							else if((cx>500)&&(cx<555))
							{
								USER.action=2;//raise
								setfillstyle(1,BLACK);
								bar(390,getmaxy()-95,610,getmaxy()-65);//hides options
								setcolor(CYAN);
								rectangle(390,getmaxy()-95,610,getmaxy()-65);
								outtextxy(395,getmaxy()-85,"Enter raise amount: ");
							  char  t[50];
								user_input(t,550,getmaxy()-85);

								delay(2000);
								setfillstyle(1,BLACK);
								bar(390,getmaxy()-95,610,getmaxy()-65);//hides user input
								rectangle(390,getmaxy()-95,445,getmaxy()-65);
								outtextxy(400,getmaxy()-85,"CHECK");
								rectangle(450,getmaxy()-95,495,getmaxy()-65);
								outtextxy(460,getmaxy()-85,"CALL");
								rectangle(500,getmaxy()-95,555,getmaxy()-65);
								outtextxy(510,getmaxy()-85,"RAISE");
								rectangle(560,getmaxy()-95,610,getmaxy()-65);
								outtextxy(570,getmaxy()-85,"FOLD");

								delay(2000);
								outtextxy(105,getmaxy()-70,"RAISE BY:  $");
								outtextxy(200,getmaxy()-70,t);

								delay(2000);
								setfillstyle(1,BLACK);
								bar(195,getmaxy()-90,250,getmaxy()-75);//hides amount
								USER.bet_amt=atol(t);//ERROR FLAG
								USER.amt=USER.amt-USER.bet_amt;
								ltoa(USER.amt,t,10);
								outtextxy(195,getmaxy()-90,t);

								setfillstyle(1,BLACK);
								bar(105,getmaxy()-70,250,getmaxy()-50);//hides action

								GAME_STATUS.raise++;
								GAME_STATUS.raise_amt=USER.bet_amt;
								GAME_STATUS.pot_amt=GAME_STATUS.pot_amt+USER.amt;
							}
							else if((cx>570)&&(cx<610))
							{
								USER.action=3;//fold
								delay(2000);
								outtextxy(135,getmaxy()-70,"FOLD");
								delay(2000);
								setfillstyle(1,BLACK);
								bar(105,getmaxy()-70,250,getmaxy()-50);//hides action
								GAME_STATUS.fold++;
							}
						    }
							GAME_STATUS.turn++;

							setfillstyle(1,BLUE);
							bar(205,350,235,380);

							PLAYER[0].ACTION(ssize);
					       }break;
					case 2:{
						      if(PLAYER[0].action!=3)
						      {
							setfillstyle(1,YELLOW);
							bar(100,270,130,300);

							delay(5000);

							if(PLAYER[0].action==1)
							{
								outtextxy(30,340,"CHECK");
								delay(2000);
								setfillstyle(1,BLACK);
								bar(30,340,180,360); //hides action
							}
							else if(PLAYER[0].action==2)
							{
								setcolor(CYAN);
								outtextxy(30,340,"RAISE BY:  $");
							  char  t[6];
								ltoa(PLAYER[0].bet_amt,t,10);
								outtextxy(125,340,t);

								delay(2000);
								setfillstyle(1,BLACK);
								bar(30,340,180,360); //hides action
								delay(2000);
								setfillstyle(1,BLACK);
								bar(90,320,150,335);// hides amount
								ltoa(PLAYER[0].amt,t,10);
								outtextxy(90,320,t);
							}
							else if(PLAYER[0].action==3)
							{
								outtextxy(30,340,"FOLD");
								delay(2000);
								setfillstyle(1,BLACK);
								bar(30,340,180,360); //hides action
							}
							else if(PLAYER[0].action==4)
							{
								setcolor(CYAN);
								outtextxy(30,340,"CALL");
							  char  t[6];
								delay(2000);
								setfillstyle(1,BLACK);
								bar(90,320,150,335);// hides amount
								ltoa(PLAYER[0].amt,t,10);
								outtextxy(110,340,t);
								delay(2000);
								setfillstyle(1,BLACK);
								bar(30,340,180,360); //hides action
							}
						      }

							GAME_STATUS.turn++;
							setfillstyle(1,BLUE);
							bar(100,270,130,300);

							PLAYER[1].ACTION(ssize);
					       }break;
					case 3:{
						     if(PLAYER[1].action!=3)
						     {
							setfillstyle(1,YELLOW);
							bar(245,140,275,170);

							delay(5000);

							if(PLAYER[1].action==1)
							{
								outtextxy(135,60,"CHECK");
								delay(2000);
								setfillstyle(1,BLACK);
								bar(105,60,250,80); //hides action
							}
							else if(PLAYER[1].action==2)
							{
								setcolor(CYAN);
								outtextxy(105,60,"RAISE BY:  $");

								delay(2000);
							  char  t[6];
								ltoa(PLAYER[0].bet_amt,t,10);
								outtextxy(200,60,t);

								delay(2000);
								setfillstyle(1,BLACK);
								bar(195,40,250,55);// hides amount
								ltoa(PLAYER[0].amt,t,10);
								outtextxy(195,40,t);

								delay(2000);
								setfillstyle(1,BLACK);
								bar(105,60,250,80); //hides action
							}
							else if(PLAYER[1].action==3)
							{
								outtextxy(30,340,"FOLD");
								delay(2000);
								setfillstyle(1,BLACK);
								bar(105,60,250,80); //hides action
							}
							else if(PLAYER[1].action==4)
							{
								setcolor(CYAN);
								outtextxy(30,340,"CALL");
							  char  t[6];
								delay(2000);
								setfillstyle(1,BLACK);
								bar(195,40,250,55);// hides amount
								ltoa(PLAYER[0].amt,t,10);
								outtextxy(195,40,t);
								delay(2000);
								setfillstyle(1,BLACK);
								bar(105,60,250,80); //hides action
							}
						     }
							GAME_STATUS.turn++;
							setfillstyle(1,BLUE);
							bar(245,140,275,170);

							PLAYER[2].ACTION(ssize);
					       }break;
					case 4:{
						     if(PLAYER[2].action!=3)
						     {
							setfillstyle(1,YELLOW);
							bar(510,150,540,180);

							delay(5000);

							if(PLAYER[2].action==1)
							{
								outtextxy(450,340,"CHECK");
								delay(2000);
								setfillstyle(1,BLACK);
								bar(450,340,600,360); //hides action
							}
							else if(PLAYER[2].action==2)
							{
								setcolor(CYAN);
								outtextxy(450,340,"RAISE BY:  $");

								delay(2000);
							  char  t[6];
								ltoa(PLAYER[0].bet_amt,t,10);
								outtextxy(545,340,t);

								delay(2000);
								setfillstyle(1,BLACK);
								bar(560,320,615,340);// hides amount
								ltoa(PLAYER[0].amt,t,10);
								outtextxy(560,320,t);

								delay(2000);
								setfillstyle(1,BLACK);
								bar(450,340,600,360); //hides action
							}
							else if(PLAYER[2].action==3)
							{
								outtextxy(450,340,"FOLD");
								delay(2000);
								setfillstyle(1,BLACK);
								bar(450,340,600,360); //hides action
							}
							else if(PLAYER[2].action==4)
							{
								setcolor(CYAN);
								outtextxy(450,340,"CALL");
							  char  t[6];
								delay(2000);
								setfillstyle(1,BLACK);
								bar(560,320,615,340);// hides amount
								ltoa(PLAYER[0].amt,t,10);
								outtextxy(560,320,t);
								delay(2000);
								setfillstyle(1,BLACK);
								bar(450,340,600,360); //hides action
							}
						     }
							GAME_STATUS.turn++;
							setfillstyle(1,BLUE);
							bar(510,150,540,180);
					       }break;
				}//switch turn ends
			}//for loop for each player's turn ends
		//}while(GAME_STATUS.count_raise()!=1);

		if(i==4)
		{
			delay(5000);
			settextstyle(0,0,1);
			setcolor(CYAN);

			int WINNER=0;

			for(int j=0;j<3;j++)
			{
				if(j==0)WINNER=j;
					else if(PLAYER[j].bet_set>=PLAYER[WINNER].bet_set)WINNER=j+1;
			}
			if(USER.bet_set>=PLAYER[WINNER].bet_set)WINNER=3;

			WINSCREEN();

			DISPLAY_CARDS(270,365,USER.pcard[0],USER.psuit[0]);
			DISPLAY_CARDS(340,365,USER.pcard[1],USER.psuit[1]);

			j=0;
			for(int x1=150,y1=getmaxy()-290,x2=210,y2=getmaxy()-190;j<5;x1+=70,x2+=70,j++)
				DISPLAY_CARDS(x1+15,y1+15,gcard[j],gsuit[j]);

			delay(2000);

			switch(WINNER)
			{
				case 0: switch(PLAYER[0].bet_set)
					{
					 case 3:switch(PLAYER[0].subset)
					 {
						case 3:{
							outtextxy(30,320,"WINNER BY:");
							outtextxy(30,340,"ROYAL FLUSH");
						       }break;
						case 2:{
							outtextxy(30,320,"WINNER BY:");
							outtextxy(30,340,"STRAIGHT FLUSH");
						       }break;
						case 1:{
							outtextxy(30,320,"WINNER BY:");
							outtextxy(30,340,"FOUR OF A KIND");
						       }break;
					 }break;
					 case 2:switch(PLAYER[0].subset)
					 {
						case 3:{
							outtextxy(30,320,"WINNER BY:");
							outtextxy(30,340,"FULL HOUSE");
						       }break;
						case 2:{
							outtextxy(30,320,"WINNER BY:");
							outtextxy(30,340,"STRAIGHT");
						       }break;
						case 1:{
							outtextxy(30,320,"WINNER BY:");
							outtextxy(30,340,"FLUSH");
						       }break;
					 }break;
					 case 1:switch(PLAYER[0].subset)
					 {
						case 3:{
							outtextxy(30,320,"WINNER BY:");
							outtextxy(30,340,"THREE OF A KIND");
						       }break;
						case 2:{
							outtextxy(30,320,"WINNER BY:");
							outtextxy(30,340,"TWO PAIR");
						       }break;
						case 1:{
							outtextxy(30,320,"WINNER BY:");
							outtextxy(30,340,"ONE PAIR");
						       }break;
					 }break;
					 default:
					 {
					      outtextxy(30,320,"WINNER BY:");
					      outtextxy(30,340,"HIGH CARD");
					 }break;
					}break;
				case 1: switch(PLAYER[1].bet_set)
					{
						case 3:switch(PLAYER[1].subset)
						{
							case 3:{
								outtextxy(135,40,"WINNER BY:");
								outtextxy(105,60,"ROYAL FLUSH");
							       }break;
							case 2:{
								outtextxy(135,40,"WINNER BY:");
								outtextxy(105,60,"STRAIGHT FLUSH");
							       }break;
							case 1:{
								outtextxy(135,40,"WINNER BY:");
								outtextxy(105,60,"FOUR OF A KIND");
							       }break;
						}break;
						case 2:switch(PLAYER[1].subset)
						{
							case 3:{
								outtextxy(135,40,"WINNER BY:");
								outtextxy(105,60,"FULL HOUSE");
							       }break;
							case 2:{
								outtextxy(135,40,"WINNER BY:");
								outtextxy(105,60,"STRAIGHT");
							       }break;
							case 1:{
								outtextxy(135,40,"WINNER BY:");
								outtextxy(105,60,"FLUSH");
							       }break;
						}break;
						case 1:switch(PLAYER[1].subset)
						{
							case 3:{
								outtextxy(135,40,"WINNER BY:");
								outtextxy(105,60,"THREE OF A KIND");
							       }break;
							case 2:{
								outtextxy(135,40,"WINNER BY:");
								outtextxy(105,60,"TWO PAIR");
							       }break;
							case 1:{
							       outtextxy(135,40,"WINNER BY:");
							       outtextxy(105,60,"ONE PAIR");
							       }break;
						}break;
						default:
						{
						     outtextxy(135,40,"WINNER BY:");
						     outtextxy(105,60,"HIGH CARD");
						}break;
					}break;
				case 2: switch(PLAYER[2].bet_set)
					{
						case 3:switch(PLAYER[2].subset)
						{
							case 3:{
								outtextxy(500,320,"WINNER BY:");
								outtextxy(450,340,"ROYAL FLUSH");
							       }break;
							case 2:{
								outtextxy(500,320,"WINNER BY:");
								outtextxy(450,340,"STRAIGHT FLUSH");
							       }break;
							case 1:{
								outtextxy(500,320,"WINNER BY:");
								outtextxy(450,340,"FOUR OF A KIND");
							       }break;
						}break;
						case 2:switch(PLAYER[2].subset)
						{
							case 3:{
								outtextxy(500,320,"WINNER BY:");
								outtextxy(450,340,"FULL HOUSE");
							       }break;
							case 2:{
								outtextxy(500,320,"WINNER BY:");
								outtextxy(450,340,"STRAIGHT");
							       }break;
							case 1:{
								outtextxy(500,320,"WINNER BY:");
								outtextxy(450,340,"FLUSH");
							       }break;
						}break;
						case 1:switch(PLAYER[2].subset)
						{
							case 3:{
								outtextxy(500,320,"WINNER BY:");
								outtextxy(450,340,"THREE OF A KIND");
							       }break;
							case 2:{
								outtextxy(500,320,"WINNER BY:");
								outtextxy(450,340,"TWO PAIR");
							       }break;
							case 1:{
								outtextxy(500,320,"WINNER BY:");
								outtextxy(450,340,"ONE PAIR");
							       }break;
						}break;
						default:
						{
							outtextxy(500,320,"WINNER BY:");
							outtextxy(450,340,"HIGH CARD");
						}break;
					}break;
				case 3: switch(USER.bet_set)
					{
						case 3:switch(USER.subset)
						{
							case 3:{
								outtextxy(135,390,"WINNER BY:");
								outtextxy(105,410,"ROYAL FLUSH");
							       }break;
							case 2:{
								outtextxy(135,390,"WINNER BY:");
								outtextxy(105,410,"STRAIGHT FLUSH");
							       }break;
							case 1:{
								outtextxy(135,390,"WINNER BY:");
								outtextxy(105,410,"FOUR OF A KIND");
							       }break;
						}break;
						case 2:switch(USER.subset)
						{
							case 3:{
								outtextxy(135,390,"WINNER BY:");
								outtextxy(105,410,"FULL HOUSE");
							       }break;
							case 2:{
								outtextxy(135,390,"WINNER BY:");
								outtextxy(105,410,"STRAIGHT");
							       }break;
							case 1:{
								outtextxy(135,390,"WINNER BY:");
								outtextxy(105,410,"FLUSH");
							       }break;
						}break;
						case 1:switch(USER.subset)
						{
							case 3:{
								outtextxy(135,390,"WINNER BY:");
								outtextxy(105,410,"THREE OF A KIND");
							       }break;
							case 2:{
								outtextxy(135,390,"WINNER BY:");
								outtextxy(105,410,"TWO PAIR");
							       }break;
							case 1:{
								outtextxy(135,390,"WINNER BY:");
								outtextxy(105,410,"ONE PAIR");
							       }break;
						}break;
						default:
						{
							outtextxy(135,390,"WINNER BY:");
							outtextxy(105,410,"HIGH CARD");
						}break;
					}break;
			}
			if(WINNER==3)USER.amt=USER.amt+GAME_STATUS.pot_amt;
				else PLAYER[WINNER].amt=PLAYER[WINNER].amt+GAME_STATUS.pot_amt;
		delay(2000);

		}

	}//ROUND LOOP ends

    } //GAME loop ends  */
}
void distribute()
{
	for(int i=0;i<4;i++)
	{
		DOC[i].suit= char(i+3);
			for(int j=0,k=2;k<=14;j++,k++) //Loop to store cards
			{
				DOC[i].number[j][0]=k;
				DOC[i].number[j][1]=1;
			}
	}
}

void main()
{
	    distribute();
	    randomize();

	int             a=9,b=2;
			initgraph(&a,&b,"c:\\tc\\bgi");

			front();

}