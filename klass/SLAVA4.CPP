#include<iomanip.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
class tdid
	{
	int count,*data;
	char text[80];
	public:
		tdid(int c);
		~tdid();
		void filldata();
		void fillprint();
	};
	tdid::tdid(int c)
		{
		count=c;
		data=new int[c];
		}
	tdid::~tdid() {delete []data;}
	void tdid::filldata()
		{
		char s[80];
		strcpy(text,"");
		strcpy(s,"");

		for (int i=0; i<count; i++)
			{
			data[i]=pow(2,i);
			itoa(data[i],s,10);
			strcat(text,s);
			if (i<(count-1)) strcat(text,",");
			else strcat(text,".");
			}

		}
	void tdid::fillprint()
		{
		puts(text);
		}

void main()
	{
clrscr();
	tdid t(10);
	t.filldata();
	t.fillprint();
	tdid t1();
getch();
	}