# include <iostream.h>
# include <math.h>
# include <conio.h>
# include <iomanip.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <dir.h>
# include <graphics.h>

char sl[40]="c:\\uefa06\\zbornaya.txt",
     sl1[40]="c:\\uefa06\\gruppi.txt",
     sl2[20]="c:\\uefa06\\18.txt",
     sl3[20]="c:\\uefa06\\14.txt",
     sl4[20]="c:\\uefa06\\12.txt",
     sl5[20]="c:\\uefa06\\f.txt",
     sl6[20]="c:\\uefa06\\tr.txt",
     sl7[20]="c:\\uefa06\\save.txt",
     sl8[40]="c:\\uefa06\\zbornay1.txt";

void msave(int);
int  rsave();
void copyf();

void sozdtt(char*);
void vivodtt(char*);
void ogtt();
void sorttt();
void pvtt(char*);
void diagro();
void diagrzg();

int win(char*,char*);
int lose(char*,char*);

void sozdpg(char*,char*);
void psozdpg(char*);

void vivodpg(char*);
void ipg(char*);

void uvkg(char*);

char* sigri(int,int);

void gsozds(char*);
void gvivods();
void gochiss();
void fgi(int);
void sortsg();
void sm();
void sspfg(char*);

void sogruppi(char*);
void vvgruppi(char*);
void vv1gruppi(char*,char*);

void sozds(char*);
void ochiss();
void vivods();
void sortsb();
void sortsi();
void sortss(char*);
void udalsn(char*);
void sspf(char*);

void dob(char*);
void redigr(char*,char*);
void redkom(char*,char*);
void zamena(char*,char*);
void ochis(char*);

void vivod(char*);
void vivodim(char*,char*);
void vivodigr(char*,char*);
void vivodpoz(char*,char*);

void menu();
void menuv();
void menur();
void menuv2();
void menuvp();
void menugr(int);
void menuvb(int);
void menuzg(int);

void vivmenu(int);
void redmenu(int);
void grvmenu();

void me1g(int);
void me2g(int);
void me3g(int);
void me4g(int);
void me18(int);
void me14(int);
void me12(int);
void mefinal(int);
void mefirst();

void vivodtn(char*);
void vivodti(char*,char*);

char* vibor(char*,int);
char* vibor1(char*,char*,int);
char* oprc();
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

struct skomanda
	{
	komanda k;
	skomanda *next;
	};
	skomanda *first=0,*last=0,*c,*c1;

struct vgruppi
	{
	char str[15];
	int o,zg,pg,po,pr,n,is,srbal,nk;
	};
struct gruppi
	{
	char nazg[3];
	vgruppi vgr[4];
	}gr;

struct turtab
	{
	char str[15];
	int o,zg,pg,po,pr,n,is;
	}tr;
struct sturtab
	{
	turtab t;
	sturtab *next;
	};
	sturtab *fir=0,*las=0,*cc,*cc1;


struct sgruppi
	{
	gruppi g;
	sgruppi *next1;
	};
	sgruppi *first1=0,*last1=0,*c2,*c3;

struct chtv
	{
	char str[15];
	int srbal,kg;
	}ch[2],pf[2];

void main()
	{
	clrscr();
	randomize();
	mefirst();
	}
void copyf()
	{
	FILE *f,*f1;

		if ((f=fopen(sl8,"r+b"))==0)
			{
			cout<<"Oshibka1";
			return;
			}

		if ((f1=fopen(sl,"w+b"))==0)
			{
			cout<<"Oshibka2";
			return;
			}

		while(fread(&klub,sizeof (klub),1,f))
			fwrite(&klub,sizeof(klub),1,f1);


	fclose(f);
	fclose(f1);
	}
void msave(int x)
	{
	FILE *f;
		if ((f=fopen(sl7,"w+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		fwrite(&x,sizeof(x),1,f);
	fclose(f);
	}
int rsave()
	{
	FILE *f;
	int x;
	char s[5];
		if ((f=fopen(sl7,"r+b"))==0)
			return 0;
		fread(&x,sizeof (x),1,f);
		fclose(f);return x;

	}
void pfstt(char*)
	{
	FILE *f;
	if ((f=fopen(sl6,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	while(fread(&tr,sizeof (tr),1,f))
		{
		cc=new sturtab;
		cc->next=fir;
		cc->t=tr;
		if (fir==0) fir=cc;
		else las->next=cc;
		las=cc;
		}
	fclose(f);
	}
char* oprc()
	{
	FILE *f;
	if ((f=fopen(sl5,"r+b"))==0)
			cout<<"Oshibka";

	while(fread(&ch,sizeof (ch),1,f))
		if (ch[0].kg>ch[1].kg) {fclose(f);return ch[0].str;}
		else {fclose(f);return ch[1].str;}
	fclose(f);
	}
void psftt()
	{
	FILE *f;
	cc=fir;
	if ((f=fopen(sl6,"w+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	do
		{
		tr=cc->t;
		fwrite(&tr,sizeof(tr),1,f);
		cc=cc->next;
		}
	while(cc!=fir);
	fclose(f);
	}
void ochisstt()
	{
	las->next=0;
	while(fir!=0)
		{
		cc=fir;
		fir=fir->next;
		delete cc;
		}
	}
void ogtt()
	{
	int i;
	gsozds(sl1);
	pfstt(sl6);
	c3=first1;
	do
		{
		for (i=0; i<4; i++)
			{
			cc=fir;
			do
				{
				if (strcmp(c3->g.vgr[i].str,cc->t.str)==0)
					{
					cc->t.o=c3->g.vgr[i].o;
					cc->t.zg=c3->g.vgr[i].zg;
					cc->t.pg=c3->g.vgr[i].pg;
					cc->t.po=c3->g.vgr[i].po;
					cc->t.pr=c3->g.vgr[i].pr;
					cc->t.n=c3->g.vgr[i].n;
					cc->t.is=c3->g.vgr[i].is;
					}
				cc=cc->next;
				}
			while(cc!=fir);
			}
		c3=c3->next1;
		}
	while(c3!=first1);
	sorttt();
	psftt();
	gochiss();
	ochisstt();
	}
void sorttt()
	{
	int d;
	do
		{
		d=1;
		cc=fir;
		do
			{
			if (cc->t.o<cc->next->t.o)
						{
						tr=cc->t;
						cc->t=cc->next->t;
						cc->next->t=tr;
						d=0;
						}
					else if (cc->t.o==cc->next->t.o)
						if (cc->t.zg<cc->next->t.zg)
							{
							tr=cc->t;
							cc->t=cc->next->t;
							cc->next->t=tr;
							d=0;
							}
						 else if (cc->t.zg==cc->next->t.zg)
							if (cc->t.pg>cc->next->t.pg)
								{
								tr=cc->t;
								cc->t=cc->next->t;
								cc->next->t=tr;
								d=0;
								}
							else if (cc->t.pg==cc->next->t.pg)
								if (cc->t.po<cc->next->t.po)
									{
									tr=cc->t;
									cc->t=cc->next->t;
									cc->next->t=tr;
									d=0;


									}
								else if (cc->t.po==cc->next->t.po)
									if (cc->t.pr>cc->next->t.pr)
										{
										tr=cc->t;
										cc->t=cc->next->t;
										cc->next->t=tr;
										d=0;

										}
			cc=cc->next;
			}
		while(cc->next!=fir);
		}
	while (!d);
	}
void pvtt(char*sss)
	{
	FILE *f;
		if ((f=fopen(sss,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		pfstt(sl6);
		while(fread(&ch,sizeof (ch),1,f))
			{
			if (ch[0].kg>ch[1].kg)
				{
				cc=fir;
				do
					{
					if (strcmp(ch[0].str,cc->t.str)==0)
						{
						cc->t.o+=3;
						cc->t.zg+=ch[0].kg;
						cc->t.pg+=ch[1].kg;
						cc->t.po++;
						cc->t.is++;
						}
					cc=cc->next;
					}
				while(cc!=fir);
				cc=fir;
				do
					{
					if (strcmp(ch[1].str,cc->t.str)==0)
						{
						cc->t.zg+=ch[1].kg;
						cc->t.pg+=ch[0].kg;
						cc->t.pr++;
						cc->t.is++;
						}
					cc=cc->next;
					}
				while(cc!=fir);
				}
			else
				{
				cc=fir;
				do
					{
					if (strcmp(ch[1].str,cc->t.str)==0)
						{
						cc->t.o+=3;
						cc->t.zg+=ch[1].kg;
						cc->t.pg+=ch[0].kg;
						cc->t.po++;
						cc->t.is++;
						}
					cc=cc->next;
					}
				while(cc!=fir);
				cc=fir;
				do
					{
					if (strcmp(ch[0].str,cc->t.str)==0)
						{
						cc->t.zg+=ch[0].kg;
						cc->t.pg+=ch[1].kg;
						cc->t.pr++;
						cc->t.is++;
						}
					cc=cc->next;
					}
				while(cc!=fir);
				}
			}
		sorttt();
		psftt();
		ochisstt();
		fclose(f);

	}
char* vibor(char*sl,int x)
	{
	FILE *f;
	int i=1;
	if ((f=fopen(sl,"r+b"))==0)
			cout<<"Oshibka";

		while(fread(&klub,sizeof (klub),1,f))
			if (i++==x) {fclose(f);return klub.strana;}

	fclose(f);
	}
char* vibor1(char*sl,char*s,int x)
	{
	FILE *f;
	int i=1;
	if ((f=fopen(sl,"r+b"))==0)
			cout<<"Oshibka";

		while(fread(&klub,sizeof (klub),1,f))
			if (strcmp(klub.strana,s)==0)
				for(i=1;i<16;i++)
					if (i==x){fclose(f); return klub.fboler[i-1].im;}


	fclose(f);
	}
void vivodtn(char*sl)
	{
	FILE *f;
	int i=15;
	if ((f=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	textcolor(14);
	gotoxy(33,13);
	cprintf("FIFA WORLD CUP");
	gotoxy(34,14);
	cprintf("GERMANY 2006");
		while(fread(&klub,sizeof (klub),1,f))
			{
			i++;
			gotoxy(35,i);
			textcolor(9);
			cout<<i-15;
			cprintf(".");
			cprintf(klub.strana);
			}
		fclose(f);
	textcolor(13);
	gotoxy(35,i+2);
	cprintf("0.Nazad");
	textcolor(10);
	gotoxy(35,i+3);
	cprintf("Vash vibor: ");
	}
void vivodti(char*sl,char*s)
	{
	FILE *f;
	int i;
	if ((f=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		textcolor(14);
		gotoxy(33,10);
		cprintf("FIFA WORLD CUP");
		gotoxy(34,11);
		cprintf("GERMANY 2006");
		while(fread(&klub,sizeof (klub),1,f))
			if (strcmp(klub.strana,s)==0)
				for(i=1;i<16;i++)
					{
					gotoxy(35,i+12);
					textcolor(9);
					cout<<i<<".";
					cprintf(klub.fboler[i-1].im);
					}

	fclose(f);
	textcolor(13);
	gotoxy(35,i+13);
	cprintf("0.Nazad");
	textcolor(10);
	gotoxy(35,i+14);
	cprintf("Vash vibor: ");
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
			textcolor(15);
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
				clrscr();
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
				fclose(f); return;
				}
			}
			fclose(f);
			gotoxy(18,15);
			cout<<"Ne pravelno vvedeno naz strani poprobui punkt 2";
			getch();
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
					clrscr();
					menuzg(1);

					textcolor(13);
					gotoxy(23,13);
					cprintf("Strana: ");
					cprintf(klub.strana);

					gotoxy(28,15);
					cout<<"   Imya: ";
					puts(klub.fboler[i].im);

					gotoxy(28,16);
					cout<<"   God rogdenia: ";
					cout<<klub.fboler[i].grog<<endl;

					gotoxy(28,17);
					cout<<"   Nomer: ";
					cout<<klub.fboler[i].nom;

					gotoxy(28,18);
					cout<<"   Pozicia: ";
					puts(klub.fboler[i].poz);

					gotoxy(28,19);
					cout<<"   Nastroi: ";
					if (klub.fboler[i].nastroi==1) cout<<"Ploho"<<endl;
					if (klub.fboler[i].nastroi==2) cout<<"Normalno"<<endl;
					if (klub.fboler[i].nastroi==3) cout<<"Super"<<endl;

					gotoxy(28,20);
					cout<<"   Sostoyanie: ";
					puts(klub.fboler[i].sos);


					gotoxy(28,21);
					cout<<"   Sr bal igroka: ";
					cout<<klub.fboler[i].srbal;
					getch();
					fclose(f);return;
					}
		fclose(f);
		gotoxy(18,15);
		cout<<"Ne pravelno vvedeno imya igraka poprobui punkt 2";
		getch();
	}
void redigr(char *sl,char *s1)
	{
	FILE *f;
	int i,l,x=2;
	float y;
	if ((f=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
			while(fread(&klub,sizeof (klub),1,f))
				for (int i=0; i<15; i++)
						if (strcmp(s1,klub.fboler[i].im)==0)
							{
							while (x)
								{
								clrscr();
								menuzg(1);
								textcolor(11);
								gotoxy(28,13);
								cprintf(klub.fboler[i].im);

								gotoxy(28,15);
								cout<<"1.Hotite izmenit imya?";
								gotoxy(28,16);
								cout<<"2.Hotite izmenit datu rogdeniya?";
								gotoxy(28,17);
								cout<<"3.Hotite izmenit nomer?";
								gotoxy(28,18);
								cout<<"4.Hotite izmenit poziciu?";
								gotoxy(28,19);
								cout<<"5.Hotite izmenit nastroi?";
								gotoxy(28,20);
								cout<<"6.Hotite izmenit sr bal?";
								textcolor(13);
								gotoxy(28,21);
								cprintf("0.         Nazad");
								textcolor(10);
								gotoxy(28,22);
								cprintf("Vash vibor: ");
								cin>>x;
								textcolor(15);
								switch (x)
									{
									case 1: gotoxy(28,24);
										cout<<"Vvedite imya: ";
										gets(klub.fboler[i].im);
										break;

									case 2: gotoxy(28,24);
										cout<<"Vvedite God rogdenia: ";
										cin>>klub.fboler[i].grog;
										klub.fboler[i].grog+=1900;
										break;

									case 3: gotoxy(28,24);
										cout<<"Vvedite nomer: ";
										cin>>klub.fboler[i].nom;
										break;

									case 4: gotoxy(28,24);
										cout<<"Vvedite poziciu "<<endl;
										gotoxy(28,25);
										cout<<"1 Vratar  2 Zashitnik  3 Huvback  4 Forvard"<<endl;
										gotoxy(28,26);
										cout<<"Vibereti iz vishe perechislenuh:  ";
										cin>>l;
										if (l==1) strcpy(klub.fboler[i].poz,"Vratar");
										if (l==2) strcpy(klub.fboler[i].poz,"Zashitnik");
										if (l==3) strcpy(klub.fboler[i].poz,"Huvback");
										if (l==4) strcpy(klub.fboler[i].poz,"Forvard");
										break;

									case 5: if (klub.fboler[i].nastroi==2) klub.fboler[i].srbal-=5;
										if (klub.fboler[i].nastroi==3) klub.fboler[i].srbal-=10;
										gotoxy(28,24);
										cout<<"Vvedite nastroi"<<endl;
										gotoxy(28,25);
										cout<<"1 Ploho  2 Normalno  3 Super"<<endl;
										gotoxy(28,26);
										cout<<"Vibereti iz vishe perechislenuh:  ";
										cin>>klub.fboler[i].nastroi;
										if (klub.fboler[i].nastroi==2) klub.fboler[i].srbal+=5;
										if (klub.fboler[i].nastroi==3) klub.fboler[i].srbal+=10;
										break;

									case 6: if (strcmp(klub.fboler[i].sos,"V pole")==0) klub.srbal-=(klub.fboler[i].srbal/11);
										gotoxy(28,24);
										cout<<"Vvedite Sr bal igroka: ";
										cin>>klub.fboler[i].srbal;
										if (klub.fboler[i].nastroi==2) klub.fboler[i].srbal+=5;
										if (klub.fboler[i].nastroi==3) klub.fboler[i].srbal+=10;
										if (strcmp(klub.fboler[i].sos,"V pole")==0) klub.srbal+=(klub.fboler[i].srbal/11);
										break;
									}

								}
							for (i=0; i<15; i++)
								y+=klub.fboler[i].nastroi;
							y/=15;
							if (y>=1 && y<=1.5) klub.nastroi=1;
							if (y>=1.6 && y<=2.3) klub.nastroi=2;
							if (y>=2.4 && y<=3) klub.nastroi=3;
							fseek(f,ftell(f)-sizeof(klub),0);
							fwrite(&klub,sizeof(klub),1,f);
							fclose(f);return;
							}
				fclose(f);
				gotoxy(18,15);
				cout<<"Ne pravelno vvedeno naz strani poprobui punkt 2"; getch();
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
						menuzg(1);

						textcolor(11);
						gotoxy(28,13);
						cprintf("Strana: ");
						cprintf(klub.strana);

						gotoxy(28,15);
						cout<<"1.Hotite izmenit stranu?";
						gotoxy(28,16);
						cout<<"2.Hotite izmenit formacia?";
						gotoxy(28,17);
						cout<<"3.Hotite izmenit imya gltrenera?";
						gotoxy(28,18);
						textcolor(13);
						cprintf("0.         Nazad");
						textcolor(10);
						gotoxy(28,19);
						cprintf("Vash vibor: ");
						cin>>x;
						textcolor(15);
						switch (x)
							{
							case 1: gotoxy(28,21);
								cout<<"Vvedite stranu: ";
								gets(klub.strana);
								break;

							case 2: gotoxy(28,21);
								cout<<"Vvedite formaciu: ";
								gets(klub.formacia);
								break;

							case 3: gotoxy(28,21);
								cout<<"Vvedite imya gltrenera: ";
								gets(klub.gltrener);
								break;
							}
						}
					fseek(f,ftell(f)-sizeof(klub),0);
					fwrite(&klub,sizeof(klub),1,f);
					fclose(f);
					return;
					}
				fclose(f);
			gotoxy(18,15);
			cout<<"Ne pravelno vvedeno naz strani poprobui punkt 2"; getch();

	}
void zamena(char*sl,char*s)
	{
	FILE *f;
	int i,x,k=0;
		if ((f=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		while(fread(&klub,sizeof (klub),1,f))
			{
			if (strcmp(klub.strana,s)==0)
				{
				do
					{
					clrscr();
					menuzg(1);
					textcolor(13);
					gotoxy(28,13);
					cprintf("Strana: ");
					cprintf(klub.strana);
					textcolor(13);
					gotoxy(28,14);
					cprintf("Kogo iz glsostava");
					for (i=1; i<12; i++)
						{
						gotoxy(28,i+15);
						cout<<i<<'.'<<klub.fboler[i-1].im<<endl;
						}
					gotoxy(28,i+16);
					textcolor(13);
					cprintf("0.Nazad");
					gotoxy(28,i+17);
					textcolor(10);
					cprintf("Vash vibor: ");

					cin>>x;
					textcolor(9);
					if (x>0 && x<12) {klub.srbal-=(klub.fboler[x-1].srbal/11);strcpy(klub.fboler[x-1].sos,"Na zamene");}
					}
				while (x<0 || x>11);
				if (x)
					do
						{
						clrscr();
						textcolor(14);
						gotoxy(33,10);
						cprintf("FIFA WORLD CUP");
						gotoxy(34,11);
						cprintf("GERMANY 2006");

						textcolor(13);
						gotoxy(28,13);
						cprintf("Strana: ");
						cprintf(klub.strana);
						textcolor(13);
						gotoxy(28,14);
						cprintf("Kogo iz zameni");

						for (i=12; i<16; i++)
							{
							gotoxy(28,i+4);
							cout<<i<<'.'<<klub.fboler[i-1].im<<endl;
							}
						gotoxy(28,i+5);
						textcolor(10);
						cprintf("Vash vibor: ");
						cin>>x;
						textcolor(9);
						if (x>11 && x<16) {klub.srbal+=(klub.fboler[x-1].srbal/11);strcpy(klub.fboler[x-1].sos,"V Pole");}
						}
					while(x<12||x>15);
				k=1;
				}
			fseek(f,ftell(f)-sizeof(klub),0);
			fwrite(&klub,sizeof(klub),1,f);
			}
		fclose(f);
		sozds(sl);
		sortss(s);
		sspf(sl);
		ochiss();
		if (k==0) {gotoxy(18,15);
			cout<<"Ne pravelno vvedeno naz strani poprobui punkt 2"; getch();}
		}
void vivodpoz(char*sl,char*s)
	{
	FILE *f;
	int x=17,y=13,k=0;
	if ((f=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}

		while(fread(&klub,sizeof (klub),1,f))
			for (int i=0; i<15; i++)
				if (strcmp(s,klub.fboler[i].poz)==0)
					{
					if (k==30||k==0)
						{
						if (k==30)getch();
						clrscr(); y=13; k=0;
						gotoxy(17,13);
						cout<<"Imya";
						gotoxy(32,13);
						cout<<"Strana";
						gotoxy(47,13);
						cout<<"Nomer";
						gotoxy(55,13);
						cout<<"Sr bal";
						y++;
						textcolor(14);
						gotoxy(33,10);
						cprintf("FIFA WORLD CUP");
						gotoxy(34,11);
						cprintf("GERMANY 2006");
						textcolor(15);
						}
					y++;
					gotoxy(x,y);
					puts(klub.fboler[i].im);

					gotoxy(x+=15,y);
					puts(klub.strana);

					gotoxy(x+=15,y);
					cout<<klub.fboler[i].nom;

					gotoxy(x+=8,y);
					cout<<klub.fboler[i].srbal;
					x=17;
					k++;

					}
			getch();
			clrscr();
		fclose(f);
	}
void sozds(char*sss)
	{
	FILE *f;
	if ((f=fopen(sss,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	while(fread(&klub,sizeof (klub),1,f))
		{
		c=new skomanda;
		c->next=first;
		c->k=klub;
		if (first==0) first=c;
		else last->next=c;
		last=c;
		}
	fclose(f);
	}
void ochiss()
	{
	last->next=0;
	while(first!=0)
		{
		c=first;
		first=first->next;
		delete c;
		}
	}
void vivods()
	{
	int x=4,y=10;
	skomanda* c;
	c=first;
	do
		{
		cout<<"Strana: ";
		puts(c->k.strana);

		cout<<"Formacia: ";
		puts(c->k.formacia);

		cout<<"Imya gltrenera: ";
		puts(c->k.gltrener);

		cout<<"Nastroi: ";
		if (c->k.nastroi==1) cout<<"Ploho";
		if (c->k.nastroi==2) cout<<"Normalno";
		if (c->k.nastroi==3) cout<<"Super";

		cout<<endl;
		cout<<"Sr Bal komandi: ";
		cout<<c->k.srbal;

		cout<<endl;
		cout<<"Sostav:";


		for (int i=0; i<15; i++)
			{
			gotoxy(x,y++);
			cout<<"   Imya: ";
			puts(c->k.fboler[i].im);

			gotoxy(x,y++);
			cout<<"   God rogdenia: ";
			cout<<c->k.fboler[i].grog<<endl;

			gotoxy(x,y++);
			cout<<"   Nomer: ";
			cout<<c->k.fboler[i].nom;

			gotoxy(x,y++);
			cout<<"   Pozicia: ";
			puts(c->k.fboler[i].poz);

			gotoxy(x,y++);
			cout<<"   Nastroi: ";
			if (c->k.fboler[i].nastroi==1) cout<<"Ploho"<<endl;
			if (c->k.fboler[i].nastroi==2) cout<<"Normalno"<<endl;
			if (c->k.fboler[i].nastroi==3) cout<<"Super"<<endl;

			gotoxy(x,y++);
			cout<<"   Sostoyanie: ";
			puts(c->k.fboler[i].sos);

			gotoxy(x,y++);
			cout<<"   Sr bal igroka: ";
			cout<<c->k.fboler[i].srbal;
			if (i==4 || i==9) {y=10; x+=25;}
			else y++;
			}
		getch();
		clrscr();
		x=4;y=10;
		c=c->next;
		}
	while(c!=first);
	}
void sortsb()
	{
	skomanda *c;
	int d;

	do
		{
		d=1;
		c=first;
		do
			{
			if (c->k.srbal<c->next->k.srbal)
				{
				klub=c->k;
				c->k=c->next->k;
				c->next->k=klub;
				d=0;
				}
			c=c->next;
			}
		while(c->next!=first);
		}
	while (!d);
	}
void sortsi()
	{
	skomanda *c;
	int d;

	do
		{
		d=1;
		c=first;
		do
			{
			if (strcmp(c->k.strana,c->next->k.strana)>0)
				{
				klub=c->k;
				c->k=c->next->k;
				c->next->k=klub;
				d=0;
				}
			c=c->next;
			}
		while(c->next!=first);
		}
	while (!d);
	}
void sortss(char*s)
	{
	int d,i;
		c=first;
		do
			{
			if (strcmp(c->k.strana,s)==0)
				do
					{
					d=1;
					for (i=0; i<14; i++)
						if (strcmp(c->k.fboler[i].sos,c->k.fboler[i+1].sos)<0)
							{
							klub.fboler[i]=c->k.fboler[i];
							c->k.fboler[i]=c->k.fboler[i+1];
							c->k.fboler[i+1]=klub.fboler[i];
							d=0;
							}

					}
				while (!d);
			c=c->next;
			}
		while(c!=first);
	}
void udalsn(char *s)
	{
	c=first;
	if (strcmp(c->k.strana,s)==0)
		{
		first=first->next;
		last->next=first;
		delete c;
		return;
		}

	while(strcmp(c->next->k.strana,s)!=0)
		c=c->next;

	c1=new skomanda;
	c1=c->next;
	c->next=c1->next;
	if (c1==last) {last=c; last->next=first;}
	delete c1;
	}
void sspf(char*sss)
	{
	FILE *f;
	c=first;
	if ((f=fopen(sss,"w+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	do
		{
		klub=c->k;
		fwrite(&klub,sizeof(klub),1,f);
		c=c->next;
		}
	while(c!=first);
	fclose(f);
	}
void sogruppi(char *sss)
	{
	FILE *f1;
	int k=0,a[32],l,i,m=8,n,j,t;
		sozds(sl);
		sortsb();

		if ((f1=fopen(sss,"w+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}

		for(i=0; i<32; i++)
			a[i]=0;


		for (i=0; i<8; i++)
			{
			c=first;
			n=0; k=0;
			if (i==0) strcpy(gr.nazg,"A");
			if (i==1) strcpy(gr.nazg,"B");
			if (i==2) strcpy(gr.nazg,"C");
			if (i==3) strcpy(gr.nazg,"D");
			if (i==4) strcpy(gr.nazg,"E");
			if (i==5) strcpy(gr.nazg,"F");
			if (i==6) strcpy(gr.nazg,"G");
			if (i==7) strcpy(gr.nazg,"H");
			for (j=0; j<4; j++)
				{
				do
					l=random(m)+n;
				while (a[l]!=0);
				a[l]=1;

				for(t=k; t<l; t++)
					c=c->next;
				k=l;

				strcpy(gr.vgr[j].str,c->k.strana);
				gr.vgr[j].o=0; gr.vgr[j].zg=0; gr.vgr[j].pg=0; gr.vgr[j].po=0;
				gr.vgr[j].pr=0; gr.vgr[j].n=0; gr.vgr[j].is=0; gr.vgr[j].srbal=c->k.srbal;
				gr.vgr[j].nk=j;
				n+=8;
				}

			fwrite(&gr,sizeof(gr),1,f1);
			}
	fclose(f1);
	ochiss();
	}
void vvgruppi(char*sl1)
	{
	FILE *f1;
	int x=5,y=10,k=1;
		if ((f1=fopen(sl1,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		clrscr();
		textcolor(14);
		gotoxy(33,5);
		cprintf("FIFA WORLD CUP");
		gotoxy(34,6);
		cprintf("GERMANY 2006");
		while(fread(&gr,sizeof (gr),1,f1))
			{
			k++;
			gotoxy(x,y);
			cout<<"Gruppa ";
			puts(gr.nazg);
			gotoxy(x+14,y);
			cout<<"O";
			gotoxy(x+16,y);
			cout<<"ZG";
			gotoxy(x+19,y);
			cout<<"PG";
			gotoxy(x+22,y);
			cout<<"Po";
			gotoxy(x+25,y);
			cout<<"Pr";
			gotoxy(x+28,y);
			cout<<"N";
			gotoxy(x+30,y);
			cout<<"IS";

			y+=2;
			for (int i=0; i<4; i++)
				{
				gotoxy(x,y+i);
				puts(gr.vgr[i].str);
				gotoxy(x+14,y+i);
				cout<<gr.vgr[i].o;
				gotoxy(x+16,y+i);
				cout<<gr.vgr[i].zg;
				gotoxy(x+19,y+i);
				cout<<gr.vgr[i].pg;
				gotoxy(x+22,y+i);
				cout<<gr.vgr[i].po;
				gotoxy(x+25,y+i);
				cout<<gr.vgr[i].pr;
				gotoxy(x+28,y+i);
				cout<<gr.vgr[i].n;
				gotoxy(x+30,y+i);
				cout<<gr.vgr[i].is;
				}
			y-=2;
			if (k%2==0) x=44;
			else {y+=8; x=5;}
			}
		fclose(f1);
		getch();
	}
void vv1gruppi(char*sl1,char*s)
	{
	FILE *f1;
	int x=23,y=13;
		if ((f1=fopen(sl1,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}


		while(fread(&gr,sizeof (gr),1,f1))
			{
			if (strcmp(gr.nazg,s)==0)
				{
				clrscr();
				menuzg(1);
				gotoxy(x-4,y);
				cout<<"Gruppa ";
				puts(gr.nazg);
				gotoxy(x+14,y);
				cout<<"O";
				gotoxy(x+16,y);
				cout<<"ZG";
				gotoxy(x+19,y);
				cout<<"PG";
				gotoxy(x+22,y);
				cout<<"Po";
				gotoxy(x+25,y);
				cout<<"Pr";
				gotoxy(x+28,y);
				cout<<"N";
				gotoxy(x+30,y);
				cout<<"IS";

				y+=2;
				for (int i=0; i<4; i++)
					{
					gotoxy(x-4,y+i);
					puts(gr.vgr[i].str);
					gotoxy(x+14,y+i);
					cout<<gr.vgr[i].o;
					gotoxy(x+16,y+i);
						cout<<gr.vgr[i].zg;
					gotoxy(x+19,y+i);
					cout<<gr.vgr[i].pg;
					gotoxy(x+22,y+i);
					cout<<gr.vgr[i].po;
					gotoxy(x+25,y+i);
						cout<<gr.vgr[i].pr;
						gotoxy(x+28,y+i);
					cout<<gr.vgr[i].n;
					gotoxy(x+30,y+i);
					cout<<gr.vgr[i].is;
					}
				}
			}
		fclose(f1);
		getch();
	}

char* sigri(int srb1,int srb2)
	{
	int l,x,k1=0,k2=0;
	char *s=new char[10];
	char *s1=new char[5];
		if (srb1>srb2)
			{
			l=srb1-srb2;
			srb1=50+l;
			srb2=50-l;
			}
		else
			{
			l=srb2-srb1;
			srb2=50+l;
			srb1=50-l;
			}
		do
			{
			x=random(100)+1;
			if (srb1>=x) k1++;
			x=random(100)+1;
			if (srb2>=x) k2++;
			}
		while(k1==k2);

		x=random(10)+1;
		if (x<=2)
			if (k1>k2) k2++;
			else k1++;
		else
			{
			l/=5;
			x=random(l)+1;
			if (k1>k2) k1+=x;
			else k2+=x;
			}
		if (k2>k1 && srb2<srb1) k2--;

		itoa(k1,s,10);
		itoa(k2,s1,10);
		strcat(s,"i");
		strcat(s,s1);

	return s;
	}
void sozdtt(char*sss)
	{
	FILE *f,*f1;
	if ((f=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	if ((f1=fopen(sss,"w+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	while(fread(&klub,sizeof (klub),1,f))
		{
		strcpy(tr.str,klub.strana);
		tr.o=0;
		tr.zg=0;
		tr.pg=0;
		tr.po=0;
		tr.pr=0;
		tr.n=0;
		tr.is=0;
		fwrite(&tr,sizeof(tr),1,f1);
		}
	fclose(f);
	fclose(f1);
	}
void vivodtt(char*sss)
	{
	FILE *f;
	int x=25,y=15,i=0;
	if ((f=fopen(sss,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	clrscr();
	textcolor(14);
	gotoxy(35,12);
	cprintf("FIFA WORLD CUP");
	gotoxy(36,13);
	cprintf("GERMANY 2006");

	gotoxy(x-4,y);
	cout<<"Sbornaya ";
	gotoxy(x+10,y);
	cout<<"O";
	gotoxy(x+14,y);
	cout<<"ZG";
	gotoxy(x+18,y);
	cout<<"PG";
	gotoxy(x+22,y);
	cout<<"Po";
	gotoxy(x+26,y);
	cout<<"Pr";
	gotoxy(x+30,y);
	cout<<"N";
	gotoxy(x+34,y);
	cout<<"IS";
	y+=2;
	while(fread(&tr,sizeof (tr),1,f))
		{
		i++;
		gotoxy(x-4,y+i);
		puts(tr.str);
		gotoxy(x+10,y+i);
		cout<<tr.o;
		gotoxy(x+14,y+i);
		cout<<tr.zg;
		gotoxy(x+18,y+i);
		cout<<tr.pg;
		gotoxy(x+22,y+i);
		cout<<tr.po;
		gotoxy(x+26,y+i);
		cout<<tr.pr;
		gotoxy(x+30,y+i);
		cout<<tr.n;
		gotoxy(x+34,y+i);
		cout<<tr.is;
		}
	fclose(f);
	getch();
	}
void gsozds(char*sl1)
	{
	FILE *f1;
	if ((f1=fopen(sl1,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	while(fread(&gr,sizeof (gr),1,f1))
		{
		c2=new sgruppi;
		c2->next1=first1;
		c2->g=gr;
		if (first1==0) first1=c2;
		else last1->next1=c2;
		last1=c2;
		}
	fclose(f1);
	}
void gochiss()
	{
	last1->next1=0;
	while(first1!=0)
		{
		c2=first1;
		first1=first1->next1;
		delete c2;
		}
	}
void gvivods()
	{
	int x=5,y=1,k=1;
		c2=first1;
		do
			{
			k++;
			gotoxy(x,y);
			cout<<"Gruppa ";
			puts(c2->g.nazg);
			gotoxy(x+14,y);
			cout<<"O";
			gotoxy(x+16,y);
			cout<<"ZG";
			gotoxy(x+19,y);
			cout<<"PG";
			gotoxy(x+22,y);
			cout<<"Po";
			gotoxy(x+25,y);
			cout<<"Pr";
			gotoxy(x+28,y);
			cout<<"N";
			gotoxy(x+30,y);
			cout<<"IS";

			y+=2;
			for (int i=0; i<4; i++)
				{
				gotoxy(x,y+i);
				puts(c2->g.vgr[i].str);
				gotoxy(x+14,y+i);
				cout<<c2->g.vgr[i].o;
				gotoxy(x+16,y+i);
				cout<<c2->g.vgr[i].zg;
				gotoxy(x+19,y+i);
				cout<<c2->g.vgr[i].pg;
				gotoxy(x+22,y+i);
				cout<<c2->g.vgr[i].po;
				gotoxy(x+25,y+i);
				cout<<c2->g.vgr[i].pr;
				gotoxy(x+28,y+i);
				cout<<c2->g.vgr[i].n;
				gotoxy(x+30,y+i);
				cout<<c2->g.vgr[i].is;
				}
			y-=2;
			if (k%2==0) x=44;
			else {y+=8; x=5;}
			c2=c2->next1;
			}
		while(c2!=first1);
	}
void fgi(int d)
	{
	char s[10],ss[40],ss1[5];
	int x,y,i,k1,k2,j,i1,l,k=0;
		gsozds(sl1);
		c2=first1;
		do
			{
			if (d==1) for(i1=0; i1<4; i1++)
					{
					if (c2->g.vgr[i1].nk==0) k1=i1;
					if (c2->g.vgr[i1].nk==1) k2=i1;
					}

			if (d==2) for(i1=0; i1<4; i1++)
					{
					if (c2->g.vgr[i1].nk==0) k1=i1;
					if (c2->g.vgr[i1].nk==2) k2=i1;
					}

			if (d==3) for(i1=0; i1<4; i1++)
					{
					if (c2->g.vgr[i1].nk==0) k1=i1;
					if (c2->g.vgr[i1].nk==3) k2=i1;
					}


			for (i=0; i<2; i++)
				{
				strcpy(s,sigri(c2->g.vgr[k1].srbal,c2->g.vgr[k2].srbal));
				x=atoi(&s[0]);
				for (j=0; s[j]!='i'; j++);
				strcpy(s,&s[j+1]);
				y=atoi(s);

				strcpy (ss,c2->g.vgr[k1].str);
				itoa(x,ss1,10);
				for (l=strlen(ss); l<14; l++)
					strcat(ss," ");

				strcat(ss,ss1);
				strcat(ss," - ");
				itoa(y,ss1,10);
				strcat(ss,ss1);
				strcat(ss," ");
				strcat(ss,c2->g.vgr[k2].str);
				k++;
				gotoxy(23,k+15);
				puts(ss);

				if (x>y)
					{
					c2->g.vgr[k1].o+=3;
					c2->g.vgr[k1].po++;
					c2->g.vgr[k2].pr++;
					c2->g.vgr[k1].srbal=win(sl,c2->g.vgr[k1].str);
					c2->g.vgr[k2].srbal=lose(sl,c2->g.vgr[k2].str);
					}
				if (x<y)
					{
					c2->g.vgr[k2].o+=3;
					c2->g.vgr[k2].po++;
					c2->g.vgr[k1].pr++;
					c2->g.vgr[k2].srbal=win(sl,c2->g.vgr[k1].str);
					c2->g.vgr[k1].srbal=lose(sl,c2->g.vgr[k2].str);
					}

				if (x==y) {c2->g.vgr[k1].o++; c2->g.vgr[k2].o++;
					   c2->g.vgr[k1].n++; c2->g.vgr[k2].n++;}
				c2->g.vgr[k1].zg+=x; c2->g.vgr[k2].zg+=y;
				c2->g.vgr[k1].pg+=y; c2->g.vgr[k2].pg+=x;
				c2->g.vgr[k1].is++;  c2->g.vgr[k2].is++;
				if (d==1) for(i1=0; i1<4; i1++)
						{
						if (c2->g.vgr[i1].nk==2) k1=i1;
						if (c2->g.vgr[i1].nk==3) k2=i1;
						}

				if (d==2) for(i1=0; i1<4; i1++)
						{
						if (c2->g.vgr[i1].nk==1) k1=i1;
						if (c2->g.vgr[i1].nk==3) k2=i1;
						}
				if (d==3) for(i1=0; i1<4; i1++)
						{
						if (c2->g.vgr[i1].nk==1) k1=i1;
						if (c2->g.vgr[i1].nk==2) k2=i1;
						}
				}
			c2=c2->next1;
			}
		while(c2!=first1);
		sortsg();
		if (d==3) sm();
		sspfg(sl1);
		gochiss();

	}
void sortsg()
	{
	int d,i;
		c2=first1;
		do
			{
			do
				{
				d=1;
				for (i=0; i<3; i++)
					if (c2->g.vgr[i].o<c2->g.vgr[i+1].o)
						{
						gr.vgr[i]=c2->g.vgr[i];
						c2->g.vgr[i]=c2->g.vgr[i+1];
						c2->g.vgr[i+1]=gr.vgr[i];
						d=0;
						}
					else if (c2->g.vgr[i].o==c2->g.vgr[i+1].o)
						if (c2->g.vgr[i].zg<c2->g.vgr[i+1].zg)
							{
							gr.vgr[i]=c2->g.vgr[i];
							c2->g.vgr[i]=c2->g.vgr[i+1];
							c2->g.vgr[i+1]=gr.vgr[i];
							d=0;
							}
						 else if (c2->g.vgr[i].zg==c2->g.vgr[i+1].zg)
							if (c2->g.vgr[i].pg>c2->g.vgr[i+1].pg)
								{
								gr.vgr[i]=c2->g.vgr[i];
								c2->g.vgr[i]=c2->g.vgr[i+1];
								c2->g.vgr[i+1]=gr.vgr[i];
								d=0;
								}
							else if (c2->g.vgr[i].pg==c2->g.vgr[i+1].pg)
								if (c2->g.vgr[i].po<c2->g.vgr[i+1].po)
									{
									gr.vgr[i]=c2->g.vgr[i];
									c2->g.vgr[i]=c2->g.vgr[i+1];
									c2->g.vgr[i+1]=gr.vgr[i];
									d=0;
									}
								else if (c2->g.vgr[i].po==c2->g.vgr[i+1].po)
									if (c2->g.vgr[i].pr>c2->g.vgr[i+1].pr)
										{
										gr.vgr[i]=c2->g.vgr[i];
										c2->g.vgr[i]=c2->g.vgr[i+1];
										c2->g.vgr[i+1]=gr.vgr[i];
										d=0;
										}
				}
			while (!d);
			c2=c2->next1;
			}
		while(c2!=first1);
	}
void sm()
	{
	char s[10];
	int x,y,j,l;

		c2=first1;
		do
			{
			if (c2->g.vgr[1].o==c2->g.vgr[2].o&&c2->g.vgr[1].zg==c2->g.vgr[2].zg
			&&c2->g.vgr[1].pg==c2->g.vgr[2].pg&&c2->g.vgr[1].po==c2->g.vgr[2].po
			&&c2->g.vgr[1].pr==c2->g.vgr[2].pr&&c2->g.vgr[1].n==c2->g.vgr[2].n)
				{
				strcpy(s,sigri(c2->g.vgr[1].srbal,c2->g.vgr[1].srbal));
				x=atoi(&s[0]);
				for (j=0; s[j]!='i'; j++);
				strcpy(s,&s[j+1]);
				y=atoi(s);
				if (x==y)
					{
					l=random(2)+1;
					if (l==1) x++;
					else y++;
					}
				if (x<y)
					{
					gr.vgr[0]=c2->g.vgr[1];
					c2->g.vgr[1]=c2->g.vgr[2];
					c2->g.vgr[2]=gr.vgr[0];
					}

				}
			c2=c2->next1;
			}
		while(c2!=first1);
	}
void sspfg(char*sl1)
	{
	FILE *f1;
	c2=first1;
	if ((f1=fopen(sl1,"w+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	do
		{
		gr=c2->g;
		fwrite(&gr,sizeof(gr),1,f1);
		c2=c2->next1;
		}
	while(c2!=first1);
	fclose(f1);
	}
void uvkg(char*sl1)
	{
	FILE *f1;

		if ((f1=fopen(sl1,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		sozds(sl);
		while(fread(&gr,sizeof (gr),1,f1))
			{
			udalsn(gr.vgr[2].str);
			udalsn(gr.vgr[3].str);
			}
		fclose(f1);
		sspf(sl);
		ochiss();
	}
void psozdpg(char*sss)
	{
	FILE *f2;
	int k2=0,k=0,k1=0,i;
	if ((f2=fopen(sss,"w+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
	gsozds(sl1);
	c2=first1;
	for (i=0; i<8; i++)
		{
		k++;
		if (k%2!=0) {k2=0;k1=1;}
		else {k2=1;k1=0;}

		if (i==2 || i==4 || i==6) {c2=c2->next1; c2=c2->next1;}

		strcpy(ch[0].str,c2->g.vgr[k2].str);
		ch[0].srbal=c2->g.vgr[k2].srbal;
		ch[0].kg=0;

		c3=c2;
		c2=c2->next1;

		strcpy(ch[1].str,c2->g.vgr[k2].str);
		ch[1].srbal=c2->g.vgr[k2].srbal;
		ch[1].kg=0;

		fwrite(&ch,sizeof(ch),1,f2);
		c2=c3;
		}
	fclose(f2);
	gochiss();
	}
void vivodpg(char*sss)
	{
	FILE *f2;
	int l,k=0;
	char ss[40],ss1[5];
		if ((f2=fopen(sss,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		while(fread(&ch,sizeof (ch),1,f2))
			{
			strcpy (ss,ch[0].str);
			itoa(ch[0].kg,ss1,10);
			for (l=strlen(ss); l<14; l++)
					strcat(ss," ");
				strcat(ss,ss1);
				strcat(ss," - ");
				itoa(ch[1].kg,ss1,10);
				strcat(ss,ss1);
				strcat(ss," ");
				strcat(ss,ch[1].str);
				k++;
				gotoxy(25,k+15);
				puts(ss);



			}
	fclose(f2);
	}
void ipg(char*sss)
	{
	FILE *f2;
	char s[15];
	int x,y,j,l;
		if ((f2=fopen(sss,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		sozds(sl);
		while(fread(&ch,sizeof (ch),1,f2))
			{
			strcpy(s,sigri(ch[0].srbal,ch[1].srbal));
			x=atoi(&s[0]);
			for (j=0; s[j]!='i'; j++);
			strcpy(s,&s[j+1]);
			y=atoi(s);
			if (x==y)
				{
				l=random(2)+1;
				if (l==1) x++;
				else y++;
				}
			ch[0].kg=x;
			ch[1].kg=y;

			if (x<y)strcpy(s,ch[0].str);
			else strcpy(s,ch[1].str);
			udalsn(s);

			fseek(f2,ftell(f2)-sizeof(ch),0);
			fwrite(&ch,sizeof(ch),1,f2);
			fseek(f2,ftell(f2),0);
			}
		fclose(f2);
		sspf(sl);
		ochiss();
	}
void sozdpg(char*sss1,char*sss2)
	{
	FILE *f2,*f3;
	int k=1;
		if ((f2=fopen(sss1,"r+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		if ((f3=fopen(sss2,"w+b"))==0)
			{
			cout<<"Oshibka";
			return;
			}
		while(fread(&ch,sizeof (ch),1,f2))
			{
			k++;
			if(ch[0].kg>ch[1].kg) strcpy(pf[k%2].str,ch[0].str);
			else strcpy(pf[k%2].str,ch[1].str);
			pf[k%2].kg=0;
			if (k%2!=0) fwrite(&pf,sizeof(pf),1,f3);
			}
		fclose(f2);
		fclose(f3);

	}
int win(char*sl,char*s)
	{
	FILE *f;
	int y=0,l,i;
	float x;

		if ((f=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			//return;
			}
		while(fread(&klub,sizeof (klub),1,f))
			{
			if (strcmp(s,klub.strana)==0)
				{
				for (i=0; i<15; i++)
					{
					if (klub.fboler[i].nastroi==2) klub.fboler[i].srbal-=5;
					if (klub.fboler[i].nastroi==3) klub.fboler[i].srbal-=10;
					if (klub.fboler[i].nastroi!=3)
						{
						l=random(2)+1;
						if (l==1) klub.fboler[i].nastroi++;
						}
					x+=klub.fboler[i].nastroi;
					if (klub.fboler[i].nastroi==2) klub.fboler[i].srbal+=5;
					if (klub.fboler[i].nastroi==3) klub.fboler[i].srbal+=10;
					if (strcmp(klub.fboler[i].sos,"V pole")==0) y+=klub.fboler[i].srbal;
					}
				x/=15;
				if (x>=1 && x<=1.5) klub.nastroi=1;
				if (x>1.5 && x<=2.3) {klub.nastroi=2; y+=5;}
				if (x>2.3 && x<=3) {klub.nastroi=3; y+=5;}
				klub.srbal=y/11;
				y=klub.srbal;
				fseek(f,ftell(f)-sizeof(klub),0);
				fwrite(&klub,sizeof(klub),1,f);
				}
			}
		fclose(f);
		return y;
	}
int lose(char*sl,char*s)
	{
	FILE *f;
	int y=0,l,i;
	float x;

		if ((f=fopen(sl,"r+b"))==0)
			{
			cout<<"Oshibka";
			//return;
			}
		while(fread(&klub,sizeof (klub),1,f))
			{
			if (strcmp(s,klub.strana)==0)
				{
				for (i=0; i<15; i++)
					{
					if (klub.fboler[i].nastroi==2) klub.fboler[i].srbal-=5;
					if (klub.fboler[i].nastroi==3) klub.fboler[i].srbal-=10;
					if (klub.fboler[i].nastroi!=1)
						{
						l=random(2)+1;
						if (l==1) klub.fboler[i].nastroi--;
						}
					x+=klub.fboler[i].nastroi;
					if (klub.fboler[i].nastroi==2) klub.fboler[i].srbal+=5;
					if (klub.fboler[i].nastroi==3) klub.fboler[i].srbal+=10;
					if (strcmp(klub.fboler[i].sos,"V pole")==0) y+=klub.fboler[i].srbal;
					}
				x/=15;
				if (x>=1 && x<=1.5) klub.nastroi=1;
				if (x>1.5 && x<=2.3) {klub.nastroi=2; y+=5;}
				if (x>2.3 && x<=3) {klub.nastroi=3; y+=5;}
				klub.srbal=y/11;
				y=klub.srbal;
				fseek(f,ftell(f)-sizeof(klub),0);
				fwrite(&klub,sizeof(klub),1,f);
				}
			}
		fclose(f);
		return y;
	}
void diagro()
	{
	int gd,gm,a[10],i=0,x=85,y=400;
	char s[3],ss[15];
		gd=DETECT;
		initgraph(&gd,&gm,"c:\\borlandc\\bgi");


		 pfstt(sl6);
		 cc=fir;
		 for(i=0;i<10;i++)
			{
			a[i]=cc->t.o;
			cc=cc->next;
			}

		 line(60,170,60,400);
		 line(60,400,500,400);
		 line(60,170,55,175);
		 line(60,170,65,175);
		 line(500,400,495,395);
		 line(500,400,495,405);
		 settextstyle(0,0,1);
		 settextjustify(1,1);
		 outtextxy(485,420,"nzkom");
		 settextstyle(0,1,1);
		 settextjustify(2,2);
		 outtextxy(20,260,"kol ochkov");
		 settextstyle(0,1,1);
		 settextjustify(2,2);

		 cc=fir;
		 for(i=1; i<11; i++)
		       {
		       strcpy(ss,cc->t.str);
		       ss[9]='\0';
		       outtextxy(x,405,ss);
		       x=x+40;
		       cc=cc->next;
		       }

		 settextstyle(0,0,1);
		 settextjustify(2,1);
		 for (i=0; i<22; i++)
		       {
		       line(55,y,65,y);
		       itoa(i,s,10);
		       outtextxy(55,y,s);
		       y=y-10;
		       }

		 setcolor(2);
		 x=70;
		 for (i=0;i<10;i++)
		       {
		       setfillstyle(1,i+1);
		       bar(x,400-a[i]*10,x+30,399);
		       settextjustify(1,0);
		       itoa(a[i],s,10);
		       outtextxy(x+15,395-a[i]*10,s);
		       x=x+40;
		       }
		ochisstt();
		getch();
		closegraph();
	}
void diagrzg()
	{
	int gd,gm,a[10],i=0,x=85,y=400;
	char s[3],ss[15];
		gd=DETECT;
		initgraph(&gd,&gm,"c:\\borlandc\\bgi");


		 pfstt(sl6);
		 cc=fir;
		 for(i=0;i<10;i++)
			{
			a[i]=cc->t.zg;
			cc=cc->next;
			}

		 line(60,20,60,400);
		 line(60,400,500,400);
		 line(60,20,55,25);
		 line(60,20,65,25);
		 line(500,400,495,395);
		 line(500,400,495,405);
		 settextstyle(0,0,1);
		 settextjustify(1,1);
		 outtextxy(485,420,"nzkom");
		 settextstyle(0,1,1);
		 settextjustify(2,2);
		 outtextxy(20,260,"kol ochkov");
		 settextstyle(0,1,1);
		 settextjustify(2,2);

		 cc=fir;
		 for(i=1; i<11; i++)
		       {
		       strcpy(ss,cc->t.str);
		       ss[9]='\0';
		       outtextxy(x,405,ss);
		       x=x+40;
		       cc=cc->next;
		       }

		 settextstyle(0,0,1);
		 settextjustify(2,1);
		 for (i=0; i<37; i++)
		       {
		       line(55,y,65,y);
		       itoa(i,s,10);
		       outtextxy(55,y,s);
		       y=y-10;
		       }

		 setcolor(2);
		 x=70;
		 for (i=0;i<10;i++)
		       {
		       setfillstyle(1,i+1);
		       bar(x,400-a[i]*10,x+30,399);
		       settextjustify(1,0);
		       itoa(a[i],s,10);
		       outtextxy(x+15,395-a[i]*10,s);
		       x=x+40;
		       }
		ochisstt();
		getch();
		closegraph();
	}

void menu()
	{
	menuzg(0);
	textcolor(12);
	gotoxy(33,14);
	cprintf("1.Start");

	gotoxy(33,15);
	cprintf("2.Vivodi");

	gotoxy(33,16);
	cprintf("3.Redoktirovanie");

	gotoxy(33,17);
	cprintf("4.Zagruzit save");

	gotoxy(33,18);
	cprintf("5.Udalit save");

	textcolor(13);
	gotoxy(33,19);
	cprintf("0.   Quit");

	textcolor(10);
	gotoxy(33,20);
	cprintf("Vash vibor: ");
	}
void menuv()
	{
	menuzg(0);
	textcolor(12);
	gotoxy(23,14);
	cprintf("1.Vivod uchastnikov chempionata");
	gotoxy(23,15);
	cprintf("2.Vivod otdelno informaciu o komande");
	gotoxy(23,16);
	cprintf("3.Vivod otdelno informaciu o igroke");
	gotoxy(23,17);
	cprintf("4.Vivod tablici igrokov po poziciyam");
	textcolor(13);
	gotoxy(23,18);
	cprintf("0.         Nazad");
	textcolor(10);
	gotoxy(23,19);
	cprintf("Vash vibor: ");
	textcolor(15);
	}
void menur()
	{
	menuzg(0);
	textcolor(12);
	gotoxy(28,14);
	cprintf("1.Otredoktirovat komandu");
	gotoxy(28,15);
	cprintf("2.Otredoktirovat igroka");
	gotoxy(28,16);
	cprintf("3.Sdelat zamenu");
	textcolor(13);
	gotoxy(28,17);
	cprintf("0.      Nazad");
	textcolor(10);
	gotoxy(28,18);
	cprintf("Vash vibor: ");
	}
void menuv2()
	{
	menuzg(0);
	textcolor(12);
	gotoxy(33,14);
	cprintf("1.Sami vvedete");
	gotoxy(33,15);
	cprintf("2.Viberetie iz spiska");
	textcolor(13);
	gotoxy(33,16);
	cprintf("0.       Nazad");
	textcolor(10);
	gotoxy(33,17);
	cprintf("Vash vibor: ");
	}
void menuvp()
	{
	menuzg(0);
	textcolor(12);
	gotoxy(33,14);
	cprintf("1.Vratar");
	gotoxy(33,15);
	cprintf("2.Zashitnik");
	gotoxy(33,16);
	cprintf("3.Huvback");
	gotoxy(33,17);
	cprintf("4.Forvard");
	gotoxy(33,18);
	textcolor(13);
	cprintf("0.Nazad");
	textcolor(10);
	gotoxy(33,19);
	cprintf("Vash vibor: ");
	}
void menugr(int i)
	{
	menuzg(0);
	textcolor(12);
	gotoxy(28,14);
	if (i==1) cprintf("1.Sigrat pervii igri v gruppah");
	if (i==2) cprintf("1.Sigrat vtorii igri v gruppah");
	if (i==3) cprintf("1.Sigrat poslednii igri v gruppah");
	if (i==4) cprintf("1.Pereiti v 1/8");
	gotoxy(28,15);
	cprintf("2.Prosmotret gruppi");
	gotoxy(28,16);
	cprintf("3.Prosmotret ttablicu");
	gotoxy(28,17);
	cprintf("4.Vivodi");
	gotoxy(28,18);
	cprintf("5.Redoktirovanie");
	textcolor(13);
	gotoxy(28,19);
	cprintf("0.Viti v glmenu i sohr");
	textcolor(10);
	gotoxy(28,20);
	cprintf("Vash vibor: ");
	}
void menuvb(int i)
	{
	menuzg(0);
	textcolor(12);
	gotoxy(28,14);
	if (i==1) cprintf("1.Pereiti v 1/4");
	if (i==2) cprintf("1.Pereiti v 1/2");
	if (i==3) cprintf("1.Pereiti v FINAL");
	if (i==4) cprintf("1.FINAL");
	gotoxy(28,15);
	cprintf("2.Prosmotret rezultati");
	gotoxy(28,16);
	cprintf("3.Prosmotret ttablicu");
	if (i==4)
		{
		gotoxy(28,17);
		cprintf("4.Posmotret diagramu");
		gotoxy(28,18);
		cprintf("5.Vivodi");
		gotoxy(28,19);
		cprintf("6.Redoktirovanie");
		textcolor(13);
		gotoxy(28,20);
		cprintf("0.Viti v glmenu i sohr");
		textcolor(10);
		gotoxy(28,21);
		cprintf("Vash vibor: ");
		}
	else
		{
		gotoxy(28,17);
		cprintf("4.Vivodi");
		gotoxy(28,18);
		cprintf("5.Redoktirovanie");
		textcolor(13);
		gotoxy(28,19);
		cprintf("0.Viti v glmenu i sohr");
		textcolor(10);
		gotoxy(28,20);
		cprintf("Vash vibor: ");
		}
	}
void menuzg(int l)
	{
	textcolor(14);
	gotoxy(33,10);
	cprintf("FIFA WORLD CUP");
	gotoxy(34,11);
	cprintf("GERMANY 2006");
	if (!l) {
		textcolor(15);
		gotoxy(37,13);
		cprintf("MENU:");
		}
	}
void vivmenu(int l)
	{
	int x1,x2,tn,tn1;
	char nz[20],nz1[20];
	do
		      {
		      clrscr();
		      menuv();
		      cin>>x1;
		      switch (x1)
			 {
			 case 1: clrscr();
				 vivod(sl);
				 break;
			 case 2: do
				   {
				   clrscr();
				   menuv2();
				   cin>>x2;
				   textcolor(9);
				   switch(x2)
				     {
				     case 1: clrscr();
					     menuzg(1);
					     textcolor(9);
					     gotoxy(28,13);
					     cprintf("Vvedite naz zbornoi: ");
					     gets(nz);
					     textcolor(15);
					     vivodim(sl,nz);
					     break;
				     case 2: do
					       {
					       clrscr();
					       vivodtn(sl);
					       cin>>tn;
					       strcpy(nz,vibor(sl,tn));
					       clrscr();
					       textcolor(15);
					       if (tn!=0 && tn<l && tn>-1) vivodim(sl,nz);
					       textcolor(9);
					       }
					     while (tn);
					     break;
				     }
				   }
				 while(x2);
				 break;
			 case 3: do
				   {
				   clrscr();
				   menuv2();
				   cin>>x2;
				   textcolor(9);
				   switch(x2)
				     {
				     case 1: clrscr();
					     menuzg(1);
					     textcolor(9);
					     gotoxy(28,13);
					     cprintf("Vvedite naz igroka: ");
					     gets(nz);
					     vivodigr(sl,nz);
					     break;
				     case 2: do
					       {
					       clrscr();
					       vivodtn(sl);
					       cin>>tn;
					       textcolor(9);
					       strcpy(nz,vibor(sl,tn));
					       if (tn!=0 && tn<l && tn>0)
						 do
						   {
						   clrscr();
						   vivodti(sl,nz);
						   cin>>tn1;
						   textcolor(9);
						   strcpy(nz1,vibor1(sl,nz,tn1));
						   clrscr();
						   if (tn1!=0 && tn1<16 && tn1>-1) vivodigr(sl,nz1);
						   textcolor(9);
						   }
						 while(tn1);
					       }
					     while (tn);
					     break;
				     }
				   }
				 while(x2);
				 break;
			 case 4: do
				   {
				   clrscr();
				   menuvp();
				   cin>>x2;
				   textcolor(15);
				   switch(x2)
				     {
				     case 1: clrscr();
					     vivodpoz(sl,"Vratar");
					     break;
				     case 2: clrscr();
					     vivodpoz(sl,"Zashitnik");
					     break;
				     case 3: clrscr();
					     vivodpoz(sl,"Huvback");
					     break;
				     case 4: clrscr();
					     vivodpoz(sl,"Forvard");
					     break;

				     }
				   }
				 while(x2);
				 break;
			 }
		      }
		    while(x1);
	}
void redmenu(int l)
	{
	int x1,x2,tn,tn1;
	char nz[20],nz1[20];
	do
		      {
		      clrscr();
		      menur();
		      cin>>x1;
		      switch(x1)
			{
			case 1: do
				  {
				  clrscr();
				  menuv2();
				  cin>>x2;
				  textcolor(9);
				  switch(x2)
				    {
				    case 1: clrscr();
					    menuzg(1);
					    textcolor(9);
					    gotoxy(28,13);
					    cout<<"Vvedite stranu: ";
					    gets(nz);
					    textcolor(15);
					    redkom(sl,nz);
					    break;
				    case 2: do
					      {
					      clrscr();
					      vivodtn(sl);
					      cin>>tn;
					      textcolor(9);
					      strcpy(nz,vibor(sl,tn));
					      clrscr();
					      if (tn!=0 && tn<l && tn>-1) {textcolor(15); redkom(sl,nz);}
					      textcolor(9);
					      }
					    while (tn);
					    break;
				    }
				  }
				while(x2);
				break;
			case 2: do
				   {
				   clrscr();
				   menuv2();
				   cin>>x2;
				   textcolor(9);
				   switch(x2)
				     {
				     case 1: clrscr();
					     menuzg(1);
					     textcolor(9);
					     gotoxy(28,13);
					     cout<<"Vvedite naz igroka: ";
					     gets(nz);
					     textcolor(15);
					     redigr(sl,nz);
					     break;
				     case 2: do
					       {
					       clrscr();
					       vivodtn(sl);
					       cin>>tn;
					       textcolor(9);
					       strcpy(nz,vibor(sl,tn));
					       if (tn!=0 && tn<l && tn>0)
						 do
						   {
						   clrscr();
						   vivodti(sl,nz);
						   cin>>tn1;
						   textcolor(9);
						   strcpy(nz1,vibor1(sl,nz,tn1));
						   clrscr();
						   if (tn1!=0 && tn1<16 && tn1>-1) {textcolor(15);redigr(sl,nz1);}
						   textcolor(9);
						   }
						 while(tn1);
					       }
					     while (tn);
					     break;
				     }
				   }
				 while(x2);
				 break;
			case 3: do
				  {
				  clrscr();
				  menuv2();
				  cin>>x2;
				  textcolor(9);
				  switch(x2)
				    {
				    case 1: clrscr();
					    menuzg(1);
					    textcolor(9);
					    gotoxy(28,13);
					    cout<<"Vvedite stranu: ";
					    gets(nz);
					    zamena(sl,nz);
					    break;
				    case 2: do
					      {
					      clrscr();
					      vivodtn(sl);
					      cin>>tn;
					      textcolor(9);
					      strcpy(nz,vibor(sl,tn));
					      clrscr();
					      if (tn!=0 && tn<l && tn>-1) zamena(sl,nz);
					      textcolor(9);
					      }
					    while (tn);
					    break;
				    }
				  }
				while(x2);
				break;

			}
		      }
		    while(x1);
	}
void grvmenu()
	{
	int x2,x3;
		do
			{
			clrscr();
			menuzg(0);
			textcolor(9);
			gotoxy(36,14);
			cprintf("1.Odnu");
			gotoxy(36,15);
			cprintf("2.Vse");
			textcolor(13);
			gotoxy(36,16);
			cprintf("0.Nazad");
			textcolor(10);
			gotoxy(36,17);
			cprintf("Vash vibor: ");
			cin>>x2;
			textcolor(9);
			switch (x2)
				{
				case 1: do
						{
						clrscr();
						menuzg(0);
						textcolor(9);
						gotoxy(36,14);
						cprintf("1.A");
						gotoxy(36,15);
						cprintf("2.B");
						gotoxy(36,16);
						cprintf("3.C");
						gotoxy(36,17);
						cprintf("4.D");
						gotoxy(36,18);
						cprintf("5.E");
						gotoxy(36,19);
						cprintf("6.F");
						gotoxy(36,20);
						cprintf("7.G");
						gotoxy(36,21);
						cprintf("8.H");
						textcolor(13);
						gotoxy(36,22);
						cprintf("0.Nazad");
						textcolor(10);
						gotoxy(36,23);
						cprintf("Vash vibor: ");
						cin>>x3;
						textcolor(9);
						switch (x3)
							{
							case 1: vv1gruppi(sl1,"A"); break;
							case 2: vv1gruppi(sl1,"B"); break;
							case 3: vv1gruppi(sl1,"C"); break;
							case 4: vv1gruppi(sl1,"D"); break;
							case 5: vv1gruppi(sl1,"E"); break;
							case 6: vv1gruppi(sl1,"F"); break;
							case 7: vv1gruppi(sl1,"G"); break;
							case 8: vv1gruppi(sl1,"H"); break;
							}
						}
					while(x3);
					break;
				case 2: vvgruppi(sl1); break;
				}
			}
		while(x2);
	}
void me1g(int l)
	{
	int x1;
	clrscr();
	if (l)
		{
		sogruppi(sl1);
		menuzg(1);
		textcolor(13);
		gotoxy(23,13);
		cprintf("Novost: ");
		textcolor(10);
		gotoxy(23,14);
		cprintf("   Bila provedena gerebyovka grupp");

		textcolor(12);
		gotoxy(34,16);
		cprintf("Press any key");

		sozdtt(sl6);
		ogtt();
		getch();
		}
	    do
		{
		clrscr();
		menugr(1);
		cin>>x1;
		switch (x1)
			{
			case 1: me2g(1);  break;
			case 2: grvmenu(); break;
			case 3: vivodtt(sl6); break;
			case 4: vivmenu(33); break;
			case 5: redmenu(33); break;
			}
		}
	    while(x1);
	    msave(1);
	    mefirst();
	    //_exit(0);
	}
void me2g(int l)
	{
	int x2;
	clrscr();
	if (l)
		{
		menuzg(1);
		textcolor(13);
		gotoxy(23,13);
		cprintf("Novost: ");
		textcolor(9);
		gotoxy(23,14);
		cprintf("   Rezultati pervih matchei");
		fgi(1);
		ogtt();
		textcolor(12);
		gotoxy(34,34);
		cprintf("Press any key");
		getch();
		}
	do
		{
		clrscr();
		menugr(2);
		cin>>x2;
		switch (x2)
			{
			case 1: me3g(1);  break;
			case 2: grvmenu(); break;
			case 3: vivodtt(sl6); break;
			case 4: vivmenu(33); break;
			case 5: redmenu(33); break;
			}
		}
		while(x2);
		msave(2);
		mefirst();
		//_exit(0);
	}
void me3g(int l)
	{
	int x3;
	clrscr();
	if (l)
		{
		menuzg(1);
		textcolor(13);
		gotoxy(23,13);
		cprintf("Novost: ");
		textcolor(9);
		gotoxy(23,14);
		cprintf("   Rezultati vtorih matchei");
		fgi(2);
		ogtt();
		textcolor(12);
		gotoxy(34,34);
		cprintf("Press any key");
		getch();
		}
		do
			{
			clrscr();
			menugr(3);
			cin>>x3;
			textcolor(9);
			switch (x3)
				{
				case 1: me4g(1);  break;
				case 2: textcolor(9);grvmenu(); break;
				case 3: vivodtt(sl6); break;
				case 4: vivmenu(33); break;
				case 5: redmenu(33); break;
				}
			}
		while(x3);
		msave(3);
		mefirst();
		//_exit(0);
	}
void me4g(int l)
	{
	int x3;
	clrscr();
	if (l)  {
		menuzg(1);
		textcolor(13);
		gotoxy(23,13);
		cprintf("Novost: ");
		textcolor(9);
		gotoxy(23,14);
		cprintf("   Rezultati tretih matchei");
		fgi(3);
		ogtt();
		uvkg(sl1);
		textcolor(12);
		gotoxy(34,34);
		cprintf("Press any key");


		getch();
		}
		do
			{
			clrscr();
			menugr(4);
			cin>>x3;
			textcolor(9);
			switch (x3)
				{
				case 1: me18(1);break;
				case 2: grvmenu(); break;
				case 3: vivodtt(sl6); break;
				case 4: vivmenu(17); break;
				case 5: redmenu(17); break;
				}
			}
		while(x3);
		msave(4);
		mefirst();
		//_exit(0);
	}
void me18(int l)
	{
	int x3;
	clrscr();
	if (l)  {
		menuzg(1);
		textcolor(13);
		gotoxy(23,13);
		cprintf("Novost: ");
		textcolor(9);
		gotoxy(23,14);
		cprintf("   Rezultati 1/8");
		psozdpg(sl2);
		ipg(sl2);
		pvtt(sl2);
		vivodpg(sl2);
		textcolor(12);
		gotoxy(34,28);
		cprintf("Press any key");
		getch();
		}
		do
			{
			clrscr();
			menuvb(1);
			cin>>x3;
			switch (x3)
				{
				case 1: me14(1);break;
				case 2: clrscr();
					menuzg(1);
					textcolor(9);
					gotoxy(31,13);
					cprintf("Rezultati 1/8");
					vivodpg(sl2);
					textcolor(12);
					gotoxy(34,28);
					cprintf("Press any key");
					getch();
					break;
				case 3: vivodtt(sl6); break;
				case 4: vivmenu(9); break;
				case 5: redmenu(9); break;
				}
			}
		while(x3);
		msave(5);
		mefirst();
		//_exit(0);
	}
void me14(int l)
	{
	int x3;
	clrscr();
	if (l)  {
		menuzg(1);
		textcolor(13);
		gotoxy(23,13);
		cprintf("Novost: ");
		textcolor(9);
		gotoxy(23,14);
		cprintf("   Rezultati 1/4");

		sozdpg(sl2,sl3);
		ipg(sl3);
		pvtt(sl3);
		vivodpg(sl3);

		textcolor(12);
		gotoxy(34,22);
		cprintf("Press any key");
		getch();


		}
		do
			{
			clrscr();
			menuvb(2);
			cin>>x3;
			switch (x3)
				{
				case 1: me12(1); break;
				case 2: clrscr();
					menuzg(1);
					textcolor(9);
					gotoxy(31,13);
					cprintf("Rezultati 1/4");
					vivodpg(sl3);
					textcolor(12);
					gotoxy(34,22);
					cprintf("Press any key");
					getch();
					break;
				case 3: vivodtt(sl6); break;
				case 4: vivmenu(5); break;
				case 5: redmenu(5); break;
				}
			}
		while(x3);
		msave(6);
		mefirst();
		//_exit(0);
	}
void me12(int l)
	{
	int x3;
	clrscr();
	if (l)  {
		menuzg(1);
		textcolor(13);
		gotoxy(23,13);
		cprintf("Novost: ");
		textcolor(9);
		gotoxy(23,14);
		cprintf("   Rezultati 1/2");

		sozdpg(sl3,sl4);
		ipg(sl4);
		pvtt(sl4);
		vivodpg(sl4);

		textcolor(12);
		gotoxy(34,20);
		cprintf("Press any key");
		getch();
		}
		do
			{
			clrscr();
			menuvb(3);
			cin>>x3;
			switch (x3)
				{
				case 1: mefinal(1);break;
				case 2: clrscr();
					menuzg(1);
					textcolor(9);
					gotoxy(31,13);
					cprintf("Rezultati 1/4");
					vivodpg(sl4);
					textcolor(12);
					gotoxy(34,20);
					cprintf("Press any key");
					getch();
					break;
				case 3: vivodtt(sl6); break;
				case 4: vivmenu(2); break;
				case 5: redmenu(2); break;
				}
			}
		while(x3);
		msave(7);
		mefirst();
		//_exit(0);
	}
void mefinal(int l)
	{
	int x3,x4;
	clrscr();
	if (l)  {
		menuzg(1);
		textcolor(13);
		gotoxy(23,13);
		cprintf("Novost: ");
		textcolor(9);
		gotoxy(23,14);
		cprintf("   Rezultat FINALA");

		sozdpg(sl4,sl5);
		ipg(sl5);
		pvtt(sl5);
		vivodpg(sl5);

		textcolor(12);
		gotoxy(34,20);
		cprintf("Press any key");
		getch();

		}
		do
			{
			clrscr();
			menuvb(4);
			cin>>x3;
			switch (x3)
				{
				case 1: clrscr();
					menuzg(1);
					textcolor(12);
					gotoxy(25,13);
					cprintf(oprc());
					cprintf(" CHAMPION!!!!!!!!");
					getch(); break;
				case 2: clrscr();
					menuzg(1);
					textcolor(9);
					gotoxy(31,13);
					cprintf("Rezultat FINALA");
					vivodpg(sl5);
					textcolor(12);
					gotoxy(34,20);
					cprintf("Press any key");
					getch();
					break;
				case 3: vivodtt(sl6); break;
				case 4: do
						{
						clrscr();
						textcolor(14);
						gotoxy(33,7);
						cprintf("FIFA WORLD CUP");
						gotoxy(34,8);
						cprintf("GERMANY 2006");

						textcolor(12);
						gotoxy(28,10);
						cprintf("1.Diagrama po ochkam");
						gotoxy(28,11);
						cprintf("2.Diagrama po zab golam");
						textcolor(13);
						gotoxy(28,12);
						cprintf("0.  Nazad");
						textcolor(10);
						gotoxy(28,13);
						cprintf("Vash vibor: ");
						cin>>x4;
						switch (x4)
							{
							case 1: diagro(); break;
							case 2: diagrzg(); break;
							}
						}
					while (x4);
					break;
				case 5: vivmenu(2); break;
				case 6: redmenu(2); break;
				}
			}
		while(x3);
		msave(8);
		mefirst();
		//_exit(0);
	}
void mefirst()
	{
	int x=1,x1;
	while(x)
	  {
	  clrscr();
	  menu();
	  cin>>x;
	  switch (x)
	    {
	    case 1: copyf(); me1g(1); break;
	    case 2: if (rsave()>3)
			do
				{
				clrscr();
				menuzg(0);
				textcolor(12);
				gotoxy(23,14);
				cprintf("Tak kak u vas est save sdelaite vibor");
				gotoxy(23,15);
				cprintf("1.Udalit save i prosm polnoceno fail");
				gotoxy(23,16);
				cprintf("2.Ne udalat save i prosm nepolnoceno fail");
				gotoxy(23,17);
				textcolor(13);
				cprintf("0.         Nazad");
				gotoxy(23,18);
				textcolor(10);
				cprintf("Vash vibor: ");

				cin>>x1;
				switch(x1)
					{
					case 1: unlink(sl7); copyf(); vivmenu(33); x1=0; break;
					case 2: if (rsave()==4) vivmenu(17);
						if (rsave()==5) vivmenu(9);
						if (rsave()==6) vivmenu(5);
						if (rsave()==7||rsave()==8) vivmenu(2);
						break;
					}
				}
			while(x1);
		    else vivmenu(33);
		    break;
	    case 3: if (rsave()>3)
			do
				{
				clrscr();
				menuzg(0);
				textcolor(12);
				gotoxy(23,14);
				cprintf("Tak kak u vas est save sdelaite vibor");
				gotoxy(23,15);
				cprintf("1.Udalit save i redokt polnoceno fail");
				gotoxy(23,16);
				cprintf("2.Ne udalat save i redokt nepolnoceno fail");
				gotoxy(23,17);
				textcolor(13);
				cprintf("0.         Nazad");
				gotoxy(23,18);
				textcolor(10);
				cprintf("Vash vibor: ");
				cin>>x1;
				switch(x1)
					{
					case 1: unlink(sl7); copyf(); redmenu(33); x1=0; break;
					case 2: if (rsave()==4) redmenu(17);
						if (rsave()==5) redmenu(9);
						if (rsave()==6) redmenu(5);
						if (rsave()==7 || rsave()==8) redmenu(2);
						break;
					}
				}
			while(x1);
		    else redmenu(33);
		    break;
	    case 4: if (rsave()==1) me1g(0);
		    if (rsave()==2) me2g(0);
		    if (rsave()==3) me3g(0);
		    if (rsave()==4) me4g(0);
		    if (rsave()==5) me18(0);
		    if (rsave()==6) me14(0);
		    if (rsave()==7) me12(0);
		    if (rsave()==8) mefinal(0);
		    break;
	    case 5: copyf();
		    unlink(sl7);
		    unlink(sl6);
		    unlink(sl5);
		    unlink(sl4);
		    unlink(sl3);
		    unlink(sl2);
		    unlink(sl1);
		    break;
	    }
	   }
	_exit(0);
	}