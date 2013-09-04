#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <iomanip.h>
#include <fstream.h>
#include <string.h>
#include <graphics.h>
void soz(char*);
void poisk(char*,char*);
void zamena(char*,char*,char*);
void sortdlin(char*);
void vivod(char*);
void main()
	{
clrscr();
	char s[80],s1[80];
	int k=0;


		//soz("c:\\my.txt");
		//poisk("e:\\my.txt","gol");
		zamena("c:\\my.txt","gol","Bati_GOL");
		//sortdlin("e:\\my.txt");
		vivod("c:\\my.txt");
getch();
	}
void soz(char* sl)
	{
	char s[80];
	ofstream f;
	int i;

	f.open(sl,ios::out);
	if (!f) {cerr<<"Oshibka"; return;}

	for (i=0; i<4; i++)
		{
		gets(s);
		f.write(s,80);
		}
	f.close();
	}
void vivod(char* sl)
	{
	ifstream f;
	char s[80];

		f.open(sl);
		if (!f) {cerr<<"Oshibka"; return;}

		while (f.peek()!=EOF)
			{
			f.read(s,80);
			puts(s);
			}
	f.close();
	}
void poisk(char* sl,char* s1)
	{
	ifstream f;
	int l=0,i,k=0,j=0,l1,i1,n;
	char s[80],s2[80],s3[80],s4[80];

		f.open(sl);
		if (!f) {cerr<<"Oshibka"; return;}


		while (f.peek()!=EOF)
			{
			l++;
			f.read(s,80);
			puts(s);
			strcpy(s3,s);

			for (i=0,k=0; s3[i]!='\0'; i++)
				if (s3[i]==' ') k++;

			for (i=0; i<=k; i++)
				{
				for (j=0; s3[j]!=' '; j++);
				strncpy(s2,s3,j);
				s2[j]='\0';

				if (strcmp(s1,s2)==0)
					{
					cout<<"Nomer slova "<<i+1<<endl;
					cout<<"Nomer stroki "<<l<<endl;
					for (i1=0,l1=0; s[i1]!='\0'; i1++)
						{
						if (i==l1) break;
						if (s[i1]==' ') l1++;
						}
					strncpy(s4,s,i1);
					s4[i1]='\0';
					cprintf(s4);
					textcolor(10);
					cprintf(s1);
					n=strlen(s1);
					strcpy(s4,&s[i1+n]);
					textcolor(7);
					cprintf(s4);
					cout<<'\n';
					}
				strcpy(s3,&s3[j+1]);
				}
			}
		f.close();
	}
void zamena(char* sl,char* s1,char* s2)
	{
	ifstream f;
	int i,k=0,j=0,l1,i1,n,l=0;
	char s[80],s3[80],s4[80],s5[80],s6[80];

		f.open(sl,ios::out);
		if (!f) {cerr<<"Oshibka"; return;}

		while (f.peek()!=EOF)
			{
			l++;
			f.read(s,80);
			strcpy(s3,s);

			for (i=0,k=0; s3[i]!='\0'; i++)
				if (s3[i]==' ') k++;

			for (i=0; i<=k; i++)
				{
				for (j=0; s3[j]!=' '; j++);
				strncpy(s4,s3,j);
				s4[j]='\0';

				if (strcmp(s1,s4)==0)
					{
					cout<<"Nomer slova "<<i+1<<endl;
					cout<<"Nomer stroki "<<l<<endl;
					for (i1=0,l1=0; s[i1]!='\0'; i1++)
						{
						if (i==l1) break;
						if (s[i1]==' ') l1++;
						}
					strncpy(s5,s,i1);
					s5[i1]='\0';
					cprintf(s5);
					textcolor(12);
					cprintf(s2);
					n=strlen(s4);
					strcpy(s6,&s[i1+n]);
					textcolor(7);
					cprintf(s6);
					cout<<'\n';
					strcpy(s,s5);
					strcat(s,s2);
					strcat(s,s6);
					}
				strcpy(s3,&s3[j+1]);
				}
			n=strlen(s);
			for(i=0; i<n; i++)
				f.get(s[i]);
			}
		f.close();

	}
void sortdlin(char* sl)
	{
	ifstream f;
	int i;
	char s[80];

		f.open(sl);
		if (!f) {cerr<<"Oshibka"; return;}

		do
			{
			k=1;
			f.read(s,80)
			n=strlen(s);
			while(f.read(s1,80))
				{
				n=strlen(s1);
				if (n>n1)
					{
					seekp((-2)*sizeof(s),ios::cur);
					f.write(s1,80);
					f.write(s,80);
					k=0;
					}
				else
					strcpy(s,s1);
				}
			}
			while(!k);
		f.close();
	}