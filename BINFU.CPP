# include <iostream.h>
# include <math.h>
# include <conio.h>
# include<iomanip.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
void soz(char*);
void perenos(char*,char*);
void sort(char*);
const m=2,n=3;
struct ekzamen
	{
	char pred[10];
	int oc;
	};
struct student
	{
	char fio[40];
	int nkur,ngrup,r,obuch;
	ekzamen usp[m][n];
	}st,st1;
void main ()
	{
	clrscr();

		FILE *f,*f1;
		int i1,j1;
		//soz("c:\\BMonitor.txt");
		//perenos("c:\\BMonitor.txt","c:\\BM.txt");
		//sort("c:\\BMonitor.txt");
		/*if ((f1=fopen("c:\\BMonitor.txt","r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		while(fread(&st,sizeof (st),1,f1))
			{
			cout<<"fio  ";
			puts(st.fio);
			cout<<"nkur  ";
			cout<<st.nkur<<endl;
			cout<<"ngrup  ";
			cout<<st.ngrup<<endl;
			for (i1=0; i1<m; i1++)
				for (j1=0;j1<n; j1++)
					{
					puts(st.usp[i1][j1].pred);
					cout<<st.usp[i1][j1].oc<<endl;
					}
			cout<<"forma obuch  ";
			cout<<st.obuch<<endl;
			cout<<endl;
			}
		fclose(f1);
		*/
		if ((f1=fopen("c:\\BMonitor.txt","r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		cin>>x;
		while(fread(&st,sizeof (st),1,f1))
			{
			if (st.nkur==x)
	getch();
	}
void soz(char *sl)
	{
	FILE *f1;
	int i,i1,j1;
	if ((f1=fopen(sl,"w+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	for (i=0; i<4; i++)
		{
		cout<<"Vvedite familiu  ";
		gets(st.fio);
		cout<<"Vvedite nkur  ";
		cin>>st.nkur;
		cout<<"Vvedite ngrup  ";
		cin>>st.ngrup;
		for (i1=0; i1<m; i1++)
			for (j1=0;j1<n; j1++)
				{
				gets(st.usp[i1][j1].pred);
				cin>>st.usp[i1][j1].oc;
				}
		cout<<"Vvedite obuch  ";
		cin>>st.obuch;
		fwrite(&st,sizeof(st),1,f1);
		}
	fclose(f1);
	}
void perenos(char *sl,char *sl1)
	{
	FILE *f1,*f2;
	int i1,j1,s=0,k=0;
	if ((f2=fopen(sl1,"w+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	if ((f1=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	while(fread(&st,sizeof (st),1,f1))
			{
			for (i1=0,s=0; i1<m; i1++)
				for (j1=0;j1<n; j1++)
					s+=st.usp[i1][j1].oc;
			if (s/6==5) fwrite(&st,sizeof(st),1,f2);
			}
	fclose(f1);
	fclose(f2);

	}
void sort(char *sl)
	{
	FILE *f1;
	int i1,j1,s=0,k=0;

	if ((f1=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	do
		{
		k=1;
		fread(&st,sizeof (st),1,f1);
		while (fread(&st1,sizeof (st1),1,f1))
			if (st.ngrup>st1.ngrup)
				{
				k=0;
				fseek(f1,ftell(f1)-2*sizeof (st),0);
				fwrite (&st1,sizeof (st1),1,f1);
				fwrite (&st,sizeof (st),1,f1);
				}
			else st=st1;
	rewind(f1);
		}
	while (!k);
	fclose(f1);
	}
