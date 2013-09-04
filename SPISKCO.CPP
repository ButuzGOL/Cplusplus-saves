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
	elem *first=0,*last=0,*c,*c1,*first1=0,*last1=0,*first2=0,*last2=0,*first3=0,*last3=0,*first4=0,*last4=0;

int kol(elem*);
elem *poisk(elem*,int);
void sort(elem**);
void soz(elem**,elem**);
void vivod(elem*);
void ochis();
void vst1(int,int);
void vst2(int);
void udal1(int);
void udal2(int);
void dob(elem**,elem**,int);
void rastus();
void sozs();

void main()
	{
clrscr();

	soz(&first,&last);
	//cout<<kol(first);
	//cout<<endl<<poisk(first,8);
	//sort(&first);
	ochis();
	//vst1(6,777);
	vivod(first);
	/*cout<<endl;
	soz(&first4,&last4);
	vivod(first4);
	sozs();
	cout<<endl;
	vivod(first);
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
void soz(elem**fir,elem**las)
	{
	for (int i=0; i<5; i++)
			{
			c=new elem;
			c->next=*fir;
			cin>>c->x;
			if (*fir==0) *fir=c;
			else (*las)->next=c;
			*las=c;
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
int kol(elem*fir)
	{
	elem *c;
	c=fir;
	int k=0;
	do
		{
		k++;
		c=c->next;
		}
	while(c!=fir);
	return k;
	}
elem* poisk(elem*fir,int y)
	{
	c=fir;
	do
		{
		if (c->x==y)  return c;
		c=c->next;
		}
	while(c!=fir);
	if (c==fir) return 0;
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
		while(c->next!=*fir);
		}
	while (!d);
	}
void ochis()
	{
	last->next=0;
	while (first!=0)
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
	if (n>kol(first)+1)	{cout<<"Vvodim normalno"<<endl; return;}

	while(i!=n-1)
		{
		i++;
		c=c->next;
		}

	c1=new elem;
	c1->next=c->next;
	c1->x=x;
	c->next=c1;
	if (n==kol(first)+1) c=last;
	}
void vst2(int x)
	{
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
void sozs()
	{
	sort(&first3);
	sort(&first4);

	elem*c;
	elem*c1;

	c=first3;
	c1=first4;

	while (c!=0 && c1!=0)
		{
		if (c->x>=c1->x)
			{
			dob(&first,&last,c1->x);
			c1=c1->next;
			}
		else
			{
			dob(&first,&last,c->x);
			c=c->next;
			}
		}
	while (c!=0)
		{
		dob(&first,&last,c->x);
		c=c->next;
		}
	while (c1!=0)
		{
		dob(&first,&last,c1->x);
		c1=c1->next;
		}
	}