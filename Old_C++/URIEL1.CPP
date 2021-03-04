
#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>
#include<time.h>
#include<fstream.h>
#include<string.h>
#include<ctype.h>

char schh[20];
void stud_next();
void menu1();
void op();
class festt
 {
  public:char school[10];
	 char fname[10];
	 char date[10];
 }fes;
class pas
 {
  public: char uname[10];
	  void checkpass(char temp[17]);
	  void inpass(char temp[17]);
	  void inpass2(char temp[17]);
	  void putpass(char temp[17])
		{
		  strcpy(pass,temp);
		}
	  char* getpass()
		{
		  return pass;
		}
  protected:char pass[17];

 }p,p1;

void pas::checkpass(char temp[17])
{
	int length,i=0,valid=1,upper=0,lower=0,digit=0,punct=0,print=0,sum=0;
	char ch;
	length=strlen(temp);
	if(length<8)
	{
		cout<<"\n\n\t\tPlease enter a password with a length greater than 8 characters\n";
		valid=0;
	}
	for(i=0;i<length;i++)
	{
		ch=temp[i];
		if(isupper(ch)&&upper==0)
			upper++;
		else if(islower(ch)&&lower==0)
			lower++;
		else if(isdigit(ch)&&digit==0)
			digit++;
		else if(ispunct(ch)&&punct==0)
			punct++;
		if(isprint(ch))
			print++;
	}
	sum=upper+lower+digit+punct;
	if(sum>=3&&print==length&&valid==1)
		cout<<"\n\n\t\t\tYour password is STRONG";
	else if(print!=length)
	{
		valid=0;
		cout<<"\n\n\t\tPlease enter valid characters only";
	}
	else if(upper==0||lower==0||digit==0||punct==0)
	{
		cout<<"\n\n\t\tYour password does not contain \n";
		valid=0;
		if(upper==0)
			cout<<"\t\tupper case characters\n";
		if(lower==0)
			cout<<"\t\tlower case characters\n";
		if(digit==0)
			cout<<"\t\tdigits\n";
		if(punct==0)
			cout<<"\t\tpunctuations\n";
	}
	if(valid==0)
	{
		cout<<"\n\n\t\tPlease try again!\n";
		getch();
		clrscr();
		cout<<endl<<endl<<endl;
		inpass(temp);
	}

}

void pas::inpass(char temp[17])
  {
    cout<<"\t\t\tPassword:";
    for(int i=0;i<16;i++)
      {
	temp[i]=getch();
	if(temp[i]==char(13))
	  {
	    temp[i]='\0';
	    break;
	  }
	else if(temp[i]==char(8)&&i==0)
	  {
		 i--;
	     continue;
	  }
	else if(temp[i]==char(8)&&i>0)
	  {
		cout<<'\b'<<" "<<'\b';
	    i-=2;
	  }

	else
	   cout<<"*";
      }
      temp[i]='\0';
      cout<<endl;
	  checkpass(temp);
 }


void pas::inpass2(char temp[17])
  {
    cout<<"\t\t\tPassword:";
    for(int i=0;i<16;i++)
      {
	temp[i]=getch();
	if(temp[i]==char(13))
	  {
	    temp[i]='\0';
	    break;
	  }
	else if(temp[i]==char(8)&&i==0)
	  {
		 i--;
	     continue;
	  }
	else if(temp[i]==char(8)&&i>0)
	  {
		cout<<'\b'<<" "<<'\b';
	    i-=2;
	  }

	else
	   cout<<"*";
      }
      temp[i]='\0';
      cout<<endl;
 }


class stud:public pas
 {
   public:
   char sna[30];    //School Name
   char stream[20]; //stream
   char rname[10];
   int count;
   void read()
   {
	cout<<"\n\t\tEnter the name of the .school. you study in\n";
	cout<<"\t\t"<<char(175);
	gets(sna);
	cout<<"\t\tEnter the .stream. that you have taken up\n";
	cout<<"\t\t"<<char(175);
	gets(stream);
   }

   void disp()
   {
	cout<<"The details are \n";
	cout<<sna<<stream;
   }
 }s,s1,gla;

class school:public pas
 {
  public:
  int ver;     //Blue Ticks
  char pro[20][10],pro1[20];
  void prom();
  void add_prom();
 }sc;

void school::add_prom()
{
 ofstream fout;
 char op;
 fout.open("School_Pro.txt",ios::app);
 char pro[40];
 do
  {
   cout<<"Please enter your promise";
   gets(pro);
   fout<<schh<<endl<<pro<<endl;
	cout<<"Do you want to enter another promise?(Y/N)\n";
	op=getch();
	if(op!='y'&&op!='Y')
	break;
  }while(1);
  fout.close();
  }


void school::prom()
{
 int i=0;
 ofstream fout;
 char op;
 fout.open("School_Pro.txt",ios::app);
 char pro[30],pro1[30];
 cout<<"Enter your promises one by one(at least 5)\n";
 do
  {
   cout<<"Enter promise no "<<i+1<<endl;
   gets(pro);
   fout<<schh<<endl<<pro<<endl;
   if(i>3)
   {
	cout<<"Do you want to enter another promise?(Y/N)\n";
	op=getch();
	if(op!='y'&&op!='Y')
	break;
   }
	i++;
  }while(1);
  fout.close();
}

class pos
{
  public: float x;
	  float y;
};

class player
{
  public:int slno;
	 char name[10];
	 int fcolour;
	 int point ;
	 pos pa;
	 int sum;
	 char symbol;
	 int l;
	 int bcolour;
};

class snake
{
  public:
  player p[2];
  int c[4],no,i;
  int sounds();
  int start_text();
  void s_load();
  void g_load();
  void colo();
  void info();
  void bcol();
  void snakes();
  void lad();
  void grid();
  void board();
  void position();
  void qn();
  void end();
  void die();
  void display();
  void game();
  };

//Function 1

int snake::sounds()
{
   clrscr();
   sound(900);
   delay(50);
   sound(1200);
   delay(50);
   sound(1500);
   delay(100);
   sound(900);
   delay(100);
   sound(1050);
   nosound();
   return 0;
}


//intro page function


int snake::start_text()
{
   sounds();

   /* select a driver and mode that supports */

   /* multiple background colors.            */

   int gdriver = EGA, gmode = EGAHI;
   int bkcol, maxcolor;
   char msg1[100],msg2[100],msg3[100],msg4[100],msg5[100];
   char msg6[100],msg7[100],msg8[100],msg9[100],msg10[100];
   char msg11[100],msg12[100],msg13[100],msg14[100],msg15[100];
   char msg16[100],msg17[100],msg18[100],msg19[100],msg20[100],msg21[100];

   /* initialize graphics and local variables */

   initgraph(&gdriver, &gmode, "\\TURBOC3\\BGI");


   /* loop through the available colors */

   for (bkcol=0; bkcol<=5; bkcol++)
   {
      if(bkcol==4||bkcol==2||bkcol==3||bkcol==7)
	  continue;

      /* clear the screen */

      cleardevice();
      if(bkcol!=0)
	 delay(500);

      /* select a new background color */

      setbkcolor(bkcol);

      /* output a messsage */

      if (bkcol == WHITE)
	 setcolor(EGA_BLUE);
      else
	 setcolor(bkcol+2*2+1);

      sprintf(msg1, "       ::::::::  ::::    :::     :::     :::    ::: :::::::::: ::::::::  ");
	  sprintf(msg2, "      :+:    :+: :+:+:   :+:   :+: :+:   :+:   :+:  :+:       :+:    :+: ");
      sprintf(msg3, "      +:+        :+:+:+  +:+  +:+   +:+  +:+  +:+   +:+       +:+         ");
      sprintf(msg4, "      +#++:++#++ +#+ +:+ +#+ +#++:++#++: +#++:++    +#++:++#  +#++:++#++  ");
      sprintf(msg5, "             +#+ +#+  +#+#+# +#+     +#+ +#+  +#+   +#+              +#+  ");
      sprintf(msg6, "      #+#    #+# #+#   #+#+# #+#     #+# #+#   #+#  #+#       #+#    #+#  ");
      sprintf(msg7, "       ########  ###    #### ###     ### ###    ### ########## ########    ");
      sprintf(msg8, "          :::     ::::    ::: :::::::::      ");
      sprintf(msg9, "        :+: :+:   :+:+:   :+: :+:    :+:    ");
      sprintf(msg10,"       +:+   +:+  :+:+:+  +:+ +:+    +:+   ");
      sprintf(msg11,"      +#++:++#++: +#+ +:+ +#+ +#+    +:+    ");
      sprintf(msg12,"      +#+     +#+ +#+  +#+#+# +#+    +#+   ");
      sprintf(msg13,"      #+#     #+# #+#   #+#+# #+#    #+#    ");
      sprintf(msg14,"      ###     ### ###    #### #########    ");
      sprintf(msg15, ":::            :::     :::::::::  :::::::::  :::::::::: :::::::::   ::::::::   ");
      sprintf(msg16, ":+:          :+: :+:   :+:    :+: :+:    :+: :+:        :+:    :+: :+:    :+:  ");
      sprintf(msg17, "+:+         +:+   +:+  +:+    +:+ +:+    +:+ +:+        +:+    +:+ +:+         ");
      sprintf(msg18, "+#+        +#++:++#++: +#+    +:+ +#+    +:+ +#++:++#   +#++:++#:  +#++:++#++  ");
	  sprintf(msg19, "+#+        +#+     +#+ +#+    +#+ +#+    +#+ +#+        +#+    +#+        +#+  ");
      sprintf(msg20, "#+#        #+#     #+# #+#    #+# #+#    #+# #+#        #+#    #+# #+#    #+#  ");
      sprintf(msg21, "########## ###     ### #########  #########  ########## ###    ###  ########   ");
	  outtextxy(0,10,msg1);
      outtextxy(0,25,msg2);
      outtextxy(0,40,msg3);
      outtextxy(0,55,msg4);
      outtextxy(0,70,msg5);
      outtextxy(0,85,msg6);
      outtextxy(0,100,msg7);
      outtextxy(120,130,msg8);
      outtextxy(120,145,msg9);
      outtextxy(120,160,msg10);
      outtextxy(120,175,msg11);
      outtextxy(120,190,msg12);
      outtextxy(120,205,msg13);
      outtextxy(120,220,msg14);
      outtextxy(10,250,msg15);
      outtextxy(10,265,msg16);
      outtextxy(10,280,msg17);
	  outtextxy(10,295,msg18);
      outtextxy(10,310,msg19);
      outtextxy(10,325,msg20);
	  outtextxy(10,340,msg21);
      delay(750);
   }

   /* clean up */

   clrscr();
   closegraph();
   clrscr();
   return 0;
}


//welcome Function


void snake::s_load()
{
    clrscr();
    delay(250);
	for(int j=1;j<=3;j++)
	 {
	   textcolor(YELLOW);
	   clrscr();
	   gotoxy(1,10);
		cprintf(",--. ,--.,--.   ,--.,------.,--.    ,-----. ,-----. ,--.   ,--.,------.,--. ,--. ");
	   gotoxy(1,11.5);
		cprintf("|  | |  ||  |   |  ||  .---'|  |   '  .--./'  .-.  '|   `.'   ||  .---'|  | |  | ");
	   gotoxy(1,12);
		cprintf("`-'  `-' |  |.'.|  ||  `--, |  |   |  |    |  | |  ||  |'.'|  ||  `--, `-'  `-'  ");
	   gotoxy(1,13.5);
		cprintf("         |   ,'.   ||  `---.|  '--.'  '--'\'   '-'  '|  |   |  ||  `---.          ");
	   gotoxy(1,14.5);
		cprintf("         '--'   '--'`------'`-----' `-----' `-----' `--'   `--'`------'          ");
	   gotoxy(32,1);
		{
		  textcolor(LIGHTGREEN);
			cprintf("\n\n\n\n\nLOADING");
		  delay(300);
			cprintf(" .");
		  delay(300);
			cprintf(" .");
		  delay(300);
			cprintf(" .");
		  delay(300);
		}
	  clrscr();

	 }

}


//loading function


void snake::g_load()
{
	clrscr();
	delay(250);

	for(int j=1;j<=3;j++)
	 {
	    clrscr();
	    textcolor(14);
	    gotoxy(25,20);
	    cprintf("\"MAY THE LADDERS BE WITH YOU\"");
	    gotoxy(32,1);
	       {
		 textcolor(10);
			cprintf("\n\n\n\n\nLOADING");
		 delay(300);
			cprintf(" .");
		 delay(300);
			cprintf(" .");
		 delay(300);
			cprintf(" .");
		 delay(300);
	       }
	   clrscr();

	 }
}


//colour options Function


void snake::colo()
{
 textcolor(15);
	cprintf("\t³ÍÍÍÍÍÍÍÍÍÍÍÍÍÍØÍÍÍÍÍÍÍÍÍÍÍÍÍØ");
	cout<<endl;
	cprintf("\t³ Colour       ³Colour number³");
	cout<<endl;
	cprintf("\t³ÍÍÍÍÍÍÍÍÍÍÍÍÍÍØÍÍÍÍÍÍÍÍÍÍÍÍÍØ");
	cout<<endl;
 textcolor(1);
	cprintf("\t³ BLUE         ³      1      ³");
	cout<<endl;
 textcolor(2);
	cprintf("\t³ GREEN        ³      2      ³");
	cout<<endl;
 textcolor(3);
	cprintf("\t³ CYAN         ³      3      ³");
	cout<<endl;
 textcolor(4);
	cprintf("\t³ RED          ³      4      ³");
	cout<<endl;
 textcolor(5);
	cprintf("\t³ MAGENTA      ³      5      ³");
	cout<<endl;
 textcolor(6);
	cprintf("\t³ BROWN        ³      6      ³");
	cout<<endl;
 textcolor(7);
	cprintf("\t³ LIGHTGRAY    ³      7      ³");
	cout<<endl;
 textcolor(8);
	cprintf("\t³ DARKGRAY     ³      8      ³");
	cout<<endl;
 textcolor(9);
	cprintf("\t³ LIGHTBLUE    ³      9      ³");
	cout<<endl;
 textcolor(10);
	cprintf("\t³ LIGHTGREEN   ³     10      ³");
	cout<<endl;
 textcolor(11);
	cprintf("\t³ LIGHTCYAN    ³     11      ³");
	cout<<endl;
 textcolor(12);
	cprintf("\t³ LIGHTRED     ³     12      ³");
	cout<<endl;
 textcolor(13);
	cprintf("\t³ LIGHTMAGENTA ³     13      ³");
	cout<<endl;
 textcolor(14);
	cprintf("\t³ YELLOW       ³     14      ³");
	cout<<endl;
 textcolor(15);
	cprintf("\t³ WHITE        ³     15      ³");
	cout<<endl;
	cprintf("\t³ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄ³");
	cout<<endl<<endl<<"\t";
}



//accepting player details Function


void snake::info()
{
  clrscr();
  randomize();
  int a;
  clrscr();
  textcolor(LIGHTRED);
  cout<<"\n\t";
  cprintf("Enter the Number of Players");
  cout<<"\n\t";
  cout<<">> ";
  cin>>no;

  if(no==0)
	exit(0);

  for(i=0;i<no;i++)
  {
    p[i].sum=0;
    p[i].l=0;
    cout<<'\t';
    cprintf("Enter the Name of Player %d : ",i+1);
    cin>>p[i].name;
    cout<<endl<<'\t';
    cprintf("Enter your colour out of these :- ");
    cout<<endl;
	colo();
    textcolor(LIGHTRED);
    cprintf("Your colour is number : ");
	textcolor(LIGHTGREEN);
    cin>>p[i].fcolour;
    textcolor(LIGHTRED);
    c[i]=p[i].fcolour;
    clrscr();

  }

}


//symbol  Function


void snake::bcol()
{
 for(i=0;i<no;i++)
	 {
      switch(p[i].fcolour)
	{
	 case 0:p[i].bcolour=15;
		p[i].symbol=(char)2;
		break;
	 case 1:p[i].bcolour=14;
		p[i].symbol=(char)30;
		break;
	 case 2:p[i].bcolour=13;
		p[i].symbol=(char)168;
		break;
	 case 3:p[i].bcolour=12;
		p[i].symbol=(char)224;
		break;
	 case 4:p[i].bcolour=11;
		p[i].symbol=(char)165;
		break;
	 case 5:p[i].bcolour=10;
		p[i].symbol=(char)12;
		break;
	 case 6:p[i].bcolour=9;
		p[i].symbol=(char)11;
		break;
	 case 7:p[i].bcolour=8;
		p[i].symbol=(char)35;
		break;
	 case 8:p[i].bcolour=7;
		p[i].symbol=(char)63;
		break;
	 case 9:p[i].bcolour=6;
		p[i].symbol=(char)64;
		break;
	 case 10:p[i].bcolour=5;
		 p[i].symbol=(char)127;
		 break;
	 case 11:p[i].bcolour=4;
		 p[i].symbol=(char)14;
		 break;
	 case 12:p[i].bcolour=3;
		 p[i].symbol=(char)227;
		 break;
	 case 13:p[i].bcolour=2;
		 p[i].symbol=(char)237;
		 break;
	 case 14:p[i].bcolour=1;
		 p[i].symbol=(char)233;
		 break;
	 case 15:p[i].bcolour=0;
		 p[i].symbol=(char)21;
		 break;
	 default:p[i].fcolour=5;
		 p[i].bcolour=10;
		 p[i].symbol=(char)12;
       }
     }
}


//snakes funtion


void snake::snakes()
	{
	  textcolor(9);
	  textbackground(0);


	 //snake 1   99 to 43

	  gotoxy(17,5);
	      cprintf("~");
	  gotoxy(18,5);
	      cprintf("%c%c",20,177);
	  gotoxy(19,6);
	      cprintf("%c",177);
	  gotoxy(19,7);
	      cprintf("%c",177);
	  gotoxy(19,8);
	      cprintf("%c",177);
	  gotoxy(19,9);
	      cprintf("%c",223);
	  gotoxy(20,9);
		  cprintf("%c",223);
	  gotoxy(21,9);
	      cprintf("%c",177);
	  gotoxy(21,10);
	      cprintf("%c",177);
	  gotoxy(21,11);
	      cprintf("%c",177);
	  gotoxy(20,11);
	      cprintf("%c",220);
	  gotoxy(19,11);
	      cprintf("%c",220);
	  gotoxy(18,11);
	      cprintf("%c",220);
	  gotoxy(17,11);
	      cprintf("%c",177);
	  gotoxy(17,10);
	      cprintf("%c",220);
	  gotoxy(18,10);
	      cprintf("%c",220);
	  gotoxy(19,10);
		  cprintf("%c",220);
	  gotoxy(19,11);
	      cprintf("%c",219);
	  gotoxy(19,12);
	      cprintf("%c",177);
	  gotoxy(19,13);
	      cprintf("%c",223);
	  gotoxy(20,13);
	      cprintf("%c",219);
	  gotoxy(20,14);
	      cprintf("%c",177);
	  gotoxy(20,15);
	      cprintf("%c",31);


	//snake 2  31 to 8


	  textcolor(12);
	  gotoxy(72,18);
		 cprintf("%c",234);
	  gotoxy(72,17);
	     cprintf(",");
	  gotoxy(72,19);
	     cprintf("%c",178);
	  gotoxy(72,20);
	     cprintf("%c",178);
	  gotoxy(71,21);
	     cprintf("%c",223);
	  gotoxy(72,21);
	     cprintf("%c",223);
	  gotoxy(70,21);
	     cprintf("%c",178);
	  gotoxy(68,22);
	     cprintf("%c",223);
	  gotoxy(69,22);
	     cprintf("%c",223);
	  gotoxy(70,22);
	     cprintf("%c",223);
	  textcolor(YELLOW);
	  gotoxy(69,23);
	      cprintf("9");
	  textcolor(12);
	  gotoxy(67,22);
	     cprintf("%c",178);
	  gotoxy(66,23);
	     cprintf("%c",223);
	  gotoxy(65,23);
	     cprintf("%c",223);
	  gotoxy(67,23);
	     cprintf("%c",223);
	  gotoxy(64,23);
	       cprintf("%c",2);
	  gotoxy(63,23);
	      cprintf("%c",14);
	  gotoxy(62,23.5);
	     cprintf("%c",174);


	  //snake 3  88 to 33


	   textcolor(11);
	   gotoxy(58,8);
	     cprintf("%c",142);
	   gotoxy(58,7);
	     cprintf(",");
	   gotoxy(58,10);
	     cprintf("%c",176);
	   gotoxy(58,9);
	     cprintf("%c",176);
	   gotoxy(58,11);
	     cprintf("%c",176);
	   gotoxy(58,12);
	     cprintf("%c",176);
	   gotoxy(58,13);
	     cprintf("%c",176);
	   gotoxy(58,14);
	     cprintf("%c",176);
	   gotoxy(58,15);
		 cprintf("%c",176);
	   gotoxy(58,16);
	     cprintf("%c",176);
	   gotoxy(58,17);
	     cprintf("%c",231);


	   // snake 4 55 to 24


	   textcolor(10);
	   gotoxy(43,15);
	     cprintf("%c",178);
	   gotoxy(43,14);
	     cprintf("%c",234);
	   gotoxy(43,13);
		  cprintf(",");
	   gotoxy(43,16);
	     cprintf("%c",178);
	   gotoxy(43,17);
		 cprintf("%c",223);
	   gotoxy(42,17);
	     cprintf("%c",223);
	   gotoxy(41,17);
	     cprintf("%c",223);
	   gotoxy(40,17);
	     cprintf("%c",178);
	   gotoxy(40,18);
	     cprintf("%c",223);
	   gotoxy(39,18);
	     cprintf("%c",223);
	   gotoxy(38,18);
	     cprintf("%c",223);
	   gotoxy(37,18);
	     cprintf("%c",223);
	   gotoxy(36,18);
	     cprintf("%c",223);
	   gotoxy(35,18);
	     cprintf("%c",223);
	   gotoxy(34,18);
		 cprintf("%c",223);
	   gotoxy(33,18);
	     cprintf("%c",178);
	   gotoxy(33,19);
	     cprintf("%c",157);
	 }


//ladder function


void snake::lad()
{
	textcolor(BLUE);
	textbackground(13);

  //ladder 1  49 to 70

   gotoxy(66,15);
      {
	   cprintf("%c",237);
	   textcolor(14);
	   textbackground(0);
	   cprintf(" 49 ");
	   textcolor(1);
	   textbackground(13);
	   cprintf("%c",237);
      }
   gotoxy(67,14);
      {
	   cprintf("%c",237);
	   cprintf("****");
	   cprintf("%c",237);
      }
   gotoxy(65.5,13);
      {
	   textcolor(14);
	   textbackground(0);
	   cprintf("52 ");
	   textcolor(1);
	   textbackground(13);
	   cprintf("%c",237);
	   textbackground(0);
	   cprintf("  ");
	   textbackground(0);
	   textcolor(RED+128);
	   cprintf("%c",157);
	   cprintf(" ");
	   textcolor(1);
	   textbackground(13);
	   cprintf("%c",237);

      }
   gotoxy(69,12);
      {
	   cprintf("%c",237);
	   cprintf("****");
	   cprintf("%c",237);
      }
   gotoxy(70,11);
	   {
	   cprintf("%c",237);
	   textcolor(RED+BLINK);
	   textbackground(0);
	   cprintf("%c",157);
	   textcolor(1);
	   textbackground(0);
	   cprintf("   ");
	   textbackground(13);
	   cprintf("%c",237);
	   textcolor(14);
	   textbackground(0);
	   cprintf("70");
      }
   gotoxy(71,10);
       {
	   textcolor(1);
	   textbackground(13);
	   cprintf("%c",237);
	   cprintf("****");
	   cprintf("%c",237);
      }
   gotoxy(72,9);
       cprintf("%c",237);
   gotoxy(77.5,9);
       cprintf("%c",237);


   //ladder 2 19 to 40

   textcolor(6);
   textbackground(0);
   gotoxy(12,21);
       {
	   cprintf("%c",92);
	   cprintf("%c",219);
	   textcolor(14);
	   textbackground(0);
	   cprintf("19");
	   textcolor(6);
	   textbackground(0);
	   cprintf("%c",219);
	   cprintf("%c",92);
	  }
   gotoxy(10,20);
      {
	   cprintf("%c",92);
	   cprintf("%c",219);
	   cprintf("**");
	   cprintf("%c",219);
	   cprintf("%c",92);
	  }
   gotoxy(6,19);
      {    textcolor(14);
	   textbackground(0);
	   cprintf("21");
	   textcolor(6);
	   textbackground(0);
	   cprintf("%c",92);
	   cprintf("%c",219);
	  }
   gotoxy(13,19);
      {
	   cprintf("%c",219);
	   cprintf("%c",92);
	  }
   gotoxy(7,18);
       {
	   cprintf("%c",92);
	   cprintf("%c",219);
	   cprintf("**");
	   cprintf("%c",219);
	   cprintf("%c",92);
	  }
   gotoxy(5,17);
       {
	   cprintf("%c",92);
	   cprintf("%c",219);
	   textcolor(14);
	   textbackground(0);
	   cprintf("40");
	   textcolor(6);
	   textbackground(0);
	   cprintf("%c",219);
	   cprintf("%c",92);
	  }


       // ladder 3 57 to 77

   textcolor(13);
   textbackground(0);
   gotoxy(28,13);
      cprintf("%c",223);
   gotoxy(33,13);
      cprintf("%c",223);
   gotoxy(28,12);
	  {
	   cprintf("%c",219);
	   cprintf("####");
	   cprintf("%c",219);
	  }
   gotoxy(28,11);
      cprintf("%c",219);
   gotoxy(33,11);
      cprintf("%c",219);
   gotoxy(28,10);
      {
       cprintf("%c",219);
	   cprintf("####");
	   cprintf("%c",219);
	  }
   textbackground(0);
   gotoxy(28,9);
      cprintf("%c",220);
   gotoxy(33,9);
      cprintf("%c",220);

}


//grid funtion


void snake::grid()
{
  clrscr();

  system("cls");
  int i;

  for(i=5;i<80;i++)
   {
       textcolor(RED+BLINK);
       textbackground(0);
       gotoxy(i,3.2);
	   cprintf("-");
	   gotoxy(i,4);
	   cprintf("%c",26);
       gotoxy(i,6);
	   cprintf("%c",26);
       gotoxy(i,8);
	   cprintf("%c",26);
       gotoxy(i,10);
	   cprintf("%c",26);
       gotoxy(i,12);
	   cprintf("%c",26);
       gotoxy(i,14);
	   cprintf("%c",26);
       gotoxy(i,16.2);
	   cprintf("%c",26);
       gotoxy(i,18.4);
	   cprintf("%c",26);
       gotoxy(i,20.6);
	   cprintf("%c",26);
       gotoxy(i,22.8);
	   cprintf("%c",26);
       gotoxy(i,24.6);
	   cprintf("%c",26);
       gotoxy(i,25.4);
	   cprintf("-");
   }

   for(i=4;i<25;i++)
   {
       gotoxy(3,i);
	   cprintf("|%c",157);
       gotoxy(11.5,i);
	   cprintf("%c",157);
       gotoxy(19,i);
	   cprintf("%c",157);
       gotoxy(26.5,i);
	   cprintf("%c",157);
       gotoxy(34,i);
	   cprintf("%c",157);
       gotoxy(41.5,i);
	   cprintf("%c",157);
	   gotoxy(49,i);
	   cprintf("%c",157);
       gotoxy(56.5,i);
	   cprintf("%c",157);
       gotoxy(64,i);
	   cprintf("%c",157);
       gotoxy(71.5,i);
	   cprintf("%c",157);
       gotoxy(79,i);
	   cprintf("%c|",157);
   }
}


//displaying numbers funtion


void snake::board()
 {
    textcolor(YELLOW);
	textbackground(0);
    float x=7.5;

	 for(int i=1;i<=10;i++)
	   {
	     if(i!=9)
	       {
		 gotoxy(x,23);
		    cprintf("%d",i);
	       }
	     x+=7.5;
	   }

	 for(i=11,x=75;i<=20;i++,x-=7.5)
	   {
	      gotoxy(x,21);
		 cprintf("%d",i);
	   }

	 for(i=21,x=7.5;i<=30;i++)
	   {
	      gotoxy(x,19);
		 cprintf("%d",i);
		  x+=7.5;
	   }

	 for(i=31,x=75;i<=40;i++,x-=7.5)
	   {
	      gotoxy(x,17);
		 cprintf("%d",i);
	   }

	 for(i=41,x=7.5;i<=50;i++)
	   {
	      gotoxy(x,15);
		 cprintf("%d",i);
	     x+=7.5;
	   }

	 for(i=51,x=75;i<=60;i++,x-=7.5)
	   {
	      gotoxy(x,13);
		 cprintf("%d",i);
	   }

	 for(i=61,x=7.5;i<=70;i++)
	   {
	      gotoxy(x,11);
		 cprintf("%d",i);
	      x+=7.5;
	   }

	 for(i=71,x=75;i<=80;i++,x-=7.5)
	   {
	      gotoxy(x,9);
		 cprintf("%d",i);
	   }

	 for(i=81,x=7.5;i<=90;i++)
	   {
		  gotoxy(x,7);
		 cprintf("%d",i);
	      x+=7.5;
	   }

	 for(i=91,x=75;i<=100;i++,x-=7.5)
	   {
	      gotoxy(x,5);
		 cprintf("%d",i);
	   }

 }


//position function


void snake::position()
{
      if(p[i].sum>0&&p[i].sum<11)
	  {
	     p[i].pa.x=(7.5*p[i].sum)-(0.2*i);
	     p[i].pa.y=23;
	  }

      if(p[i].sum>10&&p[i].sum<21)
	  {
	     p[i].pa.x=(75-(7.5*(p[i].sum-11))-(0.2*i));
	     p[i].pa.y=21;
	  }

      if(p[i].sum>20&&p[i].sum<31)
	  {
	     p[i].pa.x=(7.5*(p[i].sum-20))-(0.2*i);
	     p[i].pa.y=19;
	  }

      if(p[i].sum>30&&p[i].sum<41)
	  {
	     p[i].pa.x=(75-(7.5*(p[i].sum-31))-(0.2*i));
		 p[i].pa.y=17;
	  }

	  if(p[i].sum>40&&p[i].sum<51)
	  {
	     p[i].pa.x=(7.5*(p[i].sum-40))-(0.2*i);
	     p[i].pa.y=15;
	  }

      if(p[i].sum>50&&p[i].sum<61)
	  {
	     p[i].pa.x=(75-(7.5*(p[i].sum-51))-(0.2*i));
	     p[i].pa.y=13;
	  }

      if(p[i].sum>60&&p[i].sum<71)
	  {
	     p[i].pa.x=(7.5*(p[i].sum-60))-(0.2*i);
	     p[i].pa.y=11;
	  }

      if(p[i].sum>70&&p[i].sum<81)
	  {
		 p[i].pa.x=(75-(7.5*(p[i].sum-71))-(0.2*i));
	     p[i].pa.y=9;
	  }

      if(p[i].sum>80&&p[i].sum<91)
	  {
	     p[i].pa.x=(7.5*(p[i].sum-80))-(0.2*i);
	     p[i].pa.y=7;
	  }

      if(p[i].sum>90&&p[i].sum<101)
	  {
	     p[i].pa.x=(75-(7.5*(p[i].sum-91))-(0.2*i));
	     p[i].pa.y=5;
	  }

    grid();
	board();
    snakes();
    lad();

    for(int k=0;k<no;k++)
     {
	textcolor(p[k].fcolour);
	gotoxy(p[k].pa.x,p[k].pa.y);
	     cprintf("%c",p[k].symbol);
     }

    gotoxy(p[i].pa.x,p[i].pa.y);
    {
       textcolor(p[i].fcolour);
	    cprintf("%c",p[i].symbol);
    }
}


//update function


void snake::qn()
 {
   delay(1500);
   clrscr();
   p[i].l++;
   char z[1000],ansi[5],anso[5];
   int k,q,m,n;
   cout<<"  Your Question is :"<<endl;
   cout<<"Qn no "<<p[i].sum<<endl;
   ifstream fin2,fin1;
   fin1.open("hello.txt");
   fin2.open("ans.txt");
   if(p[i].l>1)
     fin1.seekg(m,ios::cur);
   fin1.getline(z,1000,'|');
   m=fin1.tellg();
   cout<<m;
   getch();
   cout<<z;
   fin1.close();
   cout<<"Enter the correct options : ";
   cin>>ansi;
   if(p[i].l>1)
     fin2.seekg(n,ios::cur);
   fin2.getline(anso,5,'|');
   n=fin2.tellg();
   if(!strcmpi(ansi,anso))
     {
	   cout<<"\nIts the correct Answer\n"<<endl;
     }
   else
     {
	   cout<<"Sorry,Your was Incorrect\nThe correct answer is "<<anso;
     }
   if(p[i].sum==49||p[i].sum==19||p[i].sum==57)
    {
       clrscr();
       fin1.open("hots_qn.txt");
	   fin2.open("hots_ans.txt");
       cout<<"This is a bonus Question\n Answer it right and u go up the ladder\n";
       if(p[i].l>1)
	  fin1.seekg(k);
       fin1.getline(z,1000,'|');
       k=fin1.tellg();
       cout<<z;
       fin1.close();
       cout<<"Enter the correct options : ";
       cin>>ansi;
       if(p[i].l>1)
	 fin2.seekg(q);
       fin2.getline(anso,5,'|');
       q=fin2.tellg();
       getch();
       if(!strcmpi(ansi,anso))
	 {
	   cout<<"\nIts the correct Answer\nYou have climbed the ladder"<<endl;
	      if(p[i].sum==49)
		 p[i].sum=71;
		  else if(p[i].sum==19)
		 p[i].sum=40;
	      else if(p[i].sum==57)
		 p[i].sum=77;
	 }
       else
	 {
	   cout<<"Sorry,Your was Incorrect\nThe correct answer is "<<anso;
	   cout<<endl<<"Try better next time ";
	 }

     }
   if(p[i].sum==99||p[i].sum==55||p[i].sum==88||p[i].sum==31)
     {
       clrscr();
       cout<<"This is a Follow up Question\n Answer it right and the snake doesnt bite you";
       fin1.open("normalqns.txt");
       fin2.open("normalans.txt");
       if(p[i].l>1)
	  fin1.seekg(m);
	   fin1.getline(z,1000,'|');
       m=fin1.tellg();
       cout<<z;
	   fin1.close();
       cout<<"Enter the correct options : ";
       cin>>ansi;
       if(p[i].l>1)
	 fin2.seekg(n);
       fin2.getline(anso,5,'|');
       n=fin2.tellg();
       getch();
       if(!strcmpi(ansi,anso))
	 {
	   cout<<"\nIts the correct Answer\nYou dogde the snake!!"<<endl;
	   cout<<"Keep this goin...";
	 }
       else
	 {
	   cout<<"Sorry,Your was Incorrect\nThe correct answer is "<<anso;
	   cout<<"\nOuch!!The snake found you \n";
	   if(p[i].sum==99)
		 p[i].sum=43;
	   else if(p[i].sum==55)
		 p[i].sum=24;
	   else if(p[i].sum==88)
		 p[i].sum=33;
	   else if(p[i].sum==31)
		 p[i].sum=8;
	}
   }
 }

//end function


void snake::end()
{
  char op;
  int m;

  cout<<"\n\n\tThe standing is as follows ...";

  cout.setf(ios::left);

  cout<<endl<<endl<<endl<<"\t";
  cout<<setw(10)<<"Sl No"<<setw(10)<<"Name"<<setw(15)<<"Colour"<<setw(12)<<"Symbol"<<setw(7)<<"Score"<<endl;
  cout<<endl;

  for(m=0;m<no;m++)
     {
	cout<<endl<<"\t";
	cout<<setw(10)<<m+1<<setw(10)<<p[m].name<<setw(15)<<p[m].fcolour;
	cout<<setw(12)<<p[m].symbol<<"     "<<p[m].sum<<endl;
     }

}


//die fuction


void snake::die()
{
  int dice,f=0,a;
  char ch[5];

  for(int l=0;l<no;l++)
	{
	   p[l].pa.x=2-0.2*l;
	   p[l].pa.y=23;
	}

  do
   {
     for(i=0;i<no;i++)
       {
	 randomize();
	 delay(3000);
	 clrscr();
	 cout<<"To Pause Press 'Esc ' Button\n";
	 delay(1000);

	 resume:
	 clrscr();
	 cout<<"Press your Lucky key to roll player "<<i+1<<":";
	 randomize();
	 dice=rand() % 6 + 1;
	 //dice=random(a)+1;


	 //PAUSE MENU START

	 if(getch()==(char)27)
	 {
	    clrscr();
	    char op;

	    end();

	    cout<<endl<<endl<<"\t";

	    cout<<"Do you want to "<<endl;
	    cout<<"\t1.Resume? \n\t2.Quit? \n\t";
		cin>>op;

	    switch(op)
	    {
		case '1':goto resume;

		case '2':clrscr();
		       gotoxy(20,17);
			  cout<<"Hope you enjoyed the ladders\n";
		       gotoxy(20,18.5);
			  cout<<"Thank You for playing!\n";
		       delay(5000);
		       stud_next();
		       break;
		default:goto resume;

	    }

	 }


	 //PAUSE MENU END


	 cout<<"\nThe number is ......"<<dice;


	 //DIE PIC START

	 switch(dice)
	 {
	     case 1:gotoxy(5,5);
		       {
			 cout<<endl;
			 cprintf("   .-------.");
			 cout<<endl;
			 cprintf("  /       /|");
			 cout<<endl;
			 cprintf(" /_______/ |");
			 cout<<endl;
			 cprintf(" |       | |");
			 cout<<endl;
			 cprintf(" |   o   | /");
			 cout<<endl;
			 cprintf(" |       |/ ");
			 cout<<endl;
			 cprintf(" '-------'  ");
			 cout<<endl;
			 break;
		       }
	     case 2:gotoxy(5,5);
		       {
			 cout<<endl;
			 cprintf("   .-------.");
			 cout<<endl;
			 cprintf("  /       /|");
			 cout<<endl;
			 cprintf(" /_______/ |");
			 cout<<endl;
			 cprintf(" | o     | |");
			 cout<<endl;
			 cprintf(" |       | /");
			 cout<<endl;
			 cprintf(" |     o |/");
			 cout<<endl;
			 cprintf(" '-------'");
			 cout<<endl;
			 break;
		       }
	     case 3:gotoxy(5,5);
		       {
			 cout<<endl;
			 cprintf("   .-------.");
			 cout<<endl;
			 cprintf("  /       /|");
			 cout<<endl;
			 cprintf(" /_______/ |");
			 cout<<endl;
			 cprintf(" | o     | |");
			 cout<<endl;
			 cprintf(" |   o   | /");
			 cout<<endl;
			 cprintf(" |     o |/ ");
			 cout<<endl;
			 cprintf(" '-------'  ");
			 cout<<endl;
			 break;
		       }
	     case 4:gotoxy(5,5);
		       {
			 cout<<endl;
			 cprintf("   .-------.");
			 cout<<endl;
			 cprintf("  /       /|");
			 cout<<endl;
			 cprintf(" /_______/ |");
			 cout<<endl;
			 cprintf(" | o   o | |");
			 cout<<endl;
			 cprintf(" |       | /");
			 cout<<endl;
			 cprintf(" | o   o |/ ");
			 cout<<endl;
			 cprintf(" '-------'  ");
			 cout<<endl;
			 break;
		       }
	     case 5:gotoxy(5,5);
		       {
			 cout<<endl;
			 cprintf("   .-------.");
			 cout<<endl;
			 cprintf("  /       /|");
			 cout<<endl;
			 cprintf(" /_______/ |");
			 cout<<endl;
			 cprintf(" | o   o | |");
			 cout<<endl;
			 cprintf(" |   o   | /");
			 cout<<endl;
			 cprintf(" | o   o |/ ");
			 cout<<endl;
			 cprintf(" '-------'  ");
			 cout<<endl;
			 break;
		       }
	     case 6:gotoxy(5,5);
		       {
			 cout<<endl;
			 cprintf("   .-------.");
			 cout<<endl;
			 cprintf("  /       /|");
			 cout<<endl;
			 cprintf(" /_______/ |");
			 cout<<endl;
			 cprintf(" | o   o | |");
			 cout<<endl;
			 cprintf(" | o   o | /");
			 cout<<endl;
			 cprintf(" | o   o |/ ");
			 cout<<endl;
			 cprintf(" '-------'  ");
			 cout<<endl;
			 break;
		       }


	 }


	 //DIE PIC END

	 if(p[i].sum<100)
	     p[i].sum+=dice;
	 if(p[i].sum==100)
	 {
	   f=1;
	   break;
	 }
	 delay(2000);
	qn();
	delay(3000);
	position();
       }

   }while(f==0);

}


//display


void snake::display()
{
  int m;

  cout.setf(ios::left);

  cout<<"\n\n\n\n\tThe players and their Symbols are :";
  cout<<endl<<endl<<endl<<'\t'<<'\t';
  cout<<setw(10)<<"Sl No"<<setw(10)<<"Name"<<setw(15)<<"Colour"<<setw(12)<<"Symbol"<<endl;
  cout<<endl;
  for(m=0;m<no;m++)
     {
	cout<<'\t'<<'\t';
	cout<<setw(10)<<m+1<<setw(10)<<p[m].name<<setw(15)<<p[m].fcolour;
	cout<<setw(12)<<p[m].symbol<<endl;
     }

  delay(4000);
}


//calling function


void snake::game()
{
  sounds();
  g_load();
  grid();
  board();
  snakes();
  lad();
  delay(2000);
  die();
  end();
  delay(4000);
}


//MAIN FUNCTION

void load_s1()
{
    clrscr();
    delay(150);
	for(int j=1;j<=3;j++)
	 {
	   gotoxy(32,1);
		{
			cprintf("\n\n\n\n\nLOADING");
		  delay(300);
			cprintf(" .");
		  delay(300);
			cprintf(" .");
		  delay(300);
			cprintf(" .");
		  delay(300);
		}
	  clrscr();

	 }

}


void uriel()
  {
  clrscr();
  cout<<endl<<"\n\n\t\t";
  textcolor(LIGHTRED+BLINK);
  cprintf("IELURI  URIELURIELURIELU    URIELU  ELURIELURIE  RIELUR        ");cout<<endl<<"\t\t";
  cprintf("IELURI  URIEL RIELURIELUR   URIELU  ELURIELURIEL RIELUR        ");cout<<endl<<"\t\t";
  cprintf(" ELU     RIE   IEL    LUR    RIEL   ELUR    RIEL   ELU         ");cout<<endl<<"\t\t";
  cprintf("  LU     RIE   IELURIELUR     IEL    LUR           EL          ");cout<<endl<<"\t\t";
  cprintf("  LU     RIE   IELURIELU     RIE     LURIEL        EL          ");cout<<endl<<"\t\t";
  cprintf("  LU     RIE   IELURIEL       IEL    LURIELU       EL          ");cout<<endl<<"\t\t";
  cprintf("  LUR    RIE   IELURIELU      IE     LURIELU       ELU         ");cout<<endl<<"\t\t";
  cprintf("  LUR    RIE   IEL   ELU  E   IE     LUR          IELU    UR   ");cout<<endl<<"\t\t";
  cprintf("  LURIELURI    IEL   ELURIE  RIEL    LURI    IEL   ELU    UR   ");cout<<endl<<"\t\t";
  cprintf("   URIELUR    RIELU  ELURIE URIELU  ELURIEL RIEL RIELURIELUR   ");cout<<endl<<"\t\t";
  cprintf("    IELU     RIELU   LURI  URIELUR ELURIELURIEL RIELURIELUR    ");cout<<endl<<"\t\t";
  delay(4000);
  textcolor(WHITE);
  clrscr();
  }


void per_prom()
{
  clrscr();
  char a[10],op;
  int l;
  float per,tot=0;
  s.count=0;
  ifstream fin;
  fin.open("school_pro.txt");
  cout<<endl;
  while(!fin.eof())
    {
      fin>>a;
      if(!fin)
	 break;
      l=strcmp(a,schh);
      if(l==0)
	 {
	    tot++;
	    fin>>a;
	    if(!fin)
	       break;
	    cout<<"\tDoes your school have "<<a<<" ?(Y/N)"<<endl;
	    op=getch();
	    if(op=='y'||op=='Y')
		s.count++;
	 }
    }
       cout<<"\tThe school satisfied "<<s.count<<" promises";
       getch();
       fin.close();
       ofstream fout;
       per=s.count/tot*100;
       fout.open("promper.txt",ios::app);
       fout<<schh<<endl<<per<<endl;
       fout.close();
}

void review()
{
  clrscr();
  char revw[100];
  cout<<"\n\n\n\t\tYou have selected to enter the review of your school\n";
  cout<<"\n\n\n\t\tPlease enter your review (only adjectives):\n\t\t\t";
  gets(revw);
  ofstream fout;
  fout.open("Review.TXT",ios::app);
  fout<<schh<<endl<<revw<<"|"<<endl;
  cout<<"Your review for "<<schh<<" has been saved\n";
  fout.close();
}

void test()
 {
  cout<<"\n\n\n\t\tYou have selected to attempt the offline test series\n";
  /*cout<<"\t\tDo you want to make this intresting?\n";
  cout<<"\t\tTHEN PRESS ESC KEY\n";
  if(getch()==27)
   {
     //SNAKES GAME MODIEFIED
     snake s;
     gotoxy(12,10);
	cout<<"LETS BEGIN...";
     delay(500);
     s.start_text();
     s.s_load();
     s.info();
     s.bcol();
     s.display();
     s.game();
     clrscr();
   }
  else
   {   */
    getch();
    clrscr();
    char qn[100];
    int ans,uans;
    float qns=0.0,count=0.0;
    ifstream fin;
    ifstream fin1;
    fin.open("TEST1.TXT");
    fin1.open("ANS1.TXT");
    while(!fin.eof())
     {
      fin.getline(qn,100,'\n');
      cout<<"\n\n\n"<<qn;
      qns++;
      cout<<"\n\nYour Answer to the qn is...\n";
      cin>>uans;
      fin1>>ans;
      if(uans==ans)
       {
	count++;
	cout<<"\n\nYour answer was correct!!\n";
	   }
      else
       {
	cout<<"\n\nThis was not the correct ans\n";
	cout<<"The correct ans was "<<ans;
	cout<<endl;
       }
     }
      fin.close();
      fin1.close();
      cout<<"\n\n\nThe test is over, press any key to see the results\n";
      getch();
      clrscr();
      cout<<"\n\n\n\n\n\n\n\t\tYour final score is "<<count<<" out of "<<qns;
      cout<<"\n\n\t\tYou scored "<<count/qns*100<<" %";
      getch();
}


void acc_del()
{
pas p2;
stud s2;
int f=0;
//To delete account from stud_l.dat
ifstream fin;
ofstream fout;
fin.open("Stud_l.dat",ios::binary);
fout.open("temp.dat",ios::binary);
while(!fin.eof())
{
fin.read((char*)&p2,sizeof(p2));
f=0;
if(!fin)
break;
if(!strcmp(p.uname,p2.uname))
f=1;
if(f==0)
{
fout.write((char*)&p2,sizeof(p2));
}
}
fin.close();
fout.close();
remove("stud_l.dat");
rename("temp.dat","stud_l.dat");

//To delete account from Stud_reg.dat

f=0;
fin.open("Stud_reg.dat",ios::binary);
fout.open("temp.dat",ios::binary);
while(!fin.eof())
{
fin.read((char*)&s2,sizeof(s2));
f=0;
if(!fin)
break;
if(!strcmp(p.uname,s2.rname))
f=1;
if(f==0)
{
fout.write((char*)&s2,sizeof(s2));
}
}
fin.close();
fout.close();
remove("stud_reg.dat");
rename("temp.dat","stud_reg.dat");
}
/*
void ch_pass()
{
  char temp[17];
  pas p3,p4;
  clrscr();
  ifstream fin;
  while(!fin.eof())
  {
    fin.open("Stud_l.dat",ios::binary);
    fin.read((char*)&p3,sizeof(p3));
    if(!fin)
    break;
    if(!strcmp(p3.uname,p1.uname))
    {
      cout<<"\n\n\t\tPlease enter your old password"<<endl;
      p4.inpass2(temp);
      if(!strcmp(temp,p3.getpass()))
      {
	cout<<"\n\t\tPlease enter your new password\n";
	p4.inpass(temp);
	strcpy(p3.getpass(),temp);
	cout<<"Your password was sucessfully changed!\n";
      }
      else
      {
	cout<<"You have entered the wrong password\n";
	cout<<"Please try again\n";
	getch();
	clrscr();
	ch_pass();
      }
    }
  }
}
*/

void stud_next()
{
  int f=0;
  stud glam;
  do
   {
     clrscr();
     cout<<endl<<"-------------------------------------------------------------------------------"<<endl;
     ifstream fin;
     fin.open("stud_reg.dat",ios::binary);
     while(!fin.eof())
     {
      fin.read((char*)&glam,sizeof(glam));
      while(!fin)
      break;
      if(!strcmp(p1.uname,glam.rname))
      {
       f=1;
       break;
      }
     }
      if(f==1)
      {
       cout<<"\tUsername :"<<glam.rname<<"\t\t\tSchool Name :"<<glam.sna<<endl<<endl;
       cout<<"\t\t\t\t\b\b Stream :"<<glam.stream<<endl;
      }
     cout<<"\n-------------------------------------------------------------------------------\n";
     cout<<"\n\n\t\tCHOOSE ONE OF THE FOLLOWING \n\n";
     cout<<"\t\t\t.[1].Verify promises of your school\n";
     cout<<"\t\t\t.[2].Offline Test Simulation\n";
     cout<<"\t\t\t.[3].Write a review of your school\n";
     cout<<"\t\t\t.[4].Logout\n";
     //cout<<"\t\t\t.[5].Change your password\n";
     cout<<"\t\t\t.[5].Delete your account\n";
     int n=getch();
     if(n==49)
	per_prom();
     else if(n==50)
	test();
     else if(n==51)
	review();
     else if(n==52)
	{
	  clrscr();
	  cout<<"\n\n\n\t\tAre you sure you want to logout?(y/n)";
	  if(getch()=='y')
	    {
	      menu1();
	    }
	}
    // else if(n==53)
       //	ch_pass();
     else if(n==53)
	{
	  clrscr();
	  cout<<"\n\n\n\t\tAre you sure you want to delete your account?(y/n)";
	  if(getch()=='y')
	   {
	    clrscr();
	    cout<<"\n\n\n\t\tWARNING!!\n";
	    cout<<"\n\t\tThis action cannot be overturned\n";
	    cout<<"\t\tPlease confirm your decision(y/n)";
	    if(getch()=='y')
	    {
	     acc_del();
	     cout<<"\n\n\n\t\tYOUR ACCOUNT WAS SUCESSFULLY DELETED\n";
	     getch();
	     clrscr();
	     menu1();
	    }
	    else
	    {
	     cout<<"\n\n\n\t\tYou cancelled your request of deleting your account\n";
	     getch();
	     stud_next();
	    }
	   }
	  else
	   stud_next();
     }
   }while(1);
}

void fest_info()
{
  ofstream fout,fout1;
  char op,events[20],edetails[100];
  strcpy(fes.school,schh);
  fout.open("fest.dat",ios::app|ios::binary);
  cout<<"Enter the name of the fest\n";
  gets(fes.fname);
  cout<<"Enter the date of the fest\n";
  gets(fes.date);
  fout.write((char*)&fes,sizeof(fes));
  fout.close();
  fout.open("Events.txt",ios::app);
  fout1.open("E_Details.txt",ios::app);
  do
   {
	 cout<<"Enter the name of an event in the fest\n";
	 gets(events);
	 fout<<fes.fname<<endl<<events<<endl;
	 cout<<"Enter the details about the event "<<events<<endl;
	 gets(edetails);
	 fout1<<events<<endl<<edetails<<endl<<","<<endl;
	 cout<<"Do you want to add another event?\n";
	 cin>>op;
   }while(op=='y'||op=='Y');
  fout<<","<<endl;
  fout.close();
  fout1.close();
  getch();
}


void fest_disp_fest()
{
 x:
 clrscr();
 ifstream fin;
 fin.open("fest.dat",ios::binary);
		   cout<<"\t\t\n\nFests around are : \n\n";
		   cout.setf(ios::right);
		   cout<<"\t------------------------------------------------------------------\n";
		   cout<<"\t|"<<setw(16)<<"School"<<setw(10)<<"|"<<setw(10)<<"Fest"<<setw(10)<<"|"<<setw(10)<<"Date"<<setw(10)<<"|\n";
		   cout<<"\t------------------------------------------------------------------\n";
		   while(!fin.eof())
		 {
		   fin.read((char*)&fes,sizeof(fes));
		   if(!fin)
		   break;
		   cout<<"\t|"<<setw(16)<<fes.school<<setw(10)<<"|"<<setw(10)<<fes.fname<<setw(10)<<"|"<<setw(10)<<fes.date<<setw(10)<<"|";
		   cout<<endl;
		 }
		   cout<<"\t------------------------------------------------------------------\n";
		   fin.close();
		   delay(750);

//fest_disp_event

int flag1=0;
ifstream fin1;
cout<<"\tDo you want to see the events of any fest";
char ch=getch();
if(ch=='y'||ch=='Y')
 {
cout<<"\n\tPlease enter the name of Fest to see it's events ";
		   char f1[30],a1[30],b1[30];
		   gets(f1);
		   clrscr();
		   fin1.open("Events.txt");
		   while(!fin1.eof())
		   {
		fin1.getline(a1,30,'\n');
		if(!fin1)
		break;
		if(!strcmp(a1,f1))
		{
			flag1=1;
			break;
		}
		}
		if(flag1==1)
		{
		 cout<<"\tEvents of the Fest "<<a1<<" are : \n";
		 while(strcmp(a1,","))
		 {
		 fin1.getline(a1,30,'\n');
		 if(strcmp(a1,",")&&strcmp(a1,f1))
		 cout<<"\t\t"<<a1<<endl;
		}
		}
		else
		{
			clrscr();
			cout<<"\t\tThis fest does not exist\n\t\tPlease Enter the correct fest ";
			delay(750);
			goto x;
		 }

		   fin1.close();
	}
else
{
	op();
}


//fest_disp_details

int flag2=0;
ifstream fin2;
char f2[30],a2[30],b2[30];
cout<<"\n\tEnter the event name to see it's details ";
gets(f2);
fin2.open("E_detail.txt");
while(!fin2.eof())
  {
     fin2.getline(a2,30,'\n');
     if(!fin2)
	break;
     if(!strcmp(a2,f2))
	{
		flag2=1;
		break;
	}
  }
if(flag2==1)
  {
	 cout<<"\tDetails of the Event "<<a2<<" are :\n";
	 while(strcmp(a2,","))
	 {
	   fin2.getline(a2,30,'\n');
	   if(strcmp(a2,",")&&strcmp(a2,f2))
		  cout<<"\t\t"<<a2<<endl;
	   getch();
	 }
   }
else
   {
	cout<<"\t\tThis event does not exist\n\t\tPlease Enter the correct Event ";
	delay(750);
   }
   fin2.close();
   goto x;
 }



void school_next()
{
  do
   {
	 clrscr();
	 cout<<"\n\n\n\t\tCHOOSE ONE OF THE FOLLOWING \n";
	 cout<<"\t\t\t.[1].Input fest details\n";
	 cout<<"\t\t\t.[2].Add a promise\n";
	 cout<<"\t\t\t.[3].Logout\n";
	 int n=getch();
	 if(n==49)
	    fest_info();
	 else if(n==50)
	    sc.add_prom();
	 else if(n==51)
	  {
	    clrscr();
	    cout<<"\n\n\n\t\tAre you sure you wanna logout?(y/n)";
	    if(getch()=='y')
	      {
		menu1();
	      }
	  }
   }while(1);
}


void reg1()
{
 char ri[17],re[17],tuname[20],o;
 int f=0,t,l,h,ea;
 ofstream fout;
 ifstream fin;
 s.read();
 clrscr();
 cout<<"\n\n\n\t\t\tDo you want to stay anonymous?(y/n)\n";
 o=getch();
 if(o=='y'||o=='Y')
   {
	 cout<<"\n\t\t\tYou have chosen to stay anonymous\n";
	 delay(500);
	 clrscr();
	 char ch[6];
	 z:
	   f=0;
	   randomize();
	   for(int i=0;i<5;i++)
	     {
	       int l=rand()%10;
	       l+=48;
	       ch[i]=char(l);
	     }
	   ch[i]='\0';
	   fin.open("Stud_L.DAT",ios::binary);
	   while(!fin.eof())
	     {
	       fin.read((char*)&p,sizeof(p));
	       if(!strcmpi(ch,p.uname))
		 {
		   f=1;
		   break;
		 }
	     }
	   fin.close();
	   if(f==1)
	   goto z;
	   cout<<"\n\n\t\t\tYour Username is "<<ch;
	   strcpy(p1.uname,ch);
	   strcpy(s.rname,ch);
	   h:
	   cout<<"\n\n\n\t\t\tEnter the password\n";
	   p1.inpass(ri);
	   cout<<"\n\n\t\t\tPlease confirm your password\n";
	   p1.inpass(re);
	   l=strcmp(re,ri);
	   if(l==0)
	 {
	   p1.putpass(re);
	   load_s1();
	   fout.open("Stud_L.DAT",ios::binary|ios::app);
	   fout.write((char*)&p1,sizeof(p1));
	   fout.close();
	 }
	   else
	 {
	   clrscr();
	   cout<<"\n\n\t\t\tThe passwords dont match,\n\t\t\tPlease try again\n";
	   getch();
	   clrscr();
	   goto h;
	 }
	   fout.open("STUD_REG.DAT",ios::binary|ios::app);
	   fout.write((char*)&s,sizeof(s));
	   fout.close();
   }
 else
   {
	 ea:
	f=0;
	cout<<"\t\t\nEnter your \n \t\t\tUsername :";
	cin>>p.uname;
	fin.open("Stud_L.DAT",ios::binary);
	while(!fin.eof())
	  {
		fin.read((char*)&p1,sizeof(p1));
		int c=strcmpi(p.uname,p1.uname);
		if(c==0)
		  {
		cout<<"\n\t\t Username already taken \n\t Please select a separate one";
		f=1;
		delay(1000);
		clrscr();
		break;
		  }
	  }
	fin.close();
	 if(f==1)
	  goto ea;
	 strcpy(s.rname,p.uname);
	 q:
	   cout<<"\t\tEnter the password\n";
	   p1.inpass(ri);
	   cout<<"\n\t\tPlease confirm your password\n";
	   p1.inpass(re);
	   l=strcmp(re,ri);
	   if(l==0)
	{
	  p.putpass(re);
	  load_s1();
	  fout.open("Stud_L.DAT",ios::binary|ios::app);
	  fout.write((char*)&p,sizeof(p));
	  fout.close();
	}
	   else
	{
	  clrscr();
	  cout<<"\n\n\n\t\t\tThe passwords dont match,\n\t\t\tPlease try again\n";
	  clrscr();
	  goto q;
	}
	   fout.open("STUD_REG.DAT",ios::binary|ios::app);
	   fout.write((char*)&s,sizeof(s));
	   strcpy(schh,s.sna);
	   strcpy(p1.uname,p.uname);
	   fout.close();
   }
}
void reg2()
{
 char ri[17],re[17],tuname[20],o;
 int f=0,t,l;
 ofstream fout;
 ifstream fin;
 e:
  f=0;
  cout<<"\n\t\tEnter your\n\t\t\tUsername :";
  cin>>p.uname;
  fin.open("SC_L.DAT",ios::binary);
   while(!fin.eof())
	{
	 fin.read((char*)&p1,sizeof(p1));
	 if(!strcmpi(p.uname,p1.uname))
	  {
	   cout<<"\n\t\t\t Username already taken! \n\t\t Please select a separate one";
	   delay(750);
	   clrscr();
	   f=1;
	   break;
	  }
	}
   fin.close();
 if(f==1)
   goto e;
 q:
  cout<<"\n\t\tEnter the password\n";
  p1.inpass(ri);
  cout<<"\n\t\tPlease confirm your password\n";
  p1.inpass(re);
  l=strcmp(re,ri);
  if(l==0)
   {
	 p.putpass(re);
	 load_s1();
	 fout.open("SC_L.DAT",ios::binary|ios::app);
	 fout.write((char*)&p,sizeof(p));
	 fout.close();
   }
  else
   {
	 clrscr();
	 cout<<"\t\t\tThe passwords dont match,:(\n\t\t\tPlease try again\n";
	 delay(750);
	 clrscr();
	 goto q;
   }
  sc.putpass(re);
  strcpy(schh,p.uname);
  sc.prom();
}

void login1()
 {
   char temp[17],tuname[20],op;
   int f,v=0;
   clrscr();
   gotoxy(18,10);
   cout<<"Login..."<<endl<<endl<<endl;
   x:
   v++;
   f=0;
   gotoxy(19,12);
   cout<<"\t Username:";
   cin>>tuname;
   ifstream fin;
   fin.open("stud_l.dat",ios::binary);
   while(!fin.eof())
	 {
	   fin.read((char*)&p1,sizeof(p1));
	   if(!strcmpi(p1.uname,tuname))
	  {
		f=1;
		break;
	  }
	 }
   fin.close();
   if(f==0&&v>3)
	 {
	  clrscr();
	  cout<<"\n\n\t\tToo many tries..."<<endl;
	  cout<<"\n\t\tDo you want to register?\n";
	  op=getch();
	  if(op=='y'||op=='Y')
	  reg1();
	  else
	  menu1();
	 }
   else if(f==0)
	{
	 clrscr();
	 cout<<"\n\t\tSorry User name not found try again"<<endl;
	 delay(750);
	 clrscr();
	 goto x;
	}
   za:
	  fin.open("stud_reg.dat");
	  while(!fin.eof())
		{
		  fin.read((char*)&gla,sizeof(gla));
		  if(strcmp(gla.rname,tuname)==0)
		 {
		   strcpy(schh,gla.sna);
		 }
		}
	  fin.close();
	  cout<<"\n";
	  p.inpass2(temp);
	  if(!strcmp(temp,p1.getpass()))
	   {
	 load_s1();
	 clrscr();
	   }
	  else
	   {
	 clrscr();
	 cout<<"\n\tSorry wrong password enter again"<<endl;
	 delay(500);
	 clrscr();
	 cout<<"\n\n\n\t\tUsername:"<<p1.uname;
	 goto za;
	   }
}

void login2()
 {
   char temp[17],tuname[20],op;
   int f=0,v=0;
   clrscr();
   gotoxy(18,8);
   cout<<"Login..."<<endl<<endl<<endl;
   y:
	 v++;
	 gotoxy(18,12);
	cout<<"\t Username:";
	 cin>>tuname;
	 ifstream fin;
	 fin.open("sc_l.dat",ios::binary);
	 while(!fin.eof())
	   {
	 fin.read((char*)&p1,sizeof(p1));
	 if(!strcmpi(p1.uname,tuname))
	   {
		 f=1;
		 break;
	   }
	   }
	 fin.close();
	 if(f==0&&v>3)
	   {
	 clrscr();
	 cout<<"\n\n\t\tToo many tries...."<<endl;
	 cout<<"\n\t\tDo you want to register?\n";
	 cin>>op;
	 if(op=='y'||op=='Y')
	   reg2();
	 else
	   menu1();
	   }
	 else if(f==0)
	   {
	 cout<<"\n\t\tSorry User name not found try again :("<<endl;
	 delay(500);
	 clrscr();
	 goto y;
	   }
   zb:
	  cout<<"\n";
	 p.inpass2(temp);
	  if(!strcmp(temp,p1.getpass()))
	{
	  load_s1();
	  clrscr();
	  strcpy(sc.uname,tuname);

	}
	  else
	{
	  clrscr();
	  cout<<"\n\n\t\tSorry wrong password enter again";
	  clrscr();
	  cout<<"Username:"<<p1.uname;
	  goto zb;
	}
}

void ip();

void op()
{
 ifstream fin;
 char a[200],b[400];
 int opt,op1;
 do
 {
   clrscr();
   cout<<"\n\n\n\n\t\t\t";
   cout<<".[1].Top Institutes of India\n";
   cout<<"\t\t\t.[2].Top Institutes in 5 regions\n";
   cout<<"\t\t\t.[3].Top Institutes of each stream\n";
   cout<<"\t\t\t.[4].Institues Around Me\n";
   cout<<"\t\t\t.[5].Fests Around Me\n";
   cout<<"\t\t\t.[6].Display the Details of Registered Schools\n";
   cout<<"\t\t\tPress .S P A C E B A R to EXIT"<<endl;
   cout<<"\t\t\tPress .ESC. for main menu";
   op1=getch();
   clrscr();
   switch(op1)
     {
       case 49:
	   fin.open("TOPINDIA.txt");
	       cout<<"\n\n\n\n";
	       while(!fin.eof())
		 {
		   fin.getline(a,200,'\n');
		     cout<<"\t\t\t"<<a<<endl;
		 }
	       fin.close();
	       getch();
	       clrscr();
	       break;
       case 50:
       cout<<endl<<endl<<endl;
	      cout<<"\t\t\t.[1].Delhi"<<endl;
	      cout<<"\t\t\t.[2].Coimbatore"<<endl;
	      cout<<"\t\t\t.[3].Madurai"<<endl;
	      cout<<"\t\t\t.[4].Tiruchirappali"<<endl;
	      cout<<"\t\t\t.[5].Chennai"<<endl;
	      opt=getch();
	      clrscr();
	      switch(opt)
		 {
		   case 49:fin.open("Delhi1.txt");
			   cout<<"\n\n\n\n";
			   while(!fin.eof())
			     {
			       fin.getline(a,200,'\n');
			       cout<<"\t\t\t"<<a<<endl;
			     }
			   fin.close();
			   getch();
			   clrscr();
			   break;

		   case 50:
		      fin.open("Coim.txt");
			   cout<<"\n\n\n\n";
			   while(!fin.eof())
			     {
			       fin.getline(a,200,'\n');
			       cout<<"\t\t\t"<<a<<endl;
			     }
			   fin.close();
			   getch();
			   clrscr();
			   break;

		   case 51:
		       fin.open("Madurai1.txt");
			   cout<<"\n\n\n\n";
			   while(!fin.eof())
			     {
			       fin.getline(a,200,'\n');
			       cout<<"\t\t\t"<<a<<endl;
			     }
			   fin.close();
			   getch();
			   clrscr();
			   break;

		   case 52:

		       fin.open("Tiru.txt");
			   cout<<"\n\n\n\n";
			   while(!fin.eof())
			     {
			       fin.getline(a,200,'\n');
			       cout<<"\t\t\t"<<a<<endl;
			     }
			   fin.close();
			   gotoxy(21.5,12);
			   cout<<"|";
			   getch();
			   clrscr();
			   break;
		   case 53:fin.open("Chennai1.txt");
			   cout<<"\n\n\n\n";
			   while(!fin.eof())
			     {
			       fin.getline(a,200,'\n');
			       cout<<"\t\t\t"<<a<<endl;
			     }
			   fin.close();
			   getch();
			   clrscr();
			   break;

		 }
	       break;
       case 51:cout<<"\n\n\n";
	       cout<<"\t\t\t.[1].Architecture"<<endl;
	       cout<<"\t\t\t.[2].Commerce"<<endl;
	       cout<<"\t\t\t.[3].Engineering Private"<<endl;
	       cout<<"\t\t\t.[4].Law"<<endl;
	       cout<<"\t\t\t.[5].Management"<<endl;
	       cout<<"\t\t\t.[6].Medical"<<endl;
	       opt=getch();
	       clrscr();
	       switch(opt)
		 {
		   case 49:fin.open("Arc.txt");
			   cout<<"\n\n\n\n";
			   while(!fin.eof())
			     {
				fin.getline(a,200,'\n');
				cout<<"\t"<<a<<endl;
			     }
			   fin.close();
			   getch();
			   clrscr();
			   break;

		   case 50:fin.open("Comm.txt");
			   cout<<"\n\n\n\n";
			   while(!fin.eof())
			     {
				fin.getline(a,200,'\n');
				cout<<"\t\t\t"<<a<<endl;
			     }
			   fin.close();
			   getch();
			   clrscr();
			   break;

		   case 51:fin.open("Ep.txt");
			   cout<<"\n\n\n\n";
			   while(!fin.eof())
			     {
				fin.getline(a,200,'\n');
				cout<<"\t\t"<<a<<endl;
			     }
			   fin.close();
			   getch();
			   clrscr();
			   break;

		   case 52:fin.open("law.txt");
			   cout<<"\n\n\n\n";
			   while(!fin.eof())
			     {
				fin.getline(a,200,'\n');
				cout<<"\t"<<a<<endl;
			     }
			   fin.close();
			   getch();
			   clrscr();
			   break;

		   case 53:fin.open("Man.txt");
			   cout<<"\n\n\n\n";
			   while(!fin.eof())
			     {
				fin.getline(a,200,'\n');
				cout<<"\t\t\t"<<a<<endl;
			     }
			   fin.close();
			   getch();
			   clrscr();
			   break;

		   case 54:fin.open("Med.txt");
			   cout<<"\n\n\n\n";
			   while(!fin.eof())
			     {
				fin.getline(a,200,'\n');
				cout<<"\t\t\t"<<a<<endl;
			     }
			   fin.close();
			   getch();
			   clrscr();
			   break;
		 }
	       break;
       case 52:fin.open("aroundme.txt");
	       cout<<"\n\n\n\n";
	       while(!fin.eof())
		 {
		    fin.getline(a,200,'\n');
		    cout<<"\t\t\t"<<a<<endl;
		 }
	       fin.close();
	       getch();
	       clrscr();
	       break;
       case 53:
	       clrscr();
	       fest_disp_fest();
	       break;

       case 54:clrscr();
	       int i=0;
	       char ch[100],a[100];
	       cout<<"\n\n\n\t\tPlease enter the school name you want details about ";
	       cin>>ch;
	       ifstream fin;
	       clrscr();
	       cout<<"\n\n\n\t\tThe school Promises to :"<<endl;
	       fin.open("school_pro.txt");
	       while(!fin.eof())
		 {
		   fin>>a;
		   if(!fin)
		      break;
		   int l=strcmpi(a,ch);
		   if(l==0)
		     {
		       i++;
		       fin>>a;
			   if(!fin)
			 break;
		       cout<<"\t\t\t"<<i<<"."<<a<<endl;
		     }
		 }
	       fin.close();
	       i=0;
	       float sum=0,k;
	       fin.open("promper.txt");
	       while(!fin.eof())
		 {
		   fin>>a;
		   if(!fin)
		     break;
		   int l=strcmpi(a,ch);
		   if(l==0)
		    {
		      i++;
		      fin>>k;
		      sum+=k;
			}
		 }
	       cout<<"\t\tPROMISE PERCENT is :"<<sum/i<<"%"<<endl;
	       fin.close();
	       i=0;
	       fin.open("review.txt");
	       cout<<"\n\t\tFew of the Reviews by students are :"<<endl<<endl;
	       while(!fin.eof())
		 {
		   fin>>a;
		   if(!fin)
		     break;
		   int l=strcmpi(a,ch);
		   if(l==0)
		    {
		      i++;
		      fin.getline(a,100,'|');
		      a[0]=' ';
		      if(!fin)
			break;
			  if(i<3)
			cout<<"\t\t\t"<<i<<"."<<a<<endl;
		    }
		 }
	       getch();
	       clrscr();

	       break;
       case 27: load_s1();
		menu1();
		break;
       case 32: clrscr();
		cout<<"\n\n\n\t\t\t.Hope you enjoyed our app :).";
		delay(1000);
		exit(0);
     }
 }while(1);
}

void menu1();

void ip()
 {
  int h,n;
  h:
  cout<<endl<<endl<<endl<<endl<<endl;
  cout<<"\t\t\tYou are ? "<<endl;
  cout<<"\t\t\t  .[1].Student\n";
  cout<<"\t\t\t  .[2].School\n";
  cout<<"\t\t\tpress .ESC. to go back\n";
  n=getch();
  if(n==49)
   {
    clrscr();
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\tDo you wanna ?"<<endl;
    cout<<"\t\t\t .[1].JOIN THE COMMUNITY & EXPLORE !!(register)\n";
    cout<<"\t\t\t .[2].LOG IN AND ADD or VERIFY DETAILS \n";
    if(getch()==49)
     {
       clrscr();
       reg1();
	   stud_next();
     }
    else
     {
       clrscr();
	   login1();
       stud_next();
     }
   }
  else if(n==50)
    {
      clrscr();
      cout<<endl<<endl<<endl<<endl<<endl;
      cout<<"\t\t\tDo you wanna ?"<<endl;
      cout<<"\t\t\t .[1].JOIN THE COMMUNITY & EXPLORE !!(register)\n";
      cout<<"\t\t\t .[2].LOG IN AND ADD DETAILS \n";
      if(getch()==49)
      {
	clrscr();
	reg2();
	school_next();
      }
      else
      {
	clrscr();
	login2();
	school_next();
      }
    }
  else if(n==27)
	 menu1();
  else
     {
       cout<<" Please a VALID option\n";
       clrscr();
       goto h;
     }

}

void menu1()
{
  int h,n;
   h:
  clrscr();
  gotoxy(18,4);
	 cout<<"Select your option:- "<<endl<<endl;
  gotoxy(19,7);
	 cout<<".[1].SEE WHAT OUR COMMUNITY HAS TO PROVIDE. "<<endl;
  gotoxy(19,8);
	 cout<<".[2].HELP BUILD OUR COMMUNITY BY REGISTERING OR LOGIN. \n"<<endl<<endl;
  gotoxy(18,10);
	 cout<<"\n\t\t .S P A C E B A R. to exit \n";
  n=getch();
  if(n==49)
	{
	  clrscr();
	  op();
	}
  else if(n==50)
	{
	 clrscr();
	 ip();
	}
  else if(n==32)
	{
	   cout<<"\n\t\t.Hope you enjoyed this app :).";
	   delay(1000);
	   exit(0);
	}
  else
	{
	  clrscr();
	  cout<<"Please Select an available option";
	  delay(1000);
	  goto h;
	}
  clrscr();
}

void inifiles()
{
  char ch[17]={"hik"};
  strcpy(p.uname,"try");
  p.putpass(ch);
  ofstream fout;
  fout.open("stud_l.dat",ios::binary);
  fout.write((char*)&p,sizeof(p));
  fout.close();
  fout.open("sc_l.dat",ios::binary);
  fout.write((char*)&p,sizeof(p));
  fout.close();
}

void trun()
{
  ofstream fout;
  fout.open("stud_l.dat",ios::trunc);
  fout.close();
  fout.open("sc_l.dat",ios::trunc);
  fout.close();
  fout.open("stud_reg.dat",ios::trunc);
  fout.close();
}

void tc()
{
	trun();
	inifiles();
}


void main()
{
  clrscr();
  //uriel();
  //getch();
  //tc();
  menu1();
  getch();
}
