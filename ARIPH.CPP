#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <iomanip.h>
#include <fstream.h>
#include <string.h>
char* prov(char*,char*);
char* preo(char*,char*);
char* bukvi(int);
void main()
	{
clrscr();
	char s[40],c[40];


		cout<<"Vvedite chislo ";
		gets(s);
		cout<<"Vvedite sistemu ";
		gets(c);
		puts(prov(s,c));
		if (strcmp(prov(s,c),"vse pravelno")==0) puts(preo(s,c));

getch();
	}
char* preo(char s[40],char c[40])
	{
	char s1[40],s2[40],s3[40],s4[40],s5[40],s6[40];
	int i=0,l=0,x,y,z,z1,z2;
	float x1,x2;

		strcpy(s5,"");
		strcpy(s6,"");
		while(s[i]!='\0')
			{
			if (s[i]=='.') l=1;
			i++;
			}

		if (l==1)
			{
			for(i=0; s[i]!='.'; i++);
			strncpy(s1,s,i);
			s1[i]='\0';
			strcpy(s2,&s[i+1]);
			x=atoi(s1);
			x1=atoi(s2);
			}
		else {strcpy(s1,s); x=atoi(s1);}
		y=atoi(c);

		if (y>x && l!=1) {itoa(x,s3,10); return s3;}
		z=x;
		while(y<=z)
			{
			strcpy(s4,"");
			z1=z/y;
			z2=z-z1*y;
			if (z2>9) strcpy(s4,bukvi(z2));
			else itoa(z2,s4,10);
			strcat(s4,s5);
			strcpy(s5,s4);
			z=z1;
			}
			itoa(z,s4,10);
			strcat(s4,s5);

		if (l==1)
			{
			x1=x1/pow(10,strlen(s2));
			for(i=0; i<3; i++)
				{
				x2=x1*y;
				if (x2>1)
					{
					itoa(x2,s5,10);
					x1=x2-atoi(s5);
					if (atoi(s5)>9) strcpy(s5,bukvi(atoi(s5)));
					strcat(s6,s5);
					}
				else strcat(s6,"0");
				}
			strcat(s4,".");
			strcat(s4,s6);
			return(s4);
			}
		return(s4);
	}
char* bukvi(int x)
	{
	switch (x)
		{
		case 10:return "A";
		case 11:return "B";
		case 12:return "C";
		case 13:return "D";
		case 14:return "E";
		case 15:return "F";
		}
	}
char* prov(char s[40],char c[40])
	{
	int x=0,x1=0;
	for(int i=0; s[i]!='\0'; i++)
		if (s[i]<'0'|| s[i]>'9') x=1;
	if (c[0]=='1' && c[1]>'6') x1=1;
	if (c[0]>'1'&& c[1]!='\0') x1=1;
	if (x==1 && x1==0) return "Nepravelnii znak";
	if (x==1 && x1==1) return "Nepravelnii znak ++ max 16";
	if (x==0 && x1==1) return "max 16";
	return "vse pravelno";
	}












