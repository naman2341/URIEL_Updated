
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
  uriel();
  uriel();
  getch();
  //tc();
  menu1();
  getch();
}
