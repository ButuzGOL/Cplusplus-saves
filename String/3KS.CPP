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

	int i,k=0,j,l,n,h,o,g=0,k1=0;

		gets(s);
		for (i=0; s[i]!='\0'; i++)
			if (s[i]==' ') k++;

	struct slov
		{
		char s1[80];
		};
	slov *a=new slov[k];

		strcat(s," ");
		strcpy(s4,s);
		for(i=0; i<=k; i++)
			{
			for(j=0; s[j]!=' '; j++);
			strncpy(s1,s,j);
			s1[j]='\0';



			n=0;
			strcpy(s3,s4);
			for(l=0; l<=k; l++)
				{
				for(h=0; s3[h]!=' '; h++);
				strncpy(s2,s3,h);
				s2[h]='\0';
				strcpy(s3,&s3[h+1]);
				h=strcmp(s1,s2);
				if (h==0) n++;
				}

				o=0;
				for(l=0; l<g; l++)
					{
					h=strcmp(a[l].s1,s1);
					if (h==0) o++;
					}


			if (o==0)
				{
				if (n>2)
					{
					k1++;
					}
				strcpy(a[g].s1,s1);
				g++;
				}
			strcpy(s,&s[j+1]);
			}
			cout<<"Kol-vo ";
			cout<<k1;



 getch();

	}
