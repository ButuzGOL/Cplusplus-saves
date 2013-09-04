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
	int n=0,k=0,i=0,j=0,n1=0;
	char s[80];
	char s1[80];
	soz(f,"c:\\borlandc\\f.txt");
	if ((f=fopen("c:\\borlandc\\f.txt","r+t"))==0)
		{
		cout<<"OSHIBKA 1";
		return;
		}
	cout<<"\n";
        gets(s1);
        j=1;
	while (fgets(s,80,f))
		{
		n=strlen(s);
		s[n-1]='\0';
		n1=strlen(s1);
                if (n1>n) n=n1;
		for (i=0,k=0; s1[i]!='\0'; i++)
			if (s[i]==s1[i]) k++;
                        else break;
                k++;
		if (k==n) cout<<"Sovpalo "<<j<<'\n';
		j++;
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