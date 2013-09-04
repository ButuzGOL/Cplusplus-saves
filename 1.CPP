#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int minim(int*,int,int);
void main()
	{
clrscr();
randomize();
	const n=8;
	int i,min,a[n],y,x;

		for (i=0; i<n; i++)
			a[i]=random(11)-4;

		for (i=0; i<n-1; i++)
			{
			x=minim(a,n,i);
			y=a[i];
			a[i]=a[x];
			a[x]=y;
			}
		for (i=0; i<n; i++)
			cout<<a[i]<<'\n';

getch();
	}
int minim(int *a,int n, int i)
	{
	int min;
		min=i;
		for (i; i<n; i++)
			if (a[i]<a[min]) min=i;
	return min;
	}
