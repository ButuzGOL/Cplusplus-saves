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

	int i;
	float a[7],s=0;

		for (i=0; i<7; i++)
			cin>>a[i];

		for (i=0; i<7; i++)
			s+=a[i];
		s=s/7;

		for (i=0; i<7; i++)
			if (a[i]<s) cout<<'\n'<<a[i];
	getch();
	}
