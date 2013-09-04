# include <iostream.h>
# include <math.h>
# include <conio.h>
# include<iomanip.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
void soz(char*,int);
void red(int, char*);
void dop(char*);
int raz(char*);
void sor(char*);
int fog(char*);

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
		int i,so=0,n=0,x;

		soz("c:\\BMonitor.txt",2);
		//red(2,"c:\\BMonitor.txt");
		//dop("c:\\BMonitor.txt");
		//cout<<raz("c:\\BMonitor.txt");
		//sor("c:\\BMonitor.txt");
		if ((f1=fopen("c:\\BMonitor.txt","r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		while(fread(&x,sizeof (x),1,f1))
			{
			cout<<x;
			}
		fclose(f1);
		cout<<endl;
		cout<<fog("c:\\BMonitor.txt");

	getch();
	}

void soz(char *sl,int x)
	{
	FILE *f1;
	int i;
	char ss[5];
	if ((f1=fopen(sl,"w+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	fwrite(&x,sizeof(x),1,f1);
	fclose(f1);
	}
int fog(char *sl)
	{
	FILE *f1;
	int x1,x;
	char s[40];
	if ((f1=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			}
	while(fread(&x,sizeof (x),1,f1))
		x1=x;
	fclose(f1);
	return x1;
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
void sor(char *sl)
	{
	int x,i,d1,d2,d3,do1,do2,do3,k,j,k1;
	char s1[80],s2[80];
	FILE *f1;
	if ((f1=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	x=raz(sl);
	do
		{
		k=1;
		for (i=0; i<x-1; i++)
			{
			k1=0;
			while(fread(&mon,sizeof (mon),1,f1))
				{
				k1++;
				if (i==k1) d1=mon.d;
				}

			k1=0;
			while(fread(&mon,sizeof (mon),1,f1))
				{
				k1++;
				if ((i+1)==k1) do1=mon.d;
				}
			cout<<"proverka d1 vs do1 "<<d1<<"    "<<do1<<endl;
			if (d1>do1)
				{
				k1=0;
				while(fread(&mon,sizeof (mon),1,f1))
					{
					if (i==k1)
					k1++;
					}

				strcpy(s1,mon.n);
				d2=mon.o;
				d3=mon.r;

				k1=0;
				while(fread(&mon,sizeof (mon),1,f1))
					{
					if ((i+1)==k1)
					k1++;
					}
				strcpy(s2,mon.n);
				do2=mon.o;
				do3=mon.r;


				k1=0;
				while(fread(&mon,sizeof (mon),1,f1))
					{
					if (i==k1)
					k1++;
					}
				strcpy(mon.n,s2);
				mon.o=do2;
				mon.r=do3;
				fwrite(&mon,sizeof(mon),1,f1);

				k1=0;
				while(fread(&mon,sizeof (mon),1,f1))
					{
					if ((i+1)==k1)
					k1++;
					}
				strcpy(mon.n,s1);
				mon.o=d2;
				mon.r=d3;
				fwrite(&mon,sizeof(mon),1,f1);

				k=0;
				}
			}
		}
	while (!k);

       /*	for (i=0; i<x; i++)
		{
		k1=0;
		while(fread(&mon,sizeof (mon),1,f1))
			{
			if (i==k1)
			k1++;
			}
		strcpy(s1,mon.n);
		d1=mon.d;
		d2=mon.o;
		d3=mon.r;
		k=i;
		for (j=i+1; j<x; j++)
			{
			k1=0;
			while(fread(&mon,sizeof (mon),1,f1))
				{
				if (j==k1)
				k1++;
				}
			if (mon.d<d1)
				{
				k1=0;
				while(fread(&mon,sizeof (mon),1,f1))
					{
					if (j==k1)
					k1++;
					}
				strcpy(s1,mon.n);
				d1=mon.d;
				d2=mon.o;
				d3=mon.r;
				k=j;
				}
			}
		k1=0;
		while(fread(&mon,sizeof (mon),1,f1))
			{
			if (i==k1)
			k1++;
			}
		strcpy(s2,mon.n);
		do1=mon.d;
		do2=mon.o;
		do3=mon.r;

		k1=0;
		while(fread(&mon,sizeof (mon),1,f1))
			{
			if (i==k1)
				{
				strcpy(mon.n,s1);
				mon.d=d1;
				mon.o=d2;
				mon.r=d3;
				fwrite(&mon,sizeof(mon),1,f1);
				}
			k1++;
			}

		k1=0;
		while(fread(&mon,sizeof (mon),1,f1))
			{
			if (k==k1)
				{
				strcpy(mon.n,s2);
				mon.d=do1;
				mon.o=do2;
				mon.r=do3;
				fwrite(&mon,sizeof(mon),1,f1);
				}
			k1++;
			}
		}
	*/





	fclose(f1);
	}