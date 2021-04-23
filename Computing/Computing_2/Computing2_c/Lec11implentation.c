#include "stack.h"

static Item *s;
static int N;

void STACKinit(int maxSize)
{
	s = malloc(maxSize*sizeof(Item));
	if( s == NULL)
		printf("memory is not allocated\n");
	N = 0;
}

int STACKempty(Item item)
{
	return N = 0;
}

void STACKpush(Item item)
{
	s[N] = item;
	N++;
}

Item STACKpop()
{
	Item temp = s[--N];
}