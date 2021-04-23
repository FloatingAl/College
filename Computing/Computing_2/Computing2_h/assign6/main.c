/*******************************************************
	91.102 Assignment6
	Program: Recursion
	Author: Albara Mehene
	Date: 10/23/2015
	Time spent: 2 hours
	Purpose: The purpose of this code is to be able multiply and read a array using recursion
********************************************************/



#include <stdio.h>
#include "Interface.h"

int main(void)
{//Ask the user for the numbers to multiply
  int mult1;
  int mult2;
  int answer;
  printf("Pick a number: ");
  scanf("%d",&mult1);
  printf("Multiply it how many times ? ");
  scanf("%d",&mult2);
  //Save the final product and print it out
  answer = multiply (mult1,mult2);
  printf("The answer is %d\n",answer);
  
  int arr[5];
  int i;
  int value;
  printf("What value do you to find ?");
  scanf("%d",&value);
  //Gave values for each index until it hits 20.
  for(i = 0; i < 5; i++)
  {
	arr[i] = i + 1;
  }
  //passed the products to the search function.
  search(arr,value,0,4);

  return 0;
}
