#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <iomanip.h>
#include <graphics.h>

void main() 	{
clrscr();
randomize();
		int a,b,c,r=0,d,x1,y1,k=0;
		float i=-0.16;
		a=DETECT;
		initgraph(&a,&b,"c:\\borlandc\\bgi");
		setcolor(4);
		cin>>r;

		while (2*(r/1.68)*(i+1)+r<=640 && (480-2*(r/1.68)*(i+1))-r>=0)
			{
			i++;
			x1=2*(r/1.68)*i;
			y1=480-2*(r/1.68)*i;
				c=random(15)+1;
				setcolor(c);
				circle(x1*1.34,y1,r);
				k+=1;
			}

		cout<<k;
getch();
		}
