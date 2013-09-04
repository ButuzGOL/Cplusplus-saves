#include <iostream.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
void main()
	{
clrscr();

	char c;
	do
		{
		if (kbhit ())
			{
			c=getch();
			if (c==72) cout<<"FOg";
			}
		}
	while (c=='a');
getch();
	}
