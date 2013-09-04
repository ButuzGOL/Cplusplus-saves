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
char so[80];
int cp=0;
void copyf(char*,char*,char*);
void copyp(char*,char*,char*);
void deletef(char*,char*);
void deletep(char*,char*);
void main()
	{
clrscr();
	int x,i;
	FILE* f,*f1;
	char s[80],s1[80],s2[80];


	      //copyf("e:\\P1\\","e:\P2\\","F1.txt");
	      strcpy(so,"c:\\");
	      copyp("c:\\A1\\","c:\\borlandc\\A1\\","B1");

	      //deletef("e:\\P1\\","F1.txt");
	      //strcpy(so,"c:\\borlandc\\");
	      //deletep("c:\\borlandc\\A1\\","B1");


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
	int x,k=0,k1=0,i,j,x1;
	char s1[80],s2[80],s3[80],s4[80],s5[80],sp[80];

	       cout<<"1a  ";
		strcpy(s1,s);
		strcat(s1,sss);
	       puts(s1);

	       cout<<"2a  ";
		strcpy(s2,ss);
		strcat(s2,sss);
	       puts(s2);

		x=mkdir(s2);

		strcpy(s3,s1);
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
				strcpy(sp,s1);
				copyf(sp,s2,full.ff_name);
				x=findnext(&full);
				}
			}

		strcpy(s1,s);
		strcat(s1,sss);
		strcpy(s2,ss);
		strcat(s2,sss);
		strcpy(s4,s1);
		strcat(s4,"\\*.");
		struct ffblk full1;
		x=findfirst(s4,&full1,0x10);
		while (!x)
			{
			x=findnext(&full1);
			k++;
			}
		if (k>2)
			{
			strcat(s1,"\\");
			strcat(s2,"\\");
			struct ffblk full1;
			x=findfirst(s4,&full1,0x10);
			while (!x)
				{
				if (full1.ff_name[0]!='.')
					{
					strcpy(s3,s2);
					strcat(s3,full1.ff_name);
					if (cp==1) return;
					x1=mkdir(s3);
					cout<<"3  s3  ";
					puts(s3);
					getch();
					if (x1==0)
						{
						x1=rmdir(s3);
						k1=1;
						cout<<"OtKuda  ";
						puts(s1);
						cout<<"Kuda  ";
						puts(s2);
						copyp(s1,s2,full1.ff_name);
						}
					}
				x=findnext(&full1);
				}
			}
		if (k<3 || k1==0)
			{
			k=0;
			strcpy(s1,"");
			strcpy(s2,"");
			for (i=0; s[i]!='\0'; i++)
				if (s[i]=='\\') k++;
			k--;
			for (i=0; i<k; i++)
				{
				for (j=0; s[j]!='\\'; j++);
				strncpy(s1,s,j+1);
				s1[j+1]='\0';
				strcat(s2,s1);
				strcpy(s,&s[j+1]);
				}
			for(i=0; s[i]!='\\'; i++);
			s[i]='\0';

			k=0;
			strcpy(s1,"");
			strcpy(s5,"");
			for (i=0; ss[i]!='\0'; i++)
				if (ss[i]=='\\') k++;
			k--;
			for (i=0; i<k; i++)
				{
				for (j=0; ss[j]!='\\'; j++);
				strncpy(s1,ss,j+1);
				s1[j+1]='\0';
				strcat(s5,s1);
				strcpy(ss,&ss[j+1]);
				}
			if (strcmp(so,s2)==0) {cp=1; return;}
			puts(s2);
			cout<<"5  ";
			puts(s5);
			getch();
			copyp(s2,s5,s);
			}
	}
void deletef(char *s,char *sss)
	{
	char s1[80];

		strcpy(s1,s);
		strcat(s1,sss);
		unlink(s1);
	}
void deletep(char *s,char *sss)
	{
	char s1[80],s3[80],s4[80],s2[80];
	int x,k=0,k1=0,i,j;

		strcpy(s1,s);
		strcat(s1,sss);
		strcpy(s3,s1);
		strcat(s3,"\\*.*");
		struct ffblk full;
		x=findfirst(s3,&full,0);
		if (x==0)
			{
			strcat(s1,"\\");
			struct ffblk full;
			x=findfirst(s3,&full,0);
			while (!x)
				{
				deletef(s1,full.ff_name);
				x=findnext(&full);
				}
			}
		strcpy(s1,s);
		strcat(s1,sss);
		strcpy(s4,s1);
		strcat(s4,"\\*.");
		struct ffblk full1;
		x=findfirst(s4,&full1,0x10);
		while (!x)
			{
			x=findnext(&full1);
			k++;
			}
		if (k>2)
			{
			strcat(s1,"\\");
			struct ffblk full1;
			x=findfirst(s4,&full1,0x10);
			while (!x)
				{
				if (full1.ff_name[0]!='.')
					{
					cout<<"1  "<<endl;
					puts(s1);
					getch();
					deletep(s1,full1.ff_name);
					}
				x=findnext(&full1);
				}
			}

		else
			{
			strcpy(s1,s);
			strcat(s1,sss);
			x=rmdir(s1);
			cout<<"Rem "<<endl;
			puts(s1);
			strcpy(s1,s);
			strcpy(s4,s1);
			strcat(s4,"*.");
			struct ffblk full1;
			x=findfirst(s4,&full1,0x10);
			k=0;
			while (!x)
				{
				x=findnext(&full1);
				k++;
				}
			if (k>2)
				{
				return;
				cout<<"Sdelan vozvrat"<<endl;
				}
			else
				{
				k=0;
				strcpy(s1,"");
				strcpy(s2,"");
				for (i=0; s[i]!='\0'; i++)
					if (s[i]=='\\') k++;
				k--;
				for (i=0; i<k; i++)
					{
					for (j=0; s[j]!='\\'; j++);
					strncpy(s1,s,j+1);
					s1[j+1]='\0';
					strcat(s2,s1);
					strcpy(s,&s[j+1]);
					}
				for(i=0; s[i]!='\\'; i++);
				s[i]='\0';
				cout<<"2  "<<endl;
				puts(s2);
				getch();
				if (strcmp(so,s2)==0) return;
				deletep(s2,s);
				}
			}
	}



