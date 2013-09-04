#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <iomanip.h>
#include <fstream.h>
#include <string.h>
char* preo(char*);
char* obr(char*);
char* sum(char*,char*);
void main()
	{
clrscr();
	char s[40],s1[40],s2[40];

		cout<<"Vvedite chislo <=64  ";
		gets(s);
		strcpy(s2,preo(s));


		cout<<"Pramoi ";
		puts(s2);

		cout<<"Obrat  ";
		strcpy(s1,obr(preo(s)));

		if (s2[0]=='0') puts(s2);
		if (s2[0]=='1') puts(s1);

		cout<<"Dopal  ";
		if (s2[0]=='0') puts(s2);
		if (s2[0]=='1') puts(sum(s1,"1"));


getch();
	}
char* preo(char s[40])
	{
	char s1[40],s2[40],s4[40],s5[40];
	int i=0,x,y,z,z1,z2,l=0;
	float x1,x2;

		strcpy(s5,"");

		if (s[0]=='-') {l=1; strcpy(s,&s[1]);}
		x=atoi(s);
		y=2;

		if (y>x)
			{
			itoa(x,s4,10);
			strcpy(s5,"");
			for (i=0; i<8-strlen(s4); i++)
				strcat(s5,"0");
			if (l==1) s5[0]='1';
			strcat(s5,s4);
			return s5;
			}
		z=x;
		while(y<=z)
			{
			strcpy(s4,"");
			z1=z/y;
			z2=z-z1*y;
			itoa(z2,s4,10);
			strcat(s4,s5);
			strcpy(s5,s4);
			z=z1;
			}
		itoa(z,s4,10);
		strcat(s4,s5);

		strcpy(s5,"");
		for (i=0; i<8-strlen(s4); i++)
			strcat(s5,"0");

		if (l==1) s5[0]='1';

		strcat(s5,s4);
		return(s5);
	}
char* obr(char s[40])
	{
	for (int i=0; i<strlen(s); i++)
		if (s[i]=='1') s[i]='0';
		else s[i]='1';
	return(s);
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







