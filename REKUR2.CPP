#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <graphics.h>
void ci(int,int,int);
void main()
	{
randomize();
	int a=0,b=0,x,pr;
	initgraph(&a,&b, "c:\\borlandc\\bgi");
	ci(320,240,75);

getch();
	}
void ci(int x,int y, int r)
	{
	if(r<=5) return;
	else
		{
		ci(x+r,y,r/2);
		ci(x-r,y,r/2);
		ci(x,y+r,r/2);
		ci(x,y-r,r/2);
		circle(x,y,r);
		setcolor(random(15)+1);
		}
	}
