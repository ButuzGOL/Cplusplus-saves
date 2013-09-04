#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
void main(){
  randomize();
  int a[10],i=0,gd,gm;
  for(i=0;i<10;i++){
	 a[i]=random(18)+1;
	 cout<<a[i]<<endl;}
  gd=DETECT;
  initgraph(&gd,&gm,"c:\\borlandc\\bgi");

  line(60,170,60,400);
  line(60,400,500,400);

  line(60,170,55,175);
  line(60,170,65,175);
  line(500,400,495,395);
  line(500,400,495,405);
  settextstyle(0,0,1);
  settextjustify(1,1);
  outtextxy(250,430,"nomer komandi");
  settextstyle(0,1,1);
  settextjustify(2,2);
  outtextxy(20,260,"kol ochkov");
  char s[3];
  settextstyle(0,0,1);
  settextjustify(1,1);
  int x=85;

	for(i=1; i<11; i++)
		{
		itoa(i,s,10);
		outtextxy(x,415,s);
		x=x+40;
		}

  settextjustify(2,1);
  int y=400;
	for (i=0; i<22; i++)
		{
		line(55,y,65,y);
		itoa(i,s,10);
		outtextxy(55,y,s);
		y=y-10;
		}
  x=70;
  setcolor(2);

	for (i=0;i<10;i++)
		{
		setfillstyle(1,i+1);
		bar(x,400-a[i]*10,x+30,399);
		settextjustify(1,0);
		itoa(a[i],s,10);
		outtextxy(x+15,395-a[i]*10,s);
		x=x+40;
		}
  getch();


}