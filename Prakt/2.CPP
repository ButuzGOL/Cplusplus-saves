#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>

void main()
	{
  clrscr();
  int a,b;

	cin>>a;
	cin>>b;
	if (a<=b)
		{
		gotoxy(40,25);
		textcolor(14);
		cout<<a*b;
		}
	else
		{
		gotoxy(76,1);
		textcolor(14);
		cout<<a<<"*"<<b;
		};

  getch();
	}
