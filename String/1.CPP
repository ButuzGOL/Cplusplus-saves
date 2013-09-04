#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

void main()
	{
  clrscr();

	char *s1=new char[10];
	char *s=new char[80];
	int i,k=0,j=0;

		gets(s);
		for (i=0; s[i]!='\0'; i++)
			if (s[i]==' ') k++;

		strcat(s," ");
		for(i=0; i<=k; i++)
			{
			for(j=0; s[j]!=' '; j++);
			strncpy(s1,s,j);
			s1[j]='\0';
			puts(s1);
			strcpy(s,&s[j+1]);
			}
  getch();
	}
