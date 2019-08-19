#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>

void menu1();
class pas
 {
  public:
  char uname[10];
  void inpass(char temp[9]);
  void putpass(char temp[9])
     {
       strcpy(pass,temp);
     }
  char* getpass()
   {
    return pass;
   }
  protected:
  char pass[9];
  char* getuname()
   {
    return uname;
   }

 }p,p1;
void pas::inpass(char temp[9])
  {
    cout<<"Password :";
    for(int i=0;i<8;i++)
      {
	temp[i]=getch();
	if(temp[i]==char(13))
	  {
	    temp[i]='\0';
	    break;
	  }
	else if(temp[i]==char(8))
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
   int  cla;        //Class
   char stream[20]; //stream
   int rname;
   int count;
   void read()
   {
    cout<<"Enter the following values\n";
    cout<<"School Name  Class Stream\n";
    cin>>sna>>cla>>stream;
   }

   void disp()
   {
    cout<<"The details are \n";
    cout<<sna<<cla<<stream;
   }
 }s,s1;

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
 char pro[10];
 do
  {
   cout<<"Please enter your promise";
   cin>>pro;
   fout<<uname<<endl<<pro<<endl;
    cout<<"Do you want to enter another promise?(Y/N)\n";
    cin>>op;
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
 char pro[20][10],pro1[20];
 cout<<"Enter your promises one by one(at least 5)\n";
 do
  {
   cout<<"Enter promise no "<<i+1<<endl;
   cin>>pro[i];
   fout<<uname<<endl<<pro[i]<<endl;
   if(i>3)
   {
    cout<<"Do you want to enter another promise?(Y/N)\n";
    cin>>op;
    if(op!='y'&&op!='Y')
    break;
   }
    i++;
  }while(1);
  fout.close();
  }

void load_screen()
{
 //REFER SNAKES AND LAD
}

void per_prom()
{
ifstream fin;
s.count=0;
char pro[20],op;
fin.open("School_Pro.DAT");
cout<<"You have seleted to verify the promises of your school\n";
if(s.count==0)
{
while(!fin.eof())
{
fin>>pro;
cout<<"Does your school have "<<pro<<" ? (Y/N)";
cin>>op;
if(op=='y'||op=='Y')
s.count++;
}
fin.close();
}
else
cout<<"You have already verified the promises of your school\n";
cout<<s.count;
}

void review()
{
char revw[100];
cout<<"You have selected to enter the review of your school\n";
cout<<"Please enter your review (in 100 words)\n";
gets(revw);
ofstream fout;
fout.open("Review.TXT",ios::app);
fout<<s.sna<<endl<<s.uname<<endl<<revw;
cout<<"Your review for "<<s.sna<<" has been saved\n";
fout.close();
}

void test()
 {
  cout<<"You have selected to attempt the test series\n";
  cout<<"Do you want to make this intresting?\n";
  cout<<"THEN PRESS ESC KEY\n";
  if(getch()==27)
   {
   //SNAKES GAME MODIEFIED
   cout<<"SNAKES\n";
   }
  else
   {
    char qn[30];
    int count=0,ans,uans;
    ifstream fin;
    ifstream fin1;
    fin.open("TEST1.TXT");
    fin1.open("ANS1.TXT");
    while(!fin.eof())
     {
      fin>>qn;
      cout<<qn;
      cout<<"\nYour Answer to the qn is...\n";
      cin>>uans;
      fin1>>ans;
      if(uans==ans)
       {
	count++;
	cout<<"\nYour answer was correct!!\n";
       }
      else
       {
	cout<<"\nThis was not the correct ans\n";
	cout<<"\nThe correct ans was "<<ans;
	cout<<endl;
       }
     }
      fin.close();
      fin1.close();
      cout<<"\nYour final score is "<<count;
   }
   getch();
}


void stud_next()
{
do
{
cout<<"CHOOSE ONE OF THE FOLLOWING \n";
cout<<"1.Verify promises of your school\n";
cout<<"2.Offline Test Simulation\n";
cout<<"3.Write a review of your school\n";
cout<<"4.Exit";
if(getch()==49)
per_prom();
else if(getch()==50)
test();
else if(getch()==51)
review();
else
exit(0);
}while(1);
}

void fest_info()
{
ofstream fout;
char op;
fout.open("Fest.TXT",ios::app);
fout<<sc.uname<<endl;
char fest[20],date[15],events[10],edetails[100];
cout<<"Enter the name of your fest\n";
gets(fest);
fout<<fest<<endl;
cout<<"Enter the date of the fest\n";
gets(date);
fout<<date<<endl;
do
{
cout<<"Enter the name of a event of the fest\n";
gets(events);
cout<<"Enter the details about the event "<<events<<endl;
gets(edetails);
fout<<events<<endl<<edetails<<endl;
cout<<"Do you want to add another event?\n";
cin>>op;
}while(op=='y'||op=='Y');
fout<<"End"<<endl;
fout.close();
getch();
}


void school_next()
{
do
{
cout<<"CHOOSE ONE OF THE FOLLOWING \n";
cout<<"1.Input fest details\n";
cout<<"2.Add a promise\n";
cout<<"3.Reply to reviews\n";
cout<<"4.Exit";
if(getch()==49)
fest_info();
else if(getch()==50)
sc.add_prom();
//else if(getch()==51)
//reply_revw();
else
exit(0);
}while(1);
}


void reg1()
{
 char ri[9],re[9],tuname[20],o;
 int f=0,t,l;
 ofstream fout;
 ifstream fin;
 s.read();
 fout.open("STUD_REG.DAT",ios::binary|ios::app);
 fout.write((char*)&s,sizeof(s));
 fout.close();
 cout<<"Do you want to stay anonymous?\n";
 cin>>o;
 if(o=='y'||o=='Y')
 {
  cout<<"You have chosen to stay anonymous\n";
  char ch[6];
  z:
  randomize();
  for(int i=0;i<5;i++)
    {
      int l=rand()%10;
      l+=48;
      ch[i]=char(l);
    }
  ch[i]='\0';
  cout<<ch;
  fin.open("Stud_L.DAT",ios::binary);
   while(!fin.eof())
    {
     fin.read((char*)&p,sizeof(p));
     if(strcmp(ch,p.uname))
      {
       f=1;
       break;
      }
    }
   fin.close();
   if(!f)
    goto z;
   cout<<"Your Username is "<<ch;
   strcpy(p1.uname,ch);
  h:
  cout<<"Enter the password\n";
  p1.inpass(ri);
  cout<<"\nPlease confirm your password\n";
  p1.inpass(re);
  l=strcmp(re,ri);
  if(l==0)
  {
    p1.putpass(re);
   //LOAD SCREEN
     fout.open("Stud_L.DAT",ios::binary|ios::app);
     fout.write((char*)&p1,sizeof(p1));
     fout<<endl;
     fout.close();
   }
  else
  {
   cout<<"The passwords dont match,\nPlease try agian\n";
   goto h;
  }
 }
 else
  {
  f=0;
  ea:
  cout<<"Enter your user name\n";
  cin>>p.uname;
  fin.open("Stud_L.DAT",ios::binary);
   while(!fin.eof())
    {
     fin.read((char*)&p1,sizeof(p1));
     if(strcmp(p.uname,p1.uname))
      {
       f=1;
       break;
      }
    }
   fin.close();
   if(!f)
    goto ea;
  q:
  cout<<"Enter the password\n";
  p1.inpass(ri);
  cout<<"\nPlease confirm your password\n";
  p1.inpass(re);
  l=strcmp(re,ri);
  if(l==0)
  {
    p.putpass(re);
   //LOAD SCREEN
     fout.open("Stud_L.DAT",ios::binary|ios::app);
     fout.write((char*)&p,sizeof(p));
     fout<<endl;
     fout.close();
   }
  else
  {
   cout<<"The passwords dont match,\nPlease try agian\n";
   goto q;
  }
 }
 }

void reg2()
{
 char ri[9],re[9],tuname[20],o;
 int f=0,t,l;
 ofstream fout;
 ifstream fin;
 cout<<"Enter your user name\n";
  e:
  cin>>p.uname;
  fin.open("SC_L.DAT",ios::binary);
   while(!fin.eof())
    {
     fin.read((char*)&p1,sizeof(p1));
     if(strcmp(p.uname,p1.uname))
      {
       f=1;
       break;
      }
    }
    fin.close();
   if(!f)
    goto e;
  q:
  cout<<"Enter the password\n";
  p1.inpass(ri);
  cout<<"\nPlease confirm your password\n";
  p1.inpass(re);
  l=strcmp(re,ri);
  if(l==0)
  {
    p.putpass(re);
   //LOAD SCREEN
     fout.open("SC_L.DAT",ios::binary|ios::app);
     fout.write((char*)&p,sizeof(p));
     fout<<endl;
     fout.close();
   }
  else
  {
   cout<<"The passwords dont match,\nPlease try agian\n";
   goto q;
  }
 sc.putpass(re);
 strcpy(sc.uname,p.uname);
 sc.prom();
}

void login1()
 {
   char temp[9],tuname[20],op;
   int f=0,v=0;
   clrscr();
   cout<<"\t\tLogin..."<<endl<<endl<<endl;
   x:
   v++;
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
      cout<<"Do you want to register?\n";
      cin>>op;
      if(op=='y'||op=='Y')
      reg1();
      else
      menu1();
     }
   else if(f==0)
    {
     cout<<"\nSorry User name not found try again";
     goto x;
    }
   za:
   cout<<"\t";
   p.inpass(temp);
   if(!strcmp(temp,p1.getpass()))
     {
       cout<<"welcome";
     }
   else
     {
       cout<<"Sorry wrong password enter again";
       clrscr;
       cout<<"Username:"<<p1.uname;
       goto za;
     }
 }

void login2()
 {
   char temp[9],tuname[20],op;
   int f=0,v=0;
   clrscr();
   cout<<"\t\tLogin..."<<endl<<endl<<endl;
   y:
   v++;
   cout<<"\t Username:";
   cin>>tuname;
   ifstream fin;
   fin.open("sc_l.dat",ios::binary);
   while(!fin.eof())
     {
       fin.read((char*)&p1,sizeof(p1));
       cout<<p1.uname<<p1.getpass();
       if(!strcmpi(p1.uname,tuname))
	  {
	    f=1;
	    break;
	  }
     }
   fin.close();
   if(f==0&&v>3)
     {
      cout<<"Do you want to register?\n";
      cin>>op;
      if(op=='y'||op=='Y')
      reg2();
      else
      menu1();
     }
   else if(f==0)
    {
     cout<<"\nSorry User name not found try again";
     goto y;
    }
   zb:
   cout<<"\t";
   p.inpass(temp);
   if(!strcmp(temp,p1.getpass()))
     {
       cout<<"welcome";
     }
   else
     {
       cout<<"Sorry wrong password enter again";
       clrscr;
       cout<<"Username:"<<p1.uname;
       goto zb;
     }
 }


void ip()
 {
  cout<<"1.Student\n";
  cout<<"2.School\n";
  if(getch()==49)
   {
    clrscr();
    cout<<"1.Register\n";
    cout<<"2.Log In\n";
    if(getch()==49)
     {
      reg1();
      stud_next();
     }
    else
     {
      login1();
      stud_next();
     }
   }
    else if(getch()==50)
    {
      clrscr();
      cout<<"1.Register\n";
      cout<<"2.Log In\n";
      if(getch()==49)
	reg2();
      else
	login2();
    }
    else
     cout<<"Please a valid option\n";
 }
/*else if(getch()==50)
else if(getch()==51)*/

 void menu1()
 {
  cout<<"1.Output\n2.Input\n";
  if(getch()==50)//if(getch()==49)
  //op();
  //else
  ip();
 }

 void main()
 {
  clrscr();
  menu1();
  cout<<"BATMAN";
  getch();
 }
