#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
void soz(FILE*,char*);
void main()
	{
  clrscr();
	FILE *f;
	int n,k=0,i;
	char s[80];
	soz(f,"c:\\borlandc\\f.txt");
	if ((f=fopen("c:\\borlandc\\f.txt","r+t"))==0)
		{
		cout<<"OSHIBKA 1";
		return;
		}
	cout<<"\n";
	while (fgets(s,80,f))
		{
		n=strlen(s);
		s[n-1]='\0';
		puts(s);
		}


	fclose(f);

  getch();
	}
void soz(FILE*f, char*s)
	{
	char s1[80];
	if ((f=fopen(s,"w+t"))==0)
		{
		cout<<"OSHIBKA 1";
		return;
		}
	for (int i=0; i<4; i++)
		{
		gets(s1);
		fputs(s1,f);
		fputs("\n",f);
		}
	fclose(f);
	}