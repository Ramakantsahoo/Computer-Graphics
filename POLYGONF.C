// Implement polygon filling algorithm.
// Here we are implemented 8 connected polygon filling.

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void polyfill8(int x, int y, int fc, int bc)
{
	if (getpixel(x, y) != bc && getpixel(x, y) != fc)
	{
		putpixel(x, y, fc);
		polyfill8(x + 1, y, fc, bc);
		polyfill8(x+1, y+1, fc, bc);
		polyfill8(x, y + 1, fc, bc);
		polyfill8(x-1, y+1, fc, bc);
		polyfill8(x - 1, y, fc, bc);
		polyfill8(x-1, y-1, fc, bc);
		polyfill8(x, y - 1, fc, bc);
		polyfill8(x+1, y-1, fc, bc);
	}
}

int main()
{
	int x = 100, y = 100, r = 15;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	rectangle(50, 50, 100, 100);
	polyfill8(55, 55, 4, 15);
	delay(5000);
	getch();
	closegraph();
	return 0;
}
