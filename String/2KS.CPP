#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

void main()


	{
  clrscr();

	char *s=new char[80];
	char *s1=new char[80];
	char *s2=new char[80];
	char *s3=new char[80];
	char *s4=new char[80];

	int i,k=0,j,n1,max;

		gets(s);
		for (i=0; s[i]!='\0'; i++)
			if (s[i]==' ') k++;

	struct slov
		{
		char s1[80];
		};
	slov *a=new slov[k];

		strcat(s," ");
		for(i=0; i<=k; i++)
			{
			for(j=0; s[j]!=' '; j++);
			strncpy(s1,s,j);
			s1[j]='\0';
			strcpy(a[i].s1,s1);
			strcpy(s,&s[j+1]);
			}

		for(i=0; i<=k; i++)
			{
			max=strlen(a[i].s1); n1=i; strcpy(s4,a[i].s1);
			for(j=i+1; j<=k; j++)
				if (strlen(a[j].s1)>max)
					{
					max=strlen(a[j].s1);
					n1=j;
					strcpy(s4,a[j].s1);
					}
			strcpy(a[n1].s1,a[i].s1);
			strcpy(a[i].s1,s4);
			}
		for(i=0; i<=k; i++)
			puts(a[i].s1);



 getch();

	}
