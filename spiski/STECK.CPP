#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<iomanip.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
struct Elem
	{
	int x;
	Elem*p;
	};
Elem *first(int);
void push(Elem**,int);
int  pop(Elem**);
void main()
	{
clrscr();
	int x;
		cout<<"Введите список (стек):"<<endl;
		cin>>x;
	Elem*top=first(x);
		for (int i=1;i<5;i++)
			{
			cin>>x;
			push(&top,x);
			}
		cout<<"\nРаспечатка:"<<endl;
		while(top)
			cout<<pop(&top)<<" ";
getch();
	}
Elem *first(int d)
	{
	Elem*c=new Elem;
	c->x=d;
	c->p=0;
	return c;
	}
void push (Elem**top,int d)
	{
	Elem *c=new Elem;
	c->x=d;
	c->p=*top;
	*top=c;
	}
int pop(Elem**top)
	{
	int temp=(*top)->x;
	Elem*c=*top;
	*top=(*top)->p;
	delete c;
	return temp;
	}