#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <iomanip.h>
#include <fstream.h>
#include <string.h>
void soz(char*);
void vivod(char*);
void otl(char*,char*);
void sort(char*);
void oc(char*);
const n=2;
const m=2;
struct	ekz
	{
	char nam[15];
	int oc;
	};
struct	student
	{
	char f[15];
	int nkur,ngru,fo;
	ekz a[n][m];
	}st,st1;


void main()
	{
clrscr();

		//soz("c:\\fog1.txt");
		//otl("c:\\fog1.txt","c:\\fog2.txt");
		sort("c:\\fog1.txt");
		vivod("c:\\fog1.txt");
		//oc("c:\\fog1.txt");


getch();
	}
void soz(char* sl)
	{
	char s[80];
	ofstream f;
	int i,i1,j1;

	f.open(sl,ios::in|ios::binary);
	if (!f) {cerr<<"Oshibka"; return;}

	for (i=0; i<3; i++)
		{
		cout<<"VVedite fam   ";
		gets(st.f);
		cout<<"VVedite nkur  ";
		cin>>st.nkur;
		cout<<"VVedite ngru  ";
		cin>>st.ngru;
		for (i1=0; i1<n; i1++)
			for (j1=0; j1<m; j1++)
				{
				cout<<"VVedite nam  ";
				gets(st.a[i1][j1].nam);
				cout<<"VVedite ocen ";
				cin>>st.a[i1][j1].oc;
				}
		f.write((char*)&st,sizeof(st));
		}
	f.close();
	}
void vivod(char* sl)
	{
	ifstream f;
	char s[80];
	int i1,j1;
		f.open(sl);
		if (!f) {cerr<<"Oshibka"; return;}

		while (f.peek()!=EOF)
			{
			f.read((char*)&st,sizeof(st));
			cout<<"familia   ";
			puts(st.f);
			cout<<"nkursa    "<<st.nkur<<endl;
			cout<<"ngrupi    "<<st.ngru<<endl;
			for (i1=0; i1<n; i1++)
				for (j1=0; j1<m; j1++)
					{
					cout<<"Imya pred  ";
					puts(st.a[i1][j1].nam);
					cout<<"Ocenka     "<<st.a[i1][j1].oc<<endl;
					}

			getch();
			}
	f.close();
	}
void otl(char* sl,char* sl1)
	{
	ifstream f;
	ofstream f1;
	int i1,j1,s;

		f.open(sl);
		if (!f) {cerr<<"Oshibka"; return;}

		f1.open(sl1,ios::in|ios::binary);
		if (!f1) {cerr<<"Oshibka"; return;}


		while (f.peek()!=EOF)
			{
			f.read((char*)&st,sizeof(st));

			for (i1=0,s=0; i1<n; i1++)
				for (j1=0; j1<m; j1++)
					{
					s+=st.a[i1][j1].oc;
					}
			if (s/4==5) f1.write((char*)&st,sizeof(st));
			}
	f.close();
	f1.close();
	}
void sort(char* sl)
	{
	fstream f;
	char s[80];
	int k;
		f.open(sl,ios::in|ios::binary);
		if (!f) {cerr<<"Oshibka"; return;}

		do
			{
			k=1;
			f.seekp(0,ios::beg);
			f.read((char*)&st,sizeof(st));
			while (f.peek()!=EOF)
				{
				f.read((char*)&st1,sizeof(st1));
				if (st.ngru<st1.ngru)
					{
					k=0;
					f.seekp(-2*sizeof(st),ios::cur);
					f.write((char*)&st1,sizeof(st1));
					f.write((char*)&st,sizeof(st));
					}
				else    st=st1;
				}
			}
		while(!k);
		f.close();
	}
void oc(char* sl)
	{
	ifstream f;
	int i1,j1,a[4],k1,x,s1=0,s,k2=0,k,i,j;
		f.open(sl);
		if (!f) {cerr<<"Oshibka"; return;}

		for (i1=0,k1=0; i1<4; i1++)
				a[i1]=0;
		cout<<"Vvedite kurs  ";
		cin>>x;
		for (i=0; i<4; i++)
			{
			f.seekg(i*sizeof(st),ios::beg);
			f.read((char*)&st,sizeof(st));
			for (i1=0,k1=0; i1<4; i1++)
				if (a[i1]==st.ngru) k1=1;
			if (k1==0)
				{
				if (x==st.nkur)
					{
					k=0;
					s=0;
					a[i]=st.ngru;
					for (j=0; j<4; j++)
						{
						f.seekg(j*sizeof(st),ios::beg);
						f.read((char*)&st,sizeof(st));
						if (a[i]==st.ngru)
							{
							for (i1=0; i1<n; i1++)
								for (j1=0; j1<m; j1++)
									{
									s+=st.a[i1][j1].oc;
									s1+=st.a[i1][j1].oc;
									k2++;
									}
							k++;
							}
						}
					s/=(4*k);
					cout<<"Sredniy bal "<<x<<"  kursa "<<a[i]<<"  grupp= "<<s<<endl;
					}
				}
			}
		cout<<"Sredniy bal "<<x<<"  kursa "<<s1/k2;
		f.close();
                }
