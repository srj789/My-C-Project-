
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
main()
{
  int ch;
  char pl[20],dest[20];
  float dist,time,tfare;
   int gd=DETECT,gm;
   clrscr();
  initgraph(&gd,&gm,"c:\\tc\\bgi");
  setbkcolor(BLACK);
  setcolor(YELLOW);
  settextstyle(4,0,4);
  outtextxy(60,20,"Poornima College of Engineering");
  settextstyle(2,0,8);
  outtextxy(150,90,"Transportaion Fees");
 settextstyle(3,0,2);
  outtextxy(70,140,"Guided by:\t\t\t\t\t\t\t\t\tDeveloped by:");
 settextstyle(3,0,2);
  outtextxy(70,170,"Sanjay Gupta\t\t\t\t\t\t\t 1. Suraj kumar");
  settextstyle(3,0,2);
  outtextxy(70,190,"Asst.Professor");
  outtextxy(240,280,"Computer Engineering");
  outtextxy(240,310,"Section B");
  getch();
  cleardevice();
  setbkcolor(RED);
  printf("\nCars Available: ");
  printf("\n1. Ola Mini\n2. Ola Micro\n3. Sedan\nEnter choice: ");
  scanf("%d",&ch);
  printf("\nEnter pickup location: ");
  scanf("%s",&pl);
  printf("\nEnter destination: ");
  scanf("%s",&dest);
  printf("\nEnter distance(in km): ");
  scanf("%f",&dist);
  printf("\nEnter time of journey(in min.): ");
  scanf("%f",&time);
  switch(ch)
  {  case 1: printf("\nYou selected Ola Mini.\n\tCharges:-");
	     printf("\n\tBase fare= Rs 50\n\tRs 6/km\n\tand Rs 1/minute");
	     tfare=50+(dist*6)+(time*1);
	     printf("\nTotal fare=%f",tfare);
	     break;
     case 2: printf("\nYou selected Ola Micro.\n\tCharges:-");
	     printf("\n\tBase fare= Rs 60\n\tRs 8/km\n\tand Rs 1/minute");
	     tfare=60+(dist*8)+(time*1);
	     printf("\nTotal fare=%f",tfare);
	     break;
     case 3: printf("\nYou selected Sedan.\n\tCharges:-");
	     printf("\n\tBase fare= Rs 70\n\tRs 12/km\n\tand Rs 1/minute");
	     tfare=70+(dist*12)+(time*1);
	     printf("\nTotal fare=%f",tfare);
	     break;
     default: printf("\nSelect correct choice!!!!");
   }
    printf("\n\n******************Thank You for using Ola.************************* ");
  getch();
 }
