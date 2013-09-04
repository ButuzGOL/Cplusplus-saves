#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <iomanip.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <dos.h>
#include <dir.h>
void copyf(char*,char*,char*);
void copyp(char*,char*,char*);
void main()
	{
clrscr();
	int x,i;
	FILE* f,*f1;
	char s[80],s1[80],s2[80];


		x=mkdir("c:\\borlandc\\P1");
		x=mkdir("c:\\borlandc\\P2");
	      //copyf("c:\\borlandc\\P1\\","c:\\borlandc\\P2\\","F1.txt");
		copyp("c:\\borlandc\\P1\\","c:\\borlandc\\P2\\","F1");

getch();
	}
void copyf(char *s,char *ss,char *sss)
	{
	char s1[80],s2[80];
	FILE *f,*f1;

		strcpy(s1,s);
		strcpy(s2,ss);
		strcat(s1,sss);
		if ((f=fopen(s1,"r+t"))==0)
			{
			cout<<"Oshibka1";
			return;
			}
		strcat(s2,sss);
		if ((f1=fopen(s2,"w+t"))==0)
			{
			cout<<"Oshibka2";
			return;
			}
		while (fgets(s,80,f))
			fputs(s,f1);
		fclose(f);
		fclose(f1);
	}
void copyp(char *s,char *ss,char *sss)
	{
	int x,k=0;
	char s1[80],s2[80],s3[80],sp[80],s4[80];

		strcpy(s2,s);
		strcat(s2,sss);
		strcpy(s1,ss);
		strcat(s1,sss);
		x=mkdir(s1);
		strcpy(s4,s2);
		strcat(s4,"\\*.");
		struct ffblk full1;
		x=findfirst(s4,&full1,0x10);
		if (x==0)
			{
			strcat(s1,"\\");
			strcat(s2,"\\");
			struct ffblk full1;
			x=findfirst(s4,&full1,0x10);
			while (!x)
				{
				k++;
				if (k>=3)
					{
					strcpy(sp,s2);
					copyp(sp,s1,full1.ff_name);
					x=findnext(&full1);
					}
				}
			}
		else return;
		strcpy(s3,s2);
		strcat(s3,"\\*.*");
		struct ffblk full;
		x=findfirst(s3,&full,0);
		if (x==0)
			{
			strcat(s1,"\\");
			strcat(s2,"\\");
			struct ffblk full;
			x=findfirst(s3,&full,0);
			while (!x)
				{
				strcpy(sp,s2);
				copyf(sp,s1,full.ff_name);
				x=findnext(&full);
				}
			}

	}



