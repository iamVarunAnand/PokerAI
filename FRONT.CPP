void game();
void front()
{

	int a=9,b=2;
	initgraph(&a,&b,"d:\\TC\\bgi");
	//setbkcolor(RED);
	setcolor(RED);
	settextstyle(3,0,3);
	rectangle(20,20,getmaxx()-20,getmaxy()-20); // Border
	outtextxy(200,35,"TEXAS HOLD-EM POKER"); //Heading
	rectangle(270,90,370,170); // play
	settextstyle(3,0,1);
	outtextxy(300,110,"PLAY");
	rectangle(270,200,370,280); // help
	outtextxy(300,225,"HELP");
	rectangle(270,310,370,390); // exit
	outtextxy(300,335,"EXIT");

	//mouse m;
	//m.show_mouse();
	//m.get_status();

	//if((cy>90)&&(cy<170))//play
       //	{
		delay(200);
		game();
      //	}
		//else if((cy>200)&&(cy<280))//help
	//		else if((cy>310)&&(cy<390))exit(0);

	getch();
}
