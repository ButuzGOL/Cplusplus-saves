#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
void main(){
  randomize();
  int a[15],i=0,gd,gm;
  for(i=0;i<15;i++){
	 a[i]=random(300)+10;
	 cout<<a[i]<<endl;}
  gd=DETECT;
  initgraph(&gd,&gm,"d:\\borlandc\\bgi");
/////////////////////  oc x
  line(60,30,60,400);
 ///////////// os y
  line(60,400,500,400);
 /////////////// strelki na y
  line(60,30,55,35);
  line(60,30,65,35);
  ///////////////// strelki na x
   line(500,400,495,395);
  line(500,400,495,405);
  settextstyle(1,0,1);
  settextjustify(2,1);
  outtextxy(490,430,"nomer");
  settextstyle(0,1,1);
  settextjustify(2,2);
  outtextxy(40,30,"element");
  char s[6];
  settextstyle(1,0,1);
  settextjustify(1,1);
  outtextxy(50,405,"0");
  int x=85;
  for(i=1;i<16;i++)
    {line(x,395,x,405);
     itoa(i,s,10);
     outtextxy(x,415,s);
     x=x+25;
     }
  settextjustify(2,1);
  int y=375;
  for (i=1;i<11;i++)
    {line(55,y,65,y);
     itoa(i*1,s,10);
     outtextxy(55,y,s);
    y=y-25;}
  moveto(60,a[0]);
  x=85;
  setcolor(2);
  for (i=1;i<15;i++){
    lineto(x,400-a[i]);
    x=x+25;
  }
  getch();


}