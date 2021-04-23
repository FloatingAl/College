#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Hello.h"
int addInt(int , int );
int (*functionPtr)(int , int);

double (*mathPtr)(double);
void someOperation(double (*mathPtr)(double), double operand);

int main()
{
	functionPtr = &addInt;
	int sum = (*functionPtr)(1,2);
	
	someOperation(&aihaga,9);
	
	printf(Summation is equal: %d\n);
	
	return 0;
}

int addInt(int n, int m)
{
	return n+m;
}

double aihaga(double f)
{
	return (f*2);
}

void someOperation(double (*mathPtr)(double), double operand)
{
	double absOperand = fabs(operand);
	absOperand = absOperand/4;
	printf("The output: %f\n"), (*mathPtr)(9.0));
}


//Function pointers can be used as a seperate. 