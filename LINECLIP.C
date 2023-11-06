#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>

int main()
{
	int x1, x2, y1, y2, minx, maxx, miny, maxy, i;
	float slope;
	int flag = 0;
	int r_begin[4] = {0, 0, 0, 0}, r_end[4] = {0, 0, 0, 0}, r_code[4];
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	printf("Enter minx, miny, maxx, maxy: ");
	scanf("%d %d %d %d", &minx, &miny, &maxx, &maxy);
	printf("Enter the End points: ");
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	cleardevice();
	rectangle(minx, miny, maxx, maxy);
	line(x1, y1, x2, y2);
	if (y1 > maxy)
	{
		r_begin[0] = 1;
		flag = 1;
	}
	if (y1 < miny)
	{
		r_begin[1] = 1;
		flag = 1;
	}
	if (x1 > maxx)
	{
		r_begin[2] = 1;
		flag = 1;
	}
	if (x1 < minx)
	{
		r_begin[3] = 1;
		flag = 1;
	}

	if (y2 > maxy)
	{
		r_end[0] = 1;
		flag = 1;
	}
	if (y2 < miny)
	{
		r_end[1] = 1;
		flag = 1;
	}
	if (x2 > maxx)
	{
		r_end[2] = 1;
		flag = 1;
	}
	if (x2 < minx)
	{
		r_end[3] = 1;
		flag = 1;
	}

	if (flag == 0)
	{
		printf("The line is inside the clipped window\n");
	}
	flag = 1;

	for (i = 0; i < 4; i++)
	{
		r_code[i] = r_begin[i] & r_end[i];
		if (r_code[i] == 1)
		{
			flag = 0;
		}
	}

	if (flag == 0)
	{
		printf("The line is outside the window and no need of clipping\n");
	}

	else
	{
		slope = (float)(y2 - y1) / (float)(x2 - x1);

		if (r_begin[0] == 1 && r_begin[1] == 0)
		{
			x1 = x1 + (float)(maxy - y1) / slope;
			y1 = maxy;
		}
		if (r_begin[0] == 0 && r_begin[1] == 1)
		{
			x1 = x1 + (float)(miny - y1) / slope;
			y1 = miny;
		}
		if (r_begin[2] == 1 && r_begin[3] == 0)
		{
			y1 = y1 + (float)(maxx - x1) * slope;
			x1 = maxx;
		}
		if (r_begin[2] == 0 && r_begin[3] == 1)
		{
			y1 = y1 + (float)(minx - x1) * slope;
			x1 = minx;
		}

		if (r_end[0] == 1 && r_end[1] == 0)
		{
			x2 = x2 + (float)(maxy - y2) / slope;
			y2 = maxy;
		}
		if (r_end[0] == 0 && r_end[1] == 1)
		{
			x2 = x2 + (float)(miny - y2) / slope;
			y2 = miny;
		}
		if (r_end[2] == 1 && r_end[3] == 0)
		{
			y2 = y2 + (float)(maxx - x2) * slope;
			x2 = maxx;
		}
		if (r_end[2] == 0 && r_end[3] == 1)
		{
			y2 = y2 + (float)(minx - x2) * slope;
			x2 = minx;
		}
	}
	delay(1000);
	clearviewport();
	rectangle(minx, miny, maxx, maxy);
	setcolor(RED);
	line(x1, y1, x2, y2);
	getch();
	closegraph();

	return 0;
}