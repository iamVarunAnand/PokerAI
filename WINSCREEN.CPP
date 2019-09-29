#include<graphics.h>
#include<dos.h>
#include<conio.h>

void WINSCREEN()
{
	int a=9,b=2;
	initgraph(&a,&b,"d:\\tc\\bgi");

	setfillstyle(1,RED);
		rectangle(20,20,getmaxx()-20,getmaxy()-20);
		rectangle(getmaxx()-20,0,getmaxx(),20);
			floodfill(5,5,WHITE);
		setfillstyle(1,BLUE);
			floodfill(getmaxx()-18,2,WHITE);
		settextstyle(3,0,1);
		setcolor(YELLOW);
		outtextxy(getmaxx()-15,-3,"X");

	setcolor(RED);

	rectangle(255,getmaxy()-130,315,getmaxy()-30);
	rectangle(325,getmaxy()-130,385,getmaxy()-30);

	rectangle(30,110,90,210);
	rectangle(30,230,90,330);

	rectangle(255,30,315,130);
	rectangle(325,30,385,130);

	rectangle(550,110,610,210);
	rectangle(550,230,610,330);

	for(int x1=150,y1=getmaxy()-290,x2=210,y2=getmaxy()-190,i=1;i<=5;x1+=70,x2+=70,i++)
		rectangle(x1,y1,x2,y2);



}