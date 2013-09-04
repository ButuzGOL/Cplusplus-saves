# include <iostream.h>
# include <math.h>
# include <conio.h>
# include <iomanip.h>
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

	       komplex operator+(komplex C2)
					     {
					     komplex C3;
					     C3.Re=Re+C2.Re;
					     C3.Im=Im+C2.Im;
					     return C3;
					     }
	       komplex operator*(komplex C2)
					     {
					     komplex C4;
					     C4.Re=Re*C2.Re;
					     C4.Im=Im*C2.Im;
					     return C4;
					     }
	       int operator==(komplex C2)
					     {
					     if (Re==C2.Re && Im==C2.Im) return 1;
					     else return 0;
					     }


	       void vivod()
			{
			cout<<Re;
			cout<<" + i"<<get_Im()<<endl;
			}
	      };
void main()
	{
	clrscr();
	komplex c1(2,5);
	komplex c2(6,7);
	komplex c3=c1+c2;
	komplex c4=c1*c2;
	c1.vivod();
	c2.vivod();
	c3.vivod();
	c4.vivod();
	if (c1==c2) cout<<1;
	else cout<<0;
getch();
	}
