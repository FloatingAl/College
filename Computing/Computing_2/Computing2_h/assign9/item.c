#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"
#include "linkedListSt.h"

int less(Item string1, Item string2)
{
	if(strcmp(string1,string2) > 0)
	{
		return 1;
	
	} 
	else if(strcmp(string1,string2) == 0)
	{
		return 0;
	}

}
