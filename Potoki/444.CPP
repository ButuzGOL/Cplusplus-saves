#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<graphics.h>
void main(){ clrscr();
     char s[80];
    ifstream f;
  f.open("e:\\111\\potoki\\111.txt");
  if (!f) {cerr<<"Owubka"; return;}
  char simb,last,next;
  ofstream f1,f2;
  int n=0;
  f1.open("e:\\111\\potoki\\123.txt",ios::ate);
  f2.open("e:\\111\\potoki\\124.txt",ios::app);
  cin.get();
  while (f.get(simb)){n++;
  if (simb=='\n') n=0;
  if (simb!='/')  f1.put(simb);
  else {if (!f.get(next)) break;
  if (next=='/')
    {if (n!=1) f1.put('\n');
    f2.put(simb);
    f2.put(next);
    do {
    f.get(simb);
    f2.put(simb); }
      while (simb!='\n');}
    else { f1.put(simb);
	   f1.put(next); }}}

getch();}