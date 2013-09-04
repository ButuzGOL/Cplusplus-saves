#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int st(int);
int st1(int);
int st2(int);
void main()
	{
clrscr();
	int x,pr;
		for (int i=5;i<8;i++)
			{
			pr=st(i);
			cout<<pr<<'\n';
			}
		cout<<"\n2 Zadanie\n\n";
		for (i=5;i<8;i++)
			{
			pr=st1(i);
			cout<<pr*-1<<'\n';
			}
		cout<<"\n3 Zadanie\n\n";
		for (i=5;i<8;i++)
			{
			pr=st2(i);
			cout<<pr<<'\n';
			}
getch();
	}
int st(int x)
	{
	if(x==1) return 1;
	else st(x-1)+2;
	}
int st1(int x)
	{
	if(x==0) return 1;
	else st1(x-1)*(-2);
	}
int st2(int x)
	{
	if(x==1) return 1;
	else st2(x-1)*3-1;
	}
