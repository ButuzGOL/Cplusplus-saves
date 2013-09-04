# include <iostream.h>
# include <math.h>
# include <conio.h>
# include <iomanip.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
void dob(char*);
void ochis(char*);
void vivod(char*);
void ooo(char*);
struct igrok
	{
	char im[15],poz[10],sos[10];
	int srbal,grog,nastroi,nom;
	};
struct komanda
	{
	char strana[15],formacia[15],gltrener[15];
	int srbal,nastroi;
	igrok fboler[15];
	}klub;
void main ()
	{
	clrscr();
	randomize();
		//ochis("c:\\zbornaya.txt");
		//dob("c:\\zbornaya.txt");
		clrscr();
		ooo("c:\\zbornaya.txt");
		vivod("c:\\zbornaya.txt");
	getch();
	}
void dob(char *sl)
	{
	FILE *f;
	int i,l;
	float x=0;
	if ((f=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	fseek(f,0,2);
	cout<<"Vvedite stranu ";
	gets(klub.strana);

	cout<<"Vvedite formaciu ";
	gets(klub.formacia);

	cout<<"Vvedite imya gltrenera ";
	gets(klub.gltrener);

	for (i=0; i<15; i++)
		{
		cout<<endl;
		if (i==0) cout<<"Shas vvodite tex kto na pole (11)\n\n";
		if (i==11) cout<<"Shas vvodite tex kto zamena (4)\n\n";

		cout<<"   Vvedite Imya ";
		gets(klub.fboler[i].im);

		cout<<"   Vvedite God rogdenia ";
		cin>>klub.fboler[i].grog;
		klub.fboler[i].grog+=1900;

		cout<<"   Vvedite Nomer ";
		cin>>klub.fboler[i].nom;


		cout<<"   Vvedite poziciu "<<endl;
		cout<<"   1 Vratar  2 Zashitnik  3 Huvback  4 Forvard"<<endl;
		cout<<"   Vibereti iz vishe perechislenuh  ";
		cin>>l;
		if (l==1) strcpy(klub.fboler[i].poz,"Vratar");
		if (l==2) strcpy(klub.fboler[i].poz,"Zashitnik");
		if (l==3) strcpy(klub.fboler[i].poz,"Huvback");
		if (l==4) strcpy(klub.fboler[i].poz,"Forvard");

		klub.fboler[i].nastroi=random(3)+1;
		x+=klub.fboler[i].nastroi;
		if (i<11) l=1;
		else l=2;
		if (l==1) strcpy(klub.fboler[i].sos,"V pole");
		if (l==2) strcpy(klub.fboler[i].sos,"Na zamene");

		cout<<"   Vvedite Sr bal igroka ";
		cin>>klub.fboler[i].srbal;

		if (klub.fboler[i].nastroi==2) klub.fboler[i].srbal+=5;
		if (klub.fboler[i].nastroi==3) klub.fboler[i].srbal+=10;

		if (l==1) klub.srbal+=klub.fboler[i].srbal;
		}

	x/=15;
	if (x>=1 && x<=1.5) klub.nastroi=1;
	if (x>1.5 && x<=2.3) klub.nastroi=2;
	if (x>2.3 && x<=3) klub.nastroi=3;

	if (klub.nastroi==2) klub.srbal+=5;
	if (klub.nastroi==3) klub.srbal+=10;

	klub.srbal/=11;
	fwrite(&klub,sizeof(klub),1,f);
	fclose(f);
	}
void vivod(char*sl)
	{
	FILE *f;
	int x=4,y=10;
	if ((f=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		while(fread(&klub,sizeof (klub),1,f))
			{
			cout<<"Strana: ";
			puts(klub.strana);

			cout<<"Formacia: ";
			puts(klub.formacia);

			cout<<"Imya gltrenera: ";
			puts(klub.gltrener);

			cout<<"Nastroi: ";
			if (klub.nastroi==1) cout<<"Ploho";
			if (klub.nastroi==2) cout<<"Normalno";
			if (klub.nastroi==3) cout<<"Super";
			cout<<endl;
			cout<<"Sr Bal komandi: ";
			cout<<klub.srbal;

			cout<<endl;
			cout<<"Sostav:";


			for (int i=0; i<15; i++)
				{
				gotoxy(x,y++);
				cout<<"   Imya: ";
				puts(klub.fboler[i].im);

				gotoxy(x,y++);
				cout<<"   God rogdenia: ";
				cout<<klub.fboler[i].grog<<endl;

				gotoxy(x,y++);
				cout<<"   Nomer: ";
				cout<<klub.fboler[i].nom;

				gotoxy(x,y++);
				cout<<"   Pozicia: ";
				puts(klub.fboler[i].poz);

				gotoxy(x,y++);
				cout<<"   Nastroi: ";
				if (klub.fboler[i].nastroi==1) cout<<"Ploho"<<endl;
				if (klub.fboler[i].nastroi==2) cout<<"Normalno"<<endl;
				if (klub.fboler[i].nastroi==3) cout<<"Super"<<endl;


				gotoxy(x,y++);
				cout<<"   Sostoyanie: ";
				puts(klub.fboler[i].sos);

				gotoxy(x,y++);
				cout<<"   Sr bal igroka: ";
				cout<<klub.fboler[i].srbal;
				if (i==4 || i==9) {y=10; x+=25;}
				else y++;
				}
			getch();
			clrscr();
			x=4;y=10;
			}
		fclose(f);

	}
void ochis(char *sl)
	{
	FILE *f;
	if ((f=fopen(sl,"w+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	}
void ooo(char *sl)
	{
	FILE *f;
	float x;
	int i;
	if ((f=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		while(fread(&klub,sizeof (klub),1,f))
			{
			for (i=0,x=0; i<15; i++)
				x+=klub.fboler[i].nastroi;
			x/=15;
			if (klub.nastroi==2) klub.srbal-=5;
			if (klub.nastroi==3) klub.srbal-=10;

			if (x>=1 && x<=1.5) klub.nastroi=1;
			if (x>1.5 && x<=2.3) klub.nastroi=2;
			if (x>2.3 && x<=3) klub.nastroi=3;

			if (klub.nastroi==2) klub.srbal+=5;
			if (klub.nastroi==3) klub.srbal+=10;

			fseek(f,ftell(f)-sizeof(klub),0);
			fwrite(&klub,sizeof(klub),1,f);
			fseek(f,ftell(f),0);
			}
		fclose(f);
	}
