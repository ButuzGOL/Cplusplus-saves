#include <string.h>
#include <iomanip.h>
#include <conio.h>


class tovar
	{
	char name[25];
	float price;
	char diler[25];
	public:
		tovar(char*nam,float pri,char*dil)
			{
			strcpy(name,nam);
			price=pri;
			strcpy(diler,dil);
			}
		virtual void print(){cout<<name<<" ";}
	};
class proc:public tovar
	{
	int speed;
	public:
		proc(int sp,char*nam,float pri,char*dil):tovar(nam,pri,dil)
			{speed=sp;}
		virtual void print()
			{
			tovar::print();
			cout<<speed<<endl;
			}
	};
class ozu:public tovar
	{
	int v;
	public:
		ozu(int vv,char*nam,float pri,char*dil):tovar(nam,pri,dil)
			{v=vv;}
		virtual void print()
			{
			tovar::print();
			cout<<v<<endl;
			}
	};
void main()
	{
clrscr();

	tovar *t[4];
	t[0]=new proc(2000,"Monitor",3.200,"Nbis");
	t[1]=new proc(1000,"MISH",2.200,"Nbis");
	t[2]=new ozu(500,"Klava",4.200,"Nbis");
	t[3]=new ozu(150,"Kover",1.200,"Nbis");

		for (int i=0;i<4; i++)
			t[i]->print();
getch();
	}
