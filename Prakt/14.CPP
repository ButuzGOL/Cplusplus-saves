#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<iomanip.h>

void main()
	{
	clrscr();

	int i,j,k,kol,p;
	char s[80];

		gets(s);
		strcat(s," ");
		for (i=0,kol=0,p=0; s[i]!='\0'; i++)
			if (s[i]==' ')
				{
				k=0;
				for (j=p; s[j]!=' '; j++)
					if (s[j]=='g') k=1;
				if (k==1) kol++;
				p=i+1;
				}
                cout<<kol;

	getch();
	}
