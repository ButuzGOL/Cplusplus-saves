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
void sortal(char*);
void vivod(char*);
void main()
	{
clrscr();
	char s[80],s1[80];


		//soz("e:\\my.txt");
		//poisk("e:\\my.txt","gol");
		//zamena("e:\\my.txt","gol","Bati_GOL");
		//sortdlin("e:\\my.txt");
		//sortal("e:\\my.txt");
		vivod("e:\\my.txt");
getch();
	}
void soz(char* sl)
	{
	char s[80];
	ofstream f;
	int i;

	f.open(sl,ios::in);
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
	int l=0,i,k=0,j=0,l1,i1,n,j1=0,n1;
	char s[80],s2[80],s3[80],s4[80];

		f.open(sl);
		if (!f) {cerr<<"Oshibka"; return;}

		n=strlen(s1);
		while (f.peek()!=EOF)
			{
			j1=0;
			l++;
			f.read(s,80);
			strcpy(s3,s);
			puts(s);

			for (i=0,k=0; s3[i]!='\0'; i++)
				if (s3[i]==s1[0]) k++;

			for (i=0; i<k ; i++)
				{
				for (j=0; s3[j]!=s1[0]; j++);

				j1+=j;
				strcpy(s3,&s3[j]);
				strncpy(s2,s3,n);
				s2[n]='\0';

				if (strcmp(s1,s2)==0)
					{
					cout<<"Nomer poz "<<j1+1<<endl;
					cout<<"Nomer stroki "<<l<<endl;
					strncpy(s4,s,j1);
					s4[j1]='\0';
					cprintf(s4);
					textcolor(10);
					cprintf(s1);
					strcpy(s4,&s[j1+n]);
					textcolor(7);
					cprintf(s4);
					cout<<'\n';
					}
				strcpy(s3,&s3[1]);
				j1++;
				}
			}
		f.close();
	}
void zamena(char* sl,char* s1,char* s2)
	{
	fstream f;
	int i,k=0,j=0,l1,i1,n,l=0,j1,n1;
	char s[80],s3[80],s4[80],s5[80],s6[80];

		f.open(sl,ios::in|ios::out);
		if (!f) {cerr<<"Oshibka"; return;}


		n=strlen(s1);
		while (f.peek()!=EOF)
			{
			j1=0;
			f.read(s,80);
			//puts(s);
			strcpy(s3,s);
			for (i=0,k=0; s3[i]!='\0'; i++)
				if (s3[i]==s1[0]) k++;

			for (i=0; i<k; i++)
				{
				for (j=0; s3[j]!=s1[0]; j++);

				j1+=j;
				strcpy(s3,&s3[j]);
				strncpy(s4,s3,n);
				s4[n]='\0';

				if (strcmp(s1,s4)==0)
					{
					cout<<"Nomer poz "<<j1+1<<endl;
					cout<<"Nomer stroki "<<l<<endl;
					strncpy(s5,s,j1);
					s5[j1]='\0';
					cprintf(s5);
					textcolor(12);
					cprintf(s2);
					n1=strlen(s4);
					strcpy(s6,&s[j1+n]);
					textcolor(7);
					cprintf(s6);
					cout<<'\n';
					strcpy(s,s5);
					strcat(s,s2);
					strcat(s,s6);
					n1=strlen(s2);
					if (n1>n) j1+=(n1-n);
					if (n1<n) j1-=(n-n1);
					}
				strcpy(s3,&s3[1]);
				j1++;
				}
			f.seekp(l*80,ios::beg);
			f.write(s,80);
			l++;
			}
		f.close();
		}
void sortdlin(char* sl)
	{
	fstream f;
	int k;
	char s[80],s1[80];

		f.open(sl,ios::in|ios::out);
		if (!f) {cerr<<"Oshibka"; return;}

		do
			{
			k=1;
			f.seekp(0,ios::beg);
			f.read(s,80);
			while(f.peek()!=EOF)
				{
				f.read(s1,80);
				if (strlen(s)>strlen(s1))
					{
					k=0;
					f.seekp(-2*80,ios::cur);
					f.write(s1,80);
					f.write(s,80);
					}
				else strcpy(s,s1);
				}
			}
		while(!k);

		f.close();
	}
void sortal(char* sl)
	{
	fstream f;
	int k;
	char s[80],s1[80];

		f.open(sl,ios::in|ios::out);
		if (!f) {cerr<<"Oshibka"; return;}

		do
			{
			k=1;
			f.seekp(0,ios::beg);
			f.read(s,80);
			while(f.peek()!=EOF)
				{
				f.read(s1,80);
				if (strcmp(s,s1)>0)
					{
					k=0;
					f.seekp(-2*80,ios::cur);
					f.write(s1,80);
					f.write(s,80);
					}
				else strcpy(s,s1);
				}
			}
		while(!k);

		f.close();
	}