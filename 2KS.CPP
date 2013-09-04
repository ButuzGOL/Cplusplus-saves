#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

void main()


	{
  clrscr();

	char *s1=new char[80];
	char *s=new char[80];
	char *s2=new char[80];
	char *s3=new char[80];
	char *s4=new char[80];
	char *s5=new char[80];
	char *s6=new char[80];
	int i,k=0,j=0,n,l,h,i1,j1,max;

		gets(s);
		for (i=0; s[i]!='\0'; i++)
			if (s[i]==' ') k++;


		strcat(s," ");
		for(i=0; i<=k; i++)
			{

			for(j=0; s[j]!=' '; j++);
			strncpy(s1,s,j+1);
			s1[j+1]='\0';
			max=strlen(s1);
			i1=0;
			j1-=max;

			strcpy(s3,s);
			for(l=j+1; l<=k-i-1; l++)
				{
				for(h=0; s3[h]!=' '; h++);
				strncpy(s5,s3,h+1);
				s5[h+1]='\0';
				n=strlen(s5);
				if (n>max)
					{
					max=n;
					i1=h;
					j1-=max+1;
					strcpy(s6,s5);
					}
				strcpy(s3,&s3[h+1]);
				}
			puts(s6);

			strcpy(s3,s);
			strcpy(s,&s[i1+1]);

			strncpy(s4,s3,j1+1);
			strcat(s4,s);

			strcpy(s,s4);
			}



 getch();

	}
