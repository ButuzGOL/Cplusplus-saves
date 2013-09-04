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
void main()
	{
clrscr();

	puts(sum("10110","110"));

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

		for(i=0; i<strlen(s); i++)
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
		return ot;
		}