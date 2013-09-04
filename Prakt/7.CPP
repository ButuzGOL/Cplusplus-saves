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

	int a[11],i,b[5],j;

		for (i=0,j=0; i<11; i++)
			{
			cin>>a[i];
			if (i%2!=0)
				{
				b[j]=a[i];
				j++;
				}
			}

		for(i=0; i<5; i++)
			cout<<'\n'<<b[i];

	getch();
	}
