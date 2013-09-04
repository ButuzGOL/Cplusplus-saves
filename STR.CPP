# include <iostream.h>
# include <math.h>
# include <conio.h>
# include <iomanip.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
class str
	{
	private:
		char*S;

	public:
		str ()
			{
			S=new char[80];
			}
		str (char*x)
			{
			S=new char [strlen(x)+1];
			strcpy(S,x);
			}
		~ str()
			{
			delete[]S;
			}
		str operator = (char*S1)
			{
			strcpy(S,S1);
			return *this;
			}
		char operator [] (int i)
			{
			if (i>=1 && strlen(S)>0) return S[i-1];
			}
		void vvod()
			{
			cout<<"stroku:"<<endl;
			gets(S);
			}
		char* get_S() {return S;}
		void p()
			{
			puts(S);
			cout<<endl;
			}
		friend ostream&operator<<(ostream & S,str&x)
			{
			return S<<x.S;
			}
		friend istream&operator>>(istream &S,str&x)
			{
			char buf[256];
			S>>buf;
			x=buf;
			//cout<<"echo:"<<x<<"\n";
			return S;
			}
		int operator ==(str S01)
			{
			if (strcmp(S,S01.S)==0) return 1;
			else return 0;
			}
		int operator >(str S02)
			{
			if (strcmp(S,S02.S)<0) return 1;
			else return 0;
			}
		  //int len(str S);


		  int operator ||len(str S)
			return strlen(S);

		};
void main()
	{
clrscr();
	str s;
	s.vvod();
	s.p();

	str s1;
	/*s1="123456789";
	cout<<"Posle=:"<<endl;
	s1.p();
	cout<<s1[3]<<endl;
	*/

	str s2;
	cout<<"stroka:"<<endl;
	cin>>s2;
	s2.p();

	s1=s;
	cout<<s1<<endl;
	if (s==s2) cout<<"Stroki ravny"<<endl;
	else cout<<"Stroki ne ravny"<<endl;

	if (s>s2) cout<<"1 stroka >"<<endl;
	else cout<<"2 stroka >"<<endl;
	s.p();
	//cout<<"Dlina ="<<len(s)<<endl;

getch();
	  }