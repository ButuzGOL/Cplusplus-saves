#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<iomanip.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Elem
	{
	int x;
	Elem *left;
	Elem *right;
	};
struct fog
	{
	int l;
	fog *next;
	}; fog *first1=0,*last,*c;

Elem *first(int d);
Elem *search_insert(Elem*root,Elem*root1,int d);
Elem *search(Elem*root,int d);
void del(Elem*root);
void print_tree(Elem* root,int l);
void ochis();
void main()
	{
	clrscr();
	int b[]={10,25,20,6,21,15,1,30};
	Elem* root=first(b[0]);

		for (int i=1;i<8;i++)
			search_insert(root,0,b[i]);
		print_tree(root,0);
		del(root);
		c=first1;
		while(c!=0)
			{
			cout<<c->l<<" ";
			c=c->next;
			}
		root=first(last->l);
		c=first1;
		cout<<endl<<endl;
		for (i=1;i<8;i++)
			{
			if(c->l!=21) search_insert(root,0,c->l);
			c=c->next;
			}
		print_tree(root,0);
		ochis();
		search_insert(root,0,21);
		print_tree(root,0);

	getch();
	}

Elem* first(int d)
	{
	Elem*c=new Elem;

		c->x=d;
		c->left=0;
		c->right=0;
	return c;
	}
Elem* search_insert(Elem* rt,Elem* rt1,int d)
	{

			if (!rt || d==rt->x)
				{
				Elem *p=new Elem;
				p->x=d;
				p->left=0;
				p->right=0;
				if (d<rt1->x) rt1->left=p;
				else rt1->right=p;
				return p;
				}
			else

				if (d<rt->x) search_insert(rt->left,rt,d);
				else search_insert(rt->right,rt,d);


	}
void print_tree(Elem* p,int l)
	{
	if (p)
		{
		print_tree(p->left,l+1);
		for (int i=0; i<l; i++)
			cout<<" ";

		cout<<p->x<<endl;
		print_tree(p->right,l+1);
		}
	}
Elem* search(Elem* rt,int d)
	{
			if (!rt || d==rt->x) return rt;
			else
				if (d<rt->x) search(rt->left,d);
				else search(rt->right,d);
	}
void del(Elem* p)
	{
	fog*c=new fog;
	if (p)
		{
		del(p->left);
		del(p->right);

		c->l=p->x;
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