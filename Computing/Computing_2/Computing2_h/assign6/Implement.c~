#include <stdio.h>
#include "Interface.h"



int multiply (int mult1, int mult2)
{
	//I created answer that is integer type
	int answer;
	//Base case
	//Use to stop the recursion like a counter
	if( mult2 == 0)
	{	//The counter
		answer= 0;
	}
	else
	{
		//Answer is holding the return value of multiply
		answer = multiply(mult1,mult2-1)+mult1;
	}
	//returns the result.
	return answer;

}
//This goes through the function and searches for the number in the array  
int search(int *arr, int value, int first, int last)
{
	//This is so that the first and last doesn't keep going. The first will stop 
	if(first > last)
	{
		//Returns 0 and prints this out.
		printf("I couldn't find the value\n");
		return 0;
	}
	// This condition if the number that the value asked is equal to first or last.
	if(arr[first] == value || arr[last] == value)
	{
		printf("I have found the value\n");
		return 1;
	}
	else
	{	//If not, go back 1 from the last index and go 1 forward from the first.
		search(arr,value, first+1, last-1);
	}
		


}
