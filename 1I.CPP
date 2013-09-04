#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
char* st1(char*,char*);
char* st2(char*,char*,char*);
int st3(char*,char*);
int st4(char*);
int st5(char*,char*);
char* st6(char*,char*,int,int);
char* st7(char*,char*,int);
char* st8(char*,int,int);
void main()
	{
clrscr();
	char *s=new char[80];

		gets(s);
		cout<<st5(s,"Bati");




getch();
	}
char* st1(char *s,char *s1)
	{
	int i=0;
	while(s[i]!='\0')
		{
		s1[i]=s[i];
		i++;
		}
		s1[i]='\0';

	return s1;

	}
char* st2(char *s,char *s1,char *s2)
	{
	int i=0,j=0;
	while(s[i]!='\0')
		{
		s2[i]=s[i];
		i++;
		}
		s2[i]='\0';
	while(s1[j]!='\0')
		{
		s2[i+j]=s1[j];
		j++;
		}
		s2[i+j]='\0';
	return s1;

	}
int st3(char *s,char *s1)
	{
	int i=0,j=0,l=0,k=0;
	while(s[i]!='\0')
		i++;

	while(s1[j]!='\0')
		j++;

	if (i==j)
		{
		while(s[l]!='\0')
			{
			if (s[l]!=s1[l]) k++;
			l++;
			}
		if (k==0) return 0;
		}
	return 1;
	}
int st4(char *s)
	{
	int i=0;
	while(s[i]!='\0')
		i++;
	return i;
	}
int st5(char *s,char *s1)
	{
	int i,k=0,j,l;

		for (i=0; s[i]!='\0'; i++)
			if (s[i]==s1[0])
				{
				for(j=0,l=i; s1[j]!='\0'; j++,l++)
					if (s1[j]==s[l]) k++;
					else break;
				if (k==j) return i++;
				else k=0;
				}
	}
char* st6(char *s,char *s1,int poz,int kol )
	{
	int i=poz-1,j=0;

	while(kol+poz-1!=i)
		{
		s[j]=s1[i];
		i++;
		j++;
		}
		s[j]='\0';
	return s;

	}
char* st7(char *s,char *s1,int poz)
	{
	int i=poz-1,j=0;
	char *s2=new char[80];

	while(s[i]!='\0')
		{
		s2[j]=s[i];
		i++;
		j++;
		}
		s2[j]='\0';
		s[poz-1]='\0';
	j=0;
	i=poz-1;
	while(s1[j]!='\0')
		{
		s[i]=s1[j];
		i++;
		j++;
		}
		s[i]='\0';
	j=0;
	while(s2[j]!='\0')
		{
		s[i]=s2[j];
		i++;
		j++;
		}
		s[i]='\0';

	return s;

	}
char* st8(char *s,int poz,int kol)
	{
	int i=poz-1+kol,j=poz-1;
	
	while(s[i]!='\0')
		{
		s[j]=s[i];
		i++;
		j++;
		}
		s[j]='\0';

       return s;

	}
