# include <iostream.h>
# include <math.h>
# include <conio.h>
# include <iomanip.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
int nod(int,int);
int nok(int,int);
class drobi {
	      private:
	       int ce;
	       int zn;
	      public:
	       drobi(int c=0,int z=0)
			{
		       ce=c; zn=z;}
	       int get_ce() {return ce;}
	       int get_zn() {return zn;}

	       drobi operator+(drobi c2)
					     {
					     drobi c3;
					     int i,l,k1,k2;


					     if (zn>c2.zn) l=zn;
					     else l=c2.zn;
					     for (i=l; (!(i%zn==0 && i%c2.zn==0)); i++);

					     k1=i/zn*ce;
					     k2=i/c2.zn*c2.ce;

					     c3.ce=k1+k2;
					     c3.zn=i;

					     if (c3.ce>c3.zn) l=c3.zn;
					     else l=c3.ce;

					     for (i=l; (i!=1 || l!=1); i--)
					     if (c3.ce%i==0 && c3.zn%i==0) {c3.ce/=i; c3.zn/=i; break;}

					     return c3;
					     }
	       drobi operator-(drobi c2)
					     {
					     drobi c4;
					     int i,l,k1,k2;

					     if (zn>c2.zn) l=zn;
					     else l=c2.zn;
					     for (i=l; (!(i%zn==0 && i%c2.zn==0)); i++);

					     k1=i/zn*ce;
					     k2=i/c2.zn*c2.ce;

					     c4.ce=k1-k2;
					     c4.zn=i;

					     if (c4.ce>c4.zn) l=c4.zn;
					     else l=c4.ce;

					     for (i=l; (i!=1 || l!=1); i--)
					     if (c4.ce%i==0 && c4.zn%i==0) {c4.ce/=i; c4.zn/=i; break;}

					     return c4;
					     }
	       drobi operator-()
					     {
					     drobi c6;
					     c6.ce=-ce;
					     c6.zn=zn;
					     return c6;
					     }


	       drobi operator*(drobi c2)
					     {
					     drobi c5;
					     int i,l;

					     c5.ce=ce*c2.zn;
					     c5.zn=zn*c2.ce;

					     if (c5.ce>c5.zn) l=c5.zn;
					     else l=c5.ce;

					     for (i=l; (i!=1 || l!=1); i--)
					     if (c5.ce%i==0 && c5.zn%i==0) {c5.ce/=i; c5.zn/=i; break;}

					     return c5;
					     }
	       drobi operator/(drobi c2)
					     {
					     drobi c7;
					     int i,l;

					     c7.ce=ce*c2.zn;
					     c7.zn=zn*c2.ce;

					     if (c7.ce>c7.zn) l=c7.zn;
					     else l=c7.ce;

					     for (i=l; (i!=1 || l!=1); i--)
					     if (c7.ce%i==0 && c7.zn%i==0) {c7.ce/=i; c7.zn/=i; break;}

					     return c7;
					     }

	       int operator==(drobi c2)
					     {
					     int i,l,k1,k2;

					     if (zn>c2.zn) l=zn;
					     else l=c2.zn;
					     for (i=l; (!(i%zn==0 && i%c2.zn==0)); i++);

					     k1=i/zn*ce;
					     k2=i/c2.zn*c2.ce;

					     if (k1==k2) return 1;
					     else return 0;
					     }
	       int operator>(drobi c2)
					     {
					     int i,l,k1,k2;

					     if (zn>c2.zn) l=zn;
					     else l=c2.zn;
					     for (i=l; (!(i%zn==0 && i%c2.zn==0)); i++);

					     k1=i/zn*ce;
					     k2=i/c2.zn*c2.ce;

					     if (k1>k2) return 1;
					     else return 0;
					     }
	       int operator<(drobi c2)
					     {
					     int i,l,k1,k2;

					     if (zn>c2.zn) l=zn;
					     else l=c2.zn;
					     for (i=l; (!(i%zn==0 && i%c2.zn==0)); i++);

					     k1=i/zn*ce;
					     k2=i/c2.zn*c2.ce;

					     if (k1<k2) return 1;
					     else return 0;
					     }




	       void vivod()
			{
			cout<<ce;
			cout<<" + i"<<get_zn()<<endl;
			}
	      };
void main()
	{
	clrscr();
	drobi c1(5,3);
	drobi c2(3,6);
	c1.vivod();
	c2.vivod();

	/*drobi c3=c1+c2;
	c3.vivod();

	drobi c4=c1-c2;
	c4.vivod();

	drobi c6=-c1;
	c6.vivod();

	drobi c5=c1*c2;
	c5.vivod();

	drobi c7=c1/c2;
	c7.vivod();*/


	if (c1<c2) cout<<1;
	else cout<<0;
getch();
	}
int nod(int a,int b)
	{
	int i,l;
	if (a>b) l=b;
	else l=a;
	for (i=l; (i!=1 || l!=1); i--)
	if (a%i==0 && b%i==0) return i;
	}
int nok(int a,int b)
	{
	int i,l;
	if (a>b) l=a;
	else l=b;
	for (i=l; (!(i%a==0 && i%b==0)); i++);
	return i;
	}

