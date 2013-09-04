#include<conio.h>
#include<math.h>
#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include <ctype.h>
int schet(char*);
void main()
	{
clrscr();
	char *s=new char[80];
	char *s1=new char[80];
	char *s2=new char[80];
	char *so=new char[80];
	char *sl1=new char[80];
	char *sl2=new char[80];
	int n,i,x,j,k;
	gets(s);
	strcpy(s2,s);
	strcpy(s1,s);
	n=strlen(s);
	for(i=0; i<n; i++)
		{
		if (!isalpha(s[i]) && !isdigit(s[i]) && (s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/' && s[i]!='(' && s[i]!=')'))
			{
			cout<<"Simvol ne pravelnii "<<s[i]<<endl;
			return;
			}
		if ((s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/') && (s[i+1]=='+' || s[i+1]=='*' || s[i+1]=='/'))
			{
			cout<<"Dva znaka podrad "<<endl;
			return;
			}
		if (isalpha(s[i]) && isalpha(s[i+1]))
			{
			cout<<"Dve bukvi podrad "<<endl;
			return;
			}
		if ((s[i]=='(') && (s[i+1]=='+' && s[i+1]=='*' && s[i+1]=='/'))
			{
			cout<<"( i znak podrad "<<endl;
			return;
			}
		if ((s[i+1]==')') && (s[i]=='+' && s[i]=='-' && s[i]=='*' && s[i]=='/'))
			{
			cout<<"znak i ) podrad "<<endl;
			return;
			}
		if (s[i]=='(')
			for (j=i,k=0; s[j]!=')'; j++)
				if (s[j]=='-' || s[j]=='+' || s[j]=='*' || s[j]=='/')
					k++;
			if (k==0)
				{
				cout<<" () podrad "<<endl;
				return;
				}

		}

		for (i=0,k=0; i<n; i++)
			if (s[i]=='(' || s[i]==')') k++;
		if (k%2!=0)
			{
			cout<<"malo kovichek "<<endl;
			return;
			}
		if (k!=0)
			{
			for (i=0; s[i]!='('; i++);
			for (j=0; s[j]!=')'; j++);
			if (i>j)
				{
				cout<<"snochalo otkrivaut a ne zakrivaut "<<endl;
				return;
				}
			}

		if (s[n-1]=='+' || s[n-1]=='*' || s[n-1]=='/' || s[n-1]=='-')
			{
			cout<<"Poslediy simvol znak "<<endl;
			return;
			}
		if (s[0]=='+' || s[0]=='*' || s[0]=='/')
			{
			cout<<"Pervii simvol znak "<<endl;
			return;
			}

		for (i=0; i<n; i++)
			{
			if (s[i]=='+' && s[i+1]=='-')
				{
				strncpy(so,s,i);
				so[i]='\0';
				strcpy(s,&s[i+2]);
				strcat(so,"-");
				strcat(so,s);
				strcpy(s,so);
				}
			if (s[i]=='-' && s[i+1]=='-')
				{
				strncpy(so,s,i);
				so[i]='\0';
				strcpy(s,&s[i+2]);
				strcat(so,"+");
				strcat(so,s);
				strcpy(s,so);
				}
			}

		n=strlen(s);
		for (i=0; i<n; i++)
			if (s[i]=='(')
				{
				for (j=i; s[j]!=')'; j++);
				strcpy(sl1,s);
				strcpy(sl1,&sl1[i+1]);
				strncpy(sl2,sl1,j-i);
				sl2[j-i-1]='\0';
				x=schet(sl2);

				strncpy(s1,s,i);
				s1[i]='\0';
				itoa(x,so,10);
				strcat(s1,so);
				strcpy(so,&s[j+1]);
				strcat(s1,so);
				strcpy(s,s1);
				i=0;
				}

		x=schet(s1);
		strcat(s2,"=");
		itoa(x,so,10);
		strcat(s2,so);
		puts(s2);


getch();
	}
struct buk
	{
	char b;
	int c;
	};
int schet (char*s)
	{
	int x,n,i,j1,j,y,z,k1,k2=0,k=0;
	char *sp=new char[80];
	char *so=new char[80];
	char *s1=new char[80];
	strcpy(s1,"");
        n=strlen(s);
	for (i=0; i<n; i++)
			{
			if (isalpha(s[i]))
				{
				for(j=0,k1=0; j<i; j++)
					if (s[i]==s[j]) k1++;
				if (k1==0) k++;
				}
			}

	buk *bu=new buk[k];

		for (i=0; i<n; i++)
			{
			if (isalpha(s[i]))
				{
				for(j=0,k1=0; j<i; j++)
					if (s[i]==s[j]) k1++;
				if (k1==0)
					{
					bu[k2].b=s[i];
					k2++;
					}
				}
			}
		if (k>0)
			{
			cout<<"WWWedite bukvu\n";
			for (i=0; i<k; i++)
				{
				cout<<bu[i].b<<" ";
				cin>>bu[i].c;
				cout<<'\n';
				}
			}

	if (isalpha(s[0])) x=bu[0].c;
		if (isdigit(s[0])) x=atoi(s);
		if (s[0]=='-' && isdigit(s[1]))	{x=atoi(&s[1]); x*=-1; strcpy(s,&s[1]);}
		if (s[0]=='-' && isalpha(s[1])) {x=bu[0].c; x*=-1; strcpy(s,&s[1]);}

		n=strlen(s);
		for (i=0; i<n; i++)
			{
			for (j1=0; j1<n; j1++)
				{
				if (s[j1]=='+' && s[j1+1]=='-')
					{
					strncpy(so,s,j1);
					so[j1]='\0';
					strcpy(s,&s[j1+2]);
					strcat(so,"-");
					strcat(so,s);
					strcpy(s,so);
					}
				if (s[j1]=='-' && s[j1+1]=='-')
					{
					strncpy(so,s,j1);
					so[j1]='\0';
					strcpy(s,&s[j1+2]);
					strcat(so,"+");
					strcat(so,s);
					strcpy(s,so);
					}
				}

			if ((s[i]=='/' || s[i]=='*') && (s[i+1]!='-'))
				{
				if (isalpha(s[i+1]))
					{
					for (j=0; j<k; j++)
						if (s[i+1]==bu[j].b)
							y=bu[j].c;
					}
				else y=atoi(&s[i+1]);
				switch (s[i])
					{
					case '*':z=x*y; break;
					case '/':z=x/y; break;
					}
				x=z;
				}
			if (s[i]=='+' || s[i]=='-')
				{
				itoa(x,sp,10);
				strcat(s1,sp);
				switch (s[i])
					{
					case '+':strcat(s1,"+");; break;
					case '-':strcat(s1,"-");; break;
					}
				if (isalpha(s[i+1]))
					{
					for (j=0; j<k; j++)
						if (s[i+1]==bu[j].b)
							x=bu[j].c;
					}
				else x=atoi(&s[i+1]);
				}
			if ((s[i]=='/' || s[i]=='*') && (s[i+1]=='-'))
				{
				if (isalpha(s[i+2]))
					{
					for (j=0; j<k; j++)
						if (s[i+2]==bu[j].b)
							y=bu[j].c;
							y*=-1;
					}
				else {y=atoi(&s[i+2]); y*=-1;}
				switch (s[i])
					{
					case '*':z=x*y; break;
					case '/':z=x/y; break;
					}
				x=z;
				i++;
				}

			}
		itoa(x,sp,10);
		strcat(s1,sp);
		n=strlen(s1);
		for (i=0; i<n; i++)
			{
			if (s1[i]=='+' && s1[i+1]=='-')
				{
				strncpy(so,s1,i);
				so[i]='\0';
				strcpy(s1,&s1[i+2]);
				strcat(so,"-");
				strcat(so,s1);
				strcpy(s1,so);
				}
			if (s1[i]=='-' && s1[i+1]=='-')
				{
				strncpy(so,s1,i);
				so[i]='\0';
				strcpy(s1,&s1[i+2]);
				strcat(so,"+");
				strcat(so,s1);
				strcpy(s1,so);
				}
			}
		if (s1[0]=='-') {x=atoi(&s1[1]); x*=-1;}
		else x=atoi(s1);
		strcpy(s1,&s1[1]);
		n=strlen(s1);
		for (i=0; i<n; i++)
			if (s1[i]=='+' || s1[i]=='-')
				{
				y=atoi(&s1[i+1]);
				switch (s1[i])
					{
					case '+':z=x+y; break;
					case '-':z=x-y; break;
					}
				x=z;
				}
		return x;
	}