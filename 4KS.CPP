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
	int i,k=0,j=0,n,l,h;

		gets(s);
		strcat(s," (");
		for (i=0; s[i]!='\0'; i++)
			if (s[i]=='(') k++;


		strcpy(s2,"");
		for(i=0; i<k; i++)
			{
			for(j=0; s[j]!='('; j++);
			s1=new char[80];
			strncpy(s1,s,j);
			s1[j]='\0';

			strcat(s2,s1);
			delete[]s1;
			s1=new char[80];
			strcpy(s1,s2);
			delete[]s2;
			s2=new char[80];
			strcpy(s2,s1);

			for(j=0; s[j]!=')'; j++);
			strcpy(s,&s[j+2]);
			delete[]s1;
			}
		puts(s2);
		delete[]s2;
		delete[]s;








 getch();

	}
