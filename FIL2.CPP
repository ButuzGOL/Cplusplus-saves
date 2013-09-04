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
	int n=0,k=0,i=0;
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
		k=0;
		i=0;
		while(s[i]!='\0')
			{
			if (isdigit(s[i])) k=1;
			i++;
			}
		if (k==0) n++;
		}
	fclose(f);
	cout<<"kol "<<n;
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