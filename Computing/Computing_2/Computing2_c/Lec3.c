/*
*Demonstrates the use of functions with pointers as inputs
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void mult(int value1, int value2, char *sign, int *output);

int main(void)
{
int value1 = 0, value2 = 0;
char sn= ' ';
int results=0;

printf("enter first number: ");
scanf("%d",&value1);
printf("\n enter second number: ");
scanf("%d",&value2);
printf("/n");

mult(value1, value2, &sn, &results);

printf("The result is: %d, the sign is: %c\n", results, sn);
return 0;
}

void mult(int value1, int value2, char *sign, int *output)
{
	int result = value1 * value2;
	char sn= ' ';
	if (result > 0)
	{
		sn = '+';
	}
	elseif(result < 0)
	{
		sn = '-';
	}
	
}