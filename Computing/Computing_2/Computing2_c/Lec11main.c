#include <stdio.h>
#include <stdlib.h>

int main()
{
	STACKinit(10);
	STACKpush(10);
	STACKpush(29);
	printf("I am poping one value: %d\n", STACKpop());
	printf("Checking if the stack is empty again or not %d\n",STACKempty());
	
	
	return 0;
}