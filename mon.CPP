# include <iostream.h>
# include <math.h>
# include <conio.h>
# include<iomanip.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
void main ()
	{
	clrscr();

		FILE *f;
		char s[80],s1[80],s2[80],s3[80];
		int i,x,so=0;
		if ((f=fopen("E:\\Monitor.txt","r+t"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		while(fgets(s,80,f))
			{
			for(i=0; s[i]!=' '; i++);
			strncpy(s2,s,i+1);
			s2[i+1]='\0';
			puts(s2);

			strcpy(s,&s[10]);
			strncpy(s2,s,3);
			s2[3]='\0';
			puts(s2);

			strcpy(s,&s[3]);
			x=atoi(s);
			if (so<x) so=x;
			cout<<x<<endl;

			strcpy(s,&s[5]);
			x=atoi(s);
			cout<<x<<endl;
			}
		fclose(f);
		if ((f=fopen("E:\\Monitor.txt","r+t"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		gets(s1);
		while(fgets(s,80,f))
			{
			for(i=0; s[i]!=' '; i++);
			strncpy(s2,s,i);
			s2[i]='\0';
			if (strcmp(s2,s1)==0)
				{
				puts(s2);

				strcpy(s,&s[10]);
				strncpy(s2,s,3);
				s2[3]='\0';
				puts(s2);

				strcpy(s,&s[3]);
				x=atoi(s);
				cout<<x<<endl;

				strcpy(s,&s[5]);
				x=atoi(s);
				cout<<x<<endl;
				}
			}

		fclose(f);
		if ((f=fopen("E:\\Monitor.txt","r+t"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		while(fgets(s,80,f))
			{
			for(i=0; s[i]!=' '; i++);
			strncpy(s2,s,i);
			s2[i]='\0';
			strcpy(s,&s[10]);
			strncpy(s3,s,3);
			s3[3]='\0';
			strcpy(s,&s[3]);
			x=atoi(s);
			if (x==so) puts(s2);
			strcpy(s,&s[5]);
			x=atoi(s);
			}


		fclose(f);



	getch();
	}