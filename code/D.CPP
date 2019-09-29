void  DISPLAY_CARDS(int x,int y,int card,int suit)
{
	settextstyle(0,0,1);
	switch(suit)
	{
	    case 3: {
				setcolor(RED);
			char    s[2]={char(suit)};

			switch(card)
			{
			    case  2: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"2");
				     }break;
			    case  3: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"3");
				     }break;
			    case 4:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"4");
				     }break;
			    case 5:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"5");
				     }break;
			    case 6:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"6");
				     }break;
			    case 7:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"7");
				     }break;
			    case 8:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"8");
				     }break;
			    case 9:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"9");
				     }break;
			    case 10: {
					outtextxy(x,y,s);
					settextstyle(0,0,4);
					outtextxy(x-10,y+20,"1");
					outtextxy(x+20,y+20,"0");
				     }break;
			    case 11: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"J");
				     }break;
			    case 12: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"Q");
				     }break;
			    case 13: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"K");
				     }break;
			    case 14: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"A");
				     }break;
			}
		    }break;
	    case 4: {
				setcolor(RED);
			char    s[2]={char(suit)};

			switch(card)
			{
			    case  2: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"2");
				     }break;
			    case  3: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"3");
				     }break;
			    case 4:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"4");
				     }break;
			    case 5:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"5");
				     }break;
			    case 6:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"6");
				     }break;
			    case 7:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"7");
				     }break;
			    case 8:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"8");
				     }break;
			    case 9:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"9");
				     }break;
			    case 10: {
					outtextxy(x,y,s);
					settextstyle(0,0,4);
					outtextxy(x-10,y+20,"1");
					outtextxy(x+20,y+20,"0");
				     }break;
			    case 11: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"J");
				     }break;
			    case 12: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"Q");
				     }break;
			    case 13: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"K");
				     }break;
			    case 14: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"A");
				     }break;
			}
		    }break;
	    case 5: {
				setcolor(DARKGRAY);
			char    s[2]={char(suit)};

			switch(card)
			{
			    case  2: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"2");
				     }break;
			    case  3: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"3");
				     }break;
			    case 4:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"4");
				     }break;
			    case 5:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"5");
				     }break;
			    case 6:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"6");
				     }break;
			    case 7:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"7");
				     }break;
			    case 8:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"8");
				     }break;
			    case 9:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"9");
				     }break;
			    case 10: {
					outtextxy(x,y,s);
					settextstyle(0,0,4);
					outtextxy(x-10,y+20,"1");
					outtextxy(x+20,y+20,"0");
				     }break;
			    case 11: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"J");
				     }break;
			    case 12: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"Q");
				     }break;
			    case 13: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"K");
				     }break;
			    case 14: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"A");
				     }break;
			}
		    }break;
	    case 6: {
				setcolor(DARKGRAY);
			char    s[2]={char(suit)};

			switch(card)
			{
			    case  2: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"2");
				     }break;
			    case  3: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"3");
				     }break;
			    case 4:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"4");
				     }break;
			    case 5:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"5");
				     }break;
			    case 6:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"6");
				     }break;
			    case 7:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"7");
				     }break;
			    case 8:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"8");
				     }break;
			    case 9:  {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"9");
				     }break;
			    case 10: {
					outtextxy(x,y,s);
					settextstyle(0,0,4);
					outtextxy(x-10,y+20,"1");
					outtextxy(x+20,y+20,"0");
				     }break;
			    case 11: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"J");
				     }break;
			    case 12: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"Q");
				     }break;
			    case 13: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"K");
				     }break;
			    case 14: {
					outtextxy(x,y,s);
					settextstyle(0,0,5);
					outtextxy(x,y+20,"A");
				     }break;
			}
		    }
	}
}
/*void main()
{
    int a=9,b=2;
    initgraph(&a,&b,"d:\\tc\\bgi");
    setcolor(DARKGRAY);
    DISPLAY_CARDS(300,300,8,4);


} */