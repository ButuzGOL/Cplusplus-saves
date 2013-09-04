#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

void main()


	{
  clrscr();

	char *s1=new char[80];
	char *s=new char[80];
	char *s2=new char[80];

	int i,k=0,j=0,l=0;

		gets(s);
		for (i=0; s[i]!='\0'; i++)
			if (s[i]==' ') k++;


		s2="\0";
		strcat(s," ");
		for(i=0; i<=k; i++)
			{
			for(j=0; s[j]!=' '; j++);
			s1=new char[20];
			strncpy(s1,s,j);
			s1[j]='\0';
			strcat (s1," ");
			strcat(s1,s2);
			delete[]s2;
			s2=new char[80];
			strcpy(s2,s1);
			strcpy(s,&s[j+1]);
			delete[]s1;
			}
		puts(s2);
		delete[]s2;
		delete[]s;
  getch();

	}
