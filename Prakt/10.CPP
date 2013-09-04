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

	const n=2;
	const m=5;
	int i,a[n][m],j,s=0;

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
			for (j=0; j<m; j++)
				if (a[i][j]<0) s+=a[i][j];
		cout<<s;
	getch();
	}
