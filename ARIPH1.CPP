#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <iomanip.h>
#include <fstream.h>
#include <string.h>
char* prov(char*,int);
char* vd(char*);
char* dv(char*);
char* ds(char*);
char* sd(char*);
int bukvi(char);
char* buk(int);
void main()
	{
clrscr();
	char s[40],s1[40];
	int x;
		cout<<"V kakoi hotite vvesti ";
		cin>>x;
		cout<<"Vvedite chislo ";
		gets(s);
		puts(prov(s,x));
		if (strcmp(prov(s,x),"vse normalno")==0)
			{
			if (x==2) {puts(ds(s)); puts(dv(s));}
			if (x==8) {puts(vd(s)); strcpy(s1,vd(s)); puts(ds(s1));}
			if (x==16){puts(sd(s)); strcpy(s1,sd(s)); puts(dv(s1));}
			}
getch();
	}
char* vd(char*s)
	{
	char s1[40],s2[40],s3[40],s4[40],s5[40],s6[40];
	int i=0,l=0,x,x1,x2;

		strcpy(s5,"");
		strcpy(s6,"");
		while(s[i]!='\0')
			{
			if (s[i]=='.') l=1;
			i++;
			}

		if (l==1)
			{
			for(i=0; s[i]!='.'; i++);
			strncpy(s1,s,i);
			s1[i]='\0';
			strcpy(s2,&s[i+1]);
			x=atoi(s1);
			x1=atoi(s2);
			}
		else {strcpy(s1,s); x=atoi(s1);}

		for (i=0; i<strlen(s1); i++)
			{
			itoa(x,s3,10);
			strcpy(s4,&s3[1]);
			x=atoi(s4);
			s3[1]='\0';
			x2=atoi(s3);
			if (x2>=4) {x2-=4; strcat(s5,"1");}
			else strcat(s5,"0");
			if (x2>=2) {x2-=2; strcat(s5,"1");}
			else strcat(s5,"0");
			if (x2>=1) {x2-=1; strcat(s5,"1");}
			else strcat(s5,"0");

			}

		if (l==1)
			{
			for (i=0; i<strlen(s2); i++)
				{
				itoa(x1,s3,10);
				strcpy(s4,&s3[1]);
				x1=atoi(s4);
				s3[1]='\0';
				x2=atoi(s3);
				if (x2>=4) {x2-=4; strcat(s6,"1");}
				else strcat(s6,"0");
				if (x2>=2) {x2-=2; strcat(s6,"1");}
				else strcat(s6,"0");
				if (x2>=1) {x2-=1; strcat(s6,"1");}
				else strcat(s6,"0");
				}
			strcat(s5,".");
			strcat(s5,s6);
			}
		return s5;
	}
char* sd(char*s)
	{
	char s1[40],s2[40],s3[40],s4[40],s5[40],s6[40];
	int i=0,l=0,x,x1,x2;

		strcpy(s5,"");
		strcpy(s6,"");
		while(s[i]!='\0')
			{
			if (s[i]=='.') l=1;
			i++;
			}

		if (l==1)
			{
			for(i=0; s[i]!='.'; i++);
			strncpy(s1,s,i);
			s1[i]='\0';
			strcpy(s2,&s[i+1]);
			}
		else strcpy(s1,s);

		strcpy(s3,s1);
		for (i=0; i<strlen(s1); i++)
			{
			if (s3[0]>='A' && s3[0]<='F') x2=bukvi(s3[0]);
			else {strncpy(s4,s3,1); s4[1]='\0'; x2=atoi(s4); }

			if (x2>=8) {x2-=8; strcat(s5,"1");}
			else strcat(s5,"0");
			if (x2>=4) {x2-=4; strcat(s5,"1");}
			else strcat(s5,"0");
			if (x2>=2) {x2-=2; strcat(s5,"1");}
			else strcat(s5,"0");
			if (x2>=1) {x2-=1; strcat(s5,"1");}
			else strcat(s5,"0");
			strcpy(s3,&s3[1]);
			}

		if (l==1)
			{
			strcpy(s3,s2);
			for (i=0; i<strlen(s2); i++)
				{
				if (s3[0]>='A' && s3[0]<='F') x2=bukvi(s3[0]);
				else {strncpy(s4,s3,1); s4[1]='\0'; x2=atoi(s4);}

				if (x2>=8) {x2-=8; strcat(s6,"1");}
				else strcat(s6,"0");
				if (x2>=4) {x2-=4; strcat(s6,"1");}
				else strcat(s6,"0");
				if (x2>=2) {x2-=2; strcat(s6,"1");}
				else strcat(s6,"0");
				if (x2>=1) {x2-=1; strcat(s6,"1");}
				else strcat(s6,"0");
				strcpy(s3,&s3[1]);
				}
			strcat(s5,".");
			strcat(s5,s6);
			}
		return s5;
	}
char* dv(char*s)
	{
	char s1[40],s2[40],s3[40],s4[40],s5[40],s6[40];
	int i=0,l=0,x,x1,x2;

		strcpy(s5,"");
		strcpy(s6,"");
		while(s[i]!='\0')
			{
			if (s[i]=='.') l=1;
			i++;
			}
		if (l==1)
			{
			for(i=0; s[i]!='.'; i++);
			strncpy(s1,s,i);
			s1[i]='\0';
			if (strlen(s1)%3==2)
				{
				strcpy(s3,"0");
				strcat(s3,s1);
				strcpy(s1,s3);
				}
			if (strlen(s1)%3==1)
				{
				strcpy(s3,"00");
				strcat(s3,s1);
				strcpy(s1,s3);
				}
			strcpy(s2,&s[i+1]);
			if (strlen(s2)%3==2) strcat(s2,"0");
			if (strlen(s2)%3==1) strcat(s2,"00");
			}
		else
			{
			strcpy(s1,s);
			if (strlen(s1)%3==2)
				{
				strcpy(s3,"0");
				strcat(s3,s1);
				strcpy(s1,s3);
				}
			if (strlen(s1)%3==1)
				{
				strcpy(s3,"00");
				strcat(s3,s1);
				strcpy(s1,s3);
				}
			}
		strcpy(s3,s1);
		for (i=0; i<(strlen(s1)/3); i++)
			{
			x2=0;
			strncpy(s4,s3,3);
			s4[3]='\0';
			if (s4[0]=='1') x2+=4;
			if (s4[1]=='1') x2+=2;
			if (s4[2]=='1') x2+=1;
			strcpy(s3,&s3[3]);
			itoa(x2,s4,10);
			strcat(s5,s4);
			}

		if (l==1)
			{
			strcpy(s3,s2);
			for (i=0; i<(strlen(s2)/3); i++)
				{
				x2=0;
				strncpy(s4,s3,3);
				s4[3]='\0';
				if (s4[0]=='1') x2+=4;
				if (s4[1]=='1') x2+=2;
				if (s4[2]=='1') x2+=1;
				strcpy(s3,&s3[3]);
				itoa(x2,s4,10);
				strcat(s6,s4);
				}
			strcat(s5,".");
			strcat(s5,s6);
			}
		return s5;
	}
char* ds(char*s)
	{
	char s1[40],s2[40],s3[40],s4[40],s5[40],s6[40];
	int i=0,l=0,x,x1,x2;

		strcpy(s5,"");
		strcpy(s6,"");
		while(s[i]!='\0')
			{
			if (s[i]=='.') l=1;
			i++;
			}
		if (l==1)
			{
			for(i=0; s[i]!='.'; i++);
			strncpy(s1,s,i);
			s1[i]='\0';
			if (strlen(s1)%4==3)
				{
				strcpy(s3,"0");
				strcat(s3,s1);
				strcpy(s1,s3);
				}
			if (strlen(s1)%4==2)
				{
				strcpy(s3,"00");
				strcat(s3,s1);
				strcpy(s1,s3);
				}
			if (strlen(s1)%4==1)
				{
				strcpy(s3,"000");
				strcat(s3,s1);
				strcpy(s1,s3);
				}

			strcpy(s2,&s[i+1]);
			if (strlen(s2)%4==3) strcat(s2,"0");
			if (strlen(s2)%4==2) strcat(s2,"00");
			if (strlen(s2)%4==1) strcat(s2,"000");
			}
		else
			{
			strcpy(s1,s);
			if (strlen(s1)%4==3)
				{
				strcpy(s3,"0");
				strcat(s3,s1);
				strcpy(s1,s3);
				}
			if (strlen(s1)%4==2)
				{
				strcpy(s3,"00");
				strcat(s3,s1);
				strcpy(s1,s3);
				}
			if (strlen(s1)%4==1)
				{
				strcpy(s3,"000");
				strcat(s3,s1);
				strcpy(s1,s3);
				}
			}
		strcpy(s3,s1);
		for (i=0; i<(strlen(s1)/4); i++)
			{
			x2=0;
			strncpy(s4,s3,4);
			s4[4]='\0';
			if (s4[0]=='1') x2+=8;
			if (s4[1]=='1') x2+=4;
			if (s4[2]=='1') x2+=2;
			if (s4[3]=='1') x2+=1;
			strcpy(s3,&s3[4]);
			if (x2>9) strcat(s5,buk(x2));
			else {itoa(x2,s4,10); strcat(s5,s4);}
			}

		if (l==1)
			{
			strcpy(s3,s2);
			for (i=0; i<(strlen(s2)/4); i++)
				{
				x2=0;
				strncpy(s4,s3,4);
				s4[4]='\0';
				if (s4[0]=='1') x2+=8;
				if (s4[1]=='1') x2+=4;
				if (s4[2]=='1') x2+=2;
				if (s4[3]=='1') x2+=1;
				strcpy(s3,&s3[4]);
				if (x2>9) strcat(s6,buk(x2));
				else {itoa(x2,s4,10); strcat(s6,s4);}
				}
			strcat(s5,".");
			strcat(s5,s6);
			}
		return s5;
	}

int bukvi(char x)
	{
	switch (x)
		{
		case 'A':return 10;
		case 'B':return 11;
		case 'C':return 12;
		case 'D':return 13;
		case 'E':return 14;
		case 'F':return 15;
		}
	}
char* buk(int x)
	{
	switch (x)
		{
		case 10:return "A";
		case 11:return "B";
		case 12:return "C";
		case 13:return "D";
		case 14:return "E";
		case 15:return "F";
		}
	}
char* prov(char*s,int c)
	{
	int x=0, x1=0;
	if (c!=2 && c!=8 && c!=16) x=1;
	for (int i=0;s[i]!='\0';i++)
		{
		if ((s[i]>'1' || s[i]<'0') && c==2) x1=1;
		if ((s[i]>'7' || s[i]<'0') && c==8) x1=1;
		if (!((s[i]>'A' && s[i]<'F')|| (s[i]>'0' && s[i]<'9')) && c==16) x1=1;
		}
	if (x==1 && x1==0) return "nepr vvedina sistema";
	if (x==0 && x1==1)  return "ne sootvetstvuet sisteme";
	return "vse normalno";
	}



