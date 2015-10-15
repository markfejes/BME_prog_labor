#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct Pont
	{
		double x;
		double y;
	}Pont;

double distanceOf(Pont a, Pont b);
Pont getPoint(void);

int main(void) {
	Pont start,p2;

	printf("Please enter the first point in this format: \'x,y\':\n");

	start = getPoint();
	p2    = getPoint();
	/*Pont last = {0,0};
	Pont current = {0,0};s
	double fullDistance = 0.0;*/

	printf("%g,%g\n", start.x, start.y);
	printf("%g\n", distanceOf(start,p2));
//	fullDistance += distanceOf();

	return 0;
}

double distanceOf(Pont a, Pont b){
	
	double distanceOnX = fabs(a.x - b.x);
	double distanceOnY = fabs(a.y - b.y);

	return sqrt(pow(distanceOnX,2) + pow(distanceOnY,2));
}

Pont getPoint(void){

	Pont entered = {0.0,0.0};

	printf("Please enter the coordinates of the point: ");
	scanf ("%lf,%lf", &entered.x, &entered.y);

	return entered;
}