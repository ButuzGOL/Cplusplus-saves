#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
void soz(FILE*,char*);
void red(FILE*,char*);
void main()
	{
  clrscr();
	FILE *f;
	soz(f,"c:\\borlandc\\f.txt");
	red (f,"c:\\borlandc\\f.txt");
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
void red(FILE*f, char*s)
	{
	int n=0,k=0,k1=0,i=0,j=0,max=-1,k2=0,j1=0,n1=0,j2=0,k3=0,k4=0,j5=0,j4=0,j3=0;
	FILE*f1;
	char s1[80];
	char s2[80];
	char s3[80];
	if ((f=fopen(s,"r+t"))==0)
		{
		cout<<"OSHIBKA 2";
		return;
		}

	if ((f1=fopen("c:\\borlandc\\f1.txt","w+t"))==0)
		{
		cout<<"OSHIBKA 2";
		return;
		}

	while (fgets(s,80,f))
		fputs(s,f1);

	fclose(f1);
	fclose(f);
	if ((f=fopen("c:\\borlandc\\f.txt","r+t"))==0)
		{
		cout<<"OSHIBKA 2";
		return;
		}
	while (fgets(s,80,f))
		{
		for(j=0,k3=0; s[j]!='\0'; j++)
			if (s[j]==' ') k3++;
		n=strlen(s);
		s[n-1]=' ';
		for(j2=0; j2<=k3; j2++)
			{
			for(j=0; s[j]!=' '; j++);
			strncpy(s1,s,j);
			s1[j]='\0';
			strcpy(s,&s[j+1]);
			k2=-1;
			//puts(s1);
			if ((f1=fopen("c:\\borlandc\\f1.txt","r+t"))==0)
				{
				cout<<"OSHIBKA 2";
				return;
				}
			while(fgets(s3,80,f1))
				{
				for(j4=0,k4=0; s3[j4]!='\0'; j4++)
					if (s3[j4]==' ') k4++;
				n=strlen(s3);
				s3[n-1]=' ';
				for(j5=0; j5<=k4; j5++)
					{
					for(j1=0; s3[j1]!=' '; j1++);
					strncpy(s2,s3,j1);
					s2[j1]='\0';
					//puts(s2);
					n=strlen(s2);
					n1=strlen(s1);
					if (n<n1) n=n1;
					for(j3=0,k=0; j3<n; j3++)
						if (s2[j3]==s1[j3]) k++;
						else break;
					if (k==n) k2++;
					strcpy(s3,&s3[j1+1]);
					}
				}
			if (k2==0) puts(s1);
			}
			fclose(f1);
		}
	fclose(f);
	}                                  