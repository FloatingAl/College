#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char strArr[] = "Hello";
	char * strArr2 = malloc(6*sizeof(char));
	strcpy(strArr2, strArr);
	
	//array of strings
	char **strArr - malloc (N*sizeof(char*));
	for(int i =0l i < N; i++)
	{
		strArr[i] = malloc(100*sizeof(char));
	}
	
	//char * strArr[5];
	//char strArr[3][4];
	free(strArr);
	return 0;
}