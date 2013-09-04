#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>

void main()
	{
  clrscr();
  int s=1,a,i;

	for (i=0; i<9; i++)
		{
		cin>>a;
		if (a<0) s*=a;
		}
	cout<<s;
  getch();
	}
