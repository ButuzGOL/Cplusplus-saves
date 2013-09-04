#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <iomanip.h>
#include <fstream.h>
#include <string.h>
void main()
	{
clrscr();
	char s[80],s1[80];
	int k=0,j,i;
	ifstream f;

		f.open("c:\\bm.txt");
		if (!f) {cerr<<"Oshibka"; return;}
		while (f.peek()!=EOF)
			{
			f.getline(s,80);
			for (i=0; s[i]!='\0'; i++)
				if (s[i]==' ') k++;
			for (i=0; i<=k; i++)
				{
				for (j=0; s[j]!=' '; j++);
				strncpy(s1,s,j);
				s1[j]='\0';
				if (strlen(s1)<=5) //if (isupper(s[0])!=0)
					puts(s);
				strcpy(s,&s[j+1]);
				}
			}
		f.close();


getch();
	}

