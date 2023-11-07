// Write a program to perform 3d-Transfermation in c using computer graphics

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>

int maxx, maxy, midx, midy;

void axis()
{
	getch();
	cleardevice();
	line(midx, 0, midx, maxy);
	line(0, midy, maxx, midy);
}

void main()
{
	int gd = DETECT, gm;
	int tx, ty, sx, sy, sz, x1, x2, y1, y2, c;
	float ang, t;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	maxx = getmaxx();
	maxy = getmaxy();
	midx = maxx / 2;
	midy = maxy / 2;
	outtextxy(100, 100, "Original Object: ");
	line(midx, 0, midx, maxy);
	line(0, midy, maxx, midy);
	bar3d(midx + 100, midy - 20, midx + 60, midy - 90, 20, 5);
	axis();
	printf("Enter: \n1.Translation\n2.Scaling\n3.Rotation\n");
	scanf("%d", &c);
	switch (c)
	{
	case 1:
		outtextxy(100, 100, "Translation: ");
		printf("Enter the translation factor: ");
		scanf("%d %d", &tx, &ty);
		bar3d(midx + 100, midy - 20, midx + 60, midy - 90, 20, 5);
		bar3d(midx + tx + 100, midy - (ty + 20), midx + tx + 60, midy - (ty + 90), 20, 5);
		axis();
	case 2:
		outtextxy(100, 100, "Scaling: ");
		printf("Enter the scaling factors: ");
		scanf("%d %d %d", &sx, &sy, &sz);
		bar3d(midx + 100, midy - 20, midx + 60, midy - 90, 20, 5);
		bar3d(midx + sx * 100, midy - (sy * 20), midx + sx * 60, midy - (sy * 90), sz * 20, 5);
		axis();
	case 3:
		outtextxy(100, 100, "Rotation: ");
		printf("Enter the angle of rotation: ");
		scanf("%f", &ang);
		t = 3.14 * ang / 180;
		x1 = 100 * cos(t) - 20 * sin(t);
		y1 = 100 * sin(t) + 20 * cos(t);
		x2 = 60 * cos(t) - 90 * sin(t);
		y2 = 60 * sin(t) + 90 * cos(t);
		printf("About z axis: \n");
		bar3d(midx + 100, midy - 20, midx + 60, midy - 90, 20, 5);
		bar3d(midx + x1, midy - y1, midx + x2, midy - y2, 20, 5);
		axis();

		printf("About x axis: \n");
	       //	bar3d(midx+100, midy-20, midx+60, midy-90, 20, 5);
		bar3d(midx + 100, midy - x1, midx + 60, midy - x2, 20, 5);
		axis();

		printf("About y axis: \n");
	       //	bar3d(midx+100, midy-20, midx+60, midy-90, 20, 5);
		bar3d(midx + x1, midy - 20, midx + x2, midy - 90, 20, 5);
		axis();
	default:
		printf("Enter currect choices\n");
		break;
	}
}
