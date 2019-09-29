# include<graphics.h>
# include<fstream.h>
# include<stdio.h>
# include<dos.h>
# include<conio.h>
int cx,cy,q;
class mouse
{
		REGS regs;
		int no_buttons;
	public:
		mouse()
		{
			regs.x.ax=0;
			int86(0x33,&regs,&regs);
			if(regs.x.ax==0xfff)no_buttons=regs.x.bx;
		}
		void show_mouse()
		{
			regs.x.ax=0x01;
			int86(0x33,&regs,&regs);
		}
		void hide_mouse()
		{
			regs.x.ax=0x02;
			int86(0x33,&regs,&regs);
		}
		void get_status()
		{
			regs.x.ax=0x03;
			int86(0x33,&regs,&regs);
			while(q!=1)
			{
				regs.x.ax=0x03;
				int86(0x33,&regs,&regs);
				q=regs.x.bx;
				cx=regs.x.cx;
				cy=regs.x.dx;
			}
			q=0;

		}
}m;
/*void main()
{
	mouse	m;
	int a = 9, b = 2;
	initgraph(&a, &b,"c:\\tc\\bin");
		m.show_mouse();
		m.get_status();
		m.hide_mouse();
		if (cx>100)  outtextxy(100,100,"FILE MENU");
			else outtextxy(200,200,"Compile MENU");
		getch();
} */
