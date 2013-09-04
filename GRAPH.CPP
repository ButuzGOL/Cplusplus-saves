#include<iomanip.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<iostream.h>
#include<ctype.h>
#include<math.h>
#include<stdio.h>
#include<conio.h>
void perevod(float,int []);
void menu();
void per_obr(int []);
void per_dop(int []);
void slogenie(int [],int [],int []);
void perevod(float n,int m[])
 {
  int temp;
  int j=0;
  temp=n;
  //razbienie i zaniseni pologitelnogo chisla v massiv
  if(temp>0)
   {
    while(temp>0)
     {
      m[j]=fmod(temp,2);
      j++;
      temp=temp/2;
     }
    for(int i=j;i<8;i++)
     m[i]=0;
   }

   //razbienie i zaniseni otricatelnogo chisla v massiv
    else
   {
    temp=n-n-n;
    cout<<temp;
    while(temp>0)
     {
      m[j]=fmod(temp,2);
      j++;
      temp=temp/2;
     }
    for(int i=j;i<7;i++)
     m[i]=0;
    m[7]=1;
   }
    int tt=7; int t;
    for(int i=0;i<4;i++)
     {
      t=m[i]; m[i]=m[tt];m[tt]=t; tt--;
     }
 }



 void per_obr(int m[])
 {
  if(m[0]==1)
   for(int i=1;i<8;i++)
    {
     if(m[i]==1) m[i]=0; else m[i]=1;
    }
 }



 void per_dop(int m[])
 {
  if(m[0]==1)
   {
    m[7]=m[7]+1;
    for(int i=7;i>0;i--)
      {
       if(m[i]==2) {m[i]=0; m[i-1]=m[i-1]+1;} else break;
      }
   }
 }
void slogenie(int mas[],int mas2[],int mas4[])
{
    int mast[9];
    for(int i=0;i<8;i++)
	mast[i]=mas[i];
    for(i=7;i>0;i--)
    {
	mas4[i]=mast[i]+mas2[i];
	if(mas4[i]==2)
	{
	    mas4[i]=0;
	    mast[i-1]=mast[i-1]+1;
	}
	if(mas4[i]==3)
	{
	    mas4[i]=1;
	    mast[i-1]=mast[i-1]+1;
	}
    }
    //if(mas[0]==1 || mas2[0]==1)
    if(mas[0]+mas2[0]==1 || mas[0]+mas2[0]==2)
	mas4[0]=1;
    else
	mas4[0]=0;
    //cout<<endl<<"mas[0]"<<mas[0]<<endl;
    //cout<<endl<<"mas2[0]"<<mas2[0]<<endl;
    //cout<<endl<<"mas4[0]"<<mas4[0]<<endl;
}
void menu()
{
    clrscr();
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int style, midx, midy;
   int size = 1;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "c:\\borlandc\\bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
   midx = getmaxx() -325;
   midy = getmaxy() -350;
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   style=GOTHIC_FONT;
   cleardevice();
   size = 8;
   setcolor(4);
   settextstyle(style, HORIZ_DIR, size);
   outtextxy(midx, midy, "PROGRAMM" );
   style=GOTHIC_FONT;
   size = 5;
   settextstyle(style, HORIZ_DIR, size);
   outtextxy(midx, midy+100,"For translition's digitS");
   style=GOTHIC_FONT;
   size = 3;
   settextstyle(style, HORIZ_DIR, size);
   outtextxy(midx, midy+300,"Any press to keY");
   getch();
   closegraph();
}
void main()
{
  menu();
 /* const col=9;
  int mas[col],mas2[col],mas3[col],mas4[col];
  int x,y;
  char c='+';
  x=0;
  y=0;
  textcolor(4);
  cprintf("Vvedite 1 chislo v 10 sisteme\n");
  cin>>x;
  cprintf("Vvedite 2 chislo v 10 sisteme\n");
  cin>>y;
  cprintf("OTBET: ");
  textcolor(15);
  perevod(x,mas);
  cout<<endl<<"Pryamoj kod: "<<endl<<"1) ";
  for(int i=0;i<8;i++)
      cout<<mas[i];
  cout<<endl;
  perevod(y,mas2);
  cout<<"2) ";
  for( i=0;i<8;i++)
      cout<<mas2[i];
  cout<<endl;
  per_obr(mas);
  cout<<"Obratnij kod: "<<endl<<"1) ";
  for( i=0;i<8;i++)
      cout<<mas[i];
  cout<<endl;
  per_obr(mas2);
  cout<<"2) ";
  for( i=0;i<8;i++)
      cout<<mas2[i];
  slogenie(mas,mas2,mas3);
  cout<<endl<<"Slogenie v obratnom kode: ";
  for( i=0;i<8;i++)
      cout<<mas3[i];
  cout<<endl;
  per_dop(mas);
  cout<<"Dopolnitelnij kod: "<<endl<<"1) ";
  for(i=0;i<8;i++)
      cout<<mas[i];
  cout<<endl;
  per_dop(mas2);
  cout<<"2) ";
  for( i=0;i<8;i++)
      cout<<mas2[i];
  slogenie(mas,mas2,mas4);
  cout<<endl<<"Slogenie v dopolnitelnom kode: ";
  for( i=0;i<8;i++)
      cout<<mas4[i];*/
  getch();
}
