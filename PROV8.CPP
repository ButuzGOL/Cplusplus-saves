#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <iomanip.h>
#include <graphics.h>

void main() 	{
clrscr();
		int nn,n,k;

                cin>>n;
		for(nn=n,k=0; nn!=0; k++,nn/=10);

		int *c=new int [k];

		for(c[k--]=0; k>0; k--,n/=10)
			{
			c[k]=n%10+'0';
			cout<<c[k]<<"\n";
			}


getch();
		}
