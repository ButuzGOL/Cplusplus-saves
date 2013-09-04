#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<iomanip.h>

void main()
	{
	clrscr();
	randomize();

	const n=5;
	const m=2;
	int i,a[n][m],j,k;

		for (i=0; i<n; i++)
			for (j=0; j<m; j++)
				a[i][j]=random(9)-4;

		for (i=0; i<n; i++)
			{
			for (j=0; j<m; j++)
				cout<<setw(3)<<a[i][j];
			cout<<'\n';
			}

		for (i=0; i<n; i++)
			{
			k=0;
			for (j=0; j<m; j++)
				if (a[i][j]<0) k++;
			if (k==2) cout<<i<<'\n';
			}
	getch();
	}
