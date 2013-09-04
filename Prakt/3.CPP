#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>

void main()
	{
  clrscr();
  int a,i,s=0;
	for (i=0; i<13; i++)
		{
		cin>>a;
		if (a>0 && a%4!=0) s+=a;
		}
	cout<<s;
  getch();
	}
