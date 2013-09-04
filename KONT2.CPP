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
struct fog
	{
	char* punkt,*fio;
	int nom;
	data dd;
	fog *next;
	}; fog *first1=0,*last,*c;

bilet *first();
bilet *first2();
bilet *dobavl(bilet*,bilet*,int);
bilet *dobavl2(bilet*,bilet*,fog*,int);
void *search(bilet*,int d);
void vivod(bilet*,int l);
void del(bilet*root);
void ochis();
void main()
	{
	clrscr();
	int nom;
	bilet* root=first();

		for(int i=1; i<3;i++)
			{
			cin>>nom;
			dobavl(root,0,nom);
			}
		vivod(root,0);
		cout<<endl;
		del(root);

		root=first2();

		c=first1;
		cout<<endl<<endl;

		for (i=1;i<3;i++)
			{
			if (c->nom!=2) dobavl2(root,0,c,c->nom);
			c=c->next;
			}

		vivod(root,0);
		search(root,3);
		ochis();

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

bilet* first2()
	{

	bilet*p=new bilet;

	c=last;

	strncpy(c->fio,p->fio,strlen(p->fio));
		c->fio[strlen(p->fio)]='\0';

	p->punkt=c->punkt;
	p->nom=c->nom;
	p->dd.d=c->dd.d;
	p->dd.m=c->dd.m;
	p->dd.y=c->dd.y;

	p->left=0;
	p->right=0;
	return p;
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
bilet* dobavl2(bilet* rt,bilet* rt1,fog*c,int d)
			{
			if (!rt || d==rt->nom)
				{
				bilet *p=new bilet;

				strncpy(c->fio,p->fio,strlen(p->fio));
				c->fio[strlen(p->fio)]='\0';

				p->punkt=c->punkt;
				p->nom=c->nom;
				p->dd.d=c->dd.d;
				p->dd.m=c->dd.m;
				p->dd.y=c->dd.y;


				p->left=0;
				p->right=0;

				if (d<rt1->nom) rt1->left=p;
				else rt1->right=p;
				return p;
				}
			else

				if (d<rt->nom) dobavl2(rt->left,rt,c,d);
				else dobavl2(rt->right,rt,c,d);


	}

void vivod(bilet* p,int l)
	{
	if (p)
		{
		vivod(p->left,l+1);

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
	}
void* search(bilet* rt,int d)
	{
			if (!rt || d==rt->nom)
				{

				cout<<"fio ";
				puts(rt->fio);

				cout<<"punkt ";
				puts(rt->punkt);

				cout<<"Nomer "<<rt->nom<<endl;

				cout<<"Data\n";

				cout<<" Den "<<rt->dd.d<<endl;


				cout<<" Mes "<<rt->dd.m<<endl;


				cout<<" God "<<rt->dd.y<<endl;
				return 0;
				}
			else
				if (d<rt->nom) search(rt->left,d);
				else search(rt->right,d);





	}
void del(bilet* p)
	{
	fog*c=new fog;
	if (p)
		{
		del(p->left);
		del(p->right);

		strncpy(c->fio,p->fio,strlen(p->fio));
		c->fio[strlen(p->fio)]='\0';
		c->punkt=p->punkt;
		c->nom=p->nom;
		c->dd.d=p->dd.d;
		c->dd.m=p->dd.m;
		c->dd.y=p->dd.y;


		c->next=0;
		if (first1==0) first1=c;
		else last->next=c;
		last=c;

		delete p;
		}
	}
void ochis()
	{
	fog*c;
	c=first1;
	while(first1!=0)
		{
		c=first1;
		first1=first1->next;
		delete c;
		}
	}