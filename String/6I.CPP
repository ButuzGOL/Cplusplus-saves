#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int proverka(char**,int,char*);
void main()
	{
clrscr();
	char *s=new char[80];
	char *s1=new char[80];
	int i,n,kol=1,j,k;

		gets(s);
		n=strlen(s);
		strcat(s," ");
		for (i=0;i<n-1;i++)
			if (s[i]==' ' && s[i+1]!=' ') kol++;

	char **a=new char *[kol];

		for (i=0;i<kol;i++)
			a[i]=new char [40];

		j=0;
		while (strchr(s,' '))
			{
			for (i=0;s[i]!=' ';i++);
			strncpy(s1,s,i);
			s1[i]='\0';
			strcpy(a[j],s1); j++;
			strcpy(s,&s[i+1]);
			}

		for (i=0;i<kol;i++)
			if (proverka(a,i,a[i])==0)
				{
				puts(a[i]);
				cout<<proverka(a,kol,a[i])<<endl;
				}

		delete []s;
		delete []a;
getch();
	}
int proverka(char **x,int n,char *y)
	{
	for (int i=0,k=0;i<n;i++)
		if (strcmp(x[i],y)==0) k++;
		if (k>0) return k;
	return 0;
	}
