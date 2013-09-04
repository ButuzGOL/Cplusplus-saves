#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <iomanip.h>
#include <fstream.h>
#include <iostream.h>
#include <string.h>
void main()
	{
clrscr();
	char s[80],s1[80];
	int k=0,j,i,a[4];
	ofstream f;

		f.open("c:\\my.txt",ios::in);
		if (!f) {cerr<<"Oshibka"; return;}

		for (i=0; i<4; i++)
			{
			gets(s);
			a[i]=strlen(s)+2;
			//for(j=strlen(s); j<79; j++)
			  //	strcat(s,".");
			f.write(s,80);
			}
		f.close();

	ofstream ff;

		ff.open("c:\\my.txt",ios::in);
		if (!ff) {cerr<<"Oshibka"; return;}

		ff.seekp(160,ios::beg);
		gets(s);
		ff.write(s,80);
		ff.close();


	ifstream f1;

		f1.open("c:\\my.txt");
		if (!f1) {cerr<<"Oshibka"; return;}

		while (f1.peek()!=EOF)
			{
			f1.read(s,80);
			puts(s);
			}
		f1.close();


getch();
	}

