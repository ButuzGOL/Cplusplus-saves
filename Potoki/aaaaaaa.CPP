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
	int j,i,raz[4],x;
	ofstream f;

		f.open("e:\\my.txt");
		if (!f) {cerr<<"Oshibka"; return;}

		for(i=0; i<4; i++)
			{
			gets(s);
			raz[i]=strlen(s)+2;
			for(j=raz[i]-2; j<40; j++)
				strcat(s,".");
			strcat(s,'\0');
			f<<s;
			f<<'\n';
			}
		f.close();

		fstream ff;
		ff.open("e:\\my.txt",ios::out|ios::in);
		if (!ff) {cerr<<"Oshibka"; return;}

		x=80;
		ff.seekp(x,ios::beg);
		gets(s);
		raz[2]=strlen(s)+2;
		for(j=raz[i]-2; j<40; j++)
			strcat(s,".");
		strcat(s,'\0');

		ff<<s;
		ff.close();


		ifstream f1;
		f1.open("e:\\my.txt",ios::out);
		if (!f1) {cerr<<"Oshibka"; return;}
		i=0;
		while (f1.peek()!=EOF)
			{
			f1.getline(s,raz[i]);
			puts(s);
			cout<<strlen(s)+2<<endl;
			i++;
			}
		f1.close();

getch();
	}

