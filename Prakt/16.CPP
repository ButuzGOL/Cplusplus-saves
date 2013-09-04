#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<iomanip.h>
struct fam
	{
	char f[80];
	int g;
	}a[3],god;
void main()
	{
	clrscr();

	int i,k=0;
	char *s=new char[80];


		for (i=0; i<3; i++)
			{
			cout<<"Vvedite familuu: ";
			cin>>a[i].f;
			cout<<"Vvedite god: ";
			cin>>a[i].g;
			cout<<endl;
			}

		for (i=0; i<3; i++)
			{
			cout<<"familuu: ";
			cout<<a[i].f;
			cout<<endl;
			cout<<"god: ";
			cout<<a[i].g;
			cout<<endl;
			}

		do
			{
			k=1;
			for(i=0; i<2; i++)
				if (a[i].g>a[i+1].g)
					{
					god=a[i];
					a[i]=a[i+1];
					a[i+1]=god;
					k=0;
					}
			}
		while(!k);

		cout<<endl;
		for (i=0; i<3; i++)
			{
			cout<<"familuu: ";
			cout<<a[i].f;
			cout<<endl;
			cout<<"god: ";
			cout<<a[i].g;
			cout<<endl;
			}
		do
			{
			k=1;
			for(i=0; i<2; i++)
				if (strcmp(a[i].f,a[i+1].f)>0)
					{
					god=a[i];
					a[i]=a[i+1];
					a[i+1]=god;
					k=0;
					}
			}
		while(!k);

		cout<<endl;
		for (i=0; i<3; i++)
			{
			cout<<"familuu: ";
			cout<<a[i].f;
			cout<<endl;
			cout<<"god: ";
			cout<<a[i].g;
			cout<<endl;
			}

	getch();
	}
