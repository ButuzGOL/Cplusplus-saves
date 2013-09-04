# include <iostream.h>
# include <math.h>
# include <conio.h>
# include<iomanip.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
class komplex {
	      private:
	       int Re;
	       int Im;
	      public:
	       komplex(int R=0,int I=0){
		       Re=R; Im=I;}
	       int get_Re() {return Re;}
	       int get_Im() {return Im;}
	       komplex operator+(komplex C2){komplex C3;
					     C3.Re=Re+C2.Re;
					     C3.Im=Im+C2.Im;
					     return C3;
					     }
	      };
void main() {clrscr();
	     komplex c1(2,5);
	     cout<<c1.get_Re();
	     cout<<" + i"<<c1.get_Im()<<endl;
	     komplex c2(6,7);
	     cout<<c2.get_Re();
	     cout<<" + i"<<c2.get_Im()<<endl;
	     komplex c3=c1+c2;
	     cout<<"summa="<<c3.get_Re()<<"+"<<c3.get_Im();
	     getch();
	     }