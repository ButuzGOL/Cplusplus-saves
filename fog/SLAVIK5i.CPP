#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <iomanip.h>
#include <fstream.h>
#include <string.h>
char* sum(char*,char*);
char* raz(char*,char*);
void main()
	{
clrscr();

	puts(sum("10110","110"));
	cout<<"Raz";
	puts(raz("10100100","101101"));

getch();
	}
char* sum(char s[40],char s1[40])
	{
	int n,n1,i,j,k;
	char so[40],ot[40],ot1[40],s2[40];

		strcpy(s2,"");
		strcpy(ot1,"");
		strcpy(ot,"");
		n=strlen(s);
		n1=strlen(s1);

		if (n>n1)
			{
			for(i=0; i<n-n1; i++)
				strcat(s2,"0");
			strcat(s2,s1);
			strcpy(s1,s2);
			}
		if (n<n1)
			{
			for(i=0; i<n1-n; i++)
				strcat(s2,"0");
			strcat(s2,s);
			strcpy(s,s2);
			}

		n=strlen(s);
		for(i=0; i<n; i++)
			{
			strcpy(so,ot1);
			strcpy(ot1,"");
			strcat(so,&s[strlen(s)-1]);
			strcat(so,&s1[strlen(s1)-1]);

			for(j=0,k=0; j<strlen(so); j++)
				if (so[j]=='1') k++;

			if (k==0) strcat(ot,"0");
			if (k==1) strcat(ot,"1");
			if (k==2) {strcat(ot,"0"); strcat(ot1,"1");}
			if (k==3) {strcat(ot,"1"); strcat(ot1,"1");}

			s[strlen(s)-1]='\0';
			s1[strlen(s1)-1]='\0';
			}
		strcpy(so,"");
		j=strlen(ot);
		j--;
		for (i=0; i<strlen(ot); i++)
			{
			so[i]=ot[j];
			so[i+1]='\0';
			j--;
			}
		strcpy(ot,so);

		return ot;
	}
char* raz(char s[40],char s1[40])
	{
	int n,n1,i,j,k,j1;
	char so[40],ot[40],ot1[40],s2[40];

		strcpy(s2,"");
		strcpy(ot1,"");
		strcpy(ot,"");

		n=strlen(s);
		n1=strlen(s1);

		if (n>n1)
			{
			for(i=0; i<n-n1; i++)
				strcat(s2,"0");
			strcat(s2,s1);
			strcpy(s1,s2);
			}

		n=strlen(s);
		for(i=0; i<n; i++)
			{
			strcpy(so,"");
			strcat(so,&s[strlen(s)-1]);
			strcat(so,&s1[strlen(s1)-1]);

			if (strcmp(so,"00")==0) strcat(ot,"0");
			if (strcmp(so,"11")==0) strcat(ot,"0");
			if (strcmp(so,"10")==0) strcat(ot,"1");
			if (strcmp(so,"01")==0)
				{
				strcat(ot,"1");
				j=strlen(s);
				j--;
				while(s[j]!='1')
					{s[j]='1'; j--;}
				}
				s[j]='0';
			s[strlen(s)-1]='\0';
			s1[strlen(s1)-1]='\0';
			}

		strcpy(so,"");
		j=strlen(ot);
		j--;
		for (i=0; i<strlen(ot); i++)
			{
			so[i]=ot[j];
			so[i+1]='\0';
			j--;
			}
		strcpy(ot,so);
		return ot;

	}