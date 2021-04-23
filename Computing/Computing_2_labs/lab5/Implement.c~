#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Interface.h" 

pBook loadBookInfo(char* fileName)
{
    //Allocating the space for the struct book
    pBook books = malloc(55*sizeof(Book));
    //Opening file    
    FILE *fp;
    if ((fp = fopen(fileName, "r")) == NULL) {
        printf("Can not open the file %s\n", fileName);
        return;
    }
    //created 1 arrays that store the line into buffer.
    char buffer[55];
    //Used for temporary string moving
    char temp[55];
    int i;
    //Continue to loop until i hits 55
    for(i = 0; i < 55;i++)
    {
      //reads one line of thefile and stores it into buffer
      fgets(buffer,55,fp);
      //copys the first line until it hits comma and stores it into temp
      strcpy(temp,strtok(buffer,","));
      //Then create space for authorname
      (books+i)->authorName = malloc(sizeof(char)*strlen(temp));
      //Then stores the first part of the line to authorname
      strcpy((books+i) -> authorName,temp);
      printf("%-30s\n",strcpy((books+i) -> authorName,temp));
      //Now copy the rest of the line after the comma into temp
      strcpy(temp,strtok(NULL,","));
      //creates memory for bookname
      (books+i)->bookName = malloc(sizeof(char)*strlen(temp)); 
      //Then stores into Bookname
      strcpy((books+i) -> bookName,temp);
      printf("%-40s\n",strcpy((books+i) -> bookName,temp));
    }
	//I returned books so it could be dstoryed 
	return books;

}
void destroyBookInfo(pBook *books)
{	
	int i;
	//loop until its at the element of 55. Each time, free that element.
	for(i = 0;i != 55; i++)
	{
		free((*books+i)->bookName);
		free((*books+i)->authorName);
	}
	//I only needed to free book 
	free(*books);
	fclose(fp);
	*books = NULL;

}

