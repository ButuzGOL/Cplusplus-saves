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
	};
	elem *first=0,*last,*c,*c1,*first1=0,*last1,*first2=0,*last2;

int kol();
elem *poisk(int);
void sort();
void soz(elem*);
void vivod(elem*);
void ochis();
void vst1(int,int);
void vst2(int);
void udal1(int);
void udal2(int);
void dob(elem*,elem*,int);
void rastus();

void main()
	{
clrscr();
	int y;

	soz(first);
	vivod(first);
	/*
	cout<<endl<<"kol="<<kol()<<endl;
	cout<<"vvedite nugnij element  ";
	cin>>y;
	cout<<"Poisk  "<<poisk(y)<<endl;
	sort();
	ochis();
	vst1(6,777);
	vst2(5);
	udal1(1);
	udal2(5);
	rastus();
	*/


getch();
	}
void soz(elem**fir)
	{
	for (int i=0; i<5; i++)
			{
			c=new elem;
			c->next=0;
			cin>>c->x;
			if (*fir==0) *fir=c;
			else last->next=c;
			last=c;
			}
	}
void vivod(elem*fir)
	{
	c=fir;
	while(c!=0)
		{
		cout<<c->x<<"  ";
		c=c->next;
		}
	}
int kol()
	{
	elem *c;
	c=first;
	int k=0;
	while(c!=0)
		{
		k++;
		c=c->next;
		}
	return k;
	}
elem* poisk(int y)
	{
	c=first;
	while(c!=0)
		{
		if (c->x==y)  return c;
		c=c->next;
		}
	if (c==0) return 0;
	}
void sort()
	{
	elem *c;
	int d,m;
	do
		{
		d=1;
		c=first;
		while(c->next!=0)
			{
			if (c->x<c->next->x)
				{
				m=c->x;
				c->x=c->next->x;
				c->next->x=m;
				d=0;
				}
			c=c->next;
			}
		}
	while (!d);
	}
void ochis()
	{
	while(first!=0)
		{
		c=first;
		first=first->next;
		delete c;
		}
	}
void vst1(int n,int x)
	{
	int i=1;
	c=first;
	if (n==1)
		{
		c->x=x;
		c=c->next;
		return;
		}
	if (n>kol()+1)	{cout<<"Vvodim normalno"<<endl; return;}

	while(i!=n-1)
		{
		i++;
		c=c->next;
		}

	c1=new elem;
	c1->next=c->next;
	c1->x=x;
	c->next=c1;
	if (n==kol()+1) c=last;
	}
void vst2(int x)
	{
	int i=1;
	c=first;

	while(c->x!=x)
		c=c->next;

	c1=new elem;
	c1->next=c->next;
	c1->x=x;
	c->next=c1;
	}
void udal1(int n)
	{
	int i=1;

	c=first;
	if (n==1)
		{
		first=first->next;
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
	delete c1;
	}
void udal2(int x)
	{
	int i=1;

	c=first;
	if (c->x==x)
		{
		first=first->next;
		delete c;
		return;
		}

	while(c->next->x!=x)
		c=c->next;

	c1=new elem;
	c1=c->next;
	c->next=c1->next;
	delete c1;
	}
void dob(elem**fir,elem**las,int x)
	{
	elem*c;
	c=new elem;
	c->x=x;
	c->next=0;
	if (*fir==0) *fir=c;
	else (*las)->next=c;
	*las=c;
	}
void rastus()
	{
	elem*c;
	c=first;
	while(c!=0)
		{
		if (c->x>0) dob(&first1,&last1,c->x);
		if (c->x<0) dob(&first2,&last2,c->x);
		c=c->next;
		}
	cout<<endl;
	vivod(first1);
	cout<<endl;
	vivod(first2);
        }


