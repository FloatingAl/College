#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "pq.h"



int less(Item item1, Item item2)
{
	if(item1 < item2)
	{
		return 1;
	
	} 
	else if(item1 > item2)
	{
		return 0;
	}

}
