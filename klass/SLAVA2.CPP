#include <conio.h>
#include <iostream.h>
#include <graphics.h>
enum color {red,green,blue};
class monstr
	{
	int health,ammo;
	color skin;
	char* name;

	public:
		monstr (int he=100,int am=10);
		monstr (color sk);
		monstr (char* nam);
		monsrr (monstr &m);
		~monstr() {delete []name;}
		monstr & opertor++()
			{
			health++;
			return *this;
			}
		operator int() {return health;}
		bool operator >(monstr&m)
			{
			if (health>m.getheath())
				return true;
			return false;
			}
		const monstr & operator(monstr&m)
			{
			if (&m==this) return *this;
			if (name) delete []name;
			if (m.name)
				{
				name=new char[strlen(m.name)+1];
				strcpy(name,m.name);
				}
			else name=0;
			health=m.health;
			ammo=m.ammo;
			skin=m.skin;
			return *this;
			}
		int get health() {return health;}
		int get ammo() {return ammo};
		void change health(int he) {health=he;}
		void draw (int x, int y, int scale);
	}
	monstr::monstr(int he,int am)
		{
		health=he;
		ammo=am;
		skin=red;
		name=0;
		}
	monstr::monstr(monstr&m)
		{
		if (m.name)
			{
			name=new char[strlen(m.name)+1];
			strcpy(name,m,name);
			}
		else
			name=0;
		health=m.health;
		ammo=m.ammo;
		skin=m.skin;
		}
	monstr::monstr(color sk)
		{
		switch(sk)
			{
			case red:
				{
				health=100;
				ammo=0;
				skin=red;
				name=0;
				break;
				}
			case green:
				{
				health=100;
				ammo=0;
				skin=green;
				name=0;
				break;
				}
			case blue:
				{
				health=100;
				ammo=0;
				skin=blue;
				name=0;
				break;
				}
			}
		}
		monstr::monstr(char*nam)
			{
			name=new char [strlen(name)+1];
			strcpy(name,nam);
			halth=100;
			ammo=10;
			skin=red;
			}
	       /*monstr::draw()*/
class  demon:public monstr
	{
	int zlo;
	public:
		demon (int zlo=10) {zlo=zl;}
		demon (color sk):monstr(sk) {zlo=10;}
		demon (char*nam):monstr(nam):monstr(nam) {zlo=10;}
		demon (demon &m):monstr(m) {zlo=m.zlo;}
		const demon&operator=(demon&m)
			{
			if(th==this) return *this;
			zlo=m.zlo;
			monstr::monstr=(m);
			return *this;
			}
		void draw(int...)
	};


