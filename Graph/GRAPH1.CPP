#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <iomanip.h>
#include <graphics.h>

void main() 	{
clrscr();
		int a,b;
		a=DETECT;
		initgraph(&a,&b,"c:\\borlandc\\bgi");
		setcolor(10);
		rectangle(220,90,420,390);
		circle(400,390,20);
		circle(240,90,20);

		rectangle(200,410,400,410);
		circle(200,390,20);
		rectangle(200,370,220,390);
		circle(200,380,10);

		rectangle(240,70,440,110);
		circle(440,90,20);
		circle(240,100,10);

		setfillstyle(1,10);
		floodfill(240,150,10);
		setfillstyle(1,10);
		floodfill(400,380,10);
		setfillstyle(1,10);
		floodfill(400,400,10);
		setfillstyle(1,10);
		floodfill(380,400,10);
		setfillstyle(1,10);
		floodfill(215,380,10);
		setfillstyle(1,10);
		floodfill(215,375,10);
		setfillstyle(1,10);
		floodfill(280,100,10);
		setfillstyle(1,10);
		floodfill(280,80,10);
		setfillstyle(1,10);
		floodfill(430,80,10);
		setfillstyle(1,10);
		floodfill(450,80,10);
		setfillstyle(1,10);
		floodfill(222,89,10);
		setfillstyle(1,10);
		floodfill(242,89,10);
		setfillstyle(1,10);
		floodfill(222,89,10);
		setfillstyle(1,10);
		floodfill(422,100,10);
		setfillstyle(1,10);
		floodfill(222,91,10);

	      	setcolor(2);
		circle(240,100,10);
		line(240,90,240,110);
		line(240,90,258,90);
		setfillstyle(1,2);
		floodfill(240,100,10);

		setcolor(2);
		circle(200,380,10);
		line(200,370,200,390);
		setcolor(10);
		line(195,370,220,370);
		setfillstyle(1,2);
		floodfill(200,380,10);

getch();     	}
