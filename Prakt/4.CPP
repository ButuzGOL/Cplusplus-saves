#include<iostream.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>

void main()
	{
  clrscr();
  int n,i;
  float s;
	cin>>n;
	for (i=1; i<=n; i++)
		s+=pow(-1,i)*(i-1/i);
	cout<<s;
  getch();
	}
