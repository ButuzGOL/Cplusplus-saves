#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
//#include <string.h>
#include <stdlib.h>
char* st(char*,char*);
void main()
	{
clrscr();
	char *s=new char[80];
	char *s1=new char[80];

		gets(s);
		st(s,s1);
		puts(s1);


getch();
	}
char* st(char *s,char *s1)
	{
	int i=0;
	while(s[i]!='\0')
		{
		s1[i]=s[i];
		s1[i]='\0';
		i++;
		}

	return s1;

	}
