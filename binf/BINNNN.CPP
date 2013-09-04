# include <iostream.h>
# include <math.h>
# include <conio.h>
# include<iomanip.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
void soz(char*);
void red(int, char*);
void dop(char*);
int raz(char*);
void sor(char*);
void udal(int, char*);
void redgrup(char*);
struct monitor
	{
	char n[11];
	int d,o,r;
	}mon,mon1,mon2;
void main ()
	{
	clrscr();

		FILE *f,*f1;
		char s[30],s1[80];
		int i,so=0,n=0;

		//soz("c:\\BMonitor.txt");
		//red(2,"c:\\BMonitor.txt");
		//dop("c:\\BMonitor.txt");
		//cout<<raz("c:\\BMonitor.txt");
		//sor("e:\\BMonitor.txt");
		//udal(2,"e:\\BMonitor.txt");
		redgrup("c:\\BMonitor.txt");
		if ((f1=fopen("c:\\BMonitor.txt","r+b"))==0)
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
			}
		fclose(f1);


	getch();
	}
void redgrup(char *sl)
	{
	FILE *f1;
	int k1=0,i;
	if ((f1=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}

	for (i=0; i<4; i++)
		{
		fseek(f1,i*sizeof(mon),0);
		fread(&mon,sizeof(mon),1,f1);
		mon.r*=2;
		fseek(f1,i*sizeof(mon),0);
		fwrite(&mon,sizeof(mon),1,f1);
		}

	fclose(f1);
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
void red(int x, char *sl)
	{
	FILE *f1;
	int k=0,l;
	x--;
	if ((f1=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	fseek(f1,x*sizeof(mon),0);
	cout<<"Vi hotite redak naz monitora?0/1";
	cin>>l;
	if (l==0) gets(mon.n);
	cout<<"Vi hotite redak dio monitora?0/1";
	cin>>l;
	if (l==0) cin>>mon.d;
	cout<<"Vi hotite redak opt monitora?0/1";
	cin>>l;
	if (l==0) cin>>mon.o;
	cout<<"Vi hotite redak dio monitora?0/1";
	cin>>l;
	if (l==0) cin>>mon.r;
	fwrite(&mon,sizeof(mon),1,f1);
	fclose(f1);
	}
void dop(char *sl)
	{
	FILE *f1;
	if ((f1=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	fseek(f1,0,2);
	gets(mon.n);
	cin>>mon.d;
	cin>>mon.o;
	cin>>mon.r;
	fwrite(&mon,sizeof(mon),1,f1);
	fclose(f1);
	}
int raz(char *sl)
	{
	FILE *f1;
	if ((f1=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return 0;
			}
	fseek(f1,0,2);
	return ftell(f1)/17;

	}
void udal(int x,char *sl)
	{
	FILE *f1,*f2;
	int k1=0;
	if ((f1=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	if ((f2=fopen("e:\\BM.txt","w+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	while(fread(&mon,sizeof (mon),1,f1))
		{
		k1++;
		if (x!=k1)
			fwrite(&mon,sizeof(mon),1,f2);
		}
	fclose(f1);
	fclose(f2);
	if ((f2=fopen("e:\\BM.txt","r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	if ((f1=fopen(sl,"w+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	while(fread(&mon,sizeof (mon),1,f2))
		fwrite(&mon,sizeof(mon),1,f1);

	fclose(f1);
	fclose(f2);
	unlink("e:\\BM.txt");
	}



void sor(char *sl)
	{
	int x,i,k,j;
	char s1[80],s2[80];
	FILE *f1;
	if ((f1=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	x=raz(sl);
	for (i=0; i<x; i++)
		{
		fseek(f1,i*sizeof(mon),0);
		fread(&mon,sizeof (mon),1,f1);
		mon1=mon;
		k=i;
		for (j=i+1; j<x; j++)
			{
			fseek(f1,j*sizeof(mon),0);
			fread(&mon,sizeof (mon),1,f1);
			if (mon.d<mon1.d)
				{
				fseek(f1,j*sizeof(mon),0);
				fread(&mon,sizeof (mon),1,f1);
				mon1=mon;
				k=j;
				}
			}
		fseek(f1,i*sizeof(mon),0);
		fread(&mon,sizeof (mon),1,f1);
		mon2=mon;

		fseek(f1,i*sizeof(mon),0);
		fread(&mon,sizeof (mon),1,f1);
		mon=mon1;

		fseek(f1,i*sizeof(mon),0);
		fwrite(&mon,sizeof(mon),1,f1);

		fseek(f1,k*sizeof(mon),0);
		fread(&mon,sizeof (mon),1,f1);
		mon=mon2;

		fseek(f1,k*sizeof(mon),0);
		fwrite(&mon,sizeof(mon),1,f1);
		}

	fclose(f1);
	}
