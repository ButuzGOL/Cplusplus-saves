#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdio.h >
#include<ctype.h>
#include<stdlib.h>

int f(int *a)
	{
	for(int i=0,s=0; i<5; i++)
		s+=a[i];

	return s/5;
	}
void main()
	{
	clrscr();
	randomize();

	int a[5],i;

		for(i=0; i<5; i++)
			a[i]=random(9)+1;

		for(i=0; i<5; i++)
			cout<<a[i]<<'\n';
                cout<<f(a);


  getch();
	}
