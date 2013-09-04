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
	int n;
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
		if (isupper(s[0])!=0)
			{
			n=strlen(s);
			s[n-1]='\0';
			puts(s);
			}

	fclose(f);

  getch();
	}
