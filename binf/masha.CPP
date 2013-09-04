# include <iostream.h>
# include <math.h>
# include <conio.h>
# include<iomanip.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
void soz(char*);
void zvk(char*);
void red(char*,int);
struct monitor
	{
	char n[11];
	int d,o,r;
	}mon;
void main ()
	{
	clrscr();

		FILE *f,*f1;
		char s[30],s1[80];
		int i,so=0,n=0;

 //	soz("E:\\BMonitor.txt");
			 /*	if ((f=fopen("E:\\Monitor.txt","r+t"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		if ((f1=fopen("E:\\BMonitor.txt","w+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}

		while(fgets(s,30,f))
			{
			strncpy(mon.n,s,10);
			mon.n[10]='\0';

			mon.d=atoi(&s[10]);

			mon.o=atoi(&s[13]);

			mon.r=atoi(&s[18]);

			fwrite(&mon,sizeof(mon),1,f1);
			}
		fclose(f);
		fclose(f1);
		*/
		if ((f1=fopen("E:\\BMonitor.txt","r+b"))==0)
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
			//if (mon.r>so) so=mon.r;
			}
		fclose(f1);
		  /*
		gets(s1);
		if ((f1=fopen("E:\\BMonitor.txt","r+b"))==0)
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
		if ((f1=fopen("E:\\BMonitor.txt","r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}

		while(fread(&mon,sizeof (mon),1,f1))
			if (so==mon.r)
				puts(mon.n);
		fclose(f1);
				*/
  int p;
  cout<<"vvedite nomer redaktirovannoy zapisi:(ot 0 do 3)"<<endl;
  cin>>p;
  red("E:\\BMonitor.txt",p);
	if ((f1=fopen("E:\\BMonitor.txt","r+b"))==0)
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
			//if (mon.r>so) so=mon.r;
			}
			 zvk("E:\\BMonitor.txt");
		fclose(f1);
	getch();
	}
void soz(char *sl)
	{
	FILE *f1;
	int i;
	if ((f1=fopen(sl,"w+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	for (i=0; i<4; i++)
		{
		gets(mon.n);
		cin>>mon.d;
		cin>>mon.o;
		cin>>mon.r;
		fwrite(&mon,sizeof(mon),1,f1);
		}
		fclose(f1);
	}
void red(char*sl,int p)
{ 	FILE *f1;
	int i;
	if ((f1=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	fseek(f1,p*sizeof(mon),0);
	fread(&mon,sizeof(mon),1,f1);
	cout<<"redaktirovaemaya zapis"<<endl;
	 puts(mon.n);
		cout<<mon.d<<endl;
		cout<<mon.o<<endl;
		cout<<mon.r<<endl;
  fseek(f1,p*sizeof(mon),0);
	cout<<"vvesti nhovie dannie"<<endl;
	 gets(mon.n);
		cin>>mon.d;
		cin>>mon.o;
		cin>>mon.r;
	fwrite(&mon,sizeof(mon),1,f1);
		fclose(f1);

}
void zvk(char*sl)
{ 	FILE *f1;
	int i;
	if ((f1=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	fseek(f1,0,2);
	fread(&mon,sizeof(mon),1,f1);
	cout<<"poslednyaya zapis"<<endl;
	 puts(mon.n);
		cout<<mon.d<<endl;
		cout<<mon.o<<endl;
		cout<<mon.r<<endl;
  fseek(f1,0,2);
	cout<<"vvesti novie dannie"<<endl;
	 gets(mon.n);
		cin>>mon.d;
		cin>>mon.o;
		cin>>mon.r;
	fwrite(&mon,sizeof(mon),1,f1);
		fclose(f1);

}