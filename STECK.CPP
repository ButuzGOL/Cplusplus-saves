#include <iostream.h>
#include <zagol.h>
#include <math.h>
#include <conio.h>
#include <iomanip.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
void *operator new (size_t,void *buf)
	{
	return buf;
	}
struct tmp{
	  int x;
	  tmp *next,*p;
	  };

tmp*first=0,*last=0;
int d;
int r=0,razm=0;
Elem *top=0,*t=0;

void main()
	{
clrscr();
	int key,n;
	do
			{
			menu();
			key=getch();
			switch(key)
				{
				case '1':
					{
					clrscr();
					cout<<"����� ࠧ��� �⥪�:"<<endl;
					cin>>r;
					t=new Elem[r+1];
					break;
					}
				case '2':
					{
					char k=0;
					clrscr();
					if (t==0) cout<<"������ ��� �⥪ �� �뤥���� �롥�� �㭪� 1"<<endl;
					else
						{
						if (razm+1>r)
							{
							cout<<"��᫥ ����� ������ ������� �⥪ �㤥� ��९�����"<<endl;
							cout<<"Dobavit novij element[y/n]?"<<endl;
							cin>>k;
							}
						if (razm+1<=r || k=='y')
							{
							cout<<"Vvod novogo elementa  "<<endl;
							push(&top);
							razm=razm+1;
							}
						if (razm>r)
							{
							cout<<"Stack perepolnen,element v stec ne dobavlen"<<endl;
							pop(&top);
							}
						}
					getch();
					break;
					}
				case '3':
					{
					clrscr();
					if (razm==0) cout<<"Stack pust!"<<endl;
					else
						{
						pop(&top);
						razm=razm-1;
						cout<<"Element udalen!"<<endl;
						}
					getch();
					break;
					}
				case '4':
					{
					clrscr();
					if (top!=0) print (top);
					else cout<<"Steck pust"<<endl;
					getch();
					break;
					}
				case '5':
					{
					if (t==0) cout<<"Pamiat ne videlena";
					else
						{
						if (first!=0)
							{
							tmp*c=first;
							tmp*c1=0;
							while(c!=0)
								{
								c1=c;
								c=c->p;
								delete c1;
								}
							}
						delete[]t;
						razm=0; t=0;
						cout<<"\nPamyat ochish\n";
						}
					getch();
					break;
					}
				case '6':
					{
					clrscr();
					if (razm==0) cout<<"Stack pust!"<<endl;
					else
						{
						if (n==1) pop(&top);
						else udal(top,2);
						razm=razm-1;
						cout<<"Element udalen!"<<endl;
						}
					getch();
					break;
					}


				}
			}
		while(key!='q');
	     }
void push(Elem**top)
	{
	Elem*temp;
	if (top==0) temp=t;
	else temp=t+(razm*sizeof(Elem));
	Elem *c=new(temp)Elem;
	cout<<"\nVvedite chislo \n";
	cin>>c->x;
	c->p=*top;
	*top=c;
	}
void pop(Elem**top)
	{
	*top=(*top)->p;
	}
void print(Elem*top)
	{
	Elem *c=top;
	while(c)
		{
		cout<<c->x<<endl;
		c=c->p;
		}
	}
void menu()
	{
	cout<<"1 Vidilenie pamyati pod stek"<<endl;
	cout<<"2 Dobavlenie elementa v stek"<<endl;
	cout<<"3 Udalenie elementa iz steka (Pervii)"<<endl;
	cout<<"4 Pechat"<<endl;
	cout<<"5 Ochistka pamyati"<<endl;
	cout<<"6 Udalenie elementa iz steka (Luboi)"<<endl;

	}
void udal(Elem*top,int n)
	{
	int k=1,i;
	tmp *c;
	Elem *c1=top;
	while (c1 && k!=n)
		{
		k++;
		c=new tmp;
		c->next=0;
		c->x=c1->x;
		if (first==0) first=c;
		else last->next=c;
		last=c;
		c1=c1->p;
		}
	if (first!=0)
		{
		tmp*c3=first;
		tmp*c4=0;
		while(c!=0)
			{
			c4=c3;
			c3=c3->p;
			delete c4;
			}
		}
		delete[]t;
		}
	while(c!=0)
		{
		Elem*temp;
		if (top==0) temp=t;
		else temp=t+(razm*sizeof(Elem));
		Elem *c2=new(temp)Elem;
		c2->x=c->x;
		c2->p=top;
		top=c2;
		c=c->next;
		}
	}



