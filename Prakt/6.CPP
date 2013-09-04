#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

void main()
	{
	clrscr();
	randomize();

	int max,min,a,i;

		a=random(9)-4;
		max=a;
		min=a;
		cout<<a;
		for (i=0; i<9; i++)
			{
			a=random(9)-4;
                        cout<<'\n'<<a;
			if (a<min) min=a;
			if (a>max) max=a;
			}
		cout<<'\n'<<max-min;

	getch();
	}
