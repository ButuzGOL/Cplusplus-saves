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
		int i1,j1,a[4],s,x,i,j,k,k1,k2=0,s1=0;
		//soz("e:\\BMonitor.txt");
		//perenos("e:\\BMonitor.txt","e:\\BM.txt");
		sort("e:\\BMonitor.txt");
		if ((f1=fopen("e:\\BMonitor.txt","r+b"))==0)
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
			getch();
			}
		fclose(f1);

		if ((f1=fopen("e:\\BMonitor.txt","r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		for (i1=0,k1=0; i1<4; i1++)
				a[i1]=0;
		cout<<"Vvedite kurs  ";
		cin>>x;
		for (i=0; i<4; i++)
			{
			fseek (f1,i*sizeof (st),0);
			fread(&st,sizeof (st),1,f1);
			for (i1=0,k1=0; i1<4; i1++)
				if (a[i1]==st.ngrup) k1=1;
			if (k1==0)
				{
				if (x==st.nkur)
					{
					k=0;
					s=0;
					a[i]=st.ngrup;
					for (j=0; j<4; j++)
						{
						fseek (f1,j*sizeof (st),0);
						fread(&st,sizeof (st),1,f1);
						if (a[i]==st.ngrup)
							{
							for (i1=0; i1<m; i1++)
								for (j1=0; j1<n; j1++)
									{
									s+=st.usp[i1][j1].oc;
									s1+=st.usp[i1][j1].oc;
									k2++;
									}
							k++;
							}
						}
					s/=(6*k);
					cout<<"Sredniy bal "<<x<<"  kursa "<<a[i]<<"grupp=  "<<s<<endl;
					}
				}
			}
		cout<<s1/k2;
		fclose(f1);
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
