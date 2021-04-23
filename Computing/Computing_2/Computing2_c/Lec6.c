#include <stdio.h>
#include <stdlib.h>


struct point
{
	int x;
	int y;
};
typedef struct point Point;

int display(void);

int main();
{
	Point banana [3];

	points [0].x = 10;
	points [0].y = 20;
	points [1].x = 500;
	points [1].y = 600;
	
	--------------------------------------------------------------
	
	struct Point * dPoints = malloc(3* sizeof(struct Point));
	//Another way to give the sizeof the type
	//struct Point * dPoints = malloc(3* sizeof(*dPoints));
	
	free(dPoints);
	return 0;
}