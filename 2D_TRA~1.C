// Write a program to implement 2D transformation using computer graphics in c.

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
void main()
{
    int gm;
    int gd = DETECT;
    int x1, x2, x3, y1, y2, y3, nx1, nx2, nx3, ny1, ny2, ny3, c;
    int sx, sy, xt, yt, r, ch1, shx, shy;
    int xc, yc;
    float t;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    printf("\t Program for Transformations\n");
    printf("Enter the coordinates of the center: ");
    scanf("%d %d", &xc, &yc);
    line(xc, 0, xc, getmaxy());
    line(0, yc, getmaxx(), yc);
    getch();
    printf("\n\t Enter the points of triangle: ");
    setcolor(1);
    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    line(xc + x1, yc + y1, xc + x2, yc + y2);
    line(xc + x2, yc + y2, xc + x3, yc + y3);
    line(xc + x3, yc + y3, xc + x1, yc + y1);
    getch();
    printf("\n 1.Transaction\n 2.Rotation\n 3.Scalling\n 4.Refelction\n 5.Shearing\n 6.exit\n");
    printf("Enter your choice: ");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
	printf("\n Enter the translation factor: ");
	scanf("%d%d", &xt, &yt);
	nx1 = xc + x1 + xt;
	ny1 = yc + y1 + yt;
	nx2 = xc + x2 + xt;
	ny2 = yc + y2 + yt;
	nx3 = xc + x3 + xt;
	ny3 = yc + y3 + yt;
	line(nx1, ny1, nx2, ny2);
	line(nx2, ny2, nx3, ny3);
	line(nx3, ny3, nx1, ny1);
	getch();
	break;
    case 2:
	printf("\n Enter the angle of rotation: ");
	scanf("%d", &r);
	t = 3.14 * r / 180;
	nx1 = x1 * cos(t) - y1 * sin(t);
	ny1 = x1 * sin(t) + y1 * cos(t);
	nx2 = x2 * cos(t) - y2 * sin(t);
	ny2 = x2 * sin(t) + y2 * cos(t);
	nx3 = x3 * cos(t) - y3 * sin(t);
	ny3 = x3 * sin(t) + y3 * cos(t);
	line(xc + nx1, yc + ny1, xc + nx2, yc + ny2);
	line(xc + nx2, yc + ny2, xc + nx3, yc + ny3);
	line(xc + nx3, yc + ny3, xc + nx1, yc + ny1);
	getch();
	break;
    case 3:
	printf("\n Enter the scalling factor: ");
	scanf("%d%d", &sx, &sy);
	nx1 = xc + x1 * sx;
	ny1 = yc + y2 * sy;
	nx2 = xc + x2 * sx;
	ny2 = yc + y2 * sy;
	nx3 = xc + x3 * sx;
	ny3 = yc + y3 * sy;
	line(nx1, ny1, nx2, ny2);
	line(nx2, ny2, nx3, ny3);
	line(nx3, ny3, nx1, ny1);
	getch();
	break;
    case 4:
	printf("\nEnter Reflection axis\n 1.x-axis\n 2.y-axis\n 3.origin: ");
	scanf("%d", &ch1);
	switch(ch1){
		case 1:
			line(xc+x1, yc-y1, xc+x2, yc-y2);
			line(xc+x2, yc-y2, xc+x3, yc-y3);
			line(xc+x3, yc-y3, xc+x1, yc-y1);
			getch();
			break;
		case 2:
		       line(xc-x1, yc+y1, xc-x2, yc+y2);
		       line(xc-x2, yc+y2, xc-x3, yc+y3);
		       line(xc-x3, yc+y3, xc-x1, yc+y1);
		       getch();
		       break;
		case 3:
		       line(xc-x1, yc-y1, xc-x2, yc-y2);
		       line(xc-x2, yc-y2, xc-x3, yc-y3);
		       line(xc-x3, yc-y3, xc-x1, yc-y1);
		       getch();
		       break;
		default:
			printf("Invalid");
	}
    case 5:
	printf("\nEnter shearing factor(shx and shy): ");
	scanf("%d %d", &shx, &shy);
	line(xc + x1 + shx * y1, yc + y1 + shy * x1,xc + x2 + shx * y2, yc + y2 + shy * x2 );
	line(xc + x2 + shx * y2, yc + y2 + shy * x2,xc + x3 + shx * y3, yc + y3 + shy * x3 );
	line(xc + x3 + shx * y3, yc + y3 + shy * x3,xc + x1 + shx * y1, yc + y1 + shy * x1 );
	getch();
	break;
    case 6:
	break;
    default:
	printf("Enter the correct choice");
    }
    closegraph();
}
