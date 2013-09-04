# include<conio.h>
# include<math.h>
# include<iostream.h>
# include<stdlib.h>
# include<string.h>
# include<stdio.h>
# include <ctype.h>
struct perem
	{
	char name;
	int zn;
	};
void main()
	{
clrscr();
	char *s=new char[80];
	char *s2=new char[80];
	char *ss=new char[80];
	char a[50];
	int i,n,x,zn,y,r,kol=0,b,j,m;

		strcpy(s2,"");
		gets(s);
		if (s[0]=='+'||s[0]=='*'||s[0]=='/')
			{
			cout<<"Первый символ - недопустимый знак"<<endl;
			return;
			}
		n=strlen(s);
		for (i=0;i<n;i++)
			{
			if (!isalpha(s[i]) && !isdigit(s[i]) && (s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'))
				{
				cout<<"Неправильный символ "<<s[i]<<endl;
				return;
				}
			if ((s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/') && (s[i+1]=='+'||s[i+1]=='-'||s[i+1]=='*'||s[i+1]=='/'))
				{
				cout<<"Два знака подряд"<<endl;
				return;
				}
			if (isalpha(s[i])&&isalpha(s[i+1]))
				{
				cout<<"Две буквы подряд"<<endl;
				return;
				}
			}
		if (s[n-1]=='+'||s[n-1]=='*'||s[n-1]=='/')
			{
			cout<<"Последний символ - знак"<<endl;
			return;
			}
		//cout<<"Все ОК!"<<endl;


		kol=0;
		for (i=0;i<n;i++)
			{
			if (isalpha(s[i]))
				{
				m=0;
				for (j=0;j<i;j++)
					if (s[j]==s[i]) m++;
				if (m==0) kol++;
				}
			}

	    // cout<<"Кол-во="<<kol<<endl;

	perem *k=new perem [kol];
	int l=0;

		for (i=0;i<n;i++)
			{
			if (isalpha(s[i]))
				{
				m=0;
				for (j=0;j<i;j++)
					if (s[j]==s[i]) m++;
				if (m==0)
					{
					k[l].name=s[i];
					l++;
					}
				}
			}
		if (kol>0) cout<<"Введите значение переменных:"<<endl;
			for (b=0;b<kol;b++)
				{
				cout<<k[b].name<<": ";
				cin>>k[b].zn;
				}

		if (isalpha(s[0]))
			for (b=0;b<kol;b++)
				if (s[0]==k[b].name) x=k[b].zn;
		else x=atoi(s);

		for (i=0;i<n;i++)
			{
			if (s[i]=='*' || s[i]=='/')
				{
				if (isalpha(s[i+1]))
					for (b=0;b<kol;b++)
						if (s[i+1]==k[b].name) y=k[b].zn;
				else y=atoi(&s[i+1]);

				if (s[i]=='*')
					r=x*y;
				if (s[i]=='/')
					r=x/y;
				x=r;
				}

			if (s[i]=='+' || s[i]=='-')
				{
				itoa(x,ss,10);
				strcat(s2,ss);
				if (s[i]=='+')
					strcat(s2,"+");
				if (s[i]=='-')
					strcat(s2,"-");
				x=atoi(&s[i+1]);
				}
			}

		itoa(x,ss,10);
		strcat(s2,ss);
		//puts(s2);
		r=0;
		x=atoi(s2);
		for (i=0;i<strlen(s2);i++)
			{
			if (s2[i]=='+' || s2[i]=='-')
				if (isalpha(s2[i+1]))
					for (b=0;b<kol;b++)
						if (s2[i+1]==k[b].name) y=k[b].zn;
				else y=atoi(&s2[i+1]);
			if (s2[i]=='+')
				r=x+y;
			if (s2[i]=='-')
				r=x-y;
			x=r;
			}
		strcat(s2,"=");
		itoa(r,ss,10);
		strcat(s2,ss);
		puts(s2);
getch();
	}
