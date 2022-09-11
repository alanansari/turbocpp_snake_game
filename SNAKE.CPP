#include<fstream.h>
#include<iomanip.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<process.h>
#include<time.h>
int tx[350],ty[350],b,x=39,y=12,a,n,i,m,e,j,r,s,last='y',c;
int o=39,p=12,t,cnt=0,g,u,l=0,f,four=0,lnth=1,cntr=0,pos=0;
struct player{
  char username[30];
  int scr;
  void putdata()
  {
   cout<<"\t"<<setw(20)<<username<<"\t\t\t"<<scr<<endl;
  }
}s1,s2;
void logo()
{
clrscr();
textbackground(RED);
textcolor(WHITE);
clrscr();
cout<<endl<<endl<<endl<<endl;
for(i=1;i<=80;i++)
cout<<char(2);
cout<<endl;
delay(60);
cout<<char(2)<<"             &&&&&&  $&&$     $  &&&&&&&&   &    &   $&&&&&&&                "<<char(2)<<endl;
delay(60);
cout<<char(2)<<"             $       $   $    $  $      $   &  &     $                       "<<char(2)<<endl;
delay(60);
cout<<char(2)<<"             $       $    $   $  $      $   &&       $                       "<<char(2)<<endl;
delay(60);
cout<<char(2)<<"             &&&&&&  $     $  $  $&&&&&&$   &&       $&&&&                   "<<char(2)<<endl;
delay(60);
cout<<char(2)<<"                  $  $     $  $  $      $   &  &     $                       "<<char(2)<<endl;
delay(60);
cout<<char(2)<<"                  $  $     $  $  $      $   &    &   $                       "<<char(2)<<endl;
delay(60);
cnt=0;
cout<<char(2)<<"             &&&&&&  $      &&$  $      $   &     &  $&&&&&&&                "<<char(2)<<endl;
delay(60);
for(i=1;i<=80;i++)
cout<<char(2);cout<<endl<<endl;
cout<<"                                                                By: Alan Ansari";
cout<<endl<<endl<<endl;
}
void score()
{
 cout<<"        score: "<<cnt<<"   press (x) to exit";
}
void border()
{
 cout<<endl;
 cout<<" ";
 for(int i=1;i<=77;i++)
 cout<<char(220);
 cout<<endl;
 for(i=1;i<=22;i++)
 {
 cout<<" ";
 cout<<char(221);
 cout<<"                                                                           ";
 cout<<char(222)<<endl;
 }
 cout<<" ";
 for(i=1;i<=77;i++)
 cout<<char(223);
}
void food()
{
 unsigned int seedval;
 time_t t;
 seedval=(unsigned)time(&t);
 srand(seedval);
 gotoxy(o,p);
 cout<<char(5);
 if(x==o&&y==p)
 {
  cnt+=1;
  if(cnt<=1)
  lnth+=1;
  else
  lnth+=2.5;
  o=(rand()%72)+5;
  p=(rand()%20)+4;
  nohere:
  if(o%2==0)
  o+=1;
  if(o==37)
  o+=2;
  if (p==13)
  p=p+2;
  for(i=0;i<=lnth;i++)
  {
  if(o==tx[i]&&p==ty[i])
   {
    o=(rand()%72)+5;
    p=(rand()%20)+4;
    goto nohere;
   }
  }
 }
}
void checkscr()
{
 fstream fin("scores.dat",ios::binary|ios::in|ios::out);
 fstream fout("temp.dat",ios::binary|ios::out);
 fin.read((char*)&s2,sizeof(s2));
 cntr++;
 while(cntr<=10)
 {
  if(s1.scr>=s2.scr)
  {
   fout.write((char*)&s1,sizeof(s1));
   last='n';
   break;
  }
  else
  fout.write((char*)&s2,sizeof(s2));
  pos=fin.tellg();
  fin.read((char*)&s2,sizeof(s2));
  cntr++;
 }
 if(last=='y'&&cntr<=10)
 fout.write((char*)&s1,sizeof(s1));
 else if(!fin.eof())
 {
  fin.seekg(pos);
  fin.read((char*)&s2,sizeof(s2));
  cntr++;
  while(cntr<=10)
  {
  fout.write((char*)&s2,sizeof(s2));
  fin.read((char*)&s2,sizeof(s2));
  cntr++;
  }
 }
 fin.close();
 fout.close();
 remove("scores.dat");
 rename("temp.dat","scores.dat");
}
void main()                         //main content
{
home:
textbackground(BLACK);
clrscr();
_setcursortype(_NOCURSOR);       //blinking cursor not visible
gotoxy(39,13);
cout<<"LOADING";                 //LOADING SCREEN
for(i=2;i<=77;i++)
{
 gotoxy(i,23);
 cout<<char(177);
 delay(10);
}
retrn:
clrscr();
clrscr();
logo();
cout<<"      Start game.......................(press y)"<<endl;
cout<<"      Instructions.....................(press i)"<<endl;
cout<<"      High Scores......................(press s)"<<endl;
cout<<"      Exit.............................(press x)"<<endl;
e=getch();
if(e=='y'||e=='Y')
 {
  play:                                      //game starts from here
  clrscr();
  cout<<endl<<"                       CHOOSE SPEED:"<<endl<<endl;
  cout<<"         1.  slow"<<endl;
  cout<<"         2.  medium"<<endl;
  cout<<"         3.  fast"<<endl;
  cout<<"         4.  Flash"<<endl<<endl;
  cout<<"     enter (1/2/3/4):";
  cin>>f;
  if(f==1)
  t=120;
  else if(f==2)
  t=105;
  else if(f==3)
  t=80;
  else if(f==4)
  t=65;
  else
  goto play;
  cout<<"           Enable wall(y/n)";
  char wall;
  cin>>wall;
  if(wall=='y')
  {four=0;}
  else if(wall=='n')
  {four=1;}
  else
  goto play;
  clrscr();
  textbackground(BLACK);
  textcolor(WHITE);
  cout<<"STARTING GAME ";
  for(i=1;i<=3;i++)
   {
   cout<<". ";
   delay(250);
   }

  clrscr();
					    //snake head
  while(!kbhit())
   {
   changed:
   score();
   border();
   food();
   if(cnt%7==0)                           //game screen colour
    {
    c=((rand()%15)+1);
    if(c==6||c==14||c==7||c==9)
    c=1;
    textbackground(c);
    textcolor(15);
    clrscr();
    clrscr();
    cnt+=1;
    }
   //controller
   if(a=='d'||a=='D')             //right
   {x+=2;}
   if(a=='a'||a=='A')             //left
   {x-=2;}
   if(a=='w'||a=='W')             //up
   {y--;}
   if(a=='s'||a=='S')             //down
   {y++;}
   if(a=='x'||a=='X')
   goto exit;
   //reappearing from border
   if(four==0)
   {
    if(x>=79||x<=2||y>=25||y<=2)
    {
    delay(1150);
    goto exit;
    }
   }
   if(four==1&&f>=1&&f<=3)
   {
   //                            level 2
    if(cnt==15)
    {
    gotoxy(38,13);
    cout<<"LEVEL 2";
    delay(1150);
    cnt+=1;
    }
    if(cnt>=15)
    {
    gotoxy(3,13);
    for(i=0;i<=74;i++)
    cout<<char(16);
    //                            level 3
     if(cnt==30)
     {
     gotoxy(20,10);
     cout<<"LEVEL 3";
     delay(1150);
     cnt+=1;
     }
     if(cnt>=30)
     {
      for(j=3;j<=24;j++)
      {
       gotoxy(37,j);
       cout<<char(16);
       if(x==37)
       goto exit;
       if(o==38)
       o+=2;
      }
     }
    if(y==13)
    goto exit;
    if(p==13)
    p+=2;
    }
   }
   if(four==1)
   {
   //               reappearing
   if(x>=79) x=3;
   if(x<=2) x=77;
   if(y>=25) y=3;
   if(y<=2) y=24;
   }
   tx[0]=x;
   ty[0]=y;
   int px=tx[0],py=ty[0];                 //tail maker
   int p2x,p2y;
   for(i=1;i<lnth;i++)
   {
    p2x=tx[i];
    p2y=ty[i];
    tx[i]=px;
    ty[i]=py;
    px=p2x;
    py=p2y;
   }
   for(j=0;j< lnth ;j++)
   {
    if(j==0)
    {
    gotoxy(tx[j],ty[j]);
    cout<<char(2);                                  //head
    }
    if(j>1)
    {
    gotoxy(tx[j],ty[j]);
    cout<<char(1);				   //tail
    }
    if(j>=2)
    {
     if(tx[j]==tx[0]&&ty[j]==ty[0])
     {
     delay(1100);
     goto exit;
     }
    }
   }
   delay(t);
   clrscr();
   }
   a=getch();
   goto changed;
 }
 else if(e=='i'||e=='I')
 {
  info:
  textbackground(BLUE);
  textcolor(WHITE);
  clrscr();
  cout<<endl<<"                             INSTRUCTIONS   "<<endl;
  cout<<endl<<endl;
  cout<<"       1. to move up press key                     (w)"<<endl;
  cout<<"       2. to move down press key                   (s)"<<endl;
  cout<<"       3. to move left press key                   (a)"<<endl;
  cout<<"       4. to move right press key                  (d)"<<endl;
  cout<<"       5, to exit while playing the game           (x)"<<endl;
  cout<<endl<<endl;
  cout<<"\tEnter game..................(press y)"<<endl;
  cout<<"\tHome........................(press h)"<<endl;
  cout<<"\tHigh Scores.................(press s)"<<endl;
  cout<<"\tExit........................(press x)"<<endl;
  b=getch();
  if(b=='y')
  goto play;
  else if(b=='h')
  goto retrn;
  else if(b=='x'||b=='X')
  goto exit;
  else if(b=='s')
  goto hscore;
  else
  goto info;
 }
 else if(e=='s')
 {
  hscore:
  clrscr();
  textbackground(GREEN);
  textcolor(WHITE);
  clrscr();
  cout<<endl<<"                             HIGH SCORES   "<<endl;
  cout<<endl<<endl;
  fstream fi("scores.dat",ios::binary|ios::in);
  fi.read((char*)&s2,sizeof(s2));
  while(!fi.eof())
  {
   s2.putdata();
   fi.read((char*)&s2,sizeof(s2));
  }
  fi.close();
  cout<<endl<<endl;
  cout<<"\tEnter game..................(press y)"<<endl;
  cout<<"\tInstructions................(press i)"<<endl;
  cout<<"\tHome........................(press h)"<<endl;
  cout<<"\tExit........................(press x)"<<endl;
  b=getch();
  if(b=='y')
  goto play;
  else if(b=='h')
  goto retrn;
  else if(b=='x'||b=='X')
  goto exit;
  else if(b=='i')
  goto info;
  else
  goto hscore;
 }
 else if(e=='x'||e=='X')
 {
 exit:
 if(cnt>0)
 {
 textcolor(BLACK);
 textbackground(WHITE);
 clrscr();
 cout<<endl<<endl<<endl<<endl<<endl<<endl;
 cout<<"                                  GAME OVER !!!";
 cout<<endl<<endl<<endl<<endl<<endl<<endl;

 cout<<"                                  RAW SCORE:"<<cnt<<endl;
 if(f==4)cnt+=15;if(f==3)cnt+=10;if(f==2)cnt+=5;
 cout<<"          (RAW + LEVEL BONUS)     TOTAL SCORE: "<<cnt;
 getch();
 cout<<endl<<endl<<"\t ENTER USERNAME: ";
 cin>>s1.username;
 s1.scr=cnt;
 checkscr();
 }
 textbackground(BLACK);
 textcolor(WHITE);
 clrscr();
 cout<<endl<<"exiting";
 for(i=0;i<=3;i++)
  {
  delay(250);
  cout<<".";
  }
  textcolor(WHITE);
  textbackground(BLACK);
  clrscr();
 }
 else
 goto retrn;
}