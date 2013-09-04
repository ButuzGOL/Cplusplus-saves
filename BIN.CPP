# include <iostream.h>
# include <math.h>
# include <conio.h>
# include<iomanip.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
struct monitor
	{
	char n[11];
	int d,o,r;
	}mon;
void main ()
	{
	clrscr();

		FILE *f,*f1;
		char s[80],s1[80];
		int i,so=0;
		if ((f=fopen("C:\\borlandc\\Monitor.txt","r+t"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		if ((f1=fopen("C:\\borlandc\\BMonitor.txt","w+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}

		while(fgets(s,30,f))
			{
			strncpy(mon.n,s,10);
			mon.n[10]='\0';

			mon.d=atoi(&s[10]);

			mon.o=atoi(&s[13]);;

			mon.r=atoi(&s[18]);;
			fwrite(&mon,sizeof (mon),1,f1);
			}
		fclose(f);
		fclose(f1);

		if ((f1=fopen("C:\\borlandc\\BMonitor.txt","r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		while(fread(&mon,sizeof (mon),1,f1))
			{
			puts(mon.n);
			cout<<mon.d<<endl;
			cout<<mon.o<<endl;
			cout<<mon.r<<endl;
			if (mon.r>so) so=mon.r;
			}
		fclose(f1);

		gets(s1);
		if ((f1=fopen("C:\\borlandc\\BMonitor.txt","r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		while(fread(&mon,sizeof (mon),1,f1))
			{
			i=0;
			while(mon.n[i]!=' ')
				i++;
			mon.n[i]='\0';
			if (strcmp(s1,mon.n)==0)
				{
				puts(mon.n);
				cout<<mon.d<<endl;
				cout<<mon.o<<endl;
				cout<<mon.r<<endl;
				}
			}
		fclose(f1);
		if ((f1=fopen("C:\\borlandc\\BMonitor.txt","r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}

		while(fread(&mon,sizeof (mon),1,f1))
			if (so==mon.r)
				puts(mon.n);
		fclose(f1);

	getch();
	}