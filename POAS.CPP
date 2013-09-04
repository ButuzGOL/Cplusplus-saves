#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <iomanip.h>

struct korabl
	{ char n[10];
	  int g;
	} a[3];

struct gryz
	{ char n[10];
	  int g;
	} b[2];


void main()
	{
	clrscr();
	int i,j,l,k,k1,k2;
	char n[10];
		for (i=0; i<3; i++)
			{
			cout<<"Nazvanie koroblya ";
			cin>>a[i].n;
			cout<<"Gruzopodemnost ";
			cin>>a[i].g;
			cout<<'\n';
			}

		cout<<'\n';
		for (i=0; i<2; i++)
			{
			cout<<"Nazvanie gruza ";
			cin>>b[i].n;
			cout<<"Ves ";
			cin>>b[i].g;
			}

		for (i=0; i<2; i++)
			{k1=0; k2=0;

			for (j=0; j<3; j++)
				{
				if (a[j].g>=b[i].g)
					{
					for (l=0, k=0; l<10; l++)
						if (a[j].n[l]==b[i].n[l]) k++;
					if (k==10)
						{
						if (k1==0)
							cout<<'\n'<<i+1<<" gruz povezet korabl N \n";
						k1=1;
						cout<<j+1<<'\n';
						} else {k2++;
						  if (k2==3)  cout<<'\n'<<i+1<<" gruz ne vozmet ne odin korabl";}
					} else {k2++;
					if (k2==3) cout<<'\n'<<i+1<<" gruz ne vozmet ne odin korabl";}
				}
			}
		do
			{
			k=1;
			for (i=0; i<2; i++)
				if (a[i].g>a[i+1].g)
					{k1=a[i].g;
					 for (j=0; j<10; j++)
						n[j]=a[i].n[j];
					 a[i].g=a[i+1].g;
					 for (j=0; j<10; j++)
						a[i].n[j]=a[i+1].n[j];
					 a[i+1].g=k1;
					 for (j=0; j<10; j++)
						a[i+1].n[j]=n[j];
					 k=0;
					 }
			}
			while(!k);

                cout<<'\n';
		for (i=0; i<3; i++)
			{
			cout<<'\n';
			cout<<"Nazvanie koroblya ";
			cout<<a[i].n;
			cout<<'\n';
			cout<<"Gruzopodemnost ";
			cout<<a[i].g;
			cout<<'\n';
			}


getch();
}