#include<reg51.h>
#define display P2


// for keypad
sbit r1=P1^0;
sbit r2=P1^1;
sbit r3=P1^2;
sbit r4=P1^3;
sbit c1=P1^4;
sbit c2=P1^5;
sbit c3=P1^6;

// for lcd
sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;

//for LED
sbit mn=P3^7;
sbit mp1=P3^3;
sbit mp2=P3^4;
sbit mp3=P3^5;
sbit mp4=P3^6;



void lcdcmd(unsigned char);
void lcddat(unsigned char);
void lcddis(unsigned char *,unsigned char);
void delay(unsigned int);
void check();
void checkoff();
void lockback();
void turnon();
unsigned char pwd[4];
unsigned int x;
int MP1=0;
int MP2=0;
int MP3=0;
int MP4=0;


void main()
{
 
lcdcmd(0x38);
lcdcmd(0x0c);
lcdcmd(0x01);
lcdcmd(0x80);
lcddis("PASSWORD PROTECT",16);
lcdcmd(0xc5);
lcddis("SYSTEM",6);
 delay(300);
 while(1){
 turnon();
 }
 }

void turnon()
{
 lcdcmd(0x01);
 lcddis("ENTER PASSWORD",14);
 lcdcmd(0xc0);
 pwd[0]='#';
 pwd[1]='#';
 pwd[2]='#'; 
 pwd[3]='#';
 x=0;
 while(1)
 
{
  r1=0;
   if(c1==0)
  {
   pwd[x]='1';
   delay(40);
   lcddat('1');
   x=x+1;
  }
  if(c2==0)
  {
   pwd[x]='2';
   delay(40);
  lcddat('2');
   x=x+1;
  }
  if(c3==0)
  {
   pwd[x]='3';
   delay(40);
  lcddat('3');
   x=x+1;
  }
  
  r1=1;
  r2=0;
  if(c1==0)
  {
   pwd[x]='4';
   delay(40);
  lcddat('4');
   x=x+1;
  }
  
  if(c2==0)
  {
   pwd[x]='5';
   delay(40);
  lcddat('5');
   x=x+1;
  }
  
  if(c3==0)
  {
   pwd[x]='6';
   delay(40);
   lcddat('6');
   x=x+1;
  }
  
  r2=1;
  r3=0;
  
  if(c1==0)
  {
   pwd[x]='7';
   delay(40);
  lcddat('7');
   x=x+1;
  }
  
  if(c2==0)
  {
   pwd[x]='8';
   delay(40);
  lcddat('8');
   x=x+1;
  }
  
  if(c3==0)
  {
   pwd[x]='9';
   delay(40);
   lcddat('9');
   x=x+1;
  }
  r3=1;
  r4=0;
  if(c1==0)
  {
   pwd[x]='*';
   delay(40);
  lcddat('*');
   x=x+1;
  }
  
  if(c2==0)
  {
   pwd[x]='0';
   delay(40);
  lcddat('0');
   x=x+1;
  }
  
  if(c3==0)
  {
   break;
  }
  
  r4=1;
  
 }
check();


}


void check()
{
 
 //LED ON case
 
 if(pwd[0]=='1'&&pwd[1]=='1'&&pwd[2]=='1'&&pwd[3]=='1')
 {
  
  mp1=1;
  MP1=1;
  if(MP2==0)
  mp2=0;
  if(MP3==0)
  mp3=0;
  if(MP4==0)
  mp4=0;
  mn=0;
  lcdcmd(0x01);
  lcddis("PASSWORD MATCH",14);
  delay(500); 
  
 }
 else if(pwd[0]=='2'&&pwd[1]=='2'&&pwd[2]=='2'&&pwd[3]=='2')
 {
  
  mp2=1;
  MP2=1;
  if(MP1==0)
 mp1=0;
  if(MP3==0)
  mp3=0;
  if(MP4==0)
  mp4=0;
  mn=0;
  lcdcmd(0x01);
  lcddis("PASSWORD MATCH",14);
  delay(500); 
  
 }
 else if(pwd[0]=='3'&&pwd[1]=='3'&&pwd[2]=='3'&&pwd[3]=='3')
 {
  
  mp3=1;
  MP3=1;
  if(MP1==0)
 mp1=0;
  if(MP2==0)
  mp2=0;
  if(MP4==0)
  mp4=0;
  mn=0;
  lcdcmd(0x01);
  lcddis("PASSWORD MATCH",14);
  delay(500); 
  
 }
 else if(pwd[0]=='4'&&pwd[1]=='4'&&pwd[2]=='4'&&pwd[3]=='4')
 {
  
  mp4=1;
  MP4=1;
  if(MP1==0)
  mp1=0;
  if(MP2==0)
  mp2=0;
  if(MP3==0)
  mp3=0;
  mn=0;
  lcdcmd(0x01);
  lcddis("PASSWORD MATCH",14);
  delay(500); 
  
 }
 
 
 //LED OFF case
 
 
 else if(pwd[0]=='5'&&pwd[1]=='5'&&pwd[2]=='5'&&pwd[3]=='5')
 {
  
  mp1=0;
  MP1=0;
  mn=0;
  lcdcmd(0x01);
  lcddis("PASSWORD MATCH",14);
  delay(500); 
  
 }
  else if(pwd[0]=='6'&&pwd[1]=='6'&&pwd[2]=='6'&&pwd[3]=='6')
 {
  
  mp2=0;
  MP2=0;
  mn=0;
  lcdcmd(0x01);
  lcddis("PASSWORD MATCH",14);
  delay(500); 
  
 }
 
  else if(pwd[0]=='7'&&pwd[1]=='7'&&pwd[2]=='7'&&pwd[3]=='7')
 {
  
  mp3=0;
  MP3=0;
  mn=0;
  lcdcmd(0x01);
  lcddis("PASSWORD MATCH",14);
  delay(500); 
  
 }
 
  else if(pwd[0]=='8'&&pwd[1]=='8'&&pwd[2]=='8'&&pwd[3]=='8')
 {
  
  mp4=0;
  MP4=0;
  mn=0;
  lcdcmd(0x01);
  lcddis("PASSWORD MATCH",14);
  delay(500); 
  
 }
 else
 {
  lcdcmd(0x01);
  lcddis("PASSWORD WRONG",14);
  lcdcmd(0xc0);
  lcddis("TRY AGAIN",9);
  delay(500);
 }
}



void lcdcmd(unsigned char val)
{
 display=val;
 rs=0;
 rw=0;
 en=1;
 delay(1);
 en=0;
}

void lcddat(unsigned char dat)
{
 display=dat;
 rs=1;
 rw=0;
 en=1;
 delay(1);
 en=0;
}

void lcddis(unsigned char *s,unsigned char r)
{
 unsigned char w;
 for(w=0;w<r;w++)
 {
  lcddat(s[w]);
  //delay(1);
 }
}

void delay(unsigned int time)
{
 unsigned int i,j;
 for(i=0;i<time;i++)
 {
  for(j=0;j<1275;j++)
  {}
 }
}