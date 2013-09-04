#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<iomanip.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data
	{
	int d,m,y;
	};
struct bilet
	{
	char* punkt,*fio;
	int nom;
	data dd;

	bilet *left;
	bilet *right;
	};
bilet *first();
bilet *dobavl(bilet*,bilet*,int);
//Elem *search(bilet*,int d);
void vivod(bilet*,int l);

void main()
	{
	clrscr();
	int nom;
	bilet* root=first();
		cout<<"VVedite nomer ";
		cin>>nom;
		dobavl(root,0,nom);
		vivod(root,0);


		//cout<<endl;
	       //	cout<<search(root,50)->x;

	getch();
	}

bilet* first()
	{

	bilet*c=new bilet;

	cout<<"fio ";
	gets(c->fio);

	cout<<"punkt ";
	gets(c->punkt);

	cout<<"Nomer ";
	cin>>c->nom;

	cout<<"Data\n";

	cout<<" Den ";
	cin>>c->dd.d;

	cout<<" Mes ";
	cin>>c->dd.m;

	cout<<" God ";
	cin>>c->dd.y;


		c->left=0;
		c->right=0;
	return c;
	}
bilet* dobavl(bilet* rt,bilet* rt1,int d)
	{

			if (!rt || d==rt->nom)
				{
				bilet *p=new bilet;

				cout<<"fio ";
				gets(p->fio);

				cout<<"punkt ";
				gets(p->punkt);

				p->nom=d;

				cout<<"Data\n";

				cout<<" Den ";
				cin>>p->dd.d;

				cout<<" Mes ";
				cin>>p->dd.m;

				cout<<" God ";
				cin>>p->dd.y;

				p->left=0;
				p->right=0;

				if (d<rt1->nom) rt1->left=p;
				else rt1->right=p;
				return p;
				}
			else

				if (d<rt->nom) dobavl(rt->left,rt,d);
				else dobavl(rt->right,rt,d);


	}
void vivod(bilet* p,int l)
	{
	if (p)
		{
		vivod(p->left,l+1);
		for (int i=0; i<l; i++)
			cout<<" ";

		cout<<"fio ";
		puts(p->fio);

		cout<<"punkt ";
		puts(p->punkt);

		cout<<"Nomer "<<p->nom<<endl;

		cout<<"Data\n";

		cout<<" Den "<<p->dd.d<<endl;


		cout<<" Mes "<<p->dd.m<<endl;


		cout<<" God "<<p->dd.y<<endl;


		vivod(p->right,l+1);
		}
	} /*
Elem* search(Elem* rt,int d)
	{
			if (!rt || d==rt->x) return rt;
			else
				if (d<rt->x) search(rt->left,d);
				else search(rt->right,d);
	}*/
