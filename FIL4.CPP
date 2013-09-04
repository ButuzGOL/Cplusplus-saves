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
	FILE *f,*f1;
	int n=0,k=0,i=0,j=0,k1=0,n1=0;
	char s[80];
	char s1[80];
	if ((f=fopen("c:\\borlandc\\f.txt","r+t"))==0)
		{
		cout<<"OSHIBKA 1";
		return;
		}
	if ((f1=fopen("c:\\borlandc\\f1.txt","r+t"))==0)
		{
		cout<<"OSHIBKA 1";
		return;
		}
	j=0;
	k1=0;
	while (fgets(s,80,f)&&fgets(s1,80,f1))
		{
		n=strlen(s);
		n1=strlen(s1);
		if (n1>n) n=n1;
		for(i=0,k=0; s[i]!='\0'; i++)
			if (s[i]==s1[i]) k++;
			else break;
		if (k==n) k1++;
		j++;
		}
	if (k1==j) cout<<"YES";
	else cout<<"NO";
  fclose(f);
  fclose(f1);
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