#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

void main()
	{
  clrscr();

	char *s1=new char[10];
	char *s2=new char[10];
	char *s3=new char[10];
	char *s4=new char[20];
	char *s=new char[30];
	int i,n,k=0;

		s="FOG Slavenii Oleg";
		puts(s);
		for (i=0; s[i]!=' '; i++);
		strncpy(s1,s,i);
		s1[i]='\0';
		puts(s1);
		for (i=i+1; s[i]!=' '; i++);
		strncpy(s4,s,i);
		s4[i]='\0';
                s2=strchr(s4,' ');
		s2+=1;
		puts(s2);
		for (i=30; s[i]!=' '; i--);
		s=s+(i+1);
		strcpy(s3,s);
		puts(s3);
  getch();
	}
