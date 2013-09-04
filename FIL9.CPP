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
	int n=0,k=0,j,i,a[4],j1=0;
	char s[80];
	char s1[80];
	char min[1],m[1];
	soz(f,"c:\\borlandc\\f.txt");
	if ((f=fopen("c:\\borlandc\\f.txt","r+t"))==0)
		{
		cout<<"OSHIBKA 1";
		return;
		}
	cout<<'\n';
	while(fgets(s,80,f))
		k++;

	fclose(f);
	min[0]='|';
	m[0]='!';
	for(i=0; i<4; i++)
		a[i]=0;

	if ((f1=fopen("c:\\borlandc\\f1.txt","w+t"))==0)
			{
			cout<<"oshibka 1";
			return ;
			}

	for (i=0; i<k; i++)
		{
		if ((f=fopen("c:\\borlandc\\f.txt","r+t"))==0)
			{
			cout<<"OSHIBKA 1";
			return;
			}
		j1=0;
		while(fgets(s,80,f))
			{
			if (s[0]<min[0] && s[0]>=m[0] && a[j1]==0)
				{
				min[0]=s[0];
				strcpy(s1,s);
				j=j1;
				}

			j1++;
			}
		a[j]=1;
		m[0]=min[0];
		min[0]='|';
		fputs(s1,f1);
		fclose(f);
		}
	fclose(f1);

	if ((f1=fopen("c:\\borlandc\\f1.txt","r+t"))==0)
			{
			cout<<"oshibka 1";
			return ;
			}

	while(fgets(s,80,f1))
		{
		n=strlen(s);
		s[n-1]='\0';
		puts(s);
		}
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