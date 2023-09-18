#include<stdio.h>
#include<dos.h>
#include<graphics.h>

void PutOctants(int x, int y, int x0, int y0){
	putpixel(x+x0, y+y0, 3);
	putpixel(x-x0, y+y0, 3);
	putpixel(x-y0, y+x0, 3);
	putpixel(x-y0, y-x0, 3);
	putpixel(x-x0, y-y0, 3);
	putpixel(x+x0, y-y0, 3);
	putpixel(x+y0, y-x0, 3);
	putpixel(x+y0, y+x0, 3);
}

void MidpointCircle(int x, int y, int r){
	int x0 = 0;
	int y0 = r;
	int dp = 1-r;
	while(x0 <= y0){
		PutOctants(x, y, x0, y0);
		delay(50);
		x0++;
		if(dp < 0){
			dp += 2*x0 + 1;
		}
		else if(dp > 0){
			y0--;
			dp += 2*x0 - 2*y0 + 1;
		}
	}
}

int main(){
	int x, y, r;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	printf("Enter the coordinate of the center: ");
	scanf("%d %d", &x, &y);
	printf("Enter the length of the radius: ");
	scanf("%d", &r);
	MidpointCircle(x, y, r);
	getch();
	closegraph();
	return 0;
}
