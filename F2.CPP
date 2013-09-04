#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>

void main()
	{
  clrscr();
	FILE *f;
	int n,k=0;
	char s[80];
	if ((f=fopen("c:\\borlandc\\f.txt","w+t"))==0)
		{
		cout<<"OSHIBKA 1";
		return;
		}
	for (int i=0; i<4; i++)
		{
		gets(s);
		fputs(s,f);
		fputs("\n",f);
		}
	fclose(f);
	if ((f=fopen("c:\\borlandc\\f.txt","r+t"))==0)
		{
		cout<<"OSHIBKA 1";
		return;
		}
	cout<<"\n";
	while (fgets(s,80,f))
		{
		n=strlen(s);
		if (s[0]==s[n-2]) k++;
		}
	cout<<k;
	fclose(f);

  getch();
	}
