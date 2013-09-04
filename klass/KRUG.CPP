#include <conio.h>
#include <iostream.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>
class crug
	{
	int x,y,r,c;
	public:
	crug(int xx,int yy,int rr,int cc);
	~crug();
	void draw();
	void clear();
	void move(int dx,int dy);
	};
	crug::crug(int xx,int yy,int rr,int cc)
		{
		x=xx;
		y=yy;
		r=rr;
		c=cc;
		}
	crug::~crug()
		{
		clear();
		}
	void crug::draw()
		{
		setcolor(c);
		circle(x,y,r);
		}
	void crug::clear()
		{
		setcolor(getbkcolor());
		circle(x,y,r);
		}
	void crug::move(int dx,int dy)
		{
		clear();
		x+=dx;
		y+=dy;
		draw();
		}
class barr
	{
	int x,y,x1,y1,c;
	public:
	barr(int xx,int yy,int xx1,int yy1,int cc);
	~barr();
	void draw();
	void clear();
	void move(int dx,int dy,int dx1,int dy1);
	};
	barr::barr(int xx,int yy,int xx1,int yy1,int cc)
		{
		x=xx;
		y=yy;
		x1=xx1;
		y1=yy1;
		c=cc;
		}
	barr::~barr()
		{
		clear();
		}
	void barr::draw()
		{
		setcolor(c);
		rectangle(x,y,x1,y1);
		}
	void barr::clear()
		{
		setcolor(getbkcolor());
		rectangle(x,y,x1,y1);
		}
	void barr::move(int dx,int dy,int dx1,int dy1)
		{
		clear();
		x+=dx;
		y+=dy;
		x1+=dx1;
		y1+=dy1;
		draw();
		}

void main()
	{
	const ss=1;
	int a=0,b,d=100,dd=100,i,l=1,ll=1,m=1,mm=260;
	char k;
	crug c(d,dd,15,4);
	barr br(200,450,mm,479,5);

	initgraph(&a,&b,"c:\\borlandc\\bgi");

	do
		{
		if (d==624) l=(-1)*ss;
		if (d==15) l=ss;
		//if (dd==464) ll=(-1)*ss;
		if (dd==15) ll=ss;



			if (kbhit ())
				{
				k=getch();
				if (k=='l' && mm<640) m=ss;
				if (k=='k'&& mm>60) m=(-1)*ss;
				}

			if (mm==639) m=(-1)*ss;
			if (mm==60) m=ss;



		if ((mm-60)<(d+15) && (mm-60)>d && dd<450 && (dd+15)>450) {l=(-1)*ss; ll=(-1)*ss;}
		if (mm>(d-15) && mm<d && dd<450 && (dd+15)>450) {l=ss;ll=(-1)*ss;}

		if ((dd+15)==450 && ((mm-60)<d && mm>d)) ll=(-1)*ss;
		if ((d+16)==(mm-60) && (dd>450 && dd<479)) l=(-1)*ss;
		if ((d-16)==mm && (dd>450 && dd<479)) l=ss;


		delay(5);
		c.move(l,ll);

		if (l==ss && ll==ss) {d+=ss; dd+=ss;}
		if (l==ss && ll==(-1)*ss) {d+=ss; dd-=ss;}
		if (l==(-1)*ss && ll==(-1)*ss) {d-=ss; dd-=ss;}
		if (l==(-1)*ss && ll==ss) {d-=ss; dd+=ss;}

		br.move(m,0,m,0);

			if (m==ss) mm+=ss;
			if (m==(-1)*ss) mm-=ss;

		}
	while (k!='s');
	}
