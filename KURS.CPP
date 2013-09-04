# include <iostream.h>
# include <math.h>
# include <conio.h>
# include <iomanip.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
void dob(char*);
void redigr(char*,char*,char*);
void redkom(char*,char*);
void ochis(char*);

void vivod(char*);
void vivodim(char*,char*);
void vivodigr(char*,char*);
void vivodpoz(char*,char*);


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
		//vivodim("d:\\zbornaya.txt","Italy");
		//vivodigr("d:\\zbornaya.txt","Zidane");
		//redigr("d:\\zbornaya.txt","France","Zidane");
		//redkom("d:\\zbornaya.txt","Italy");
		//vivodim("d:\\zbornaya.txt","Italy");
		vivod("c:\\zbornaya.txt");
		//vivodpoz("c:\\zbornaya.txt","Vratar");
	getch();
	}
void dob(char *sl)
	{
	FILE *f;
	int i,l;
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

	/*cout<<"Vvedite nastroi"<<endl;
	cout<<"1 Ploho  2 Normalno  3 Super"<<endl;
	cout<<"Vibereti iz vishe perechislenuh  ";
	*/
	klub.nastroi=random(3)+1;

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

		/*cout<<"   Vvedite nastroi"<<endl;
		cout<<"   1 Ploho  2 Normalno  3 Super"<<endl;
		cout<<"   Vibereti iz vishe perechislenuh  ";
		*/
		klub.fboler[i].nastroi=random(3)+1;

		/*cout<<"   Vvedite sostoyanie"<<endl;
		cout<<"   1 V pole  2 Na zamena "<<endl;
		cout<<"   Vibereti iz vishe perechislenuh  ";
		*/
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
void vivodim(char*sl,char*s)
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
			if (strcmp(s,klub.strana)==0)
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
					cout<<endl<<endl;
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
			}
			fclose(f);

	}
void vivodigr(char*sl,char*s)
	{
	FILE *f;

	if ((f=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}

		while(fread(&klub,sizeof (klub),1,f))
			for (int i=0; i<15; i++)
				if (strcmp(s,klub.fboler[i].im)==0)
					{
					cout<<"Strana: ";
					puts(klub.strana);

					cout<<endl;
					cout<<"   Imya: ";
					puts(klub.fboler[i].im);

					cout<<"   God rogdenia: ";
					cout<<klub.fboler[i].grog<<endl;

					cout<<"   Nomer: ";
					cout<<klub.fboler[i].nom;

					cout<<endl;
					cout<<"   Pozicia: ";
					puts(klub.fboler[i].poz);


					cout<<"   Nastroi: ";
					if (klub.fboler[i].nastroi==1) cout<<"Ploho"<<endl;
					if (klub.fboler[i].nastroi==2) cout<<"Normalno"<<endl;
					if (klub.fboler[i].nastroi==3) cout<<"Super"<<endl;

					cout<<"   Sostoyanie: ";
					puts(klub.fboler[i].sos);


					cout<<"   Sr bal igroka: ";
					cout<<klub.fboler[i].srbal;
					}
			getch();
			clrscr();
		fclose(f);
	}
void redigr(char *sl,char *s,char *s1)
	{
	FILE *f;
	int i,l,x=2;
	if ((f=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
			while(fread(&klub,sizeof (klub),1,f))
				if (strcmp(s,klub.strana)==0)
					for (int i=0; i<15; i++)
						if (strcmp(s1,klub.fboler[i].im)==0)
							{
							while (x)
								{
								clrscr();
								cout<<"1.Hotite izmenit imya?\n";
								cout<<"2.Hotite izmenit datu rogdeniya?\n";
								cout<<"3.Hotite izmenit nomer?\n";
								cout<<"4.Hotite izmenit poziciu?\n";
								cout<<"5.Hotite izmenit nastroi?\n";
								cout<<"6.Hotite izmenit sostoyanie?\n";
								cout<<"7.Hotite izmenit sr bal?\n";
								cout<<"0.Vihod\n";
								cin>>x;
								switch (x)
									{
									case 1:	cout<<"Vvedite imya ";
										gets(klub.fboler[i].im);
										break;

									case 2: cout<<"Vvedite God rogdenia ";
										cin>>klub.fboler[i].grog;
										klub.fboler[i].grog+=1900;
										break;

									case 3: cout<<"Vvedite nomer ";
										cin>>klub.fboler[i].nom;
										break;

									case 4: cout<<"Vvedite poziciu "<<endl;
										cout<<"1 Vratar  2 Zashitnik  3 Huvback  4 Forvard"<<endl;
										cout<<"Vibereti iz vishe perechislenuh  ";
										cin>>l;
										if (l==1) strcpy(klub.fboler[i].poz,"Vratar");
										if (l==2) strcpy(klub.fboler[i].poz,"Zashitnik");
										if (l==3) strcpy(klub.fboler[i].poz,"Huvback");
										if (l==4) strcpy(klub.fboler[i].poz,"Forvard");
										break;

									case 5: if (klub.fboler[i].nastroi==2) klub.fboler[i].srbal-=5;
										if (klub.fboler[i].nastroi==3) klub.fboler[i].srbal-=10;
										cout<<"Vvedite nastroi"<<endl;
										cout<<"1 Ploho  2 Normalno  3 Super"<<endl;
										cout<<"Vibereti iz vishe perechislenuh  ";
										cin>>klub.fboler[i].nastroi;
										if (klub.fboler[i].nastroi==2) klub.fboler[i].srbal+=5;
										if (klub.fboler[i].nastroi==3) klub.fboler[i].srbal+=10;
										break;

									case 6: cout<<"Vvedite sostoyanie"<<endl;
										cout<<"1 V pole  2 Na zamena "<<endl;
										cout<<"Vibereti iz vishe perechislenuh  ";
										cin>>l;
										if (l==1) strcpy(klub.fboler[i].sos,"V pole");
										if (l==2) strcpy(klub.fboler[i].sos,"Na zamene");
										break;

									case 7: if (strcmp(klub.fboler[i].sos,"V pole")==0) klub.srbal-=(klub.fboler[i].srbal/11);
										cout<<"Vvedite Sr bal igroka ";
										cin>>klub.fboler[i].srbal;
										if (klub.fboler[i].nastroi==2) klub.fboler[i].srbal+=5;
										if (klub.fboler[i].nastroi==3) klub.fboler[i].srbal+=10;
										if (strcmp(klub.fboler[i].sos,"V pole")==0) klub.srbal+=(klub.fboler[i].srbal/11);
										break;
									}

								}
							fseek(f,ftell(f)-sizeof(klub),0);
							fwrite(&klub,sizeof(klub),1,f);
							}
				fclose(f);
	}
void redkom(char *sl,char *s)
	{
	FILE *f;
	int i,l,x=2;
	if ((f=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
			while(fread(&klub,sizeof (klub),1,f))
				if (strcmp(s,klub.strana)==0)
					{
					while (x)
						{
						clrscr();
						cout<<"1.Hotite izmenit stranu?\n";
						cout<<"2.Hotite izmenit formacia?\n";
						cout<<"3.Hotite izmenit imya gltrenera?\n";
						cout<<"4.Hotite izmenit nastroi?\n";
						cout<<"0.Vihod\n";
						cin>>x;
						switch (x)
							{
							case 1:	cout<<"Vvedite stranu ";
								gets(klub.strana);
								break;

							case 2: cout<<"Vvedite formaciu ";
								gets(klub.formacia);
								break;

							case 3: cout<<"Vvedite imya gltrenera ";
								gets(klub.gltrener);
								break;

							case 4: if (klub.nastroi==2) klub.srbal-=5;
								if (klub.nastroi==3) klub.srbal-=10;
								cout<<"Vvedite nastroi"<<endl;
								cout<<"1 Ploho  2 Normalno  3 Super"<<endl;
								cout<<"Vibereti iz vishe perechislenuh  ";
								cin>>klub.nastroi;
								if (klub.nastroi==2) klub.srbal+=5;
								if (klub.nastroi==3) klub.srbal+=10;

								break;
							}
						}
					fseek(f,ftell(f)-sizeof(klub),0);
					fwrite(&klub,sizeof(klub),1,f);
					}
				fclose(f);
	}
void vivodpoz(char*sl,char*s)
	{
	FILE *f;
	int x=2,y=2,k=0;
	if ((f=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		gotoxy(2,2);
		cout<<"Imya";
		gotoxy(22,2);
		cout<<"Strana";
		gotoxy(42,2);
		cout<<"Nomer";
		gotoxy(62,2);
		cout<<"Sr bal";
                y++;
		while(fread(&klub,sizeof (klub),1,f))
			for (int i=0; i<15; i++)
				if (strcmp(s,klub.fboler[i].poz)==0)
					{
					y++;
					gotoxy(x,y);
					puts(klub.fboler[i].im);

					gotoxy(x+=20,y);
					puts(klub.strana);

					gotoxy(x+=20,y);
					cout<<klub.fboler[i].nom;

					gotoxy(x+=20,y);
					cout<<klub.fboler[i].srbal;
					x=2;
				       //if (k==9 || k==18) {y=5; x+=25;}
				       //if (k==27) {getch(); clrscr(); y=5; x=2; k=0;}
                                        }
			getch();
			clrscr(); 
		fclose(f);
	}
