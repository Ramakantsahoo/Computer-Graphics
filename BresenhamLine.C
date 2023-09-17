// Write a program to implement Bresenhams Line drawing algorithm.

#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

void BresenhamLine(int x1, int y1, int x2, int y2){
	int x = x1;
	int y = y1;
	int dx = x2-x1;
	int dy = y2-y1;
	int p = 2*dy - dx;

	if(dx){
		while(x <= x2){
			putpixel(x,y,3);
			x++;
			if(p < 0){
				p = p + 2*dy;
			}
			else{
				y++;
				p = p + 2*dy - 2*dx;
			}
		}
	}
	else if(dy){
		while(y <= y2){
			putpixel(x,y,2);
			y++;
			if(p < 0){
				p = p+2*dy;
			}
			else{
				p = p+2*dy-2*dx;
			}
		}
	}
}

int main(){
	int x1, y1, x2, y2;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	printf("Enter the co-ordinates of starting and ending point of the line: ");
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	BresenhamLine(x1, y1, x2, y2);
	getch();
	closegraph();
	return 0;
}
