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
Elem *search_insert(Elem*root,int d);
void print_tree(Elem* root,int l);
void main()
	{
	clrscr();
	int b[]={10,25,20,6,21,8,1,30};
	Elem* root=first(b[0]);

		for (int i=1;i<8;i++)
			search_insert(root,b[i]);
		print_tree(root,0);
	getch();
	}
Elem*first(int d)
	{
	Elem*c=new Elem;

	c->x=d;
	c->left=0;
	c->right=0;
	return c;
	}
Elem * search_insert(Elem* root,int d)
	{
	Elem *c=root,*prev;
	int found=0;

		while (c && !found)
			{
			prev=c;
			if (d==c->x) found=1;
			else 	if(d<c->x) c=c->left;
				else c=c->right;
			}
	if (found) return c;

	Elem *p=new Elem;

		p->x=d;
		p->left=0;
		p->right=0;
		if (d<prev->x) prev->left=p;
		else prev->right=p;

	return p;
	}
void print_tree(Elem* p,int l)
	{
	if (p)
		{
		print_tree(p->left,l+1);
		for (int i=0;i<l;i++) cout<<" ";
			cout<<p->x<<endl;
		print_tree(p->right,l+1);
		}
}