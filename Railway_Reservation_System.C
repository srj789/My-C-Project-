	 /* R A I L W A Y   R E S E R V A T I O N   S Y S T E M */
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<dos.h>
#include<graphics.h>


struct train                            //struct train - contain datamembers
  {                                 	// for train details

	int tno;
	char tname[30];
	char bp[30];
	char dest[30];
	int seat,fare,seatleft;
	char dt[11];
  };

void getdetail(struct train *p)
  {
	printf("Enter the details as follows\n\n");
	printf("Train number :"); flushall();
	scanf("%d",&(p->tno));
	printf("Train name :"); flushall();
	gets(p->tname);
	printf("Boarding point :"); flushall();
	gets(p->bp);
	printf("Destination point :"); flushall();
	gets(p->dest);
	printf("Number of seats available :"); flushall();
	scanf("%d",&(p->seat));
	p->seatleft=p->seat;
	printf("Rate of one seat (in Rs.) :"); flushall();
	scanf("%d",&(p->fare));
	printf("Date of travel (dd/mm/yyyy) :"); flushall();
	gets(p->dt);
  }

void dispdetail(struct train *p)          //member function of train
  {
	printf("%5d%10s%10s%14s%8d%7d%13s%7d\n",p->tno,p->tname,p->bp,p->dest,p->seat,p->fare,p->dt,p->seatleft);
  }

struct res                                 //class res - contain datamembers
  {                                 // for reservation detail
	int tno;
	char tname[30];
	char bp[30];
	char dest[30];
	int seat;
	char dt[11];
	char pname[15][30];
	int page[15];
	int pnr;
	float amt;
  };

void getresdet(struct res *p)             //member function of train
  {
	int i;
	printf("Enter the details of passengers :\n");
	for(i=0;i<(p->seat);i++)
	  {
		printf("\tPassenger %d :\n\t",i+1);
		printf("Name :"); flushall();
		gets(p->pname[i]);
		printf("\tAge :"); flushall();
		scanf("%d",&(p->page[i]));
	  }
	printf("Thanks for giving details!!\n");
	getch();
  }

void dispresdet(struct res *p)            //member function of train
  {
	int i;
	clrscr();
	printf("Train Number :\t\t\t%d\nTrain Name \t\t\t%s\nBoarding Point :\t\t%s",p->tno,p->tname,p->bp);
	printf("\nDestination :\t\t\t%s\nSeats Reserved :\t\t%d",p->dest,p->seat);
	printf("\nAmount (in Rs.) :\t\t%f.2\nPNR Number :\t\t\t%d\nBoarding Date :\t\t\t",p->amt,p->pnr);
	printf("%s\n",p->dt);
	for(i=0;i<(p->seat);i++)
	  {
		printf("\tPassenger %d :\n\t\t",i+1);
		printf("Name :\t");puts(p->pname[i]);
		printf("\t\tAge :\t%d",p->page[i]);
		printf("\nPress enter to continue...\n");
		getch();
	  }
  }

void heading()                            //heading function
  {                                         //called before displaying train detail
	printf("T.No.|Train name| Boarding | Destination | Seats | Fare |   Date   | Seats left\n\n");
  }
int psw()                                 //the psw fuction
  {                                 //called by administrator function
	int x;
	char *p;
	char *op="admin" ;                //PASSWORD FOR ADMIN
	p=getpass("Enter password : ");
	x=strcmp(p,op);
	return(x);
  }
void administrator()                      //the administrator fuction
  {
	FILE *f,*f1;
	int x,chadm;
	char c;
	struct train t1;
	struct res r2;
	x=psw();                          //go to psw function
	if(x!=0)
	  {
		printf("\nWrong password!!!\n");
		printf("Enter the password correctly \n");
		printf("You are not permitted to logon this mode\n");
		delay(2000);
		goto b;
	  }
	d:
	do
	  {
		clrscr();
		printf("\t\t\t   ~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("\t\t\t          ADMIN MENU       \n");
		printf("\t\t\t   ~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("\n1.) Create train details database\n2.) Add train details");
		printf("\n3.) Display train database\n4.) Passengers detail\n5.) Return to main menu\n");
		printf("\nEnter your choice (1 / 2 / 3 / 4 / 5) :- ");
		scanf("%d",&chadm);
		switch(chadm)
		  {
		  case 1:
			f=fopen("train.txt","wb");
			do
				{
				getdetail(&t1);//go to class train member function
				fwrite(&t1,sizeof(t1),1,f);
				printf("Do you want to add one more record?\n");
				printf("y - for Yes\nn - for No\n");
				scanf("%c",&c);
				} while(c=='y');
			fclose(f);
		  break;

		  case 2:
			f=fopen("train.txt","ab");
			getdetail(&t1);   //go to class train member function
			fwrite(&t1,sizeof(t1),1,f);
			fclose(f);
		  break;

		  case 3:
			f=fopen("train.txt","rb");
			if (f==NULL)
				{
				printf("\ncant open file");
				getch();
				goto d;
				}

			heading();
			while(fread(&t1,sizeof(t1),1,f)==1)
			  {
			  dispdetail(&t1);//go to class train member function
			  }
			getch();
			fclose(f);
		  break;

		  case 4:

			f1=fopen("reserve.txt","rb");
			if (f==NULL)
				{
				printf("\ncant open file");
				goto d;
				}

			while(fread(&r2,sizeof(r2),1,f1)==1)
			{
				dispresdet(&r2);//go to class res member
			}                       //function
			fclose(f1);
		  break;

		  case 5:
			goto b;

		  default:
			printf("\nWRONG INPUT!!\n");
			getch();
		}
	  }while (1);
	b:
  }



void reserve()                            //the reserve function
  {                                 //called by user function
	time_t t;
	fpos_t ft;
	FILE *f1,*f2;
	struct res r1;
	struct train t2;
	int flag=0,i;
	char chres;
	clrscr();
	printf("\t\t\t\t~~~~~~~~~~~~~~~~\n");
	printf("\t\t\t\tRESERVATION MENU\n");
	printf("\t\t\t\t~~~~~~~~~~~~~~~~\n\n");
	printf("Enter the following details :\n");
	printf("Train number :"); flushall();
	scanf("%d",&r1.tno);
	printf("Number of seats required for reservation (max. 15) :"); flushall();
	scanf("%d",&r1.seat);
	while(r1.seat>15)
	  {
		printf("Reservation of %d seats not permitted!!\n",r1.seat);
		printf("Enter number of seats required again (max. 15) :"); flushall();
		scanf("%d",&r1.seat);
	  }
	f1=fopen("train.txt","rb");
	while(fread(&t2,sizeof(t2),1,f1)==1)
	  {
		if(t2.tno==r1.tno)
		  {
			flag=1;
			flushall();
			strcpy(r1.tname,t2.tname);
			flushall();
			strcpy(r1.bp,t2.bp);
			flushall();
			strcpy(r1.dest,t2.dest);
			flushall();
			strcpy(r1.dt,t2.dt);
			if(t2.seatleft==0)
			  {
				printf("Train fully reserved!!");
				getch();
				flag=2;
			  }
			else if ((r1.seat>t2.seatleft))
			  {
				printf("Only %d seats left!!",t2.seatleft);
				getch();
				flag=2;
			  }
		  }
	  }
	fclose(f1);
	if(flag==1)
	  {
		getresdet(&r1);                   //go to class res member function
		srand((unsigned) time(&t));
		f1=fopen("train.txt","rb+");
		f2=fopen("reserve.txt","ab");
		while (!feof(f1))
		  {
			fgetpos(f1, &ft);
			fread(&t2,sizeof(t2),1,f1);
			if (t2.tno==r1.tno)
			  {
				r1.amt=0;
				for(i=0;i<r1.seat;i++)
				  {
					if((r1.page[i]>10)&&(r1.page[i]<60))
					  {
						r1.amt+=t2.fare;
					  }
					else if(r1.page[i]>=60)
					  {
						r1.amt+=(t2.fare*0.5);
					  }
				  }
				r1.pnr=rand();
				t2.seatleft-=r1.seat;
				printf("\nTotal Amount (in Rs.) = %f",r1.amt);
				printf("\n\nWant to pay the amount (y / n) :- ");
				flushall();
				scanf("%c",&chres);
				getch();
				if(chres=='y'||chres=='Y')
				  {
					fsetpos(f1, &ft);
					fwrite(&t2,sizeof(t2),1,f1);
					fwrite(&r1,sizeof(r1),1,f2);
					printf("Reservation successful!!\n\n");
					printf("Your PNR number is :- %d",r1.pnr);
					getch();
				  }
				break;
			  }

		  }
	fcloseall();
	  }
	else if(flag==0)
	  {
		printf("Wrong train no.! Check train in train info menu");
		getch();
	  }
  }



void cancel()                             //the cancel fuction
      {                                   //called by user function
	struct res r4;
	struct train t3;
	long pos;
	char confirm;
	int pnr,flag=0;
	fpos_t ft;
	FILE *f1,*f2,*f3;
	clrscr();
	printf("\t\t\t\t~~~~~~~~~~~~~~~~\n");
	printf("\t\t\t\tCANCELATION MENU\n");
	printf("\t\t\t\t~~~~~~~~~~~~~~~~\n\n");
	printf("Enter PNR number : ");
	scanf("%d",&pnr);
	f1=fopen("reserve.txt","rb");
	f2=fopen("temp.txt","wb");
	f3=fopen("train.txt","rb+");
	while(fread(&r4,sizeof(r4),1,f1))
	  {
	  if(pnr!=r4.pnr)
	    {
		fwrite(&r4,sizeof(r4),1,f2);
	    }
	  else
	    {
		flag=1;
		dispresdet(&r4);          //go to class res member function
		printf("Are you sure, you want to cancel reservation ? (y / n) :");
		flushall();
		scanf("%c",&confirm);
		if(confirm=='y'||confirm=='Y')
		{
		  while(!feof(f3))
		    {
			fgetpos(f3, &ft);
			fread(&t3,sizeof(t3),1,f3);
			if(t3.tno==r4.tno)
			 {
			   t3.seatleft+=r4.seat;
			   fsetpos(f3, &ft);
			   fwrite(&t3,sizeof(t3),1,f3);
			 }
		    }
		  printf("Amount Received (in Rs.) :- %f",(r4.amt)*0.8);
		  printf("\n\n\t\t\t  Cancellation Successful");
		  getch();
		}
		else
		{
		  fwrite(&r4,sizeof(r4),1,f2);
		  printf("\n\n\t\t\t  Cancellation Unsuccessful....");
		  getch();
		}
	    }
	  }
	if(!flag)
	  {
		printf("Wrong PNR number!!");
		getch();
	  }
	  fcloseall();
	  remove("reserve.txt");
	  rename("temp.txt","reserve.txt");
      }
void user()                               //the user function
	{
	FILE *f,*f1;
	int x,chusr;
	struct train t3;
	int pnr,flag=0;
	struct res r3;
	e:
	do
	{
	clrscr();
	printf("\t\t\t\t~~~~~~~~~~~~~~~\n");
	printf("\t\t\t\t   USER MENU   \n");
	printf("\t\t\t\t~~~~~~~~~~~~~~~\n\n");
	printf("1.) Reserve Seats\n2.) Train Info\n3.) Display Passengers Detail\n");
	printf("4.) Cancel\n5.) Return to Main Menu\n\n\n");
	printf("Enter your choice (1 / 2 / 3 / 4 / 5) : ");
	scanf("%d",&chusr);
	switch(chusr)
	{
		case 1:
		       reserve();         //go to reserve function
		break;

		case 2:
			f=fopen("train.txt","rb");
			heading();        //go to heading function
			while(fread(&t3,sizeof(t3),1,f)==1)
			  {
			  dispdetail(&t3);//go to class train member function
			  }
			getch();
			fclose(f);
		break;

		case 3:
		       printf("Enter PNR number : ");
		       scanf("%d",&pnr);
		       f1=fopen("reserve.txt","rb");
		       while(fread(&r3,sizeof(r3),1,f1)==1)
			{
				if(pnr==r3.pnr)
				{
					flag=1;
					dispresdet(&r3);//go to class train
				}                       //member function
			}
		       if(flag==0)
			{
				printf("Wrong PNR number!!");
				getch();
			}
		       fclose(f1);
		break;

		case 4: cancel();         //go to cancel function
		break;

		case 5: goto g;

		default:printf("Wrong input!!");
			goto e;
	}
	}while(1);
	g:
	}
void main()                               //the main function
{
	int ch,i,x,y;
int gd=DETECT,gm;
clrscr();
initgraph(&gd,&gm,"c:\\tc\\bgi");
 while (!kbhit()) {
      // color 1500 random pixels on screen
   for(i=0; i<=1500; i++) {
       x=rand()%getmaxx();
	  y=rand()%getmaxy();
	  delay(l1);
	  putpixel(x,y,15);
      }


setbkcolor(BLACK);
setcolor(YELLOW);
settextstyle(4,0,4);
outtextxy(10,30,"    Poornima College Of Engineering");
settextstyle(7,0,2);
outtextxy(70,110,"Guided by:");
outtextxy(70,140,"Mr.Sanjay gupta");
outtextxy(70,160,"Asst.proffesor");
outtextxy(70,180,"M-tech");
settextstyle(7,0,2);
outtextxy(340,110,"Developed by:");
outtextxy(340,140,"Suraj kumar");
outtextxy(340,160,"Sudhanshu Jain");
outtextxy(340,180,"Section-B");
outtextxy(340,200,"Computer engineering");
settextstyle(7,0,4);
outtextxy(100,240,"RAILWAY RESERVATION");
outtextxy(100,260,"---------------------");
settextstyle(6,0,2);
outtextxy(10,320,"       Thankyou sir for being cooperative and supporting us.");
settextstyle(7,0,2);
outtextxy(10,380,"                               Happy Journey");
getch();
clrscr();
closegraph();
	printf("\n\n\n\n\n\n\n******************************************************************************\n******************************************************************************\n\n");
	printf("   W E L C O M E   T O   R A I L W A Y   R E S E R V A T I O N   S Y S T E M\n\n");
	printf("******************************************************************************\n******************************************************************************\n\n");
	getch();
	do
	{
	a:
	clrscr();
	printf("\t\t\t   ~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\t\t\t\t   MAIN MENU       \n");
	printf("\t\t\t   ~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n1.) Admin Menu");
	printf("\n2.) User Menu");
	printf("\n3.) Exit");
	printf("\n\n\nEnter your choice:- ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:administrator();   //go to administrator function
		break;
		case 2:user();            //go to user function
		break;
		case 3:exit(0);
		break;
		default:printf("\n\nWrong choice!!");
		goto a;
	}
	} while(ch<=3);
	getch();
}}
