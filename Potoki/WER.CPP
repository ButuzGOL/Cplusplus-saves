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
	char s[80],s1[80],s2[80],s3[80];
	int k,i,j,j1;
	ifstream f;

		f.open("e:\\my.txt");
		if (!f) {cerr<<"Oshibka"; return;}

		while (f.peek()!=EOF)
			{
			f.getline(s,80);
			puts(s);
			}
		f.close();


getch();
	}

