#include <conio.h>
#include <iostream.h>
#include <graphics.h>
class crug
	{
	int x,y,c;
	public:
	crug(int xx,int yy,int cc);
	~crug();
	void draw();
	void clear();
	void move(int dx,int dy);
	};
	crug::crug(int xx,int yy,int cc)
		{
		x=xx;
		y=yy;
		c=cc;
		}
	crug::~crug()
		{
		clear();
		}
	void crug::draw()
		{
		circle(x,y,c);
		}
	void crug::clear()
		{
		circle(x,y,getbkcolor());
		}
	void crug::move(int dx,int dy)
		{
		clear();
		x+=dx;
		y+=dy;
		draw();
		}
void main()
	{
	int a=0,b;
	initgraph(&a,&b,"c:\\borlandc\\bgi");
	crug c(100,100,15);
	c.draw();
	getch();
	c.move(100,100);
	getch();
	}
