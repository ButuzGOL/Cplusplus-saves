#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <iomanip.h>
#include <graphics.h>

void main() 	{
clrscr();
randomize();
		int a,b,c,r,i,k=0;
		float x1,y1;
		a=DETECT;
		initgraph(&a,&b,"c:\\borlandc\\bgi");
		setcolor(4);
		cin>>r;
		c=random(15)+1;
		setcolor(c);
		x1=r*1.333;
		y1=479-r;
		circle(x1,y1,r);
		for (i=1; i<=800; i++)
			putpixel(i*1.333,480-i,10);
		while (x1+(2*r)*0.8+r<=640 && y1-(2*r)/1.68-r>=0)
			{
			x1=x1+(2*r)*0.8;
			y1=y1-(2*r)/1.68;
			c=random(15)+1;
			setcolor(c);
			circle(x1,y1,r);
			k++;
			}


		cout<<k+1;
getch();
		}
