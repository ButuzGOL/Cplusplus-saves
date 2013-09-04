#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <iomanip.h>
#include <fstream.h>
#include <string.h>
char* prov(char*,int);
float preo(char*,int);
int bukvi(char);
void main()
	{
clrscr();
	char s[40];
	int o;

		cout<<"Vvedite osnovanie ";
		cin>>o;
		cout<<"Vvedite chislo ";
		gets(s);
		puts(prov(s,o));
		if (strcmp(prov(s,o),"vse pravelno")==0)
			cout<<preo(s,o);

getch();
	}
float preo(char*s,int y)
	{
	char s1[40],s2[40],s3[40],s4[40],s5[40],s6[40],s7[40];
	int i=0,l=0,x,x1=0;
	float x2=0,x3;
		strcpy(s5,"");
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
			}
		else {strcpy(s1,s);}

		strcpy(s3,s1);
		for (i=strlen(s1)-1; i!=-1; i--)
			{
			if (s3[0]>='A' && s3[0]<='F') x=bukvi(s3[0]);
			else {strncpy(s4,s3,1); s4[1]='\0'; x=atoi(s4);}
			x1+=(x*pow(y,i));
			strcpy(s3,&s3[1]);
			}
		if (l==1)
			{
			strcpy(s3,s2);
			for (i=1; i<=strlen(s2); i++)
				{
				if (s3[0]>='A' && s3[0]<='F') x=bukvi(s3[0]);
				else {strncpy(s4,s3,1); s4[1]='\0'; x=atoi(s4);}
				x2+=(x*pow(y,(i*-1)));
				strcpy(s3,&s3[1]);
				}

			}
		return x1+x2;
	}
int bukvi(char x)
	{
	switch (x)
		{
		case 'A':return 10;
		case 'B':return 11;
		case 'C':return 12;
		case 'D':return 13;
		case 'E':return 14;
		case 'F':return 15;
		}
	}
char* prov(char s[40],int o)
	{
	int x=0,x1=0;
	for(int i=0; s[i]!='\0'; i++)
		if (!(s[i]>='0' && s[i]<='9') || !(s[i]>'A' && s[i]<'F')) x=1;

	if (o>16) x1=1;
	if (x==1 && x1==0) return "Nepravelnii znak";
	if (x==1 && x1==1) return "Nepravelnii znak ++ max 16";
	if (x==0 && x1==1) return "max 16";
	return "vse pravelno";
	}
