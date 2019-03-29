/* || PROJECT IN 2ND SEM ||
   || SIMPLE  CALCULATOR || */
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
  {
	char ch;
	int a,b,r;
	int x,y,t,lcm,hcf;
	double c,r1,t1;
	int gd=DETECT,gm;
clrscr();
initgraph(&gd,&gm,"c:\\tc\\bgi");
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
outtextxy(340,160,"Section-B");
outtextxy(340,180,"Computer engineering");
settextstyle(8,0,4);
outtextxy(100,220,"SCIENTIFIC CALCULATOR");
outtextxy(100,240,"------------------");
settextstyle(6,0,2);
outtextxy(10,300,"       Thankyou sir for being cooperative and supporting us.");
settextstyle(7,0,2);
outtextxy(10,380,"                Jai Jai Poornima Sansthan");
getch();
cleardevice();
	getch();
	clrscr();
	printf("\t\t\t\t--:MENU:--\n");
	setbkcolor(RED);
setcolor(YELLOW);
outtextxy(20,30,"1. Add");
outtextxy(20,50,"2. Substract");
outtextxy(20,70,"3. Multiplication");
outtextxy(20,90,"4. Division");
outtextxy(20,110,"5. Modulous");
outtextxy(20,130,"6. Power Of");
outtextxy(20,150,"7. Average");
outtextxy(20,170,"8. HCF");
outtextxy(20,190,"9. LCM");
outtextxy(20,210,"10. Sin");
outtextxy(20,230,"11. cos");
outtextxy(20,250,"12. tan");
outtextxy(20,270,"13. ln");
outtextxy(310,30,"14. log b10");
outtextxy(310,50,"15. Square");
outtextxy(310,70,"16. Square root");
outtextxy(310,90,"17. Cube");
outtextxy(310,110,"18. Cube root");
outtextxy(310,130,"19. Exponential");
outtextxy(310,150,"20. Factorial");
outtextxy(310,170,"21. Inverse");
	scanf("%c",&ch);
	if (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'||ch=='^'||ch=='~'||ch=='#'||ch=='@')
	  {
		printf("\nEnter two no. to perform the selected operation\n");
		printf("a=");
		scanf("%d",&a);
		printf("b=");
		scanf("%d",&b);
		switch (ch)
		  {
		    case '+':
			r=a+b;
		    break;
		    case '-':
			r=a-b;
		    break;
		    case '*':
			r=a*b;
		    break;
		    case '/':
			r=a/b;
		    break;
		    case '%':
			r=a%b;
		    break;
		    case '^':
			r=pow(a,b);
		    break;
		    case '~':
			r=(a+b)/2;
		    break;
		    case '#':
		    case '@':
			x=a;
			y=b;
			while(y!=0)
			  {
				t=y;
				y=x%y;
				x=t;
			  }
			hcf=x;
			lcm=(a*b)/hcf;
			if (ch=='#')
			  r=hcf;
			else
			  r=lcm;
		    break;
		  }
		printf("\n\n%d %c %d = %d",a,ch,b,r) ;
	  }
	else
	  {
		printf("\nEnter no. to perform the selected operation\n");
		printf("a=");
		scanf("%lf",&c);
		switch (ch)
		  {
		    case 's':
			r1=sin(c);
		    break;
		    case 'c':
			r1=cos(c);
		    break;
		    case 't':
			r1=tan(c);
		    break;
		    case 'l':
			r1=log(c);
		    break;
		    case 'o':
			r1=log10(c);
		    break;
		    case 'q':
			r1=c*c;
		    break;
		    case 'r':
			r1=sqrt(c);
		    break;
		    case 'u':
			r1=c*c*c;
		    break;
		    case 'b':
			r1=pow(c,0.333333333);
		    break;
		    case 'e':
			r1=exp(c);
		    break;
		    case '!':
			t1=c;
			r1=1;
			while(t1!=0)
			  {
				r1=r1*t1;
				t1--;
			  }
		    break;
		    case '\\':
			r1=1/c;
		    break;
		    default :
			printf("\nWRONG CHOICE!!\n\nTERMINATING...");
			getch();
			return 0;
		  }
		printf("\n\n%c of %lf = %lf",ch,c,r1);
	  }
	getch();
	return 0;
  }