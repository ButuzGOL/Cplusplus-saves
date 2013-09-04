#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <iomanip.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <dos.h>
#include <dir.h>
void main()
	{
clrscr();
	int x,i,k=0;
	FILE* f,*f1;
	char s[80],s1[80],s2[80];

		x=mkdir("c:\\borlandc\\P1");
		x=mkdir("c:\\borlandc\\P2");

		setdisk(2);
		x=chdir("c:\\borlandc\\P1");
		struct ffblk full;
		cout<<"Directory listing of *.*\n";
		x=findfirst("*.",&full,0x10);
		while (!x)
			{
			puts(full.ff_name);
			x=findnext(&full);
			}



getch();
	}


