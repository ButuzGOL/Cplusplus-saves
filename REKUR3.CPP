#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <graphics.h>
int nod(int,int);
void main()
	{
clrscr();
	int a=6,b=20;
	cout<<nod(a,b);

getch();
	}
int nod(int a,int b)
	{
	if (a==1 || b==1) return ;
	else nod(a-1,b-1);


	}
