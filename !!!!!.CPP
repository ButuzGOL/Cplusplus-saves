# include<conio.h>
# include<math.h>
# include<iostream.h>
# include<stdlib.h>
# include<string.h>
# include<stdio.h>
# include<ctype.h>
void main()
	{
clrscr();
	char *s=new char[80];
	char *s1=new char[80];
	char *s2=new char[80];
	int i,g,n,a,c,p,j,d;
	char zn;

		gets(s);
		n=strlen(s);

		if ((s[0]=='+'||s[0]=='*'||s[0]=='/')||(s[n-1]=='+'||s[n-1]=='*'||s[n-1]=='/'))
			return;
		for (i=0;i<n;i++)
			{
			if (!isalpha(s[i]) && !isdigit(s[i]) && (s[i]!='+'||s[i]!='-'||s[i]!='*'||s[i]!='/'))
				{
				cout<<"Nepravelnui simvol "<<s[i]<<endl;
				return;
				}

			if ((s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/') && (s[i+1]=='+'||s[i+1]=='-'||s[i+1]=='*'||s[i+1]=='/'));
				{
				cout<<"Dva znaka podrad"<<endl;
				return;
				}

			if (isalpha(s[i])&&isalpha(s[i+1]))
				{
				cout<<"Dve bukvi podrad"<<endl;
				return;
				}
			if (isalpha(s[i])&&isdigit(s[i+1]))|| (isdigit(s[i])&&isalpha(s[i+1]))
				{
				cout<<"Cifra i bukva podrad"<<endl;
				return;
				}
			}

	       //	cout<<"YO MaN SO ON"<<endl;

		for (i=0,p=0; i<n; i++)
			{
			if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
				{
				strncpy(s1,s,i-p);
				s1[i-p]='\0';
				zn=s[i];
				for(j=i; j<n; j++)
					{
					if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
						{
						d=j;
						break;
						}
					}
				strncpy(s2,s,j-i);
				s2[j-i]='\0';
				a=atoi(s1);
				c=atoi(s2);
				if (zn=='-') {g=a-c; a=g;}
				if (zn=='+') {g=a+c; a=g;}
				if (zn=='*') {g=a*c; a=g;}
				if (zn=='/') {g=a/c; a=g;}
				p=i;
			}
		  }
		  cout<<"znachenie virazenia="<<a;
       getch();
	      }
