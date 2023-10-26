// Write a program in c using computer graphics to draw a line using Digital differential analyzer (DDA) algorithm.

#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>

int round(float x){
	float f = floor(x);
	float c = ceil(x);
	if(c - x >= 0.5)
		return c;
	return f;
}

void DDA(int x1,int y1, int x2, int y2){
	int dx = abs(x2-x1);
	int dy = abs(y2-y1);
	int steps;
	float xinc = (float)dx / (float)steps;
	float yinc = (float)dy / (float)steps;
	float x = x1;
	float y = y1;
	int i;
	if(dx > dy)
		steps = dx;
	else
		steps = dy;

	for(i = 0;i < steps;i++){
		putpixel(round(x),round(y), RED);
		x += xinc;
		y += yinc;
		delay(10);
	}
}

int main(){
	int x1, y1, x2, y2;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	printf("Enter the first and last point of the line(x1, y1, x2, y2): ");
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	DDA(x1, y1, x2, y2);
	getch();
	closegraph();
	return 0;
}
