#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "linkedListSt.h"

int less(Item string1, Item string2)
{

	if(strcmp(string1,string2) == 1)
	{
		printf("The string 1 is greater than string2");
		return 1;
	
	} 
	else if(strcmp(string1,string2) == 0)
	{
		printf("The strings are equal");
		return 0;
	}
	else if (strcmp(string1,string2) == -1)
	{	
		printf("String1 is less than than string2");
		return -1;
	}	
	
}
