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
Elem *first(int d);
Elem *search_insert(Elem*root,Elem*root1,int d);
Elem *search(Elem*root,int d);
void del(Elem*);
void print_tree(Elem* root,int l);

void main()
	{
	clrscr();
	int b[]={10,25,20,6,21,15,1,30};
	Elem* root=first(b[0]);

		for (int i=1;i<8;i++)
			search_insert(root,0,b[i]);
		print_tree(root,0);
	       //	del(root);
	       //	print_tree(root,0);

		//cout<<endl;
	       //	cout<<search(root,50)->x;

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
		getch();
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
	if (p)
		{
		del(p->left);
		delete p;
		del(p->right);
		}
	}