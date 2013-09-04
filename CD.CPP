#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<iomanip.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct elem
	{
	int x;
	elem *next;
	elem *prev;
	};
	elem *first=0,*last=0,*c,*c1;

void soz(elem**,elem**);
void vivod1(elem*);
void vivod2(elem*);
int kol();
elem *poisk(int);
void sort(elem**);
void ochis();
void vst1(int,int);
void vst2(int,int);
void udal1(int);
void udal2(int);
void main()
	{
clrscr();
	int y;

	soz(&first,&last);
	//vivod1(first);
	//cout<<endl;
	//vivod2(last);
	//cout<<endl<<"Kol "<<kol();
	//cout<<endl<<"Poisk "<<poisk(5);
	//sort(&first);
	//vst1(1,777);
	//vst2(5,777);
	//udal1(5);
	//udal2(5);
	cout<<endl;
	vivod1(first);
	cout<<endl;
	vivod2(last);
	ochis();

getch();
	}
void soz(elem**fir,elem**las)
	{
	for (int i=0; i<5; i++)
			{
			c=new elem;
			c->next=*fir;
			cin>>c->x;
			if (*fir==0) *fir=c;
			else {c->prev=*las; (*las)->next=c;}
			*las=c;
			}
	(*fir)->prev=*las;
	}
void vivod1(elem*fir)
	{
	c=fir;
	do
		{
		cout<<c->x<<"  ";
		c=c->next;
                getch();
		}
	while(c!=fir);
	}
void vivod2(elem*las)
	{
	c=las;
	do
		{
		cout<<c->x<<"  ";
		c=c->prev;
		}
	while(c!=las);
	}
int kol()
	{
	elem *c;
	c=first;
	int k=0;
	do
		{
		k++;
		c=c->next;
		}
	while(c!=first);
	return k;
	}
elem* poisk(int y)
	{
	c=first;
        do
		{
		if (c->x==y)  return c;
		c=c->next;
		}
	while(c!=first);
	if (c==first) return 0;
	}
void sort(elem**fir)
	{
	elem *c;
	int d,m;
	do
		{
		d=1;
		c=*fir;
		do
			{
			if (c->x>c->next->x)
				{
				m=c->x;
				c->x=c->next->x;
				c->next->x=m;
				d=0;
				}
			c=c->next;
			}
		while(c->next!=first);
		}
	while (!d);
	}
void ochis()
	{
	c=first->next;
	while(c!=first)
		{
		first->next=c->next;
		delete c;
		c=first->next;
		}
	delete first;
	c=last->prev;
	while(c!=last)
		{
		last->prev=c->prev;
		delete c;
		c=last->prev;
		}
        delete last;
	}
void vst1(int n,int x)
	{
	int i=1;
	c=first;
	c1=new elem;
	c1->x=x;
	if (n==1)
		{
		first->prev=c1;
		c1->next=first;
		first=c1;
		first->prev=last;
		last->next=first;
		return;
		}
	if (n>kol()+1)	{cout<<"Vvodim normalno"<<endl; return;}

	while(i!=n-1)
		{
		i++;
		c=c->next;
		}

	c1->next=c->next;
	c->next=c1;
	c1->prev=c;
	c=c1->next;
	c->prev=c1;
	if (n==kol()) last=c1;
	}
void vst2(int x,int x1)
	{
	c=first;
	c1=new elem;
	c1->x=x1;

	while(c->x!=x)
		c=c->next;

	c1->next=c->next;
	c->next=c1;
	c1->prev=c;
	c=c1->next;
	c->prev=c1;
	if (c1->prev==last) last=c1;
	}
void udal1(int n)
	{
	int i=1;

	c=first;
	if (n==1)
		{
		first=first->next;
		first->prev=last;
		last->next=first;
		delete c;
		return;
		}

	while(n-1!=i)
		{
		i++;
		c=c->next;
		}
	c1=new elem;
	c1=c->next;
	c->next=c1->next;
	c=c1->next;
	c->prev=c1->prev;
	delete c1;
	if (kol()==n-1) last=c1->prev;
	}
void udal2(int x)
	{
	c=first;
	if (c->x==x)
		{
		first=first->next;
		first->prev=last;
		last->next=first;
		delete c;
		return;
		}

	while(c->next->x!=x)
		c=c->next;

	c1=new elem;
	c1=c->next;
	c->next=c1->next;
	c=c1->next;
	c->prev=c1->prev;
	delete c1;
	if (c1==last) last=c1->prev;
	}
