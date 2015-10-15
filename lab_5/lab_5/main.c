#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct point
	{
		double x;
		double y;
	}point;

double distanceOf(point a, point b);
point getPoint(void);

int main(void) {
	point start, last,current;
	double fullDistance = 0.0;

	printf("Please enter the first point in this format: \'x,y\':\n");

	start = getPoint();
	last = start;
	current = start;
	printf("Please enter the second point:\n");

	do
	{
		current = getPoint();
		fullDistance += distanceOf(last, current);
		last = current;

	} while (distanceOf(start,current) != 0);

	printf("\n\nThe full distance is: %g\n", fullDistance);

	return 0;
}

double distanceOf(point a, point b){
	
	double distanceOnX = fabs(a.x - b.x);
	double distanceOnY = fabs(a.y - b.y);

	return sqrt(pow(distanceOnX,2) + pow(distanceOnY,2));
}

point getPoint(void){

	point entered = {0.0,0.0};

	printf("Please enter the coordinates of the point: ");
	scanf ("%lf,%lf", &entered.x, &entered.y);

	return entered;
}