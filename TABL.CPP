#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <iomanip.h>
#include <graphics.h>
#include <dir.h>
#include <stdio.h>
#include <string.h>
void raz();
void tabl(char*);
void tabr(char*);
void nazl(char*);
void nazr(char*);
void nnaz(char*,int);
void main()
	{
clrscr();
		int a,b;
		char s[80],s1[80];
		a=DETECT;
		initgraph(&a,&b,"c:\\borlandc\\bgi");

		raz();

		nazl("c:\\wn\\nt\\yoi\kol\\pol\\poi\\bati_gol\\");
		nazr("c:\\wn\\nt\\yoi\kol\\pol\\poi\\bati_gol\\");

		tabl("c:");
		tabr("c:\\borlandc\\include");
		nnaz("c:",5);




getch();
	}
void raz()
	{
	setfillstyle(1,12);
	bar(5,20,9,436);
	bar(5,20,317,24);
	bar(313,20,317,436);
	bar(5,432,317,436);

	bar(322,20,326,436);
	bar(322,20,635,24);
	bar(631,20,635,436);
	bar(322,432,635,436);

	setcolor(10);
	line(161,25,161,412);
	line(478,25,478,412);

	line(10,412,312,412);
	line(327,412,630,412);

	setfillstyle(1,9);
	bar(0,1,639,10);

	setfillstyle(1,9);
	bar(0,470,639,480);
	}
void tabl(char*sl)
	{
	int i,j,x,k;
	char s[80];
	strcpy(s,sl);
	strcat(s,"\\*.");
		for (k=0, i=0; sl[i]!='\0'; i++)
			if (sl[i]=='\\') k++;
		j=3;
		i=14;
		if (k>0) {setcolor(15); outtextxy(i,10*j,".."); j=4;}
		setcolor(14);
		struct ffblk papki;
		x=findfirst(s,&papki,0x10);
		while (!x)
			{
			if (papki.ff_name[0]!='.')
				{
				outtextxy(i,10*j,papki.ff_name);
				j++;
				if (j==41) {j=3; i=166;}
				}
			x=findnext(&papki);
			}

	strcpy(s,sl);
	strcat(s,"\\*.*");
	setcolor(13);
		struct ffblk fail;
		x=findfirst(s,&fail,0x02);
		while (!x)
			{
			outtextxy(i,10*j,fail.ff_name);
			x=findnext(&fail);
			j++;
			if (j==41) {j=3; i=166;}
			}

	}
void tabr(char*sl)
	{
	int i,j,x,k;
	char s[80];
	strcpy(s,sl);
	strcat(s,"\\*.");
		for (k=0, i=0; sl[i]!='\0'; i++)
			if (sl[i]=='\\') k++;
		j=3;
		i=331;
		if (k>0) {setcolor(15); outtextxy(i,10*j,".."); j=4;}
		setcolor(14);
		struct ffblk papki;
		x=findfirst(s,&papki,0x10);
		while (!x)
			{
			if (papki.ff_name[0]!='.')
				{
				outtextxy(i,10*j,papki.ff_name);
				j++;
				if (j==41) {j=3; i=483;}
				}
			x=findnext(&papki);
			}
	strcpy(s,sl);
	strcat(s,"\\*.*");
	setcolor(13);
		struct ffblk fail;
		x=findfirst(s,&fail,0x02);
		while (!x)
			{
			outtextxy(i,10*j,fail.ff_name);
			x=findnext(&fail);
			j++;
			if (j==41) {j=3; i=483;}
			}


	}
void nazl(char*sl)
	{
	int n,x=161;
	n=strlen(sl);
	x=x-n*4;
	setfillstyle(1,14);
	bar(x-5,15,161+(161-(x-5))-2,27);
	outtextxy(x,18,sl);
	}
void nazr(char*sl)
	{
	int n,x=478;
	n=strlen(sl);
	x=x-n*4;
	setfillstyle(1,14);
	bar(x-5,15,478+(478-(x-5))-2,27);
	outtextxy(x,18,sl);
	}
void nnaz(char*sl,int k1)
	{
	int i,j,x,k,k2=0;
	char s[80],s1[80];

	setfillstyle(1,0);
	bar(10,413,312,431);

	strcpy(s,sl);
	strcat(s,"\\*.");
	for (k=0, i=0; sl[i]!='\0'; i++)
			if (sl[i]=='\\') k++;
	if (k>0 && k1==1) {outtextxy(14,420,".."); return;}
	if (k>0) k2=1;

		struct ffblk papki;
		x=findfirst(s,&papki,0x10);
		if (k==0) k2++;
		while (!x && k1!=k2)
			{
			x=findnext(&papki);
			if (papki.ff_name[0]!='.') k2++;
			}
	if (k2==k1)
		{
		outtextxy(14,420,papki.ff_name);
		setcolor(14);
		outtextxy(120,420,"Papka");
		itoa(papki.ff_fdate,s1,10);
		outtextxy(180,420,s1);
		itoa(papki.ff_ftime,s1,10);
		outtextxy(240,420,s1);
		return;
		}


	strcpy(s,sl);
	strcat(s,"\\*.*");
		struct ffblk fail;
		x=findfirst(s,&fail,0x02);
		k2++;
		while (!x && k2!=k1)
			{
			x=findnext(&fail);
			k2++;
			}
	if (k2==k1)
		{
		outtextxy(14,420,fail.ff_name);
		setcolor(14);
		outtextxy(120,420,"FAIL");
		itoa(fail.ff_fsize,s1,10);
		outtextxy(160,420,s1);
		itoa(fail.ff_fdate,s1,10);
		outtextxy(180,420,s1);
		itoa(fail.ff_ftime,s1,10);
		outtextxy(240,420,s1);
		return;
		}


	}