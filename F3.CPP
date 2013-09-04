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
		k=0;i=0;
		while(s[i]!='\0')
			{
			if (s[i]=='a') k++;
			i++;
			}
		if (k==2)
			{
			n=strlen(s);
			s[n-1]='\0';
			puts(s);
			}
		}

	fclose(f);

  getch();
	}
