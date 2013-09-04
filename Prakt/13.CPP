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

	int i,a[10],j,k,max;

		for (i=0; i<10; i++)
			cin>>a[i];

		for (i=0; i<10; i++)
			{
			max=a[i];
			k=i;
			for (j=k; j<10; j++)
				if (a[j]>max) {max=a[j]; k=j;}

			a[k]=a[i];
			a[i]=max;
			}

		for (i=0; i<10; i++)
			cout<<a[i]<<endl;



	getch();
	}
