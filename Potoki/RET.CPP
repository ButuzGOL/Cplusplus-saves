#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <iomanip.h>
#include <fstream.h>
#include <string.h>
void soz(char*);
void poisk(char*,char*);
void main()
	{
clrscr();
	char s[80],s1[80];
	int k=0;


		soz("e:\\my.txt");
		gets(s1);
		poisk("e:\\my.txt",s1);


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
void poisk(char* sl,char* s1)
	{
	ifstream f;
	int l=0,i,k=0,j=0,l1,i1;
	char s[80],s2[80],s3[80],s4[80];

		f.open("e:\\my.txt");
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
					cout<<"Nomer slova "<<i<<endl;
					cout<<"Nomer stroki "<<l<<endl;
					for (i1=0,l1=0; s[i1]!='\0'; i1++)
						{
						if (i==l1) break;
						if (s3[i]==' ') l1++;
						}
					strcmp(s4,s,i1);
					s4[i1]=='\0';
					cprintf(s4);
					cprintf(s1);

					}
				strcpy(s3,&s3[j+1]);
				}
			}
		f.close();
	}