#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<iomanip.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct film
	{
	char s[40];
	int x;
	film *next;
	};
	film *first=0,*last=0,*c,*c1,*first1=0,*last1=0;

void soz(film**,film**);
void vivod(film*);
film* dor();
int kolm(film*);
void znaz(char*,char*);
void udal(char*);
void sort(film**);
void vst(char*,int);

void main()
	{
clrscr();


	soz(&first,&last);
	cout<<endl;
	vivod(first);
	cout<<endl;
	puts(dor()->s);

	cout<<dor()->x<<endl;
	cout<<endl<<"KOL "<<kolm(dor())<<endl;

	znaz("Fog","Best");
	cout<<endl;
	vivod(first);
	udal("Best");
	cout<<endl;
	sort(&first);
	vst("Bati_GOL",50);
	vivod(first);


getch();
	}
void soz(film**fir,film**las)
	{
	for (int i=0; i<3; i++)
			{
			c=new film;
			c->next=0;
			cout<<"vvedite naz ";
			gets(c->s);
			cout<<"vvedite cenu ";
			cin>>c->x;
			if (*fir==0) *fir=c;
			else (*las)->next=c;
			*las=c;
			}
	}


void vivod(film*fir)
	{
	c=fir;
	while(c!=0)
		{
		cout<<"Naz ";
		puts(c->s);
		cout<<"Cena "<<c->x<<endl;
		c=c->next;
		}
	}

film* dor()
	{
	int max=-1;
	c=first;

	while(c!=0)
		{
		if (c->x>max)  {max=c->x; c1=c;}
		c=c->next;
		}
	return c1;
	}
int kolm(film*m)
	{
	int k=0;
	c=first;
	c1=m;
	while(c!=0)
		{
		if ((c1->x)-(c->x)<=c1->x*0.1) k++;
		c=c->next;
		}
	k--;
	return k;
	}
void znaz(char*s,char*s1)
	{
	c=first;
	while(c!=0)
		{
		if (strcmp(c->s,s)==0) {strcpy(c->s,s1); return;}
		c=c->next;
		}
	}
void udal(char*s)
	{
	int k=0;
	c=first;
	while(c!=0)
		{
		if (strcmp(c->s,s)==0) k++;
		c=c->next;
		}
	c=first;
	if (k==0) return;
	if (strcmp(c->s,s)==0)
		{
		first=first->next;
		delete c;
		return;
		}

	while(strcmp(c->next->s,s)!=0)
		c=c->next;

	c1=new film;
	c1=c->next;
	c->next=c1->next;
	delete c1;
	}
void sort(film**fir)
	{
	char s[40];
	int d,m;
	do
		{
		d=1;
		c=*fir;
		while(c->next!=0)
			{
			if (c->x<c->next->x)
				{
				m=c->x;
				strcpy(s,c->s);
				c->x=c->next->x;
				c->next->x=m;
				strcpy(c->next->s,s);
				d=0;
				}
			c=c->next;
			}
		}
	while (!d);
	}
void vst(char*s,int x)
	{
	int i=1;
	sort(&first);
	c=first;

		c1=new film;
		c1->x=x;
		strcpy(c1->s,s);
            c1->next=0;
	if (c->x<=x)
		{
		c1->next=first;
		first=c1;
		return;
		}
	

	while(c->next!=0)
		{
		if (c->x<=x && c->next->x>=x)
			{
			strcpy(c->s,s);
			c->next=c1;
			return;
			}
		c=c->next;
		}
	c->next=c1;
	last=c1;

	}
