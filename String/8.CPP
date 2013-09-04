#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

void main()


	{
  clrscr();

	char *s1=new char[80];
	char *so=new char[1];
	char *s=new char[80];
	char *s2=new char[80];
	char *s3=new char[80];
	char *s4=new char[80];
	char *s5=new char[80];
	int i,k=0,j=0,n,l,h;

		gets(s);
		for (i=0; s[i]!='\0'; i++)
			if (s[i]==' ') k++;


		so="";
		strcat(s," ");
		strcpy(s2,so);
		strcpy(s4,s);
		for(i=0; i<=k; i++)
			{
			for(j=0; s[j]!=' '; j++);
			s1=new char[80];
			strncpy(s1,s,j+1);
			s1[j+1]='\0';

			n=0;
			strcpy(s3,s4);
			for(l=0; l<=k; l++)
				{
				for(h=0; s3[h]!=' '; h++);
				strncpy(s5,s3,h+1);
				s5[h+1]='\0';
				strcpy(s3,&s3[h+1]);
				h=strcmp(s1,s5);
				if (h==0) n++;
				}

			if (n==1)
				{
				strcat(s2,s1);
				delete[]s1;
				s1=new char[80];
				strcpy(s1,s2);
				delete[]s2;
				s2=new char[80];
				strcpy(s2,s1);
				}

			strcpy(s,&s[j+1]);
			delete[]s1;
			}
		puts(s2);
		delete[]s2;
		delete[]s;








 getch();

	}
