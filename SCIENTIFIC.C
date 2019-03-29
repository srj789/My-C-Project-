#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>
main()
{
int a,b,ch;
float c;
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
setcolor(RED);
setbkcolor(BLACK);
outtextxy(20,30," Enter value of a and b:");
scanf("%d%d",&a,&b);
getch();
cleardevice();
setbkcolor(RED);
setcolor(YELLOW);
outtextxy(20,30,"1. Add");
outtextxy(20,50,"2. Substract");
outtextxy(20,70,"3. Multiplication");
outtextxy(20,90,"4. Division");
outtextxy(20,110,"5. Sin(a)");
outtextxy(20,130,"6. Sin(b)");
outtextxy(20,150,"7. Cos(a)");
outtextxy(20,170,"8. Cos(b)");
outtextxy(20,190,"9. tan(a)");
outtextxy(20,210,"10. tan(b)");
outtextxy(20,230,"11. log(a)");
outtextxy(20,250,"12. log(b)");
outtextxy(20,270,"13. Square root(a)");
outtextxy(310,30,"14. Square root(c)");
outtextxy(310,50,"15. Cube(a)");
outtextxy(310,70,"16. Cube(b)");
outtextxy(310,90,"17. Log10(a)");
outtextxy(310,110,"18. Log10(b)");
outtextxy(310,130,"19. Exponent(a)");
outtextxy(310,150,"20. Exponent(b)");
outtextxy(310,170,"21. Square of(a)");
outtextxy(310,190,"22. Square of(b)");
outtextxy(310,210,"23. Power(a,b)");
outtextxy(310,230,"24. Power(b,a)");
outtextxy(310,250,"25. Ceil(a)");
outtextxy(310,270,"26. Ceil(b)");
getch();
scanf("%d",&ch);
switch(ch)
{
case 1:
c=a+b;
break;
case 2:
c=a-b;
break;
case 3:
c=a*b;
break;
case 4:
c=a/b;
break;
case 5:
c=sin(a);
break;
case 6:
c=sin(b);
break;
case 7:
c=cos(a);
break;
case 8:
c=cos(b);
break;
case 9:
c=tan(a);
break;
case 10:
c=tan(b);
break;
case 11:
c=log(a);
break;
case 12:
c=log(b);
break;
case 13:
sqrt(a);
break;
case 14:
sqrt(b);
break;
case 15:
c=a*a*a;
break;
case 16:
c=b*b*b;
break;
case 17:
c=log10(a);
break;
case 18:
c=log10(b);
break;
case 19:
c=exp(a);
break;
case 20:
c=exp(b);
break;
case 21:
c=a*a;
break;
case 22:
c=b*b;
break;
case 23:
pow(a,b);
break;
case 24:
c=pow(b,a);
break;
case 25:
c=ceil(a);
break;
case 26:
c=ceil(b);
break;
default:
printf("\n ***********WRONG CHOICE**********");
}
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAnswer=%f",c);
getch();
}




