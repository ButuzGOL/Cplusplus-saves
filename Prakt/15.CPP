#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<iomanip.h>

void main()
	{
	clrscr();

	int i,j,k,n;
	char *s=new char[80];
	char *s1=new char[80];
	char *s2=new char[80];

		strcpy(s2,"");
		gets(s);
		strcat(s," ");
		for (i=0,k=0; s[i]!='\0'; i++)
			if (s[i]==' ') k++;
		for (i=0; i<k; i++)
			{
			for (j=0; s[j]!=' '; j++);
			strncpy(s1,s,j);
			s1[j]='\0';
			n=strlen(s1);
			if (n>5) {strcat(s2,s1); strcat(s2," ");}
			strcpy(s,&s[j+1]);
			}
		puts(s2);

	getch();
	}
