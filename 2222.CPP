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
char* raz(char*,char*);
void main()
	{
clrscr();
	char s[40],s1[40],s2[40],s3[40],s4[40],s5[40],s6[40];
	int x,y;

		strcpy(s4,"1");
		strcpy(s5,"1");
		strcpy(s6,"1");

		cout<<"Vvedite chislo1 <=64  ";
		gets(s);

		cout<<"Vvedite chislo2 <=64  ";
		gets(s2);

		cout<<"Vvedite znak +/-  ";
		gets(s3);


		if (s3[0]=='+' && s[0]!='-' && s2[0]!='-')
			{
			strcpy(s1,preo(s));
			strcpy(s,preo(s2));
			puts(sum(s1,s));
			}

		x=atoi(&s[1]);
		if (s3[0]=='+') y=atoi(s2);
		else y=atoi(&s2[1]);
		if ((s3[0]=='+' && s[0]=='-' && s2[0]!='-')||(s3[0]=='-' && s[0]=='-' && s2[0]=='-'))
			{
			strcpy(s1,preo(s));
			if (s3[0]=='-')	strcpy(s,preo(&s2[1]));
			else strcpy(s,preo(s2));
			strcpy(s1,obr(s1));
			strcpy(s1,sum(s1,"1"));
			strcpy(s3,sum(s1,s));
			if (x>y)
				{
				strcpy(s3,raz(s3,s4));
				strcpy(s,obr(s3));
				puts(s3);
				}
			else puts(s3);

			}

		x=atoi(s); y=atoi(&s2[1]);
		if (s3[0]=='+' && s[0]!='-' && s2[0]=='-')
			{
			strcpy(s1,preo(s2));
			strcpy(s2,preo(s));
			strcpy(s1,obr(s1));
			strcpy(s1,sum(s1,"1"));
			strcpy(s3,sum(s1,s2));

			if (x<y)
				{
				strcpy(s3,raz(s3,s6));
				strcpy(s3,obr(s3));
				puts(s3);
				}
			else
				puts(s3);
			}

		if (s3[0]=='+' && s[0]=='-' && s2[0]=='-')
			{
			strcpy(s1,preo(s));
			strcpy(s1,obr(s1));
			strcpy(s1,sum(s1,"1"));
			strcpy(s,"");
			strcpy(s,preo(s2));
			strcpy(s2,obr(s));
			strcpy(s2,sum(s2,s4));
			strcpy(s3,sum(s1,s2));
			strcpy(s2,raz(s3,s5));
			strcpy(s3,obr(s2));
			puts(s3);
			}



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
	for (int i=1; i<strlen(s); i++)
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
char* raz(char sl[40],char sl1[40])
	{
	int n,n1,i,j,k,j1;
	char so[40],ot[40],ot1[40],s2[40];
		strcpy(s2,"");
		strcpy(ot1,"");
		strcpy(ot,"");

		n=strlen(sl);
		n1=strlen(sl1);

		if (n>n1)
			{
			for(i=0; i<n-n1; i++)
				strcat(s2,"0");
			strcat(s2,sl1);
			strcpy(sl1,s2);
			}

		n=strlen(sl);
		for(i=0; i<n; i++)
			{
			strcpy(so,"");
			strcat(so,&sl[strlen(sl)-1]);
			strcat(so,&sl1[strlen(sl1)-1]);
			if (strcmp(so,"00")==0) strcat(ot,"0");
			if (strcmp(so,"11")==0) strcat(ot,"0");
			if (strcmp(so,"10")==0) strcat(ot,"1");
			if (strcmp(so,"01")==0)
				{
				strcat(ot,"1");
				j=strlen(sl);
				j--;
				while(sl[j]!='1')
					{sl[j]='1'; j--;}
				}
				sl[j]='0';
			sl[strlen(sl)-1]='\0';
			sl1[strlen(sl1)-1]='\0';
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
