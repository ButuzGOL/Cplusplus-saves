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

	int max,min,a[17],i,i1,j1;

		a[0]=random(10)-5;
		max=a[0];
		min=a[0];
		i1=0;
		j1=0;
		cout<<a[0];
		for (i=1; i<17; i++)
			{
			a[i]=random(10)-5;
			cout<<'\n'<<a[i];
			if (a[i]<min) {min=a[i]; i1=i;}
			if (a[i]>max) {max=a[i]; j1=i;}
			}
		cout<<'\n'<<max<<"  "<<j1;
		cout<<'\n'<<min<<"  "<<i1;
	getch();
	}
