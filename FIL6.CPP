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
	int n=0,k=0,i=0,j=0,k1=0,j1=1,n1=0,j2=0;
	char s[80];
	char s1[80];
	char s2[80];
	soz(f,"c:\\borlandc\\f.txt");
	if ((f=fopen("c:\\borlandc\\f.txt","r+t"))==0)
		{
		cout<<"OSHIBKA 1";
		return;
		}
	cout<<"\n";
	gets(s2);
	while (fgets(s,80,f))
		{
		n=strlen(s);
		s[n-1]='\0';


		for (i=0,k=0; s[i]!='\0'; i++)
			if (s[i]==' ') k++;
		for (i=0; i<=k; i++)
			{
			for(j=0; s[j]!=' '; j++);
			strncpy(s1,s,j);
			s1[j]='\0';
			n=strlen(s1);
			n1=strlen(s2);
			if (n1>n) n=n1;
			for(j2=0,k1=0; s2[j2]!=0; j2++)
				if (s1[j2]==s2[j2]) k1++;
				else break;
			if (k1==n) cout<<"Stroka : "<<j1<<" Slovo : "<<i+1<<'\n';
                        
			strcpy(s,&s[j+1]);
			}
		j1++;
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