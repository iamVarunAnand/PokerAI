void user_input(char st[100],int x,int y)
{
	int i=0;
	char ch=getch();
	while(ch!='\r')
	{
		st[i]=ch;
		st[i+1]='\0';
		outtextxy(x,y,st);
		i++;
		ch=getch();
	}
}
void game_screen()
{
	int     a=9,b=2;
		initgraph(&a,&b,"c:\\TC\\bgi");

		setfillstyle(1,RED);
		rectangle(20,20,getmaxx()-20,getmaxy()-20);
		rectangle(getmaxx()-20,0,getmaxx(),20);
			floodfill(5,5,WHITE);
		setfillstyle(1,BLUE);
			floodfill(getmaxx()-18,2,WHITE);
		settextstyle(3,0,1);
		setcolor(YELLOW);
		outtextxy(getmaxx()-15,-3,"X");

		//user
		setcolor(RED);
		settextstyle(0,0,1);

		rectangle(255,getmaxy()-130,315,getmaxy()-30);
		rectangle(325,getmaxy()-130,385,getmaxy()-30);
			setcolor(CYAN);
			outtextxy(135,getmaxy()-90,"AMOUNT:");
			outtextxy(195,getmaxy()-90,"$40,000");

		//player left
		setcolor(RED);

		rectangle(30,getmaxy()-290,90,getmaxy()-190);
		line(60,getmaxy()-290,60,getmaxy()-320);
		line(60,getmaxy()-320,120,getmaxy()-320);
		line(120,getmaxy()-320,120,getmaxy()-220);
		line(120,getmaxy()-220,90,getmaxy()-220);

			setfillstyle(5,GREEN);
			floodfill(40,getmaxy()-280,RED);
			floodfill(70,getmaxy()-300,RED);

		 setcolor(CYAN);
		 outtextxy(30,320,"AMOUNT:");
		 outtextxy(90,320,"$40,000");

		//player top
		setcolor(RED);

		rectangle(255,30,315,130);
		line(285,130,285,160);
		line(285,160,345,160);
		line(345,160,345,60);
		line(345,60,315,60);

			setfillstyle(5,GREEN);
			floodfill(260,40,RED);
			floodfill(295,140,RED);

	       settextstyle(0,0,1);
	       setcolor(CYAN);
	       outtextxy(135,40,"AMOUNT:");
	       outtextxy(195,40,"$40,000");

		//player right
		setcolor(RED);
		rectangle(520,getmaxy()-290,580,getmaxy()-190);
		line(550,getmaxy()-290,550,getmaxy()-320);
		line(550,getmaxy()-320,610,getmaxy()-320);
		line(610,getmaxy()-320,610,getmaxy()-220);
		line(610,getmaxy()-220,580,getmaxy()-220);
			setfillstyle(5,GREEN);
			floodfill(530,getmaxy()-280,RED);
			floodfill(560,getmaxy()-300,RED);
		settextstyle(0,0,1);
		setcolor(CYAN);
		outtextxy(500,320,"AMOUNT:");
		outtextxy(560,320,"$40,000");

		setfillstyle(1,YELLOW);

		bar(205,350,235,380);
		setfillstyle(1,BLUE);
		bar(100,270,130,300);
		bar(245,140,275,170);
		bar(510,150,540,180);

		setcolor(CYAN);
		settextstyle(0,0,1);
		outtextxy(400,40,"POT AMOUNT:");
		outtextxy(520,40,"$200,000");

		rectangle(390,getmaxy()-95,445,getmaxy()-65);
		outtextxy(400,getmaxy()-85,"CHECK");
		rectangle(450,getmaxy()-95,495,getmaxy()-65);
		outtextxy(460,getmaxy()-85,"CALL");
		rectangle(500,getmaxy()-95,555,getmaxy()-65);
		outtextxy(510,getmaxy()-85,"RAISE");
		rectangle(560,getmaxy()-95,610,getmaxy()-65);
		outtextxy(570,getmaxy()-85,"FOLD");



		/*outtextxy(395,getmaxy()-85,"Enter raise amount: ");
		char st[50];
		input(st,550,getmaxy()-85);   /*

		 /*For manipulating pot amount

		int t=25000;
		char ch[6];
		for(i=1;i<=4;i++)
		{
			delay(1000);
			bar(400,40,600,60);
			outtextxy(400,40,"POT AMOUNT:   $");
			t-=5000;
			itoa(t,ch,10);
			outtextxy(520,40,ch);
		}*/

	       /*	setcolor(RED);
		for(int x1=150,y1=getmaxy()-290,x2=210,y2=getmaxy()-190,i=1;i<=5;x1+=70,x2+=70,i++)
		{
			delay(1000);
			rectangle(x1,y1,x2,y2);
		} */


}
